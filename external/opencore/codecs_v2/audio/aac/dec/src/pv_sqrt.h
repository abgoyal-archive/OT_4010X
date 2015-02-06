

#ifndef PV_SQRT_H
#define PV_SQRT_H

#ifdef __cplusplus
extern "C"
{
#endif

    /*----------------------------------------------------------------------------
    ; INCLUDES
    ----------------------------------------------------------------------------*/

#include "pv_audio_type_defs.h"

    /*----------------------------------------------------------------------------
    ; MACROS
    ; Define module specific macros here
    ----------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------
    ; EXTERNAL VARIABLES REFERENCES
    ----------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------
    ; DEFINES AND SIMPLE TYPEDEF'S
    ----------------------------------------------------------------------------*/

    struct intg_sqrt
    {
        Int32 root;
        Int32 shift_factor;
    };
    typedef struct intg_sqrt Root_sq;

    void pv_sqrt(Int32 man, Int32 exp, Root_sq *result, Int32 *sqrt_cache);


#ifdef __cplusplus
}
#endif

#endif  /* PV_SQRT_H */
