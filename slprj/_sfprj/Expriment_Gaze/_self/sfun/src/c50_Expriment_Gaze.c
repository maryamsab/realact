/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Gaze_sfun.h"
#include "c50_Expriment_Gaze.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Gaze_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c50_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c50_debug_family_names[18] = { "nargin", "nargout", "v", "a",
  "p", "pFlag", "vaFlag", "gazeArr", "mutDurFactor", "avertDurFactor",
  "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance", "avertFreqFactor",
  "mutFreqFactor", "blinkFlag", "blinkPeriodMin", "blinkPeriodMax" };

static const char * c50_b_debug_family_names[22] = { "pose_custom_flag",
  "pose_chance_custom", "pose_selfAdaptor_chance_custom",
  "pose_frequency_custom", "pose_speed_custom", "pose_lean_custom", "nargin",
  "nargout", "v", "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange",
  "poseTwitch", "poseFreqFactor", "poseChanceFactor", "poseCatChance",
  "poseLean", "poseSpeed", "poseLeanFlag" };

static boolean_T c50_dataWrittenToVector[17];

/* Function Declarations */
static void initialize_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void initialize_params_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static void enable_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void disable_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void c50_update_debugger_state_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static void set_sim_state_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c50_st);
static void c50_set_sim_state_side_effects_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static void finalize_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void sf_gateway_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void c50_enter_atomic_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static void c50_enter_internal_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static void c50_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void c50_exit_internal_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance);
static void c50_initc50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);
static void initSimStructsc50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static real_T c50_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_b_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[6]);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static boolean_T c50_c_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static void c50_setGazeFactorsc50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance, real_T c50_v, real_T c50_a,
   real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag, real_T c50_gazeArr[6],
   real_T *c50_mutDurFactor, real_T *c50_avertDurFactor, real_T
   *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
   *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
   real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax);
static void c50_setPoseFactorsc50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance, real_T c50_v, real_T
   c50_ar, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag, real_T
   c50_poseArr[6], real_T c50_personalityChange, real_T *c50_poseTwitch, real_T *
   c50_poseFreqFactor, real_T *c50_poseChanceFactor, real_T *c50_poseCatChance,
   real_T *c50_poseLean, real_T *c50_poseSpeed, real_T *c50_poseLeanFlag);
static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int32_T c50_d_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static uint8_T c50_e_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_b_is_active_c50_Expriment_Gaze, const
  char_T *c50_identifier);
static uint8_T c50_f_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static const mxArray *c50_g_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c50_b_setSimStateSideEffectsInfo, const char_T
  *c50_identifier);
static const mxArray *c50_h_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_updateDataWrittenToVector(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c50_vectorIndex);
static void init_dsm_address_info(SFc50_Expriment_GazeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c50_update_debugger_state_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  const mxArray *c50_st;
  const mxArray *c50_y = NULL;
  uint8_T c50_hoistedGlobal;
  uint8_T c50_u;
  const mxArray *c50_b_y = NULL;
  c50_st = NULL;
  c50_st = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_createcellmatrix(1, 1), false);
  c50_hoistedGlobal = chartInstance->c50_is_active_c50_Expriment_Gaze;
  c50_u = c50_hoistedGlobal;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  sf_mex_assign(&c50_st, c50_y, false);
  return c50_st;
}

static void set_sim_state_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c50_st)
{
  const mxArray *c50_u;
  chartInstance->c50_doneDoubleBufferReInit = true;
  c50_u = sf_mex_dup(c50_st);
  chartInstance->c50_is_active_c50_Expriment_Gaze = c50_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 0)),
     "is_active_c50_Expriment_Gaze");
  sf_mex_assign(&chartInstance->c50_setSimStateSideEffectsInfo,
                c50_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c50_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c50_u);
  chartInstance->c50_doSetSimStateSideEffects = 1U;
  c50_update_debugger_state_c50_Expriment_Gaze(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void c50_set_sim_state_side_effects_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  if (chartInstance->c50_doSetSimStateSideEffects != 0) {
    chartInstance->c50_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c50_setSimStateSideEffectsInfo);
}

