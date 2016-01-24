#ifndef __c57_Expriment_All2_h__
#define __c57_Expriment_All2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc57_Expriment_All2InstanceStruct
#define typedef_SFc57_Expriment_All2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c57_sfEvent;
  uint8_T c57_tp_headAvert;
  uint8_T c57_tp_stateInit1;
  uint8_T c57_tp_stateRandGen1;
  uint8_T c57_tp_stateHeadNeutralN1;
  uint8_T c57_tp_stateAvertHeadNormal;
  uint8_T c57_tp_stateHeadNeutralF1;
  uint8_T c57_tp_stateAvertHeadFast;
  uint8_T c57_tp_stateHeadNeutralS1;
  uint8_T c57_tp_stateAvertHeadSlow;
  uint8_T c57_tp_stateGazingGUI;
  uint8_T c57_tp_stateGazingUserHand;
  uint8_T c57_tp_stateGazeIde;
  uint8_T c57_tp_setBlinkRate;
  uint8_T c57_tp_stateInit;
  uint8_T c57_tp_mutAgain;
  uint8_T c57_tp_stateCheckMutCont;
  uint8_T c57_tp_stateAvert;
  uint8_T c57_tp_stateAvertEye;
  uint8_T c57_tp_stateAvertHead;
  uint8_T c57_tp_stateMutualGazeE;
  uint8_T c57_tp_stateCheckAvertCont;
  boolean_T c57_isStable;
  uint8_T c57_is_active_c57_Expriment_All2;
  uint8_T c57_is_headAvert;
  uint8_T c57_is_active_headAvert;
  uint8_T c57_is_stateGazeIde;
  uint8_T c57_is_active_stateGazeIde;
  real_T c57_randHeadDur;
  real_T c57_randHeadDurOver;
  real_T c57_avertContChance;
  real_T c57_gazeGUIChance;
  real_T c57_mutContChance;
  real_T c57_mutContF[3];
  real_T c57_CHANCEM;
  real_T c57_avertDur;
  real_T c57_gazeDir;
  real_T c57_CHANCEA;
  real_T c57_magnitude;
  real_T c57_randHeadChance;
  real_T c57_avertContF[3];
  real_T c57_gazeUserHandChance;
  real_T c57_chanceO;
  real_T c57_BMLl[1000];
  real_T c57_newBmlsL[5000];
  real_T c57_n[1000];
  real_T c57_mutDur;
  real_T c57_mF;
  real_T c57_hF;
  real_T c57_aF;
  real_T c57_mFe;
  real_T c57_hFe;
  real_T c57_aFe;
  real_T c57_chanceH;
  real_T c57_currentTime;
  real_T c57_str[1000];
  uint32_T c57_temporalCounter_i1;
  uint32_T c57_temporalCounter_i2;
  uint8_T c57_doSetSimStateSideEffects;
  const mxArray *c57_setSimStateSideEffectsInfo;
  real_T (*c57_BML_address)[1000];
  int32_T c57_BML_index;
  real_T *c57_BOREDOM_THRESHOLD_address;
  int32_T c57_BOREDOM_THRESHOLD_index;
  real_T *c57_GAZE_GUI_address;
  int32_T c57_GAZE_GUI_index;
  real_T *c57_GAZE_SOFTEYE_address;
  int32_T c57_GAZE_SOFTEYE_index;
  real_T *c57_GAZE_USER_HAND_address;
  int32_T c57_GAZE_USER_HAND_index;
  real_T *c57_GAZE_WIN_address;
  int32_T c57_GAZE_WIN_index;
  real_T *c57_P_address;
  int32_T c57_P_index;
  real_T *c57_STATE_BEFORE_address;
  int32_T c57_STATE_BEFORE_index;
  real_T *c57_STATE_GO_address;
  int32_T c57_STATE_GO_index;
  real_T *c57_STATE_OVER_address;
  int32_T c57_STATE_OVER_index;
  real_T *c57_STATE_READY_address;
  int32_T c57_STATE_READY_index;
  real_T *c57_avert_address;
  int32_T c57_avert_index;
  real_T *c57_avertH_address;
  int32_T c57_avertH_index;
  real_T *c57_avert_freq_factor_address;
  int32_T c57_avert_freq_factor_index;
  real_T *c57_avert_gaze_dirs_chance_address;
  int32_T c57_avert_gaze_dirs_chance_index;
  real_T *c57_avert_gaze_duration_factor_address;
  int32_T c57_avert_gaze_duration_factor_index;
  real_T *c57_avert_head_frequency_factor_address;
  int32_T c57_avert_head_frequency_factor_index;
  real_T *c57_avert_head_speed_address;
  int32_T c57_avert_head_speed_index;
  real_T *c57_blink_flag_address;
  int32_T c57_blink_flag_index;
  real_T *c57_blinkperiod_max_address;
  int32_T c57_blinkperiod_max_index;
  real_T *c57_blinkperiod_min_address;
  int32_T c57_blinkperiod_min_index;
  real_T (*c57_bmlsL_address)[5000];
  int32_T c57_bmlsL_index;
  real_T *c57_bodyBusyFlag_address;
  int32_T c57_bodyBusyFlag_index;
  real_T *c57_boredom_address;
  int32_T c57_boredom_index;
  real_T *c57_faceBusyFlag_address;
  int32_T c57_faceBusyFlag_index;
  real_T *c57_fileID_address;
  int32_T c57_fileID_index;
  real_T *c57_gazing_address;
  int32_T c57_gazing_index;
  real_T *c57_interest_address;
  int32_T c57_interest_index;
  real_T *c57_mut_freq_factor_address;
  int32_T c57_mut_freq_factor_index;
  real_T *c57_mutual_gaze_duration_factor_address;
  int32_T c57_mutual_gaze_duration_factor_index;
  real_T *c57_pr_address;
  int32_T c57_pr_index;
  real_T *c57_randAvertGazeChance_address;
  int32_T c57_randAvertGazeChance_index;
  real_T *c57_randGazeDur_address;
  int32_T c57_randGazeDur_index;
  real_T *c57_randPoseChance_address;
  int32_T c57_randPoseChance_index;
} SFc57_Expriment_All2InstanceStruct;

