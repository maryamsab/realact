/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c47_lib_affectiveChar_behavior.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c47_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c47_debug_family_names[20] = { "gaze_custom_flag",
  "mutual_gaze_duration_custom", "avert_gaze_duration_custom",
  "avert_head_frequency_custom", "avert_head_speed_custom", "nargin", "nargout",
  "v", "a", "p", "pFlag", "vaFlag", "gazeArr", "mutDurFactor", "avertDurFactor",
  "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance", "avertFreqFactor",
  "mutFreqFactor" };

static const char * c47_b_debug_family_names[22] = { "pose_custom_flag",
  "pose_chance_custom", "pose_selfAdaptor_chance_custom",
  "pose_frequency_custom", "pose_speed_custom", "pose_lean_custom", "nargin",
  "nargout", "v", "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange",
  "poseTwitch", "poseFreqFactor", "poseChanceFactor", "poseCatChance",
  "poseLean", "poseSpeed", "poseLeanFlag" };

static boolean_T c47_dataWrittenToVector[14];

/* Function Declarations */
static void initialize_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c47_update_debugger_state_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_st);
static void c47_set_sim_state_side_effects_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c47_enter_atomic_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c47_enter_internal_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c47_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c47_exit_internal_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c47_initc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber);
static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static real_T c47_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static void c47_b_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId, real_T c47_y[6]);
static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static boolean_T c47_c_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static void c47_setGazeFactorsc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c47_v,
   real_T c47_a, real_T c47_p, boolean_T c47_pFlag, boolean_T c47_vaFlag, real_T
   c47_gazeArr[6], real_T *c47_mutDurFactor, real_T *c47_avertDurFactor, real_T *
   c47_avertHeadFreqFactor, real_T *c47_avertHeadSpeed, real_T
   *c47_avertDirsChance, real_T *c47_avertFreqFactor, real_T *c47_mutFreqFactor);
static void c47_setPoseFactorsc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c47_v,
   real_T c47_ar, real_T c47_p, boolean_T c47_pFlag, boolean_T c47_vaFlag,
   real_T c47_poseArr[6], real_T c47_personalityChange, real_T *c47_poseTwitch,
   real_T *c47_poseFreqFactor, real_T *c47_poseChanceFactor, real_T
   *c47_poseCatChance, real_T *c47_poseLean, real_T *c47_poseSpeed, real_T
   *c47_poseLeanFlag);
static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static int32_T c47_d_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static uint8_T c47_e_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_b_is_active_c47_lib_affectiveChar_behavior, const char_T *c47_identifier);
static uint8_T c47_f_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId);
static const mxArray *c47_g_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_b_setSimStateSideEffectsInfo, const char_T *c47_identifier);
static const mxArray *c47_h_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_updateDataWrittenToVector
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c47_vectorIndex);
static void c47_errorIfDataNotWrittenToFcn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c47_vectorIndex, uint32_T c47_dataNumber);
static void init_dsm_address_info(SFc47_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c47_update_debugger_state_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c47_st;
  const mxArray *c47_y = NULL;
  uint8_T c47_hoistedGlobal;
  uint8_T c47_u;
  const mxArray *c47_b_y = NULL;
  c47_st = NULL;
  c47_st = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_createcellmatrix(1, 1), false);
  c47_hoistedGlobal =
    chartInstance->c47_is_active_c47_lib_affectiveChar_behavior;
  c47_u = c47_hoistedGlobal;
  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", &c47_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 0, c47_b_y);
  sf_mex_assign(&c47_st, c47_y, false);
  return c47_st;
}

static void set_sim_state_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_st)
{
  const mxArray *c47_u;
  chartInstance->c47_doneDoubleBufferReInit = true;
  c47_u = sf_mex_dup(c47_st);
  chartInstance->c47_is_active_c47_lib_affectiveChar_behavior =
    c47_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c47_u, 0)),
    "is_active_c47_lib_affectiveChar_behavior");
  sf_mex_assign(&chartInstance->c47_setSimStateSideEffectsInfo,
                c47_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c47_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c47_u);
  chartInstance->c47_doSetSimStateSideEffects = 1U;
  c47_update_debugger_state_c47_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c47_st);
}

static void c47_set_sim_state_side_effects_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c47_doSetSimStateSideEffects != 0) {
    chartInstance->c47_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c47_setSimStateSideEffectsInfo);
}

static void sf_gateway_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c47_set_sim_state_side_effects_c47_lib_affectiveChar_behavior(chartInstance);
}

