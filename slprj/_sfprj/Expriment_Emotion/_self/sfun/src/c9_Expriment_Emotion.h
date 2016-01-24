#ifndef __c9_Expriment_Emotion_h__
#define __c9_Expriment_Emotion_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Expriment_EmotionInstanceStruct
#define typedef_SFc9_Expriment_EmotionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_headAvert;
  uint8_T c9_tp_stateInit1;
  uint8_T c9_tp_stateRandGen1;
  uint8_T c9_tp_stateHeadNeutralN1;
  uint8_T c9_tp_stateAvertHeadNormal;
  uint8_T c9_tp_stateHeadNeutralF1;
  uint8_T c9_tp_stateAvertHeadFast;
  uint8_T c9_tp_stateHeadNeutralS1;
  uint8_T c9_tp_stateAvertHeadSlow;
  uint8_T c9_tp_stateGazingGUI;
  uint8_T c9_tp_stateGazingUserHand;
  uint8_T c9_tp_stateGazeIde;
  uint8_T c9_tp_mut;
  uint8_T c9_tp_stateInit;
  uint8_T c9_tp_stateCheckMutCont;
  uint8_T c9_tp_stateAvert;
  uint8_T c9_tp_stateAvertEye;
  uint8_T c9_tp_stateAvertHead;
  uint8_T c9_tp_stateMutualGazeE;
  uint8_T c9_tp_stateCheckAvertCont;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_Expriment_Emotion;
  uint8_T c9_is_headAvert;
  uint8_T c9_is_active_headAvert;
  uint8_T c9_is_stateGazeIde;
  uint8_T c9_is_active_stateGazeIde;
  real_T c9_randHeadDur;
  real_T c9_randHeadDurOver;
  real_T c9_avertContChance;
  real_T c9_gazeGUIChance;
  real_T c9_mutContChance;
  real_T c9_mutContF[3];
  real_T c9_CHANCEM;
  real_T c9_avertDur;
  real_T c9_gazeDir;
  real_T c9_CHANCEA;
  real_T c9_magnitude;
  real_T c9_randHeadChance;
  real_T c9_avertContF[4];
  real_T c9_gazeUserHandChance;
  real_T c9_chanceO;
  real_T c9_BMLl[1000];
  real_T c9_newBmlsL[5000];
  real_T c9_n[1000];
  real_T c9_mutDur;
  real_T c9_mF;
  real_T c9_hF;
  real_T c9_aF;
  real_T c9_mFe;
  real_T c9_hFe;
  real_T c9_aFe;
  real_T c9_chanceH;
  real_T c9_currentTime;
  uint32_T c9_temporalCounter_i1;
  uint32_T c9_temporalCounter_i2;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T (*c9_BML_address)[1000];
  int32_T c9_BML_index;
  real_T *c9_BOREDOM_THRESHOLD_address;
  int32_T c9_BOREDOM_THRESHOLD_index;
  real_T *c9_GAZE_GUI_address;
  int32_T c9_GAZE_GUI_index;
  real_T *c9_GAZE_SOFTEYE_address;
  int32_T c9_GAZE_SOFTEYE_index;
  real_T *c9_GAZE_USER_HAND_address;
  int32_T c9_GAZE_USER_HAND_index;
  real_T *c9_GAZE_WIN_address;
  int32_T c9_GAZE_WIN_index;
  real_T *c9_P_address;
  int32_T c9_P_index;
  real_T *c9_STATE_BEFORE_address;
  int32_T c9_STATE_BEFORE_index;
  real_T *c9_STATE_GO_address;
  int32_T c9_STATE_GO_index;
  real_T *c9_STATE_OVER_address;
  int32_T c9_STATE_OVER_index;
  real_T *c9_STATE_READY_address;
  int32_T c9_STATE_READY_index;
  real_T *c9_avert_address;
  int32_T c9_avert_index;
  real_T *c9_avertH_address;
  int32_T c9_avertH_index;
  real_T *c9_avert_freq_factor_address;
  int32_T c9_avert_freq_factor_index;
  real_T *c9_avert_gaze_dirs_chance_address;
  int32_T c9_avert_gaze_dirs_chance_index;
  real_T *c9_avert_gaze_duration_factor_address;
  int32_T c9_avert_gaze_duration_factor_index;
  real_T *c9_avert_head_frequency_factor_address;
  int32_T c9_avert_head_frequency_factor_index;
  real_T *c9_avert_head_speed_address;
  int32_T c9_avert_head_speed_index;
  real_T (*c9_bmlsL_address)[5000];
  int32_T c9_bmlsL_index;
  real_T *c9_bodyBusyFlag_address;
  int32_T c9_bodyBusyFlag_index;
  real_T *c9_boredom_address;
  int32_T c9_boredom_index;
  real_T *c9_faceBusyFlag_address;
  int32_T c9_faceBusyFlag_index;
  real_T *c9_fileID_address;
  int32_T c9_fileID_index;
  real_T *c9_gazing_address;
  int32_T c9_gazing_index;
  real_T *c9_interest_address;
  int32_T c9_interest_index;
  real_T *c9_mut_freq_factor_address;
  int32_T c9_mut_freq_factor_index;
  real_T *c9_mutual_gaze_duration_factor_address;
  int32_T c9_mutual_gaze_duration_factor_index;
  real_T *c9_pr_address;
  int32_T c9_pr_index;
  real_T *c9_randAvertGazeChance_address;
  int32_T c9_randAvertGazeChance_index;
  real_T *c9_randGazeDur_address;
  int32_T c9_randGazeDur_index;
  real_T *c9_randPoseChance_address;
  int32_T c9_randPoseChance_index;
} SFc9_Expriment_EmotionInstanceStruct;

