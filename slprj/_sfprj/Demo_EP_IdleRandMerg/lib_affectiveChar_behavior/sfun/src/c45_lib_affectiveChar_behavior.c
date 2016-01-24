/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c45_lib_affectiveChar_behavior.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c45_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c45_debug_family_names[18] = { "gaze_custom_flag",
  "mutual_gaze_duration_custom", "avert_gaze_duration_custom",
  "avert_head_frequency_custom", "avert_head_speed_custom", "nargin", "nargout",
  "v", "a", "p", "pFlag", "vaFlag", "gazeArr", "mutDurFactor", "avertDurFactor",
  "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance" };

static boolean_T c45_dataWrittenToVector[5];

/* Function Declarations */
static void initialize_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c45_update_debugger_state_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_st);
static void c45_set_sim_state_side_effects_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c45_enter_atomic_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c45_enter_internal_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c45_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c45_exit_internal_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c45_initc45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber);
static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static real_T c45_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static void c45_b_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId, real_T c45_y[6]);
static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static boolean_T c45_c_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static void c45_setGazeFactorsc45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c45_v,
   real_T c45_a, real_T c45_p, boolean_T c45_pFlag, boolean_T c45_vaFlag, real_T
   c45_gazeArr[6], real_T *c45_mutDurFactor, real_T *c45_avertDurFactor, real_T *
   c45_avertHeadFreqFactor, real_T *c45_avertHeadSpeed, real_T
   *c45_avertDirsChance);
static const mxArray *c45_d_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static int32_T c45_d_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static uint8_T c45_e_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_b_is_active_c45_lib_affectiveChar_behavior, const char_T *c45_identifier);
static uint8_T c45_f_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId);
static const mxArray *c45_g_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_b_setSimStateSideEffectsInfo, const char_T *c45_identifier);
static const mxArray *c45_h_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_updateDataWrittenToVector
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c45_vectorIndex);
static void c45_errorIfDataNotWrittenToFcn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c45_vectorIndex, uint32_T c45_dataNumber);
static void init_dsm_address_info(SFc45_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c45_update_debugger_state_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c45_st;
  const mxArray *c45_y = NULL;
  uint8_T c45_hoistedGlobal;
  uint8_T c45_u;
  const mxArray *c45_b_y = NULL;
  c45_st = NULL;
  c45_st = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_createcellmatrix(1, 1), false);
  c45_hoistedGlobal =
    chartInstance->c45_is_active_c45_lib_affectiveChar_behavior;
  c45_u = c45_hoistedGlobal;
  c45_b_y = NULL;
  sf_mex_assign(&c45_b_y, sf_mex_create("y", &c45_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 0, c45_b_y);
  sf_mex_assign(&c45_st, c45_y, false);
  return c45_st;
}

static void set_sim_state_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_st)
{
  const mxArray *c45_u;
  chartInstance->c45_doneDoubleBufferReInit = true;
  c45_u = sf_mex_dup(c45_st);
  chartInstance->c45_is_active_c45_lib_affectiveChar_behavior =
    c45_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 0)),
    "is_active_c45_lib_affectiveChar_behavior");
  sf_mex_assign(&chartInstance->c45_setSimStateSideEffectsInfo,
                c45_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c45_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c45_u);
  chartInstance->c45_doSetSimStateSideEffects = 1U;
  c45_update_debugger_state_c45_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c45_st);
}

static void c45_set_sim_state_side_effects_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c45_doSetSimStateSideEffects != 0) {
    chartInstance->c45_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c45_setSimStateSideEffectsInfo);
}

static void sf_gateway_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c45_set_sim_state_side_effects_c45_lib_affectiveChar_behavior(chartInstance);
}

static void c45_enter_atomic_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c45_sfEvent);
  chartInstance->c45_is_active_c45_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c45_sfEvent);
}

static void c45_enter_internal_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c45_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c45_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c45_sfEvent);
}

static void c45_exit_internal_c45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c45_initc45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c45_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c45_doSetSimStateSideEffects = 0U;
  chartInstance->c45_setSimStateSideEffectsInfo = NULL;
  chartInstance->c45_is_active_c45_lib_affectiveChar_behavior = 0U;
}

static void initSimStructsc45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber)
{
  (void)c45_machineNumber;
  (void)c45_chartNumber;
  (void)c45_instanceNumber;
}

