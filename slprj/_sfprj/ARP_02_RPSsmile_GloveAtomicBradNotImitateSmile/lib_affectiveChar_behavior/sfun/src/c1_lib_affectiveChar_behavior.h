#ifndef __c1_lib_affectiveChar_behavior_h__
#define __c1_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc1_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_stateRandomPose;
  uint8_T c1_tp_stateBoredPose;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_lib_affectiveChar_behavior;
  uint8_T c1_is_c1_lib_affectiveChar_behavior;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state;
  boolean_T c1_state_not_empty;
  uint32_T c1_b_state[2];
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[625];
  boolean_T c1_c_state_not_empty;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  real_T *c1_BOREDOM_THRESHOLD_address;
  int32_T c1_BOREDOM_THRESHOLD_index;
  real_T *c1_boredom_address;
  int32_T c1_boredom_index;
  real_T *c1_interest_address;
  int32_T c1_interest_index;
  real_T *c1_isPosing_address;
  int32_T c1_isPosing_index;
  real_T *c1_randPoseChance_address;
  int32_T c1_randPoseChance_index;
} SFc1_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc1_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c1_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c1_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void
  sf_exported_auto_resetTemporalCounter_c1_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_c1_lib_affectiveChar_behavior_secs
  (SimStruct *c1_S);
extern boolean_T sf_exported_auto_isStablec1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_duringc1_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_enterc1_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_exitc1_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc1_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void sf_exported_auto_enablec1_lib_affectiveChar_behavior(SimStruct *c1_S);
extern void sf_exported_auto_disablec1_lib_affectiveChar_behavior(SimStruct
  *c1_S);
extern void sf_exported_auto_stepBuffersc1_lib_affectiveChar_behavior(SimStruct *
  c1_S);
extern void sf_exported_auto_initBuffersc1_lib_affectiveChar_behavior(SimStruct *
  c1_S);
extern void sf_exported_auto_activate_callc1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_increment_call_counterc1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_reset_call_counterc1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_deactivate_callc1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_initc1_lib_affectiveChar_behavior(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern const mxArray *sf_internal_get_sim_state_c1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_auto_setSimstatec1_lib_affectiveChar_behavior(SimStruct *
  c1_S, const mxArray *c1_in);
extern void sf_internal_set_sim_state_c1_lib_affectiveChar_behavior(SimStruct
  *c1_S, const mxArray *c1_in);
extern void
  sf_exported_auto_check_state_inconsistency_c1_lib_affectiveChar_behavior
  (SimStruct *c1_S);
extern void sf_exported_user_c1_lib_affectiveChar_behavior_idlePoseBradTable
  (SimStruct *c1_S, real_T c1_bmlID, real_T c1_poseBML[256]);
extern void sf_exported_user_c1_lib_affectiveChar_behavior_sendBML(SimStruct
  *c1_S, real_T c1_arg[256]);

/* Function Definitions */
extern void sf_c1_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c1_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
