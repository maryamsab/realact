#ifndef __c43_Demo_EP_IdleRandMerg_h__
#define __c43_Demo_EP_IdleRandMerg_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_Demo_EP_IdleRandMergInstanceStruct
#define typedef_SFc43_Demo_EP_IdleRandMergInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c43_sfEvent;
  uint8_T c43_tp_init;
  uint8_T c43_tp_wait;
  uint8_T c43_tp_setBehavior;
  boolean_T c43_isStable;
  uint8_T c43_is_active_c43_Demo_EP_IdleRandMerg;
  uint8_T c43_is_c43_Demo_EP_IdleRandMerg;
  SimStruct *c43_subchartSimstruct;
  uint8_T c43_doSetSimStateSideEffects;
  const mxArray *c43_setSimStateSideEffectsInfo;
  real_T *c43_avert_freq_factor_address;
  int32_T c43_avert_freq_factor_index;
  real_T *c43_avert_gaze_dirs_chance_address;
  int32_T c43_avert_gaze_dirs_chance_index;
  real_T *c43_avert_gaze_duration_factor_address;
  int32_T c43_avert_gaze_duration_factor_index;
  real_T *c43_avert_head_frequency_factor_address;
  int32_T c43_avert_head_frequency_factor_index;
  real_T *c43_avert_head_speed_address;
  int32_T c43_avert_head_speed_index;
  real_T *c43_mut_freq_factor_address;
  int32_T c43_mut_freq_factor_index;
  real_T *c43_mutual_gaze_duration_factor_address;
  int32_T c43_mutual_gaze_duration_factor_index;
  real_T *c43_pose_cat_chance_address;
  int32_T c43_pose_cat_chance_index;
  real_T *c43_pose_chanc_factor_address;
  int32_T c43_pose_chanc_factor_index;
  real_T *c43_pose_frequency_factor_address;
  int32_T c43_pose_frequency_factor_index;
  real_T *c43_pose_lean_address;
  int32_T c43_pose_lean_index;
  real_T *c43_pose_lean_flag_address;
  int32_T c43_pose_lean_flag_index;
  real_T *c43_pose_speed_address;
  int32_T c43_pose_speed_index;
  real_T *c43_pose_twitch_address;
  int32_T c43_pose_twitch_index;
} SFc43_Demo_EP_IdleRandMergInstanceStruct;

#endif                                 /*typedef_SFc43_Demo_EP_IdleRandMergInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void sf_exported_user_c50_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c43_S, real_T c43_v, real_T c43_a, real_T c43_p, boolean_T
   c43_pFlag, boolean_T c43_vaFlag, real_T c43_gazeArr[6], real_T
   *c43_mutDurFactor, real_T *c43_avertDurFactor, real_T
   *c43_avertHeadFreqFactor, real_T *c43_avertHeadSpeed, real_T
   *c43_avertDirsChance, real_T *c43_avertFreqFactor, real_T *c43_mutFreqFactor);
extern void sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c43_S, real_T c43_v, real_T c43_ar, real_T c43_p, boolean_T
   c43_pFlag, boolean_T c43_vaFlag, real_T c43_poseArr[6], real_T
   c43_personalityChange, real_T *c43_poseTwitch, real_T *c43_poseFreqFactor,
   real_T *c43_poseChanceFactor, real_T *c43_poseCatChance, real_T *c43_poseLean,
   real_T *c43_poseSpeed, real_T *c43_poseLeanFlag);
extern const mxArray
  *sf_c43_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec43_Demo_EP_IdleRandMerg(SimStruct
  *c43_S);
extern void sf_exported_auto_duringc43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern void sf_exported_auto_enterc43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern void sf_exported_auto_enablec50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_exitc43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern void sf_exported_auto_disablec50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_gatewayc43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern void sf_exported_auto_gatewayc50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_enablec43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern void sf_exported_auto_enablec50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_disablec43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern void sf_exported_auto_disablec50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_stepBuffersc43_Demo_EP_IdleRandMerg(SimStruct
  *c43_S);
extern void sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_initBuffersc43_Demo_EP_IdleRandMerg(SimStruct
  *c43_S);
extern void sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_activate_callc43_Demo_EP_IdleRandMerg(SimStruct
  *c43_S);
extern void sf_exported_auto_activate_callc50_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_increment_call_counterc43_Demo_EP_IdleRandMerg
  (SimStruct *c43_S);
extern void
  sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_reset_call_counterc43_Demo_EP_IdleRandMerg
  (SimStruct *c43_S);
extern void sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_deactivate_callc43_Demo_EP_IdleRandMerg(SimStruct
  *c43_S);
extern void sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_initc43_Demo_EP_IdleRandMerg(SimStruct *c43_S);
extern const mxArray *sf_exported_auto_getSimstatec43_Demo_EP_IdleRandMerg
  (SimStruct *c43_S);
extern const mxArray *sf_internal_get_sim_state_c43_Demo_EP_IdleRandMerg
  (SimStruct *c43_S);
extern void sf_exported_auto_setSimstatec43_Demo_EP_IdleRandMerg(SimStruct
  *c43_S, const mxArray *c43_in);
extern void sf_internal_set_sim_state_c43_Demo_EP_IdleRandMerg(SimStruct *c43_S,
  const mxArray *c43_in);
extern void sf_exported_auto_check_state_inconsistency_c43_Demo_EP_IdleRandMerg
  (SimStruct *c43_S);
extern const mxArray *sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior(SimStruct
  *c43_S, const mxArray *c43_input);
extern void sf_exported_auto_initc50_lib_affectiveChar_behavior(SimStruct *c43_S);
extern void sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c43_S);

/* Function Definitions */
extern void sf_c43_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
extern void c43_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
