#ifndef __c39_EP_IdleRandMerg_h__
#define __c39_EP_IdleRandMerg_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc39_EP_IdleRandMergInstanceStruct
#define typedef_SFc39_EP_IdleRandMergInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c39_sfEvent;
  boolean_T c39_isStable;
  boolean_T c39_doneDoubleBufferReInit;
  uint8_T c39_is_active_c39_EP_IdleRandMerg;
} SFc39_EP_IdleRandMergInstanceStruct;

#endif                                 /*typedef_SFc39_EP_IdleRandMergInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c39_EP_IdleRandMerg_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c39_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
extern void c39_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
