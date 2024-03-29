#ifndef __c20_ARP_02_RPSs_Bdr_GK_BIS5_h__
#define __c20_ARP_02_RPSs_Bdr_GK_BIS5_h__

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

#ifndef typedef_c20_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c20_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c20_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c20_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
#define typedef_SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  uint8_T c20_tp_waveRightHand;
  uint8_T c20_tp_init;
  uint8_T c20_tp_waveLeftHand;
  uint8_T c20_tp_wave;
  uint8_T c20_tp_waveBothHands;
  uint8_T c20_tp_gazeCamera2;
  uint8_T c20_tp_gazeCamera;
  uint8_T c20_tp_gazeCamera1;
  boolean_T c20_isStable;
  uint8_T c20_is_active_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  uint8_T c20_is_c20_ARP_02_RPSs_Bdr_GK_BIS5;
  real_T c20_rFlag;
  real_T c20_lFlag;
  real_T c20_bFlag;
  uint8_T c20_temporalCounter_i1;
  uint8_T c20_doSetSimStateSideEffects;
  const mxArray *c20_setSimStateSideEffectsInfo;
  real_T (*c20_BML_address)[256];
  int32_T c20_BML_index;
  real_T (*c20_BML2_address)[256];
  int32_T c20_BML2_index;
  real_T *c20_P_address;
  int32_T c20_P_index;
  real_T *c20_STATE_BEFORE_address;
  int32_T c20_STATE_BEFORE_index;
  real_T *c20_STATE_OVER_address;
  int32_T c20_STATE_OVER_index;
  real_T *c20_avert_address;
  int32_T c20_avert_index;
  real_T *c20_fileID_address;
  int32_T c20_fileID_index;
} SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct;

#endif                                 /*typedef_SFc20_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct
  *c20_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c20_S);
extern void
  sf_exported_auto_resetTemporalCounter_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c20_S);
extern void sf_exported_auto_deactivate_c20_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c20_S);
extern boolean_T sf_exported_auto_isStablec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *
  c20_S);
extern void sf_exported_auto_duringc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern void sf_exported_auto_enterc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern void sf_exported_auto_exitc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern void sf_exported_auto_gatewayc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern void sf_exported_auto_enablec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern void sf_exported_auto_disablec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern void sf_exported_auto_stepBuffersc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S);
extern void sf_exported_auto_initBuffersc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S);
extern void sf_exported_auto_activate_callc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *
  c20_S);
extern void sf_exported_auto_increment_call_counterc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S);
extern void sf_exported_auto_reset_call_counterc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S);
extern void sf_exported_auto_deactivate_callc20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S);
extern void sf_exported_auto_initc20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c20_S);
extern const mxArray *sf_exported_auto_getSimstatec20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S);
extern const mxArray *sf_internal_get_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S);
extern void sf_exported_auto_setSimstatec20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S, const mxArray *c20_in);
extern void sf_internal_set_sim_state_c20_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c20_S, const mxArray *c20_in);
extern void
  sf_exported_auto_check_state_inconsistency_c20_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c20_S);
extern void sf_exported_user_c20_ARP_02_RPSs_Bdr_GK_BIS5_wavePoseBradTable
  (SimStruct *c20_S, real_T c20_bmlID, real_T *c20_pr, real_T c20_poseBML[256]);

/* Function Definitions */
extern void sf_c20_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(mxArray *plhs[]);
extern void c20_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
