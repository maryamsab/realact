#ifndef __c37_Demo_Glove_h__
#define __c37_Demo_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_Demo_GloveInstanceStruct
#define typedef_SFc37_Demo_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_Demo_Glove;
} SFc37_Demo_GloveInstanceStruct;

#endif                                 /*typedef_SFc37_Demo_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_Demo_Glove_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c37_Demo_Glove_get_check_sum(mxArray *plhs[]);
extern void c37_Demo_Glove_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