#endif                                 /*typedef_SFc57_Expriment_All2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c57_Expriment_All2_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c57_Expriment_All2_secs(SimStruct *c57_S);
extern void sf_exported_auto_incrementTemporalCounter_c57_Expriment_All2_secs
  (SimStruct *c57_S);
extern void sf_exported_auto_resetTemporalCounter_c57_Expriment_All2_secs
  (SimStruct *c57_S);
extern void sf_exported_auto_deactivate_c57_Expriment_All2_secs(SimStruct *c57_S);
extern boolean_T sf_exported_auto_isStablec57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_duringc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_enterc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_exitc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_gatewayc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_enablec57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_disablec57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_stepBuffersc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_initBuffersc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_activate_callc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_increment_call_counterc57_Expriment_All2(SimStruct *
  c57_S);
extern void sf_exported_auto_reset_call_counterc57_Expriment_All2(SimStruct
  *c57_S);
extern void sf_exported_auto_deactivate_callc57_Expriment_All2(SimStruct *c57_S);
extern void sf_exported_auto_initc57_Expriment_All2(SimStruct *c57_S);
extern const mxArray *sf_exported_auto_getSimstatec57_Expriment_All2(SimStruct
  *c57_S);
extern const mxArray *sf_internal_get_sim_state_c57_Expriment_All2(SimStruct
  *c57_S);
extern void sf_exported_auto_setSimstatec57_Expriment_All2(SimStruct *c57_S,
  const mxArray *c57_in);
extern void sf_internal_set_sim_state_c57_Expriment_All2(SimStruct *c57_S, const
  mxArray *c57_in);
extern void sf_exported_auto_check_state_inconsistency_c57_Expriment_All2
  (SimStruct *c57_S);
extern void sf_exported_user_c57_Expriment_All2_blinkFunction(SimStruct *c57_S,
  real_T c57_blinkPeriodMin, real_T c57_blinkPeriodMax, real_T c57_arrSBM[1000]);
extern void sf_exported_user_c57_Expriment_All2_gazeFollowUserMove(SimStruct
  *c57_S, real_T c57_bmlID, real_T *c57_p, real_T c57_gazeBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleFastUpHeadTable(SimStruct
  *c57_S, real_T c57_bmlID, real_T *c57_p, real_T c57_gazeBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleGazeFunction(SimStruct
  *c57_S, real_T c57_dir, real_T c57_mag, real_T c57_dirChance, real_T
  c57_arrBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleGazeInterestedTable
  (SimStruct *c57_S, real_T c57_bmlID, real_T *c57_p, real_T c57_gazeBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleGazeOrigFunction(SimStruct
  *c57_S, real_T c57_dir, real_T c57_mag, real_T c57_arrBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleGazeTable(SimStruct *c57_S,
  real_T c57_bmlID, real_T *c57_p, real_T c57_gazeBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleHeadFunction(SimStruct
  *c57_S, real_T c57_dir, real_T c57_mag, real_T c57_dirChance, real_T
  c57_headSpeed, real_T c57_arrBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleNormalHeadTable(SimStruct
  *c57_S, real_T c57_bmlID, real_T *c57_p, real_T c57_gazeBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_idleSlowDownHeadTable(SimStruct *
  c57_S, real_T c57_bmlID, real_T *c57_p, real_T c57_gazeBML[1000]);
extern void sf_exported_user_c57_Expriment_All2_insertQueueLow(SimStruct *c57_S,
  real_T c57_bmls[5000], real_T c57_myBML[1000], real_T c57_newBmls[5000]);
extern void sf_exported_user_c57_Expriment_All2_sendSBM(SimStruct *c57_S, real_T
  c57_In[1000]);
extern void sf_exported_user_c57_Expriment_All2_successTable(SimStruct *c57_S,
  real_T c57_bmlID, real_T *c57_p, real_T c57_poseBML[1000]);

/* Function Definitions */
extern void sf_c57_Expriment_All2_get_check_sum(mxArray *plhs[]);
extern void c57_Expriment_All2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
