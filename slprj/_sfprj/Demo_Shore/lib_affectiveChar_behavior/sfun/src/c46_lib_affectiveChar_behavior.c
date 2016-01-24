/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c46_lib_affectiveChar_behavior.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c46_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c46_debug_family_names[18] = { "gaze_custom_flag",
  "mutual_gaze_duration_custom", "avert_gaze_duration_custom",
  "avert_head_frequency_custom", "avert_head_speed_custom", "nargin", "nargout",
  "v", "a", "p", "pFlag", "vaFlag", "gazeArr", "mutDurFactor", "avertDurFactor",
  "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance" };

static const char * c46_b_debug_family_names[21] = { "pose_custom_flag",
  "pose_chance_custom", "pose_selfAdaptor_chance_custom",
  "pose_frequency_custom", "pose_speed_custom", "pose_lean_custom", "nargin",
  "nargout", "v", "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange",
  "poseFreqFactor", "poseChanceFactor", "poseSelfAdaptChance", "poseLean",
  "poseSpeed", "poseLeanFlag" };

static boolean_T c46_dataWrittenToVector[11];

/* Function Declarations */
static void initialize_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c46_update_debugger_state_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_st);
static void c46_set_sim_state_side_effects_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c46_enter_atomic_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c46_enter_internal_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c46_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c46_exit_internal_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c46_initc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c46_machineNumber, uint32_T
  c46_chartNumber, uint32_T c46_instanceNumber);
static const mxArray *c46_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static real_T c46_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static const mxArray *c46_b_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static void c46_b_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId, real_T c46_y[6]);
static void c46_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static const mxArray *c46_c_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static boolean_T c46_c_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static void c46_setGazeFactorsc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c46_v,
   real_T c46_a, real_T c46_p, boolean_T c46_pFlag, boolean_T c46_vaFlag, real_T
   c46_gazeArr[6], real_T *c46_mutDurFactor, real_T *c46_avertDurFactor, real_T *
   c46_avertHeadFreqFactor, real_T *c46_avertHeadSpeed, real_T
   *c46_avertDirsChance);
static void c46_setPoseFactorsc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c46_v,
   real_T c46_ar, real_T c46_p, boolean_T c46_pFlag, boolean_T c46_vaFlag,
   real_T c46_poseArr[6], real_T c46_personalityChange, real_T
   *c46_poseFreqFactor, real_T *c46_poseChanceFactor, real_T
   *c46_poseSelfAdaptChance, real_T *c46_poseLean, real_T *c46_poseSpeed, real_T
   *c46_poseLeanFlag);
static const mxArray *c46_d_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData);
static int32_T c46_d_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData);
static uint8_T c46_e_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_b_is_active_c46_lib_affectiveChar_behavior, const char_T *c46_identifier);
static uint8_T c46_f_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId);
static const mxArray *c46_g_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_b_setSimStateSideEffectsInfo, const char_T *c46_identifier);
static const mxArray *c46_h_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId);
static void c46_updateDataWrittenToVector
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c46_vectorIndex);
static void c46_errorIfDataNotWrittenToFcn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c46_vectorIndex, uint32_T c46_dataNumber);
static void init_dsm_address_info(SFc46_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c46_update_debugger_state_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c46_st;
  const mxArray *c46_y = NULL;
  uint8_T c46_hoistedGlobal;
  uint8_T c46_u;
  const mxArray *c46_b_y = NULL;
  c46_st = NULL;
  c46_st = NULL;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_createcellmatrix(1, 1), false);
  c46_hoistedGlobal =
    chartInstance->c46_is_active_c46_lib_affectiveChar_behavior;
  c46_u = c46_hoistedGlobal;
  c46_b_y = NULL;
  sf_mex_assign(&c46_b_y, sf_mex_create("y", &c46_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c46_y, 0, c46_b_y);
  sf_mex_assign(&c46_st, c46_y, false);
  return c46_st;
}

static void set_sim_state_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_st)
{
  const mxArray *c46_u;
  chartInstance->c46_doneDoubleBufferReInit = true;
  c46_u = sf_mex_dup(c46_st);
  chartInstance->c46_is_active_c46_lib_affectiveChar_behavior =
    c46_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c46_u, 0)),
    "is_active_c46_lib_affectiveChar_behavior");
  sf_mex_assign(&chartInstance->c46_setSimStateSideEffectsInfo,
                c46_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c46_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c46_u);
  chartInstance->c46_doSetSimStateSideEffects = 1U;
  c46_update_debugger_state_c46_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c46_st);
}

static void c46_set_sim_state_side_effects_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c46_doSetSimStateSideEffects != 0) {
    chartInstance->c46_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c46_setSimStateSideEffectsInfo);
}

