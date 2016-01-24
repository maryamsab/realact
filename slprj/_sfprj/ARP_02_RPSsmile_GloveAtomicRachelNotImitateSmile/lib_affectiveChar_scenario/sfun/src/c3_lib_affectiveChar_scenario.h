#ifndef __c3_lib_affectiveChar_scenario_h__
#define __c3_lib_affectiveChar_scenario_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_lib_affectiveChar_scenarioInstanceStruct
#define typedef_SFc3_lib_affectiveChar_scenarioInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_stateStart;
  uint8_T c3_tp_stateReady;
  uint8_T c3_tp_gameOver;
  uint8_T c3_tp_statePoseReady;
  uint8_T c3_tp_stateHeadNeutral2;
  uint8_T c3_tp_stateIfSmile;
  uint8_T c3_tp_stateGo;
  uint8_T c3_tp_stateSmile;
  uint8_T c3_tp_statePoseSmile;
  uint8_T c3_tp_stateNeckBack;
  uint8_T c3_tp_stateRandomHand;
  uint8_T c3_tp_stateBrowUp;
  uint8_T c3_tp_stateBoredPose1;
  uint8_T c3_tp_statePoseFingersCLose;
  uint8_T c3_tp_statePosePaper;
  uint8_T c3_tp_statePoseRock;
  uint8_T c3_tp_statePoseScissors;
  uint8_T c3_tp_stateReadUserHand;
  uint8_T c3_tp_stateShowHands;
  uint8_T c3_tp_statePoseReturnFinger;
  uint8_T c3_tp_stateCompare;
  uint8_T c3_tp_stateUserWin;
  uint8_T c3_tp_stateBradWin;
  uint8_T c3_tp_stateNoWin;
  uint8_T c3_tp_stateRandom1;
  uint8_T c3_tp_stateHeadNeutral1;
  uint8_T c3_tp_statePoseSmileWin;
  uint8_T c3_tp_stateShowResult;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_lib_affectiveChar_scenario;
  uint8_T c3_is_c3_lib_affectiveChar_scenario;
  uint32_T c3_method;
  boolean_T c3_method_not_empty;
  uint32_T c3_state;
  boolean_T c3_state_not_empty;
  uint32_T c3_b_state[2];
  boolean_T c3_b_state_not_empty;
  uint32_T c3_c_state[625];
  boolean_T c3_c_state_not_empty;
  uint8_T c3_temporalCounter_i1;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T *c3_BOREDOM_THRESHOLD_address;
  int32_T c3_BOREDOM_THRESHOLD_index;
  real_T *c3_avert_address;
  int32_T c3_avert_index;
  real_T *c3_bHand_address;
  int32_T c3_bHand_index;
  real_T *c3_boredom_address;
  int32_T c3_boredom_index;
  real_T *c3_diff_address;
  int32_T c3_diff_index;
  real_T *c3_isPosing_address;
  int32_T c3_isPosing_index;
  real_T *c3_isSmiling_address;
  int32_T c3_isSmiling_index;
  real_T *c3_p_address;
  int32_T c3_p_index;
  real_T *c3_r_address;
  int32_T c3_r_index;
  real_T *c3_randAvertGazeChance_address;
  int32_T c3_randAvertGazeChance_index;
  real_T *c3_randPoseChance_address;
  int32_T c3_randPoseChance_index;
  real_T *c3_randSmile_address;
  int32_T c3_randSmile_index;
  real_T *c3_s_address;
  int32_T c3_s_index;
  real_T *c3_temp_address;
  int32_T c3_temp_index;
  real_T *c3_uHand_address;
  int32_T c3_uHand_index;
  real_T *c3_wristRotate_address;
  int32_T c3_wristRotate_index;
} SFc3_lib_affectiveChar_scenarioInstanceStruct;

#endif                                 /*typedef_SFc3_lib_affectiveChar_scenarioInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_lib_affectiveChar_scenario_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c3_lib_affectiveChar_scenario_secs
  (SimStruct *c3_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c3_lib_affectiveChar_scenario_secs
  (SimStruct *c3_S);
extern void
  sf_exported_auto_resetTemporalCounter_c3_lib_affectiveChar_scenario_secs
  (SimStruct *c3_S);
extern void sf_exported_auto_deactivate_c3_lib_affectiveChar_scenario_secs
  (SimStruct *c3_S);
extern boolean_T sf_exported_auto_isStablec3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_auto_duringc3_lib_affectiveChar_scenario(SimStruct *c3_S);
extern void sf_exported_auto_enterc3_lib_affectiveChar_scenario(SimStruct *c3_S);
extern void sf_exported_auto_exitc3_lib_affectiveChar_scenario(SimStruct *c3_S);
extern void sf_exported_auto_gatewayc3_lib_affectiveChar_scenario(SimStruct
  *c3_S);
extern void sf_exported_auto_enablec3_lib_affectiveChar_scenario(SimStruct *c3_S);
extern void sf_exported_auto_disablec3_lib_affectiveChar_scenario(SimStruct
  *c3_S);
extern void sf_exported_auto_stepBuffersc3_lib_affectiveChar_scenario(SimStruct *
  c3_S);
extern void sf_exported_auto_initBuffersc3_lib_affectiveChar_scenario(SimStruct *
  c3_S);
extern void sf_exported_auto_activate_callc3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_auto_increment_call_counterc3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_auto_reset_call_counterc3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_auto_deactivate_callc3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_auto_initc3_lib_affectiveChar_scenario(SimStruct *c3_S);
extern const mxArray *sf_exported_auto_getSimstatec3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern const mxArray *sf_internal_get_sim_state_c3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_auto_setSimstatec3_lib_affectiveChar_scenario(SimStruct *
  c3_S, const mxArray *c3_in);
extern void sf_internal_set_sim_state_c3_lib_affectiveChar_scenario(SimStruct
  *c3_S, const mxArray *c3_in);
extern void
  sf_exported_auto_check_state_inconsistency_c3_lib_affectiveChar_scenario
  (SimStruct *c3_S);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_handPoseSBRachelTable
  (SimStruct *c3_S, real_T c3_sbmID, real_T c3_poseSBM[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_idlePoseRachelTable
  (SimStruct *c3_S, real_T c3_bmlID, real_T c3_poseBML[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_initialPoseTable
  (SimStruct *c3_S, real_T c3_bmlID, real_T c3_poseBML[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_paperPoseRachelTable
  (SimStruct *c3_S, real_T c3_bmlID, real_T c3_poseBML[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_rockPoseTable
  (SimStruct *c3_S, real_T c3_bmlID, real_T c3_poseBML[256]);
extern void
  sf_exported_user_c3_lib_affectiveChar_scenario_scissorsPoseRachelTable
  (SimStruct *c3_S, real_T c3_bmlID, real_T c3_poseBML[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_sendBML(SimStruct
  *c3_S, real_T c3_arg[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_sendSBM(SimStruct
  *c3_S, real_T c3_arg[256]);
extern void sf_exported_user_c3_lib_affectiveChar_scenario_successTable
  (SimStruct *c3_S, real_T c3_bmlID, real_T c3_poseBML[256]);

/* Function Definitions */
extern void sf_c3_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[]);
extern void c3_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
