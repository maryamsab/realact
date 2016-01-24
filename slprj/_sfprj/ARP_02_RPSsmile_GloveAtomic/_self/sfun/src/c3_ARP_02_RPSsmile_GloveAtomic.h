#ifndef __c3_ARP_02_RPSsmile_GloveAtomic_h__
#define __c3_ARP_02_RPSsmile_GloveAtomic_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ARP_02_RPSsmile_GloveAtomicInstanceStruct
#define typedef_SFc3_ARP_02_RPSsmile_GloveAtomicInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_ARP_02_RPSsmile_GloveAtomic;
} SFc3_ARP_02_RPSsmile_GloveAtomicInstanceStruct;

#endif                                 /*typedef_SFc3_ARP_02_RPSsmile_GloveAtomicInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_ARP_02_RPSsmile_GloveAtomic_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ARP_02_RPSsmile_GloveAtomic_get_check_sum(mxArray *plhs[]);
extern void c3_ARP_02_RPSsmile_GloveAtomic_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
