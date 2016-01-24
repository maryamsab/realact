#ifndef __c3_ARP_02_GazeWalk_h__
#define __c3_ARP_02_GazeWalk_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ARP_02_GazeWalkInstanceStruct
#define typedef_SFc3_ARP_02_GazeWalkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_stateBoredPose1;
  uint8_T c3_tp_stateInitiate;
  uint8_T c3_tp_stateBoredGaze;
  uint8_T c3_tp_checkUser;
  uint8_T c3_tp_stateIntract;
  uint8_T c3_tp_stateIdle;
  uint8_T c3_tp_stateCheckUser;
  uint8_T c3_tp_stateCoping;
  uint8_T c3_tp_stateInvaded;
  uint8_T c3_tp_stateBoredPose;
  uint8_T c3_tp_stateWalkAway;
  uint8_T c3_tp_stateCheckUser2;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_ARP_02_GazeWalk;
  uint8_T c3_is_c3_ARP_02_GazeWalk;
  real_T c3_round_count;
  real_T c3_arrBML[256];
  real_T c3_bored;
  real_T c3_copingT;
  real_T c3_COPINGT;
  real_T c3_BOREDOMT;
  real_T c3_coping;
  real_T c3_PERSONALSPACE;
  real_T c3_INTERACTT;
  SimStruct *c3_subchartSimstruct;
  uint32_T c3_method;
  boolean_T c3_method_not_empty;
  uint32_T c3_state;
  boolean_T c3_state_not_empty;
  uint32_T c3_b_state[2];
  boolean_T c3_b_state_not_empty;
  uint32_T c3_c_state[625];
  boolean_T c3_c_state_not_empty;
  uint8_T c3_temporalCounter_i1;
  uint32_T c3_presentTicks;
  uint32_T c3_elapsedTicks;
  uint32_T c3_previousTicks;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_ARP_02_GazeWalkInstanceStruct;

#endif                                 /*typedef_SFc3_ARP_02_GazeWalkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_ARP_02_GazeWalk_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_gatewayc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_activate_callc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_deactivate_callc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_stepBuffersc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_enterc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_exitc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_enablec1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_disablec1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_check_state_inconsistency_c1_ARP_02_GazeWalk
  (SimStruct *c3_S);
extern const mxArray *sf_exported_auto_getSimstatec1_ARP_02_GazeWalk(SimStruct
  *c3_S);
extern void sf_exported_auto_setSimstatec1_ARP_02_GazeWalk(SimStruct *c3_S,
  const mxArray *c3_input);
extern void sf_exported_auto_initc1_ARP_02_GazeWalk(SimStruct *c3_S);
extern void sf_exported_auto_initBuffersc1_ARP_02_GazeWalk(SimStruct *c3_S);

/* Function Definitions */
extern void sf_c3_ARP_02_GazeWalk_get_check_sum(mxArray *plhs[]);
extern void c3_ARP_02_GazeWalk_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
