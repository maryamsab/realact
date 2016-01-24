#ifndef __c1_Demo_Glove_h__
#define __c1_Demo_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Demo_GloveInstanceStruct
#define typedef_SFc1_Demo_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_RPS_Scenario;
  uint8_T c1_tp_personalSpace_Controller;
  uint8_T c1_tp_wave_Controller;
  uint8_T c1_tp_idlePose_Controller;
  uint8_T c1_tp_Gaze_Controller;
  uint8_T c1_tp_facialExpression_Controller;
  uint8_T c1_tp_personality_Behavior_Factors;
  uint8_T c1_tp_emotion_Behavior_Factors;
  uint8_T c1_tp_custom_Behavior_Factors;
  uint8_T c1_tp_attention_Controller;
  uint8_T c1_tp_sendBMLbyPriority;
  uint8_T c1_tp_sendH;
  uint8_T c1_tp_init;
  uint8_T c1_tp_checkHighPriority;
  uint8_T c1_tp_sendM;
  uint8_T c1_tp_Mid;
  uint8_T c1_tp_sendL;
  uint8_T c1_tp_low;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_Demo_Glove;
  uint8_T c1_is_active_RPS_Scenario;
  uint8_T c1_is_active_personalSpace_Controller;
  uint8_T c1_is_active_wave_Controller;
  uint8_T c1_is_active_idlePose_Controller;
  uint8_T c1_is_active_Gaze_Controller;
  uint8_T c1_is_active_facialExpression_Controller;
  uint8_T c1_is_active_personality_Behavior_Factors;
  uint8_T c1_is_active_emotion_Behavior_Factors;
  uint8_T c1_is_active_custom_Behavior_Factors;
  uint8_T c1_is_active_attention_Controller;
  uint8_T c1_is_sendBMLbyPriority;
  uint8_T c1_is_active_sendBMLbyPriority;
  real_T c1_smileN;
  real_T c1_t1;
  real_T c1_t2;
  real_T c1_newBmlA;
  real_T c1_hEmpty;
  real_T c1_newBmlsH[5000];
  real_T c1_newBmlsL[5000];
  real_T c1_lEmpty;
  real_T c1_newBmlsM[5000];
  real_T c1_mEmpty;
  SimStruct *c1_subchartSimstruct;
  SimStruct *c1_b_subchartSimstruct;
  SimStruct *c1_c_subchartSimstruct;
  SimStruct *c1_d_subchartSimstruct;
  SimStruct *c1_e_subchartSimstruct;
  SimStruct *c1_f_subchartSimstruct;
  SimStruct *c1_g_subchartSimstruct;
  SimStruct *c1_h_subchartSimstruct;
  SimStruct *c1_i_subchartSimstruct;
  SimStruct *c1_j_subchartSimstruct;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  real_T (*c1_BML_address)[1000];
  int32_T c1_BML_index;
  real_T (*c1_BML1_address)[1000];
  int32_T c1_BML1_index;
  real_T (*c1_BML2_address)[1000];
  int32_T c1_BML2_index;
  real_T *c1_BORED_address;
  int32_T c1_BORED_index;
  real_T *c1_BOREDOM_THRESHOLD_address;
  int32_T c1_BOREDOM_THRESHOLD_index;
  real_T *c1_CONTEMPT_address;
  int32_T c1_CONTEMPT_index;
  real_T *c1_EXCITE_address;
  int32_T c1_EXCITE_index;
  real_T *c1_FEAR_address;
  int32_T c1_FEAR_index;
  real_T *c1_FRUST_address;
  int32_T c1_FRUST_index;
  real_T *c1_GAZE_GUI_address;
  int32_T c1_GAZE_GUI_index;
  real_T *c1_GAZE_SOFTEYE_address;
  int32_T c1_GAZE_SOFTEYE_index;
  real_T *c1_GAZE_USER_HAND_address;
  int32_T c1_GAZE_USER_HAND_index;
  real_T *c1_GAZE_WIN_address;
  int32_T c1_GAZE_WIN_index;
  real_T *c1_HAPPY_address;
  int32_T c1_HAPPY_index;
  real_T *c1_IDLE_address;
  int32_T c1_IDLE_index;
  real_T *c1_P_address;
  int32_T c1_P_index;
  real_T *c1_SAD_address;
  int32_T c1_SAD_index;
  real_T *c1_STATE_BEFORE_address;
  int32_T c1_STATE_BEFORE_index;
  real_T *c1_STATE_GO_address;
  int32_T c1_STATE_GO_index;
  real_T *c1_STATE_HAND_address;
  int32_T c1_STATE_HAND_index;
  real_T *c1_STATE_OVER_address;
  int32_T c1_STATE_OVER_index;
  real_T *c1_STATE_READY_address;
  int32_T c1_STATE_READY_index;
  real_T *c1_STATE_RESULT_address;
  int32_T c1_STATE_RESULT_index;
  real_T *c1_STATE_WAIT_address;
  int32_T c1_STATE_WAIT_index;
  real_T *c1_avert_address;
  int32_T c1_avert_index;
  real_T *c1_avertH_address;
  int32_T c1_avertH_index;
  real_T *c1_avert_gaze_dirs_chance_address;
  int32_T c1_avert_gaze_dirs_chance_index;
  real_T *c1_avert_gaze_duration_factor_address;
  int32_T c1_avert_gaze_duration_factor_index;
  real_T *c1_avert_head_frequency_factor_address;
  int32_T c1_avert_head_frequency_factor_index;
  real_T *c1_avert_head_speed_address;
  int32_T c1_avert_head_speed_index;
  real_T *c1_bHand_address;
  int32_T c1_bHand_index;
  real_T (*c1_bmlsH_address)[5000];
  int32_T c1_bmlsH_index;
  real_T (*c1_bmlsL_address)[5000];
  int32_T c1_bmlsL_index;
  real_T (*c1_bmlsM_address)[5000];
  int32_T c1_bmlsM_index;
  real_T *c1_bodyBusyFlag_address;
  int32_T c1_bodyBusyFlag_index;
  real_T *c1_boredom_address;
  int32_T c1_boredom_index;
  real_T *c1_diff_address;
  int32_T c1_diff_index;
  real_T (*c1_emotion_amount_factor_address)[6];
  int32_T c1_emotion_amount_factor_index;
  real_T *c1_faceBusyFlag_address;
  int32_T c1_faceBusyFlag_index;
  real_T *c1_fileID_address;
  int32_T c1_fileID_index;
  real_T *c1_gazing_address;
  int32_T c1_gazing_index;
  real_T *c1_interest_address;
  int32_T c1_interest_index;
  real_T *c1_mutual_gaze_duration_factor_address;
  int32_T c1_mutual_gaze_duration_factor_index;
  real_T (*c1_n_address)[1000];
  int32_T c1_n_index;
  real_T *c1_pa_address;
  int32_T c1_pa_index;
  real_T *c1_pose_chance_factor_address;
  int32_T c1_pose_chance_factor_index;
  real_T *c1_pose_change_flag_address;
  int32_T c1_pose_change_flag_index;
  real_T *c1_pose_frequency_factor_address;
  int32_T c1_pose_frequency_factor_index;
  real_T *c1_pose_lean_address;
  int32_T c1_pose_lean_index;
  real_T *c1_pose_lean_flag_address;
  int32_T c1_pose_lean_flag_index;
  real_T *c1_pose_selfAdaptor_chance_factor_address;
  int32_T c1_pose_selfAdaptor_chance_factor_index;
  real_T *c1_pose_speed_address;
  int32_T c1_pose_speed_index;
  real_T *c1_pr_address;
  int32_T c1_pr_index;
  real_T *c1_r_address;
  int32_T c1_r_index;
  real_T *c1_randAvertGazeChance_address;
  int32_T c1_randAvertGazeChance_index;
  real_T *c1_randGazeDur_address;
  int32_T c1_randGazeDur_index;
  real_T *c1_randPoseChance_address;
  int32_T c1_randPoseChance_index;
  real_T *c1_randSlowPose_address;
  int32_T c1_randSlowPose_index;
  real_T *c1_randSmile_address;
  int32_T c1_randSmile_index;
  real_T *c1_s_address;
  int32_T c1_s_index;
  real_T *c1_t_address;
  int32_T c1_t_index;
  real_T *c1_temp_address;
  int32_T c1_temp_index;
  real_T *c1_uHand_address;
  int32_T c1_uHand_index;
} SFc1_Demo_GloveInstanceStruct;

