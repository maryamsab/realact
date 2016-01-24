#ifndef __c19_Demo_GazeFWaveIdleRand_h__
#define __c19_Demo_GazeFWaveIdleRand_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_Demo_GazeFWaveIdleRandInstanceStruct
#define typedef_SFc19_Demo_GazeFWaveIdleRandInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_Demo_GazeFWaveIdleRand;
} SFc19_Demo_GazeFWaveIdleRandInstanceStruct;

#endif                                 /*typedef_SFc19_Demo_GazeFWaveIdleRandInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c19_Demo_GazeFWaveIdleRand_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_Demo_GazeFWaveIdleRand_get_check_sum(mxArray *plhs[]);
extern void c19_Demo_GazeFWaveIdleRand_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
