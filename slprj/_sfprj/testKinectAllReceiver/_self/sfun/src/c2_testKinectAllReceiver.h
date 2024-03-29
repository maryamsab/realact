#ifndef __c2_testKinectAllReceiver_h__
#define __c2_testKinectAllReceiver_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_testKinectAllReceiverInstanceStruct
#define typedef_SFc2_testKinectAllReceiverInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_stateEnableReceiver;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_testKinectAllReceiver;
  uint8_T c2_is_c2_testKinectAllReceiver;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_testKinectAllReceiverInstanceStruct;

#endif                                 /*typedef_SFc2_testKinectAllReceiverInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_testKinectAllReceiver_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_testKinectAllReceiver_get_check_sum(mxArray *plhs[]);
extern void c2_testKinectAllReceiver_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
