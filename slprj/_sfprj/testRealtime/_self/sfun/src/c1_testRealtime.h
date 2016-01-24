#ifndef __c1_testRealtime_h__
#define __c1_testRealtime_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_testRealtimeInstanceStruct
#define typedef_SFc1_testRealtimeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_start;
  uint8_T c1_tp_stateShowReady;
  uint8_T c1_tp_BradLeanForward;
  uint8_T c1_tp_smile;
  uint8_T c1_tp_stateShowGo;
  uint8_T c1_tp_stateRandomHand;
  uint8_T c1_tp_stateReadUserHand;
  uint8_T c1_tp_stateFingersCLose;
  uint8_T c1_tp_smile1;
  uint8_T c1_tp_statePlayHand;
  uint8_T c1_tp_stateShowHands;
  uint8_T c1_tp_stateCompare;
  uint8_T c1_tp_stateUserWin;
  uint8_T c1_tp_stateBradWin;
  uint8_T c1_tp_stateNoWin;
  uint8_T c1_tp_stateShowResult;
  uint8_T c1_tp_returnFinger;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_testRealtime;
  uint8_T c1_is_c1_testRealtime;
  real_T c1_temp;
  real_T c1_diff;
  real_T c1_uHand;
  real_T c1_bHand;
  real_T c1_smileN;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state;
  boolean_T c1_state_not_empty;
  uint32_T c1_b_state[2];
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[625];
  boolean_T c1_c_state_not_empty;
  uint16_T c1_temporalCounter_i1;
  uint8_T c1_temporalCounter_i2;
  uint32_T c1_presentTicks;
  uint32_T c1_elapsedTicks;
  uint32_T c1_previousTicks;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_testRealtimeInstanceStruct;

#endif                                 /*typedef_SFc1_testRealtimeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_testRealtime_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_testRealtime_get_check_sum(mxArray *plhs[]);
extern void c1_testRealtime_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
