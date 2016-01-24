#ifndef __c2_testPriorityQueue_h__
#define __c2_testPriorityQueue_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_testPriorityQueueInstanceStruct
#define typedef_SFc2_testPriorityQueueInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_a;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_testPriorityQueue;
  uint8_T c2_is_c2_testPriorityQueue;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_testPriorityQueueInstanceStruct;

#endif                                 /*typedef_SFc2_testPriorityQueueInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_testPriorityQueue_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_testPriorityQueue_get_check_sum(mxArray *plhs[]);
extern void c2_testPriorityQueue_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
