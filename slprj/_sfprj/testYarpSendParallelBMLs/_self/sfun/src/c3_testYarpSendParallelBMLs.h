#ifndef __c3_testYarpSendParallelBMLs_h__
#define __c3_testYarpSendParallelBMLs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_testYarpSendParallelBMLsInstanceStruct
#define typedef_SFc3_testYarpSendParallelBMLsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Low;
  uint8_T c3_tp_stateInitial;
  uint8_T c3_tp_tt;
  uint8_T c3_tp_gaze;
  uint8_T c3_tp_face;
  uint8_T c3_tp_High;
  uint8_T c3_tp_init;
  uint8_T c3_tp_b;
  uint8_T c3_tp_bml3;
  uint8_T c3_tp_send;
  uint8_T c3_tp_sendH;
  uint8_T c3_tp_checkHighPriority;
  uint8_T c3_b_tp_init;
  uint8_T c3_tp_sendL;
  uint8_T c3_tp_low;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_testYarpSendParallelBMLs;
  uint8_T c3_is_Low;
  uint8_T c3_is_active_Low;
  uint8_T c3_is_High;
  uint8_T c3_is_active_High;
  uint8_T c3_is_send;
  uint8_T c3_is_active_send;
  real_T c3_BMLl[256];
  real_T c3_qSizeH[2];
  real_T c3_bmlsH[1280];
  real_T c3_BML[256];
  real_T c3_qSizeL[2];
  real_T c3_bmlsL[1280];
  real_T c3_BMLh[256];
  real_T c3_n[256];
  real_T c3_hEmpty;
  real_T c3_lEmpty;
  real_T c3_newBmlsH[1280];
  real_T c3_i;
  real_T c3_newBmlsL[1280];
  real_T c3_bHand;
  real_T c3_cHand;
  real_T c3_A;
  real_T c3_B;
  uint8_T c3_temporalCounter_i1;
  uint8_T c3_temporalCounter_i2;
  uint32_T c3_presentTicks;
  uint32_T c3_elapsedTicks;
  uint32_T c3_previousTicks;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_testYarpSendParallelBMLsInstanceStruct;

#endif                                 /*typedef_SFc3_testYarpSendParallelBMLsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_testYarpSendParallelBMLs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_testYarpSendParallelBMLs_get_check_sum(mxArray *plhs[]);
extern void c3_testYarpSendParallelBMLs_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
