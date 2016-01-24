#ifndef __c4_testKinectGazeWaveGUI_h__
#define __c4_testKinectGazeWaveGUI_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_testKinectGazeWaveGUIInstanceStruct
#define typedef_SFc4_testKinectGazeWaveGUIInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_initalize;
  uint8_T c4_tp_stateInitializeSmileI;
  uint8_T c4_tp_stateInitalizeGazeE;
  uint8_T c4_tp_stateCheckUser;
  uint8_T c4_tp_stateSmile;
  uint8_T c4_tp_stateGazeI;
  uint8_T c4_tp_stateInitializeIntrovert;
  uint8_T c4_tp_stateExtravert;
  uint8_T c4_tp_initializeWalkE;
  uint8_T c4_tp_idle;
  uint8_T c4_tp_stateExtravetPose;
  uint8_T c4_tp_stateCheckUser2;
  uint8_T c4_tp_stateAvert;
  uint8_T c4_tp_stateIntrovertPose;
  uint8_T c4_tp_stateBeat;
  uint8_T c4_tp_state2beat;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_testKinectGazeWaveGUI;
  uint8_T c4_is_c4_testKinectGazeWaveGUI;
  real_T c4_beat;
  real_T c4_count;
  real_T c4_txtBeat[256];
  real_T c4_txtNoSmile[256];
  real_T c4_txtSmile[256];
  real_T c4_txtAvert[256];
  real_T c4_txtEyeTarget[256];
  real_T c4_txtGaze2;
  real_T c4_gaze;
  real_T c4_txtGaze[256];
  real_T c4_txtWalkToNeutral[256];
  real_T c4_txtWalkFw[256];
  real_T c4_n;
  real_T c4_m;
  real_T c4_beat2;
  real_T c4_txtBeat2[256];
  uint32_T c4_method;
  boolean_T c4_method_not_empty;
  uint32_T c4_state;
  boolean_T c4_state_not_empty;
  uint32_T c4_b_state[2];
  boolean_T c4_b_state_not_empty;
  uint32_T c4_c_state[625];
  boolean_T c4_c_state_not_empty;
  uint8_T c4_temporalCounter_i1;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_testKinectGazeWaveGUIInstanceStruct;

#endif                                 /*typedef_SFc4_testKinectGazeWaveGUIInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_testKinectGazeWaveGUI_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_testKinectGazeWaveGUI_get_check_sum(mxArray *plhs[]);
extern void c4_testKinectGazeWaveGUI_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
