#ifndef __c8_lib_affectiveChar_scenario_h__
#define __c8_lib_affectiveChar_scenario_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_lib_affectiveChar_scenarioInstanceStruct
#define typedef_SFc8_lib_affectiveChar_scenarioInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  uint8_T c8_tp_stateStart;
  uint8_T c8_tp_stateReady;
  uint8_T c8_tp_gameOver;
  uint8_T c8_tp_statePoseReady;
  uint8_T c8_tp_stateHeadNeutral2;
  uint8_T c8_tp_stateIfSmile;
  uint8_T c8_tp_stateGo;
  uint8_T c8_tp_stateSmile;
  uint8_T c8_tp_statePoseSmile;
  uint8_T c8_tp_stateLeanBack;
  uint8_T c8_tp_stateRandomHand;
  uint8_T c8_tp_stateBrowUp;
  uint8_T c8_tp_stateBoredPose1;
  uint8_T c8_tp_statePoseFingersCLose;
  uint8_T c8_tp_statePosePaper;
  uint8_T c8_tp_statePoseRock;
  uint8_T c8_tp_statePoseScissors;
  uint8_T c8_tp_stateReadUserHand;
  uint8_T c8_tp_stateShowHands;
  uint8_T c8_tp_statePoseReturnFinger;
  uint8_T c8_tp_stateCompare;
  uint8_T c8_tp_stateUserWin;
  uint8_T c8_tp_stateBradWin;
  uint8_T c8_tp_stateNoWin;
  uint8_T c8_tp_stateRandom1;
  uint8_T c8_tp_statePoseSmileWin;
  uint8_T c8_tp_stateShowResult;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_lib_affectiveChar_scenario;
  uint8_T c8_is_c8_lib_affectiveChar_scenario;
  uint32_T c8_method;
  boolean_T c8_method_not_empty;
  uint32_T c8_state;
  boolean_T c8_state_not_empty;
  uint32_T c8_b_state[2];
  boolean_T c8_b_state_not_empty;
  uint32_T c8_c_state[625];
  boolean_T c8_c_state_not_empty;
  uint8_T c8_temporalCounter_i1;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
  real_T *c8_BOREDOM_THRESHOLD_address;
  int32_T c8_BOREDOM_THRESHOLD_index;
  real_T *c8_avert_address;
  int32_T c8_avert_index;
  real_T *c8_bHand_address;
  int32_T c8_bHand_index;
  real_T *c8_boredom_address;
  int32_T c8_boredom_index;
  real_T *c8_diff_address;
  int32_T c8_diff_index;
  real_T *c8_isPosing_address;
  int32_T c8_isPosing_index;
  real_T *c8_isSmiling_address;
  int32_T c8_isSmiling_index;
  real_T *c8_p_address;
  int32_T c8_p_index;
  real_T *c8_r_address;
  int32_T c8_r_index;
  real_T *c8_randAvertGazeChance_address;
  int32_T c8_randAvertGazeChance_index;
  real_T *c8_randPoseChance_address;
  int32_T c8_randPoseChance_index;
  real_T *c8_randSmile_address;
  int32_T c8_randSmile_index;
  real_T *c8_s_address;
  int32_T c8_s_index;
  real_T *c8_smileN_address;
  int32_T c8_smileN_index;
  real_T *c8_temp_address;
  int32_T c8_temp_index;
  real_T *c8_uHand_address;
  int32_T c8_uHand_index;
} SFc8_lib_affectiveChar_scenarioInstanceStruct;

#endif                                 /*typedef_SFc8_lib_affectiveChar_scenarioInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_lib_affectiveChar_scenario_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c8_lib_affectiveChar_scenario_secs
  (SimStruct *c8_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c8_lib_affectiveChar_scenario_secs
  (SimStruct *c8_S);
extern void
  sf_exported_auto_resetTemporalCounter_c8_lib_affectiveChar_scenario_secs
  (SimStruct *c8_S);
extern void sf_exported_auto_deactivate_c8_lib_affectiveChar_scenario_secs
  (SimStruct *c8_S);
extern boolean_T sf_exported_auto_isStablec8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_auto_duringc8_lib_affectiveChar_scenario(SimStruct *c8_S);
extern void sf_exported_auto_enterc8_lib_affectiveChar_scenario(SimStruct *c8_S);
extern void sf_exported_auto_exitc8_lib_affectiveChar_scenario(SimStruct *c8_S);
extern void sf_exported_auto_gatewayc8_lib_affectiveChar_scenario(SimStruct
  *c8_S);
extern void sf_exported_auto_enablec8_lib_affectiveChar_scenario(SimStruct *c8_S);
extern void sf_exported_auto_disablec8_lib_affectiveChar_scenario(SimStruct
  *c8_S);
extern void sf_exported_auto_stepBuffersc8_lib_affectiveChar_scenario(SimStruct *
  c8_S);
extern void sf_exported_auto_initBuffersc8_lib_affectiveChar_scenario(SimStruct *
  c8_S);
extern void sf_exported_auto_activate_callc8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_auto_increment_call_counterc8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_auto_reset_call_counterc8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_auto_deactivate_callc8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_auto_initc8_lib_affectiveChar_scenario(SimStruct *c8_S);
extern const mxArray *sf_exported_auto_getSimstatec8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern const mxArray *sf_internal_get_sim_state_c8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_auto_setSimstatec8_lib_affectiveChar_scenario(SimStruct *
  c8_S, const mxArray *c8_in);
extern void sf_internal_set_sim_state_c8_lib_affectiveChar_scenario(SimStruct
  *c8_S, const mxArray *c8_in);
extern void
  sf_exported_auto_check_state_inconsistency_c8_lib_affectiveChar_scenario
  (SimStruct *c8_S);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_handPoseSBTable
  (SimStruct *c8_S, real_T c8_sbmID, real_T c8_poseSBM[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_idlePoseBradTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_initialPoseTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_paperPoseBradTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_rockPoseTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_scissorsPoseBradTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_sendBML(SimStruct
  *c8_S, real_T c8_arg[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_sendSBM(SimStruct
  *c8_S, real_T c8_arg[256]);
extern void sf_exported_user_c8_lib_affectiveChar_scenario_successTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);

/* Function Definitions */
extern void sf_c8_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[]);
extern void c8_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