static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  real_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(real_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static real_T c45_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  real_T c45_y;
  real_T c45_d0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_d0, 1, 0, 0U, 0, 0U, 0);
  c45_y = c45_d0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_avertDirsChance;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_y;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_avertDirsChance = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_avertDirsChance),
    &c45_thisId);
  sf_mex_destroy(&c45_avertDirsChance);
  *(real_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_i0;
  real_T c45_b_inData[6];
  int32_T c45_i1;
  real_T c45_u[6];
  const mxArray *c45_y = NULL;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  for (c45_i0 = 0; c45_i0 < 6; c45_i0++) {
    c45_b_inData[c45_i0] = (*(real_T (*)[6])c45_inData)[c45_i0];
  }

  for (c45_i1 = 0; c45_i1 < 6; c45_i1++) {
    c45_u[c45_i1] = c45_b_inData[c45_i1];
  }

  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", c45_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static void c45_b_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId, real_T c45_y[6])
{
  real_T c45_dv0[6];
  int32_T c45_i2;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), c45_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c45_i2 = 0; c45_i2 < 6; c45_i2++) {
    c45_y[c45_i2] = c45_dv0[c45_i2];
  }

  sf_mex_destroy(&c45_u);
}

static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_gazeArr;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_y[6];
  int32_T c45_i3;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_gazeArr = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_gazeArr), &c45_thisId,
    c45_y);
  sf_mex_destroy(&c45_gazeArr);
  for (c45_i3 = 0; c45_i3 < 6; c45_i3++) {
    (*(real_T (*)[6])c45_outData)[c45_i3] = c45_y[c45_i3];
  }

  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  boolean_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(boolean_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static boolean_T c45_c_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  boolean_T c45_y;
  boolean_T c45_b0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_b0, 1, 11, 0U, 0, 0U, 0);
  c45_y = c45_b0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_vaFlag;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  boolean_T c45_y;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_vaFlag = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_vaFlag),
    &c45_thisId);
  sf_mex_destroy(&c45_vaFlag);
  *(boolean_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

const mxArray *sf_c45_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c45_nameCaptureInfo = NULL;
  c45_nameCaptureInfo = NULL;
  sf_mex_assign(&c45_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c45_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec45_lib_affectiveChar_behavior(SimStruct
  *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  return true;
}

void sf_exported_auto_duringc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  c45_c45_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c45_enter_atomic_c45_lib_affectiveChar_behavior(chartInstance);
  c45_enter_internal_c45_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c45_exit_internal_c45_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_gatewayc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc45_lib_affectiveChar_behavior(SimStruct
  *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c45_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc45_lib_affectiveChar_behavior
  (SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc45_lib_affectiveChar_behavior(SimStruct
  *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc45_lib_affectiveChar_behavior(SimStruct
  *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc45_lib_affectiveChar_behavior(SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  c45_initc45_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec45_lib_affectiveChar_behavior
  (SimStruct *c45_S)
{
  const mxArray *c45_out = NULL;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  c45_out = NULL;
  sf_mex_assign(&c45_out,
                sf_internal_get_sim_state_c45_lib_affectiveChar_behavior(c45_S),
                false);
  return c45_out;
}

void sf_exported_auto_setSimstatec45_lib_affectiveChar_behavior(SimStruct *c45_S,
  const mxArray *c45_in)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c45_lib_affectiveChar_behavior(c45_S, sf_mex_dup
    (c45_in));
  sf_mex_destroy(&c45_in);
}

void sf_exported_auto_check_state_inconsistency_c45_lib_affectiveChar_behavior
  (SimStruct *c45_S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c45_setGazeFactorsc45_lib_affectiveChar_behavior
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c45_v,
   real_T c45_a, real_T c45_p, boolean_T c45_pFlag, boolean_T c45_vaFlag, real_T
   c45_gazeArr[6], real_T *c45_mutDurFactor, real_T *c45_avertDurFactor, real_T *
   c45_avertHeadFreqFactor, real_T *c45_avertHeadSpeed, real_T
   *c45_avertDirsChance)
{
  uint32_T c45_debug_family_var_map[18];
  real_T c45_gaze_custom_flag;
  real_T c45_mutual_gaze_duration_custom;
  real_T c45_avert_gaze_duration_custom;
  real_T c45_avert_head_frequency_custom;
  real_T c45_avert_head_speed_custom;
  real_T c45_nargin = 6.0;
  real_T c45_nargout = 5.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c45_debug_family_names,
    c45_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_gaze_custom_flag, 0U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_mutual_gaze_duration_custom, 1U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_avert_gaze_duration_custom, 2U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_avert_head_frequency_custom, 3U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_avert_head_speed_custom, 4U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargin, 5U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargout, 6U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_v, 7U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_a, 8U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_p, 9U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_pFlag, 10U, c45_c_sf_marshallOut,
    c45_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_vaFlag, 11U, c45_c_sf_marshallOut,
    c45_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_gazeArr, 12U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_mutDurFactor, 13U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_avertDurFactor, 14U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_avertHeadFreqFactor, 15U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_avertHeadSpeed, 16U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c45_avertDirsChance, 17U,
    c45_sf_marshallOut, c45_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 24);
  c45_gaze_custom_flag = c45_gazeArr[0];
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 25);
  c45_mutual_gaze_duration_custom = c45_gazeArr[1];
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 26);
  c45_avert_gaze_duration_custom = c45_gazeArr[2];
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 27);
  c45_avert_head_frequency_custom = c45_gazeArr[3];
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 28);
  c45_avert_head_speed_custom = c45_gazeArr[4];
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 29);
  *c45_avertDirsChance = c45_gazeArr[5];
  c45_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 31);
  *c45_mutDurFactor = 1.0;
  c45_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 32);
  *c45_avertDurFactor = 1.0;
  c45_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 33);
  *c45_avertHeadFreqFactor = 1.0;
  c45_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 34);
  *c45_avertHeadSpeed = 1.0;
  c45_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 35);
  *c45_avertDirsChance = 0.0;
  c45_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 37);
  if (CV_EML_IF(0, 1, 0, c45_gaze_custom_flag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 38);
    if (CV_EML_IF(0, 1, 1, (real_T)c45_pFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 39);
      if (CV_EML_IF(0, 1, 2, c45_p == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 40);
        *c45_mutDurFactor = 0.25;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 41);
        *c45_avertDurFactor = 0.1;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 42);
        *c45_avertHeadFreqFactor = 3.0;
        c45_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 43);
        *c45_avertHeadSpeed = 2.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 44);
        *c45_avertDirsChance = 1.0;
        c45_updateDataWrittenToVector(chartInstance, 4U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 45);
        if (CV_EML_IF(0, 1, 3, c45_p == 2.0)) {
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 46);
          *c45_mutDurFactor = 0.1;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 47);
          *c45_avertDurFactor = 0.25;
          c45_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 48);
          *c45_avertHeadFreqFactor = 3.0;
          c45_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 49);
          *c45_avertHeadSpeed = 3.0;
          c45_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 50);
          *c45_avertDirsChance = 2.0;
          c45_updateDataWrittenToVector(chartInstance, 4U);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 51);
          if (CV_EML_IF(0, 1, 4, c45_p == 3.0)) {
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 52);
            *c45_mutDurFactor = 0.5;
            c45_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 53);
            *c45_avertDurFactor = 0.25;
            c45_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 54);
            *c45_avertHeadFreqFactor = 0.5;
            c45_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 55);
            *c45_avertHeadSpeed = 2.0;
            c45_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 56);
            *c45_avertDirsChance = 1.0;
            c45_updateDataWrittenToVector(chartInstance, 4U);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 58);
            *c45_mutDurFactor = 0.25;
            c45_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 59);
            *c45_avertDurFactor = 0.5;
            c45_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 60);
            *c45_avertHeadFreqFactor = 0.5;
            c45_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 61);
            *c45_avertHeadSpeed = 3.0;
            c45_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 62);
            *c45_avertDirsChance = 2.0;
            c45_updateDataWrittenToVector(chartInstance, 4U);
          }
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 65);
    if (CV_EML_IF(0, 1, 5, (real_T)c45_vaFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 66);
      guard1 = false;
      if (CV_EML_COND(0, 1, 0, c45_v > 5.0)) {
        if (CV_EML_COND(0, 1, 1, c45_a > 5.0)) {
          CV_EML_MCDC(0, 1, 0, true);
          CV_EML_IF(0, 1, 6, true);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 67);
          c45_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
          *c45_mutDurFactor *= 0.5;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 68);
          c45_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          *c45_avertDurFactor *= 0.5;
          c45_updateDataWrittenToVector(chartInstance, 1U);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 6, false);
        _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 69);
        guard2 = false;
        if (CV_EML_COND(0, 1, 2, c45_v < -5.0)) {
          if (CV_EML_COND(0, 1, 3, c45_a > 5.0)) {
            CV_EML_MCDC(0, 1, 1, true);
            CV_EML_IF(0, 1, 7, true);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 70);
            c45_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
            *c45_mutDurFactor *= 0.5;
            c45_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 71);
            c45_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
            *c45_avertDurFactor *= 0.5;
            c45_updateDataWrittenToVector(chartInstance, 1U);
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(0, 1, 1, false);
          CV_EML_IF(0, 1, 7, false);
          _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 72);
          guard3 = false;
          if (CV_EML_COND(0, 1, 4, c45_v > 5.0)) {
            if (CV_EML_COND(0, 1, 5, c45_a < -5.0)) {
              CV_EML_MCDC(0, 1, 2, true);
              CV_EML_IF(0, 1, 8, true);
              _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 73);
              c45_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
              *c45_mutDurFactor *= 0.5;
              c45_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 74);
              c45_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
              *c45_avertDurFactor *= 0.5;
              c45_updateDataWrittenToVector(chartInstance, 1U);
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3 == true) {
            CV_EML_MCDC(0, 1, 2, false);
            CV_EML_IF(0, 1, 8, false);
            _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 75);
            guard4 = false;
            if (CV_EML_COND(0, 1, 6, c45_v < -5.0)) {
              if (CV_EML_COND(0, 1, 7, c45_a < -5.0)) {
                CV_EML_MCDC(0, 1, 3, true);
                CV_EML_IF(0, 1, 9, true);
                _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 76);
                c45_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
                *c45_mutDurFactor *= 0.5;
                c45_updateDataWrittenToVector(chartInstance, 0U);
                _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 77);
                c45_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
                *c45_avertDurFactor *= 0.5;
                c45_updateDataWrittenToVector(chartInstance, 1U);
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
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 81);
    *c45_mutDurFactor = c45_mutual_gaze_duration_custom;
    c45_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 82);
    *c45_avertDurFactor = c45_avert_gaze_duration_custom;
    c45_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 83);
    *c45_avertHeadFreqFactor = c45_avert_head_frequency_custom;
    c45_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, 84);
    *c45_avertHeadSpeed = c45_avert_head_speed_custom;
    c45_updateDataWrittenToVector(chartInstance, 3U);
  }

  _SFD_EML_CALL(0U, chartInstance->c45_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c45_lib_affectiveChar_behavior_setGazeFactors(SimStruct
  *c45_S, real_T c45_v, real_T c45_a, real_T c45_p, boolean_T c45_pFlag,
  boolean_T c45_vaFlag, real_T c45_gazeArr[6], real_T *c45_mutDurFactor, real_T *
  c45_avertDurFactor, real_T *c45_avertHeadFreqFactor, real_T
  *c45_avertHeadSpeed, real_T *c45_avertDirsChance)
{
  int32_T c45_i4;
  real_T c45_b_gazeArr[6];
  real_T c45_b_avertDirsChance;
  real_T c45_b_avertHeadSpeed;
  real_T c45_b_avertHeadFreqFactor;
  real_T c45_b_avertDurFactor;
  real_T c45_b_mutDurFactor;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c45_S))->instanceInfo)
    ->chartInstance;
  for (c45_i4 = 0; c45_i4 < 6; c45_i4++) {
    c45_b_gazeArr[c45_i4] = c45_gazeArr[c45_i4];
  }

  c45_setGazeFactorsc45_lib_affectiveChar_behavior(chartInstance, c45_v, c45_a,
    c45_p, c45_pFlag, c45_vaFlag, c45_b_gazeArr, &c45_b_mutDurFactor,
    &c45_b_avertDurFactor, &c45_b_avertHeadFreqFactor, &c45_b_avertHeadSpeed,
    &c45_b_avertDirsChance);
  *c45_mutDurFactor = c45_b_mutDurFactor;
  *c45_avertDurFactor = c45_b_avertDurFactor;
  *c45_avertHeadFreqFactor = c45_b_avertHeadFreqFactor;
  *c45_avertHeadSpeed = c45_b_avertHeadSpeed;
  *c45_avertDirsChance = c45_b_avertDirsChance;
}

