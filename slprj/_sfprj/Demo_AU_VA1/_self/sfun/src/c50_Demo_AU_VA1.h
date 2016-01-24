#ifndef __c50_Demo_AU_VA1_h__
#define __c50_Demo_AU_VA1_h__

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

#ifndef typedef_c50_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c50_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c50_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c50_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_SFc50_Demo_AU_VA1InstanceStruct
#define typedef_SFc50_Demo_AU_VA1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  uint8_T c50_tp_subFacial;
  uint8_T c50_tp_stateFacialExpression;
  uint8_T c50_tp_initial;
  uint8_T c50_tp_wait;
  boolean_T c50_isStable;
  uint8_T c50_is_active_c50_Demo_AU_VA1;
  uint8_T c50_is_subFacial;
  uint8_T c50_is_active_subFacial;
  real_T c50_BMLl[1000];
  real_T c50_newBmlsL[5000];
  uint8_T c50_temporalCounter_i1;
  uint8_T c50_doSetSimStateSideEffects;
  const mxArray *c50_setSimStateSideEffectsInfo;
  real_T (*c50_bmlsL_address)[5000];
  int32_T c50_bmlsL_index;
} SFc50_Demo_AU_VA1InstanceStruct;

#endif                                 /*typedef_SFc50_Demo_AU_VA1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c50_Demo_AU_VA1_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c50_Demo_AU_VA1_secs(SimStruct *c50_S);
extern void sf_exported_auto_incrementTemporalCounter_c50_Demo_AU_VA1_secs
  (SimStruct *c50_S);
extern void sf_exported_auto_resetTemporalCounter_c50_Demo_AU_VA1_secs(SimStruct
  *c50_S);
extern void sf_exported_auto_deactivate_c50_Demo_AU_VA1_secs(SimStruct *c50_S);
extern boolean_T sf_exported_auto_isStablec50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_duringc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_enterc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_exitc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_gatewayc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_enablec50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_disablec50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_stepBuffersc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_initBuffersc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_activate_callc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_increment_call_counterc50_Demo_AU_VA1(SimStruct
  *c50_S);
extern void sf_exported_auto_reset_call_counterc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_deactivate_callc50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_initc50_Demo_AU_VA1(SimStruct *c50_S);
extern const mxArray *sf_exported_auto_getSimstatec50_Demo_AU_VA1(SimStruct
  *c50_S);
extern const mxArray *sf_internal_get_sim_state_c50_Demo_AU_VA1(SimStruct *c50_S);
extern void sf_exported_auto_setSimstatec50_Demo_AU_VA1(SimStruct *c50_S, const
  mxArray *c50_in);
extern void sf_internal_set_sim_state_c50_Demo_AU_VA1(SimStruct *c50_S, const
  mxArray *c50_in);
extern void sf_exported_auto_check_state_inconsistency_c50_Demo_AU_VA1(SimStruct
  *c50_S);
extern void sf_exported_user_c50_Demo_AU_VA1_insertQueueLow(SimStruct *c50_S,
  real_T c50_bmls[5000], real_T c50_myBML[1000], real_T c50_newBmls[5000]);
extern void sf_exported_user_c50_Demo_AU_VA1_set_AU_Amount(SimStruct *c50_S,
  real_T c50_arousal, real_T c50_valence, real_T c50_eAmountFactor[11]);

/* Function Definitions */
extern void sf_c50_Demo_AU_VA1_get_check_sum(mxArray *plhs[]);
extern void c50_Demo_AU_VA1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
