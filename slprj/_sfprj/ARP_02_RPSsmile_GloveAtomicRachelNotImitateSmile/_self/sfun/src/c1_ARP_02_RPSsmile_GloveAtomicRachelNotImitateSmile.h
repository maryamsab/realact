#ifndef __c1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_h__
#define __c1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
#define typedef_SFc1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_RPSGameNotImitateSmileRachel;
  uint8_T c1_tp_idleGaze;
  uint8_T c1_tp_idlePoseRachel;
  uint8_T c1_tp_smile;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  uint8_T c1_is_active_RPSGameNotImitateSmileRachel;
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
  real_T *c1_avert_address;
  int32_T c1_avert_index;
  real_T *c1_bHand_address;
  int32_T c1_bHand_index;
  real_T *c1_boredom_address;
  int32_T c1_boredom_index;
  real_T *c1_diff_address;
  int32_T c1_diff_index;
  real_T *c1_interest_address;
  int32_T c1_interest_index;
  real_T *c1_isPosing_address;
  int32_T c1_isPosing_index;
  real_T *c1_isSmiling_address;
  int32_T c1_isSmiling_index;
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
  real_T *c1_randSmile_address;
  int32_T c1_randSmile_index;
  real_T *c1_s_address;
  int32_T c1_s_index;
  real_T *c1_smileDur_address;
  int32_T c1_smileDur_index;
  real_T *c1_smileN_address;
  int32_T c1_smileN_index;
  real_T *c1_temp_address;
  int32_T c1_temp_index;
  real_T *c1_uHand_address;
  int32_T c1_uHand_index;
  real_T *c1_wristRotate_address;
  int32_T c1_wristRotate_index;
} SFc1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_gatewayc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_gatewayc9_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void sf_exported_auto_gatewayc10_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void
  sf_exported_auto_gatewayc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_c10_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_activate_callc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c10_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c10_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_deactivate_callc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_stepBuffersc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc9_lib_affectiveChar_behavior(SimStruct *
  c1_S);
extern void sf_exported_auto_stepBuffersc10_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void
  sf_exported_auto_stepBuffersc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enterc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_enterc9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_duringc9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_enterc10_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_duringc10_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void
  sf_exported_auto_enterc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_duringc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_enablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_enablec9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_enablec10_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void
  sf_exported_auto_enablec11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_disablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_disablec9_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec10_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void
  sf_exported_auto_disablec11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c9_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c10_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec9_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec10_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern const mxArray
  *sf_exported_auto_getSimstatec11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_setSimstatec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec9_lib_affectiveChar_behavior(SimStruct *
  c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec10_lib_affectiveChar_behavior(SimStruct
  *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_setSimstatec11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S, const mxArray *c1_input);
extern void
  sf_exported_auto_initc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_initc9_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_initc10_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void
  sf_exported_auto_initc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_initBuffersc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc9_lib_affectiveChar_behavior(SimStruct *
  c1_S);
extern void sf_exported_auto_initBuffersc10_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void
  sf_exported_auto_initBuffersc11_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c1_S);

/* Function Definitions */
extern void sf_c1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void
  c1_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