static void sf_gateway_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c46_set_sim_state_side_effects_c46_lib_affectiveChar_behavior(chartInstance);
}

static void c46_enter_atomic_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c46_sfEvent);
  chartInstance->c46_is_active_c46_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c46_sfEvent);
}

static void c46_enter_internal_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c46_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c46_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c46_sfEvent);
}

static void c46_exit_internal_c46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c46_initc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c46_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c46_doSetSimStateSideEffects = 0U;
  chartInstance->c46_setSimStateSideEffectsInfo = NULL;
  chartInstance->c46_is_active_c46_lib_affectiveChar_behavior = 0U;
}

static void initSimStructsc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c46_machineNumber, uint32_T
  c46_chartNumber, uint32_T c46_instanceNumber)
{
  (void)c46_machineNumber;
  (void)c46_chartNumber;
  (void)c46_instanceNumber;
}

static const mxArray *c46_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  real_T c46_u;
  const mxArray *c46_y = NULL;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_u = *(real_T *)c46_inData;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", &c46_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, false);
  return c46_mxArrayOutData;
}

static real_T c46_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  real_T c46_y;
  real_T c46_d0;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_d0, 1, 0, 0U, 0, 0U, 0);
  c46_y = c46_d0;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void c46_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_avertDirsChance;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  real_T c46_y;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_avertDirsChance = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_avertDirsChance),
    &c46_thisId);
  sf_mex_destroy(&c46_avertDirsChance);
  *(real_T *)c46_outData = c46_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

static const mxArray *c46_b_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_i0;
  real_T c46_b_inData[6];
  int32_T c46_i1;
  real_T c46_u[6];
  const mxArray *c46_y = NULL;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  for (c46_i0 = 0; c46_i0 < 6; c46_i0++) {
    c46_b_inData[c46_i0] = (*(real_T (*)[6])c46_inData)[c46_i0];
  }

  for (c46_i1 = 0; c46_i1 < 6; c46_i1++) {
    c46_u[c46_i1] = c46_b_inData[c46_i1];
  }

  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", c46_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, false);
  return c46_mxArrayOutData;
}

static void c46_b_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId, real_T c46_y[6])
{
  real_T c46_dv0[6];
  int32_T c46_i2;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), c46_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c46_i2 = 0; c46_i2 < 6; c46_i2++) {
    c46_y[c46_i2] = c46_dv0[c46_i2];
  }

  sf_mex_destroy(&c46_u);
}

static void c46_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_gazeArr;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  real_T c46_y[6];
  int32_T c46_i3;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_gazeArr = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_gazeArr), &c46_thisId,
    c46_y);
  sf_mex_destroy(&c46_gazeArr);
  for (c46_i3 = 0; c46_i3 < 6; c46_i3++) {
    (*(real_T (*)[6])c46_outData)[c46_i3] = c46_y[c46_i3];
  }

  sf_mex_destroy(&c46_mxArrayInData);
}

static const mxArray *c46_c_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  boolean_T c46_u;
  const mxArray *c46_y = NULL;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_u = *(boolean_T *)c46_inData;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", &c46_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, false);
  return c46_mxArrayOutData;
}

static boolean_T c46_c_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  boolean_T c46_y;
  boolean_T c46_b0;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_b0, 1, 11, 0U, 0, 0U, 0);
  c46_y = c46_b0;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void c46_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_vaFlag;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  boolean_T c46_y;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_vaFlag = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_vaFlag),
    &c46_thisId);
  sf_mex_destroy(&c46_vaFlag);
  *(boolean_T *)c46_outData = c46_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

