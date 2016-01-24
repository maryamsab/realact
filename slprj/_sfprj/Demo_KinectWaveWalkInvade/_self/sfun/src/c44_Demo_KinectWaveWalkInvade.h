#ifndef __c44_Demo_KinectWaveWalkInvade_h__
#define __c44_Demo_KinectWaveWalkInvade_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc44_Demo_KinectWaveWalkInvadeInstanceStruct
#define typedef_SFc44_Demo_KinectWaveWalkInvadeInstanceStruct

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
  uint8_T c44_is_active_c44_Demo_KinectWaveWalkInvade;
  uint8_T c44_is_c44_Demo_KinectWaveWalkInvade;
  SimStruct *c44_subchartSimstruct;
  uint8_T c44_doSetSimStateSideEffects;
  const mxArray *c44_setSimStateSideEffectsInfo;
  real_T *c44_avert_gaze_dirs_chance_address;
  int32_T c44_avert_gaze_dirs_chance_index;
  real_T *c44_avert_gaze_duration_factor_address;
  int32_T c44_avert_gaze_duration_factor_index;
  real_T *c44_avert_head_frequency_factor_address;
  int32_T c44_avert_head_frequency_factor_index;
  real_T *c44_avert_head_speed_address;
  int32_T c44_avert_head_speed_index;
  real_T (*c44_emotion_amount_factor_address)[6];
  int32_T c44_emotion_amount_factor_index;
  real_T *c44_mutual_gaze_duration_factor_address;
  int32_T c44_mutual_gaze_duration_factor_index;
  real_T *c44_pose_chanc_factor_address;
  int32_T c44_pose_chanc_factor_index;
  real_T *c44_pose_frequency_factor_address;
  int32_T c44_pose_frequency_factor_index;
  real_T *c44_pose_lean_address;
  int32_T c44_pose_lean_index;
  real_T *c44_pose_lean_flag_address;
  int32_T c44_pose_lean_flag_index;
  real_T *c44_pose_selfAdaptor_chance_factor_address;
  int32_T c44_pose_selfAdaptor_chance_factor_index;
  real_T *c44_pose_speed_address;
  int32_T c44_pose_speed_index;
} SFc44_Demo_KinectWaveWalkInvadeInstanceStruct;

#endif                                 /*typedef_SFc44_Demo_KinectWaveWalkInvadeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void sf_exported_user_c46_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c44_S, real_T c44_v, real_T c44_a, real_T c44_p, boolean_T
   c44_pFlag, boolean_T c44_vaFlag, real_T c44_gazeArr[6], real_T
   *c44_mutDurFactor, real_T *c44_avertDurFactor, real_T
   *c44_avertHeadFreqFactor, real_T *c44_avertHeadSpeed, real_T
   *c44_avertDirsChance);
extern void sf_exported_user_c46_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c44_S, real_T c44_v, real_T c44_ar, real_T c44_p, boolean_T
   c44_pFlag, boolean_T c44_vaFlag, real_T c44_poseArr[6], real_T
   c44_personalityChange, real_T *c44_poseFreqFactor, real_T
   *c44_poseChanceFactor, real_T *c44_poseSelfAdaptChance, real_T *c44_poseLean,
   real_T *c44_poseSpeed, real_T *c44_poseLeanFlag);
extern const mxArray
  *sf_c44_Demo_KinectWaveWalkInvade_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern void sf_exported_auto_duringc44_Demo_KinectWaveWalkInvade(SimStruct
  *c44_S);
extern void sf_exported_auto_enterc44_Demo_KinectWaveWalkInvade(SimStruct *c44_S);
extern void sf_exported_auto_enablec46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_exitc44_Demo_KinectWaveWalkInvade(SimStruct *c44_S);
extern void sf_exported_auto_disablec46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_gatewayc44_Demo_KinectWaveWalkInvade(SimStruct
  *c44_S);
extern void sf_exported_auto_gatewayc46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_enablec44_Demo_KinectWaveWalkInvade(SimStruct
  *c44_S);
extern void sf_exported_auto_enablec46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_disablec44_Demo_KinectWaveWalkInvade(SimStruct
  *c44_S);
extern void sf_exported_auto_disablec46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_stepBuffersc44_Demo_KinectWaveWalkInvade(SimStruct *
  c44_S);
extern void sf_exported_auto_stepBuffersc46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_initBuffersc44_Demo_KinectWaveWalkInvade(SimStruct *
  c44_S);
extern void sf_exported_auto_initBuffersc46_lib_affectiveChar_behavior(SimStruct
  *c44_S);
extern void sf_exported_auto_activate_callc44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern void sf_exported_auto_activate_callc46_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_increment_call_counterc44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern void
  sf_exported_auto_increment_call_counterc46_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_reset_call_counterc44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern void sf_exported_auto_reset_call_counterc46_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_deactivate_callc44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern void sf_exported_auto_deactivate_callc46_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_initc44_Demo_KinectWaveWalkInvade(SimStruct *c44_S);
extern const mxArray *sf_exported_auto_getSimstatec44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern const mxArray *sf_internal_get_sim_state_c44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern void sf_exported_auto_setSimstatec44_Demo_KinectWaveWalkInvade(SimStruct *
  c44_S, const mxArray *c44_in);
extern void sf_internal_set_sim_state_c44_Demo_KinectWaveWalkInvade(SimStruct
  *c44_S, const mxArray *c44_in);
extern void
  sf_exported_auto_check_state_inconsistency_c44_Demo_KinectWaveWalkInvade
  (SimStruct *c44_S);
extern const mxArray *sf_exported_auto_getSimstatec46_lib_affectiveChar_behavior
  (SimStruct *c44_S);
extern void sf_exported_auto_setSimstatec46_lib_affectiveChar_behavior(SimStruct
  *c44_S, const mxArray *c44_input);
extern void sf_exported_auto_initc46_lib_affectiveChar_behavior(SimStruct *c44_S);
extern void sf_exported_auto_initBuffersc46_lib_affectiveChar_behavior(SimStruct
  *c44_S);

/* Function Definitions */
extern void sf_c44_Demo_KinectWaveWalkInvade_get_check_sum(mxArray *plhs[]);
extern void c44_Demo_KinectWaveWalkInvade_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
