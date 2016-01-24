#ifndef __c1_AtomicGloveBradImitateSmile_h__
#define __c1_AtomicGloveBradImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_AtomicGloveBradImitateSmileInstanceStruct
#define typedef_SFc1_AtomicGloveBradImitateSmileInstanceStruct

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
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_AtomicGloveBradImitateSmile;
  uint8_T c1_is_active_RPSGameImitateSmileBrad;
  uint8_T c1_is_active_idleGaze;
  uint8_T c1_is_active_idlePoseBrad;
  uint8_T c1_is_active_smile;
  real_T c1_randomH[2];
  SimStruct *c1_subchartSimstruct;
  SimStruct *c1_b_subchartSimstruct;
  SimStruct *c1_c_subchartSimstruct;
  SimStruct *c1_d_subchartSimstruct;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  real_T *c1_BOREDOMT_address;
  int32_T c1_BOREDOMT_index;
  real_T *c1_avert_address;
  int32_T c1_avert_index;
  real_T *c1_b_address;
  int32_T c1_b_index;
  real_T *c1_bHand_address;
  int32_T c1_bHand_index;
  real_T *c1_bored_address;
  int32_T c1_bored_index;
  real_T *c1_diff_address;
  int32_T c1_diff_index;
  real_T *c1_p_address;
  int32_T c1_p_index;
  real_T *c1_pose_address;
  int32_T c1_pose_index;
  real_T *c1_r_address;
  int32_T c1_r_index;
  real_T *c1_randomD_address;
  int32_T c1_randomD_index;
  real_T *c1_randomG_address;
  int32_T c1_randomG_index;
  real_T *c1_randomP_address;
  int32_T c1_randomP_index;
  real_T *c1_s_address;
  int32_T c1_s_index;
  real_T *c1_smileN_address;
  int32_T c1_smileN_index;
  real_T *c1_smileYN_address;
  int32_T c1_smileYN_index;
  real_T *c1_temp_address;
  int32_T c1_temp_index;
  real_T *c1_uHand_address;
  int32_T c1_uHand_index;
  real_T *c1_wristRotate_address;
  int32_T c1_wristRotate_index;
} SFc1_AtomicGloveBradImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc1_AtomicGloveBradImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_AtomicGloveBradImitateSmile_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_gatewayc7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_gatewayc6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_gatewayc5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_gatewayc4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_activate_c7_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_c6_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_c5_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_activate_callc4_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c7_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c6_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c5_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c7_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c6_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c5_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c7_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c6_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c5_AtomicGloveBradImitateSmile_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_callc4_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enterc7_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_duringc7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enterc6_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_duringc6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enterc5_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_duringc5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enterc4_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_duringc4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enablec7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enablec6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enablec5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_enablec4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_disablec4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c7_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c6_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c5_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern void
  sf_exported_auto_check_state_inconsistency_c4_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec7_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec6_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec5_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec4_AtomicGloveBradImitateSmile
  (SimStruct *c1_S);
extern void sf_exported_auto_setSimstatec7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_setSimstatec4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S, const mxArray *c1_input);
extern void sf_exported_auto_initc7_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_initc6_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_initc5_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_initc4_AtomicGloveBradImitateSmile(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc7_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_initBuffersc6_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_initBuffersc5_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);
extern void sf_exported_auto_initBuffersc4_AtomicGloveBradImitateSmile(SimStruct
  *c1_S);

/* Function Definitions */
extern void sf_c1_AtomicGloveBradImitateSmile_get_check_sum(mxArray *plhs[]);
extern void c1_AtomicGloveBradImitateSmile_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