const mxArray *sf_c46_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c46_nameCaptureInfo = NULL;
  c46_nameCaptureInfo = NULL;
  sf_mex_assign(&c46_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c46_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec46_lib_affectiveChar_behavior(SimStruct
  *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  return true;
}

void sf_exported_auto_duringc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  c46_c46_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c46_enter_atomic_c46_lib_affectiveChar_behavior(chartInstance);
  c46_enter_internal_c46_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c46_exit_internal_c46_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_gatewayc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc46_lib_affectiveChar_behavior(SimStruct
  *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c46_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc46_lib_affectiveChar_behavior
  (SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc46_lib_affectiveChar_behavior(SimStruct
  *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc46_lib_affectiveChar_behavior(SimStruct
  *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc46_lib_affectiveChar_behavior(SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  c46_initc46_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec46_lib_affectiveChar_behavior
  (SimStruct *c46_S)
{
  const mxArray *c46_out = NULL;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  c46_out = NULL;
  sf_mex_assign(&c46_out,
                sf_internal_get_sim_state_c46_lib_affectiveChar_behavior(c46_S),
                false);
  return c46_out;
}

void sf_exported_auto_setSimstatec46_lib_affectiveChar_behavior(SimStruct *c46_S,
  const mxArray *c46_in)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c46_lib_affectiveChar_behavior(c46_S, sf_mex_dup
    (c46_in));
  sf_mex_destroy(&c46_in);
}

void sf_exported_auto_check_state_inconsistency_c46_lib_affectiveChar_behavior
  (SimStruct *c46_S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c46_setGazeFactorsc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c46_v,
   real_T c46_a, real_T c46_p, boolean_T c46_pFlag, boolean_T c46_vaFlag, real_T
   c46_gazeArr[6], real_T *c46_mutDurFactor, real_T *c46_avertDurFactor, real_T *
   c46_avertHeadFreqFactor, real_T *c46_avertHeadSpeed, real_T
   *c46_avertDirsChance)
{
  uint32_T c46_debug_family_var_map[18];
  real_T c46_gaze_custom_flag;
  real_T c46_mutual_gaze_duration_custom;
  real_T c46_avert_gaze_duration_custom;
  real_T c46_avert_head_frequency_custom;
  real_T c46_avert_head_speed_custom;
  real_T c46_nargin = 6.0;
  real_T c46_nargout = 5.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c46_debug_family_names,
    c46_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_gaze_custom_flag, 0U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_mutual_gaze_duration_custom, 1U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_avert_gaze_duration_custom, 2U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_avert_head_frequency_custom, 3U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_avert_head_speed_custom, 4U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargin, 5U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargout, 6U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_v, 7U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_a, 8U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_p, 9U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pFlag, 10U, c46_c_sf_marshallOut,
    c46_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_vaFlag, 11U, c46_c_sf_marshallOut,
    c46_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_gazeArr, 12U, c46_b_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_mutDurFactor, 13U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_avertDurFactor, 14U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_avertHeadFreqFactor, 15U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_avertHeadSpeed, 16U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_avertDirsChance, 17U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 24);
  c46_gaze_custom_flag = c46_gazeArr[0];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 25);
  c46_mutual_gaze_duration_custom = c46_gazeArr[1];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 26);
  c46_avert_gaze_duration_custom = c46_gazeArr[2];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 27);
  c46_avert_head_frequency_custom = c46_gazeArr[3];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 28);
  c46_avert_head_speed_custom = c46_gazeArr[4];
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 29);
  *c46_avertDirsChance = c46_gazeArr[5];
  c46_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 31);
  *c46_mutDurFactor = 1.0;
  c46_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 32);
  *c46_avertDurFactor = 1.0;
  c46_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 33);
  *c46_avertHeadFreqFactor = 1.0;
  c46_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 34);
  *c46_avertHeadSpeed = 1.0;
  c46_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 35);
  *c46_avertDirsChance = 0.0;
  c46_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 37);
  if (CV_EML_IF(0, 1, 0, c46_gaze_custom_flag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 38);
    if (CV_EML_IF(0, 1, 1, (real_T)c46_pFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 39);
      if (CV_EML_IF(0, 1, 2, c46_p == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 40);
        *c46_mutDurFactor = 0.25;
        c46_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 41);
        *c46_avertDurFactor = 0.1;
        c46_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 42);
        *c46_avertHeadFreqFactor = 3.0;
        c46_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 43);
        *c46_avertHeadSpeed = 2.0;
        c46_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 44);
        *c46_avertDirsChance = 1.0;
        c46_updateDataWrittenToVector(chartInstance, 4U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 45);
        if (CV_EML_IF(0, 1, 3, c46_p == 2.0)) {
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 46);
          *c46_mutDurFactor = 0.1;
          c46_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 47);
          *c46_avertDurFactor = 0.25;
          c46_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 48);
          *c46_avertHeadFreqFactor = 3.0;
          c46_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 49);
          *c46_avertHeadSpeed = 3.0;
          c46_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 50);
          *c46_avertDirsChance = 2.0;
          c46_updateDataWrittenToVector(chartInstance, 4U);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 51);
          if (CV_EML_IF(0, 1, 4, c46_p == 3.0)) {
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 52);
            *c46_mutDurFactor = 0.5;
            c46_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 53);
            *c46_avertDurFactor = 0.25;
            c46_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 54);
            *c46_avertHeadFreqFactor = 0.5;
            c46_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 55);
            *c46_avertHeadSpeed = 2.0;
            c46_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 56);
            *c46_avertDirsChance = 1.0;
            c46_updateDataWrittenToVector(chartInstance, 4U);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 58);
            *c46_mutDurFactor = 0.25;
            c46_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 59);
            *c46_avertDurFactor = 0.5;
            c46_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 60);
            *c46_avertHeadFreqFactor = 0.5;
            c46_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 61);
            *c46_avertHeadSpeed = 3.0;
            c46_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 62);
            *c46_avertDirsChance = 2.0;
            c46_updateDataWrittenToVector(chartInstance, 4U);
          }
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 65);
    if (CV_EML_IF(0, 1, 5, (real_T)c46_vaFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 66);
      guard1 = false;
      if (CV_EML_COND(0, 1, 0, c46_v > 5.0)) {
        if (CV_EML_COND(0, 1, 1, c46_a > 5.0)) {
          CV_EML_MCDC(0, 1, 0, true);
          CV_EML_IF(0, 1, 6, true);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 67);
          c46_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
          *c46_mutDurFactor *= 0.5;
          c46_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 68);
          c46_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          *c46_avertDurFactor *= 0.5;
          c46_updateDataWrittenToVector(chartInstance, 1U);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 6, false);
        _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 69);
        guard2 = false;
        if (CV_EML_COND(0, 1, 2, c46_v < -5.0)) {
          if (CV_EML_COND(0, 1, 3, c46_a > 5.0)) {
            CV_EML_MCDC(0, 1, 1, true);
            CV_EML_IF(0, 1, 7, true);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 70);
            c46_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
            *c46_mutDurFactor *= 0.5;
            c46_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 71);
            c46_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
            *c46_avertDurFactor *= 0.5;
            c46_updateDataWrittenToVector(chartInstance, 1U);
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(0, 1, 1, false);
          CV_EML_IF(0, 1, 7, false);
          _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 72);
          guard3 = false;
          if (CV_EML_COND(0, 1, 4, c46_v > 5.0)) {
            if (CV_EML_COND(0, 1, 5, c46_a < -5.0)) {
              CV_EML_MCDC(0, 1, 2, true);
              CV_EML_IF(0, 1, 8, true);
              _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 73);
              c46_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
              *c46_mutDurFactor *= 0.5;
              c46_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 74);
              c46_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
              *c46_avertDurFactor *= 0.5;
              c46_updateDataWrittenToVector(chartInstance, 1U);
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3 == true) {
            CV_EML_MCDC(0, 1, 2, false);
            CV_EML_IF(0, 1, 8, false);
            _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 75);
            guard4 = false;
            if (CV_EML_COND(0, 1, 6, c46_v < -5.0)) {
              if (CV_EML_COND(0, 1, 7, c46_a < -5.0)) {
                CV_EML_MCDC(0, 1, 3, true);
                CV_EML_IF(0, 1, 9, true);
                _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 76);
                c46_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
                *c46_mutDurFactor *= 0.5;
                c46_updateDataWrittenToVector(chartInstance, 0U);
                _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 77);
                c46_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
                *c46_avertDurFactor *= 0.5;
                c46_updateDataWrittenToVector(chartInstance, 1U);
              } else {
                guard4 = true;
              }
            } else {
              guard4 = true;
            }

            if (guard4 == true) {
              CV_EML_MCDC(0, 1, 3, false);
              CV_EML_IF(0, 1, 9, false);
            }
          }
        }
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 81);
    *c46_mutDurFactor = c46_mutual_gaze_duration_custom;
    c46_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 82);
    *c46_avertDurFactor = c46_avert_gaze_duration_custom;
    c46_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 83);
    *c46_avertHeadFreqFactor = c46_avert_head_frequency_custom;
    c46_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, 84);
    *c46_avertHeadSpeed = c46_avert_head_speed_custom;
    c46_updateDataWrittenToVector(chartInstance, 3U);
  }

  _SFD_EML_CALL(0U, chartInstance->c46_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c46_setPoseFactorsc46_lib_affectiveChar_behavior
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c46_v,
   real_T c46_ar, real_T c46_p, boolean_T c46_pFlag, boolean_T c46_vaFlag,
   real_T c46_poseArr[6], real_T c46_personalityChange, real_T
   *c46_poseFreqFactor, real_T *c46_poseChanceFactor, real_T
   *c46_poseSelfAdaptChance, real_T *c46_poseLean, real_T *c46_poseSpeed, real_T
   *c46_poseLeanFlag)
{
  uint32_T c46_debug_family_var_map[21];
  real_T c46_pose_custom_flag;
  real_T c46_pose_chance_custom;
  real_T c46_pose_selfAdaptor_chance_custom;
  real_T c46_pose_frequency_custom;
  real_T c46_pose_speed_custom;
  real_T c46_pose_lean_custom;
  real_T c46_nargin = 7.0;
  real_T c46_nargout = 6.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c46_b_debug_family_names,
    c46_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pose_custom_flag, 0U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pose_chance_custom, 1U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pose_selfAdaptor_chance_custom, 2U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pose_frequency_custom, 3U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pose_speed_custom, 4U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pose_lean_custom, 5U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargin, 6U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_nargout, 7U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_v, 8U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_ar, 9U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_p, 10U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_pFlag, 11U, c46_c_sf_marshallOut,
    c46_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_vaFlag, 12U, c46_c_sf_marshallOut,
    c46_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseArr, 13U, c46_b_sf_marshallOut,
    c46_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c46_personalityChange, 14U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseFreqFactor, 15U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseChanceFactor, 16U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseSelfAdaptChance, 17U,
    c46_sf_marshallOut, c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseLean, 18U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseSpeed, 19U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c46_poseLeanFlag, 20U, c46_sf_marshallOut,
    c46_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 2);
  c46_pose_custom_flag = c46_poseArr[0];
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 3);
  c46_pose_chance_custom = c46_poseArr[1];
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 4);
  c46_pose_selfAdaptor_chance_custom = c46_poseArr[2];
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 5);
  c46_pose_frequency_custom = c46_poseArr[3];
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 6);
  c46_pose_speed_custom = c46_poseArr[4];
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 7);
  c46_pose_lean_custom = c46_poseArr[5];
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 9);
  *c46_poseSelfAdaptChance = 10.0;
  c46_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 10);
  *c46_poseChanceFactor = 1.0;
  c46_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 11);
  *c46_poseFreqFactor = 5.0;
  c46_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 12);
  *c46_poseSpeed = 0.0;
  c46_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 13);
  *c46_poseLean = 10.0;
  c46_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 15);
  *c46_poseLeanFlag = 0.0;
  c46_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 17);
  if (CV_EML_IF(1, 1, 0, c46_pose_custom_flag == 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 18);
    if (CV_EML_IF(1, 1, 1, (real_T)c46_pFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 19);
      if (CV_EML_IF(1, 1, 2, c46_personalityChange == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 20);
        *c46_poseLeanFlag = 1.0;
        c46_updateDataWrittenToVector(chartInstance, 10U);
      }

      _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 22);
      if (CV_EML_IF(1, 1, 3, c46_p == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 23);
        *c46_poseFreqFactor = 5.0;
        c46_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 24);
        *c46_poseLean = 10.0;
        c46_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 25);
        *c46_poseChanceFactor = 1.0;
        c46_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 26);
        *c46_poseSelfAdaptChance = 10.0;
        c46_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 27);
        *c46_poseSpeed = 1.0;
        c46_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 28);
        if (CV_EML_IF(1, 1, 4, c46_p == 2.0)) {
          _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 29);
          *c46_poseFreqFactor = 20.0;
          c46_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 30);
          *c46_poseLean = 11.0;
          c46_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 31);
          *c46_poseChanceFactor = 2.0;
          c46_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 32);
          *c46_poseSelfAdaptChance = 10.0;
          c46_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 33);
          *c46_poseSpeed = 2.0;
          c46_updateDataWrittenToVector(chartInstance, 9U);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 34);
          if (CV_EML_IF(1, 1, 5, c46_p == 3.0)) {
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 35);
            *c46_poseFreqFactor = 20.0;
            c46_updateDataWrittenToVector(chartInstance, 5U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 36);
            *c46_poseLean = 10.0;
            c46_updateDataWrittenToVector(chartInstance, 8U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 37);
            *c46_poseChanceFactor = 0.25;
            c46_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 38);
            *c46_poseSelfAdaptChance = 20.0;
            c46_updateDataWrittenToVector(chartInstance, 7U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 39);
            *c46_poseSpeed = 1.0;
            c46_updateDataWrittenToVector(chartInstance, 9U);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 41);
            *c46_poseFreqFactor = 30.0;
            c46_updateDataWrittenToVector(chartInstance, 5U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 42);
            *c46_poseLean = 11.0;
            c46_updateDataWrittenToVector(chartInstance, 8U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 43);
            *c46_poseChanceFactor = 1.0;
            c46_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 44);
            *c46_poseSelfAdaptChance = 20.0;
            c46_updateDataWrittenToVector(chartInstance, 7U);
            _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 45);
            *c46_poseSpeed = 2.0;
            c46_updateDataWrittenToVector(chartInstance, 9U);
          }
        }
      }
    }

    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 48);
    if (CV_EML_IF(1, 1, 6, (real_T)c46_vaFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 49);
      if (CV_EML_IF(1, 1, 7, c46_ar > 5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 50);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 5U, 11U);
        *c46_poseFreqFactor *= 1.2;
        c46_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 51);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 6U, 12U);
        *c46_poseChanceFactor *= 1.1;
        c46_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 52);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 7U, 13U);
        *c46_poseSelfAdaptChance += 2.0;
        c46_updateDataWrittenToVector(chartInstance, 7U);
      }

      _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 54);
      if (CV_EML_IF(1, 1, 8, c46_ar < -5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 55);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 5U, 11U);
        *c46_poseFreqFactor *= 1.3;
        c46_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 56);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 6U, 12U);
        *c46_poseChanceFactor *= 1.1;
        c46_updateDataWrittenToVector(chartInstance, 6U);
      }

      _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 58);
      if (CV_EML_IF(1, 1, 9, c46_v > 5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 59);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 7U, 13U);
        *c46_poseSelfAdaptChance -= 2.0;
        c46_updateDataWrittenToVector(chartInstance, 7U);
      }

      _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 61);
      if (CV_EML_IF(1, 1, 10, c46_v < -5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 62);
        c46_errorIfDataNotWrittenToFcn(chartInstance, 7U, 13U);
        *c46_poseSelfAdaptChance += 2.0;
        c46_updateDataWrittenToVector(chartInstance, 7U);
      }
    }
  } else {
    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 66);
    *c46_poseFreqFactor = c46_pose_frequency_custom;
    c46_updateDataWrittenToVector(chartInstance, 5U);
    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 67);
    *c46_poseLean = c46_pose_lean_custom;
    c46_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 68);
    *c46_poseChanceFactor = c46_pose_chance_custom;
    c46_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 69);
    *c46_poseSelfAdaptChance = c46_pose_selfAdaptor_chance_custom;
    c46_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, 70);
    *c46_poseSpeed = c46_pose_speed_custom;
    c46_updateDataWrittenToVector(chartInstance, 9U);
  }

  _SFD_EML_CALL(1U, chartInstance->c46_sfEvent, -70);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c46_lib_affectiveChar_behavior_setGazeFactors(SimStruct
  *c46_S, real_T c46_v, real_T c46_a, real_T c46_p, boolean_T c46_pFlag,
  boolean_T c46_vaFlag, real_T c46_gazeArr[6], real_T *c46_mutDurFactor, real_T *
  c46_avertDurFactor, real_T *c46_avertHeadFreqFactor, real_T
  *c46_avertHeadSpeed, real_T *c46_avertDirsChance)
{
  int32_T c46_i4;
  real_T c46_b_gazeArr[6];
  real_T c46_b_avertDirsChance;
  real_T c46_b_avertHeadSpeed;
  real_T c46_b_avertHeadFreqFactor;
  real_T c46_b_avertDurFactor;
  real_T c46_b_mutDurFactor;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  for (c46_i4 = 0; c46_i4 < 6; c46_i4++) {
    c46_b_gazeArr[c46_i4] = c46_gazeArr[c46_i4];
  }

  c46_setGazeFactorsc46_lib_affectiveChar_behavior(chartInstance, c46_v, c46_a,
    c46_p, c46_pFlag, c46_vaFlag, c46_b_gazeArr, &c46_b_mutDurFactor,
    &c46_b_avertDurFactor, &c46_b_avertHeadFreqFactor, &c46_b_avertHeadSpeed,
    &c46_b_avertDirsChance);
  *c46_mutDurFactor = c46_b_mutDurFactor;
  *c46_avertDurFactor = c46_b_avertDurFactor;
  *c46_avertHeadFreqFactor = c46_b_avertHeadFreqFactor;
  *c46_avertHeadSpeed = c46_b_avertHeadSpeed;
  *c46_avertDirsChance = c46_b_avertDirsChance;
}

