#ifndef __c10_dEMO_EP_IdleRandMerg2_h__
#define __c10_dEMO_EP_IdleRandMerg2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_dEMO_EP_IdleRandMerg2InstanceStruct
#define typedef_SFc10_dEMO_EP_IdleRandMerg2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  uint8_T c10_tp_setBodyFlag;
  uint8_T c10_tp_wait;
  uint8_T c10_tp_init;
  uint8_T c10_tp_flagOne;
  uint8_T c10_tp_check;
  uint8_T c10_tp_flagZero;
  uint8_T c10_tp_setFaceFlag;
  uint8_T c10_tp_wait2;
  uint8_T c10_tp_init2;
  uint8_T c10_tp_flagOne2;
  uint8_T c10_tp_check2;
  uint8_T c10_tp_flagZero2;
  boolean_T c10_isStable;
  uint8_T c10_is_active_c10_dEMO_EP_IdleRandMerg2;
  uint8_T c10_is_setBodyFlag;
  uint8_T c10_is_active_setBodyFlag;
  uint8_T c10_is_setFaceFlag;
  uint8_T c10_is_active_setFaceFlag;
  real_T c10_timer;
  real_T c10_timer2;
  uint32_T c10_temporalCounter_i1;
  uint32_T c10_temporalCounter_i2;
  uint8_T c10_doSetSimStateSideEffects;
  const mxArray *c10_setSimStateSideEffectsInfo;
  real_T *c10_bodyBusyFlag_address;
  int32_T c10_bodyBusyFlag_index;
  real_T *c10_faceBusyFlag_address;
  int32_T c10_faceBusyFlag_index;
} SFc10_dEMO_EP_IdleRandMerg2InstanceStruct;

#endif                                 /*typedef_SFc10_dEMO_EP_IdleRandMerg2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c10_dEMO_EP_IdleRandMerg2_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c10_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c10_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c10_S);
extern void sf_exported_auto_resetTemporalCounter_c10_dEMO_EP_IdleRandMerg2_secs
  (SimStruct *c10_S);
extern void sf_exported_auto_deactivate_c10_dEMO_EP_IdleRandMerg2_secs(SimStruct
  *c10_S);
extern boolean_T sf_exported_auto_isStablec10_dEMO_EP_IdleRandMerg2(SimStruct
  *c10_S);
extern void sf_exported_auto_duringc10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern void sf_exported_auto_enterc10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern void sf_exported_auto_exitc10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern void sf_exported_auto_gatewayc10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern void sf_exported_auto_enablec10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern void sf_exported_auto_disablec10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern void sf_exported_auto_stepBuffersc10_dEMO_EP_IdleRandMerg2(SimStruct
  *c10_S);
extern void sf_exported_auto_initBuffersc10_dEMO_EP_IdleRandMerg2(SimStruct
  *c10_S);
extern void sf_exported_auto_activate_callc10_dEMO_EP_IdleRandMerg2(SimStruct
  *c10_S);
extern void sf_exported_auto_increment_call_counterc10_dEMO_EP_IdleRandMerg2
  (SimStruct *c10_S);
extern void sf_exported_auto_reset_call_counterc10_dEMO_EP_IdleRandMerg2
  (SimStruct *c10_S);
extern void sf_exported_auto_deactivate_callc10_dEMO_EP_IdleRandMerg2(SimStruct *
  c10_S);
extern void sf_exported_auto_initc10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S);
extern const mxArray *sf_exported_auto_getSimstatec10_dEMO_EP_IdleRandMerg2
  (SimStruct *c10_S);
extern const mxArray *sf_internal_get_sim_state_c10_dEMO_EP_IdleRandMerg2
  (SimStruct *c10_S);
extern void sf_exported_auto_setSimstatec10_dEMO_EP_IdleRandMerg2(SimStruct
  *c10_S, const mxArray *c10_in);
extern void sf_internal_set_sim_state_c10_dEMO_EP_IdleRandMerg2(SimStruct *c10_S,
  const mxArray *c10_in);
extern void sf_exported_auto_check_state_inconsistency_c10_dEMO_EP_IdleRandMerg2
  (SimStruct *c10_S);

/* Function Definitions */
extern void sf_c10_dEMO_EP_IdleRandMerg2_get_check_sum(mxArray *plhs[]);
extern void c10_dEMO_EP_IdleRandMerg2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
