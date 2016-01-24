#ifndef __c1_untitled1_h__
#define __c1_untitled1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_untitled1InstanceStruct
#define typedef_SFc1_untitled1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_stateGame;
  uint8_T c1_tp_stateStart;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_untitled1;
  uint8_T c1_is_stateGame;
  uint8_T c1_is_active_stateGame;
  real_T c1_temp;
  real_T c1_diff;
  real_T c1_uHand;
  real_T c1_bHand;
  real_T c1_smileN;
  real_T c1_smileYN;
  real_T c1_bored;
  real_T c1_BOREDOMT;
  real_T c1_randomG;
  real_T c1_randomP;
  real_T c1_pose;
  real_T c1_b;
  real_T c1_r;
  real_T c1_p;
  real_T c1_s;
  real_T c1_randomD;
  real_T c1_wristRotate;
  real_T c1_randomH;
  uint8_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_untitled1InstanceStruct;

#endif                                 /*typedef_SFc1_untitled1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_untitled1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_untitled1_get_check_sum(mxArray *plhs[]);
extern void c1_untitled1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
