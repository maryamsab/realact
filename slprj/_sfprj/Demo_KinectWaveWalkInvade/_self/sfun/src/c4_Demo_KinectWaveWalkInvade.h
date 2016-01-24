#ifndef __c4_Demo_KinectWaveWalkInvade_h__
#define __c4_Demo_KinectWaveWalkInvade_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_Demo_KinectWaveWalkInvadeInstanceStruct
#define typedef_SFc4_Demo_KinectWaveWalkInvadeInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_idlePoseGenerate;
  uint8_T c4_tp_stateInit;
  uint8_T c4_tp_leanChange;
  uint8_T c4_tp_stateRandomPose;
  uint8_T c4_tp_stateExtrovertPoseChance;
  uint8_T c4_tp_poseCategoryChance1;
  uint8_T c4_tp_poseCategoryChance;
  uint8_T c4_tp_selfAdaptorFast;
  uint8_T c4_tp_weightshiftFast;
  uint8_T c4_tp_weightshiftSlow;
  uint8_T c4_tp_selfAdaptorSlow;
  uint8_T c4_tp_weightshiftNormal;
  uint8_T c4_tp_selfAdaptorNormal;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_Demo_KinectWaveWalkInvade;
  uint8_T c4_is_idlePoseGenerate;
  uint8_T c4_is_active_idlePoseGenerate;
  real_T c4_BMLM[1000];
  real_T c4_newBmlsL[5000];
  real_T c4_n[1000];
  real_T c4_randPR;
  real_T c4_pPoseChance;
  real_T c4_poseFreq;
  real_T c4_leanPose;
  real_T c4_pPoseChanceP;
  real_T c4_poseFreqP;
  real_T c4_pCatChance;
  real_T c4_catChance;
  real_T c4_BMLl[1000];
  real_T c4_newBmlsM[5000];
  real_T c4_pChangeFlag;
  uint32_T c4_method;
  boolean_T c4_method_not_empty;
  uint32_T c4_state;
  boolean_T c4_state_not_empty;
  uint32_T c4_b_state[2];
  boolean_T c4_b_state_not_empty;
  uint32_T c4_c_state[625];
  boolean_T c4_c_state_not_empty;
  uint32_T c4_temporalCounter_i1;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  real_T (*c4_BML_address)[1000];
  int32_T c4_BML_index;
  real_T *c4_BORED_address;
  int32_T c4_BORED_index;
  real_T *c4_BOREDOM_THRESHOLD_address;
  int32_T c4_BOREDOM_THRESHOLD_index;
  real_T *c4_CONTEMPT_address;
  int32_T c4_CONTEMPT_index;
  real_T *c4_EXCITE_address;
  int32_T c4_EXCITE_index;
  real_T *c4_FEAR_address;
  int32_T c4_FEAR_index;
  real_T *c4_FRUST_address;
  int32_T c4_FRUST_index;
  real_T *c4_HAPPY_address;
  int32_T c4_HAPPY_index;
  real_T *c4_IDLE_address;
  int32_T c4_IDLE_index;
  real_T *c4_P_address;
  int32_T c4_P_index;
  real_T *c4_SAD_address;
  int32_T c4_SAD_index;
  real_T *c4_STATE_BEFORE_address;
  int32_T c4_STATE_BEFORE_index;
  real_T *c4_STATE_GO_address;
  int32_T c4_STATE_GO_index;
  real_T *c4_STATE_OVER_address;
  int32_T c4_STATE_OVER_index;
  real_T *c4_STATE_READY_address;
  int32_T c4_STATE_READY_index;
  real_T (*c4_bmlsL_address)[5000];
  int32_T c4_bmlsL_index;
  real_T (*c4_bmlsM_address)[5000];
  int32_T c4_bmlsM_index;
  real_T *c4_bodyBusyFlag_address;
  int32_T c4_bodyBusyFlag_index;
  real_T *c4_boredom_address;
  int32_T c4_boredom_index;
  real_T *c4_faceBusyFlag_address;
  int32_T c4_faceBusyFlag_index;
  real_T *c4_fileID_address;
  int32_T c4_fileID_index;
  real_T *c4_interest_address;
  int32_T c4_interest_index;
  real_T *c4_pose_chance_factor_address;
  int32_T c4_pose_chance_factor_index;
  real_T *c4_pose_change_flag_address;
  int32_T c4_pose_change_flag_index;
  real_T *c4_pose_frequency_factor_address;
  int32_T c4_pose_frequency_factor_index;
  real_T *c4_pose_lean_address;
  int32_T c4_pose_lean_index;
  real_T *c4_pose_lean_flag_address;
  int32_T c4_pose_lean_flag_index;
  real_T *c4_pose_selfAdaptor_chance_factor_address;
  int32_T c4_pose_selfAdaptor_chance_factor_index;
  real_T *c4_pose_speed_address;
  int32_T c4_pose_speed_index;
  real_T *c4_randPoseChance_address;
  int32_T c4_randPoseChance_index;
  real_T *c4_randSlowPose_address;
  int32_T c4_randSlowPose_index;
} SFc4_Demo_KinectWaveWalkInvadeInstanceStruct;

