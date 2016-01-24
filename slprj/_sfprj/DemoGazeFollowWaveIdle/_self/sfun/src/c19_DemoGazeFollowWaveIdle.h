#ifndef __c19_DemoGazeFollowWaveIdle_h__
#define __c19_DemoGazeFollowWaveIdle_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_DemoGazeFollowWaveIdleInstanceStruct
#define typedef_SFc19_DemoGazeFollowWaveIdleInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_DemoGazeFollowWaveIdle;
} SFc19_DemoGazeFollowWaveIdleInstanceStruct;

#endif                                 /*typedef_SFc19_DemoGazeFollowWaveIdleInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c19_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[]);
extern void c19_DemoGazeFollowWaveIdle_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif