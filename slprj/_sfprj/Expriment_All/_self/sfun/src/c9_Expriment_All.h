#ifndef __c9_Expriment_All_h__
#define __c9_Expriment_All_h__

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

#ifndef typedef_c9_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c9_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c9_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c9_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_SFc9_Expriment_AllInstanceStruct
#define typedef_SFc9_Expriment_AllInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_subSmile;
  uint8_T c9_tp_stateInitial;
  uint8_T c9_tp_stateCheckSmile;
  uint8_T c9_tp_gazeCamera;
  uint8_T c9_tp_wait;
  uint8_T c9_tp_checkP;
  uint8_T c9_tp_faceTwitches;
  uint8_T c9_tp_ifHighNeurotic;
  uint8_T c9_tp_init;
  uint8_T c9_tp_weightshiftPoseCategory2;
  uint8_T c9_tp_subFacial;
  uint8_T c9_tp_stateFacialExpression;
  uint8_T c9_tp_initial;
  uint8_T c9_tp_wait3;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_Expriment_All;
  uint8_T c9_is_subSmile;
  uint8_T c9_is_active_subSmile;
  uint8_T c9_is_faceTwitches;
  uint8_T c9_is_active_faceTwitches;
  uint8_T c9_is_subFacial;
  uint8_T c9_is_active_subFacial;
  real_T c9_smileN;
  real_T c9_fileID;
  real_T c9_newBmlsM[10000];
  real_T c9_BMLM[2000];
  real_T c9_n[2000];
  real_T c9_au;
  real_T c9_au_i;
  real_T c9_au_L;
  real_T c9_emoDisp;
  real_T c9_BMLl[2000];
  real_T c9_newBmlsL[10000];
  real_T c9_poseRandFreq;
  real_T c9_poseNum;
  uint8_T c9_temporalCounter_i1;
  uint32_T c9_temporalCounter_i2;
  uint8_T c9_temporalCounter_i3;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T (*c9_BML_address)[2000];
  int32_T c9_BML_index;
  real_T *c9_GAZE_WIN_address;
  int32_T c9_GAZE_WIN_index;
  real_T *c9_P_address;
  int32_T c9_P_index;
  real_T *c9_STATE_BEFORE_address;
  int32_T c9_STATE_BEFORE_index;
  real_T *c9_STATE_GO_address;
  int32_T c9_STATE_GO_index;
  real_T *c9_STATE_READY_address;
  int32_T c9_STATE_READY_index;
  real_T *c9_avert_address;
  int32_T c9_avert_index;
  real_T (*c9_bmlsL_address)[10000];
  int32_T c9_bmlsL_index;
  real_T (*c9_bmlsM_address)[10000];
  int32_T c9_bmlsM_index;
  real_T (*c9_emotion_amount_factor_address)[15];
  int32_T c9_emotion_amount_factor_index;
  real_T *c9_gazing_address;
  int32_T c9_gazing_index;
} SFc9_Expriment_AllInstanceStruct;

#endif                                 /*typedef_SFc9_Expriment_AllInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Expriment_All_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c9_Expriment_All_secs(SimStruct *c9_S);
extern void sf_exported_auto_incrementTemporalCounter_c9_Expriment_All_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_resetTemporalCounter_c9_Expriment_All_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_c9_Expriment_All_secs(SimStruct *c9_S);
extern boolean_T sf_exported_auto_isStablec9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_duringc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_enterc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_exitc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_enablec9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_disablec9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_activate_callc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc9_Expriment_All(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_deactivate_callc9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_initc9_Expriment_All(SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec9_Expriment_All(SimStruct
  *c9_S);
extern const mxArray *sf_internal_get_sim_state_c9_Expriment_All(SimStruct *c9_S);
extern void sf_exported_auto_setSimstatec9_Expriment_All(SimStruct *c9_S, const
  mxArray *c9_in);
extern void sf_internal_set_sim_state_c9_Expriment_All(SimStruct *c9_S, const
  mxArray *c9_in);
extern void sf_exported_auto_check_state_inconsistency_c9_Expriment_All
  (SimStruct *c9_S);
extern void sf_exported_user_c9_Expriment_All_faceTwitchTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000]);
extern void sf_exported_user_c9_Expriment_All_facialExpr(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000]);
extern void sf_exported_user_c9_Expriment_All_insertQueue(SimStruct *c9_S,
  real_T c9_bmls[10000], real_T c9_myBML[2000], real_T c9_newBmls[10000]);
extern void sf_exported_user_c9_Expriment_All_insertQueueLow(SimStruct *c9_S,
  real_T c9_bmls[10000], real_T c9_myBML[2000], real_T c9_newBmls[10000]);
extern void sf_exported_user_c9_Expriment_All_set_AU_Amount(SimStruct *c9_S,
  real_T c9_arousal, real_T c9_valence, real_T c9_inPersonality, real_T
  c9_eAmountFactor[15]);
extern void sf_exported_user_c9_Expriment_All_smileTable(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_poseBML[2000]);

/* Function Definitions */
extern void sf_c9_Expriment_All_get_check_sum(mxArray *plhs[]);
extern void c9_Expriment_All_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