void sf_exported_user_c46_lib_affectiveChar_behavior_setPoseFactors(SimStruct
  *c46_S, real_T c46_v, real_T c46_ar, real_T c46_p, boolean_T c46_pFlag,
  boolean_T c46_vaFlag, real_T c46_poseArr[6], real_T c46_personalityChange,
  real_T *c46_poseFreqFactor, real_T *c46_poseChanceFactor, real_T
  *c46_poseSelfAdaptChance, real_T *c46_poseLean, real_T *c46_poseSpeed, real_T *
  c46_poseLeanFlag)
{
  int32_T c46_i5;
  real_T c46_b_poseArr[6];
  real_T c46_b_poseLeanFlag;
  real_T c46_b_poseSpeed;
  real_T c46_b_poseLean;
  real_T c46_b_poseSelfAdaptChance;
  real_T c46_b_poseChanceFactor;
  real_T c46_b_poseFreqFactor;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c46_S))->instanceInfo)
    ->chartInstance;
  for (c46_i5 = 0; c46_i5 < 6; c46_i5++) {
    c46_b_poseArr[c46_i5] = c46_poseArr[c46_i5];
  }

  c46_setPoseFactorsc46_lib_affectiveChar_behavior(chartInstance, c46_v, c46_ar,
    c46_p, c46_pFlag, c46_vaFlag, c46_b_poseArr, c46_personalityChange,
    &c46_b_poseFreqFactor, &c46_b_poseChanceFactor, &c46_b_poseSelfAdaptChance,
    &c46_b_poseLean, &c46_b_poseSpeed, &c46_b_poseLeanFlag);
  *c46_poseFreqFactor = c46_b_poseFreqFactor;
  *c46_poseChanceFactor = c46_b_poseChanceFactor;
  *c46_poseSelfAdaptChance = c46_b_poseSelfAdaptChance;
  *c46_poseLean = c46_b_poseLean;
  *c46_poseSpeed = c46_b_poseSpeed;
  *c46_poseLeanFlag = c46_b_poseLeanFlag;
}

