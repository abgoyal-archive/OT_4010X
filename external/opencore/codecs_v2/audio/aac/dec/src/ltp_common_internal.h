

#ifndef _LTP_COMMON_INTERNAL_H
#define _LTP_COMMON_INTERNAL_H


#define LPC 1

#define DELAY 2048

#define LEN_LTP_DATA_PRESENT 1

#define LEN_LTP_LAG 11

#define LEN_LTP_COEF 3

#define LEN_LTP_SHORT_USED 1

#define LEN_LTP_SHORT_LAG_PRESENT 1

#define LEN_LTP_SHORT_LAG 5

#define LTP_LAG_OFFSET 16

#define LEN_LTP_LONG_USED 1

#define MAX_LT_PRED_LONG_SFB 40

#define MAX_LT_PRED_SHORT_SFB 13

#define SHORT_SQ_OFFSET (BLOCK_LEN_LONG-(BLOCK_LEN_SHORT*4+BLOCK_LEN_SHORT/2))

#define CODESIZE 8

/* number of scalefactor bands used for reconstruction for short windows */
#define NUM_RECONSTRUCTED_SFB (8)

#endif /* _LTP_COMMON_INTERNAL_H */