static void c47_enter_atomic_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c47_sfEvent);
  chartInstance->c47_is_active_c47_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c47_sfEvent);
}

static void c47_enter_internal_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c47_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c47_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c47_sfEvent);
}

static void c47_exit_internal_c47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c47_initc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c47_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c47_doSetSimStateSideEffects = 0U;
  chartInstance->c47_setSimStateSideEffectsInfo = NULL;
  chartInstance->c47_is_active_c47_lib_affectiveChar_behavior = 0U;
}

static void initSimStructsc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber)
{
  (void)c47_machineNumber;
  (void)c47_chartNumber;
  (void)c47_instanceNumber;
}

static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  real_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(real_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static real_T c47_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  real_T c47_y;
  real_T c47_d0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_d0, 1, 0, 0U, 0, 0U, 0);
  c47_y = c47_d0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_mutFreqFactor;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_mutFreqFactor = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_mutFreqFactor),
    &c47_thisId);
  sf_mex_destroy(&c47_mutFreqFactor);
  *(real_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_i0;
  real_T c47_b_inData[6];
  int32_T c47_i1;
  real_T c47_u[6];
  const mxArray *c47_y = NULL;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  for (c47_i0 = 0; c47_i0 < 6; c47_i0++) {
    c47_b_inData[c47_i0] = (*(real_T (*)[6])c47_inData)[c47_i0];
  }

  for (c47_i1 = 0; c47_i1 < 6; c47_i1++) {
    c47_u[c47_i1] = c47_b_inData[c47_i1];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static void c47_b_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId, real_T c47_y[6])
{
  real_T c47_dv0[6];
  int32_T c47_i2;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), c47_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c47_i2 = 0; c47_i2 < 6; c47_i2++) {
    c47_y[c47_i2] = c47_dv0[c47_i2];
  }

  sf_mex_destroy(&c47_u);
}

