#ifndef __c3_Demo_AU_VA_SBM_h__
#define __c3_Demo_AU_VA_SBM_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Demo_AU_VA_SBMInstanceStruct
#define typedef_SFc3_Demo_AU_VA_SBMInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_facialExpression_Controller;
  uint8_T c3_tp_sendBMLbyPriority;
  uint8_T c3_tp_sendH;
  uint8_T c3_tp_init;
  uint8_T c3_tp_checkHighPriority;
  uint8_T c3_tp_sendM;
  uint8_T c3_tp_Mid;
  uint8_T c3_tp_sendL;
  uint8_T c3_tp_low;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_Demo_AU_VA_SBM;
  uint8_T c3_is_active_facialExpression_Controller;
  uint8_T c3_is_sendBMLbyPriority;
  uint8_T c3_is_active_sendBMLbyPriority;
  real_T c3_newBmlsL[5000];
  real_T c3_hEmpty;
  real_T c3_newBmlsM[5000];
  real_T c3_bmlsM[5000];
  real_T c3_newBmlsH[5000];
  real_T c3_bmlsH[5000];
  real_T c3_newBmlA;
  real_T c3_BML[1000];
  real_T c3_lEmpty;
  real_T c3_mEmpty;
  real_T c3_n[1000];
  SimStruct *c3_subchartSimstruct;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T (*c3_bmlsL_address)[5000];
  int32_T c3_bmlsL_index;
} SFc3_Demo_AU_VA_SBMInstanceStruct;

#endif                                 /*typedef_SFc3_Demo_AU_VA_SBMInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Demo_AU_VA_SBM_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_gatewayc50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_activate_c50_Demo_AU_VA_SBM_secs(SimStruct *c3_S);
extern void sf_exported_auto_incrementTemporalCounter_c50_Demo_AU_VA_SBM_secs
  (SimStruct *c3_S);
extern void sf_exported_auto_resetTemporalCounter_c50_Demo_AU_VA_SBM_secs
  (SimStruct *c3_S);
extern void sf_exported_auto_deactivate_c50_Demo_AU_VA_SBM_secs(SimStruct *c3_S);
extern void sf_exported_auto_stepBuffersc50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_enterc50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_duringc50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_enablec50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_disablec50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_check_state_inconsistency_c50_Demo_AU_VA_SBM
  (SimStruct *c3_S);
extern const mxArray *sf_exported_auto_getSimstatec50_Demo_AU_VA_SBM(SimStruct
  *c3_S);
extern void sf_exported_auto_setSimstatec50_Demo_AU_VA_SBM(SimStruct *c3_S,
  const mxArray *c3_input);
extern void sf_exported_auto_initc50_Demo_AU_VA_SBM(SimStruct *c3_S);
extern void sf_exported_auto_initBuffersc50_Demo_AU_VA_SBM(SimStruct *c3_S);

/* Function Definitions */
extern void sf_c3_Demo_AU_VA_SBM_get_check_sum(mxArray *plhs[]);
extern void c3_Demo_AU_VA_SBM_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
