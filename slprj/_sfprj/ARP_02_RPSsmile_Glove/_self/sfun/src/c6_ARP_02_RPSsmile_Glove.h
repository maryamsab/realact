#ifndef __c6_ARP_02_RPSsmile_Glove_h__
#define __c6_ARP_02_RPSsmile_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_ARP_02_RPSsmile_GloveInstanceStruct
#define typedef_SFc6_ARP_02_RPSsmile_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  uint8_T c6_tp_stateInitial;
  uint8_T c6_tp_stateHeadNeutral;
  uint8_T c6_tp_stateAvertGaze;
  uint8_T c6_tp_stateAvertHead;
  boolean_T c6_isStable;
  uint8_T c6_is_active_c6_ARP_02_RPSsmile_Glove;
  uint8_T c6_is_c6_ARP_02_RPSsmile_Glove;
  uint32_T c6_method;
  boolean_T c6_method_not_empty;
  uint32_T c6_state;
  boolean_T c6_state_not_empty;
  uint32_T c6_b_state[2];
  boolean_T c6_b_state_not_empty;
  uint32_T c6_c_state[625];
  boolean_T c6_c_state_not_empty;
  uint32_T c6_temporalCounter_i1;
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
  real_T *c6_BOREDOMT_address;
  int32_T c6_BOREDOMT_index;
  real_T *c6_b_address;
  int32_T c6_b_index;
  real_T *c6_bored_address;
  int32_T c6_bored_index;
  real_T *c6_pose_address;
  int32_T c6_pose_index;
  real_T *c6_randomD_address;
  int32_T c6_randomD_index;
  real_T *c6_randomG_address;
  int32_T c6_randomG_index;
  real_T *c6_randomP_address;
  int32_T c6_randomP_index;
} SFc6_ARP_02_RPSsmile_GloveInstanceStruct;

#endif                                 /*typedef_SFc6_ARP_02_RPSsmile_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c6_ARP_02_RPSsmile_Glove_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c6_ARP_02_RPSsmile_Glove_secs(SimStruct
  *c6_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c6_ARP_02_RPSsmile_Glove_secs
  (SimStruct *c6_S);
extern void sf_exported_auto_resetTemporalCounter_c6_ARP_02_RPSsmile_Glove_secs
  (SimStruct *c6_S);
extern void sf_exported_auto_deactivate_c6_ARP_02_RPSsmile_Glove_secs(SimStruct *
  c6_S);
extern boolean_T sf_exported_auto_isStablec6_ARP_02_RPSsmile_Glove(SimStruct
  *c6_S);
extern void sf_exported_auto_duringc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_enterc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_exitc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_gatewayc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_enablec6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_disablec6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_stepBuffersc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_initBuffersc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern void sf_exported_auto_activate_callc6_ARP_02_RPSsmile_Glove(SimStruct
  *c6_S);
extern void sf_exported_auto_increment_call_counterc6_ARP_02_RPSsmile_Glove
  (SimStruct *c6_S);
extern void sf_exported_auto_reset_call_counterc6_ARP_02_RPSsmile_Glove
  (SimStruct *c6_S);
extern void sf_exported_auto_deactivate_callc6_ARP_02_RPSsmile_Glove(SimStruct
  *c6_S);
extern void sf_exported_auto_initc6_ARP_02_RPSsmile_Glove(SimStruct *c6_S);
extern const mxArray *sf_exported_auto_getSimstatec6_ARP_02_RPSsmile_Glove
  (SimStruct *c6_S);
extern const mxArray *sf_internal_get_sim_state_c6_ARP_02_RPSsmile_Glove
  (SimStruct *c6_S);
extern void sf_exported_auto_setSimstatec6_ARP_02_RPSsmile_Glove(SimStruct *c6_S,
  const mxArray *c6_in);
extern void sf_internal_set_sim_state_c6_ARP_02_RPSsmile_Glove(SimStruct *c6_S,
  const mxArray *c6_in);
extern void sf_exported_auto_check_state_inconsistency_c6_ARP_02_RPSsmile_Glove
  (SimStruct *c6_S);
extern void sf_exported_user_c6_ARP_02_RPSsmile_Glove_boredGaze(SimStruct *c6_S,
  real_T c6_bmlID, real_T c6_gazeBML[256]);
extern void sf_exported_user_c6_ARP_02_RPSsmile_Glove_idlePose(SimStruct *c6_S,
  real_T c6_bmlID, real_T c6_poseBML[256]);
extern void sf_exported_user_c6_ARP_02_RPSsmile_Glove_sendBML(SimStruct *c6_S,
  real_T c6_arg[256]);

/* Function Definitions */
extern void sf_c6_ARP_02_RPSsmile_Glove_get_check_sum(mxArray *plhs[]);
extern void c6_ARP_02_RPSsmile_Glove_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