#endif                                 /*typedef_SFc4_Demo_KinectWaveWalkInvadeInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_Demo_KinectWaveWalkInvade_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c4_Demo_KinectWaveWalkInvade_secs
  (SimStruct *c4_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c4_Demo_KinectWaveWalkInvade_secs
  (SimStruct *c4_S);
extern void
  sf_exported_auto_resetTemporalCounter_c4_Demo_KinectWaveWalkInvade_secs
  (SimStruct *c4_S);
extern void sf_exported_auto_deactivate_c4_Demo_KinectWaveWalkInvade_secs
  (SimStruct *c4_S);
extern boolean_T sf_exported_auto_isStablec4_Demo_KinectWaveWalkInvade(SimStruct
  *c4_S);
extern void sf_exported_auto_duringc4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern void sf_exported_auto_enterc4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern void sf_exported_auto_exitc4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern void sf_exported_auto_gatewayc4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern void sf_exported_auto_enablec4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern void sf_exported_auto_disablec4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern void sf_exported_auto_stepBuffersc4_Demo_KinectWaveWalkInvade(SimStruct
  *c4_S);
extern void sf_exported_auto_initBuffersc4_Demo_KinectWaveWalkInvade(SimStruct
  *c4_S);
extern void sf_exported_auto_activate_callc4_Demo_KinectWaveWalkInvade(SimStruct
  *c4_S);
extern void sf_exported_auto_increment_call_counterc4_Demo_KinectWaveWalkInvade
  (SimStruct *c4_S);
extern void sf_exported_auto_reset_call_counterc4_Demo_KinectWaveWalkInvade
  (SimStruct *c4_S);
extern void sf_exported_auto_deactivate_callc4_Demo_KinectWaveWalkInvade
  (SimStruct *c4_S);
extern void sf_exported_auto_initc4_Demo_KinectWaveWalkInvade(SimStruct *c4_S);
extern const mxArray *sf_exported_auto_getSimstatec4_Demo_KinectWaveWalkInvade
  (SimStruct *c4_S);
extern const mxArray *sf_internal_get_sim_state_c4_Demo_KinectWaveWalkInvade
  (SimStruct *c4_S);
extern void sf_exported_auto_setSimstatec4_Demo_KinectWaveWalkInvade(SimStruct
  *c4_S, const mxArray *c4_in);
extern void sf_internal_set_sim_state_c4_Demo_KinectWaveWalkInvade(SimStruct
  *c4_S, const mxArray *c4_in);
extern void
  sf_exported_auto_check_state_inconsistency_c4_Demo_KinectWaveWalkInvade
  (SimStruct *c4_S);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_idlePoseBradOrigTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[1000]);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_insertQueue(SimStruct *
  c4_S, real_T c4_bmls[5000], real_T c4_myBML[1000], real_T c4_newBmls[5000]);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_insertQueueLow
  (SimStruct *c4_S, real_T c4_bmls[5000], real_T c4_myBML[1000], real_T
   c4_newBmls[5000]);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_selfAdaptorTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[1000]);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_setAffectParams
  (SimStruct *c4_S, real_T c4_v, real_T c4_ar, real_T c4_p, real_T *c4_pfreq,
   real_T *c4_pChance, real_T *c4_pCat, real_T *c4_pLean);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_setPersonalityParams
  (SimStruct *c4_S, real_T c4_p, real_T *c4_pf, real_T *c4_pL, real_T *c4_pC,
   real_T *c4_pCat);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_setVAParams(SimStruct *
  c4_S, real_T c4_v, real_T c4_ar, real_T c4_pfreqP, real_T c4_pChanceP, real_T
  c4_pCatP, real_T *c4_pfreq, real_T *c4_pChance, real_T *c4_pCat);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_walkInvadingTable
  (SimStruct *c4_S, real_T c4_bmlID, creal_T *c4_p, real_T c4_poseBML[1000]);
extern void sf_exported_user_c4_Demo_KinectWaveWalkInvade_weightshiftTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[1000]);

/* Function Definitions */
extern void sf_c4_Demo_KinectWaveWalkInvade_get_check_sum(mxArray *plhs[]);
extern void c4_Demo_KinectWaveWalkInvade_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
