#ifndef __c56_Expriment_Emotion_h__
#define __c56_Expriment_Emotion_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc56_Expriment_EmotionInstanceStruct
#define typedef_SFc56_Expriment_EmotionInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c56_sfEvent;
  boolean_T c56_isStable;
  boolean_T c56_doneDoubleBufferReInit;
  uint8_T c56_is_active_c56_Expriment_Emotion;
  uint8_T c56_doSetSimStateSideEffects;
  const mxArray *c56_setSimStateSideEffectsInfo;
} SFc56_Expriment_EmotionInstanceStruct;

#endif                                 /*typedef_SFc56_Expriment_EmotionInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c56_Expriment_Emotion_get_eml_resolved_functions_info
  (void);
extern boolean_T sf_exported_auto_isStablec56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_duringc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_enterc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_exitc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_gatewayc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_enablec56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_disablec56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_stepBuffersc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_initBuffersc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_activate_callc56_Expriment_Emotion(SimStruct *c56_S);
extern void sf_exported_auto_increment_call_counterc56_Expriment_Emotion
  (SimStruct *c56_S);
extern void sf_exported_auto_reset_call_counterc56_Expriment_Emotion(SimStruct
  *c56_S);
extern void sf_exported_auto_deactivate_callc56_Expriment_Emotion(SimStruct
  *c56_S);
extern void sf_exported_auto_initc56_Expriment_Emotion(SimStruct *c56_S);
extern const mxArray *sf_exported_auto_getSimstatec56_Expriment_Emotion
  (SimStruct *c56_S);
extern const mxArray *sf_internal_get_sim_state_c56_Expriment_Emotion(SimStruct *
  c56_S);
extern void sf_exported_auto_setSimstatec56_Expriment_Emotion(SimStruct *c56_S,
  const mxArray *c56_in);
extern void sf_internal_set_sim_state_c56_Expriment_Emotion(SimStruct *c56_S,
  const mxArray *c56_in);
extern void sf_exported_auto_check_state_inconsistency_c56_Expriment_Emotion
  (SimStruct *c56_S);
extern void sf_exported_user_c56_Expriment_Emotion_setGazeFactors(SimStruct
  *c56_S, real_T c56_v, real_T c56_a, real_T c56_p, boolean_T c56_pFlag,
  boolean_T c56_vaFlag, real_T c56_gazeArr[6], real_T *c56_mutDurFactor, real_T *
  c56_avertDurFactor, real_T *c56_avertHeadFreqFactor, real_T
  *c56_avertHeadSpeed, real_T *c56_avertDirsChance, real_T *c56_avertFreqFactor,
  real_T *c56_mutFreqFactor);
extern void sf_exported_user_c56_Expriment_Emotion_setPoseFactors(SimStruct
  *c56_S, real_T c56_v, real_T c56_ar, real_T c56_p, boolean_T c56_pFlag,
  boolean_T c56_vaFlag, real_T c56_poseArr[6], real_T c56_personalityChange,
  real_T *c56_poseTwitch, real_T *c56_poseFreqFactor, real_T
  *c56_poseChanceFactor, real_T *c56_poseCatChance, real_T *c56_poseLean, real_T
  *c56_poseSpeed, real_T *c56_poseLeanFlag, real_T *c56_poseSpace);

/* Function Definitions */
extern void sf_c56_Expriment_Emotion_get_check_sum(mxArray *plhs[]);
extern void c56_Expriment_Emotion_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
