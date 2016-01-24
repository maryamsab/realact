#ifndef __c5_Demo_EP_IdleRandMerg_h__
#define __c5_Demo_EP_IdleRandMerg_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_Demo_EP_IdleRandMergInstanceStruct
#define typedef_SFc5_Demo_EP_IdleRandMergInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_stateGame;
  uint8_T c5_tp_stateSt1;
  uint8_T c5_tp_stateStart;
  uint8_T c5_tp_saccadeFinish;
  uint8_T c5_tp_gameOver;
  uint8_T c5_tp_checkGameOver;
  uint8_T c5_tp_stateInit;
  uint8_T c5_tp_gazeCamera;
  uint8_T c5_tp_stateReady;
  uint8_T c5_tp_statePoseReady;
  uint8_T c5_tp_stateGo;
  uint8_T c5_tp_stateReadUserHand;
  uint8_T c5_tp_stateShowHands;
  uint8_T c5_tp_stateCompare;
  uint8_T c5_tp_stateUserWin;
  uint8_T c5_tp_stateBradWin;
  uint8_T c5_tp_stateNoWin;
  uint8_T c5_tp_stateShowResult;
  uint8_T c5_tp_statePlayHand;
  uint8_T c5_tp_stateRandomeHand;
  uint8_T c5_tp_wait;
  uint8_T c5_tp_statePoseRock;
  uint8_T c5_tp_statePosePaper;
  uint8_T c5_tp_statePoseScissors;
  uint8_T c5_tp_stateGameOver;
  uint8_T c5_b_tp_stateInit;
  uint8_T c5_tp_stateAgentNotWin;
  uint8_T c5_tp_stateAgentWin;
  uint8_T c5_tp_stateBoredom;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_Demo_EP_IdleRandMerg;
  uint8_T c5_is_stateGame;
  uint8_T c5_is_active_stateGame;
  uint8_T c5_is_statePlayHand;
  uint8_T c5_is_active_statePlayHand;
  uint8_T c5_is_stateGameOver;
  uint8_T c5_is_active_stateGameOver;
  real_T c5_newBmlsH[5000];
  real_T c5_newBmlsL[5000];
  uint32_T c5_temporalCounter_i1;
  uint32_T c5_temporalCounter_i2;
  uint32_T c5_temporalCounter_i3;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  real_T (*c5_BML_address)[1000];
  int32_T c5_BML_index;
  real_T (*c5_BML2_address)[1000];
  int32_T c5_BML2_index;
  real_T *c5_BORED_address;
  int32_T c5_BORED_index;
  real_T *c5_BOREDOM_THRESHOLD_address;
  int32_T c5_BOREDOM_THRESHOLD_index;
  real_T *c5_CONTEMPT_address;
  int32_T c5_CONTEMPT_index;
  real_T *c5_EXCITE_address;
  int32_T c5_EXCITE_index;
  real_T *c5_FEAR_address;
  int32_T c5_FEAR_index;
  real_T *c5_FRUST_address;
  int32_T c5_FRUST_index;
  real_T *c5_GAZE_GUI_address;
  int32_T c5_GAZE_GUI_index;
  real_T *c5_GAZE_SOFTEYE_address;
  int32_T c5_GAZE_SOFTEYE_index;
  real_T *c5_GAZE_USER_HAND_address;
  int32_T c5_GAZE_USER_HAND_index;
  real_T *c5_GAZE_WIN_address;
  int32_T c5_GAZE_WIN_index;
  real_T *c5_HAPPY_address;
  int32_T c5_HAPPY_index;
  real_T *c5_IDLE_address;
  int32_T c5_IDLE_index;
  real_T *c5_P_address;
  int32_T c5_P_index;
  real_T *c5_SAD_address;
  int32_T c5_SAD_index;
  real_T *c5_STATE_BEFORE_address;
  int32_T c5_STATE_BEFORE_index;
  real_T *c5_STATE_GO_address;
  int32_T c5_STATE_GO_index;
  real_T *c5_STATE_HAND_address;
  int32_T c5_STATE_HAND_index;
  real_T *c5_STATE_OVER_address;
  int32_T c5_STATE_OVER_index;
  real_T *c5_STATE_READY_address;
  int32_T c5_STATE_READY_index;
  real_T *c5_STATE_RESULT_address;
  int32_T c5_STATE_RESULT_index;
  real_T *c5_STATE_WAIT_address;
  int32_T c5_STATE_WAIT_index;
  real_T *c5_avert_address;
  int32_T c5_avert_index;
  real_T *c5_avertH_address;
  int32_T c5_avertH_index;
  real_T *c5_bHand_address;
  int32_T c5_bHand_index;
  real_T (*c5_bmlsH_address)[5000];
  int32_T c5_bmlsH_index;
  real_T (*c5_bmlsL_address)[5000];
  int32_T c5_bmlsL_index;
  real_T *c5_boredom_address;
  int32_T c5_boredom_index;
  real_T *c5_diff_address;
  int32_T c5_diff_index;
  real_T *c5_fileID_address;
  int32_T c5_fileID_index;
  real_T *c5_gazing_address;
  int32_T c5_gazing_index;
  real_T (*c5_n_address)[1000];
  int32_T c5_n_index;
  real_T *c5_pa_address;
  int32_T c5_pa_index;
  real_T *c5_pr_address;
  int32_T c5_pr_index;
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
  real_T *c5_t_address;
  int32_T c5_t_index;
  real_T *c5_temp_address;
  int32_T c5_temp_index;
  real_T *c5_uHand_address;
  int32_T c5_uHand_index;
} SFc5_Demo_EP_IdleRandMergInstanceStruct;

