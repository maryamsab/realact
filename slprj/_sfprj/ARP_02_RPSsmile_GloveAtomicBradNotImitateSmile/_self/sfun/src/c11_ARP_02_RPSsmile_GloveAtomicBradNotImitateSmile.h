#ifndef __c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_h__
#define __c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
#define typedef_SFc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  uint8_T c11_tp_stateInitial;
  uint8_T c11_tp_stateCheckSmile;
  uint8_T c11_tp_stateNeutralHead;
  uint8_T c11_tp_stateImitateSmile;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  uint8_T c11_is_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  uint8_T c11_doSetSimStateSideEffects;
  const mxArray *c11_setSimStateSideEffectsInfo;
  real_T *c11_avert_address;
  int32_T c11_avert_index;
  real_T *c11_isPosing_address;
  int32_T c11_isPosing_index;
  real_T *c11_isSmiling_address;
  int32_T c11_isSmiling_index;
  real_T *c11_smileDur_address;
  int32_T c11_smileDur_index;
  real_T *c11_smileN_address;
  int32_T c11_smileN_index;
} SFc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct;

#endif                                 /*typedef_SFc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_eml_resolved_functions_info
  (void);
extern boolean_T
  sf_exported_auto_isStablec11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_duringc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_enterc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_exitc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_gatewayc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_enablec11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_disablec11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_stepBuffersc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_initBuffersc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_activate_callc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_increment_call_counterc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_reset_call_counterc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_deactivate_callc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_initc11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern const mxArray
  *sf_exported_auto_getSimstatec11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern const mxArray
  *sf_internal_get_sim_state_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_auto_setSimstatec11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S, const mxArray *c11_in);
extern void
  sf_internal_set_sim_state_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S, const mxArray *c11_in);
extern void
  sf_exported_auto_check_state_inconsistency_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c11_S);
extern void
  sf_exported_user_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_sendBML
  (SimStruct *c11_S, real_T c11_arg[256]);
extern void
  sf_exported_user_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_smileTable
  (SimStruct *c11_S, real_T c11_bmlID, real_T c11_poseBML[256]);

/* Function Definitions */
extern void sf_c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_check_sum
  (mxArray *plhs[]);
extern void c11_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
