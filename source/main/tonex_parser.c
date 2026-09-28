#include <string.h>

#include "tonex_parser.h"

typedef struct {
    const uint8_t *data;
    size_t length;
    size_t offset;
} tTonexReader;

typedef enum {
    TONEX_VALUE_NONE,
    TONEX_VALUE_U8,
    TONEX_VALUE_FLOAT,
    TONEX_VALUE_STRING,
} tTonexValueType;

typedef struct {
    bool found;
    tTonexValueType type;
    union {
        uint8_t u8;
        float floating;
        const char *string;
    } value;
    size_t stringLength;
} tTonexValue;

static bool tonex_read_raw_byte(tTonexReader *reader, uint8_t *value)
{
    if (reader->offset >= reader->length) return false;
    *value = reader->data[reader->offset++];
    return true;
}

static bool tonex_read_byte(tTonexReader *reader, uint8_t *value)
{
    if (!tonex_read_raw_byte(reader, value)) return false;
    return *value != 0x80 || tonex_read_raw_byte(reader, value);
}

static bool tonex_read_list(tTonexReader *reader, uint8_t expected_tag, uint16_t expected_count)
{
    uint8_t tag;
    uint8_t count;
    return tonex_read_raw_byte(reader, &tag) && tonex_read_byte(reader, &count) &&
           tag == expected_tag && count == expected_count;
}

static bool tonex_read_bytes(tTonexReader *reader, uint16_t capacity,
                             const char **value, size_t *value_length)
{
    uint8_t tag;
    uint8_t prefix;
    size_t length;

    if (!tonex_read_raw_byte(reader, &tag) || tag != 0xBC ||
        !tonex_read_raw_byte(reader, &prefix)) return false;
    if (prefix == 0x80)
    {
        if (!tonex_read_raw_byte(reader, &prefix)) return false;
        length = prefix;
    }
    else if (prefix == 0x81 || prefix == 0x82)
    {
        uint8_t low;
        uint8_t high;
        if (!tonex_read_raw_byte(reader, &low) || !tonex_read_raw_byte(reader, &high)) return false;
        length = (size_t)low | ((size_t)high << 8);
    }
    else
    {
        length = prefix;
    }

    if (length > capacity || length > reader->length - reader->offset) return false;
    if (value != NULL) *value = (const char *)&reader->data[reader->offset];
    if (value_length != NULL) *value_length = length;
    reader->offset += length;
    return true;
}

static bool tonex_read_node(tTonexReader *reader, const tTonexData *node,
                            tTonexDataFieldName requested_name, tTonexValue *result)
{
    uint16_t repeat_count = node->repeatCount == 0 ? 1 : node->repeatCount;

    for (uint16_t repeat = 0; repeat < repeat_count; repeat++)
    {
        switch (node->type)
        {
            case TONEX_DATA_FIELD_BYTE:
            {
                uint8_t value;
                if (!tonex_read_byte(reader, &value)) return false;
                if (!result->found && node->name == requested_name)
                {
                    result->found = true;
                    result->type = TONEX_VALUE_U8;
                    result->value.u8 = value;
                }
                break;
            }

            case TONEX_DATA_FIELD_FLOAT:
            {
                uint8_t tag;
                float value;
                if (!tonex_read_raw_byte(reader, &tag) || tag != 0x88 ||
                    reader->length - reader->offset < sizeof(value)) return false;
                memcpy(&value, &reader->data[reader->offset], sizeof(value));
                reader->offset += sizeof(value);
                if (!result->found && node->name == requested_name)
                {
                    result->found = true;
                    result->type = TONEX_VALUE_FLOAT;
                    result->value.floating = value;
                }
                break;
            }

            case TONEX_DATA_FIELD_BYTES:
            case TONEX_DATA_FIELD_STRING:
            {
                const char *value;
                size_t value_length;
                if (!tonex_read_bytes(reader, node->byteCount, &value, &value_length)) return false;
                if (!result->found && node->name == requested_name)
                {
                    result->found = true;
                    result->type = node->type == TONEX_DATA_FIELD_STRING ?
                                   TONEX_VALUE_STRING : TONEX_VALUE_NONE;
                    result->value.string = value;
                    result->stringLength = value_length;
                }
                break;
            }

            case TONEX_DATA_FIELD_LIST_B9:
            case TONEX_DATA_FIELD_LIST_BA:
            {
                uint8_t tag = node->type == TONEX_DATA_FIELD_LIST_B9 ? 0xB9 : 0xBA;
                if (!tonex_read_list(reader, tag, node->listCount)) return false;
                for (uint16_t child = 0; child < node->childrenCount; child++)
                {
                    if (!tonex_read_node(reader, &node->children[child], requested_name, result)) return false;
                }
                break;
            }
        }
    }
    return true;
}

static bool tonex_read_value(const uint8_t *data, size_t data_length, const tTonexData *tree,
                             tTonexDataFieldName name, tTonexValue *value)
{
    tTonexReader reader = {.data = data, .length = data_length, .offset = 0};
    memset(value, 0, sizeof(*value));
    return data != NULL && tree != NULL && tonex_read_node(&reader, tree, name, value) &&
           reader.offset == data_length && value->found;
}

bool tonex_read_data_str(const uint8_t *data, size_t data_length, const tTonexData *tree,
                         tTonexDataFieldName name, const char **value, size_t *value_length)
{
    tTonexValue parsed;
    if (value == NULL || value_length == NULL ||
        !tonex_read_value(data, data_length, tree, name, &parsed) || parsed.type != TONEX_VALUE_STRING)
        return false;
    *value = parsed.value.string;
    *value_length = parsed.stringLength;
    return true;
}

bool tonex_read_data_u8(const uint8_t *data, size_t data_length, const tTonexData *tree,
                        tTonexDataFieldName name, uint8_t *value)
{
    tTonexValue parsed;
    if (value == NULL || !tonex_read_value(data, data_length, tree, name, &parsed) ||
        parsed.type != TONEX_VALUE_U8) return false;
    *value = parsed.value.u8;
    return true;
}

bool tonex_read_data_float(const uint8_t *data, size_t data_length, const tTonexData *tree,
                           tTonexDataFieldName name, float *value)
{
    tTonexValue parsed;
    if (value == NULL || !tonex_read_value(data, data_length, tree, name, &parsed) ||
        parsed.type != TONEX_VALUE_FLOAT) return false;
    *value = parsed.value.floating;
    return true;
}
