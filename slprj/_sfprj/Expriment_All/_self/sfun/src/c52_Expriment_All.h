#ifndef __c52_Expriment_All_h__
#define __c52_Expriment_All_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc52_Expriment_AllInstanceStruct
#define typedef_SFc52_Expriment_AllInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c52_sfEvent;
  boolean_T c52_isStable;
  boolean_T c52_doneDoubleBufferReInit;
  uint8_T c52_is_active_c52_Expriment_All;
} SFc52_Expriment_AllInstanceStruct;

#endif                                 /*typedef_SFc52_Expriment_AllInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c52_Expriment_All_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c52_Expriment_All_get_check_sum(mxArray *plhs[]);
extern void c52_Expriment_All_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
