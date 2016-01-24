#ifndef __c3_testBradImitateSmile_h__
#define __c3_testBradImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_testBradImitateSmileInstanceStruct
#define typedef_SFc3_testBradImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_smile;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_testBradImitateSmile;
  uint8_T c3_is_c3_testBradImitateSmile;
  SimStruct *c3_subchartSimstruct;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_testBradImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc3_testBradImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_testBradImitateSmile_get_eml_resolved_functions_info
  (void);
extern void sf_exported_auto_gatewayc4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_activate_callc4_testBradImitateSmile(SimStruct
  *c3_S);
extern void sf_exported_auto_deactivate_callc4_testBradImitateSmile(SimStruct
  *c3_S);
extern void sf_exported_auto_stepBuffersc4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_enterc4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_duringc4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_enablec4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_disablec4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_check_state_inconsistency_c4_testBradImitateSmile
  (SimStruct *c3_S);
extern const mxArray *sf_exported_auto_getSimstatec4_testBradImitateSmile
  (SimStruct *c3_S);
extern void sf_exported_auto_setSimstatec4_testBradImitateSmile(SimStruct *c3_S,
  const mxArray *c3_input);
extern void sf_exported_auto_initc4_testBradImitateSmile(SimStruct *c3_S);
extern void sf_exported_auto_initBuffersc4_testBradImitateSmile(SimStruct *c3_S);

/* Function Definitions */
extern void sf_c3_testBradImitateSmile_get_check_sum(mxArray *plhs[]);
extern void c3_testBradImitateSmile_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