static void sf_gateway_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  c50_set_sim_state_side_effects_c50_Expriment_Gaze(chartInstance);
}

static void c50_enter_atomic_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 26U, chartInstance->c50_sfEvent);
  chartInstance->c50_is_active_c50_Expriment_Gaze = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c50_sfEvent);
}

static void c50_enter_internal_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_c50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c50_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c50_sfEvent);
}

static void c50_exit_internal_c50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_initc50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  chartInstance->c50_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_doSetSimStateSideEffects = 0U;
  chartInstance->c50_setSimStateSideEffectsInfo = NULL;
  chartInstance->c50_is_active_c50_Expriment_Gaze = 0U;
}

static void initSimStructsc50_Expriment_Gaze(SFc50_Expriment_GazeInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber)
{
  (void)c50_machineNumber;
  (void)c50_chartNumber;
  (void)c50_instanceNumber;
}

static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static real_T c50_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d0, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_blinkPeriodMax;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_blinkPeriodMax = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_blinkPeriodMax),
    &c50_thisId);
  sf_mex_destroy(&c50_blinkPeriodMax);
  *(real_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i0;
  real_T c50_b_inData[6];
  int32_T c50_i1;
  real_T c50_u[6];
  const mxArray *c50_y = NULL;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i0 = 0; c50_i0 < 6; c50_i0++) {
    c50_b_inData[c50_i0] = (*(real_T (*)[6])c50_inData)[c50_i0];
  }

  for (c50_i1 = 0; c50_i1 < 6; c50_i1++) {
    c50_u[c50_i1] = c50_b_inData[c50_i1];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_b_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[6])
{
  real_T c50_dv0[6];
  int32_T c50_i2;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c50_i2 = 0; c50_i2 < 6; c50_i2++) {
    c50_y[c50_i2] = c50_dv0[c50_i2];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_gazeArr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[6];
  int32_T c50_i3;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_gazeArr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_gazeArr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_gazeArr);
  for (c50_i3 = 0; c50_i3 < 6; c50_i3++) {
    (*(real_T (*)[6])c50_outData)[c50_i3] = c50_y[c50_i3];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  boolean_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(boolean_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static boolean_T c50_c_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  boolean_T c50_y;
  boolean_T c50_b0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_b0, 1, 11, 0U, 0, 0U, 0);
  c50_y = c50_b0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_vaFlag;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  boolean_T c50_y;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_vaFlag = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_vaFlag),
    &c50_thisId);
  sf_mex_destroy(&c50_vaFlag);
  *(boolean_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

const mxArray *sf_c50_Expriment_Gaze_get_eml_resolved_functions_info(void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c50_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  return true;
}

void sf_exported_auto_duringc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_c50_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_enterc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_enter_atomic_c50_Expriment_Gaze(chartInstance);
  c50_enter_internal_c50_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_exitc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_exit_internal_c50_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_gatewayc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  chartInstance->c50_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc50_Expriment_Gaze(SimStruct *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_initc50_Expriment_Gaze(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec50_Expriment_Gaze(SimStruct *c50_S)
{
  const mxArray *c50_out = NULL;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_out = NULL;
  sf_mex_assign(&c50_out, sf_internal_get_sim_state_c50_Expriment_Gaze(c50_S),
                false);
  return c50_out;
}

void sf_exported_auto_setSimstatec50_Expriment_Gaze(SimStruct *c50_S, const
  mxArray *c50_in)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c50_Expriment_Gaze(c50_S, sf_mex_dup(c50_in));
  sf_mex_destroy(&c50_in);
}

void sf_exported_auto_check_state_inconsistency_c50_Expriment_Gaze(SimStruct
  *c50_S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_GazeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c50_setGazeFactorsc50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance, real_T c50_v, real_T c50_a,
   real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag, real_T c50_gazeArr[6],
   real_T *c50_mutDurFactor, real_T *c50_avertDurFactor, real_T
   *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
   *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
   real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax)
{
  uint32_T c50_debug_family_var_map[18];
  real_T c50_nargin = 6.0;
  real_T c50_nargout = 10.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c50_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_v, 2U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_a, 3U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_p, 4U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pFlag, 5U, c50_c_sf_marshallOut,
    c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_vaFlag, 6U, c50_c_sf_marshallOut,
    c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_gazeArr, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mutDurFactor, 8U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertDurFactor, 9U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertHeadFreqFactor, 10U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertHeadSpeed, 11U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertDirsChance, 12U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertFreqFactor, 13U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mutFreqFactor, 14U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_blinkFlag, 15U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_blinkPeriodMin, 16U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_blinkPeriodMax, 17U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 41);
  *c50_mutDurFactor = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 42);
  *c50_avertDurFactor = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 43);
  *c50_avertHeadFreqFactor = 20.0;
  c50_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 44);
  *c50_avertHeadSpeed = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 45);
  *c50_avertDirsChance = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 46);
  *c50_avertFreqFactor = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 47);
  *c50_mutFreqFactor = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 48);
  *c50_blinkFlag = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 49);
  *c50_blinkPeriodMin = 5.0;
  c50_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 50);
  *c50_blinkPeriodMax = 9.0;
  c50_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 52);
  if (CV_EML_IF(0, 1, 0, (real_T)c50_pFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 53);
    if (CV_EML_IF(0, 1, 1, c50_p == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 54);
      *c50_mutDurFactor = 2.0;
      c50_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 55);
      *c50_avertDurFactor = 0.5;
      c50_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 56);
      *c50_avertHeadFreqFactor = 30.0;
      c50_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 57);
      *c50_avertHeadSpeed = 2.0;
      c50_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 58);
      *c50_avertDirsChance = 1.0;
      c50_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 60);
      *c50_mutFreqFactor = 3.0;
      c50_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 61);
      *c50_avertFreqFactor = 0.5;
      c50_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 63);
      *c50_blinkFlag = 1.0;
      c50_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 64);
      *c50_blinkPeriodMin = 0.2;
      c50_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 65);
      *c50_blinkPeriodMax = 7.0;
      c50_updateDataWrittenToVector(chartInstance, 9U);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 66);
      if (CV_EML_IF(0, 1, 2, c50_p == 2.0)) {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 67);
        *c50_mutDurFactor = 0.5;
        c50_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 68);
        *c50_avertDurFactor = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 69);
        *c50_avertHeadFreqFactor = 15.0;
        c50_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 70);
        *c50_avertHeadSpeed = 3.0;
        c50_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 71);
        *c50_avertDirsChance = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 73);
        *c50_mutFreqFactor = 0.5;
        c50_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 74);
        *c50_avertFreqFactor = 3.0;
        c50_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 76);
        *c50_blinkFlag = 1.0;
        c50_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 77);
        *c50_blinkPeriodMin = 0.2;
        c50_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 78);
        *c50_blinkPeriodMax = 5.0;
        c50_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 79);
        if (CV_EML_IF(0, 1, 3, c50_p == 3.0)) {
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 80);
          *c50_mutDurFactor = 4.0;
          c50_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 81);
          *c50_avertDurFactor = 0.1;
          c50_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 82);
          *c50_avertHeadFreqFactor = 25.0;
          c50_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 83);
          *c50_avertHeadSpeed = 2.0;
          c50_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 84);
          *c50_avertDirsChance = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 86);
          *c50_mutFreqFactor = 3.0;
          c50_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 87);
          *c50_avertFreqFactor = 0.5;
          c50_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 89);
          *c50_blinkFlag = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 90);
          *c50_blinkPeriodMin = 5.0;
          c50_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 91);
          *c50_blinkPeriodMax = 15.0;
          c50_updateDataWrittenToVector(chartInstance, 9U);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 93);
          *c50_mutDurFactor = 0.25;
          c50_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 94);
          *c50_avertDurFactor = 0.5;
          c50_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 95);
          *c50_avertHeadFreqFactor = 10.0;
          c50_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 96);
          *c50_avertHeadSpeed = 3.0;
          c50_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 97);
          *c50_avertDirsChance = 2.0;
          c50_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 99);
          *c50_mutFreqFactor = 0.5;
          c50_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 100);
          *c50_avertFreqFactor = 3.0;
          c50_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 102);
          *c50_blinkFlag = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 103);
          *c50_blinkPeriodMin = 5.0;
          c50_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 104);
          *c50_blinkPeriodMax = 9.0;
          c50_updateDataWrittenToVector(chartInstance, 9U);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -104);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_setPoseFactorsc50_Expriment_Gaze
  (SFc50_Expriment_GazeInstanceStruct *chartInstance, real_T c50_v, real_T
   c50_ar, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag, real_T
   c50_poseArr[6], real_T c50_personalityChange, real_T *c50_poseTwitch, real_T *
   c50_poseFreqFactor, real_T *c50_poseChanceFactor, real_T *c50_poseCatChance,
   real_T *c50_poseLean, real_T *c50_poseSpeed, real_T *c50_poseLeanFlag)
{
  uint32_T c50_debug_family_var_map[22];
  real_T c50_pose_custom_flag;
  real_T c50_pose_chance_custom;
  real_T c50_pose_selfAdaptor_chance_custom;
  real_T c50_pose_frequency_custom;
  real_T c50_pose_speed_custom;
  real_T c50_pose_lean_custom;
  real_T c50_nargin = 7.0;
  real_T c50_nargout = 7.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c50_b_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pose_custom_flag, 0U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pose_chance_custom, 1U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pose_selfAdaptor_chance_custom, 2U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pose_frequency_custom, 3U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pose_speed_custom, 4U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pose_lean_custom, 5U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 6U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 7U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_v, 8U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_ar, 9U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_p, 10U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_pFlag, 11U, c50_c_sf_marshallOut,
    c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_vaFlag, 12U, c50_c_sf_marshallOut,
    c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseArr, 13U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_personalityChange, 14U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseTwitch, 15U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseFreqFactor, 16U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseChanceFactor, 17U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseCatChance, 18U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseLean, 19U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseSpeed, 20U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseLeanFlag, 21U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 3);
  c50_pose_custom_flag = c50_poseArr[0];
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 4);
  c50_pose_chance_custom = c50_poseArr[2];
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 5);
  c50_pose_selfAdaptor_chance_custom = c50_poseArr[1];
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 6);
  c50_pose_frequency_custom = c50_poseArr[3];
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 7);
  c50_pose_speed_custom = c50_poseArr[4];
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 8);
  c50_pose_lean_custom = c50_poseArr[5];
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 10);
  *c50_poseCatChance = 70.0;
  c50_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 11);
  *c50_poseChanceFactor = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 12);
  *c50_poseFreqFactor = 20.0;
  c50_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 13);
  *c50_poseSpeed = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 14);
  *c50_poseLean = 10.0;
  c50_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 15);
  *c50_poseTwitch = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 16);
  *c50_poseLeanFlag = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 18);
  if (CV_EML_IF(1, 1, 0, c50_pose_custom_flag == 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 19);
    if (CV_EML_IF(1, 1, 1, (real_T)c50_pFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 20);
      if (CV_EML_IF(1, 1, 2, c50_personalityChange == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 21);
        *c50_poseLeanFlag = 1.0;
        c50_updateDataWrittenToVector(chartInstance, 16U);
      }

      _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 23);
      if (CV_EML_IF(1, 1, 3, c50_p == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 24);
        *c50_poseTwitch = 1.0;
        c50_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 25);
        *c50_poseFreqFactor = 10.0;
        c50_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 26);
        *c50_poseLean = 11.0;
        c50_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 27);
        *c50_poseChanceFactor = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 28);
        *c50_poseCatChance = 90.0;
        c50_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 29);
        *c50_poseSpeed = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 15U);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 30);
        if (CV_EML_IF(1, 1, 4, c50_p == 2.0)) {
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 31);
          *c50_poseTwitch = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 32);
          *c50_poseFreqFactor = 17.0;
          c50_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 33);
          *c50_poseLean = 12.0;
          c50_updateDataWrittenToVector(chartInstance, 14U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 34);
          *c50_poseChanceFactor = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 12U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 35);
          *c50_poseCatChance = 10.0;
          c50_updateDataWrittenToVector(chartInstance, 13U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 36);
          *c50_poseSpeed = 3.0;
          c50_updateDataWrittenToVector(chartInstance, 15U);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 37);
          if (CV_EML_IF(1, 1, 5, c50_p == 3.0)) {
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 38);
            *c50_poseTwitch = 0.0;
            c50_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 39);
            *c50_poseFreqFactor = 12.0;
            c50_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 40);
            *c50_poseLean = 11.0;
            c50_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 41);
            *c50_poseChanceFactor = 2.0;
            c50_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 42);
            *c50_poseCatChance = 10.0;
            c50_updateDataWrittenToVector(chartInstance, 13U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 43);
            *c50_poseSpeed = 2.0;
            c50_updateDataWrittenToVector(chartInstance, 15U);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 45);
            *c50_poseTwitch = 0.0;
            c50_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 46);
            *c50_poseFreqFactor = 20.0;
            c50_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 47);
            *c50_poseLean = 12.0;
            c50_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 48);
            *c50_poseChanceFactor = 1.0;
            c50_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 49);
            *c50_poseCatChance = 90.0;
            c50_updateDataWrittenToVector(chartInstance, 13U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 50);
            *c50_poseSpeed = 3.0;
            c50_updateDataWrittenToVector(chartInstance, 15U);
          }
        }
      }
    }
  } else {
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 68);
    *c50_poseFreqFactor = c50_pose_frequency_custom;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 69);
    *c50_poseLean = c50_pose_lean_custom;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 70);
    *c50_poseChanceFactor = c50_pose_chance_custom;
    c50_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 71);
    *c50_poseCatChance = c50_pose_selfAdaptor_chance_custom;
    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 72);
    *c50_poseSpeed = c50_pose_speed_custom;
    c50_updateDataWrittenToVector(chartInstance, 15U);
  }

  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, -72);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c50_Expriment_Gaze_setGazeFactors(SimStruct *c50_S, real_T
  c50_v, real_T c50_a, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag,
  real_T c50_gazeArr[6], real_T *c50_mutDurFactor, real_T *c50_avertDurFactor,
  real_T *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
  *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
  real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax)
{
  int32_T c50_i4;
  real_T c50_b_gazeArr[6];
  real_T c50_b_blinkPeriodMax;
  real_T c50_b_blinkPeriodMin;
  real_T c50_b_blinkFlag;
  real_T c50_b_mutFreqFactor;
  real_T c50_b_avertFreqFactor;
  real_T c50_b_avertDirsChance;
  real_T c50_b_avertHeadSpeed;
  real_T c50_b_avertHeadFreqFactor;
  real_T c50_b_avertDurFactor;
  real_T c50_b_mutDurFactor;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  for (c50_i4 = 0; c50_i4 < 6; c50_i4++) {
    c50_b_gazeArr[c50_i4] = c50_gazeArr[c50_i4];
  }

  c50_setGazeFactorsc50_Expriment_Gaze(chartInstance, c50_v, c50_a, c50_p,
    c50_pFlag, c50_vaFlag, c50_b_gazeArr, &c50_b_mutDurFactor,
    &c50_b_avertDurFactor, &c50_b_avertHeadFreqFactor, &c50_b_avertHeadSpeed,
    &c50_b_avertDirsChance, &c50_b_avertFreqFactor, &c50_b_mutFreqFactor,
    &c50_b_blinkFlag, &c50_b_blinkPeriodMin, &c50_b_blinkPeriodMax);
  *c50_mutDurFactor = c50_b_mutDurFactor;
  *c50_avertDurFactor = c50_b_avertDurFactor;
  *c50_avertHeadFreqFactor = c50_b_avertHeadFreqFactor;
  *c50_avertHeadSpeed = c50_b_avertHeadSpeed;
  *c50_avertDirsChance = c50_b_avertDirsChance;
  *c50_avertFreqFactor = c50_b_avertFreqFactor;
  *c50_mutFreqFactor = c50_b_mutFreqFactor;
  *c50_blinkFlag = c50_b_blinkFlag;
  *c50_blinkPeriodMin = c50_b_blinkPeriodMin;
  *c50_blinkPeriodMax = c50_b_blinkPeriodMax;
}

