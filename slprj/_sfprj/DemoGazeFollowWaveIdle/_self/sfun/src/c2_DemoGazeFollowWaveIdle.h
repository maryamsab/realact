#ifndef __c2_DemoGazeFollowWaveIdle_h__
#define __c2_DemoGazeFollowWaveIdle_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_DemoGazeFollowWaveIdleInstanceStruct
#define typedef_SFc2_DemoGazeFollowWaveIdleInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_DemoGazeFollowWaveIdle;
} SFc2_DemoGazeFollowWaveIdleInstanceStruct;

#endif                                 /*typedef_SFc2_DemoGazeFollowWaveIdleInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
extern void c2_DemoGazeFollowWaveIdle_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