static const mxArray *c45_d_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(int32_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static int32_T c45_d_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  int32_T c45_y;
  int32_T c45_i5;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_i5, 1, 6, 0U, 0, 0U, 0);
  c45_y = c45_i5;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_sfEvent;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y;
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c45_b_sfEvent = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_sfEvent),
    &c45_thisId);
  sf_mex_destroy(&c45_b_sfEvent);
  *(int32_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static uint8_T c45_e_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_b_is_active_c45_lib_affectiveChar_behavior, const char_T *c45_identifier)
{
  uint8_T c45_y;
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_is_active_c45_lib_affectiveChar_behavior), &c45_thisId);
  sf_mex_destroy(&c45_b_is_active_c45_lib_affectiveChar_behavior);
  return c45_y;
}

static uint8_T c45_f_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  uint8_T c45_y;
  uint8_T c45_u0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_u0, 1, 3, 0U, 0, 0U, 0);
  c45_y = c45_u0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static const mxArray *c45_g_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_b_setSimStateSideEffectsInfo, const char_T *c45_identifier)
{
  const mxArray *c45_y = NULL;
  emlrtMsgIdentifier c45_thisId;
  c45_y = NULL;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  sf_mex_assign(&c45_y, c45_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_setSimStateSideEffectsInfo), &c45_thisId), false);
  sf_mex_destroy(&c45_b_setSimStateSideEffectsInfo);
  return c45_y;
}