static const mxArray *c46_d_sf_marshallOut(void *chartInstanceVoid, void
  *c46_inData)
{
  const mxArray *c46_mxArrayOutData = NULL;
  int32_T c46_u;
  const mxArray *c46_y = NULL;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_mxArrayOutData = NULL;
  c46_u = *(int32_T *)c46_inData;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_create("y", &c46_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c46_mxArrayOutData, c46_y, false);
  return c46_mxArrayOutData;
}

static int32_T c46_d_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  int32_T c46_y;
  int32_T c46_i6;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_i6, 1, 6, 0U, 0, 0U, 0);
  c46_y = c46_i6;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void c46_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c46_mxArrayInData, const char_T *c46_varName, void *c46_outData)
{
  const mxArray *c46_b_sfEvent;
  const char_T *c46_identifier;
  emlrtMsgIdentifier c46_thisId;
  int32_T c46_y;
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c46_b_sfEvent = sf_mex_dup(c46_mxArrayInData);
  c46_identifier = c46_varName;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c46_b_sfEvent),
    &c46_thisId);
  sf_mex_destroy(&c46_b_sfEvent);
  *(int32_T *)c46_outData = c46_y;
  sf_mex_destroy(&c46_mxArrayInData);
}

static uint8_T c46_e_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_b_is_active_c46_lib_affectiveChar_behavior, const char_T *c46_identifier)
{
  uint8_T c46_y;
  emlrtMsgIdentifier c46_thisId;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  c46_y = c46_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c46_b_is_active_c46_lib_affectiveChar_behavior), &c46_thisId);
  sf_mex_destroy(&c46_b_is_active_c46_lib_affectiveChar_behavior);
  return c46_y;
}

