#ifndef __c1_ex_custom_code_global_constants_vars_fcns_h__
#define __c1_ex_custom_code_global_constants_vars_fcns_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_ex_custom_code_global_constants_vars_fcnsInstanceStruct
#define typedef_SFc1_ex_custom_code_global_constants_vars_fcnsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_A;
  uint8_T c1_tp_B;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ex_custom_code_global_constants_vars_fcns;
  uint8_T c1_is_c1_ex_custom_code_global_constants_vars_fcns;
  int32_T c1_local_data;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_ex_custom_code_global_constants_vars_fcnsInstanceStruct;

#endif                                 /*typedef_SFc1_ex_custom_code_global_constants_vars_fcnsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_ex_custom_code_global_constants_vars_fcns_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_ex_custom_code_global_constants_vars_fcns_get_check_sum
  (mxArray *plhs[]);
extern void c1_ex_custom_code_global_constants_vars_fcns_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
