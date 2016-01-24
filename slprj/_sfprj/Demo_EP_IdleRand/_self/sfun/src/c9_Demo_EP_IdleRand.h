#ifndef __c9_Demo_EP_IdleRand_h__
#define __c9_Demo_EP_IdleRand_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Demo_EP_IdleRandInstanceStruct
#define typedef_SFc9_Demo_EP_IdleRandInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_stateGazeIde;
  uint8_T c9_tp_stateInit;
  uint8_T c9_tp_stateRandGen;
  uint8_T c9_tp_stateCheckMutCont;
  uint8_T c9_tp_mut;
  uint8_T c9_tp_stateAvertGaze;
  uint8_T c9_tp_stateCheckAvertCont;
  uint8_T c9_tp_stateMutualGazeE;
  uint8_T c9_tp_stateAvertHeadExtrovert;
  uint8_T c9_tp_eHeadNeutral;
  uint8_T c9_tp_stateAvertHeadIntrovert;
  uint8_T c9_tp_iHeadNeutral;
  uint8_T c9_tp_stateGazingGUI;
  uint8_T c9_tp_stateGazingUserHand;
  uint8_T c9_tp_stateGazeWin;
  uint8_T c9_b_tp_stateInit;
  uint8_T c9_tp_stateWinSmile;
  uint8_T c9_tp_stateNeckBack;
  uint8_T c9_tp_stateBrowUp;
  uint8_T c9_tp_stateGazeSoft;
  uint8_T c9_c_tp_stateInit;
  uint8_T c9_tp_stateGazeSoftEye;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_Demo_EP_IdleRand;
  uint8_T c9_is_stateGazeIde;
  uint8_T c9_is_active_stateGazeIde;
  uint8_T c9_is_stateGazeWin;
  uint8_T c9_is_active_stateGazeWin;
  uint8_T c9_is_stateGazeSoft;
  uint8_T c9_is_active_stateGazeSoft;
  real_T c9_randHeadDur;
  real_T c9_randHeadDurOver;
  real_T c9_avertContChance;
  real_T c9_gazeGUIChance;
  real_T c9_mutContChance;
  real_T c9_mutContF[3];
  real_T c9_CHANCEM;
  real_T c9_avertDur;
  real_T c9_gazeDir;
  real_T c9_CHANCEA;
  real_T c9_magnitude;
  real_T c9_randHeadChance;
  real_T c9_avertContF[4];
  real_T c9_gazeUserHandChance;
  real_T c9_chanceO;
  real_T c9_BMLl[256];
  real_T c9_newBmlsL[1280];
  real_T c9_n[256];
  real_T c9_mutDur;
  real_T c9_mF;
  real_T c9_hF;
  real_T c9_aF;
  uint32_T c9_method;
  boolean_T c9_method_not_empty;
  uint32_T c9_state;
  boolean_T c9_state_not_empty;
  uint32_T c9_b_state[2];
  boolean_T c9_b_state_not_empty;
  uint32_T c9_c_state[625];
  boolean_T c9_c_state_not_empty;
  uint32_T c9_temporalCounter_i1;
  uint8_T c9_temporalCounter_i2;
  uint8_T c9_temporalCounter_i3;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T (*c9_BML_address)[256];
  int32_T c9_BML_index;
  real_T *c9_BOREDOM_THRESHOLD_address;
  int32_T c9_BOREDOM_THRESHOLD_index;
  real_T *c9_GAZE_GUI_address;
  int32_T c9_GAZE_GUI_index;
  real_T *c9_GAZE_SOFTEYE_address;
  int32_T c9_GAZE_SOFTEYE_index;
  real_T *c9_GAZE_USER_HAND_address;
  int32_T c9_GAZE_USER_HAND_index;
  real_T *c9_GAZE_WIN_address;
  int32_T c9_GAZE_WIN_index;
  real_T *c9_P_address;
  int32_T c9_P_index;
  real_T *c9_STATE_BEFORE_address;
  int32_T c9_STATE_BEFORE_index;
  real_T *c9_STATE_GO_address;
  int32_T c9_STATE_GO_index;
  real_T *c9_STATE_OVER_address;
  int32_T c9_STATE_OVER_index;
  real_T *c9_STATE_READY_address;
  int32_T c9_STATE_READY_index;
  real_T *c9_avert_address;
  int32_T c9_avert_index;
  real_T *c9_avertH_address;
  int32_T c9_avertH_index;
  real_T (*c9_bmlsL_address)[1280];
  int32_T c9_bmlsL_index;
  real_T *c9_boredom_address;
  int32_T c9_boredom_index;
  real_T *c9_changeFlag_address;
  int32_T c9_changeFlag_index;
  real_T *c9_fileID_address;
  int32_T c9_fileID_index;
  real_T *c9_gazing_address;
  int32_T c9_gazing_index;
  real_T *c9_interest_address;
  int32_T c9_interest_index;
  real_T *c9_pr_address;
  int32_T c9_pr_index;
  real_T *c9_randAvertGazeChance_address;
  int32_T c9_randAvertGazeChance_index;
  real_T *c9_randGazeDur_address;
  int32_T c9_randGazeDur_index;
  real_T *c9_randPoseChance_address;
  int32_T c9_randPoseChance_index;
} SFc9_Demo_EP_IdleRandInstanceStruct;

