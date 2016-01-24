#ifndef __c1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_h__
#define __c1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
#define typedef_SFc1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_RPSGameImitateSmileBrad;
  uint8_T c1_tp_idleGaze;
  uint8_T c1_tp_idlePoseBrad;
  uint8_T c1_tp_smile;
  uint8_T c1_tp_setDistanceIfUserMoves;
  uint8_T c1_tp_gazeIfUserMoves;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImi;
  uint8_T c1_is_active_RPSGameImitateSmileBrad;
  uint8_T c1_is_active_idleGaze;
  uint8_T c1_is_active_idlePoseBrad;
  uint8_T c1_is_active_smile;
  uint8_T c1_is_active_setDistanceIfUserMoves;
  uint8_T c1_is_active_gazeIfUserMoves;
  SimStruct *c1_subchartSimstruct;
  SimStruct *c1_b_subchartSimstruct;
  SimStruct *c1_c_subchartSimstruct;
  SimStruct *c1_d_subchartSimstruct;
  SimStruct *c1_e_subchartSimstruct;
  SimStruct *c1_f_subchartSimstruct;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  real_T *c1_BOREDOM_THRESHOLD_address;
  int32_T c1_BOREDOM_THRESHOLD_index;
  real_T *c1_GAZE_GUI_address;
  int32_T c1_GAZE_GUI_index;
  real_T *c1_GAZE_SHOFTEYE_address;
  int32_T c1_GAZE_SHOFTEYE_index;
  real_T *c1_GAZE_USER_HAND_address;
  int32_T c1_GAZE_USER_HAND_index;
  real_T *c1_GAZE_WIN_address;
  int32_T c1_GAZE_WIN_index;
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
  real_T *c1_avert_address;
  int32_T c1_avert_index;
  real_T *c1_bHand_address;
  int32_T c1_bHand_index;
  real_T *c1_boredom_address;
  int32_T c1_boredom_index;
  real_T *c1_diff_address;
  int32_T c1_diff_index;
  real_T *c1_gazing_address;
  int32_T c1_gazing_index;
  real_T *c1_interest_address;
  int32_T c1_interest_index;
  real_T *c1_isPosing_address;
  int32_T c1_isPosing_index;
  real_T *c1_p_address;
  int32_T c1_p_index;
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
  real_T *c1_smileN_address;
  int32_T c1_smileN_index;
  real_T *c1_temp_address;
  int32_T c1_temp_index;
  real_T *c1_uHand_address;
  int32_T c1_uHand_index;
} SFc1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_gatewayc5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_setSimstatec5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_initc5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc5_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc9_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc4_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc8_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc10_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c1_S);

/* Function Definitions */
extern void
  sf_c1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void
  c1_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
