#ifndef __c9_lib_affectiveChar_behavior_h__
#define __c9_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc9_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_stateInitial;
  uint8_T c9_tp_stateHeadNeutral;
  uint8_T c9_tp_stateAvertGaze;
  uint8_T c9_tp_stateAvertHead;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_lib_affectiveChar_behavior;
  uint8_T c9_is_c9_lib_affectiveChar_behavior;
  uint32_T c9_method;
  boolean_T c9_method_not_empty;
  uint32_T c9_state;
  boolean_T c9_state_not_empty;
  uint32_T c9_b_state[2];
  boolean_T c9_b_state_not_empty;
  uint32_T c9_c_state[625];
  boolean_T c9_c_state_not_empty;
  uint32_T c9_temporalCounter_i1;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T *c9_BOREDOM_THRESHOLD_address;
  int32_T c9_BOREDOM_THRESHOLD_index;
  real_T *c9_boredom_address;
  int32_T c9_boredom_index;
  real_T *c9_interest_address;
  int32_T c9_interest_index;
  real_T *c9_isPosing_address;
  int32_T c9_isPosing_index;
  real_T *c9_randAvertGazeChance_address;
  int32_T c9_randAvertGazeChance_index;
  real_T *c9_randGazeDur_address;
  int32_T c9_randGazeDur_index;
  real_T *c9_randPoseChance_address;
  int32_T c9_randPoseChance_index;
} SFc9_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc9_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c9_S);
extern boolean_T sf_exported_auto_isStablec9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void sf_exported_auto_duringc9_lib_affectiveChar_behavior(SimStruct *c9_S);
extern void sf_exported_auto_enterc9_lib_affectiveChar_behavior(SimStruct *c9_S);
extern void sf_exported_auto_exitc9_lib_affectiveChar_behavior(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc9_lib_affectiveChar_behavior(SimStruct
  *c9_S);
extern void sf_exported_auto_enablec9_lib_affectiveChar_behavior(SimStruct *c9_S);
extern void sf_exported_auto_disablec9_lib_affectiveChar_behavior(SimStruct
  *c9_S);
extern void sf_exported_auto_stepBuffersc9_lib_affectiveChar_behavior(SimStruct *
  c9_S);
extern void sf_exported_auto_initBuffersc9_lib_affectiveChar_behavior(SimStruct *
  c9_S);
extern void sf_exported_auto_activate_callc9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void sf_exported_auto_reset_call_counterc9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_callc9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void sf_exported_auto_initc9_lib_affectiveChar_behavior(SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern const mxArray *sf_internal_get_sim_state_c9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void sf_exported_auto_setSimstatec9_lib_affectiveChar_behavior(SimStruct *
  c9_S, const mxArray *c9_in);
extern void sf_internal_set_sim_state_c9_lib_affectiveChar_behavior(SimStruct
  *c9_S, const mxArray *c9_in);
extern void
  sf_exported_auto_check_state_inconsistency_c9_lib_affectiveChar_behavior
  (SimStruct *c9_S);
extern void
  sf_exported_user_c9_lib_affectiveChar_behavior_idleGazeInterestedTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_lib_affectiveChar_behavior_idleGazeTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_lib_affectiveChar_behavior_sendBML(SimStruct
  *c9_S, real_T c9_arg[256]);

/* Function Definitions */
extern void sf_c9_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c9_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
