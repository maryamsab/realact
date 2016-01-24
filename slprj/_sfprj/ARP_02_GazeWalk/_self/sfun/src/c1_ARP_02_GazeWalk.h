#ifndef __c1_ARP_02_GazeWalk_h__
#define __c1_ARP_02_GazeWalk_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_ARP_02_GazeWalkInstanceStruct
#define typedef_SFc1_ARP_02_GazeWalkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_stateBoredGaze;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ARP_02_GazeWalk;
  uint8_T c1_is_c1_ARP_02_GazeWalk;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state;
  boolean_T c1_state_not_empty;
  uint32_T c1_b_state[2];
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[625];
  boolean_T c1_c_state_not_empty;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_ARP_02_GazeWalkInstanceStruct;

#endif                                 /*typedef_SFc1_ARP_02_GazeWalkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_ARP_02_GazeWalk_get_eml_resolved_functions_info(void);
extern boolean_T sf_exported_auto_isStablec1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_duringc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_enterc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_exitc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_gatewayc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_enablec1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_disablec1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_stepBuffersc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_initBuffersc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_activate_callc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_increment_call_counterc1_ARP_02_GazeWalk(SimStruct *
  c1_S);
extern void sf_exported_auto_reset_call_counterc1_ARP_02_GazeWalk(SimStruct
  *c1_S);
extern void sf_exported_auto_deactivate_callc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern void sf_exported_auto_initc1_ARP_02_GazeWalk(SimStruct *c1_S);
extern const mxArray *sf_exported_auto_getSimstatec1_ARP_02_GazeWalk(SimStruct
  *c1_S);
extern const mxArray *sf_internal_get_sim_state_c1_ARP_02_GazeWalk(SimStruct
  *c1_S);
extern void sf_exported_auto_setSimstatec1_ARP_02_GazeWalk(SimStruct *c1_S,
  const mxArray *c1_in);
extern void sf_internal_set_sim_state_c1_ARP_02_GazeWalk(SimStruct *c1_S, const
  mxArray *c1_in);
extern void sf_exported_auto_check_state_inconsistency_c1_ARP_02_GazeWalk
  (SimStruct *c1_S);

/* Function Definitions */
extern void sf_c1_ARP_02_GazeWalk_get_check_sum(mxArray *plhs[]);
extern void c1_ARP_02_GazeWalk_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
