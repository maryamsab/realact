#ifndef __c10_DemoGazeFollowWaveIdleRand_h__
#define __c10_DemoGazeFollowWaveIdleRand_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_DemoGazeFollowWaveIdleRandInstanceStruct
#define typedef_SFc10_DemoGazeFollowWaveIdleRandInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  uint8_T c10_tp_wait;
  uint8_T c10_tp_init;
  uint8_T c10_tp_check;
  uint8_T c10_tp_flagOne;
  uint8_T c10_tp_flagZero;
  boolean_T c10_isStable;
  uint8_T c10_is_active_c10_DemoGazeFollowWaveIdleRand;
  uint8_T c10_is_c10_DemoGazeFollowWaveIdleRand;
  real_T c10_timer;
  uint32_T c10_temporalCounter_i1;
  uint8_T c10_doSetSimStateSideEffects;
  const mxArray *c10_setSimStateSideEffectsInfo;
  real_T *c10_changeFlag_address;
  int32_T c10_changeFlag_index;
} SFc10_DemoGazeFollowWaveIdleRandInstanceStruct;

#endif                                 /*typedef_SFc10_DemoGazeFollowWaveIdleRandInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c10_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c10_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c10_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c10_S);
extern void
  sf_exported_auto_resetTemporalCounter_c10_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c10_S);
extern void sf_exported_auto_deactivate_c10_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c10_S);
extern boolean_T sf_exported_auto_isStablec10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern void sf_exported_auto_duringc10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_enterc10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_exitc10_DemoGazeFollowWaveIdleRand(SimStruct *c10_S);
extern void sf_exported_auto_gatewayc10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_enablec10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_disablec10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_stepBuffersc10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_initBuffersc10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S);
extern void sf_exported_auto_activate_callc10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern void
  sf_exported_auto_increment_call_counterc10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern void sf_exported_auto_reset_call_counterc10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern void sf_exported_auto_deactivate_callc10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern void sf_exported_auto_initc10_DemoGazeFollowWaveIdleRand(SimStruct *c10_S);
extern const mxArray *sf_exported_auto_getSimstatec10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern const mxArray *sf_internal_get_sim_state_c10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);
extern void sf_exported_auto_setSimstatec10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S, const mxArray *c10_in);
extern void sf_internal_set_sim_state_c10_DemoGazeFollowWaveIdleRand(SimStruct
  *c10_S, const mxArray *c10_in);
extern void
  sf_exported_auto_check_state_inconsistency_c10_DemoGazeFollowWaveIdleRand
  (SimStruct *c10_S);

/* Function Definitions */
extern void sf_c10_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray *plhs[]);
extern void c10_DemoGazeFollowWaveIdleRand_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
