#ifndef __c44_Expriment_Pose_h__
#define __c44_Expriment_Pose_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc44_Expriment_PoseInstanceStruct
#define typedef_SFc44_Expriment_PoseInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c44_sfEvent;
  uint8_T c44_tp_setP;
  uint8_T c44_tp_init;
  uint8_T c44_tp_wait;
  uint8_T c44_tp_setP1;
  boolean_T c44_isStable;
  uint8_T c44_is_active_c44_Expriment_Pose;
  uint8_T c44_is_c44_Expriment_Pose;
  SimStruct *c44_subchartSimstruct;
  uint8_T c44_doSetSimStateSideEffects;
  const mxArray *c44_setSimStateSideEffectsInfo;
  real_T *c44_avert_freq_factor_address;
  int32_T c44_avert_freq_factor_index;
  real_T *c44_avert_gaze_dirs_chance_address;
  int32_T c44_avert_gaze_dirs_chance_index;
  real_T *c44_avert_gaze_duration_factor_address;
  int32_T c44_avert_gaze_duration_factor_index;
  real_T *c44_avert_head_frequency_factor_address;
  int32_T c44_avert_head_frequency_factor_index;
  real_T *c44_avert_head_speed_address;
  int32_T c44_avert_head_speed_index;
  real_T (*c44_emotion_amount_factor_address)[11];
  int32_T c44_emotion_amount_factor_index;
  real_T *c44_mut_freq_factor_address;
  int32_T c44_mut_freq_factor_index;
  real_T *c44_mutual_gaze_duration_factor_address;
  int32_T c44_mutual_gaze_duration_factor_index;
  real_T *c44_pose_cat_chance_address;
  int32_T c44_pose_cat_chance_index;
  real_T *c44_pose_chanc_factor_address;
  int32_T c44_pose_chanc_factor_index;
  real_T *c44_pose_frequency_factor_address;
  int32_T c44_pose_frequency_factor_index;
  real_T *c44_pose_lean_address;
  int32_T c44_pose_lean_index;
  real_T *c44_pose_lean_flag_address;
  int32_T c44_pose_lean_flag_index;
  real_T *c44_pose_speed_address;
  int32_T c44_pose_speed_index;
  real_T *c44_pose_twitch_address;
  int32_T c44_pose_twitch_index;
} SFc44_Expriment_PoseInstanceStruct;

#endif                                 /*typedef_SFc44_Expriment_PoseInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void sf_exported_user_c50_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c44_S, real_T c44_v, real_T c44_a, real_T c44_p, boolean_T
   c44_pFlag, boolean_T c44_vaFlag, real_T c44_gazeArr[6], real_T
   *c44_mutDurFactor, real_T *c44_avertDurFactor, real_T
   *c44_avertHeadFreqFactor, real_T *c44_avertHeadSpeed, real_T
   *c44_avertDirsChance, real_T *c44_avertFreqFactor, real_T *c44_mutFreqFactor,
   real_T *c44_blinkFlag, real_T *c44_blinkPeriodMin, real_T *c44_blinkPeriodMax);
extern void sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c44_S, real_T c44_v, real_T c44_ar, real_T c44_p, boolean_T
   c44_pFlag, boolean_T c44_vaFlag, real_T c44_poseArr[6], real_T
   c44_personalityChange, real_T *c44_poseTwitch, real_T *c44_poseFreqFactor,
   real_T *c44_poseChanceFactor, real_T *c44_poseCatChance, real_T *c44_poseLean,
   real_T *c44_poseSpeed, real_T *c44_poseLeanFlag);
extern const mxArray *sf_c44_Expriment_Pose_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_duringc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_enterc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_enablec50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_exitc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_disablec50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_gatewayc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_gatewayc50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_enablec44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_enablec50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_disablec44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_disablec50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_stepBuffersc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_initBuffersc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_activate_callc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_activate_callc50_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_increment_call_counterc44_Expriment_Pose(SimStruct *
  c44_S);
extern void
  sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_reset_call_counterc44_Expriment_Pose(SimStruct
  *c44_S);
extern void sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_deactivate_callc44_Expriment_Pose(SimStruct *c44_S);
extern void sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_initc44_Expriment_Pose(SimStruct *c44_S);
extern const mxArray *sf_exported_auto_getSimstatec44_Expriment_Pose(SimStruct
  *c44_S);
extern const mxArray *sf_internal_get_sim_state_c44_Expriment_Pose(SimStruct
  *c44_S);
extern void sf_exported_auto_setSimstatec44_Expriment_Pose(SimStruct *c44_S,
  const mxArray *c44_in);
extern void sf_internal_set_sim_state_c44_Expriment_Pose(SimStruct *c44_S, const
  mxArray *c44_in);
extern void sf_exported_auto_check_state_inconsistency_c44_Expriment_Pose
  (SimStruct *c44_S);
extern const mxArray *sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior(SimStruct
  *c44_S, const mxArray *c44_input);
extern void sf_exported_auto_initc50_lib_affectiveChar_behavior(SimStruct *c44_S);
extern void sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c44_S);

/* Function Definitions */
extern void sf_c44_Expriment_Pose_get_check_sum(mxArray *plhs[]);
extern void c44_Expriment_Pose_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