void sf_exported_user_c50_Expriment_Gaze_setPoseFactors(SimStruct *c50_S, real_T
  c50_v, real_T c50_ar, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag,
  real_T c50_poseArr[6], real_T c50_personalityChange, real_T *c50_poseTwitch,
  real_T *c50_poseFreqFactor, real_T *c50_poseChanceFactor, real_T
  *c50_poseCatChance, real_T *c50_poseLean, real_T *c50_poseSpeed, real_T
  *c50_poseLeanFlag)
{
  int32_T c50_i5;
  real_T c50_b_poseArr[6];
  real_T c50_b_poseLeanFlag;
  real_T c50_b_poseSpeed;
  real_T c50_b_poseLean;
  real_T c50_b_poseCatChance;
  real_T c50_b_poseChanceFactor;
  real_T c50_b_poseFreqFactor;
  real_T c50_b_poseTwitch;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  for (c50_i5 = 0; c50_i5 < 6; c50_i5++) {
    c50_b_poseArr[c50_i5] = c50_poseArr[c50_i5];
  }

  c50_setPoseFactorsc50_Expriment_Gaze(chartInstance, c50_v, c50_ar, c50_p,
    c50_pFlag, c50_vaFlag, c50_b_poseArr, c50_personalityChange,
    &c50_b_poseTwitch, &c50_b_poseFreqFactor, &c50_b_poseChanceFactor,
    &c50_b_poseCatChance, &c50_b_poseLean, &c50_b_poseSpeed, &c50_b_poseLeanFlag);
  *c50_poseTwitch = c50_b_poseTwitch;
  *c50_poseFreqFactor = c50_b_poseFreqFactor;
  *c50_poseChanceFactor = c50_b_poseChanceFactor;
  *c50_poseCatChance = c50_b_poseCatChance;
  *c50_poseLean = c50_b_poseLean;
  *c50_poseSpeed = c50_b_poseSpeed;
  *c50_poseLeanFlag = c50_b_poseLeanFlag;
}

