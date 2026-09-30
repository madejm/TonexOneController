#include "tonex_parser_trees.h"
#include "tonex_parser.h"

#define BYTE(p_name) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_BYTE, \
        .name = p_name, \
    }

#define FLOAT(p_name) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_FLOAT, \
        .name = p_name, \
    }

#define FLOATS(p_name, p_repeat_count) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_FLOAT, \
        .name = p_name, \
        .repeatCount = p_repeat_count, \
    }

#define BYTES(p_name, p_byte_count) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_BYTES, \
        .name = p_name, \
        .byteCount = p_byte_count, \
    }

#define STRING(p_name, p_byte_count) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_STRING, \
        .name = p_name, \
        .byteCount = p_byte_count, \
    }

#define LIST_B9(p_name, p_child_count, ...) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_LIST_B9, \
        .name = p_name, \
        .listCount = p_child_count, \
        .childrenCount = p_child_count, \
        .children = (const tTonexData[]){ __VA_ARGS__ }, \
    }

#define LIST_BA(p_name, p_child_count, ...) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_LIST_BA, \
        .name = p_name, \
        .listCount = p_child_count, \
        .childrenCount = p_child_count, \
        .children = (const tTonexData[]){ __VA_ARGS__ }, \
    }

// A TONEX detail is B9 02: a prefixed byte buffer followed by its string length.
#define DETAIL(p_name, p_capacity) \
    LIST_B9(TONEX_UNUSED, 2, \
        STRING(p_name, p_capacity), \
        BYTE(TONEX_UNUSED) \
    )

// A parameter bank has one float schema child repeated 109 times.
#define PARAMETER_BANK(p_name) \
    (tTonexData){ \
        .type = TONEX_DATA_FIELD_LIST_BA, \
        .name = p_name, \
        .listCount = 109, \
        .childrenCount = 1, \
        .children = (const tTonexData[]){ FLOATS(TONEX_UNUSED, 109) }, \
    }

/*
 * FullPresetDetails
 *
 * B9 03
 * ├─ byte                         unknown/version
 * ├─ byte                         preset index
 * └─ B9 04                        preset full
 *    ├─ B9 04                     preset partial
 *    ├─ B9 05                     model A
 *    ├─ byte                      separate model enabled
 *    └─ B9 05                     model B (empty when separate model is disabled)
 */
const tTonexData TonexPresetDetailsFullTree =
LIST_B9(TONEX_PRESET_DETAILS_FULL, 3,
    BYTE(TONEX_UNUSED),
    BYTE(TONEX_PRESET_INDEX),

    LIST_B9(TONEX_PRESET_FULL, 4,
        LIST_B9(TONEX_PRESET_PARTIAL, 4,
            DETAIL(TONEX_PRESET_NAME, 33),
            LIST_BA(TONEX_UNUSED, 2,
                FLOAT(TONEX_PRESET_ENABLED),
                FLOAT(TONEX_PRESET_TEMPO)
            ),
            LIST_BA(TONEX_PRESET_PARAMETERS, 3,
                PARAMETER_BANK(TONEX_PRESET_PARAMETER_BANK_0),
                PARAMETER_BANK(TONEX_PRESET_PARAMETER_BANK_1),
                PARAMETER_BANK(TONEX_PRESET_PARAMETER_BANK_2)
            ),
            LIST_B9(TONEX_PRESET_METADATA, 13,
                DETAIL(TONEX_PRESET_METADATA_AUTHOR, 33),
                DETAIL(TONEX_PRESET_METADATA_DATE, 11),
                DETAIL(TONEX_PRESET_METADATA_CHARACTER, 33),
                DETAIL(TONEX_PRESET_METADATA_INSTRUMENT, 33),
                DETAIL(TONEX_PRESET_METADATA_INSTRUMENT_TYPE, 33),
                DETAIL(TONEX_PRESET_METADATA_PICKUP_POSITION, 33),
                DETAIL(TONEX_PRESET_METADATA_PICKUP_TYPE, 33),
                DETAIL(TONEX_PRESET_METADATA_ARTIST, 33),
                DETAIL(TONEX_PRESET_METADATA_ALBUM, 33),
                DETAIL(TONEX_PRESET_METADATA_SONG, 33),
                DETAIL(TONEX_PRESET_METADATA_SONG_PART, 33),
                DETAIL(TONEX_PRESET_METADATA_GENRE, 33),
                DETAIL(TONEX_PRESET_METADATA_DESCRIPTION, 65)
            )
        ),
        LIST_B9(TONEX_MODEL_A, 5,
            BYTES(TONEX_MODEL_A_IDENTIFIER, 16),
            DETAIL(TONEX_MODEL_A_NAME, 33),
            BYTE(TONEX_MODEL_A_TYPE),
            BYTES(TONEX_MODEL_A_PAYLOAD, 13768),
            LIST_B9(TONEX_MODEL_A_METADATA, 9,
                BYTE(TONEX_MODEL_A_METADATA_INSTRUMENT),
                BYTE(TONEX_MODEL_A_METADATA_LICENSED),
                BYTE(TONEX_MODEL_A_METADATA_CATEGORY),
                DETAIL(TONEX_MODEL_A_METADATA_SKIN_NAME, 17),
                DETAIL(TONEX_MODEL_A_METADATA_CATEGORY_NAME, 17),
                DETAIL(TONEX_MODEL_A_METADATA_DATE, 11),
                DETAIL(TONEX_MODEL_A_METADATA_AUTHOR, 33),
                DETAIL(TONEX_MODEL_A_METADATA_COMMENT, 65),
                DETAIL(TONEX_MODEL_A_METADATA_DESCRIPTION, 65)
            )
        ),
        BYTE(TONEX_MODEL_SEPARATE_ENABLED),
        LIST_B9(TONEX_MODEL_B, 5,
            BYTES(TONEX_MODEL_B_IDENTIFIER, 16),
            DETAIL(TONEX_MODEL_B_NAME, 33),
            BYTE(TONEX_MODEL_B_TYPE),
            BYTES(TONEX_MODEL_B_PAYLOAD, 13768),
            LIST_B9(TONEX_MODEL_B_METADATA, 9,
                BYTE(TONEX_MODEL_B_METADATA_INSTRUMENT),
                BYTE(TONEX_MODEL_B_METADATA_LICENSED),
                BYTE(TONEX_MODEL_B_METADATA_CATEGORY),
                DETAIL(TONEX_MODEL_B_METADATA_SKIN_NAME, 17),
                DETAIL(TONEX_MODEL_B_METADATA_CATEGORY_NAME, 17),
                DETAIL(TONEX_MODEL_B_METADATA_DATE, 11),
                DETAIL(TONEX_MODEL_B_METADATA_AUTHOR, 33),
                DETAIL(TONEX_MODEL_B_METADATA_COMMENT, 65),
                DETAIL(TONEX_MODEL_B_METADATA_DESCRIPTION, 65)
            )
        )
    )
);
