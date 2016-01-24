#ifndef __c47_lib_affectiveChar_behavior_h__
#define __c47_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc47_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc47_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c47_sfEvent;
  boolean_T c47_isStable;
  boolean_T c47_doneDoubleBufferReInit;
  uint8_T c47_is_active_c47_lib_affectiveChar_behavior;
  uint8_T c47_doSetSimStateSideEffects;
  const mxArray *c47_setSimStateSideEffectsInfo;
} SFc47_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc47_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c47_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void sf_exported_auto_duringc47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_enterc47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_exitc47_lib_affectiveChar_behavior(SimStruct *c47_S);
extern void sf_exported_auto_gatewayc47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_enablec47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_disablec47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_stepBuffersc47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_initBuffersc47_lib_affectiveChar_behavior(SimStruct
  *c47_S);
extern void sf_exported_auto_activate_callc47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void
  sf_exported_auto_increment_call_counterc47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void sf_exported_auto_reset_call_counterc47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void sf_exported_auto_deactivate_callc47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void sf_exported_auto_initc47_lib_affectiveChar_behavior(SimStruct *c47_S);
extern const mxArray *sf_exported_auto_getSimstatec47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern const mxArray *sf_internal_get_sim_state_c47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void sf_exported_auto_setSimstatec47_lib_affectiveChar_behavior(SimStruct
  *c47_S, const mxArray *c47_in);
extern void sf_internal_set_sim_state_c47_lib_affectiveChar_behavior(SimStruct
  *c47_S, const mxArray *c47_in);
extern void
  sf_exported_auto_check_state_inconsistency_c47_lib_affectiveChar_behavior
  (SimStruct *c47_S);
extern void sf_exported_user_c47_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c47_S, real_T c47_v, real_T c47_a, real_T c47_p, boolean_T
   c47_pFlag, boolean_T c47_vaFlag, real_T c47_gazeArr[6], real_T
   *c47_mutDurFactor, real_T *c47_avertDurFactor, real_T
   *c47_avertHeadFreqFactor, real_T *c47_avertHeadSpeed, real_T
   *c47_avertDirsChance, real_T *c47_avertFreqFactor, real_T *c47_mutFreqFactor);
extern void sf_exported_user_c47_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c47_S, real_T c47_v, real_T c47_ar, real_T c47_p, boolean_T
   c47_pFlag, boolean_T c47_vaFlag, real_T c47_poseArr[6], real_T
   c47_personalityChange, real_T *c47_poseTwitch, real_T *c47_poseFreqFactor,
   real_T *c47_poseChanceFactor, real_T *c47_poseCatChance, real_T *c47_poseLean,
   real_T *c47_poseSpeed, real_T *c47_poseLeanFlag);

/* Function Definitions */
extern void sf_c47_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c47_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
