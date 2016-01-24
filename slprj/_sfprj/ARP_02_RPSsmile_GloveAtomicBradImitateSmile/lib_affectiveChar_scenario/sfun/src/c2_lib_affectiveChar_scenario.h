#ifndef __c2_lib_affectiveChar_scenario_h__
#define __c2_lib_affectiveChar_scenario_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_lib_affectiveChar_scenarioInstanceStruct
#define typedef_SFc2_lib_affectiveChar_scenarioInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_stateStart;
  uint8_T c2_tp_stateReady;
  uint8_T c2_tp_gameOver;
  uint8_T c2_tp_statePoseReady;
  uint8_T c2_tp_stateHeadNeutral2;
  uint8_T c2_tp_stateGo;
  uint8_T c2_tp_stateWinSmile;
  uint8_T c2_tp_stateNeckBack;
  uint8_T c2_tp_stateRandomHand;
  uint8_T c2_tp_stateBrowUp;
  uint8_T c2_tp_statePoseFingersCLose;
  uint8_T c2_tp_stateNotWinBored;
  uint8_T c2_tp_statePosePaper;
  uint8_T c2_tp_statePoseRock;
  uint8_T c2_tp_statePoseScissors;
  uint8_T c2_tp_stateReadUserHand;
  uint8_T c2_tp_stateShowHands;
  uint8_T c2_tp_statePoseReturnFinger;
  uint8_T c2_tp_stateCompare;
  uint8_T c2_tp_stateUserWin;
  uint8_T c2_tp_stateBradWin;
  uint8_T c2_tp_stateNoWin;
  uint8_T c2_tp_stateShowResult;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_lib_affectiveChar_scenario;
  uint8_T c2_is_c2_lib_affectiveChar_scenario;
  uint32_T c2_method;
  boolean_T c2_method_not_empty;
  uint32_T c2_state;
  boolean_T c2_state_not_empty;
  uint32_T c2_b_state[2];
  boolean_T c2_b_state_not_empty;
  uint32_T c2_c_state[625];
  boolean_T c2_c_state_not_empty;
  uint8_T c2_temporalCounter_i1;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  real_T *c2_BOREDOM_THRESHOLD_address;
  int32_T c2_BOREDOM_THRESHOLD_index;
  real_T *c2_avert_address;
  int32_T c2_avert_index;
  real_T *c2_bHand_address;
  int32_T c2_bHand_index;
  real_T *c2_boredom_address;
  int32_T c2_boredom_index;
  real_T *c2_diff_address;
  int32_T c2_diff_index;
  real_T *c2_isPosing_address;
  int32_T c2_isPosing_index;
  real_T *c2_p_address;
  int32_T c2_p_index;
  real_T *c2_r_address;
  int32_T c2_r_index;
  real_T *c2_randAvertGazeChance_address;
  int32_T c2_randAvertGazeChance_index;
  real_T *c2_randPoseChance_address;
  int32_T c2_randPoseChance_index;
  real_T *c2_randSmile_address;
  int32_T c2_randSmile_index;
  real_T *c2_s_address;
  int32_T c2_s_index;
  real_T *c2_smileN_address;
  int32_T c2_smileN_index;
  real_T *c2_temp_address;
  int32_T c2_temp_index;
  real_T *c2_uHand_address;
  int32_T c2_uHand_index;
} SFc2_lib_affectiveChar_scenarioInstanceStruct;

#endif                                 /*typedef_SFc2_lib_affectiveChar_scenarioInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_lib_affectiveChar_scenario_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c2_lib_affectiveChar_scenario_secs
  (SimStruct *c2_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c2_lib_affectiveChar_scenario_secs
  (SimStruct *c2_S);
extern void
  sf_exported_auto_resetTemporalCounter_c2_lib_affectiveChar_scenario_secs
  (SimStruct *c2_S);
extern void sf_exported_auto_deactivate_c2_lib_affectiveChar_scenario_secs
  (SimStruct *c2_S);
extern boolean_T sf_exported_auto_isStablec2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_auto_duringc2_lib_affectiveChar_scenario(SimStruct *c2_S);
extern void sf_exported_auto_enterc2_lib_affectiveChar_scenario(SimStruct *c2_S);
extern void sf_exported_auto_exitc2_lib_affectiveChar_scenario(SimStruct *c2_S);
extern void sf_exported_auto_gatewayc2_lib_affectiveChar_scenario(SimStruct
  *c2_S);
extern void sf_exported_auto_enablec2_lib_affectiveChar_scenario(SimStruct *c2_S);
extern void sf_exported_auto_disablec2_lib_affectiveChar_scenario(SimStruct
  *c2_S);
extern void sf_exported_auto_stepBuffersc2_lib_affectiveChar_scenario(SimStruct *
  c2_S);
extern void sf_exported_auto_initBuffersc2_lib_affectiveChar_scenario(SimStruct *
  c2_S);
extern void sf_exported_auto_activate_callc2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_auto_increment_call_counterc2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_auto_reset_call_counterc2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_auto_deactivate_callc2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_auto_initc2_lib_affectiveChar_scenario(SimStruct *c2_S);
extern const mxArray *sf_exported_auto_getSimstatec2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern const mxArray *sf_internal_get_sim_state_c2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_auto_setSimstatec2_lib_affectiveChar_scenario(SimStruct *
  c2_S, const mxArray *c2_in);
extern void sf_internal_set_sim_state_c2_lib_affectiveChar_scenario(SimStruct
  *c2_S, const mxArray *c2_in);
extern void
  sf_exported_auto_check_state_inconsistency_c2_lib_affectiveChar_scenario
  (SimStruct *c2_S);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_handPoseSBTable
  (SimStruct *c2_S, real_T c2_sbmID, real_T c2_poseSBM[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_idlePoseBradTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_initialPoseTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_paperPoseBradTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_rockPoseTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_scissorsPoseBradTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_sendBML(SimStruct
  *c2_S, real_T c2_arg[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_sendSBM(SimStruct
  *c2_S, real_T c2_arg[256]);
extern void sf_exported_user_c2_lib_affectiveChar_scenario_successTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256]);

/* Function Definitions */
extern void sf_c2_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[]);
extern void c2_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
