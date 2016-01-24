#ifndef __c1_dEMO_EP_IdleRandMerg2_h__
#define __c1_dEMO_EP_IdleRandMerg2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_dEMO_EP_IdleRandMerg2InstanceStruct
#define typedef_SFc1_dEMO_EP_IdleRandMerg2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_attendChange;
  uint8_T c1_tp_sendBMLbyPriority;
  uint8_T c1_tp_sendH;
  uint8_T c1_tp_init;
  uint8_T c1_tp_checkHighPriority;
  uint8_T c1_tp_sendM;
  uint8_T c1_tp_Mid;
  uint8_T c1_tp_sendL;
  uint8_T c1_tp_low;
  uint8_T c1_tp_RPSGameImitateSmileBrad;
  uint8_T c1_tp_setDistanceIfUserMoves;
  uint8_T c1_tp_waveBack;
  uint8_T c1_tp_smile;
  uint8_T c1_tp_Gaze;
  uint8_T c1_tp_idlePoseBrad;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_dEMO_EP_IdleRandMerg2;
  uint8_T c1_is_active_attendChange;
  uint8_T c1_is_sendBMLbyPriority;
  uint8_T c1_is_active_sendBMLbyPriority;
  uint8_T c1_is_active_RPSGameImitateSmileBrad;
  uint8_T c1_is_active_setDistanceIfUserMoves;
  uint8_T c1_is_active_waveBack;
  uint8_T c1_is_active_smile;
  uint8_T c1_is_active_Gaze;
  uint8_T c1_is_active_idlePoseBrad;
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
  real_T *c1_faceBusyFlag_address;
  int32_T c1_faceBusyFlag_index;
  real_T *c1_fileID_address;
  int32_T c1_fileID_index;
  real_T *c1_gazing_address;
  int32_T c1_gazing_index;
  real_T *c1_interest_address;
  int32_T c1_interest_index;
  real_T (*c1_n_address)[1000];
  int32_T c1_n_index;
  real_T *c1_pa_address;
  int32_T c1_pa_index;
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
} SFc1_dEMO_EP_IdleRandMerg2InstanceStruct;

#endif                                 /*typedef_SFc1_dEMO_EP_IdleRandMerg2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_dEMO_EP_IdleRandMerg2_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_gatewayc10_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc20_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc11_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_activate_c10_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c5_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c8_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c20_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c11_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c9_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c4_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c5_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c8_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c20_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c11_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c4_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c10_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c5_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c8_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c20_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c11_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c9_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_resetTemporalCounter_c4_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c10_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_deactivate_c5_dEMO_EP_IdleRandMerg2_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_deactivate_c8_dEMO_EP_IdleRandMerg2_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_deactivate_c20_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_deactivate_c11_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c1_S);
extern void sf_exported_auto_deactivate_c9_dEMO_EP_IdleRandMerg2_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_deactivate_c4_dEMO_EP_IdleRandMerg2_secs(SimStruct *
  c1_S);
extern void sf_exported_auto_stepBuffersc10_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc20_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc11_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc10_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc10_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc20_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc20_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc11_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc11_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enterc4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_duringc4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec10_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec20_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec11_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_enablec4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec10_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec20_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec11_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_disablec4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c10_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c5_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c8_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c20_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c11_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c9_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_check_state_inconsistency_c4_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec10_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec5_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec8_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec20_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec11_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec9_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec4_dEMO_EP_IdleRandMerg2
  (SimStruct *c1_S);
extern void sf_exported_auto_setSimstatec10_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S,
  const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S,
  const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec20_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec11_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S,
  const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S,
  const mxArray *c1_input);
extern void sf_exported_auto_initc10_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initc5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initc8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initc20_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initc11_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initc9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initc4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc10_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S);
extern void sf_exported_auto_initBuffersc5_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc8_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc20_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S);
extern void sf_exported_auto_initBuffersc11_dEMO_EP_IdleRandMerg2(SimStruct
  *c1_S);
extern void sf_exported_auto_initBuffersc9_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc4_dEMO_EP_IdleRandMerg2(SimStruct *c1_S);

/* Function Definitions */
extern void sf_c1_dEMO_EP_IdleRandMerg2_get_check_sum(mxArray *plhs[]);
extern void c1_dEMO_EP_IdleRandMerg2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