static uint8_T c46_f_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  uint8_T c46_y;
  uint8_T c46_u0;
  (void)chartInstance;
  sf_mex_import(c46_parentId, sf_mex_dup(c46_u), &c46_u0, 1, 3, 0U, 0, 0U, 0);
  c46_y = c46_u0;
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static const mxArray *c46_g_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_b_setSimStateSideEffectsInfo, const char_T *c46_identifier)
{
  const mxArray *c46_y = NULL;
  emlrtMsgIdentifier c46_thisId;
  c46_y = NULL;
  c46_thisId.fIdentifier = c46_identifier;
  c46_thisId.fParent = NULL;
  sf_mex_assign(&c46_y, c46_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c46_b_setSimStateSideEffectsInfo), &c46_thisId), false);
  sf_mex_destroy(&c46_b_setSimStateSideEffectsInfo);
  return c46_y;
}

static const mxArray *c46_h_emlrt_marshallIn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c46_u, const emlrtMsgIdentifier *c46_parentId)
{
  const mxArray *c46_y = NULL;
  (void)chartInstance;
  (void)c46_parentId;
  c46_y = NULL;
  sf_mex_assign(&c46_y, sf_mex_duplicatearraysafe(&c46_u), false);
  sf_mex_destroy(&c46_u);
  return c46_y;
}

