#ifndef __c50_lib_affectiveChar_behavior_h__
#define __c50_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc50_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc50_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  boolean_T c50_isStable;
  boolean_T c50_doneDoubleBufferReInit;
  uint8_T c50_is_active_c50_lib_affectiveChar_behavior;
  uint8_T c50_doSetSimStateSideEffects;
  const mxArray *c50_setSimStateSideEffectsInfo;
} SFc50_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc50_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c50_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void sf_exported_auto_duringc50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_enterc50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_exitc50_lib_affectiveChar_behavior(SimStruct *c50_S);
extern void sf_exported_auto_gatewayc50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_enablec50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_disablec50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior(SimStruct
  *c50_S);
extern void sf_exported_auto_activate_callc50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void
  sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void sf_exported_auto_initc50_lib_affectiveChar_behavior(SimStruct *c50_S);
extern const mxArray *sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern const mxArray *sf_internal_get_sim_state_c50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior(SimStruct
  *c50_S, const mxArray *c50_in);
extern void sf_internal_set_sim_state_c50_lib_affectiveChar_behavior(SimStruct
  *c50_S, const mxArray *c50_in);
extern void
  sf_exported_auto_check_state_inconsistency_c50_lib_affectiveChar_behavior
  (SimStruct *c50_S);
extern void sf_exported_user_c50_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c50_S, real_T c50_v, real_T c50_a, real_T c50_p, boolean_T
   c50_pFlag, boolean_T c50_vaFlag, real_T c50_gazeArr[6], real_T
   *c50_mutDurFactor, real_T *c50_avertDurFactor, real_T
   *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
   *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
   real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax);
extern void sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c50_S, real_T c50_v, real_T c50_ar, real_T c50_p, boolean_T
   c50_pFlag, boolean_T c50_vaFlag, real_T c50_poseArr[6], real_T
   c50_personalityChange, real_T *c50_poseTwitch, real_T *c50_poseFreqFactor,
   real_T *c50_poseChanceFactor, real_T *c50_poseCatChance, real_T *c50_poseLean,
   real_T *c50_poseSpeed, real_T *c50_poseLeanFlag);

/* Function Definitions */
extern void sf_c50_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c50_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
