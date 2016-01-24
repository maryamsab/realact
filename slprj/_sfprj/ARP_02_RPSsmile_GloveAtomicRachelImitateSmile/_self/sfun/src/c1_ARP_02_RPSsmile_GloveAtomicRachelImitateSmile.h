#ifndef __c1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_h__
#define __c1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct
#define typedef_SFc1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_RPSGameImitateSmileRachel;
  uint8_T c1_tp_idleGaze;
  uint8_T c1_tp_idlePoseRachel;
  uint8_T c1_tp_smile;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile;
  uint8_T c1_is_active_RPSGameImitateSmileRachel;
  uint8_T c1_is_active_idleGaze;
  uint8_T c1_is_active_idlePoseRachel;
  uint8_T c1_is_active_smile;
  SimStruct *c1_subchartSimstruct;
  SimStruct *c1_b_subchartSimstruct;
  SimStruct *c1_c_subchartSimstruct;
  SimStruct *c1_d_subchartSimstruct;
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
  real_T *c1_s_address;
  int32_T c1_s_index;
  real_T *c1_temp_address;
  int32_T c1_temp_index;
  real_T *c1_uHand_address;
  int32_T c1_uHand_index;
} SFc1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_gatewayc4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_gatewayc11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_setSimstatec4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_initc4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initc11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc4_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc10_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc11_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c1_S);

/* Function Definitions */
extern void sf_c1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void c1_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