static void c46_updateDataWrittenToVector
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c46_vectorIndex)
{
  (void)chartInstance;
  c46_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c46_vectorIndex, 0, 10, 1, 0)] = true;
}

static void c46_errorIfDataNotWrittenToFcn
  (SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c46_vectorIndex, uint32_T c46_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c46_dataNumber, c46_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c46_vectorIndex, 0, 10, 1,
    0)]);
}

static void init_dsm_address_info(SFc46_lib_affectiveChar_behaviorInstanceStruct
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

void sf_c46_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3162552718U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2896652733U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(944852690U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(170394654U);
}

mxArray *sf_c46_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bAqBzZseVKKGhyRLdfvtNE");
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

mxArray *sf_c46_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c46_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c46_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c46_lib_affectiveChar_behavior\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c46_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           46,
           2,
           0,
           0,
           24,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_lib_affectiveChar_behaviorMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _lib_affectiveChar_behaviorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lib_affectiveChar_behaviorMachineNumber_,
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
          _SFD_SET_DATA_PROPS(15,8,0,0,"");
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,8,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
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
        _SFD_CV_INIT_EML(0,1,1,10,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc46_lib_affectiveChar_behavior",
                             0,-1,4141);
        _SFD_CV_INIT_EML_IF(0,1,0,2373,2396,3928,4141);
        _SFD_CV_INIT_EML_IF(0,1,1,2401,2413,-1,3355);
        _SFD_CV_INIT_EML_IF(0,1,2,2422,2430,2673,3345);
        _SFD_CV_INIT_EML_IF(0,1,3,2673,2685,2913,3345);
        _SFD_CV_INIT_EML_IF(0,1,4,2913,2925,3137,3345);
        _SFD_CV_INIT_EML_IF(0,1,5,3360,3373,-1,3924);
        _SFD_CV_INIT_EML_IF(0,1,6,3382,3396,3511,3530);
        _SFD_CV_INIT_EML_IF(0,1,7,3511,3530,3645,3916);
        _SFD_CV_INIT_EML_IF(0,1,8,3645,3664,3780,3916);
        _SFD_CV_INIT_EML_IF(0,1,9,3780,3800,-1,3800);

        {
          static int condStart[] = { 3385, 3392 };

          static int condEnd[] = { 3388, 3395 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,3385,3395,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3518, 3526 };

          static int condEnd[] = { 3522, 3529 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,3518,3529,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3652, 3659 };

          static int condEnd[] = { 3655, 3663 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,3652,3663,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3787, 3795 };

          static int condEnd[] = { 3791, 3799 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,3787,3799,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,1,1,11,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc46_lib_affectiveChar_behavior",
                             0,-1,2120);
        _SFD_CV_INIT_EML_IF(1,1,0,499,522,1893,2119);
        _SFD_CV_INIT_EML_IF(1,1,1,531,543,-1,1377);
        _SFD_CV_INIT_EML_IF(1,1,2,552,576,-1,616);
        _SFD_CV_INIT_EML_IF(1,1,3,625,633,802,1369);
        _SFD_CV_INIT_EML_IF(1,1,4,802,814,1009,1369);
        _SFD_CV_INIT_EML_IF(1,1,5,1009,1021,1193,1369);
        _SFD_CV_INIT_EML_IF(1,1,6,1382,1395,-1,1892);
        _SFD_CV_INIT_EML_IF(1,1,7,1404,1413,-1,1584);
        _SFD_CV_INIT_EML_IF(1,1,8,1593,1602,-1,1717);
        _SFD_CV_INIT_EML_IF(1,1,9,1726,1733,-1,1800);
        _SFD_CV_INIT_EML_IF(1,1,10,1809,1817,-1,1884);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_c_sf_marshallOut,(MexInFcnForType)
          c46_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_c_sf_marshallOut,(MexInFcnForType)
          c46_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_b_sf_marshallOut,(MexInFcnForType)
            c46_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_c_sf_marshallOut,(MexInFcnForType)
          c46_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_c_sf_marshallOut,(MexInFcnForType)
          c46_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c46_b_sf_marshallOut,(MexInFcnForType)
            c46_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c46_sf_marshallOut,(MexInFcnForType)c46_sf_marshallIn);
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
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lib_affectiveChar_behaviorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GiVpF02MWU7HTb4hOOstBF";
}

static void sf_opaque_initialize_c46_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc46_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c46_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c46_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c46_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c46_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c46_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c46_lib_affectiveChar_behavior(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c46_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c46_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c46_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c46_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc46_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c46_lib_affectiveChar_behavior
      ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc46_lib_affectiveChar_behavior
    ((SFc46_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c46_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c46_lib_affectiveChar_behavior
      ((SFc46_lib_affectiveChar_behaviorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c46_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      46);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,46,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,46,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,46);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,46);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1196276417U));
  ssSetChecksum1(S,(3823594201U));
  ssSetChecksum2(S,(3531072073U));
  ssSetChecksum3(S,(1100753767U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c46_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c46_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc46_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc46_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc46_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc46_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c46_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c46_lib_affectiveChar_behavior;
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

void c46_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c46_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c46_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c46_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c46_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
