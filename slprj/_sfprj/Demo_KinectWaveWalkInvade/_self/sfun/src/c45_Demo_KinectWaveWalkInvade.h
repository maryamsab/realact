#ifndef __c45_Demo_KinectWaveWalkInvade_h__
#define __c45_Demo_KinectWaveWalkInvade_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc45_Demo_KinectWaveWalkInvadeInstanceStruct
#define typedef_SFc45_Demo_KinectWaveWalkInvadeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c45_sfEvent;
  boolean_T c45_isStable;
  boolean_T c45_doneDoubleBufferReInit;
  uint8_T c45_is_active_c45_Demo_KinectWaveWalkInvade;
} SFc45_Demo_KinectWaveWalkInvadeInstanceStruct;

#endif                                 /*typedef_SFc45_Demo_KinectWaveWalkInvadeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c45_Demo_KinectWaveWalkInvade_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c45_Demo_KinectWaveWalkInvade_get_check_sum(mxArray *plhs[]);
extern void c45_Demo_KinectWaveWalkInvade_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
