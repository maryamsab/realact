#ifndef __c11_Demo_EP_IdleRand_h__
#define __c11_Demo_EP_IdleRand_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_Demo_EP_IdleRandInstanceStruct
#define typedef_SFc11_Demo_EP_IdleRandInstanceStruct

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
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_Demo_EP_IdleRand;
  uint8_T c11_is_subSmile;
  uint8_T c11_is_active_subSmile;
  uint8_T c11_is_subFacial;
  uint8_T c11_is_active_subFacial;
  real_T c11_smileN;
  real_T c11_fileID;
  real_T c11_newBmlsM[1280];
  real_T c11_BMLM[256];
  real_T c11_n[256];
  real_T c11_l;
  real_T c11_au[6];
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
} SFc11_Demo_EP_IdleRandInstanceStruct;

#endif                                 /*typedef_SFc11_Demo_EP_IdleRandInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_Demo_EP_IdleRand_get_eml_resolved_functions_info
  (void);
extern void sf_exported_auto_activate_c11_Demo_EP_IdleRand_secs(SimStruct *c11_S);
extern void sf_exported_auto_incrementTemporalCounter_c11_Demo_EP_IdleRand_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_resetTemporalCounter_c11_Demo_EP_IdleRand_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_c11_Demo_EP_IdleRand_secs(SimStruct
  *c11_S);
extern boolean_T sf_exported_auto_isStablec11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_duringc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_enterc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_exitc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_enablec11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_disablec11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_stepBuffersc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_initBuffersc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_activate_callc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern void sf_exported_auto_increment_call_counterc11_Demo_EP_IdleRand
  (SimStruct *c11_S);
extern void sf_exported_auto_reset_call_counterc11_Demo_EP_IdleRand(SimStruct
  *c11_S);
extern void sf_exported_auto_deactivate_callc11_Demo_EP_IdleRand(SimStruct
  *c11_S);
extern void sf_exported_auto_initc11_Demo_EP_IdleRand(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_Demo_EP_IdleRand(SimStruct
  *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_Demo_EP_IdleRand(SimStruct
  *c11_S);
extern void sf_exported_auto_setSimstatec11_Demo_EP_IdleRand(SimStruct *c11_S,
  const mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_Demo_EP_IdleRand(SimStruct *c11_S,
  const mxArray *c11_in);
extern void sf_exported_auto_check_state_inconsistency_c11_Demo_EP_IdleRand
  (SimStruct *c11_S);
extern void sf_exported_user_c11_Demo_EP_IdleRand_EAU(SimStruct *c11_S, real_T
  c11_E, real_T c11_AU[6]);
extern void sf_exported_user_c11_Demo_EP_IdleRand_facialExpr(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);
extern void sf_exported_user_c11_Demo_EP_IdleRand_insertQueue(SimStruct *c11_S,
  real_T c11_bmls[1280], real_T c11_myBML[256], real_T c11_newBmls[1280]);
extern void sf_exported_user_c11_Demo_EP_IdleRand_smileTable(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);

/* Function Definitions */
extern void sf_c11_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
extern void c11_Demo_EP_IdleRand_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
