/*******************************************************************
* Filename:   DefAnderror.h
* Author:     Michał Bajkos
* Details:    Header file for errors and hard-coding macro
*********************************************************************/

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

/*************************** DEFINES  ********************************/
#define CONSOLE printf
#define len     (120u)
#define size    (50u)

/***************************  DATA TYPES   ***************************/
typedef uint8_t     u8;
typedef uint32_t    u32;
typedef long int    li;

typedef struct{
    li alfabet[size]; // a b c d 
    li ileRazy[size]; // a -1 raz, b-2 razy itd
    li ktoreMiejsce[size]; // bitowo index 1, a-1,4,5 miejsce, b=2,6 itd
}str;

typedef enum
{
    INCORECT_POINTER    = 0,

}errorTypes;


enum AsciiTable
{
  //control characters

	_NULL,                                            // NULL
	SOH,                                             // Start of Heading
	STX,                                             // Start of Text
	ETX,                                             // End of Text
	EOT,                                             // End of Transmission
	ENQ,                                             // Enquiry
	ACK,                                             // Acknowledgement
	BEL,                                             // Bell
	BS,                                              // Backspace
	TAB,                                             // Horizontal Tab
	LF,                                              // Line Feed 
	VT,                                              // Vertical Tab 
	FF,                                              // Form Feed 
	CR,                                              // Carriage Return
	SO,                                              // Shift Out 
	SI,                                              // Shift In 
	DLE,                                             // Data Link Escape 
	DC1,                                             // Device Control 1
	DC2,                                             // Device Control 2
	DC3,                                             // Device Control 3
	DC4,                                             // Device Control 4
	NAK,                                             // Negative Acknowledgement 
	SYN,                                             // Synchronous Idle 
	ETB,                                             // End of Transmission Block 
	CAN,                                             // Cancel
	EM,                                              // End of Medium 
	SUB,                                             // Substitute 
	ESC,                                             // Escape
	SF,                                              // File Separator
	GS,                                              // Group Separator
	RS,                                              // Record Separator
	US,                                              // Unit Separator

	//misc characters				                 

	SPACE,                                           // space
	EXCLAMAION_MARK,                                 // !
	QUOTATION_MARK_DOUBLE,                           // "
	HASHTAG,                                         // #
	SING_DOLLAR,                                     // $
	PRECENT,                                         // %
	AMPERSANT,                                       // &
	QUOTATION_MARK_SINGLE,                           // '
	PARENTHESES_OPEN,                                // (
	PARENTHESES_CLOSE,                               // )
	ASTERISK,                                        // *
	PLUS,                                            // +
	COMMA,                                           // ,
	MINUS,                                           // -
	DOT,                                             // .
	SLASH_FOWARD,                                    // /
	NUMBER_0,                                        // 0
	NUMBER_1,                                        // 1
	NUMBER_2,                                        // 2
	NUMBER_3,                                        // 3
	NUMBER_4,                                        // 4
	NUMBER_5,                                        // 5
	NUMBER_6,                                        // 6
	NUMBER_7,                                        // 7
	NUMBER_8,                                        // 8
	NUMBER_9,                                        // 9
	COLON,                                           // :
	COLON_SEMI,                                      // ;
	LESS_THAN,                                       // <
	EQUAL_TO,                                        // =
	GREATER_THAN,                                    // >
	QUESTION_MARK,                                   // ?
	SING_AT,                                         // @

	//upper case alphabet			                 

	A_UPPER,                                         // A
	B_UPPER,                                         // B
	C_UPPER,                                         // C
	D_UPPER,                                         // D
	E_UPPER,                                         // E
	F_UPPER,                                         // F
	G_UPPER,                                         // G
	H_UPPER,                                         // H
	I_UPPER,                                         // I
	J_UPPER,                                         // J
	K_UPPER,                                         // K
	L_UPPER,                                         // L
	M_UPPER,                                         // M
	N_UPPER,                                         // N
	O_UPPER,                                         // O
	P_UPPER,                                         // P
	Q_UPPER,                                         // Q
	R_UPPER,                                         // R
	S_UPPER,                                         // S
	T_UPPER,                                         // T
	U_UPPER,                                         // U
	V_UPPER,                                         // V
	W_UPPER,                                         // W
	X_UPPER,                                         // X
	Y_UPPER,                                         // Y
	Z_UPPER,                                         // Z

	//misc characters				                 

	BRACKET_OPEN,                                    // [
	SLASH_BACKWARD,                                  //  slash
	BRACKET_CLOSE,                                   // ]
	CARET,                                           // ^
	UNDERSCORE,                                      // _
	GRAVE_ACCENT,                                    // ` 

	//lower case alphabet			                 

	A_LOWER,                                         // a
	B_LOWER,                                         // b
	C_LOWER,                                         // c
	D_LOWER,                                         // d
	E_LOWER,                                         // e
	F_LOWER,                                         // f
	G_LOWER,                                         // g
	H_LOWER,                                         // h
	I_LOWER,                                         // i
	J_LOWER,                                         // j
	K_LOWER,                                         // k
	L_LOWER,                                         // l
	M_LOWER,                                         // m
	N_LOWER,                                         // n
	O_LOWER,                                         // o
	P_LOWER,                                         // p
	Q_LOWER,                                         // q
	R_LOWER,                                         // r
	S_LOWER,                                         // s
	T_LOWER,                                         // t
	U_LOWER,                                         // u
	V_LOWER,                                         // v
	W_LOWER,                                         // w
	X_LOWER,                                         // x
	Y_LOWER,                                         // y
	Z_LOWER,                                         // z
};

#endif /* ERROR_H_INCLUDED */