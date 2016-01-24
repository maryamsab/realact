#ifndef __c3_testPersonaliSpace_Kinect_h__
#define __c3_testPersonaliSpace_Kinect_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef enum_invadeStandingSpots
#define enum_invadeStandingSpots

enum invadeStandingSpots
{
  invadeStandingSpots_BACK = 1,
  invadeStandingSpots_MIDDLE = 0,
  invadeStandingSpots_FORWARD = 2
};

#endif                                 /*enum_invadeStandingSpots*/

#ifndef typedef_c3_invadeStandingSpots
#define typedef_c3_invadeStandingSpots

typedef enum invadeStandingSpots c3_invadeStandingSpots;

#endif                                 /*typedef_c3_invadeStandingSpots*/

#ifndef typedef_SFc3_testPersonaliSpace_KinectInstanceStruct
#define typedef_SFc3_testPersonaliSpace_KinectInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_init;
  uint8_T c3_tp_stateGoMiddle;
  uint8_T c3_tp_stateGoBack;
  uint8_T c3_tp_stateGoForward;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_testPersonaliSpace_Kinect;
  uint8_T c3_is_c3_testPersonaliSpace_Kinect;
  real_T c3_BACK;
  real_T c3_FORWARD;
  real_T c3_MIDDLE;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_testPersonaliSpace_KinectInstanceStruct;

#endif                                 /*typedef_SFc3_testPersonaliSpace_KinectInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_testPersonaliSpace_Kinect_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_testPersonaliSpace_Kinect_get_check_sum(mxArray *plhs[]);
extern void c3_testPersonaliSpace_Kinect_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
