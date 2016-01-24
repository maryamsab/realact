#ifndef __c13_DemoSmile_KS_h__
#define __c13_DemoSmile_KS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_DemoSmile_KSInstanceStruct
#define typedef_SFc13_DemoSmile_KSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_DemoSmile_KS;
} SFc13_DemoSmile_KSInstanceStruct;

#endif                                 /*typedef_SFc13_DemoSmile_KSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_DemoSmile_KS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_DemoSmile_KS_get_check_sum(mxArray *plhs[]);
extern void c13_DemoSmile_KS_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
