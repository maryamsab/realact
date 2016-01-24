#ifndef __c55_Expriment_Emotion_h__
#define __c55_Expriment_Emotion_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc55_Expriment_EmotionInstanceStruct
#define typedef_SFc55_Expriment_EmotionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c55_sfEvent;
  uint8_T c55_tp_init;
  uint8_T c55_tp_wait;
  uint8_T c55_tp_setBehavior;
  boolean_T c55_isStable;
  uint8_T c55_is_active_c55_Expriment_Emotion;
  uint8_T c55_is_c55_Expriment_Emotion;
  SimStruct *c55_subchartSimstruct;
  uint8_T c55_doSetSimStateSideEffects;
  const mxArray *c55_setSimStateSideEffectsInfo;
  real_T *c55_avert_freq_factor_address;
  int32_T c55_avert_freq_factor_index;
  real_T *c55_avert_gaze_dirs_chance_address;
  int32_T c55_avert_gaze_dirs_chance_index;
  real_T *c55_avert_gaze_duration_factor_address;
  int32_T c55_avert_gaze_duration_factor_index;
  real_T *c55_avert_head_frequency_factor_address;
  int32_T c55_avert_head_frequency_factor_index;
  real_T *c55_avert_head_speed_address;
  int32_T c55_avert_head_speed_index;
  real_T *c55_mut_freq_factor_address;
  int32_T c55_mut_freq_factor_index;
  real_T *c55_mutual_gaze_duration_factor_address;
  int32_T c55_mutual_gaze_duration_factor_index;
  real_T *c55_pose_cat_chance_address;
  int32_T c55_pose_cat_chance_index;
  real_T *c55_pose_chanc_factor_address;
  int32_T c55_pose_chanc_factor_index;
  real_T *c55_pose_frequency_factor_address;
  int32_T c55_pose_frequency_factor_index;
  real_T *c55_pose_lean_address;
  int32_T c55_pose_lean_index;
  real_T *c55_pose_lean_flag_address;
  int32_T c55_pose_lean_flag_index;
  real_T *c55_pose_space_address;
  int32_T c55_pose_space_index;
  real_T *c55_pose_speed_address;
  int32_T c55_pose_speed_index;
  real_T *c55_pose_twitch_address;
  int32_T c55_pose_twitch_index;
} SFc55_Expriment_EmotionInstanceStruct;

#endif                                 /*typedef_SFc55_Expriment_EmotionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void sf_exported_user_c56_Expriment_Emotion_setGazeFactors(SimStruct
  *c55_S, real_T c55_v, real_T c55_a, real_T c55_p, boolean_T c55_pFlag,
  boolean_T c55_vaFlag, real_T c55_gazeArr[6], real_T *c55_mutDurFactor, real_T *
  c55_avertDurFactor, real_T *c55_avertHeadFreqFactor, real_T
  *c55_avertHeadSpeed, real_T *c55_avertDirsChance, real_T *c55_avertFreqFactor,
  real_T *c55_mutFreqFactor);
extern void sf_exported_user_c56_Expriment_Emotion_setPoseFactors(SimStruct
  *c55_S, real_T c55_v, real_T c55_ar, real_T c55_p, boolean_T c55_pFlag,
  boolean_T c55_vaFlag, real_T c55_poseArr[6], real_T c55_personalityChange,
  real_T *c55_poseTwitch, real_T *c55_poseFreqFactor, real_T
  *c55_poseChanceFactor, real_T *c55_poseCatChance, real_T *c55_poseLean, real_T
  *c55_poseSpeed, real_T *c55_poseLeanFlag, real_T *c55_poseSpace);
extern const mxArray *sf_c55_Expriment_Emotion_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_duringc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_enterc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_enablec56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_exitc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_disablec56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_gatewayc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_gatewayc56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_enablec55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_enablec56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_disablec55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_disablec56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_stepBuffersc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_stepBuffersc56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_initBuffersc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_initBuffersc56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_activate_callc55_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_activate_callc56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_increment_call_counterc55_Expriment_Emotion
  (SimStruct *c55_S);
extern void sf_exported_auto_increment_call_counterc56_Expriment_Emotion
  (SimStruct *c55_S);
extern void sf_exported_auto_reset_call_counterc55_Expriment_Emotion(SimStruct
  *c55_S);
extern void sf_exported_auto_reset_call_counterc56_Expriment_Emotion(SimStruct
  *c55_S);
extern void sf_exported_auto_deactivate_callc55_Expriment_Emotion(SimStruct
  *c55_S);
extern void sf_exported_auto_deactivate_callc56_Expriment_Emotion(SimStruct
  *c55_S);
extern void sf_exported_auto_initc55_Expriment_Emotion(SimStruct *c55_S);
extern const mxArray *sf_exported_auto_getSimstatec55_Expriment_Emotion
  (SimStruct *c55_S);
extern const mxArray *sf_internal_get_sim_state_c55_Expriment_Emotion(SimStruct *
  c55_S);
extern void sf_exported_auto_setSimstatec55_Expriment_Emotion(SimStruct *c55_S,
  const mxArray *c55_in);
extern void sf_internal_set_sim_state_c55_Expriment_Emotion(SimStruct *c55_S,
  const mxArray *c55_in);
extern void sf_exported_auto_check_state_inconsistency_c55_Expriment_Emotion
  (SimStruct *c55_S);
extern const mxArray *sf_exported_auto_getSimstatec56_Expriment_Emotion
  (SimStruct *c55_S);
extern void sf_exported_auto_setSimstatec56_Expriment_Emotion(SimStruct *c55_S,
  const mxArray *c55_input);
extern void sf_exported_auto_initc56_Expriment_Emotion(SimStruct *c55_S);
extern void sf_exported_auto_initBuffersc56_Expriment_Emotion(SimStruct *c55_S);

/* Function Definitions */
extern void sf_c55_Expriment_Emotion_get_check_sum(mxArray *plhs[]);
extern void c55_Expriment_Emotion_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
