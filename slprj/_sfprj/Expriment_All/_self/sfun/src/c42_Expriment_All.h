#ifndef __c42_Expriment_All_h__
#define __c42_Expriment_All_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc42_Expriment_AllInstanceStruct
#define typedef_SFc42_Expriment_AllInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c42_sfEvent;
  uint8_T c42_tp_setPoseGaze;
  uint8_T c42_tp_init;
  uint8_T c42_tp_wait;
  boolean_T c42_isStable;
  uint8_T c42_is_active_c42_Expriment_All;
  uint8_T c42_is_c42_Expriment_All;
  SimStruct *c42_subchartSimstruct;
  uint8_T c42_doSetSimStateSideEffects;
  const mxArray *c42_setSimStateSideEffectsInfo;
  real_T *c42_avert_freq_factor_address;
  int32_T c42_avert_freq_factor_index;
  real_T *c42_avert_gaze_dirs_chance_address;
  int32_T c42_avert_gaze_dirs_chance_index;
  real_T *c42_avert_gaze_duration_factor_address;
  int32_T c42_avert_gaze_duration_factor_index;
  real_T *c42_avert_head_duration_factor_address;
  int32_T c42_avert_head_duration_factor_index;
  real_T *c42_avert_head_frequency_factor_address;
  int32_T c42_avert_head_frequency_factor_index;
  real_T *c42_avert_head_speed_address;
  int32_T c42_avert_head_speed_index;
  real_T *c42_blink_flag_address;
  int32_T c42_blink_flag_index;
  real_T *c42_blinkperiod_max_address;
  int32_T c42_blinkperiod_max_index;
  real_T *c42_blinkperiod_min_address;
  int32_T c42_blinkperiod_min_index;
  real_T (*c42_emotion_amount_factor_address)[15];
  int32_T c42_emotion_amount_factor_index;
  real_T *c42_head_mut_chance_address;
  int32_T c42_head_mut_chance_index;
  real_T *c42_mut_freq_factor_address;
  int32_T c42_mut_freq_factor_index;
  real_T *c42_mutual_gaze_duration_factor_address;
  int32_T c42_mutual_gaze_duration_factor_index;
  real_T *c42_pose_cat_chance_address;
  int32_T c42_pose_cat_chance_index;
  real_T *c42_pose_chanc_factor_address;
  int32_T c42_pose_chanc_factor_index;
  real_T *c42_pose_change_flag_address;
  int32_T c42_pose_change_flag_index;
  real_T *c42_pose_frequency_factor_address;
  int32_T c42_pose_frequency_factor_index;
  real_T *c42_pose_lean_address;
  int32_T c42_pose_lean_index;
  real_T *c42_pose_lean_flag_address;
  int32_T c42_pose_lean_flag_index;
  real_T *c42_pose_space_address;
  int32_T c42_pose_space_index;
  real_T *c42_pose_speed_address;
  int32_T c42_pose_speed_index;
  real_T *c42_pose_twitch_address;
  int32_T c42_pose_twitch_index;
} SFc42_Expriment_AllInstanceStruct;

#endif                                 /*typedef_SFc42_Expriment_AllInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void sf_exported_user_c59_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c42_S, real_T c42_v, real_T c42_a, real_T c42_p, boolean_T
   c42_pFlag, boolean_T c42_vaFlag, real_T c42_gazeArr[6], real_T
   c42_personalityChange, real_T *c42_mutDurFactor, real_T *c42_avertDurFactor,
   real_T *c42_avertHeadFreqFactor, real_T *c42_avertHeadSpeed, real_T
   *c42_avertDirsChance, real_T *c42_avertFreqFactor, real_T *c42_mutFreqFactor,
   real_T *c42_blinkFlag, real_T *c42_blinkPeriodMin, real_T *c42_blinkPeriodMax,
   real_T *c42_headMutChance, real_T *c42_avertHeadDurFactor);
extern void sf_exported_user_c59_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c42_S, real_T c42_v, real_T c42_ar, real_T c42_p, boolean_T
   c42_pFlag, boolean_T c42_vaFlag, real_T c42_poseArr[6], real_T
   c42_personalityChange, real_T *c42_poseTwitch, real_T *c42_poseFreqFactor,
   real_T *c42_poseChanceFactor, real_T *c42_poseCatChance, real_T *c42_poseLean,
   real_T *c42_poseSpeed, real_T *c42_poseSpace, real_T *c42_poseLeanFlag);
extern const mxArray *sf_c42_Expriment_All_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_duringc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_enterc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_enablec59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_exitc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_disablec59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_gatewayc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_gatewayc59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_enablec42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_enablec59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_disablec42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_disablec59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_stepBuffersc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_stepBuffersc59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_initBuffersc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_initBuffersc59_lib_affectiveChar_behavior(SimStruct
  *c42_S);
extern void sf_exported_auto_activate_callc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_activate_callc59_lib_affectiveChar_behavior
  (SimStruct *c42_S);
extern void sf_exported_auto_increment_call_counterc42_Expriment_All(SimStruct
  *c42_S);
extern void
  sf_exported_auto_increment_call_counterc59_lib_affectiveChar_behavior
  (SimStruct *c42_S);
extern void sf_exported_auto_reset_call_counterc42_Expriment_All(SimStruct
  *c42_S);
extern void sf_exported_auto_reset_call_counterc59_lib_affectiveChar_behavior
  (SimStruct *c42_S);
extern void sf_exported_auto_deactivate_callc42_Expriment_All(SimStruct *c42_S);
extern void sf_exported_auto_deactivate_callc59_lib_affectiveChar_behavior
  (SimStruct *c42_S);
extern void sf_exported_auto_initc42_Expriment_All(SimStruct *c42_S);
extern const mxArray *sf_exported_auto_getSimstatec42_Expriment_All(SimStruct
  *c42_S);
extern const mxArray *sf_internal_get_sim_state_c42_Expriment_All(SimStruct
  *c42_S);
extern void sf_exported_auto_setSimstatec42_Expriment_All(SimStruct *c42_S,
  const mxArray *c42_in);
extern void sf_internal_set_sim_state_c42_Expriment_All(SimStruct *c42_S, const
  mxArray *c42_in);
extern void sf_exported_auto_check_state_inconsistency_c42_Expriment_All
  (SimStruct *c42_S);
extern const mxArray *sf_exported_auto_getSimstatec59_lib_affectiveChar_behavior
  (SimStruct *c42_S);
extern void sf_exported_auto_setSimstatec59_lib_affectiveChar_behavior(SimStruct
  *c42_S, const mxArray *c42_input);
extern void sf_exported_auto_initc59_lib_affectiveChar_behavior(SimStruct *c42_S);
extern void sf_exported_auto_initBuffersc59_lib_affectiveChar_behavior(SimStruct
  *c42_S);

/* Function Definitions */
extern void sf_c42_Expriment_All_get_check_sum(mxArray *plhs[]);
extern void c42_Expriment_All_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
