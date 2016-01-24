#ifndef __c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_h__
#define __c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct
#define typedef_SFc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_statePlayHand;
  uint8_T c5_tp_stateRandomeHand;
  uint8_T c5_tp_statePoseFingersCLose;
  uint8_T c5_tp_statePosePaper;
  uint8_T c5_tp_statePoseRock;
  uint8_T c5_tp_statePoseScissors;
  uint8_T c5_tp_stateGame;
  uint8_T c5_tp_stateStart;
  uint8_T c5_tp_stateInPlace;
  uint8_T c5_tp_stateReady;
  uint8_T c5_tp_stateInit;
  uint8_T c5_tp_statePoseReady;
  uint8_T c5_tp_gameOver;
  uint8_T c5_tp_stateGo;
  uint8_T c5_tp_stateReadUserHand;
  uint8_T c5_tp_stateShowHands;
  uint8_T c5_tp_statePoseReturnFinger;
  uint8_T c5_tp_stateCompare;
  uint8_T c5_tp_stateUserWin;
  uint8_T c5_tp_stateBradWin;
  uint8_T c5_tp_stateNoWin;
  uint8_T c5_tp_stateShowResult;
  uint8_T c5_tp_stateGameOver;
  uint8_T c5_b_tp_stateInit;
  uint8_T c5_tp_stateHeadNeutral2;
  uint8_T c5_tp_stateAgentNotWin;
  uint8_T c5_tp_stateAgentWin;
  uint8_T c5_tp_stateBoredom;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile;
  uint8_T c5_is_statePlayHand;
  uint8_T c5_is_active_statePlayHand;
  uint8_T c5_is_stateGame;
  uint8_T c5_is_active_stateGame;
  uint8_T c5_is_stateGameOver;
  uint8_T c5_is_active_stateGameOver;
  uint32_T c5_method;
  boolean_T c5_method_not_empty;
  uint32_T c5_state;
  boolean_T c5_state_not_empty;
  uint32_T c5_b_state[2];
  boolean_T c5_b_state_not_empty;
  uint32_T c5_c_state[625];
  boolean_T c5_c_state_not_empty;
  uint8_T c5_temporalCounter_i1;
  uint8_T c5_temporalCounter_i2;
  uint8_T c5_temporalCounter_i3;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  real_T *c5_BOREDOM_THRESHOLD_address;
  int32_T c5_BOREDOM_THRESHOLD_index;
  real_T *c5_GAZE_GUI_address;
  int32_T c5_GAZE_GUI_index;
  real_T *c5_GAZE_SHOFTEYE_address;
  int32_T c5_GAZE_SHOFTEYE_index;
  real_T *c5_GAZE_USER_HAND_address;
  int32_T c5_GAZE_USER_HAND_index;
  real_T *c5_GAZE_WIN_address;
  int32_T c5_GAZE_WIN_index;
  real_T *c5_STATE_GO_address;
  int32_T c5_STATE_GO_index;
  real_T *c5_STATE_HAND_address;
  int32_T c5_STATE_HAND_index;
  real_T *c5_STATE_OVER_address;
  int32_T c5_STATE_OVER_index;
  real_T *c5_STATE_READY_address;
  int32_T c5_STATE_READY_index;
  real_T *c5_avert_address;
  int32_T c5_avert_index;
  real_T *c5_bHand_address;
  int32_T c5_bHand_index;
  real_T *c5_boredom_address;
  int32_T c5_boredom_index;
  real_T *c5_diff_address;
  int32_T c5_diff_index;
  real_T *c5_gameOver_address;
  int32_T c5_gameOver_index;
  real_T *c5_gazing_address;
  int32_T c5_gazing_index;
  real_T *c5_isPosing_address;
  int32_T c5_isPosing_index;
  real_T *c5_p_address;
  int32_T c5_p_index;
  real_T *c5_r_address;
  int32_T c5_r_index;
  real_T *c5_randAvertGazeChance_address;
  int32_T c5_randAvertGazeChance_index;
  real_T *c5_randPoseChance_address;
  int32_T c5_randPoseChance_index;
  real_T *c5_randSmile_address;
  int32_T c5_randSmile_index;
  real_T *c5_s_address;
  int32_T c5_s_index;
  real_T *c5_smileN_address;
  int32_T c5_smileN_index;
  real_T *c5_temp_address;
  int32_T c5_temp_index;
  real_T *c5_uHand_address;
  int32_T c5_uHand_index;
} SFc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_activate_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_secs
  (SimStruct *c5_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_secs
  (SimStruct *c5_S);
extern void
  sf_exported_auto_resetTemporalCounter_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_secs
  (SimStruct *c5_S);
extern void
  sf_exported_auto_deactivate_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_secs
  (SimStruct *c5_S);
extern boolean_T
  sf_exported_auto_isStablec5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_duringc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void sf_exported_auto_enterc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void sf_exported_auto_exitc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_gatewayc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_enablec5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_disablec5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_stepBuffersc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_initBuffersc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_activate_callc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_increment_call_counterc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_reset_call_counterc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_deactivate_callc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void sf_exported_auto_initc5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern const mxArray
  *sf_exported_auto_getSimstatec5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern const mxArray
  *sf_internal_get_sim_state_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_auto_setSimstatec5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S, const mxArray *c5_in);
extern void
  sf_internal_set_sim_state_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S, const mxArray *c5_in);
extern void
  sf_exported_auto_check_state_inconsistency_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile
  (SimStruct *c5_S);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_handPoseSBTable
  (SimStruct *c5_S, real_T c5_sbmID, real_T c5_poseSBM[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_idlePoseBradTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T c5_poseBML[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_initialPoseTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T c5_poseBML[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_paperPoseBradTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T c5_poseBML[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_rockPoseTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T c5_poseBML[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_scissorsPoseBradTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T c5_poseBML[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_sendBML
  (SimStruct *c5_S, real_T c5_arg[256]);
extern void
  sf_exported_user_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_sendSBM
  (SimStruct *c5_S, real_T c5_arg[256]);

/* Function Definitions */
extern void sf_c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void c5_ARP_02_RPSsmile_GloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
