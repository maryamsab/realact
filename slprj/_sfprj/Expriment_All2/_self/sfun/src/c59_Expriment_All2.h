#ifndef __c59_Expriment_All2_h__
#define __c59_Expriment_All2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sL6LJlPlxhdTxZzXh5NTaQC
#define struct_sL6LJlPlxhdTxZzXh5NTaQC

struct sL6LJlPlxhdTxZzXh5NTaQC
{
  int32_T intNumBits;
};

#endif                                 /*struct_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_c59_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c59_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c59_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c59_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_SFc59_Expriment_All2InstanceStruct
#define typedef_SFc59_Expriment_All2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c59_sfEvent;
  boolean_T c59_isStable;
  boolean_T c59_doneDoubleBufferReInit;
  uint8_T c59_is_active_c59_Expriment_All2;
  uint8_T c59_doSetSimStateSideEffects;
  const mxArray *c59_setSimStateSideEffectsInfo;
} SFc59_Expriment_All2InstanceStruct;

#endif                                 /*typedef_SFc59_Expriment_All2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c59_Expriment_All2_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_duringc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_enterc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_exitc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_gatewayc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_enablec59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_disablec59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_stepBuffersc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_initBuffersc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_activate_callc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_increment_call_counterc59_Expriment_All2(SimStruct *
  c59_S);
extern void sf_exported_auto_reset_call_counterc59_Expriment_All2(SimStruct
  *c59_S);
extern void sf_exported_auto_deactivate_callc59_Expriment_All2(SimStruct *c59_S);
extern void sf_exported_auto_initc59_Expriment_All2(SimStruct *c59_S);
extern const mxArray *sf_exported_auto_getSimstatec59_Expriment_All2(SimStruct
  *c59_S);
extern const mxArray *sf_internal_get_sim_state_c59_Expriment_All2(SimStruct
  *c59_S);
extern void sf_exported_auto_setSimstatec59_Expriment_All2(SimStruct *c59_S,
  const mxArray *c59_in);
extern void sf_internal_set_sim_state_c59_Expriment_All2(SimStruct *c59_S, const
  mxArray *c59_in);
extern void sf_exported_auto_check_state_inconsistency_c59_Expriment_All2
  (SimStruct *c59_S);
extern void sf_exported_user_c59_Expriment_All2_setGazeFactors(SimStruct *c59_S,
  real_T c59_v, real_T c59_a, real_T c59_p, boolean_T c59_pFlag, boolean_T
  c59_vaFlag, real_T c59_gazeArr[6], real_T c59_personalityChange, real_T
  *c59_mutDurFactor, real_T *c59_avertDurFactor, real_T *c59_avertHeadFreqFactor,
  real_T *c59_avertHeadSpeed, real_T *c59_avertDirsChance, real_T
  *c59_avertFreqFactor, real_T *c59_mutFreqFactor, real_T *c59_blinkFlag, real_T
  *c59_blinkPeriodMin, real_T *c59_blinkPeriodMax);
extern void sf_exported_user_c59_Expriment_All2_setPoseFactors(SimStruct *c59_S,
  real_T c59_v, real_T c59_ar, real_T c59_p, boolean_T c59_pFlag, boolean_T
  c59_vaFlag, real_T c59_poseArr[6], real_T c59_personalityChange, real_T
  *c59_poseTwitch, real_T *c59_poseFreqFactor, real_T *c59_poseChanceFactor,
  real_T *c59_poseCatChance, real_T *c59_poseLean, real_T *c59_poseSpeed, real_T
  *c59_poseSpace, real_T *c59_poseLeanFlag);

/* Function Definitions */
extern void sf_c59_Expriment_All2_get_check_sum(mxArray *plhs[]);
extern void c59_Expriment_All2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
