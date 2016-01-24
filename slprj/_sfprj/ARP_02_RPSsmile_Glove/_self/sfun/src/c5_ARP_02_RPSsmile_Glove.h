#ifndef __c5_ARP_02_RPSsmile_Glove_h__
#define __c5_ARP_02_RPSsmile_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_ARP_02_RPSsmile_GloveInstanceStruct
#define typedef_SFc5_ARP_02_RPSsmile_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_stateRandomPose;
  uint8_T c5_tp_stateBoredPose;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_ARP_02_RPSsmile_Glove;
  uint8_T c5_is_c5_ARP_02_RPSsmile_Glove;
  uint32_T c5_method;
  boolean_T c5_method_not_empty;
  uint32_T c5_state;
  boolean_T c5_state_not_empty;
  uint32_T c5_b_state[2];
  boolean_T c5_b_state_not_empty;
  uint32_T c5_c_state[625];
  boolean_T c5_c_state_not_empty;
  uint8_T c5_temporalCounter_i1;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  real_T *c5_BOREDOMT_address;
  int32_T c5_BOREDOMT_index;
  real_T *c5_b_address;
  int32_T c5_b_index;
  real_T *c5_bored_address;
  int32_T c5_bored_index;
  real_T *c5_pose_address;
  int32_T c5_pose_index;
  real_T *c5_randomP_address;
  int32_T c5_randomP_index;
} SFc5_ARP_02_RPSsmile_GloveInstanceStruct;

#endif                                 /*typedef_SFc5_ARP_02_RPSsmile_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_ARP_02_RPSsmile_Glove_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c5_ARP_02_RPSsmile_Glove_secs(SimStruct
  *c5_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c5_ARP_02_RPSsmile_Glove_secs
  (SimStruct *c5_S);
extern void sf_exported_auto_resetTemporalCounter_c5_ARP_02_RPSsmile_Glove_secs
  (SimStruct *c5_S);
extern void sf_exported_auto_deactivate_c5_ARP_02_RPSsmile_Glove_secs(SimStruct *
  c5_S);
extern boolean_T sf_exported_auto_isStablec5_ARP_02_RPSsmile_Glove(SimStruct
  *c5_S);
extern void sf_exported_auto_duringc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_enterc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_exitc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_gatewayc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_enablec5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_disablec5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_stepBuffersc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_initBuffersc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern void sf_exported_auto_activate_callc5_ARP_02_RPSsmile_Glove(SimStruct
  *c5_S);
extern void sf_exported_auto_increment_call_counterc5_ARP_02_RPSsmile_Glove
  (SimStruct *c5_S);
extern void sf_exported_auto_reset_call_counterc5_ARP_02_RPSsmile_Glove
  (SimStruct *c5_S);
extern void sf_exported_auto_deactivate_callc5_ARP_02_RPSsmile_Glove(SimStruct
  *c5_S);
extern void sf_exported_auto_initc5_ARP_02_RPSsmile_Glove(SimStruct *c5_S);
extern const mxArray *sf_exported_auto_getSimstatec5_ARP_02_RPSsmile_Glove
  (SimStruct *c5_S);
extern const mxArray *sf_internal_get_sim_state_c5_ARP_02_RPSsmile_Glove
  (SimStruct *c5_S);
extern void sf_exported_auto_setSimstatec5_ARP_02_RPSsmile_Glove(SimStruct *c5_S,
  const mxArray *c5_in);
extern void sf_internal_set_sim_state_c5_ARP_02_RPSsmile_Glove(SimStruct *c5_S,
  const mxArray *c5_in);
extern void sf_exported_auto_check_state_inconsistency_c5_ARP_02_RPSsmile_Glove
  (SimStruct *c5_S);
extern void sf_exported_user_c5_ARP_02_RPSsmile_Glove_boredPoseS(SimStruct *c5_S,
  real_T c5_bmlID, real_T c5_poseBML[256]);
extern void sf_exported_user_c5_ARP_02_RPSsmile_Glove_sendBML(SimStruct *c5_S,
  real_T c5_arg[256]);

/* Function Definitions */
extern void sf_c5_ARP_02_RPSsmile_Glove_get_check_sum(mxArray *plhs[]);
extern void c5_ARP_02_RPSsmile_Glove_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
