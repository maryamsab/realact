#ifndef __c2_old_Demo_RPS_h__
#define __c2_old_Demo_RPS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_old_Demo_RPSInstanceStruct
#define typedef_SFc2_old_Demo_RPSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_old_Demo_RPS;
} SFc2_old_Demo_RPSInstanceStruct;

#endif                                 /*typedef_SFc2_old_Demo_RPSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_old_Demo_RPS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_old_Demo_RPS_get_check_sum(mxArray *plhs[]);
extern void c2_old_Demo_RPS_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
