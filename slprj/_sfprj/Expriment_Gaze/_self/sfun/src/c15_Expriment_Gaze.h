#ifndef __c15_Expriment_Gaze_h__
#define __c15_Expriment_Gaze_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_Expriment_GazeInstanceStruct
#define typedef_SFc15_Expriment_GazeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  uint8_T c15_tp_stateCreatePawn;
  boolean_T c15_isStable;
  uint8_T c15_is_active_c15_Expriment_Gaze;
  uint8_T c15_is_c15_Expriment_Gaze;
  uint8_T c15_doSetSimStateSideEffects;
  const mxArray *c15_setSimStateSideEffectsInfo;
} SFc15_Expriment_GazeInstanceStruct;

#endif                                 /*typedef_SFc15_Expriment_GazeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_Expriment_Gaze_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_Expriment_Gaze_get_check_sum(mxArray *plhs[]);
extern void c15_Expriment_Gaze_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
