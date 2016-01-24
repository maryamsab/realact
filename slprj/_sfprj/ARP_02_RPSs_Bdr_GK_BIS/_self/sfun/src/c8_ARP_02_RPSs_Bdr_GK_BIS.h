#ifndef __c8_ARP_02_RPSs_Bdr_GK_BIS_h__
#define __c8_ARP_02_RPSs_Bdr_GK_BIS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
#define typedef_SFc8_ARP_02_RPSs_Bdr_GK_BISInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  uint8_T c8_tp_stateInit;
  uint8_T c8_tp_idle;
  uint8_T c8_tp_stateWalkBack;
  uint8_T c8_tp_stateHeadNeutral;
  uint8_T c8_tp_walkFW;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS;
  uint8_T c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS;
  uint8_T c8_temporalCounter_i1;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
  real_T (*c8_BML_address)[256];
  int32_T c8_BML_index;
  real_T *c8_STATE_BEFORE_address;
  int32_T c8_STATE_BEFORE_index;
  real_T *c8_STATE_OVER_address;
  int32_T c8_STATE_OVER_index;
  real_T *c8_STATE_READY_address;
  int32_T c8_STATE_READY_index;
  real_T *c8_isPosing_address;
  int32_T c8_isPosing_index;
  real_T *c8_pr_address;
  int32_T c8_pr_index;
} SFc8_ARP_02_RPSs_Bdr_GK_BISInstanceStruct;

#endif                                 /*typedef_SFc8_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_ARP_02_RPSs_Bdr_GK_BIS_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c8_ARP_02_RPSs_Bdr_GK_BIS_secs(SimStruct
  *c8_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS_secs
  (SimStruct *c8_S);
extern void sf_exported_auto_resetTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS_secs
  (SimStruct *c8_S);
extern void sf_exported_auto_deactivate_c8_ARP_02_RPSs_Bdr_GK_BIS_secs(SimStruct
  *c8_S);
extern boolean_T sf_exported_auto_isStablec8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c8_S);
extern void sf_exported_auto_duringc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern void sf_exported_auto_enterc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern void sf_exported_auto_exitc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern void sf_exported_auto_gatewayc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern void sf_exported_auto_enablec8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern void sf_exported_auto_disablec8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern void sf_exported_auto_stepBuffersc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c8_S);
extern void sf_exported_auto_initBuffersc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c8_S);
extern void sf_exported_auto_activate_callc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c8_S);
extern void sf_exported_auto_increment_call_counterc8_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct *c8_S);
extern void sf_exported_auto_reset_call_counterc8_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct *c8_S);
extern void sf_exported_auto_deactivate_callc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *
  c8_S);
extern void sf_exported_auto_initc8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S);
extern const mxArray *sf_exported_auto_getSimstatec8_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct *c8_S);
extern const mxArray *sf_internal_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct *c8_S);
extern void sf_exported_auto_setSimstatec8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c8_S, const mxArray *c8_in);
extern void sf_internal_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c8_S,
  const mxArray *c8_in);
extern void sf_exported_auto_check_state_inconsistency_c8_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct *c8_S);
extern void sf_exported_user_c8_ARP_02_RPSs_Bdr_GK_BIS_walkInvadingTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256]);

/* Function Definitions */
extern void sf_c8_ARP_02_RPSs_Bdr_GK_BIS_get_check_sum(mxArray *plhs[]);
extern void c8_ARP_02_RPSs_Bdr_GK_BIS_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