static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_gazeArr;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y[6];
  int32_T c47_i3;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_gazeArr = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_gazeArr), &c47_thisId,
    c47_y);
  sf_mex_destroy(&c47_gazeArr);
  for (c47_i3 = 0; c47_i3 < 6; c47_i3++) {
    (*(real_T (*)[6])c47_outData)[c47_i3] = c47_y[c47_i3];
  }

  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  boolean_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(boolean_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static boolean_T c47_c_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  boolean_T c47_y;
  boolean_T c47_b0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_b0, 1, 11, 0U, 0, 0U, 0);
  c47_y = c47_b0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_vaFlag;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  boolean_T c47_y;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_vaFlag = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_vaFlag),
    &c47_thisId);
  sf_mex_destroy(&c47_vaFlag);
  *(boolean_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

const mxArray *sf_c47_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c47_nameCaptureInfo = NULL;
  c47_nameCaptureInfo = NULL;
  sf_mex_assign(&c47_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c47_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec47_lib_affectiveChar_behavior(SimStruct
  *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  return true;
}

void sf_exported_auto_duringc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  c47_c47_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c47_enter_atomic_c47_lib_affectiveChar_behavior(chartInstance);
  c47_enter_internal_c47_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c47_exit_internal_c47_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_gatewayc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc47_lib_affectiveChar_behavior(SimStruct
  *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c47_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc47_lib_affectiveChar_behavior
  (SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc47_lib_affectiveChar_behavior(SimStruct
  *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc47_lib_affectiveChar_behavior(SimStruct
  *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc47_lib_affectiveChar_behavior(SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  c47_initc47_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec47_lib_affectiveChar_behavior
  (SimStruct *c47_S)
{
  const mxArray *c47_out = NULL;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  c47_out = NULL;
  sf_mex_assign(&c47_out,
                sf_internal_get_sim_state_c47_lib_affectiveChar_behavior(c47_S),
                false);
  return c47_out;
}

void sf_exported_auto_setSimstatec47_lib_affectiveChar_behavior(SimStruct *c47_S,
  const mxArray *c47_in)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c47_lib_affectiveChar_behavior(c47_S, sf_mex_dup
    (c47_in));
  sf_mex_destroy(&c47_in);
}

void sf_exported_auto_check_state_inconsistency_c47_lib_affectiveChar_behavior
  (SimStruct *c47_S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c47_setGazeFactorsc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c47_v,
   real_T c47_a, real_T c47_p, boolean_T c47_pFlag, boolean_T c47_vaFlag, real_T
   c47_gazeArr[6], real_T *c47_mutDurFactor, real_T *c47_avertDurFactor, real_T *
   c47_avertHeadFreqFactor, real_T *c47_avertHeadSpeed, real_T
   *c47_avertDirsChance, real_T *c47_avertFreqFactor, real_T *c47_mutFreqFactor)
{
  uint32_T c47_debug_family_var_map[20];
  real_T c47_gaze_custom_flag;
  real_T c47_mutual_gaze_duration_custom;
  real_T c47_avert_gaze_duration_custom;
  real_T c47_avert_head_frequency_custom;
  real_T c47_avert_head_speed_custom;
  real_T c47_nargin = 6.0;
  real_T c47_nargout = 7.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c47_debug_family_names,
    c47_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_gaze_custom_flag, 0U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_mutual_gaze_duration_custom, 1U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_avert_gaze_duration_custom, 2U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_avert_head_frequency_custom, 3U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_avert_head_speed_custom, 4U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargin, 5U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargout, 6U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_v, 7U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_a, 8U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_p, 9U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pFlag, 10U, c47_c_sf_marshallOut,
    c47_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_vaFlag, 11U, c47_c_sf_marshallOut,
    c47_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_gazeArr, 12U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_mutDurFactor, 13U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_avertDurFactor, 14U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_avertHeadFreqFactor, 15U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_avertHeadSpeed, 16U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_avertDirsChance, 17U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_avertFreqFactor, 18U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_mutFreqFactor, 19U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 24);
  c47_gaze_custom_flag = c47_gazeArr[0];
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 25);
  c47_mutual_gaze_duration_custom = c47_gazeArr[1];
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 26);
  c47_avert_gaze_duration_custom = c47_gazeArr[2];
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 27);
  c47_avert_head_frequency_custom = c47_gazeArr[3];
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 28);
  c47_avert_head_speed_custom = c47_gazeArr[4];
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 29);
  *c47_avertDirsChance = c47_gazeArr[5];
  c47_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 31);
  *c47_mutDurFactor = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 32);
  *c47_avertDurFactor = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 33);
  *c47_avertHeadFreqFactor = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 34);
  *c47_avertHeadSpeed = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 35);
  *c47_avertDirsChance = 0.0;
  c47_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 36);
  *c47_avertFreqFactor = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 37);
  *c47_mutFreqFactor = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 39);
  if (CV_EML_IF(0, 1, 0, c47_gaze_custom_flag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 40);
    if (CV_EML_IF(0, 1, 1, (real_T)c47_pFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 41);
      if (CV_EML_IF(0, 1, 2, c47_p == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 42);
        *c47_mutDurFactor = 3.0;
        c47_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 43);
        *c47_avertDurFactor = 0.5;
        c47_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 44);
        *c47_avertHeadFreqFactor = 10.0;
        c47_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 45);
        *c47_avertHeadSpeed = 2.0;
        c47_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 46);
        *c47_avertDirsChance = 1.0;
        c47_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 47);
        *c47_mutFreqFactor = 3.0;
        c47_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 48);
        *c47_avertFreqFactor = 0.5;
        c47_updateDataWrittenToVector(chartInstance, 5U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 49);
        if (CV_EML_IF(0, 1, 3, c47_p == 2.0)) {
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 50);
          *c47_mutDurFactor = 0.5;
          c47_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 51);
          *c47_avertDurFactor = 2.0;
          c47_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 52);
          *c47_avertHeadFreqFactor = 2.0;
          c47_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 53);
          *c47_avertHeadSpeed = 3.0;
          c47_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 54);
          *c47_avertDirsChance = 2.0;
          c47_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 55);
          *c47_mutFreqFactor = 0.5;
          c47_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 56);
          *c47_avertFreqFactor = 3.0;
          c47_updateDataWrittenToVector(chartInstance, 5U);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 57);
          if (CV_EML_IF(0, 1, 4, c47_p == 3.0)) {
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 58);
            *c47_mutDurFactor = 4.0;
            c47_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 59);
            *c47_avertDurFactor = 0.1;
            c47_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 60);
            *c47_avertHeadFreqFactor = 8.0;
            c47_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 61);
            *c47_avertHeadSpeed = 2.0;
            c47_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 62);
            *c47_avertDirsChance = 1.0;
            c47_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 63);
            *c47_mutFreqFactor = 3.0;
            c47_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 64);
            *c47_avertFreqFactor = 0.5;
            c47_updateDataWrittenToVector(chartInstance, 5U);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 66);
            *c47_mutDurFactor = 0.25;
            c47_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 67);
            *c47_avertDurFactor = 0.5;
            c47_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 68);
            *c47_avertHeadFreqFactor = 1.0;
            c47_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 69);
            *c47_avertHeadSpeed = 3.0;
            c47_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 70);
            *c47_avertDirsChance = 2.0;
            c47_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 71);
            *c47_mutFreqFactor = 0.5;
            c47_updateDataWrittenToVector(chartInstance, 6U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 72);
            *c47_avertFreqFactor = 3.0;
            c47_updateDataWrittenToVector(chartInstance, 5U);
          }
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 75);
    if (CV_EML_IF(0, 1, 5, (real_T)c47_vaFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 76);
      guard1 = false;
      if (CV_EML_COND(0, 1, 0, c47_v > 5.0)) {
        if (CV_EML_COND(0, 1, 1, c47_a > 5.0)) {
          CV_EML_MCDC(0, 1, 0, true);
          CV_EML_IF(0, 1, 6, true);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 77);
          c47_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
          *c47_mutDurFactor *= 0.5;
          c47_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 78);
          c47_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          *c47_avertDurFactor *= 0.5;
          c47_updateDataWrittenToVector(chartInstance, 1U);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 1, 0, false);
        CV_EML_IF(0, 1, 6, false);
        _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 79);
        guard2 = false;
        if (CV_EML_COND(0, 1, 2, c47_v < -5.0)) {
          if (CV_EML_COND(0, 1, 3, c47_a > 5.0)) {
            CV_EML_MCDC(0, 1, 1, true);
            CV_EML_IF(0, 1, 7, true);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 80);
            c47_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
            *c47_mutDurFactor *= 0.5;
            c47_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 81);
            c47_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
            *c47_avertDurFactor *= 0.5;
            c47_updateDataWrittenToVector(chartInstance, 1U);
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(0, 1, 1, false);
          CV_EML_IF(0, 1, 7, false);
          _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 82);
          guard3 = false;
          if (CV_EML_COND(0, 1, 4, c47_v > 5.0)) {
            if (CV_EML_COND(0, 1, 5, c47_a < -5.0)) {
              CV_EML_MCDC(0, 1, 2, true);
              CV_EML_IF(0, 1, 8, true);
              _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 83);
              c47_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
              *c47_mutDurFactor *= 0.5;
              c47_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 84);
              c47_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
              *c47_avertDurFactor *= 0.5;
              c47_updateDataWrittenToVector(chartInstance, 1U);
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3 == true) {
            CV_EML_MCDC(0, 1, 2, false);
            CV_EML_IF(0, 1, 8, false);
            _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 85);
            guard4 = false;
            if (CV_EML_COND(0, 1, 6, c47_v < -5.0)) {
              if (CV_EML_COND(0, 1, 7, c47_a < -5.0)) {
                CV_EML_MCDC(0, 1, 3, true);
                CV_EML_IF(0, 1, 9, true);
                _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 86);
                c47_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
                *c47_mutDurFactor *= 0.5;
                c47_updateDataWrittenToVector(chartInstance, 0U);
                _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 87);
                c47_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
                *c47_avertDurFactor *= 0.5;
                c47_updateDataWrittenToVector(chartInstance, 1U);
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
    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 91);
    *c47_mutDurFactor = c47_mutual_gaze_duration_custom;
    c47_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 92);
    *c47_avertDurFactor = c47_avert_gaze_duration_custom;
    c47_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 93);
    *c47_avertHeadFreqFactor = c47_avert_head_frequency_custom;
    c47_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 94);
    *c47_avertHeadSpeed = c47_avert_head_speed_custom;
    c47_updateDataWrittenToVector(chartInstance, 3U);
  }

  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, -94);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c47_setPoseFactorsc47_lib_affectiveChar_behavior
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c47_v,
   real_T c47_ar, real_T c47_p, boolean_T c47_pFlag, boolean_T c47_vaFlag,
   real_T c47_poseArr[6], real_T c47_personalityChange, real_T *c47_poseTwitch,
   real_T *c47_poseFreqFactor, real_T *c47_poseChanceFactor, real_T
   *c47_poseCatChance, real_T *c47_poseLean, real_T *c47_poseSpeed, real_T
   *c47_poseLeanFlag)
{
  uint32_T c47_debug_family_var_map[22];
  real_T c47_pose_custom_flag;
  real_T c47_pose_chance_custom;
  real_T c47_pose_selfAdaptor_chance_custom;
  real_T c47_pose_frequency_custom;
  real_T c47_pose_speed_custom;
  real_T c47_pose_lean_custom;
  real_T c47_nargin = 7.0;
  real_T c47_nargout = 7.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c47_b_debug_family_names,
    c47_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pose_custom_flag, 0U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pose_chance_custom, 1U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pose_selfAdaptor_chance_custom, 2U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pose_frequency_custom, 3U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pose_speed_custom, 4U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pose_lean_custom, 5U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargin, 6U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargout, 7U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_v, 8U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_ar, 9U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_p, 10U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_pFlag, 11U, c47_c_sf_marshallOut,
    c47_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_vaFlag, 12U, c47_c_sf_marshallOut,
    c47_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseArr, 13U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_personalityChange, 14U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseTwitch, 15U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseFreqFactor, 16U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseChanceFactor, 17U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseCatChance, 18U,
    c47_sf_marshallOut, c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseLean, 19U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseSpeed, 20U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c47_poseLeanFlag, 21U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 2);
  c47_pose_custom_flag = c47_poseArr[0];
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 3);
  c47_pose_chance_custom = c47_poseArr[2];
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 4);
  c47_pose_selfAdaptor_chance_custom = c47_poseArr[1];
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 5);
  c47_pose_frequency_custom = c47_poseArr[3];
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 6);
  c47_pose_speed_custom = c47_poseArr[4];
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 7);
  c47_pose_lean_custom = c47_poseArr[5];
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 9);
  *c47_poseCatChance = 10.0;
  c47_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 10);
  *c47_poseChanceFactor = 1.0;
  c47_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 11);
  *c47_poseFreqFactor = 5.0;
  c47_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 12);
  *c47_poseSpeed = 0.0;
  c47_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 13);
  *c47_poseLean = 10.0;
  c47_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 14);
  *c47_poseTwitch = 0.0;
  c47_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 16);
  *c47_poseLeanFlag = 0.0;
  c47_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 18);
  if (CV_EML_IF(1, 1, 0, c47_pose_custom_flag == 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 19);
    if (CV_EML_IF(1, 1, 1, (real_T)c47_pFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 20);
      if (CV_EML_IF(1, 1, 2, c47_personalityChange == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 21);
        *c47_poseLeanFlag = 1.0;
        c47_updateDataWrittenToVector(chartInstance, 13U);
      }

      _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 23);
      if (CV_EML_IF(1, 1, 3, c47_p == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 24);
        *c47_poseTwitch = 1.0;
        c47_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 25);
        *c47_poseFreqFactor = 10.0;
        c47_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 26);
        *c47_poseLean = 11.0;
        c47_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 27);
        *c47_poseChanceFactor = 2.0;
        c47_updateDataWrittenToVector(chartInstance, 9U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 28);
        *c47_poseCatChance = 90.0;
        c47_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 29);
        *c47_poseSpeed = 2.0;
        c47_updateDataWrittenToVector(chartInstance, 12U);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 30);
        if (CV_EML_IF(1, 1, 4, c47_p == 2.0)) {
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 31);
          *c47_poseTwitch = 1.0;
          c47_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 32);
          *c47_poseFreqFactor = 17.0;
          c47_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 33);
          *c47_poseLean = 12.0;
          c47_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 34);
          *c47_poseChanceFactor = 1.0;
          c47_updateDataWrittenToVector(chartInstance, 9U);
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 35);
          *c47_poseCatChance = 10.0;
          c47_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 36);
          *c47_poseSpeed = 1.0;
          c47_updateDataWrittenToVector(chartInstance, 12U);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 37);
          if (CV_EML_IF(1, 1, 5, c47_p == 3.0)) {
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 38);
            *c47_poseTwitch = 0.0;
            c47_updateDataWrittenToVector(chartInstance, 7U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 39);
            *c47_poseFreqFactor = 12.0;
            c47_updateDataWrittenToVector(chartInstance, 8U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 40);
            *c47_poseLean = 11.0;
            c47_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 41);
            *c47_poseChanceFactor = 0.25;
            c47_updateDataWrittenToVector(chartInstance, 9U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 42);
            *c47_poseCatChance = 10.0;
            c47_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 43);
            *c47_poseSpeed = 2.0;
            c47_updateDataWrittenToVector(chartInstance, 12U);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 45);
            *c47_poseTwitch = 0.0;
            c47_updateDataWrittenToVector(chartInstance, 7U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 46);
            *c47_poseFreqFactor = 20.0;
            c47_updateDataWrittenToVector(chartInstance, 8U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 47);
            *c47_poseLean = 12.0;
            c47_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 48);
            *c47_poseChanceFactor = 0.25;
            c47_updateDataWrittenToVector(chartInstance, 9U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 49);
            *c47_poseCatChance = 90.0;
            c47_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 50);
            *c47_poseSpeed = 1.0;
            c47_updateDataWrittenToVector(chartInstance, 12U);
          }
        }
      }
    }

    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 53);
    if (CV_EML_IF(1, 1, 6, (real_T)c47_vaFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 54);
      if (CV_EML_IF(1, 1, 7, c47_ar > 5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 55);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 8U, 14U);
        *c47_poseFreqFactor *= 1.2;
        c47_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 56);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 9U, 15U);
        *c47_poseChanceFactor *= 1.1;
        c47_updateDataWrittenToVector(chartInstance, 9U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 57);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 10U, 16U);
        (*c47_poseCatChance)++;
        c47_updateDataWrittenToVector(chartInstance, 10U);
      }

      _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 59);
      if (CV_EML_IF(1, 1, 8, c47_ar < -5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 60);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 8U, 14U);
        *c47_poseFreqFactor *= 1.3;
        c47_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 61);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 9U, 15U);
        *c47_poseChanceFactor *= 1.1;
        c47_updateDataWrittenToVector(chartInstance, 9U);
      }

      _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 63);
      if (CV_EML_IF(1, 1, 9, c47_v > 5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 64);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 10U, 16U);
        (*c47_poseCatChance)--;
        c47_updateDataWrittenToVector(chartInstance, 10U);
      }

      _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 66);
      if (CV_EML_IF(1, 1, 10, c47_v < -5.0)) {
        _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 67);
        c47_errorIfDataNotWrittenToFcn(chartInstance, 10U, 16U);
        (*c47_poseCatChance)++;
        c47_updateDataWrittenToVector(chartInstance, 10U);
      }
    }
  } else {
    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 71);
    *c47_poseFreqFactor = c47_pose_frequency_custom;
    c47_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 72);
    *c47_poseLean = c47_pose_lean_custom;
    c47_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 73);
    *c47_poseChanceFactor = c47_pose_chance_custom;
    c47_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 74);
    *c47_poseCatChance = c47_pose_selfAdaptor_chance_custom;
    c47_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, 75);
    *c47_poseSpeed = c47_pose_speed_custom;
    c47_updateDataWrittenToVector(chartInstance, 12U);
  }

  _SFD_EML_CALL(1U, chartInstance->c47_sfEvent, -75);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c47_lib_affectiveChar_behavior_setGazeFactors(SimStruct
  *c47_S, real_T c47_v, real_T c47_a, real_T c47_p, boolean_T c47_pFlag,
  boolean_T c47_vaFlag, real_T c47_gazeArr[6], real_T *c47_mutDurFactor, real_T *
  c47_avertDurFactor, real_T *c47_avertHeadFreqFactor, real_T
  *c47_avertHeadSpeed, real_T *c47_avertDirsChance, real_T *c47_avertFreqFactor,
  real_T *c47_mutFreqFactor)
{
  int32_T c47_i4;
  real_T c47_b_gazeArr[6];
  real_T c47_b_mutFreqFactor;
  real_T c47_b_avertFreqFactor;
  real_T c47_b_avertDirsChance;
  real_T c47_b_avertHeadSpeed;
  real_T c47_b_avertHeadFreqFactor;
  real_T c47_b_avertDurFactor;
  real_T c47_b_mutDurFactor;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  for (c47_i4 = 0; c47_i4 < 6; c47_i4++) {
    c47_b_gazeArr[c47_i4] = c47_gazeArr[c47_i4];
  }

  c47_setGazeFactorsc47_lib_affectiveChar_behavior(chartInstance, c47_v, c47_a,
    c47_p, c47_pFlag, c47_vaFlag, c47_b_gazeArr, &c47_b_mutDurFactor,
    &c47_b_avertDurFactor, &c47_b_avertHeadFreqFactor, &c47_b_avertHeadSpeed,
    &c47_b_avertDirsChance, &c47_b_avertFreqFactor, &c47_b_mutFreqFactor);
  *c47_mutDurFactor = c47_b_mutDurFactor;
  *c47_avertDurFactor = c47_b_avertDurFactor;
  *c47_avertHeadFreqFactor = c47_b_avertHeadFreqFactor;
  *c47_avertHeadSpeed = c47_b_avertHeadSpeed;
  *c47_avertDirsChance = c47_b_avertDirsChance;
  *c47_avertFreqFactor = c47_b_avertFreqFactor;
  *c47_mutFreqFactor = c47_b_mutFreqFactor;
}

