#ifndef __c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_h__
#define __c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
#define typedef_SFc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  uint8_T c10_tp_stateInit;
  uint8_T c10_tp_gazeMiddle;
  uint8_T c10_tp_stateIdleL;
  uint8_T c10_tp_stateGazeLeft;
  uint8_T c10_tp_stateIdleR;
  uint8_T c10_tp_stateIdleM;
  uint8_T c10_tp_gazeRight;
  boolean_T c10_isStable;
  uint8_T c10_is_active_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSm;
  uint8_T c10_is_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  uint8_T c10_temporalCounter_i1;
  uint8_T c10_doSetSimStateSideEffects;
  const mxArray *c10_setSimStateSideEffectsInfo;
  real_T *c10_STATE_BEFORE_address;
  int32_T c10_STATE_BEFORE_index;
  real_T *c10_STATE_OVER_address;
  int32_T c10_STATE_OVER_index;
  real_T *c10_STATE_READY_address;
  int32_T c10_STATE_READY_index;
  real_T *c10_isPosing_address;
  int32_T c10_isPosing_index;
} SFc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  (void);
extern void
  sf_exported_auto_activate_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c10_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c10_S);
extern void
  sf_exported_auto_resetTemporalCounter_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c10_S);
extern void
  sf_exported_auto_deactivate_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c10_S);
extern boolean_T
  sf_exported_auto_isStablec10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_duringc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_enterc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_exitc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_gatewayc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_enablec10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_disablec10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_stepBuffersc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_initBuffersc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_activate_callc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_increment_call_counterc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_reset_call_counterc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_deactivate_callc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_initc10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern const mxArray
  *sf_exported_auto_getSimstatec10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern const mxArray
  *sf_internal_get_sim_state_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_auto_setSimstatec10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S, const mxArray *c10_in);
extern void
  sf_internal_set_sim_state_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S, const mxArray *c10_in);
extern void
  sf_exported_auto_check_state_inconsistency_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c10_S);
extern void
  sf_exported_user_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_gazeFollowUserMove
  (SimStruct *c10_S, real_T c10_bmlID, real_T c10_gazeBML[256]);
extern void
  sf_exported_user_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_sendBML
  (SimStruct *c10_S, real_T c10_arg[256]);

/* Function Definitions */
extern void
  sf_c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_check_sum(mxArray
  *plhs[]);
extern void
  c10_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
