#ifndef __c3_ARP_02_PointUser_AnTS_h__
#define __c3_ARP_02_PointUser_AnTS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ARP_02_PointUser_AnTSInstanceStruct
#define typedef_SFc3_ARP_02_PointUser_AnTSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_p;
  uint8_T c3_tp_1;
  uint8_T c3_tp_stateIdle;
  uint8_T c3_tp_stateCalculateUserStatus;
  uint8_T c3_tp_statePointRight;
  uint8_T c3_tp_statePointLeft;
  uint8_T c3_tp_stateTarget;
  uint8_T c3_tp_2;
  uint8_T c3_tp_stateFacialExpression;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_ARP_02_PointUser_AnTS;
  uint8_T c3_is_c3_ARP_02_PointUser_AnTS;
  uint8_T c3_is_1;
  uint8_T c3_is_active_1;
  uint8_T c3_is_2;
  uint8_T c3_is_active_2;
  real_T c3_round_count;
  uint32_T c3_method;
  boolean_T c3_method_not_empty;
  uint32_T c3_state;
  boolean_T c3_state_not_empty;
  uint32_T c3_b_state[2];
  boolean_T c3_b_state_not_empty;
  uint32_T c3_c_state[625];
  boolean_T c3_c_state_not_empty;
  uint8_T c3_temporalCounter_i1;
  uint8_T c3_temporalCounter_i2;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_ARP_02_PointUser_AnTSInstanceStruct;

#endif                                 /*typedef_SFc3_ARP_02_PointUser_AnTSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_ARP_02_PointUser_AnTS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ARP_02_PointUser_AnTS_get_check_sum(mxArray *plhs[]);
extern void c3_ARP_02_PointUser_AnTS_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
