#ifndef __c19_DemoGazeFollow_h__
#define __c19_DemoGazeFollow_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_DemoGazeFollowInstanceStruct
#define typedef_SFc19_DemoGazeFollowInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_DemoGazeFollow;
} SFc19_DemoGazeFollowInstanceStruct;

#endif                                 /*typedef_SFc19_DemoGazeFollowInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c19_DemoGazeFollow_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_DemoGazeFollow_get_check_sum(mxArray *plhs[]);
extern void c19_DemoGazeFollow_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