#endif                                 /*typedef_SFc5_Demo_EP_IdleRandMergInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info
  (void);
extern void sf_exported_auto_activate_c5_Demo_EP_IdleRandMerg_secs(SimStruct
  *c5_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c5_Demo_EP_IdleRandMerg_secs
  (SimStruct *c5_S);
extern void sf_exported_auto_resetTemporalCounter_c5_Demo_EP_IdleRandMerg_secs
  (SimStruct *c5_S);
extern void sf_exported_auto_deactivate_c5_Demo_EP_IdleRandMerg_secs(SimStruct
  *c5_S);
extern boolean_T sf_exported_auto_isStablec5_Demo_EP_IdleRandMerg(SimStruct
  *c5_S);
extern void sf_exported_auto_duringc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_enterc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_exitc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_gatewayc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_enablec5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_disablec5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_stepBuffersc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_initBuffersc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern void sf_exported_auto_activate_callc5_Demo_EP_IdleRandMerg(SimStruct
  *c5_S);
extern void sf_exported_auto_increment_call_counterc5_Demo_EP_IdleRandMerg
  (SimStruct *c5_S);
extern void sf_exported_auto_reset_call_counterc5_Demo_EP_IdleRandMerg(SimStruct
  *c5_S);
extern void sf_exported_auto_deactivate_callc5_Demo_EP_IdleRandMerg(SimStruct
  *c5_S);
extern void sf_exported_auto_initc5_Demo_EP_IdleRandMerg(SimStruct *c5_S);
extern const mxArray *sf_exported_auto_getSimstatec5_Demo_EP_IdleRandMerg
  (SimStruct *c5_S);
extern const mxArray *sf_internal_get_sim_state_c5_Demo_EP_IdleRandMerg
  (SimStruct *c5_S);
extern void sf_exported_auto_setSimstatec5_Demo_EP_IdleRandMerg(SimStruct *c5_S,
  const mxArray *c5_in);
extern void sf_internal_set_sim_state_c5_Demo_EP_IdleRandMerg(SimStruct *c5_S,
  const mxArray *c5_in);
extern void sf_exported_auto_check_state_inconsistency_c5_Demo_EP_IdleRandMerg
  (SimStruct *c5_S);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_handPoseSBTable(SimStruct
  *c5_S, real_T c5_sbmID, real_T c5_poseSBM[1000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_idlePoseBradTable(SimStruct
  *c5_S, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_initialPoseTable(SimStruct *
  c5_S, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_insertQueue(SimStruct *c5_S,
  real_T c5_bmls[5000], real_T c5_mBML[1000], real_T c5_newBmls[5000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_insertQueueLow(SimStruct
  *c5_S, real_T c5_bmls[5000], real_T c5_myBML[1000], real_T c5_newBmls[5000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_paperPoseBradTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_rockPoseTable(SimStruct
  *c5_S, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_scissorsPoseBradTable
  (SimStruct *c5_S, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000]);
extern void sf_exported_user_c5_Demo_EP_IdleRandMerg_sendSBM(SimStruct *c5_S,
  real_T c5_arg[256]);

/* Function Definitions */
extern void sf_c5_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
extern void c5_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
