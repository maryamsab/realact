#ifndef __c11_lib_affectiveChar_scenario_h__
#define __c11_lib_affectiveChar_scenario_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_lib_affectiveChar_scenarioInstanceStruct
#define typedef_SFc11_lib_affectiveChar_scenarioInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  uint8_T c11_tp_stateRandomPose;
  uint8_T c11_tp_stateBoredPose;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_lib_affectiveChar_scenario;
  uint8_T c11_is_c11_lib_affectiveChar_scenario;
  uint32_T c11_method;
  boolean_T c11_method_not_empty;
  uint32_T c11_state;
  boolean_T c11_state_not_empty;
  uint32_T c11_b_state[2];
  boolean_T c11_b_state_not_empty;
  uint32_T c11_c_state[625];
  boolean_T c11_c_state_not_empty;
  uint8_T c11_temporalCounter_i1;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T *c11_BOREDOMT_address;
  int32_T c11_BOREDOMT_index;
  real_T *c11_b_address;
  int32_T c11_b_index;
  real_T *c11_bored_address;
  int32_T c11_bored_index;
  real_T *c11_pose_address;
  int32_T c11_pose_index;
  real_T *c11_randomP_address;
  int32_T c11_randomP_index;
} SFc11_lib_affectiveChar_scenarioInstanceStruct;

#endif                                 /*typedef_SFc11_lib_affectiveChar_scenarioInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_lib_affectiveChar_scenario_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c11_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c11_S);
extern void
  sf_exported_auto_resetTemporalCounter_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c11_S);
extern boolean_T sf_exported_auto_isStablec11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void sf_exported_auto_duringc11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_enterc11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_exitc11_lib_affectiveChar_scenario(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_enablec11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_disablec11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_stepBuffersc11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_initBuffersc11_lib_affectiveChar_scenario(SimStruct
  *c11_S);
extern void sf_exported_auto_activate_callc11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void
  sf_exported_auto_increment_call_counterc11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void sf_exported_auto_reset_call_counterc11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_callc11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void sf_exported_auto_initc11_lib_affectiveChar_scenario(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void sf_exported_auto_setSimstatec11_lib_affectiveChar_scenario(SimStruct
  *c11_S, const mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_lib_affectiveChar_scenario(SimStruct
  *c11_S, const mxArray *c11_in);
extern void
  sf_exported_auto_check_state_inconsistency_c11_lib_affectiveChar_scenario
  (SimStruct *c11_S);
extern void sf_exported_user_c11_lib_affectiveChar_scenario_boredPoseS(SimStruct
  *c11_S, real_T c11_bmlID, real_T c11_poseBML[256]);
extern void sf_exported_user_c11_lib_affectiveChar_scenario_sendBML(SimStruct
  *c11_S, real_T c11_arg[256]);

/* Function Definitions */
extern void sf_c11_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[]);
extern void c11_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
