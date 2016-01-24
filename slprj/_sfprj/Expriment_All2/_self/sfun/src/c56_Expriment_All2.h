#ifndef __c56_Expriment_All2_h__
#define __c56_Expriment_All2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc56_Expriment_All2InstanceStruct
#define typedef_SFc56_Expriment_All2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c56_sfEvent;
  boolean_T c56_isStable;
  boolean_T c56_doneDoubleBufferReInit;
  uint8_T c56_is_active_c56_Expriment_All2;
} SFc56_Expriment_All2InstanceStruct;

#endif                                 /*typedef_SFc56_Expriment_All2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c56_Expriment_All2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c56_Expriment_All2_get_check_sum(mxArray *plhs[]);
extern void c56_Expriment_All2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
