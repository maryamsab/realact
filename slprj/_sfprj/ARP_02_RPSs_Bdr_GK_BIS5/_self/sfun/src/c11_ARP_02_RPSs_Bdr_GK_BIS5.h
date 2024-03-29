#ifndef __c11_ARP_02_RPSs_Bdr_GK_BIS5_h__
#define __c11_ARP_02_RPSs_Bdr_GK_BIS5_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sL6LJlPlxhdTxZzXh5NTaQC
#define struct_sL6LJlPlxhdTxZzXh5NTaQC

struct sL6LJlPlxhdTxZzXh5NTaQC
{
  int32_T intNumBits;
};

#endif                                 /*struct_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_c11_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c11_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c11_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c11_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
#define typedef_SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  uint8_T c11_tp_stateInitial;
  uint8_T c11_tp_stateCheckSmile;
  uint8_T c11_tp_stateHeadNeutral;
  uint8_T c11_tp_gazeCamera;
  uint8_T c11_tp_stateImitateSmile;
  uint8_T c11_tp_checkP;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  uint8_T c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  real_T c11_smileN;
  real_T c11_fileID;
  uint8_T c11_temporalCounter_i1;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T (*c11_BML_address)[256];
  int32_T c11_BML_index;
  real_T *c11_GAZE_WIN_address;
  int32_T c11_GAZE_WIN_index;
  real_T *c11_P_address;
  int32_T c11_P_index;
  real_T *c11_STATE_BEFORE_address;
  int32_T c11_STATE_BEFORE_index;
  real_T *c11_STATE_GO_address;
  int32_T c11_STATE_GO_index;
  real_T *c11_STATE_READY_address;
  int32_T c11_STATE_READY_index;
  real_T *c11_avert_address;
  int32_T c11_avert_index;
  real_T *c11_changeFlag_address;
  int32_T c11_changeFlag_index;
  real_T *c11_gazing_address;
  int32_T c11_gazing_index;
} SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct;

#endif                                 /*typedef_SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct
  *c11_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c11_S);
extern void
  sf_exported_auto_resetTemporalCounter_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c11_S);
extern boolean_T sf_exported_auto_isStablec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *
  c11_S);
extern void sf_exported_auto_duringc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern void sf_exported_auto_enterc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern void sf_exported_auto_exitc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern void sf_exported_auto_gatewayc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern void sf_exported_auto_enablec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern void sf_exported_auto_disablec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern void sf_exported_auto_stepBuffersc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S);
extern void sf_exported_auto_initBuffersc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S);
extern void sf_exported_auto_activate_callc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *
  c11_S);
extern void sf_exported_auto_increment_call_counterc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S);
extern void sf_exported_auto_reset_call_counterc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S);
extern void sf_exported_auto_deactivate_callc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S);
extern void sf_exported_auto_initc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S);
extern const mxArray *sf_exported_auto_getSimstatec11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S);
extern const mxArray *sf_internal_get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S);
extern void sf_exported_auto_setSimstatec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S, const mxArray *c11_in);
extern void sf_internal_set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S, const mxArray *c11_in);
extern void
  sf_exported_auto_check_state_inconsistency_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S);
extern void sf_exported_user_c11_ARP_02_RPSs_Bdr_GK_BIS5_smileTable(SimStruct
  *c11_S, real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256]);

/* Function Definitions */
extern void sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(mxArray *plhs[]);
extern void c11_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
