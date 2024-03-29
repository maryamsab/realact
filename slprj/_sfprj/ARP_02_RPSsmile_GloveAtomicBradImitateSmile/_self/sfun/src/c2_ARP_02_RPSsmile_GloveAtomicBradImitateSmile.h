#ifndef __c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_h__
#define __c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct
#define typedef_SFc2_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile;
} SFc2_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc2_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void c2_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
