#ifndef __c9_lib_affectiveChar_scenario_h__
#define __c9_lib_affectiveChar_scenario_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_lib_affectiveChar_scenarioInstanceStruct
#define typedef_SFc9_lib_affectiveChar_scenarioInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_stateStart;
  uint8_T c9_tp_stateReady;
  uint8_T c9_tp_gameOver;
  uint8_T c9_tp_statePoseReady;
  uint8_T c9_tp_stateHeadNeutral2;
  uint8_T c9_tp_stateGo;
  uint8_T c9_tp_stateSmile;
  uint8_T c9_tp_stateNeckBack;
  uint8_T c9_tp_stateRandomHand;
  uint8_T c9_tp_stateBrowUp;
  uint8_T c9_tp_stateBoredPose1;
  uint8_T c9_tp_statePoseFingersCLose;
  uint8_T c9_tp_statePosePaper;
  uint8_T c9_tp_statePoseRock;
  uint8_T c9_tp_statePoseScissors;
  uint8_T c9_tp_stateReadUserHand;
  uint8_T c9_tp_stateShowHands;
  uint8_T c9_tp_statePoseReturnFinger;
  uint8_T c9_tp_stateCompare;
  uint8_T c9_tp_stateUserWin;
  uint8_T c9_tp_stateBradWin;
  uint8_T c9_tp_stateNoWin;
  uint8_T c9_tp_stateShowResult;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_lib_affectiveChar_scenario;
  uint8_T c9_is_c9_lib_affectiveChar_scenario;
  uint32_T c9_method;
  boolean_T c9_method_not_empty;
  uint32_T c9_state;
  boolean_T c9_state_not_empty;
  uint32_T c9_b_state[2];
  boolean_T c9_b_state_not_empty;
  uint32_T c9_c_state[625];
  boolean_T c9_c_state_not_empty;
  uint8_T c9_temporalCounter_i1;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T *c9_BOREDOM_THRESHOLD_address;
  int32_T c9_BOREDOM_THRESHOLD_index;
  real_T *c9_avert_address;
  int32_T c9_avert_index;
  real_T *c9_bHand_address;
  int32_T c9_bHand_index;
  real_T *c9_boredom_address;
  int32_T c9_boredom_index;
  real_T *c9_diff_address;
  int32_T c9_diff_index;
  real_T *c9_isPosing_address;
  int32_T c9_isPosing_index;
  real_T *c9_p_address;
  int32_T c9_p_index;
  real_T *c9_r_address;
  int32_T c9_r_index;
  real_T *c9_randAvertGazeChance_address;
  int32_T c9_randAvertGazeChance_index;
  real_T *c9_randPoseChance_address;
  int32_T c9_randPoseChance_index;
  real_T *c9_s_address;
  int32_T c9_s_index;
  real_T *c9_temp_address;
  int32_T c9_temp_index;
  real_T *c9_uHand_address;
  int32_T c9_uHand_index;
} SFc9_lib_affectiveChar_scenarioInstanceStruct;

#endif                                 /*typedef_SFc9_lib_affectiveChar_scenarioInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_lib_affectiveChar_scenario_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c9_lib_affectiveChar_scenario_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_lib_affectiveChar_scenario_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_lib_affectiveChar_scenario_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_c9_lib_affectiveChar_scenario_secs
  (SimStruct *c9_S);
extern boolean_T sf_exported_auto_isStablec9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_auto_duringc9_lib_affectiveChar_scenario(SimStruct *c9_S);
extern void sf_exported_auto_enterc9_lib_affectiveChar_scenario(SimStruct *c9_S);
extern void sf_exported_auto_exitc9_lib_affectiveChar_scenario(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc9_lib_affectiveChar_scenario(SimStruct
  *c9_S);
extern void sf_exported_auto_enablec9_lib_affectiveChar_scenario(SimStruct *c9_S);
extern void sf_exported_auto_disablec9_lib_affectiveChar_scenario(SimStruct
  *c9_S);
extern void sf_exported_auto_stepBuffersc9_lib_affectiveChar_scenario(SimStruct *
  c9_S);
extern void sf_exported_auto_initBuffersc9_lib_affectiveChar_scenario(SimStruct *
  c9_S);
extern void sf_exported_auto_activate_callc9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_auto_reset_call_counterc9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_callc9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_auto_initc9_lib_affectiveChar_scenario(SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern const mxArray *sf_internal_get_sim_state_c9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_auto_setSimstatec9_lib_affectiveChar_scenario(SimStruct *
  c9_S, const mxArray *c9_in);
extern void sf_internal_set_sim_state_c9_lib_affectiveChar_scenario(SimStruct
  *c9_S, const mxArray *c9_in);
extern void
  sf_exported_auto_check_state_inconsistency_c9_lib_affectiveChar_scenario
  (SimStruct *c9_S);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_handPoseSBRachelTable
  (SimStruct *c9_S, real_T c9_sbmID, real_T c9_poseSBM[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_idlePoseRachelTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_initialPoseTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_paperPoseRachelTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_rockPoseTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256]);
extern void
  sf_exported_user_c9_lib_affectiveChar_scenario_scissorsPoseRachelTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_sendBML(SimStruct
  *c9_S, real_T c9_arg[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_sendSBM(SimStruct
  *c9_S, real_T c9_arg[256]);
extern void sf_exported_user_c9_lib_affectiveChar_scenario_successTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256]);

/* Function Definitions */
extern void sf_c9_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[]);
extern void c9_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
