#ifndef __c15_Demo_KinectWaveWalkInvade_h__
#define __c15_Demo_KinectWaveWalkInvade_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_Demo_KinectWaveWalkInvadeInstanceStruct
#define typedef_SFc15_Demo_KinectWaveWalkInvadeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  uint8_T c15_tp_follow;
  uint8_T c15_tp_create;
  boolean_T c15_isStable;
  uint8_T c15_is_active_c15_Demo_KinectWaveWalkInvade;
  uint8_T c15_is_c15_Demo_KinectWaveWalkInvade;
  uint8_T c15_doSetSimStateSideEffects;
  const mxArray *c15_setSimStateSideEffectsInfo;
} SFc15_Demo_KinectWaveWalkInvadeInstanceStruct;

#endif                                 /*typedef_SFc15_Demo_KinectWaveWalkInvadeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_Demo_KinectWaveWalkInvade_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_Demo_KinectWaveWalkInvade_get_check_sum(mxArray *plhs[]);
extern void c15_Demo_KinectWaveWalkInvade_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif