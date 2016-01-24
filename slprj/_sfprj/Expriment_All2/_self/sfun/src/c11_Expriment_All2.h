#ifndef __c11_Expriment_All2_h__
#define __c11_Expriment_All2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_Expriment_All2InstanceStruct
#define typedef_SFc11_Expriment_All2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  uint8_T c11_tp_init;
  uint8_T c11_tp_wait;
  uint8_T c11_tp_setBehavior;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_Expriment_All2;
  uint8_T c11_is_c11_Expriment_All2;
  SimStruct *c11_subchartSimstruct;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T *c11_avert_freq_factor_address;
  int32_T c11_avert_freq_factor_index;
  real_T *c11_avert_gaze_dirs_chance_address;
  int32_T c11_avert_gaze_dirs_chance_index;
  real_T *c11_avert_gaze_duration_factor_address;
  int32_T c11_avert_gaze_duration_factor_index;
  real_T *c11_avert_head_frequency_factor_address;
  int32_T c11_avert_head_frequency_factor_index;
  real_T *c11_avert_head_speed_address;
  int32_T c11_avert_head_speed_index;
  real_T *c11_blink_flag_address;
  int32_T c11_blink_flag_index;
  real_T *c11_blinkperiod_max_address;
  int32_T c11_blinkperiod_max_index;
  real_T *c11_blinkperiod_min_address;
  int32_T c11_blinkperiod_min_index;
  real_T *c11_mut_freq_factor_address;
  int32_T c11_mut_freq_factor_index;
  real_T *c11_mutual_gaze_duration_factor_address;
  int32_T c11_mutual_gaze_duration_factor_index;
  real_T *c11_pose_cat_chance_address;
  int32_T c11_pose_cat_chance_index;
  real_T *c11_pose_chanc_factor_address;
  int32_T c11_pose_chanc_factor_index;
  real_T *c11_pose_frequency_factor_address;
  int32_T c11_pose_frequency_factor_index;
  real_T *c11_pose_lean_address;
  int32_T c11_pose_lean_index;
  real_T *c11_pose_lean_flag_address;
  int32_T c11_pose_lean_flag_index;
  real_T *c11_pose_space_address;
  int32_T c11_pose_space_index;
  real_T *c11_pose_speed_address;
  int32_T c11_pose_speed_index;
  real_T *c11_pose_twitch_address;
  int32_T c11_pose_twitch_index;
} SFc11_Expriment_All2InstanceStruct;

#endif                                 /*typedef_SFc11_Expriment_All2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void sf_exported_user_c59_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c11_S, real_T c11_v, real_T c11_a, real_T c11_p, boolean_T
   c11_pFlag, boolean_T c11_vaFlag, real_T c11_gazeArr[6], real_T
   c11_personalityChange, real_T *c11_mutDurFactor, real_T *c11_avertDurFactor,
   real_T *c11_avertHeadFreqFactor, real_T *c11_avertHeadSpeed, real_T
   *c11_avertDirsChance, real_T *c11_avertFreqFactor, real_T *c11_mutFreqFactor,
   real_T *c11_blinkFlag, real_T *c11_blinkPeriodMin, real_T *c11_blinkPeriodMax);
extern void sf_exported_user_c59_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c11_S, real_T c11_v, real_T c11_ar, real_T c11_p, boolean_T
   c11_pFlag, boolean_T c11_vaFlag, real_T c11_poseArr[6], real_T
   c11_personalityChange, real_T *c11_poseTwitch, real_T *c11_poseFreqFactor,
   real_T *c11_poseChanceFactor, real_T *c11_poseCatChance, real_T *c11_poseLean,
   real_T *c11_poseSpeed, real_T *c11_poseSpace, real_T *c11_poseLeanFlag);
extern const mxArray *sf_c11_Expriment_All2_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_duringc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_enterc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_enablec59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_exitc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_disablec59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_gatewayc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_enablec11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_enablec59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_disablec11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_disablec59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_stepBuffersc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_stepBuffersc59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_initBuffersc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_initBuffersc59_lib_affectiveChar_behavior(SimStruct
  *c11_S);
extern void sf_exported_auto_activate_callc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_activate_callc59_lib_affectiveChar_behavior
  (SimStruct *c11_S);
extern void sf_exported_auto_increment_call_counterc11_Expriment_All2(SimStruct *
  c11_S);
extern void
  sf_exported_auto_increment_call_counterc59_lib_affectiveChar_behavior
  (SimStruct *c11_S);
extern void sf_exported_auto_reset_call_counterc11_Expriment_All2(SimStruct
  *c11_S);
extern void sf_exported_auto_reset_call_counterc59_lib_affectiveChar_behavior
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_callc11_Expriment_All2(SimStruct *c11_S);
extern void sf_exported_auto_deactivate_callc59_lib_affectiveChar_behavior
  (SimStruct *c11_S);
extern void sf_exported_auto_initc11_Expriment_All2(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_Expriment_All2(SimStruct
  *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_Expriment_All2(SimStruct
  *c11_S);
extern void sf_exported_auto_setSimstatec11_Expriment_All2(SimStruct *c11_S,
  const mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_Expriment_All2(SimStruct *c11_S, const
  mxArray *c11_in);
extern void sf_exported_auto_check_state_inconsistency_c11_Expriment_All2
  (SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec59_lib_affectiveChar_behavior
  (SimStruct *c11_S);
extern void sf_exported_auto_setSimstatec59_lib_affectiveChar_behavior(SimStruct
  *c11_S, const mxArray *c11_input);
extern void sf_exported_auto_initc59_lib_affectiveChar_behavior(SimStruct *c11_S);
extern void sf_exported_auto_initBuffersc59_lib_affectiveChar_behavior(SimStruct
  *c11_S);

/* Function Definitions */
extern void sf_c11_Expriment_All2_get_check_sum(mxArray *plhs[]);
extern void c11_Expriment_All2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
