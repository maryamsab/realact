#ifndef __c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_h__
#define __c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct
#define typedef_SFc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_stateGazeSoftEye;
  uint8_T c9_tp_stateInitial;
  uint8_T c9_tp_stateHeadNeutral;
  uint8_T c9_tp_stateAvertGaze;
  uint8_T c9_tp_stateAvertHead;
  uint8_T c9_tp_stateGazingGUI;
  uint8_T c9_tp_stateGazingUserHand;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile;
  uint8_T c9_is_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile;
  uint32_T c9_method;
  boolean_T c9_method_not_empty;
  uint32_T c9_state;
  boolean_T c9_state_not_empty;
  uint32_T c9_b_state[2];
  boolean_T c9_b_state_not_empty;
  uint32_T c9_c_state[625];
  boolean_T c9_c_state_not_empty;
  uint32_T c9_temporalCounter_i1;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  real_T *c9_BOREDOM_THRESHOLD_address;
  int32_T c9_BOREDOM_THRESHOLD_index;
  real_T *c9_GAZE_GUI_address;
  int32_T c9_GAZE_GUI_index;
  real_T *c9_GAZE_SHOFTEYE_address;
  int32_T c9_GAZE_SHOFTEYE_index;
  real_T *c9_GAZE_USER_HAND_address;
  int32_T c9_GAZE_USER_HAND_index;
  real_T *c9_boredom_address;
  int32_T c9_boredom_index;
  real_T *c9_gazing_address;
  int32_T c9_gazing_index;
  real_T *c9_interest_address;
  int32_T c9_interest_index;
  real_T *c9_isPosing_address;
  int32_T c9_isPosing_index;
  real_T *c9_randAvertGazeChance_address;
  int32_T c9_randAvertGazeChance_index;
  real_T *c9_randGazeDur_address;
  int32_T c9_randGazeDur_index;
  real_T *c9_randPoseChance_address;
  int32_T c9_randPoseChance_index;
} SFc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_activate_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_resetTemporalCounter_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c9_S);
extern void
  sf_exported_auto_deactivate_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_secs
  (SimStruct *c9_S);
extern boolean_T
  sf_exported_auto_isStablec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_duringc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_enterc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_exitc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_gatewayc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_enablec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_disablec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_stepBuffersc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_initBuffersc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_activate_callc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_increment_call_counterc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_reset_call_counterc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_deactivate_callc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_initc9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern const mxArray
  *sf_exported_auto_getSimstatec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern const mxArray
  *sf_internal_get_sim_state_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_auto_setSimstatec9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S, const mxArray *c9_in);
extern void
  sf_internal_set_sim_state_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S, const mxArray *c9_in);
extern void
  sf_exported_auto_check_state_inconsistency_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile
  (SimStruct *c9_S);
extern void
  sf_exported_user_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_idleGazeInterestedTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256]);
extern void
  sf_exported_user_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_idleGazeTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256]);
extern void
  sf_exported_user_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_sendBML
  (SimStruct *c9_S, real_T c9_arg[256]);

/* Function Definitions */
extern void sf_c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void c9_ARP_02_RPSsmile_GloveAtomicRachelImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
