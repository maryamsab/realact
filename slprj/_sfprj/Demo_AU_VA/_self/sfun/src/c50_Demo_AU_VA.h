#ifndef __c50_Demo_AU_VA_h__
#define __c50_Demo_AU_VA_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc50_Demo_AU_VAInstanceStruct
#define typedef_SFc50_Demo_AU_VAInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  uint8_T c50_tp_subFaceTwitch;
  uint8_T c50_tp_init;
  uint8_T c50_tp_randFace;
  uint8_T c50_tp_subFacial;
  uint8_T c50_tp_stateFacialExpression;
  uint8_T c50_tp_initial;
  uint8_T c50_tp_wait;
  uint8_T c50_tp_subFacial1;
  uint8_T c50_b_tp_stateFacialExpression;
  uint8_T c50_b_tp_initial;
  uint8_T c50_tp_wait3;
  boolean_T c50_isStable;
  uint8_T c50_is_active_c50_Demo_AU_VA;
  uint8_T c50_is_subFaceTwitch;
  uint8_T c50_is_active_subFaceTwitch;
  uint8_T c50_is_subFacial;
  uint8_T c50_is_active_subFacial;
  uint8_T c50_is_subFacial1;
  uint8_T c50_is_active_subFacial1;
  real_T c50_BMLl[1000];
  real_T c50_newBmlsL[5000];
  real_T c50_au_L;
  real_T c50_au[6];
  real_T c50_randNum;
  real_T c50_pp;
  real_T c50_num;
  uint32_T c50_method;
  boolean_T c50_method_not_empty;
  uint32_T c50_state;
  boolean_T c50_state_not_empty;
  uint32_T c50_b_state[2];
  boolean_T c50_b_state_not_empty;
  uint32_T c50_c_state[625];
  boolean_T c50_c_state_not_empty;
  uint8_T c50_temporalCounter_i1;
  uint8_T c50_temporalCounter_i2;
  uint8_T c50_temporalCounter_i3;
  uint8_T c50_doSetSimStateSideEffects;
  const mxArray *c50_setSimStateSideEffectsInfo;
  real_T (*c50_bmlsL_address)[5000];
  int32_T c50_bmlsL_index;
} SFc50_Demo_AU_VAInstanceStruct;

#endif                                 /*typedef_SFc50_Demo_AU_VAInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c50_Demo_AU_VA_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c50_Demo_AU_VA_secs(SimStruct *c50_S);
extern void sf_exported_auto_incrementTemporalCounter_c50_Demo_AU_VA_secs
  (SimStruct *c50_S);
extern void sf_exported_auto_resetTemporalCounter_c50_Demo_AU_VA_secs(SimStruct *
  c50_S);
extern void sf_exported_auto_deactivate_c50_Demo_AU_VA_secs(SimStruct *c50_S);
extern boolean_T sf_exported_auto_isStablec50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_duringc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_enterc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_exitc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_gatewayc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_enablec50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_disablec50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_stepBuffersc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_initBuffersc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_activate_callc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_increment_call_counterc50_Demo_AU_VA(SimStruct
  *c50_S);
extern void sf_exported_auto_reset_call_counterc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_deactivate_callc50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_initc50_Demo_AU_VA(SimStruct *c50_S);
extern const mxArray *sf_exported_auto_getSimstatec50_Demo_AU_VA(SimStruct
  *c50_S);
extern const mxArray *sf_internal_get_sim_state_c50_Demo_AU_VA(SimStruct *c50_S);
extern void sf_exported_auto_setSimstatec50_Demo_AU_VA(SimStruct *c50_S, const
  mxArray *c50_in);
extern void sf_internal_set_sim_state_c50_Demo_AU_VA(SimStruct *c50_S, const
  mxArray *c50_in);
extern void sf_exported_auto_check_state_inconsistency_c50_Demo_AU_VA(SimStruct *
  c50_S);
extern void sf_exported_user_c50_Demo_AU_VA_faceTwitch(SimStruct *c50_S, real_T
  c50_bmlID, real_T *c50_p, real_T c50_poseBML[1000]);
extern void sf_exported_user_c50_Demo_AU_VA_insertQueueLow(SimStruct *c50_S,
  real_T c50_bmls[5000], real_T c50_myBML[1000], real_T c50_newBmls[5000]);
extern void sf_exported_user_c50_Demo_AU_VA_setAU(SimStruct *c50_S, real_T c50_E,
  real_T c50_AU[6], real_T *c50_L);
extern void sf_exported_user_c50_Demo_AU_VA_set_AU_Amount(SimStruct *c50_S,
  real_T c50_arousal, real_T c50_valence, real_T c50_eAmountFactor[11]);
extern void sf_exported_user_c50_Demo_AU_VA_set_eAmountFactor(SimStruct *c50_S,
  real_T c50_E, real_T c50_AU[6], real_T c50_arousal, real_T c50_valence, real_T
  c50_eAmountFactor2[6]);

/* Function Definitions */
extern void sf_c50_Demo_AU_VA_get_check_sum(mxArray *plhs[]);
extern void c50_Demo_AU_VA_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