#endif                                 /*typedef_SFc1_Demo_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Demo_Glove_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_gatewayc5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc9_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void sf_exported_auto_gatewayc11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_activate_c5_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_activate_c8_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_activate_c20_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_activate_c4_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_activate_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_c11_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_activate_callc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_activate_callc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_activate_callc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_activate_c10_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_incrementTemporalCounter_c5_Demo_Glove_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_incrementTemporalCounter_c8_Demo_Glove_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_incrementTemporalCounter_c20_Demo_Glove_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_incrementTemporalCounter_c4_Demo_Glove_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_incrementTemporalCounter_c11_Demo_Glove_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_incrementTemporalCounter_c10_Demo_Glove_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c5_Demo_Glove_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c8_Demo_Glove_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c20_Demo_Glove_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_resetTemporalCounter_c4_Demo_Glove_secs(SimStruct
  *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c11_Demo_Glove_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_resetTemporalCounter_c10_Demo_Glove_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_deactivate_c5_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c8_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c20_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c4_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c11_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_callc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_callc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_callc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c10_Demo_Glove_secs(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc9_lib_affectiveChar_behavior(SimStruct *
  c1_S);
extern void sf_exported_auto_stepBuffersc11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_duringc9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_enterc11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enterc10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_duringc10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_enablec11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_enablec10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec9_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_disablec10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c5_Demo_Glove(SimStruct
  *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c8_Demo_Glove(SimStruct
  *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c20_Demo_Glove(SimStruct *
  c1_S);
extern void sf_exported_auto_check_state_inconsistency_c4_Demo_Glove(SimStruct
  *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c9_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c11_Demo_Glove(SimStruct *
  c1_S);
extern void sf_exported_auto_check_state_inconsistency_c42_Demo_Glove(SimStruct *
  c1_S);
extern void sf_exported_auto_check_state_inconsistency_c43_Demo_Glove(SimStruct *
  c1_S);
extern void sf_exported_auto_check_state_inconsistency_c44_Demo_Glove(SimStruct *
  c1_S);
extern void sf_exported_auto_check_state_inconsistency_c10_Demo_Glove(SimStruct *
  c1_S);
extern const mxArray *sf_exported_auto_getSimstatec5_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec8_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec20_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec4_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec9_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec11_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec42_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec43_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec44_Demo_Glove(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_setSimstatec5_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec8_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec20_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec4_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec9_lib_affectiveChar_behavior(SimStruct *
  c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec11_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec42_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec43_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec44_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_setSimstatec10_Demo_Glove(SimStruct *c1_S, const
  mxArray *c1_input);
extern void sf_exported_auto_initc5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_initc11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initc10_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc5_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc8_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc20_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc4_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc9_lib_affectiveChar_behavior(SimStruct *
  c1_S);
extern void sf_exported_auto_initBuffersc11_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc42_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc43_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc44_Demo_Glove(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc10_Demo_Glove(SimStruct *c1_S);

/* Function Definitions */
extern void sf_c1_Demo_Glove_get_check_sum(mxArray *plhs[]);
extern void c1_Demo_Glove_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