static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int32_T c50_d_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i6;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i6, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i6;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_sfEvent;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y;
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static uint8_T c50_e_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_b_is_active_c50_Expriment_Gaze, const
  char_T *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_is_active_c50_Expriment_Gaze), &c50_thisId);
  sf_mex_destroy(&c50_b_is_active_c50_Expriment_Gaze);
  return c50_y;
}

static uint8_T c50_f_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static const mxArray *c50_g_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c50_b_setSimStateSideEffectsInfo, const char_T
  *c50_identifier)
{
  const mxArray *c50_y = NULL;
  emlrtMsgIdentifier c50_thisId;
  c50_y = NULL;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  sf_mex_assign(&c50_y, c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_setSimStateSideEffectsInfo), &c50_thisId), false);
  sf_mex_destroy(&c50_b_setSimStateSideEffectsInfo);
  return c50_y;
}

static const mxArray *c50_h_emlrt_marshallIn(SFc50_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  const mxArray *c50_y = NULL;
  (void)chartInstance;
  (void)c50_parentId;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_duplicatearraysafe(&c50_u), false);
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_updateDataWrittenToVector(SFc50_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c50_vectorIndex)
{
  (void)chartInstance;
  c50_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c50_vectorIndex, 0, 16, 1, 0)] = true;
}

