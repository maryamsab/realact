#ifndef __c11_EP_IdleRand_K_h__
#define __c11_EP_IdleRand_K_h__

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

#ifndef typedef_c11_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c11_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c11_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c11_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_SFc11_EP_IdleRand_KInstanceStruct
#define typedef_SFc11_EP_IdleRand_KInstanceStruct

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
  uint8_T c11_tp_initial;
  uint8_T c11_tp_stateFacialExpression;
  uint8_T c11_tp_check_i;
  uint8_T c11_tp_loop;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_EP_IdleRand_K;
  uint8_T c11_is_subSmile;
  uint8_T c11_is_active_subSmile;
  uint8_T c11_is_subFacial;
  uint8_T c11_is_active_subFacial;
  real_T c11_smileN;
  real_T c11_fileID;
  real_T c11_newBmlsM[1280];
  real_T c11_BMLM[256];
  real_T c11_n[256];
  real_T c11_au[6];
  real_T c11_eAmountF[6];
  real_T c11_au_i;
  real_T c11_au_L;
  uint16_T c11_temporalCounter_i1;
  uint8_T c11_temporalCounter_i2;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T (*c11_BML_address)[256];
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
  real_T (*c11_bmlsM_address)[1280];
  int32_T c11_bmlsM_index;
  real_T *c11_changeFlag_address;
  int32_T c11_changeFlag_index;
  real_T *c11_gazing_address;
  int32_T c11_gazing_index;
} SFc11_EP_IdleRand_KInstanceStruct;

#endif                                 /*typedef_SFc11_EP_IdleRand_KInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_EP_IdleRand_K_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c11_EP_IdleRand_K_secs(SimStruct *c11_S);
extern void sf_exported_auto_incrementTemporalCounter_c11_EP_IdleRand_K_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_resetTemporalCounter_c11_EP_IdleRand_K_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_c11_EP_IdleRand_K_secs(SimStruct *c11_S);
extern boolean_T sf_exported_auto_isStablec11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_duringc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_enterc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_exitc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_enablec11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_disablec11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_stepBuffersc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_initBuffersc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_activate_callc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_increment_call_counterc11_EP_IdleRand_K(SimStruct
  *c11_S);
extern void sf_exported_auto_reset_call_counterc11_EP_IdleRand_K(SimStruct
  *c11_S);
extern void sf_exported_auto_deactivate_callc11_EP_IdleRand_K(SimStruct *c11_S);
extern void sf_exported_auto_initc11_EP_IdleRand_K(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_EP_IdleRand_K(SimStruct
  *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_EP_IdleRand_K(SimStruct
  *c11_S);
extern void sf_exported_auto_setSimstatec11_EP_IdleRand_K(SimStruct *c11_S,
  const mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_EP_IdleRand_K(SimStruct *c11_S, const
  mxArray *c11_in);
extern void sf_exported_auto_check_state_inconsistency_c11_EP_IdleRand_K
  (SimStruct *c11_S);
extern void sf_exported_user_c11_EP_IdleRand_K_facialExpr(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);
extern void sf_exported_user_c11_EP_IdleRand_K_insertQueue(SimStruct *c11_S,
  real_T c11_bmls[1280], real_T c11_myBML[256], real_T c11_newBmls[1280]);
extern void sf_exported_user_c11_EP_IdleRand_K_setAU(SimStruct *c11_S, real_T
  c11_E, real_T c11_AU[6], real_T *c11_L);
extern void sf_exported_user_c11_EP_IdleRand_K_set_eAmountFactor(SimStruct
  *c11_S, real_T c11_E, real_T c11_Pt, real_T c11_eAmountFactor[6]);
extern void sf_exported_user_c11_EP_IdleRand_K_smileTable(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);

/* Function Definitions */
extern void sf_c11_EP_IdleRand_K_get_check_sum(mxArray *plhs[]);
extern void c11_EP_IdleRand_K_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
