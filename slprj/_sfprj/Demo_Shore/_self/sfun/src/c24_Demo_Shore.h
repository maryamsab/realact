#ifndef __c24_Demo_Shore_h__
#define __c24_Demo_Shore_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_Demo_ShoreInstanceStruct
#define typedef_SFc24_Demo_ShoreInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_Demo_Shore;
} SFc24_Demo_ShoreInstanceStruct;

#endif                                 /*typedef_SFc24_Demo_ShoreInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_Demo_Shore_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_Demo_Shore_get_check_sum(mxArray *plhs[]);
extern void c24_Demo_Shore_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
