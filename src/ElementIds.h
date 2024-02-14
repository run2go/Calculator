#pragma once
// #include "ButtonIds.h"

enum View1 // Simple View
{
    // Base 10
    NUM_0,
    NUM_1,
    NUM_2,
    NUM_3,
    NUM_4,
    NUM_5,
    NUM_6,
    NUM_7,
    NUM_8,
    NUM_9,

    // Operators
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,

    // Symbols
    SYM_COMMA,

    // Buttons
    BT_EVAL
};

enum View2 // Advanced View
{
    // Symbols
    SYM_FACTORIAL,
    SYM_NEGATE,
    SYM_RECIPROCAL,
    SYM_PI,
    SYM_PERCENT,
    SYM_SQRT,
    SYM_POW,
    SYM_BRACKET_OPEN,
    SYM_BRACKET_CLOSE
};

enum View3 // Programmer view
{
    // Base 16
    NUM_A,
    NUM_B,
    NUM_C,
    NUM_D,
    NUM_E,
    NUM_F,

    // Buttons
    BT_DELETE,
    BT_CLEAR,
    BT_COPY,

    // Base Conversion
    RB_BASE_64,
    BT_BASE_64,
    RB_BASE_16,
    BT_BASE_16,
    RB_BASE_10,
    BT_BASE_10,
    RB_BASE_2,
    BT_BASE_2
};

namespace Views
{
    enum View1 // Simple View
    {
        // Base 10
        NUM_0,
        NUM_1,
        NUM_2,
        NUM_3,
        NUM_4,
        NUM_5,
        NUM_6,
        NUM_7,
        NUM_8,
        NUM_9,

        // Operators
        OP_ADD,
        OP_SUB,
        OP_MUL,
        OP_DIV,

        // Symbols
        SYM_COMMA,

        // Buttons
        BT_EVAL
    };

    enum View2 // Advanced View
    {
        // Symbols
        SYM_FACTORIAL,
        SYM_NEGATE,
        SYM_RECIPROCAL,
        SYM_PI,
        SYM_PERCENT,
        SYM_SQRT,
        SYM_POW,
        SYM_BRACKET_OPEN,
        SYM_BRACKET_CLOSE
    };

    enum View3 // Programmer view
    {
        // Base 16
        NUM_A,
        NUM_B,
        NUM_C,
        NUM_D,
        NUM_E,
        NUM_F,

        // Buttons
        BT_DELETE,
        BT_CLEAR,
        BT_COPY,

        // Base Conversion
        RB_BASE_64,
        BT_BASE_64,
        RB_BASE_16,
        BT_BASE_16,
        RB_BASE_10,
        BT_BASE_10,
        RB_BASE_2,
        BT_BASE_2
    };
}
