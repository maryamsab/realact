#ifndef __c20_DemoGazeFollowWaveIdleRand_h__
#define __c20_DemoGazeFollowWaveIdleRand_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc20_DemoGazeFollowWaveIdleRandInstanceStruct
#define typedef_SFc20_DemoGazeFollowWaveIdleRandInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  uint8_T c20_tp_init;
  uint8_T c20_tp_waveRightHand;
  uint8_T c20_tp_gazeCamera;
  uint8_T c20_tp_wave;
  uint8_T c20_tp_gazeCamera1;
  uint8_T c20_tp_waveLeftHand;
  uint8_T c20_tp_waveBothHands;
  uint8_T c20_tp_gazeCamera2;
  boolean_T c20_isStable;
  uint8_T c20_is_active_c20_DemoGazeFollowWaveIdleRand;
  uint8_T c20_is_c20_DemoGazeFollowWaveIdleRand;
  real_T c20_rFlag;
  real_T c20_lFlag;
  real_T c20_bFlag;
  real_T c20_BMLM[256];
  real_T c20_newBmlsM[1280];
  real_T c20_n[256];
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
  real_T (*c20_bmlsM_address)[1280];
  int32_T c20_bmlsM_index;
  real_T *c20_fileID_address;
  int32_T c20_fileID_index;
} SFc20_DemoGazeFollowWaveIdleRandInstanceStruct;

#endif                                 /*typedef_SFc20_DemoGazeFollowWaveIdleRandInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c20_DemoGazeFollowWaveIdleRand_get_eml_resolved_functions_info(void);
extern void sf_exported_auto_activate_c20_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c20_S);
extern void
  sf_exported_auto_incrementTemporalCounter_c20_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c20_S);
extern void
  sf_exported_auto_resetTemporalCounter_c20_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c20_S);
extern void sf_exported_auto_deactivate_c20_DemoGazeFollowWaveIdleRand_secs
  (SimStruct *c20_S);
extern boolean_T sf_exported_auto_isStablec20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void sf_exported_auto_duringc20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_enterc20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_exitc20_DemoGazeFollowWaveIdleRand(SimStruct *c20_S);
extern void sf_exported_auto_gatewayc20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_enablec20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_disablec20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_stepBuffersc20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_initBuffersc20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S);
extern void sf_exported_auto_activate_callc20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void
  sf_exported_auto_increment_call_counterc20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void sf_exported_auto_reset_call_counterc20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void sf_exported_auto_deactivate_callc20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void sf_exported_auto_initc20_DemoGazeFollowWaveIdleRand(SimStruct *c20_S);
extern const mxArray *sf_exported_auto_getSimstatec20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern const mxArray *sf_internal_get_sim_state_c20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void sf_exported_auto_setSimstatec20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S, const mxArray *c20_in);
extern void sf_internal_set_sim_state_c20_DemoGazeFollowWaveIdleRand(SimStruct
  *c20_S, const mxArray *c20_in);
extern void
  sf_exported_auto_check_state_inconsistency_c20_DemoGazeFollowWaveIdleRand
  (SimStruct *c20_S);
extern void sf_exported_user_c20_DemoGazeFollowWaveIdleRand_insertQueue
  (SimStruct *c20_S, real_T c20_bmls[1280], real_T c20_mBML[256], real_T
   c20_newBmls[1280]);
extern void sf_exported_user_c20_DemoGazeFollowWaveIdleRand_wavePoseBradTable
  (SimStruct *c20_S, real_T c20_bmlID, real_T *c20_pr, real_T c20_poseBML[256]);

/* Function Definitions */
extern void sf_c20_DemoGazeFollowWaveIdleRand_get_check_sum(mxArray *plhs[]);
extern void c20_DemoGazeFollowWaveIdleRand_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