void sf_exported_user_c47_lib_affectiveChar_behavior_setPoseFactors(SimStruct
  *c47_S, real_T c47_v, real_T c47_ar, real_T c47_p, boolean_T c47_pFlag,
  boolean_T c47_vaFlag, real_T c47_poseArr[6], real_T c47_personalityChange,
  real_T *c47_poseTwitch, real_T *c47_poseFreqFactor, real_T
  *c47_poseChanceFactor, real_T *c47_poseCatChance, real_T *c47_poseLean, real_T
  *c47_poseSpeed, real_T *c47_poseLeanFlag)
{
  int32_T c47_i5;
  real_T c47_b_poseArr[6];
  real_T c47_b_poseLeanFlag;
  real_T c47_b_poseSpeed;
  real_T c47_b_poseLean;
  real_T c47_b_poseCatChance;
  real_T c47_b_poseChanceFactor;
  real_T c47_b_poseFreqFactor;
  real_T c47_b_poseTwitch;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c47_S))->instanceInfo)
    ->chartInstance;
  for (c47_i5 = 0; c47_i5 < 6; c47_i5++) {
    c47_b_poseArr[c47_i5] = c47_poseArr[c47_i5];
  }

  c47_setPoseFactorsc47_lib_affectiveChar_behavior(chartInstance, c47_v, c47_ar,
    c47_p, c47_pFlag, c47_vaFlag, c47_b_poseArr, c47_personalityChange,
    &c47_b_poseTwitch, &c47_b_poseFreqFactor, &c47_b_poseChanceFactor,
    &c47_b_poseCatChance, &c47_b_poseLean, &c47_b_poseSpeed, &c47_b_poseLeanFlag);
  *c47_poseTwitch = c47_b_poseTwitch;
  *c47_poseFreqFactor = c47_b_poseFreqFactor;
  *c47_poseChanceFactor = c47_b_poseChanceFactor;
  *c47_poseCatChance = c47_b_poseCatChance;
  *c47_poseLean = c47_b_poseLean;
  *c47_poseSpeed = c47_b_poseSpeed;
  *c47_poseLeanFlag = c47_b_poseLeanFlag;
}

