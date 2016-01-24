#ifndef __c46_lib_affectiveChar_behavior_h__
#define __c46_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc46_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc46_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c46_sfEvent;
  boolean_T c46_isStable;
  boolean_T c46_doneDoubleBufferReInit;
  uint8_T c46_is_active_c46_lib_affectiveChar_behavior;
  uint8_T c46_doSetSimStateSideEffects;
  const mxArray *c46_setSimStateSideEffectsInfo;
} SFc46_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc46_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c46_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void sf_exported_auto_duringc46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_enterc46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_exitc46_lib_affectiveChar_behavior(SimStruct *c46_S);
extern void sf_exported_auto_gatewayc46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_enablec46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_disablec46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_stepBuffersc46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_initBuffersc46_lib_affectiveChar_behavior(SimStruct
  *c46_S);
extern void sf_exported_auto_activate_callc46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void
  sf_exported_auto_increment_call_counterc46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void sf_exported_auto_reset_call_counterc46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void sf_exported_auto_deactivate_callc46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void sf_exported_auto_initc46_lib_affectiveChar_behavior(SimStruct *c46_S);
extern const mxArray *sf_exported_auto_getSimstatec46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern const mxArray *sf_internal_get_sim_state_c46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void sf_exported_auto_setSimstatec46_lib_affectiveChar_behavior(SimStruct
  *c46_S, const mxArray *c46_in);
extern void sf_internal_set_sim_state_c46_lib_affectiveChar_behavior(SimStruct
  *c46_S, const mxArray *c46_in);
extern void
  sf_exported_auto_check_state_inconsistency_c46_lib_affectiveChar_behavior
  (SimStruct *c46_S);
extern void sf_exported_user_c46_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c46_S, real_T c46_v, real_T c46_a, real_T c46_p, boolean_T
   c46_pFlag, boolean_T c46_vaFlag, real_T c46_gazeArr[6], real_T
   *c46_mutDurFactor, real_T *c46_avertDurFactor, real_T
   *c46_avertHeadFreqFactor, real_T *c46_avertHeadSpeed, real_T
   *c46_avertDirsChance, real_T *c46_avertFreqFactor, real_T *c46_mutFreqFactor);
extern void sf_exported_user_c46_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c46_S, real_T c46_v, real_T c46_ar, real_T c46_p, boolean_T
   c46_pFlag, boolean_T c46_vaFlag, real_T c46_poseArr[6], real_T
   c46_personalityChange, real_T *c46_poseTwitch, real_T *c46_poseFreqFactor,
   real_T *c46_poseChanceFactor, real_T *c46_poseCatChance, real_T *c46_poseLean,
   real_T *c46_poseSpeed, real_T *c46_poseLeanFlag);

/* Function Definitions */
extern void sf_c46_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c46_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
