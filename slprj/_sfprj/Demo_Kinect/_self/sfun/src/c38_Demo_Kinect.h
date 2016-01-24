#ifndef __c38_Demo_Kinect_h__
#define __c38_Demo_Kinect_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc38_Demo_KinectInstanceStruct
#define typedef_SFc38_Demo_KinectInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c38_sfEvent;
  boolean_T c38_isStable;
  boolean_T c38_doneDoubleBufferReInit;
  uint8_T c38_is_active_c38_Demo_Kinect;
} SFc38_Demo_KinectInstanceStruct;

#endif                                 /*typedef_SFc38_Demo_KinectInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c38_Demo_Kinect_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c38_Demo_Kinect_get_check_sum(mxArray *plhs[]);
extern void c38_Demo_Kinect_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
