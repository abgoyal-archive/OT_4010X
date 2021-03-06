


#ifndef __UTF8_H__
#define __UTF8_H__

/* utf.h must be included first. */
#ifndef __UTF_H__
#   include "unicode/utf.h"
#endif

/* internal definitions ----------------------------------------------------- */

#ifdef U_UTF8_IMPL
U_INTERNAL const uint8_t 
#elif defined(U_STATIC_IMPLEMENTATION)
U_CFUNC const uint8_t
#else
U_CFUNC U_IMPORT const uint8_t /* U_IMPORT2? */ /*U_IMPORT*/ 
#endif
utf8_countTrailBytes[256];

#define U8_COUNT_TRAIL_BYTES(leadByte) (utf8_countTrailBytes[(uint8_t)leadByte])

#define U8_MASK_LEAD_BYTE(leadByte, countTrailBytes) ((leadByte)&=(1<<(6-(countTrailBytes)))-1)

U_INTERNAL UChar32 U_EXPORT2
utf8_nextCharSafeBody(const uint8_t *s, int32_t *pi, int32_t length, UChar32 c, UBool strict);

U_INTERNAL int32_t U_EXPORT2
utf8_appendCharSafeBody(uint8_t *s, int32_t i, int32_t length, UChar32 c, UBool *pIsError);

U_INTERNAL UChar32 U_EXPORT2
utf8_prevCharSafeBody(const uint8_t *s, int32_t start, int32_t *pi, UChar32 c, UBool strict);

U_INTERNAL int32_t U_EXPORT2
utf8_back1SafeBody(const uint8_t *s, int32_t start, int32_t i);

/* single-code point definitions -------------------------------------------- */

#define U8_IS_SINGLE(c) (((c)&0x80)==0)

#define U8_IS_LEAD(c) ((uint8_t)((c)-0xc0)<0x3e)

#define U8_IS_TRAIL(c) (((c)&0xc0)==0x80)

#define U8_LENGTH(c) \
    ((uint32_t)(c)<=0x7f ? 1 : \
        ((uint32_t)(c)<=0x7ff ? 2 : \
            ((uint32_t)(c)<=0xd7ff ? 3 : \
                ((uint32_t)(c)<=0xdfff || (uint32_t)(c)>0x10ffff ? 0 : \
                    ((uint32_t)(c)<=0xffff ? 3 : 4)\
                ) \
            ) \
        ) \
    )

#define U8_MAX_LENGTH 4

#define U8_GET_UNSAFE(s, i, c) { \
    int32_t _u8_get_unsafe_index=(int32_t)(i); \
    U8_SET_CP_START_UNSAFE(s, _u8_get_unsafe_index); \
    U8_NEXT_UNSAFE(s, _u8_get_unsafe_index, c); \
}

#define U8_GET(s, start, i, length, c) { \
    int32_t _u8_get_index=(int32_t)(i); \
    U8_SET_CP_START(s, start, _u8_get_index); \
    U8_NEXT(s, _u8_get_index, length, c); \
}

/* definitions with forward iteration --------------------------------------- */

#define U8_NEXT_UNSAFE(s, i, c) { \
    (c)=(s)[(i)++]; \
    if((uint8_t)((c)-0xc0)<0x35) { \
        uint8_t __count=U8_COUNT_TRAIL_BYTES(c); \
        U8_MASK_LEAD_BYTE(c, __count); \
        switch(__count) { \
        /* each following branch falls through to the next one */ \
        case 3: \
            (c)=((c)<<6)|((s)[(i)++]&0x3f); \
        case 2: \
            (c)=((c)<<6)|((s)[(i)++]&0x3f); \
        case 1: \
            (c)=((c)<<6)|((s)[(i)++]&0x3f); \
        /* no other branches to optimize switch() */ \
            break; \
        } \
    } \
}

#define U8_NEXT(s, i, length, c) { \
    (c)=(s)[(i)++]; \
    if(((uint8_t)(c))>=0x80) { \
        if(U8_IS_LEAD(c)) { \
            (c)=utf8_nextCharSafeBody((const uint8_t *)s, &(i), (int32_t)(length), c, -1); \
        } else { \
            (c)=U_SENTINEL; \
        } \
    } \
}

