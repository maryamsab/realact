#ifndef __c43_lib_affectiveChar_behavior_h__
#define __c43_lib_affectiveChar_behavior_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_lib_affectiveChar_behaviorInstanceStruct
#define typedef_SFc43_lib_affectiveChar_behaviorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c43_sfEvent;
  boolean_T c43_isStable;
  boolean_T c43_doneDoubleBufferReInit;
  uint8_T c43_is_active_c43_lib_affectiveChar_behavior;
  uint8_T c43_doSetSimStateSideEffects;
  const mxArray *c43_setSimStateSideEffectsInfo;
} SFc43_lib_affectiveChar_behaviorInstanceStruct;

#endif                                 /*typedef_SFc43_lib_affectiveChar_behaviorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c43_lib_affectiveChar_behavior_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_duringc43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_enterc43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_exitc43_lib_affectiveChar_behavior(SimStruct *c43_S);
extern void sf_exported_auto_gatewayc43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_enablec43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_disablec43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_stepBuffersc43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_initBuffersc43_lib_affectiveChar_behavior(SimStruct
  *c43_S);
extern void sf_exported_auto_activate_callc43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void
  sf_exported_auto_increment_call_counterc43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_reset_call_counterc43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_deactivate_callc43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_initc43_lib_affectiveChar_behavior(SimStruct *c43_S);
extern const mxArray *sf_exported_auto_getSimstatec43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern const mxArray *sf_internal_get_sim_state_c43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_auto_setSimstatec43_lib_affectiveChar_behavior(SimStruct
  *c43_S, const mxArray *c43_in);
extern void sf_internal_set_sim_state_c43_lib_affectiveChar_behavior(SimStruct
  *c43_S, const mxArray *c43_in);
extern void
  sf_exported_auto_check_state_inconsistency_c43_lib_affectiveChar_behavior
  (SimStruct *c43_S);
extern void sf_exported_user_c43_lib_affectiveChar_behavior_setGazeFactors
  (SimStruct *c43_S, real_T c43_v, real_T c43_a, real_T c43_p, boolean_T
   c43_pFlag, boolean_T c43_vaFlag, real_T c43_gazeArr[6], real_T
   *c43_mutDurFactor, real_T *c43_avertDurFactor, real_T
   *c43_avertHeadFreqFactor, real_T *c43_avertHeadSpeed, real_T
   *c43_avertDirsChance, real_T *c43_avertFreqFactor, real_T *c43_mutFreqFactor,
   real_T *c43_blinkFlag, real_T *c43_blinkPeriodMin, real_T *c43_blinkPeriodMax);
extern void sf_exported_user_c43_lib_affectiveChar_behavior_setPoseFactors
  (SimStruct *c43_S, real_T c43_v, real_T c43_ar, real_T c43_p, boolean_T
   c43_pFlag, boolean_T c43_vaFlag, real_T c43_poseArr[6], real_T
   c43_personalityChange, real_T *c43_poseTwitch, real_T *c43_poseFreqFactor,
   real_T *c43_poseChanceFactor, real_T *c43_poseCatChance, real_T *c43_poseLean,
   real_T *c43_poseSpeed, real_T *c43_poseLeanFlag);

/* Function Definitions */
extern void sf_c43_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[]);
extern void c43_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
