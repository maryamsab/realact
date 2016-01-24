#ifndef __c1_ARP_02_RPSsmile_Glove_h__
#define __c1_ARP_02_RPSsmile_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_ARP_02_RPSsmile_GloveInstanceStruct
#define typedef_SFc1_ARP_02_RPSsmile_GloveInstanceStruct

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
  uint8_T c1_tp_stateInitial;
  uint8_T c1_tp_stateHeadNeutral;
  uint8_T c1_tp_stateAvertGaze;
  uint8_T c1_tp_stateAvertHead;
  uint8_T c1_tp_stateIdlePose;
  uint8_T c1_tp_stateRandomPose;
  uint8_T c1_tp_stateBoredPose;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ARP_02_RPSsmile_Glove;
  uint8_T c1_is_stateGame;
  uint8_T c1_is_active_stateGame;
  uint8_T c1_is_stateIdleGaze;
  uint8_T c1_is_active_stateIdleGaze;
  uint8_T c1_is_stateIdlePose;
  uint8_T c1_is_active_stateIdlePose;
  real_T c1_temp;
  real_T c1_diff;
  real_T c1_uHand;
  real_T c1_bHand;
  real_T c1_smileN;
  real_T c1_smileYN;
  real_T c1_bored;
  real_T c1_BOREDOMT;
  real_T c1_randomG;
  real_T c1_randomP;
  real_T c1_pose;
  real_T c1_b;
  real_T c1_r;
  real_T c1_p;
  real_T c1_s;
  real_T c1_randomD;
  real_T c1_wristRotate;
  real_T c1_randomH;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state;
  boolean_T c1_state_not_empty;
  uint32_T c1_b_state[2];
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[625];
  boolean_T c1_c_state_not_empty;
  uint8_T c1_temporalCounter_i1;
  uint32_T c1_temporalCounter_i2;
  uint8_T c1_temporalCounter_i3;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_ARP_02_RPSsmile_GloveInstanceStruct;

#endif                                 /*typedef_SFc1_ARP_02_RPSsmile_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_ARP_02_RPSsmile_Glove_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_ARP_02_RPSsmile_Glove_get_check_sum(mxArray *plhs[]);
extern void c1_ARP_02_RPSsmile_Glove_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
