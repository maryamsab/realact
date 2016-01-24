#ifndef __c35_Demo_Glove_h__
#define __c35_Demo_Glove_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_Demo_GloveInstanceStruct
#define typedef_SFc35_Demo_GloveInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  uint8_T c35_tp_stateCreatePawn;
  boolean_T c35_isStable;
  uint8_T c35_is_active_c35_Demo_Glove;
  uint8_T c35_is_c35_Demo_Glove;
  uint8_T c35_doSetSimStateSideEffects;
  const mxArray *c35_setSimStateSideEffectsInfo;
} SFc35_Demo_GloveInstanceStruct;

#endif                                 /*typedef_SFc35_Demo_GloveInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_Demo_Glove_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c35_Demo_Glove_get_check_sum(mxArray *plhs[]);
extern void c35_Demo_Glove_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
