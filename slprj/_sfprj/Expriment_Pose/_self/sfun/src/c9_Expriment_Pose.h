#ifndef __c9_Expriment_Pose_h__
#define __c9_Expriment_Pose_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Expriment_PoseInstanceStruct
#define typedef_SFc9_Expriment_PoseInstanceStruct

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
  uint8_T c9_tp_subFacial;
  uint8_T c9_tp_stateFacialExpression;
  uint8_T c9_tp_initial;
  uint8_T c9_tp_wait3;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_Expriment_Pose;
  uint8_T c9_is_subSmile;
  uint8_T c9_is_active_subSmile;
  uint8_T c9_is_subFacial;
  uint8_T c9_is_active_subFacial;
  real_T c9_smileN;
  real_T c9_fileID;
  real_T c9_newBmlsM[5000];
  real_T c9_BMLM[1000];
  real_T c9_n[1000];
  real_T c9_au;
  real_T c9_au_i;
  real_T c9_au_L;
  real_T c9_emoDisp;
  real_T c9_BMLl[1000];
  real_T c9_newBmlsL[5000];
  uint8_T c9_temporalCounter_i1;
  uint8_T c9_temporalCounter_i2;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T (*c9_BML_address)[1000];
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
  real_T (*c9_bmlsL_address)[5000];
  int32_T c9_bmlsL_index;
  real_T (*c9_bmlsM_address)[5000];
  int32_T c9_bmlsM_index;
  real_T (*c9_emotion_amount_factor_address)[11];
  int32_T c9_emotion_amount_factor_index;
  real_T *c9_gazing_address;
  int32_T c9_gazing_index;
} SFc9_Expriment_PoseInstanceStruct;

#endif                                 /*typedef_SFc9_Expriment_PoseInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Expriment_Pose_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c9_Expriment_Pose_secs(SimStruct *c9_S);
extern void sf_exported_auto_incrementTemporalCounter_c9_Expriment_Pose_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_resetTemporalCounter_c9_Expriment_Pose_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_c9_Expriment_Pose_secs(SimStruct *c9_S);
extern boolean_T sf_exported_auto_isStablec9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_duringc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_enterc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_exitc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_enablec9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_disablec9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_activate_callc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc9_Expriment_Pose(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_deactivate_callc9_Expriment_Pose(SimStruct *c9_S);
extern void sf_exported_auto_initc9_Expriment_Pose(SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec9_Expriment_Pose(SimStruct
  *c9_S);
extern const mxArray *sf_internal_get_sim_state_c9_Expriment_Pose(SimStruct
  *c9_S);
extern void sf_exported_auto_setSimstatec9_Expriment_Pose(SimStruct *c9_S, const
  mxArray *c9_in);
extern void sf_internal_set_sim_state_c9_Expriment_Pose(SimStruct *c9_S, const
  mxArray *c9_in);
extern void sf_exported_auto_check_state_inconsistency_c9_Expriment_Pose
  (SimStruct *c9_S);
extern void sf_exported_user_c9_Expriment_Pose_facialExpr(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[1000]);
extern void sf_exported_user_c9_Expriment_Pose_insertQueue(SimStruct *c9_S,
  real_T c9_bmls[5000], real_T c9_myBML[1000], real_T c9_newBmls[5000]);
extern void sf_exported_user_c9_Expriment_Pose_insertQueueLow(SimStruct *c9_S,
  real_T c9_bmls[5000], real_T c9_myBML[1000], real_T c9_newBmls[5000]);
extern void sf_exported_user_c9_Expriment_Pose_set_AU_Amount(SimStruct *c9_S,
  real_T c9_arousal, real_T c9_valence, real_T c9_inPersonality, real_T
  c9_eAmountFactor[11]);
extern void sf_exported_user_c9_Expriment_Pose_smileTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[1000]);

/* Function Definitions */
extern void sf_c9_Expriment_Pose_get_check_sum(mxArray *plhs[]);
extern void c9_Expriment_Pose_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