#endif                                 /*typedef_SFc9_Expriment_EmotionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Expriment_Emotion_get_eml_resolved_functions_info
  (void);
extern void sf_exported_auto_activate_c9_Expriment_Emotion_secs(SimStruct *c9_S);
extern void sf_exported_auto_incrementTemporalCounter_c9_Expriment_Emotion_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_resetTemporalCounter_c9_Expriment_Emotion_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_c9_Expriment_Emotion_secs(SimStruct
  *c9_S);
extern boolean_T sf_exported_auto_isStablec9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_duringc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_enterc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_exitc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_enablec9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_disablec9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_activate_callc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc9_Expriment_Emotion
  (SimStruct *c9_S);
extern void sf_exported_auto_reset_call_counterc9_Expriment_Emotion(SimStruct
  *c9_S);
extern void sf_exported_auto_deactivate_callc9_Expriment_Emotion(SimStruct *c9_S);
extern void sf_exported_auto_initc9_Expriment_Emotion(SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec9_Expriment_Emotion(SimStruct
  *c9_S);
extern const mxArray *sf_internal_get_sim_state_c9_Expriment_Emotion(SimStruct
  *c9_S);
extern void sf_exported_auto_setSimstatec9_Expriment_Emotion(SimStruct *c9_S,
  const mxArray *c9_in);
extern void sf_internal_set_sim_state_c9_Expriment_Emotion(SimStruct *c9_S,
  const mxArray *c9_in);
extern void sf_exported_auto_check_state_inconsistency_c9_Expriment_Emotion
  (SimStruct *c9_S);
extern void sf_exported_user_c9_Expriment_Emotion_gazeFollowUserMove(SimStruct
  *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleFastUpHeadTable(SimStruct *
  c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleGazeFunction(SimStruct
  *c9_S, real_T c9_dir, real_T c9_mag, real_T c9_dirChance, real_T c9_arrBML
  [1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleGazeInterestedTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleGazeOrigFunction(SimStruct
  *c9_S, real_T c9_dir, real_T c9_mag, real_T c9_arrBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleGazeTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleHeadFunction(SimStruct
  *c9_S, real_T c9_dir, real_T c9_mag, real_T c9_dirChance, real_T c9_headSpeed,
  real_T c9_arrBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleNormalHeadTable(SimStruct *
  c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_idleSlowDownHeadTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[1000]);
extern void sf_exported_user_c9_Expriment_Emotion_insertQueueLow(SimStruct *c9_S,
  real_T c9_bmls[5000], real_T c9_myBML[1000], real_T c9_newBmls[5000]);
extern void sf_exported_user_c9_Expriment_Emotion_successTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[1000]);

/* Function Definitions */
extern void sf_c9_Expriment_Emotion_get_check_sum(mxArray *plhs[]);
extern void c9_Expriment_Emotion_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