static void init_dsm_address_info(SFc50_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c50_Expriment_Gaze_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2749721640U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3641999921U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1773238323U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2043534874U);
}

mxArray *sf_c50_Expriment_Gaze_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YU2ogqfW1FjhZxPs1YuRgB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c50_Expriment_Gaze_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_Expriment_Gaze_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c50_Expriment_Gaze(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c50_Expriment_Gaze\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_Expriment_Gaze_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_Expriment_GazeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc50_Expriment_GazeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_GazeMachineNumber_,
           50,
           2,
           0,
           0,
           30,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_GazeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_GazeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_GazeMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,8,0,0,"");
          _SFD_SET_DATA_PROPS(1,8,0,0,"");
          _SFD_SET_DATA_PROPS(2,9,0,0,"");
          _SFD_SET_DATA_PROPS(3,9,0,0,"");
          _SFD_SET_DATA_PROPS(4,9,0,0,"");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,9,0,0,"");
          _SFD_SET_DATA_PROPS(9,8,0,0,"");
          _SFD_SET_DATA_PROPS(10,9,0,0,"");
          _SFD_SET_DATA_PROPS(11,9,0,0,"");
          _SFD_SET_DATA_PROPS(12,9,0,0,"");
          _SFD_SET_DATA_PROPS(13,9,0,0,"");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_SET_DATA_PROPS(16,9,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,9,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc50_Expriment_Gaze",0,-1,7364);
        _SFD_CV_INIT_EML_IF(0,1,0,3121,3133,-1,5283);
        _SFD_CV_INIT_EML_IF(0,1,1,3142,3150,3845,5273);
        _SFD_CV_INIT_EML_IF(0,1,2,3845,3857,4347,5273);
        _SFD_CV_INIT_EML_IF(0,1,3,4347,4359,4819,5273);
        _SFD_CV_INIT_EML(1,1,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc50_Expriment_Gaze",0,-1,2621);
        _SFD_CV_INIT_EML_IF(1,1,0,574,597,2376,2620);
        _SFD_CV_INIT_EML_IF(1,1,1,610,622,-1,1983);
        _SFD_CV_INIT_EML_IF(1,1,2,635,659,-1,707);
        _SFD_CV_INIT_EML_IF(1,1,3,720,728,1149,1971);
        _SFD_CV_INIT_EML_IF(1,1,4,1149,1161,1451,1971);
        _SFD_CV_INIT_EML_IF(1,1,5,1451,1463,1729,1971);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
          c50_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
          c50_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
            c50_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
          c50_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
          c50_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
            c50_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(1,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(2,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(3,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_GazeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Lnb5n9rbepO8eHdD8kOHGC";
}

static void sf_opaque_initialize_c50_Expriment_Gaze(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
  initialize_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c50_Expriment_Gaze(void *chartInstanceVar)
{
  enable_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c50_Expriment_Gaze(void *chartInstanceVar)
{
  disable_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c50_Expriment_Gaze(void *chartInstanceVar)
{
  sf_gateway_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c50_Expriment_Gaze(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c50_Expriment_Gaze
    ((SFc50_Expriment_GazeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c50_Expriment_Gaze();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c50_Expriment_Gaze(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c50_Expriment_Gaze();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c50_Expriment_Gaze(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c50_Expriment_Gaze(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c50_Expriment_Gaze(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_Expriment_GazeInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Gaze_optimization_info();
    }

    finalize_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_Expriment_Gaze(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c50_Expriment_Gaze((SFc50_Expriment_GazeInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_Expriment_Gaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Gaze_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      50);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,50,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,50,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,50);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,50);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(961649769U));
  ssSetChecksum1(S,(1455410973U));
  ssSetChecksum2(S,(249502709U));
  ssSetChecksum3(S,(4164552895U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_Expriment_Gaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c50_Expriment_Gaze(SimStruct *S)
{
  SFc50_Expriment_GazeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc50_Expriment_GazeInstanceStruct *)utMalloc(sizeof
    (SFc50_Expriment_GazeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_Expriment_GazeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c50_Expriment_Gaze;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c50_Expriment_Gaze;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c50_Expriment_Gaze;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c50_Expriment_Gaze;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c50_Expriment_Gaze;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c50_Expriment_Gaze;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c50_Expriment_Gaze;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c50_Expriment_Gaze;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_Expriment_Gaze;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_Expriment_Gaze;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c50_Expriment_Gaze;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c50_Expriment_Gaze_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_Expriment_Gaze(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_Expriment_Gaze(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_Expriment_Gaze(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_Expriment_Gaze_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