#define U8_APPEND_UNSAFE(s, i, c) { \
    if((uint32_t)(c)<=0x7f) { \
        (s)[(i)++]=(uint8_t)(c); \
    } else { \
        if((uint32_t)(c)<=0x7ff) { \
            (s)[(i)++]=(uint8_t)(((c)>>6)|0xc0); \
        } else { \
            if((uint32_t)(c)<=0xffff) { \
                (s)[(i)++]=(uint8_t)(((c)>>12)|0xe0); \
            } else { \
                (s)[(i)++]=(uint8_t)(((c)>>18)|0xf0); \
                (s)[(i)++]=(uint8_t)((((c)>>12)&0x3f)|0x80); \
            } \
            (s)[(i)++]=(uint8_t)((((c)>>6)&0x3f)|0x80); \
        } \
        (s)[(i)++]=(uint8_t)(((c)&0x3f)|0x80); \
    } \
}

#define U8_APPEND(s, i, length, c, isError) { \
    if((uint32_t)(c)<=0x7f) { \
        (s)[(i)++]=(uint8_t)(c); \
    } else { \
        (i)=utf8_appendCharSafeBody(s, (int32_t)(i), (int32_t)(length), c, &(isError)); \
    } \
}

#define U8_FWD_1_UNSAFE(s, i) { \
    (i)+=1+U8_COUNT_TRAIL_BYTES((s)[i]); \
}

#define U8_FWD_1(s, i, length) { \
    uint8_t __b=(s)[(i)++]; \
    if(U8_IS_LEAD(__b)) { \
        uint8_t __count=U8_COUNT_TRAIL_BYTES(__b); \
        if((i)+__count>(length)) { \
            __count=(uint8_t)((length)-(i)); \
        } \
        while(__count>0 && U8_IS_TRAIL((s)[i])) { \
            ++(i); \
            --__count; \
        } \
    } \
}

#define U8_FWD_N_UNSAFE(s, i, n) { \
    int32_t __N=(n); \
    while(__N>0) { \
        U8_FWD_1_UNSAFE(s, i); \
        --__N; \
    } \
}

#define U8_FWD_N(s, i, length, n) { \
    int32_t __N=(n); \
    while(__N>0 && (i)<(length)) { \
        U8_FWD_1(s, i, length); \
        --__N; \
    } \
}

#define U8_SET_CP_START_UNSAFE(s, i) { \
    while(U8_IS_TRAIL((s)[i])) { --(i); } \
}

#define U8_SET_CP_START(s, start, i) { \
    if(U8_IS_TRAIL((s)[(i)])) { \
        (i)=utf8_back1SafeBody(s, start, (int32_t)(i)); \
    } \
}

/* definitions with backward iteration -------------------------------------- */

#define U8_PREV_UNSAFE(s, i, c) { \
    (c)=(s)[--(i)]; \
    if(U8_IS_TRAIL(c)) { \
        uint8_t __b, __count=1, __shift=6; \
\
        /* c is a trail byte */ \
        (c)&=0x3f; \
        for(;;) { \
            __b=(s)[--(i)]; \
            if(__b>=0xc0) { \
                U8_MASK_LEAD_BYTE(__b, __count); \
                (c)|=(UChar32)__b<<__shift; \
                break; \
            } else { \
                (c)|=(UChar32)(__b&0x3f)<<__shift; \
                ++__count; \
                __shift+=6; \
            } \
        } \
    } \
}

#define U8_PREV(s, start, i, c) { \
    (c)=(s)[--(i)]; \
    if((c)>=0x80) { \
        if((c)<=0xbf) { \
            (c)=utf8_prevCharSafeBody(s, start, &(i), c, -1); \
        } else { \
            (c)=U_SENTINEL; \
        } \
    } \
}

#define U8_BACK_1_UNSAFE(s, i) { \
    while(U8_IS_TRAIL((s)[--(i)])) {} \
}

#define U8_BACK_1(s, start, i) { \
    if(U8_IS_TRAIL((s)[--(i)])) { \
        (i)=utf8_back1SafeBody(s, start, (int32_t)(i)); \
    } \
}

#define U8_BACK_N_UNSAFE(s, i, n) { \
    int32_t __N=(n); \
    while(__N>0) { \
        U8_BACK_1_UNSAFE(s, i); \
        --__N; \
    } \
}

#define U8_BACK_N(s, start, i, n) { \
    int32_t __N=(n); \
    while(__N>0 && (i)>(start)) { \
        U8_BACK_1(s, start, i); \
        --__N; \
    } \
}

#define U8_SET_CP_LIMIT_UNSAFE(s, i) { \
    U8_BACK_1_UNSAFE(s, i); \
    U8_FWD_1_UNSAFE(s, i); \
}

#define U8_SET_CP_LIMIT(s, start, i, length) { \
    if((start)<(i) && (i)<(length)) { \
        U8_BACK_1(s, start, i); \
        U8_FWD_1(s, i, length); \
    } \
}

#endif
