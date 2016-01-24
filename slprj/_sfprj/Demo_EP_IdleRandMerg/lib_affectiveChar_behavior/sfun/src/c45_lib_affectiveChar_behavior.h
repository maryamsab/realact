#ifndef __c45_lib_affectiveChar_behavior_h__
#define __c45_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc45_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc45_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c45_sfEvent;
  boolean_T c45_isStable;
  boolean_T c45_doneDoubleBufferReInit;
  uint8_T c45_is_active_c45_lib_affectiveChar_behavior;
  uint8_T c45_doSetSimStateSideEffects;
  const mxArray *c45_setSimStateSideEffectsInfo;
} SFc45_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc45_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c45_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void sf_exported_auto_duringc45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_enterc45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_exitc45_lib_affectiveChar_behavior(SimStruct *c45_S);
extern void sf_exported_auto_gatewayc45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_enablec45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_disablec45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_stepBuffersc45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_initBuffersc45_lib_affectiveChar_behavior(SimStruct
  *c45_S);
extern void sf_exported_auto_activate_callc45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void
  sf_exported_auto_increment_call_counterc45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void sf_exported_auto_reset_call_counterc45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void sf_exported_auto_deactivate_callc45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void sf_exported_auto_initc45_lib_affectiveChar_behavior(SimStruct *c45_S);
extern const mxArray *sf_exported_auto_getSimstatec45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern const mxArray *sf_internal_get_sim_state_c45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void sf_exported_auto_setSimstatec45_lib_affectiveChar_behavior(SimStruct
  *c45_S, const mxArray *c45_in);
extern void sf_internal_set_sim_state_c45_lib_affectiveChar_behavior(SimStruct
  *c45_S, const mxArray *c45_in);
extern void
  sf_exported_auto_check_state_inconsistency_c45_lib_affectiveChar_behavior
  (SimStruct *c45_S);
extern void sf_exported_user_c45_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c45_S, real_T c45_v, real_T c45_a, real_T c45_p, boolean_T
   c45_pFlag, boolean_T c45_vaFlag, real_T c45_gazeArr[6], real_T
   *c45_mutDurFactor, real_T *c45_avertDurFactor, real_T
   *c45_avertHeadFreqFactor, real_T *c45_avertHeadSpeed, real_T
   *c45_avertDirsChance);

/* Function Definitions */
extern void sf_c45_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c45_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