static const mxArray *c45_h_emlrt_marshallIn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  const mxArray *c45_y = NULL;
  (void)chartInstance;
  (void)c45_parentId;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_duplicatearraysafe(&c45_u), false);
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_updateDataWrittenToVector
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c45_vectorIndex)
{
  (void)chartInstance;
  c45_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c45_vectorIndex, 0, 4, 1, 0)] = true;
}

static void c45_errorIfDataNotWrittenToFcn
  (SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c45_vectorIndex, uint32_T c45_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c45_dataNumber, c45_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c45_vectorIndex, 0, 4, 1,
    0)]);
}

static void init_dsm_address_info(SFc45_lib_affectiveChar_behaviorInstanceStruct
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

void sf_c45_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3969079354U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2102780368U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3993771478U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3468246387U);
}

mxArray *sf_c45_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XVjds1pRBdisobBfd0cfFF");
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

mxArray *sf_c45_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c45_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c45_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c45_lib_affectiveChar_behavior\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c45_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           45,
           1,
           0,
           0,
           11,
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
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,10,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc45_lib_affectiveChar_behavior",
                             0,-1,4156);
        _SFD_CV_INIT_EML_IF(0,1,0,2373,2396,3943,4156);
        _SFD_CV_INIT_EML_IF(0,1,1,2401,2413,-1,3370);
        _SFD_CV_INIT_EML_IF(0,1,2,2437,2445,2688,3360);
        _SFD_CV_INIT_EML_IF(0,1,3,2688,2700,2928,3360);
        _SFD_CV_INIT_EML_IF(0,1,4,2928,2940,3152,3360);
        _SFD_CV_INIT_EML_IF(0,1,5,3375,3388,-1,3939);
        _SFD_CV_INIT_EML_IF(0,1,6,3397,3411,3526,3545);
        _SFD_CV_INIT_EML_IF(0,1,7,3526,3545,3660,3931);
        _SFD_CV_INIT_EML_IF(0,1,8,3660,3679,3795,3931);
        _SFD_CV_INIT_EML_IF(0,1,9,3795,3815,-1,3815);

        {
          static int condStart[] = { 3400, 3407 };

          static int condEnd[] = { 3403, 3410 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,3400,3410,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3533, 3541 };

          static int condEnd[] = { 3537, 3544 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,3533,3544,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3667, 3674 };

          static int condEnd[] = { 3670, 3678 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,3667,3678,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3802, 3810 };

          static int condEnd[] = { 3806, 3814 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,3802,3814,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_c_sf_marshallOut,(MexInFcnForType)
          c45_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_c_sf_marshallOut,(MexInFcnForType)
          c45_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)
            c45_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
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
  return "eC2OwR9R2B2Hx8NkZt4r0C";
}

static void sf_opaque_initialize_c45_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc45_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c45_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c45_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c45_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c45_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c45_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c45_lib_affectiveChar_behavior(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c45_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c45_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c45_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c45_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc45_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c45_lib_affectiveChar_behavior
      ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc45_lib_affectiveChar_behavior
    ((SFc45_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c45_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c45_lib_affectiveChar_behavior
      ((SFc45_lib_affectiveChar_behaviorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c45_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      45);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,45,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,45,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,45);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,45);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4238810133U));
  ssSetChecksum1(S,(4054931104U));
  ssSetChecksum2(S,(4061572496U));
  ssSetChecksum3(S,(3922405541U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c45_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c45_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc45_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc45_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc45_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc45_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c45_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c45_lib_affectiveChar_behavior;
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

void c45_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c45_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c45_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c45_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c45_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
