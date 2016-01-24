#ifndef __c3_testPriorityQueue_h__
#define __c3_testPriorityQueue_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_testPriorityQueueInstanceStruct
#define typedef_SFc3_testPriorityQueueInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_A1;
  uint8_T c3_tp_B1;
  uint8_T c3_tp_A2;
  uint8_T c3_tp_B2;
  uint8_T c3_tp_pr2;
  uint8_T c3_tp_pr1;
  uint8_T c3_tp_A3;
  uint8_T c3_tp_B3;
  uint8_T c3_tp_pr3;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_testPriorityQueue;
  uint8_T c3_is_pr2;
  uint8_T c3_is_active_pr2;
  uint8_T c3_is_pr1;
  uint8_T c3_is_active_pr1;
  uint8_T c3_is_pr3;
  uint8_T c3_is_active_pr3;
  uint8_T c3_temporalCounter_i1;
  uint8_T c3_temporalCounter_i2;
  uint8_T c3_temporalCounter_i3;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_testPriorityQueueInstanceStruct;

#endif                                 /*typedef_SFc3_testPriorityQueueInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_testPriorityQueue_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_testPriorityQueue_get_check_sum(mxArray *plhs[]);
extern void c3_testPriorityQueue_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
