#ifndef __c3_testKinectRPS_h__
#define __c3_testKinectRPS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_testKinectRPSInstanceStruct
#define typedef_SFc3_testKinectRPSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_stateReadUserHand;
  uint8_T c3_tp_statePlayHand;
  uint8_T c3_tp_start;
  uint8_T c3_tp_stateShowReady;
  uint8_T c3_tp_stateCompare;
  uint8_T c3_tp_stateShowResult;
  uint8_T c3_tp_stateShowGo;
  uint8_T c3_tp_stateBradWin;
  uint8_T c3_tp_stateUserWin;
  uint8_T c3_tp_stateShowUserHand;
  uint8_T c3_tp_stateNoWin;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_testKinectRPS;
  uint8_T c3_is_c3_testKinectRPS;
  real_T c3_bradHand;
  real_T c3_win;
  real_T c3_diff;
  real_T c3_userHand;
  real_T c3_temp;
  uint16_T c3_temporalCounter_i1;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_testKinectRPSInstanceStruct;

#endif                                 /*typedef_SFc3_testKinectRPSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_testKinectRPS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_testKinectRPS_get_check_sum(mxArray *plhs[]);
extern void c3_testKinectRPS_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
