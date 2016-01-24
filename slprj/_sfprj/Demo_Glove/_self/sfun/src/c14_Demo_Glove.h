#ifndef __c14_Demo_Glove_h__
#define __c14_Demo_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_Demo_GloveInstanceStruct
#define typedef_SFc14_Demo_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  boolean_T c14_isStable;
  boolean_T c14_doneDoubleBufferReInit;
  uint8_T c14_is_active_c14_Demo_Glove;
} SFc14_Demo_GloveInstanceStruct;

#endif                                 /*typedef_SFc14_Demo_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c14_Demo_Glove_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c14_Demo_Glove_get_check_sum(mxArray *plhs[]);
extern void c14_Demo_Glove_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
