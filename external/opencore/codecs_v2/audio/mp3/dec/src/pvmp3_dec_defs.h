

#ifndef PVMP3_DEC_DEFS_H
#define PVMP3_DEC_DEFS_H

#include "pvmp3_audio_type_defs.h"
#include "pvmp3decoder_api.h"

#define module(x, POW2)   ((x)&(POW2-1))

#define BUFSIZE   8192   // big enough to hold 4608 bytes == biggest mp3 frame

#define CHAN           2
#define GRAN           2


#define SUBBANDS_NUMBER        32
#define FILTERBANK_BANDS       18
#define HAN_SIZE              512


/* MPEG Header Definitions - ID Bit Values */

#define MPEG_1              0
#define MPEG_2              1
#define MPEG_2_5            2
#define INVALID_VERSION     -1

/* MPEG Header Definitions - Mode Values */

#define MPG_MD_STEREO           0
#define MPG_MD_JOINT_STEREO     1
#define MPG_MD_DUAL_CHANNEL     2
#define MPG_MD_MONO             3



#define LEFT        0
#define RIGHT       1


#define SYNC_WORD         (int32)0x7ff
#define SYNC_WORD_LNGTH   11



#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum ERROR_CODE
    {
        NO_DECODING_ERROR         = 0,
        UNSUPPORTED_LAYER         = 1,
        UNSUPPORTED_FREE_BITRATE  = 2,
        FILE_OPEN_ERROR           = 3,          /* error opening file */
        CHANNEL_CONFIG_ERROR      = 4,     /* error in channel configuration */
        SYNTHESIS_WINDOW_ERROR    = 5,   /* error in synthesis window table */
        READ_FILE_ERROR           = 6,          /* error reading input file */
        SIDE_INFO_ERROR           = 7,          /* error in side info */
        HUFFMAN_TABLE_ERROR       = 8,      /* error in Huffman table */
        COMMAND_LINE_ERROR        = 9,       /* error in command line */
        MEMORY_ALLOCATION_ERROR   = 10,   /* error allocating memory */
        NO_ENOUGH_MAIN_DATA_ERROR = 11,
        SYNCH_LOST_ERROR          = 12,
        OUTPUT_BUFFER_TOO_SMALL   = 13     /* output buffer can't hold output */
    } ERROR_CODE;

    /*----------------------------------------------------------------------------
    ; STRUCTURES TYPEDEF'S
    ----------------------------------------------------------------------------*/

    /* Header Information Structure */

    typedef struct
    {
        int32 version_x;
        int32 layer_description;
        int32 error_protection;
        int32 bitrate_index;
        int32 sampling_frequency;
        int32 padding;
        int32 extension;
        int32 mode;
        int32 mode_ext;
        int32 copyright;
        int32 original;
        int32 emphasis;
    } mp3Header;


    /* Layer III side information. */

    typedef  struct
    {
        uint32 part2_3_length;
        uint32 big_values;
        int32 global_gain;
        uint32 scalefac_compress;
        uint32 window_switching_flag;
        uint32 block_type;
        uint32 mixed_block_flag;
        uint32 table_select[3];
        uint32 subblock_gain[3];
        uint32 region0_count;
        uint32 region1_count;
        uint32 preflag;
        uint32 scalefac_scale;
        uint32 count1table_select;

    } granuleInfo;

    typedef  struct
    {
        uint32      scfsi[4];
        granuleInfo gran[2];

    } channelInfo;

    /* Layer III side info. */

    typedef struct
    {
        uint32      main_data_begin;
        uint32      private_bits;
        channelInfo ch[2];

    } mp3SideInfo;

    /* Layer III scale factors. */
    typedef struct
    {
        int32 l[23];            /* [cb] */
        int32 s[3][13];         /* [window][cb] */

    } mp3ScaleFactors;


#ifdef __cplusplus
}
#endif



#endif