#endif                                 /*typedef_SFc9_Demo_EP_IdleRandInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Demo_EP_IdleRand_get_eml_resolved_functions_info
  (void);
extern void sf_exported_auto_activate_c9_Demo_EP_IdleRand_secs(SimStruct *c9_S);
extern void sf_exported_auto_incrementTemporalCounter_c9_Demo_EP_IdleRand_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_resetTemporalCounter_c9_Demo_EP_IdleRand_secs
  (SimStruct *c9_S);
extern void sf_exported_auto_deactivate_c9_Demo_EP_IdleRand_secs(SimStruct *c9_S);
extern boolean_T sf_exported_auto_isStablec9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_duringc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_enterc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_exitc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_gatewayc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_enablec9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_disablec9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_stepBuffersc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_initBuffersc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_activate_callc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_increment_call_counterc9_Demo_EP_IdleRand(SimStruct
  *c9_S);
extern void sf_exported_auto_reset_call_counterc9_Demo_EP_IdleRand(SimStruct
  *c9_S);
extern void sf_exported_auto_deactivate_callc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern void sf_exported_auto_initc9_Demo_EP_IdleRand(SimStruct *c9_S);
extern const mxArray *sf_exported_auto_getSimstatec9_Demo_EP_IdleRand(SimStruct *
  c9_S);
extern const mxArray *sf_internal_get_sim_state_c9_Demo_EP_IdleRand(SimStruct
  *c9_S);
extern void sf_exported_auto_setSimstatec9_Demo_EP_IdleRand(SimStruct *c9_S,
  const mxArray *c9_in);
extern void sf_internal_set_sim_state_c9_Demo_EP_IdleRand(SimStruct *c9_S, const
  mxArray *c9_in);
extern void sf_exported_auto_check_state_inconsistency_c9_Demo_EP_IdleRand
  (SimStruct *c9_S);
extern void sf_exported_user_c9_Demo_EP_IdleRand_gazeFollowUserMove(SimStruct
  *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeFunction(SimStruct
  *c9_S, real_T c9_dir, real_T c9_mag, real_T c9_p, real_T c9_arrBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeInterestedTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeOrigFunction(SimStruct *
  c9_S, real_T c9_dir, real_T c9_mag, real_T c9_arrBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeTableExtrovert
  (SimStruct *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeTableIntrovert
  (SimStruct *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_insertQueueLow(SimStruct *c9_S,
  real_T c9_bmls[1280], real_T c9_myBML[256], real_T c9_newBmls[1280]);
extern void sf_exported_user_c9_Demo_EP_IdleRand_setPersonalityFactor(SimStruct *
  c9_S, real_T c9_p, real_T *c9_m, real_T *c9_a, real_T *c9_h);
extern void sf_exported_user_c9_Demo_EP_IdleRand_successTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_poseBML[256]);

/* Function Definitions */
extern void sf_c9_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[]);
extern void c9_Demo_EP_IdleRand_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
