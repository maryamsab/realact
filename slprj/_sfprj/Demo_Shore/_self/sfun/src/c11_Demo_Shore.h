#ifndef __c11_Demo_Shore_h__
#define __c11_Demo_Shore_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_Demo_ShoreInstanceStruct
#define typedef_SFc11_Demo_ShoreInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  uint8_T c11_tp_subSmile;
  uint8_T c11_tp_stateInitial;
  uint8_T c11_tp_stateCheckSmile;
  uint8_T c11_tp_gazeCamera;
  uint8_T c11_tp_wait;
  uint8_T c11_tp_checkP;
  uint8_T c11_tp_subFacial;
  uint8_T c11_tp_stateFacialExpression;
  uint8_T c11_tp_initial;
  uint8_T c11_b_tp_wait;
  uint8_T c11_tp_wait2;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_Demo_Shore;
  uint8_T c11_is_subSmile;
  uint8_T c11_is_active_subSmile;
  uint8_T c11_is_subFacial;
  uint8_T c11_is_active_subFacial;
  real_T c11_smileN;
  real_T c11_fileID;
  real_T c11_newBmlsM[5000];
  real_T c11_BMLM[1000];
  real_T c11_n[1000];
  real_T c11_au[6];
  real_T c11_au_i;
  real_T c11_au_L;
  real_T c11_emoDisp;
  real_T c11_BMLl[1000];
  real_T c11_newBmlsL[5000];
  uint8_T c11_temporalCounter_i1;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T (*c11_BML_address)[1000];
  int32_T c11_BML_index;
  real_T *c11_GAZE_WIN_address;
  int32_T c11_GAZE_WIN_index;
  real_T *c11_P_address;
  int32_T c11_P_index;
  real_T *c11_STATE_BEFORE_address;
  int32_T c11_STATE_BEFORE_index;
  real_T *c11_STATE_GO_address;
  int32_T c11_STATE_GO_index;
  real_T *c11_STATE_READY_address;
  int32_T c11_STATE_READY_index;
  real_T *c11_avert_address;
  int32_T c11_avert_index;
  real_T (*c11_bmlsL_address)[5000];
  int32_T c11_bmlsL_index;
  real_T (*c11_bmlsM_address)[5000];
  int32_T c11_bmlsM_index;
  real_T (*c11_emotion_amount_factor_address)[6];
  int32_T c11_emotion_amount_factor_index;
  real_T *c11_gazing_address;
  int32_T c11_gazing_index;
} SFc11_Demo_ShoreInstanceStruct;

#endif                                 /*typedef_SFc11_Demo_ShoreInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_Demo_Shore_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c11_Demo_Shore_secs(SimStruct *c11_S);
extern void sf_exported_auto_incrementTemporalCounter_c11_Demo_Shore_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_resetTemporalCounter_c11_Demo_Shore_secs(SimStruct *
  c11_S);
extern void sf_exported_auto_deactivate_c11_Demo_Shore_secs(SimStruct *c11_S);
extern boolean_T sf_exported_auto_isStablec11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_duringc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_enterc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_exitc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_enablec11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_disablec11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_stepBuffersc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_initBuffersc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_activate_callc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_increment_call_counterc11_Demo_Shore(SimStruct
  *c11_S);
extern void sf_exported_auto_reset_call_counterc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_deactivate_callc11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_initc11_Demo_Shore(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_Demo_Shore(SimStruct
  *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_Demo_Shore(SimStruct *c11_S);
extern void sf_exported_auto_setSimstatec11_Demo_Shore(SimStruct *c11_S, const
  mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_Demo_Shore(SimStruct *c11_S, const
  mxArray *c11_in);
extern void sf_exported_auto_check_state_inconsistency_c11_Demo_Shore(SimStruct *
  c11_S);
extern void sf_exported_user_c11_Demo_Shore_facialExpr(SimStruct *c11_S, real_T
  c11_bmlID, real_T *c11_p, real_T c11_poseBML[1000]);
extern void sf_exported_user_c11_Demo_Shore_insertQueue(SimStruct *c11_S, real_T
  c11_bmls[5000], real_T c11_myBML[1000], real_T c11_newBmls[5000]);
extern void sf_exported_user_c11_Demo_Shore_insertQueueLow(SimStruct *c11_S,
  real_T c11_bmls[5000], real_T c11_myBML[1000], real_T c11_newBmls[5000]);
extern void sf_exported_user_c11_Demo_Shore_setAU(SimStruct *c11_S, real_T c11_E,
  real_T c11_AU[6], real_T *c11_L);
extern void sf_exported_user_c11_Demo_Shore_set_eAmountFactor(SimStruct *c11_S,
  real_T c11_E, real_T c11_p, real_T c11_cFactor, real_T c11_eAmountFactor[6]);
extern void sf_exported_user_c11_Demo_Shore_smileTable(SimStruct *c11_S, real_T
  c11_bmlID, real_T *c11_p, real_T c11_poseBML[1000]);

/* Function Definitions */
extern void sf_c11_Demo_Shore_get_check_sum(mxArray *plhs[]);
extern void c11_Demo_Shore_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
