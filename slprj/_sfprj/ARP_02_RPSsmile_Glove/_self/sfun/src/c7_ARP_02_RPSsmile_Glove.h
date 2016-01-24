#ifndef __c7_ARP_02_RPSsmile_Glove_h__
#define __c7_ARP_02_RPSsmile_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_ARP_02_RPSsmile_GloveInstanceStruct
#define typedef_SFc7_ARP_02_RPSsmile_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  uint8_T c7_tp_statePosePaper;
  uint8_T c7_tp_statePoseReturnWrist;
  uint8_T c7_tp_stateStart;
  uint8_T c7_tp_statePoseScissors;
  uint8_T c7_tp_statePoseRock;
  uint8_T c7_tp_stateReadUserHand;
  uint8_T c7_tp_stateShowHands;
  uint8_T c7_tp_stateReady;
  uint8_T c7_tp_statePoseReturnFinger;
  uint8_T c7_tp_gameOver;
  uint8_T c7_tp_stateNoWin;
  uint8_T c7_tp_stateBradWin;
  uint8_T c7_tp_stateHeadNeutral2;
  uint8_T c7_tp_statePoseReady;
  uint8_T c7_tp_stateIfSmile;
  uint8_T c7_tp_statePoseSmileWin;
  uint8_T c7_tp_stateHeadNeutral1;
  uint8_T c7_tp_stateGo;
  uint8_T c7_tp_stateSmile;
  uint8_T c7_tp_statePoseSmile;
  uint8_T c7_tp_stateCompare;
  uint8_T c7_tp_stateNeckBack;
  uint8_T c7_tp_stateWristRotate;
  uint8_T c7_tp_stateRandomHand;
  uint8_T c7_tp_stateShowResult;
  uint8_T c7_tp_stateBrowUp;
  uint8_T c7_tp_stateRandom1;
  uint8_T c7_tp_stateBoredPose1;
  uint8_T c7_tp_statePoseFingersCLose;
  uint8_T c7_tp_stateUserWin;
  boolean_T c7_isStable;
  uint8_T c7_is_active_c7_ARP_02_RPSsmile_Glove;
  uint8_T c7_is_c7_ARP_02_RPSsmile_Glove;
  uint32_T c7_method;
  boolean_T c7_method_not_empty;
  uint32_T c7_state;
  boolean_T c7_state_not_empty;
  uint32_T c7_b_state[2];
  boolean_T c7_b_state_not_empty;
  uint32_T c7_c_state[625];
  boolean_T c7_c_state_not_empty;
  uint8_T c7_temporalCounter_i1;
  uint8_T c7_doSetSimStateSideEffects;
  const mxArray *c7_setSimStateSideEffectsInfo;
  real_T *c7_BOREDOMT_address;
  int32_T c7_BOREDOMT_index;
  real_T *c7_avert_address;
  int32_T c7_avert_index;
  real_T *c7_bHand_address;
  int32_T c7_bHand_index;
  real_T *c7_bored_address;
  int32_T c7_bored_index;
  real_T *c7_diff_address;
  int32_T c7_diff_index;
  real_T *c7_p_address;
  int32_T c7_p_index;
  real_T *c7_pSmile_address;
  int32_T c7_pSmile_index;
  real_T *c7_pose_address;
  int32_T c7_pose_index;
  real_T *c7_r_address;
  int32_T c7_r_index;
  real_T *c7_randomG_address;
  int32_T c7_randomG_index;
  real_T *c7_randomP_address;
  int32_T c7_randomP_index;
  real_T *c7_s_address;
  int32_T c7_s_index;
  real_T *c7_smileN_address;
  int32_T c7_smileN_index;
  real_T *c7_smileYN_address;
  int32_T c7_smileYN_index;
  real_T *c7_temp_address;
  int32_T c7_temp_index;
  real_T *c7_uHand_address;
  int32_T c7_uHand_index;
  real_T *c7_wristRotate_address;
  int32_T c7_wristRotate_index;
} SFc7_ARP_02_RPSsmile_GloveInstanceStruct;

#endif                                 /*typedef_SFc7_ARP_02_RPSsmile_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_ARP_02_RPSsmile_Glove_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c7_ARP_02_RPSsmile_Glove_secs(SimStruct
  *c7_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c7_ARP_02_RPSsmile_Glove_secs
  (SimStruct *c7_S);
extern void sf_exported_auto_resetTemporalCounter_c7_ARP_02_RPSsmile_Glove_secs
  (SimStruct *c7_S);
extern void sf_exported_auto_deactivate_c7_ARP_02_RPSsmile_Glove_secs(SimStruct *
  c7_S);
extern boolean_T sf_exported_auto_isStablec7_ARP_02_RPSsmile_Glove(SimStruct
  *c7_S);
extern void sf_exported_auto_duringc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_enterc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_exitc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_gatewayc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_enablec7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_disablec7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_stepBuffersc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_initBuffersc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern void sf_exported_auto_activate_callc7_ARP_02_RPSsmile_Glove(SimStruct
  *c7_S);
extern void sf_exported_auto_increment_call_counterc7_ARP_02_RPSsmile_Glove
  (SimStruct *c7_S);
extern void sf_exported_auto_reset_call_counterc7_ARP_02_RPSsmile_Glove
  (SimStruct *c7_S);
extern void sf_exported_auto_deactivate_callc7_ARP_02_RPSsmile_Glove(SimStruct
  *c7_S);
extern void sf_exported_auto_initc7_ARP_02_RPSsmile_Glove(SimStruct *c7_S);
extern const mxArray *sf_exported_auto_getSimstatec7_ARP_02_RPSsmile_Glove
  (SimStruct *c7_S);
extern const mxArray *sf_internal_get_sim_state_c7_ARP_02_RPSsmile_Glove
  (SimStruct *c7_S);
extern void sf_exported_auto_setSimstatec7_ARP_02_RPSsmile_Glove(SimStruct *c7_S,
  const mxArray *c7_in);
extern void sf_internal_set_sim_state_c7_ARP_02_RPSsmile_Glove(SimStruct *c7_S,
  const mxArray *c7_in);
extern void sf_exported_auto_check_state_inconsistency_c7_ARP_02_RPSsmile_Glove
  (SimStruct *c7_S);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_boredGaze(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_gazeBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_boredPose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_boredPoseS(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_handPoseSB(SimStruct *c7_S,
  real_T c7_sbmID, real_T c7_poseSBM[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_idlePose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_paperPose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_rockPose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_scissorsPose(SimStruct
  *c7_S, real_T c7_bmlID, real_T c7_poseBML[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_sendBML(SimStruct *c7_S,
  real_T c7_arg[256]);
extern void sf_exported_user_c7_ARP_02_RPSsmile_Glove_sendSBM(SimStruct *c7_S,
  real_T c7_arg[256]);

/* Function Definitions */
extern void sf_c7_ARP_02_RPSsmile_Glove_get_check_sum(mxArray *plhs[]);
extern void c7_ARP_02_RPSsmile_Glove_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
