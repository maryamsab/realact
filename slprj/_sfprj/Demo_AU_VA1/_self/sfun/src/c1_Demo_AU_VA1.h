#ifndef __c1_Demo_AU_VA1_h__
#define __c1_Demo_AU_VA1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Demo_AU_VA1InstanceStruct
#define typedef_SFc1_Demo_AU_VA1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Demo_AU_VA1;
} SFc1_Demo_AU_VA1InstanceStruct;

#endif                                 /*typedef_SFc1_Demo_AU_VA1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Demo_AU_VA1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Demo_AU_VA1_get_check_sum(mxArray *plhs[]);
extern void c1_Demo_AU_VA1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
