#ifndef __c1_ARP_02_RPSsmile_Glove_atomicError_h__
#define __c1_ARP_02_RPSsmile_Glove_atomicError_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
#define typedef_SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_stateGame;
  uint8_T c1_tp_stateStart;
  uint8_T c1_tp_stateReady;
  uint8_T c1_tp_gameOver;
  uint8_T c1_tp_stateIfSmile;
  uint8_T c1_tp_statePoseReady;
  uint8_T c1_tp_stateHeadNeutral2;
  uint8_T c1_tp_statePoseSmile;
  uint8_T c1_tp_stateGo;
  uint8_T c1_tp_stateSmile;
  uint8_T c1_tp_stateWristRotate;
  uint8_T c1_tp_stateNeckBack;
  uint8_T c1_tp_stateRandomHand;
  uint8_T c1_tp_stateBrowUp;
  uint8_T c1_tp_statePoseRock;
  uint8_T c1_tp_statePoseFingersCLose;
  uint8_T c1_tp_statePosePaper;
  uint8_T c1_tp_stateReadUserHand;
  uint8_T c1_tp_statePoseScissors;
  uint8_T c1_tp_stateShowHands;
  uint8_T c1_tp_stateBoredPose1;
  uint8_T c1_tp_statePoseReturnFinger;
  uint8_T c1_tp_stateCompare;
  uint8_T c1_tp_statePoseReturnWrist;
  uint8_T c1_tp_stateUserWin;
  uint8_T c1_tp_stateNoWin;
  uint8_T c1_tp_stateBradWin;
  uint8_T c1_tp_stateRandom1;
  uint8_T c1_tp_stateHeadNeutral1;
  uint8_T c1_tp_statePoseSmileWin;
  uint8_T c1_tp_stateShowResult;
  uint8_T c1_tp_stateIdleGaze;
  uint8_T c1_tp_stateIdlePose;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError;
  uint8_T c1_is_stateGame;
  uint8_T c1_is_active_stateGame;
  uint8_T c1_is_active_stateIdleGaze;
  uint8_T c1_is_active_stateIdlePose;
  real_T c1_temp;
  real_T c1_diff;
  real_T c1_uHand;
  real_T c1_bHand;
  real_T c1_smileN;
  real_T c1_smileYN;
  real_T c1_r;
  real_T c1_p;
  real_T c1_s;
  real_T c1_wristRotate;
  real_T c1_randomH;
  SimStruct *c1_subchartSimstruct;
  SimStruct *c1_b_subchartSimstruct;
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
  real_T *c1_BOREDOMT_address;
  int32_T c1_BOREDOMT_index;
  real_T *c1_b_address;
  int32_T c1_b_index;
  real_T *c1_bored_address;
  int32_T c1_bored_index;
  real_T *c1_pose_address;
  int32_T c1_pose_index;
  real_T *c1_randomD_address;
  int32_T c1_randomD_index;
  real_T *c1_randomG_address;
  int32_T c1_randomG_index;
  real_T *c1_randomP_address;
  int32_T c1_randomP_index;
} SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct;

#endif                                 /*typedef_SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_ARP_02_RPSsmile_Glove_atomicError_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_gatewayc10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_gatewayc11_lib_affectiveChar_scenario(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c10_ARP_02_RPSsmile_Glove_atomicError_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_ARP_02_RPSsmile_Glove_atomicError_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c10_ARP_02_RPSsmile_Glove_atomicError_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c10_ARP_02_RPSsmile_Glove_atomicError_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc11_lib_affectiveChar_scenario(SimStruct
  *c1_S);
extern void sf_exported_auto_enterc10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_duringc10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_enterc11_lib_affectiveChar_scenario(SimStruct *c1_S);
extern void sf_exported_auto_duringc11_lib_affectiveChar_scenario(SimStruct
  *c1_S);
extern void sf_exported_auto_enablec10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_enablec11_lib_affectiveChar_scenario(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_disablec11_lib_affectiveChar_scenario(SimStruct
  *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c11_lib_affectiveChar_scenario
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec10_ARP_02_RPSsmile_Glove_atomicError(SimStruct
  *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec11_lib_affectiveChar_scenario
  (SimStruct *c1_S);
extern void sf_exported_auto_setSimstatec10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec11_lib_affectiveChar_scenario(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_initc10_ARP_02_RPSsmile_Glove_atomicError(SimStruct
  *c1_S);
extern void sf_exported_auto_initc11_lib_affectiveChar_scenario(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc10_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc11_lib_affectiveChar_scenario(SimStruct
  *c1_S);

/* Function Definitions */
extern void sf_c1_ARP_02_RPSsmile_Glove_atomicError_get_check_sum(mxArray *plhs[]);
extern void c1_ARP_02_RPSsmile_Glove_atomicError_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
