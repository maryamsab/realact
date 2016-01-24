#ifndef __c56_Expriment_Gaze_h__
#define __c56_Expriment_Gaze_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc56_Expriment_GazeInstanceStruct
#define typedef_SFc56_Expriment_GazeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c56_sfEvent;
  boolean_T c56_isStable;
  boolean_T c56_doneDoubleBufferReInit;
  uint8_T c56_is_active_c56_Expriment_Gaze;
} SFc56_Expriment_GazeInstanceStruct;

#endif                                 /*typedef_SFc56_Expriment_GazeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c56_Expriment_Gaze_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c56_Expriment_Gaze_get_check_sum(mxArray *plhs[]);
extern void c56_Expriment_Gaze_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
