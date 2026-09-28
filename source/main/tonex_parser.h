#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum {
    TONEX_DATA_FIELD_BYTE,
    TONEX_DATA_FIELD_FLOAT,
    TONEX_DATA_FIELD_BYTES,
    TONEX_DATA_FIELD_STRING,
    TONEX_DATA_FIELD_LIST_B9,
    TONEX_DATA_FIELD_LIST_BA,
} tTonexDataFieldType;

typedef enum {
    TONEX_UNUSED,

    TONEX_PRESET_DETAILS_FULL,
    TONEX_PRESET_INDEX,
    TONEX_PRESET_FULL,
    TONEX_PRESET_PARTIAL,
    TONEX_PRESET_NAME,
    TONEX_PRESET_ENABLED,
    TONEX_PRESET_TEMPO,
    TONEX_PRESET_PARAMETERS,
    TONEX_PRESET_PARAMETER_BANK_0,
    TONEX_PRESET_PARAMETER_BANK_1,
    TONEX_PRESET_PARAMETER_BANK_2,
    TONEX_PRESET_METADATA,
    TONEX_PRESET_METADATA_AUTHOR,
    TONEX_PRESET_METADATA_DATE,
    TONEX_PRESET_METADATA_CHARACTER,
    TONEX_PRESET_METADATA_INSTRUMENT,
    TONEX_PRESET_METADATA_INSTRUMENT_TYPE,
    TONEX_PRESET_METADATA_PICKUP_POSITION,
    TONEX_PRESET_METADATA_PICKUP_TYPE,
    TONEX_PRESET_METADATA_ARTIST,
    TONEX_PRESET_METADATA_ALBUM,
    TONEX_PRESET_METADATA_SONG,
    TONEX_PRESET_METADATA_SONG_PART,
    TONEX_PRESET_METADATA_GENRE,
    TONEX_PRESET_METADATA_DESCRIPTION,

    TONEX_MODEL_A,
    TONEX_MODEL_B,
    TONEX_MODEL_SEPARATE_ENABLED,
    TONEX_MODEL_IDENTIFIER,
    TONEX_MODEL_A_NAME,
    TONEX_MODEL_A_TYPE,
    TONEX_MODEL_B_NAME,
    TONEX_MODEL_B_TYPE,
    TONEX_MODEL_PAYLOAD,
    TONEX_MODEL_METADATA,
    TONEX_MODEL_METADATA_INSTRUMENT,
    TONEX_MODEL_METADATA_LICENSED,
    TONEX_MODEL_METADATA_CATEGORY,
    TONEX_MODEL_METADATA_INSTRUMENT_NAME,
    TONEX_MODEL_METADATA_CATEGORY_NAME,
    TONEX_MODEL_METADATA_DATE,
    TONEX_MODEL_METADATA_OPAQUE,
    TONEX_MODEL_METADATA_DESCRIPTION,
    TONEX_MODEL_METADATA_COMMENT,
} tTonexDataFieldName;

typedef struct tTonexData tTonexData;

struct tTonexData {
    tTonexDataFieldType type;
    tTonexDataFieldName name;
    uint16_t listCount;     // Expected count in the B9 or BA list header.
    uint16_t childrenCount; // Number of schema nodes in children.
    uint16_t byteCount;     // Expected payload capacity for TONEX_DATA_FIELD_BYTES.
    uint16_t repeatCount;   // Consecutive occurrences of this child schema node.
    const tTonexData *children;
};


bool tonex_read_data_str(const uint8_t *data, size_t data_length, const tTonexData *tree,
                         tTonexDataFieldName name, const char **value, size_t *value_length);
bool tonex_read_data_u8(const uint8_t *data, size_t data_length, const tTonexData *tree,
                        tTonexDataFieldName name, uint8_t *value);
bool tonex_read_data_float(const uint8_t *data, size_t data_length, const tTonexData *tree,
                           tTonexDataFieldName name, float *value);
