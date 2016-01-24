#ifndef __c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_h__
#define __c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
#define typedef_SFc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_stateRandomPose;
  uint8_T c4_tp_stateBoredPose;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  uint8_T c4_is_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  uint32_T c4_method;
  boolean_T c4_method_not_empty;
  uint32_T c4_state;
  boolean_T c4_state_not_empty;
  uint32_T c4_b_state[2];
  boolean_T c4_b_state_not_empty;
  uint32_T c4_c_state[625];
  boolean_T c4_c_state_not_empty;
  uint8_T c4_temporalCounter_i1;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  real_T *c4_BOREDOM_THRESHOLD_address;
  int32_T c4_BOREDOM_THRESHOLD_index;
  real_T *c4_boredom_address;
  int32_T c4_boredom_index;
  real_T *c4_interest_address;
  int32_T c4_interest_index;
  real_T *c4_isPosing_address;
  int32_T c4_isPosing_index;
  real_T *c4_randPoseChance_address;
  int32_T c4_randPoseChance_index;
} SFc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_activate_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c4_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c4_S);
extern void
  sf_exported_auto_resetTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c4_S);
extern void
  sf_exported_auto_deactivate_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c4_S);
extern boolean_T
  sf_exported_auto_isStablec4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_duringc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_enterc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_exitc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_gatewayc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_enablec4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_disablec4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_stepBuffersc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_initBuffersc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_activate_callc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_increment_call_counterc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_reset_call_counterc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_deactivate_callc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_initc4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern const mxArray
  *sf_exported_auto_getSimstatec4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern const mxArray
  *sf_internal_get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_auto_setSimstatec4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S, const mxArray *c4_in);
extern void
  sf_internal_set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S, const mxArray *c4_in);
extern void
  sf_exported_auto_check_state_inconsistency_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c4_S);
extern void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_idlePoseBradTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256]);
extern void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_sendBML
  (SimStruct *c4_S, real_T c4_arg[256]);

/* Function Definitions */
extern void sf_c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void c4_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
