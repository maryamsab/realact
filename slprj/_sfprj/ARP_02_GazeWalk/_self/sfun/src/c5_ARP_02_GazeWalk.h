#ifndef __c5_ARP_02_GazeWalk_h__
#define __c5_ARP_02_GazeWalk_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_ARP_02_GazeWalkInstanceStruct
#define typedef_SFc5_ARP_02_GazeWalkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_stateCreatePawn;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_ARP_02_GazeWalk;
  uint8_T c5_is_c5_ARP_02_GazeWalk;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
} SFc5_ARP_02_GazeWalkInstanceStruct;

#endif                                 /*typedef_SFc5_ARP_02_GazeWalkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_ARP_02_GazeWalk_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_ARP_02_GazeWalk_get_check_sum(mxArray *plhs[]);
extern void c5_ARP_02_GazeWalk_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