static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(int32_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static int32_T c47_d_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  int32_T c47_y;
  int32_T c47_i6;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_i6, 1, 6, 0U, 0, 0U, 0);
  c47_y = c47_i6;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_sfEvent;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  int32_T c47_y;
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c47_b_sfEvent = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_sfEvent),
    &c47_thisId);
  sf_mex_destroy(&c47_b_sfEvent);
  *(int32_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static uint8_T c47_e_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_b_is_active_c47_lib_affectiveChar_behavior, const char_T *c47_identifier)
{
  uint8_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_is_active_c47_lib_affectiveChar_behavior), &c47_thisId);
  sf_mex_destroy(&c47_b_is_active_c47_lib_affectiveChar_behavior);
  return c47_y;
}

static uint8_T c47_f_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  uint8_T c47_y;
  uint8_T c47_u0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_u0, 1, 3, 0U, 0, 0U, 0);
  c47_y = c47_u0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static const mxArray *c47_g_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_b_setSimStateSideEffectsInfo, const char_T *c47_identifier)
{
  const mxArray *c47_y = NULL;
  emlrtMsgIdentifier c47_thisId;
  c47_y = NULL;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  sf_mex_assign(&c47_y, c47_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_setSimStateSideEffectsInfo), &c47_thisId), false);
  sf_mex_destroy(&c47_b_setSimStateSideEffectsInfo);
  return c47_y;
}

