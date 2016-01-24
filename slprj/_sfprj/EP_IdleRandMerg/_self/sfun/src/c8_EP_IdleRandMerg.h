#ifndef __c8_EP_IdleRandMerg_h__
#define __c8_EP_IdleRandMerg_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_EP_IdleRandMergInstanceStruct
#define typedef_SFc8_EP_IdleRandMergInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  uint8_T c8_tp_stateInit;
  uint8_T c8_tp_wait;
  uint8_T c8_tp_gazeSurprized;
  uint8_T c8_tp_headNeuralGazeCamera;
  uint8_T c8_tp_stateWalkBack;
  uint8_T c8_tp_browUp;
  uint8_T c8_tp_checkUserCoord;
  uint8_T c8_tp_idle;
  uint8_T c8_tp_wait2;
  uint8_T c8_tp_leanFW;
  uint8_T c8_tp_walkFW;
  uint8_T c8_tp_leanNeutral;
  uint8_T c8_tp_doIt3Times;
  uint8_T c8_tp_doIt3Times1;
  uint8_T c8_tp_doIt3Times2;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_EP_IdleRandMerg;
  uint8_T c8_is_c8_EP_IdleRandMerg;
  real_T c8_neutralBuffer;
  real_T c8_closeBuffer;
  real_T c8_NEUTRAL;
  real_T c8_TOO_FAR;
  real_T c8_TOO_CLOSE;
  real_T c8_farBuffer;
  real_T c8_position;
  real_T c8_newBmlsM[5000];
  creal_T c8_BMLM[1000];
  creal_T c8_BMLL[1000];
  real_T c8_newBmlsL[5000];
  real_T c8_n[1000];
  uint8_T c8_temporalCounter_i1;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
  real_T (*c8_BML1_address)[1000];
  int32_T c8_BML1_index;
  real_T *c8_P_address;
  int32_T c8_P_index;
  real_T *c8_STATE_BEFORE_address;
  int32_T c8_STATE_BEFORE_index;
  real_T *c8_STATE_OVER_address;
  int32_T c8_STATE_OVER_index;
  real_T *c8_STATE_READY_address;
  int32_T c8_STATE_READY_index;
  real_T *c8_avert_address;
  int32_T c8_avert_index;
  real_T (*c8_bmlsL_address)[5000];
  int32_T c8_bmlsL_index;
  real_T (*c8_bmlsM_address)[5000];
  int32_T c8_bmlsM_index;
  real_T *c8_fileID_address;
  int32_T c8_fileID_index;
  real_T *c8_pr_address;
  int32_T c8_pr_index;
} SFc8_EP_IdleRandMergInstanceStruct;

#endif                                 /*typedef_SFc8_EP_IdleRandMergInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_EP_IdleRandMerg_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c8_EP_IdleRandMerg_secs(SimStruct *c8_S);
extern void sf_exported_auto_incrementTemporalCounter_c8_EP_IdleRandMerg_secs
  (SimStruct *c8_S);
extern void sf_exported_auto_resetTemporalCounter_c8_EP_IdleRandMerg_secs
  (SimStruct *c8_S);
extern void sf_exported_auto_deactivate_c8_EP_IdleRandMerg_secs(SimStruct *c8_S);
extern boolean_T sf_exported_auto_isStablec8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_duringc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_enterc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_exitc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_gatewayc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_enablec8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_disablec8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_stepBuffersc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_initBuffersc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_activate_callc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_increment_call_counterc8_EP_IdleRandMerg(SimStruct *
  c8_S);
extern void sf_exported_auto_reset_call_counterc8_EP_IdleRandMerg(SimStruct
  *c8_S);
extern void sf_exported_auto_deactivate_callc8_EP_IdleRandMerg(SimStruct *c8_S);
extern void sf_exported_auto_initc8_EP_IdleRandMerg(SimStruct *c8_S);
extern const mxArray *sf_exported_auto_getSimstatec8_EP_IdleRandMerg(SimStruct
  *c8_S);
extern const mxArray *sf_internal_get_sim_state_c8_EP_IdleRandMerg(SimStruct
  *c8_S);
extern void sf_exported_auto_setSimstatec8_EP_IdleRandMerg(SimStruct *c8_S,
  const mxArray *c8_in);
extern void sf_internal_set_sim_state_c8_EP_IdleRandMerg(SimStruct *c8_S, const
  mxArray *c8_in);
extern void sf_exported_auto_check_state_inconsistency_c8_EP_IdleRandMerg
  (SimStruct *c8_S);
extern void sf_exported_user_c8_EP_IdleRandMerg_insertQueue(SimStruct *c8_S,
  real_T c8_bmls[5000], real_T c8_myBML[1000], real_T c8_newBmls[5000]);
extern void sf_exported_user_c8_EP_IdleRandMerg_insertQueueLow(SimStruct *c8_S,
  real_T c8_bmls[5000], real_T c8_myBML[1000], real_T c8_newBmls[5000]);
extern void sf_exported_user_c8_EP_IdleRandMerg_walkInvadingTable(SimStruct
  *c8_S, real_T c8_bmlID, real_T *c8_p, real_T c8_poseBML[1000]);

/* Function Definitions */
extern void sf_c8_EP_IdleRandMerg_get_check_sum(mxArray *plhs[]);
extern void c8_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
