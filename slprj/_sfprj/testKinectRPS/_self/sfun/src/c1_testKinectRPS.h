#ifndef __c1_testKinectRPS_h__
#define __c1_testKinectRPS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_testKinectRPSInstanceStruct
#define typedef_SFc1_testKinectRPSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_stateShowUserHand;
  uint8_T c1_tp_statePlayHand;
  uint8_T c1_tp_stateNoWin;
  uint8_T c1_tp_stateBradWin;
  uint8_T c1_tp_stateUserWin;
  uint8_T c1_tp_start;
  uint8_T c1_tp_stateCompare;
  uint8_T c1_tp_stateShowReady;
  uint8_T c1_tp_stateShowResult;
  uint8_T c1_tp_stateShowGo;
  uint8_T c1_tp_stateReadUserHand;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_testKinectRPS;
  uint8_T c1_is_c1_testKinectRPS;
  real_T c1_bradHand;
  real_T c1_temp;
  real_T c1_userHand;
  real_T c1_diff;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state;
  boolean_T c1_state_not_empty;
  uint32_T c1_b_state[2];
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[625];
  boolean_T c1_c_state_not_empty;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_testKinectRPSInstanceStruct;

#endif                                 /*typedef_SFc1_testKinectRPSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_testKinectRPS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_testKinectRPS_get_check_sum(mxArray *plhs[]);
extern void c1_testKinectRPS_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