static const mxArray *c47_h_emlrt_marshallIn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  const mxArray *c47_y = NULL;
  (void)chartInstance;
  (void)c47_parentId;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_duplicatearraysafe(&c47_u), false);
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_updateDataWrittenToVector
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c47_vectorIndex)
{
  (void)chartInstance;
  c47_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c47_vectorIndex, 0, 13, 1, 0)] = true;
}

static void c47_errorIfDataNotWrittenToFcn
  (SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c47_vectorIndex, uint32_T c47_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c47_dataNumber, c47_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c47_vectorIndex, 0, 13, 1,
    0)]);
}

static void init_dsm_address_info(SFc47_lib_affectiveChar_behaviorInstanceStruct
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

void sf_c47_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2774533039U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1847900972U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(117608638U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3211816470U);
}

mxArray *sf_c47_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fg8VdcE7gUtWAQyHEswL1G");
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

mxArray *sf_c47_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c47_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c47_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c47_lib_affectiveChar_behavior\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c47_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           47,
           2,
           0,
           0,
           27,
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
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_SET_DATA_PROPS(16,9,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
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
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc47_lib_affectiveChar_behavior",
                             0,-1,4756);
        _SFD_CV_INIT_EML_IF(0,1,0,2439,2462,4543,4756);
        _SFD_CV_INIT_EML_IF(0,1,1,2467,2479,-1,3970);
        _SFD_CV_INIT_EML_IF(0,1,2,2488,2496,3030,3960);
        _SFD_CV_INIT_EML_IF(0,1,3,3030,3042,3364,3960);
        _SFD_CV_INIT_EML_IF(0,1,4,3364,3376,3674,3960);
        _SFD_CV_INIT_EML_IF(0,1,5,3975,3988,-1,4539);
        _SFD_CV_INIT_EML_IF(0,1,6,3997,4011,4126,4145);
        _SFD_CV_INIT_EML_IF(0,1,7,4126,4145,4260,4531);
        _SFD_CV_INIT_EML_IF(0,1,8,4260,4279,4395,4531);
        _SFD_CV_INIT_EML_IF(0,1,9,4395,4415,-1,4415);

        {
          static int condStart[] = { 4000, 4007 };

          static int condEnd[] = { 4003, 4010 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,4000,4010,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4133, 4141 };

          static int condEnd[] = { 4137, 4144 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,4133,4144,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4267, 4274 };

          static int condEnd[] = { 4270, 4278 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,4267,4278,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4402, 4410 };

          static int condEnd[] = { 4406, 4414 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,4402,4414,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,1,1,11,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc47_lib_affectiveChar_behavior",
                             0,-1,2456);
        _SFD_CV_INIT_EML_IF(1,1,0,513,536,2235,2455);
        _SFD_CV_INIT_EML_IF(1,1,1,545,557,-1,1755);
        _SFD_CV_INIT_EML_IF(1,1,2,566,590,-1,630);
        _SFD_CV_INIT_EML_IF(1,1,3,639,647,1035,1747);
        _SFD_CV_INIT_EML_IF(1,1,4,1035,1047,1306,1747);
        _SFD_CV_INIT_EML_IF(1,1,5,1306,1318,1544,1747);
        _SFD_CV_INIT_EML_IF(1,1,6,1760,1773,-1,2234);
        _SFD_CV_INIT_EML_IF(1,1,7,1782,1791,-1,1950);
        _SFD_CV_INIT_EML_IF(1,1,8,1959,1968,-1,2083);
        _SFD_CV_INIT_EML_IF(1,1,9,2092,2099,-1,2154);
        _SFD_CV_INIT_EML_IF(1,1,10,2163,2171,-1,2226);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_c_sf_marshallOut,(MexInFcnForType)
          c47_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_c_sf_marshallOut,(MexInFcnForType)
          c47_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
            c47_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_c_sf_marshallOut,(MexInFcnForType)
          c47_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_c_sf_marshallOut,(MexInFcnForType)
          c47_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
            c47_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
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
  return "MjNc1SMohBmsLhaAPElgsD";
}

static void sf_opaque_initialize_c47_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc47_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c47_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c47_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c47_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c47_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c47_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c47_lib_affectiveChar_behavior(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c47_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c47_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c47_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c47_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc47_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c47_lib_affectiveChar_behavior
      ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc47_lib_affectiveChar_behavior
    ((SFc47_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c47_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c47_lib_affectiveChar_behavior
      ((SFc47_lib_affectiveChar_behaviorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c47_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      47);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,47,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,47,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,47);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,47);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3417067311U));
  ssSetChecksum1(S,(1529749956U));
  ssSetChecksum2(S,(1733706718U));
  ssSetChecksum3(S,(3926766264U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c47_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c47_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc47_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc47_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc47_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc47_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c47_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c47_lib_affectiveChar_behavior;
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

void c47_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c47_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c47_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c47_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c47_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
