#ifndef __c1_testAtomicGazeWalk_h__
#define __c1_testAtomicGazeWalk_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_testAtomicGazeWalkInstanceStruct
#define typedef_SFc1_testAtomicGazeWalkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_stateCreatePawn;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_testAtomicGazeWalk;
  uint8_T c1_is_c1_testAtomicGazeWalk;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_testAtomicGazeWalkInstanceStruct;

#endif                                 /*typedef_SFc1_testAtomicGazeWalkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_testAtomicGazeWalk_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_testAtomicGazeWalk_get_check_sum(mxArray *plhs[]);
extern void c1_testAtomicGazeWalk_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
