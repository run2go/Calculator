#pragma once
/*
#define BASE_ID_NUMBERS 1000
#define NUMBER_1 BASE_ID_NUMBERS + 1
*/

enum ButtonIds
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
	// Base 16
	NUM_A,
	NUM_B,
	NUM_C,
	NUM_D,
	NUM_E,
	NUM_F,

	// Operators
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,

	// Symbols
	SYM_COMMA,
	SYM_PI,
	SYM_RECIPROCAL,
	SYM_NEGATE,
	SYM_FACTORIAL,
	SYM_SQRT,
	SYM_POW,
	SYM_PERCENT,
	SYM_BRACKET_OPEN,
	SYM_BRACKET_CLOSE,

	// Buttons
	BT_DELETE,
	BT_CLEAR,
	BT_COPY,
	BT_EVAL
};