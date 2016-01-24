#ifndef __c4_lib_affectiveChar_behavior_h__
#define __c4_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc4_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_stateInitial;
  uint8_T c4_tp_stateCheck;
  uint8_T c4_tp_stateSmile;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_lib_affectiveChar_behavior;
  uint8_T c4_is_c4_lib_affectiveChar_behavior;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  real_T *c4_avert_address;
  int32_T c4_avert_index;
  real_T *c4_isPosing_address;
  int32_T c4_isPosing_index;
} SFc4_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc4_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_auto_duringc4_lib_affectiveChar_behavior(SimStruct *c4_S);
extern void sf_exported_auto_enterc4_lib_affectiveChar_behavior(SimStruct *c4_S);
extern void sf_exported_auto_exitc4_lib_affectiveChar_behavior(SimStruct *c4_S);
extern void sf_exported_auto_gatewayc4_lib_affectiveChar_behavior(SimStruct
  *c4_S);
extern void sf_exported_auto_enablec4_lib_affectiveChar_behavior(SimStruct *c4_S);
extern void sf_exported_auto_disablec4_lib_affectiveChar_behavior(SimStruct
  *c4_S);
extern void sf_exported_auto_stepBuffersc4_lib_affectiveChar_behavior(SimStruct *
  c4_S);
extern void sf_exported_auto_initBuffersc4_lib_affectiveChar_behavior(SimStruct *
  c4_S);
extern void sf_exported_auto_activate_callc4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_auto_increment_call_counterc4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_auto_reset_call_counterc4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_auto_deactivate_callc4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_auto_initc4_lib_affectiveChar_behavior(SimStruct *c4_S);
extern const mxArray *sf_exported_auto_getSimstatec4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern const mxArray *sf_internal_get_sim_state_c4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_auto_setSimstatec4_lib_affectiveChar_behavior(SimStruct *
  c4_S, const mxArray *c4_in);
extern void sf_internal_set_sim_state_c4_lib_affectiveChar_behavior(SimStruct
  *c4_S, const mxArray *c4_in);
extern void
  sf_exported_auto_check_state_inconsistency_c4_lib_affectiveChar_behavior
  (SimStruct *c4_S);
extern void sf_exported_user_c4_lib_affectiveChar_behavior_sendBML(SimStruct
  *c4_S, real_T c4_arg[256]);
extern void sf_exported_user_c4_lib_affectiveChar_behavior_smileTable(SimStruct *
  c4_S, real_T c4_bmlID, real_T c4_poseBML[256]);

/* Function Definitions */
extern void sf_c4_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c4_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
