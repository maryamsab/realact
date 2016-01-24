/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c43_lib_affectiveChar_behavior.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c43_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c43_debug_family_names[18] = { "nargin", "nargout", "v", "a",
  "p", "pFlag", "vaFlag", "gazeArr", "mutDurFactor", "avertDurFactor",
  "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance", "avertFreqFactor",
  "mutFreqFactor", "blinkFlag", "blinkPeriodMin", "blinkPeriodMax" };

static const char * c43_b_debug_family_names[22] = { "pose_custom_flag",
  "pose_chance_custom", "pose_selfAdaptor_chance_custom",
  "pose_frequency_custom", "pose_speed_custom", "pose_lean_custom", "nargin",
  "nargout", "v", "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange",
  "poseTwitch", "poseFreqFactor", "poseChanceFactor", "poseCatChance",
  "poseLean", "poseSpeed", "poseLeanFlag" };

static boolean_T c43_dataWrittenToVector[17];

/* Function Declarations */
static void initialize_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c43_update_debugger_state_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_st);
static void c43_set_sim_state_side_effects_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c43_enter_atomic_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c43_enter_internal_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c43_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c43_exit_internal_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c43_initc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber);
static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static real_T c43_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static void c43_b_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[6]);
static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static boolean_T c43_c_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static void c43_info_helper(const mxArray **c43_info);
static const mxArray *c43_emlrt_marshallOut(const char * c43_u);
static const mxArray *c43_b_emlrt_marshallOut(const uint32_T c43_u);
static void c43_setGazeFactorsc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c43_v,
   real_T c43_a, real_T c43_p, boolean_T c43_pFlag, boolean_T c43_vaFlag, real_T
   c43_gazeArr[6], real_T *c43_mutDurFactor, real_T *c43_avertDurFactor, real_T *
   c43_avertHeadFreqFactor, real_T *c43_avertHeadSpeed, real_T
   *c43_avertDirsChance, real_T *c43_avertFreqFactor, real_T *c43_mutFreqFactor,
   real_T *c43_blinkFlag, real_T *c43_blinkPeriodMin, real_T *c43_blinkPeriodMax);
static void c43_setPoseFactorsc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c43_v,
   real_T c43_ar, real_T c43_p, boolean_T c43_pFlag, boolean_T c43_vaFlag,
   real_T c43_poseArr[6], real_T c43_personalityChange, real_T *c43_poseTwitch,
   real_T *c43_poseFreqFactor, real_T *c43_poseChanceFactor, real_T
   *c43_poseCatChance, real_T *c43_poseLean, real_T *c43_poseSpeed, real_T
   *c43_poseLeanFlag);
static real_T c43_round(SFc43_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c43_x);
static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static int32_T c43_d_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static uint8_T c43_e_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_b_is_active_c43_lib_affectiveChar_behavior, const char_T *c43_identifier);
static uint8_T c43_f_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId);
static const mxArray *c43_g_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_b_setSimStateSideEffectsInfo, const char_T *c43_identifier);
static const mxArray *c43_h_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_updateDataWrittenToVector
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c43_vectorIndex);
static void c43_errorIfDataNotWrittenToFcn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c43_vectorIndex, uint32_T c43_dataNumber);
static void c43_b_round(SFc43_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T *c43_x);
static void init_dsm_address_info(SFc43_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c43_update_debugger_state_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c43_st;
  const mxArray *c43_y = NULL;
  uint8_T c43_hoistedGlobal;
  uint8_T c43_u;
  const mxArray *c43_b_y = NULL;
  c43_st = NULL;
  c43_st = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_createcellmatrix(1, 1), false);
  c43_hoistedGlobal =
    chartInstance->c43_is_active_c43_lib_affectiveChar_behavior;
  c43_u = c43_hoistedGlobal;
  c43_b_y = NULL;
  sf_mex_assign(&c43_b_y, sf_mex_create("y", &c43_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 0, c43_b_y);
  sf_mex_assign(&c43_st, c43_y, false);
  return c43_st;
}

static void set_sim_state_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_st)
{
  const mxArray *c43_u;
  chartInstance->c43_doneDoubleBufferReInit = true;
  c43_u = sf_mex_dup(c43_st);
  chartInstance->c43_is_active_c43_lib_affectiveChar_behavior =
    c43_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 0)),
    "is_active_c43_lib_affectiveChar_behavior");
  sf_mex_assign(&chartInstance->c43_setSimStateSideEffectsInfo,
                c43_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c43_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c43_u);
  chartInstance->c43_doSetSimStateSideEffects = 1U;
  c43_update_debugger_state_c43_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c43_st);
}

static void c43_set_sim_state_side_effects_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c43_doSetSimStateSideEffects != 0) {
    chartInstance->c43_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c43_setSimStateSideEffectsInfo);
}

static void sf_gateway_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c43_set_sim_state_side_effects_c43_lib_affectiveChar_behavior(chartInstance);
}

static void c43_enter_atomic_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c43_sfEvent);
  chartInstance->c43_is_active_c43_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c43_sfEvent);
}

static void c43_enter_internal_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c43_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c43_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c43_sfEvent);
}

static void c43_exit_internal_c43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c43_initc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c43_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c43_doSetSimStateSideEffects = 0U;
  chartInstance->c43_setSimStateSideEffectsInfo = NULL;
  chartInstance->c43_is_active_c43_lib_affectiveChar_behavior = 0U;
}

static void initSimStructsc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber)
{
  (void)c43_machineNumber;
  (void)c43_chartNumber;
  (void)c43_instanceNumber;
}

static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(real_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static real_T c43_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  real_T c43_y;
  real_T c43_d0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_d0, 1, 0, 0U, 0, 0U, 0);
  c43_y = c43_d0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_blinkPeriodMax;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_blinkPeriodMax = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_blinkPeriodMax),
    &c43_thisId);
  sf_mex_destroy(&c43_blinkPeriodMax);
  *(real_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i0;
  real_T c43_b_inData[6];
  int32_T c43_i1;
  real_T c43_u[6];
  const mxArray *c43_y = NULL;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i0 = 0; c43_i0 < 6; c43_i0++) {
    c43_b_inData[c43_i0] = (*(real_T (*)[6])c43_inData)[c43_i0];
  }

  for (c43_i1 = 0; c43_i1 < 6; c43_i1++) {
    c43_u[c43_i1] = c43_b_inData[c43_i1];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static void c43_b_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId, real_T c43_y[6])
{
  real_T c43_dv0[6];
  int32_T c43_i2;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c43_i2 = 0; c43_i2 < 6; c43_i2++) {
    c43_y[c43_i2] = c43_dv0[c43_i2];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_gazeArr;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[6];
  int32_T c43_i3;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_gazeArr = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_gazeArr), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_gazeArr);
  for (c43_i3 = 0; c43_i3 < 6; c43_i3++) {
    (*(real_T (*)[6])c43_outData)[c43_i3] = c43_y[c43_i3];
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  boolean_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(boolean_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static boolean_T c43_c_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  boolean_T c43_y;
  boolean_T c43_b0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_b0, 1, 11, 0U, 0, 0U, 0);
  c43_y = c43_b0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_vaFlag;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  boolean_T c43_y;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_vaFlag = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_vaFlag),
    &c43_thisId);
  sf_mex_destroy(&c43_vaFlag);
  *(boolean_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

const mxArray *sf_c43_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c43_nameCaptureInfo = NULL;
  c43_nameCaptureInfo = NULL;
  sf_mex_assign(&c43_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c43_info_helper(&c43_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c43_nameCaptureInfo);
  return c43_nameCaptureInfo;
}

static void c43_info_helper(const mxArray **c43_info)
{
  const mxArray *c43_rhs0 = NULL;
  const mxArray *c43_lhs0 = NULL;
  const mxArray *c43_rhs1 = NULL;
  const mxArray *c43_lhs1 = NULL;
  const mxArray *c43_rhs2 = NULL;
  const mxArray *c43_lhs2 = NULL;
  const mxArray *c43_rhs3 = NULL;
  const mxArray *c43_lhs3 = NULL;
  const mxArray *c43_rhs4 = NULL;
  const mxArray *c43_lhs4 = NULL;
  const mxArray *c43_rhs5 = NULL;
  const mxArray *c43_lhs5 = NULL;
  const mxArray *c43_rhs6 = NULL;
  const mxArray *c43_lhs6 = NULL;
  const mxArray *c43_rhs7 = NULL;
  const mxArray *c43_lhs7 = NULL;
  const mxArray *c43_rhs8 = NULL;
  const mxArray *c43_lhs8 = NULL;
  const mxArray *c43_rhs9 = NULL;
  const mxArray *c43_lhs9 = NULL;
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("round"), "name", "name", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c43_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c43_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c43_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("mrdivide"), "name", "name",
                  3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c43_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c43_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c43_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c43_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c43_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c43_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c43_info, c43_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c43_info, c43_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c43_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c43_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c43_info, sf_mex_duplicatearraysafe(&c43_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c43_rhs0);
  sf_mex_destroy(&c43_lhs0);
  sf_mex_destroy(&c43_rhs1);
  sf_mex_destroy(&c43_lhs1);
  sf_mex_destroy(&c43_rhs2);
  sf_mex_destroy(&c43_lhs2);
  sf_mex_destroy(&c43_rhs3);
  sf_mex_destroy(&c43_lhs3);
  sf_mex_destroy(&c43_rhs4);
  sf_mex_destroy(&c43_lhs4);
  sf_mex_destroy(&c43_rhs5);
  sf_mex_destroy(&c43_lhs5);
  sf_mex_destroy(&c43_rhs6);
  sf_mex_destroy(&c43_lhs6);
  sf_mex_destroy(&c43_rhs7);
  sf_mex_destroy(&c43_lhs7);
  sf_mex_destroy(&c43_rhs8);
  sf_mex_destroy(&c43_lhs8);
  sf_mex_destroy(&c43_rhs9);
  sf_mex_destroy(&c43_lhs9);
}

static const mxArray *c43_emlrt_marshallOut(const char * c43_u)
{
  const mxArray *c43_y = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c43_u)), false);
  return c43_y;
}

static const mxArray *c43_b_emlrt_marshallOut(const uint32_T c43_u)
{
  const mxArray *c43_y = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 7, 0U, 0U, 0U, 0), false);
  return c43_y;
}

boolean_T sf_exported_auto_isStablec43_lib_affectiveChar_behavior(SimStruct
  *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  return true;
}

void sf_exported_auto_duringc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  c43_c43_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c43_enter_atomic_c43_lib_affectiveChar_behavior(chartInstance);
  c43_enter_internal_c43_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c43_exit_internal_c43_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_gatewayc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc43_lib_affectiveChar_behavior(SimStruct
  *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c43_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc43_lib_affectiveChar_behavior
  (SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc43_lib_affectiveChar_behavior(SimStruct
  *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc43_lib_affectiveChar_behavior(SimStruct
  *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc43_lib_affectiveChar_behavior(SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  c43_initc43_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec43_lib_affectiveChar_behavior
  (SimStruct *c43_S)
{
  const mxArray *c43_out = NULL;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  c43_out = NULL;
  sf_mex_assign(&c43_out,
                sf_internal_get_sim_state_c43_lib_affectiveChar_behavior(c43_S),
                false);
  return c43_out;
}

void sf_exported_auto_setSimstatec43_lib_affectiveChar_behavior(SimStruct *c43_S,
  const mxArray *c43_in)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c43_lib_affectiveChar_behavior(c43_S, sf_mex_dup
    (c43_in));
  sf_mex_destroy(&c43_in);
}

void sf_exported_auto_check_state_inconsistency_c43_lib_affectiveChar_behavior
  (SimStruct *c43_S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c43_setGazeFactorsc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c43_v,
   real_T c43_a, real_T c43_p, boolean_T c43_pFlag, boolean_T c43_vaFlag, real_T
   c43_gazeArr[6], real_T *c43_mutDurFactor, real_T *c43_avertDurFactor, real_T *
   c43_avertHeadFreqFactor, real_T *c43_avertHeadSpeed, real_T
   *c43_avertDirsChance, real_T *c43_avertFreqFactor, real_T *c43_mutFreqFactor,
   real_T *c43_blinkFlag, real_T *c43_blinkPeriodMin, real_T *c43_blinkPeriodMax)
{
  uint32_T c43_debug_family_var_map[18];
  real_T c43_nargin = 6.0;
  real_T c43_nargout = 10.0;
  real_T c43_A;
  real_T c43_x;
  real_T c43_b_x;
  real_T c43_c_x;
  real_T c43_y;
  real_T c43_d_x;
  real_T c43_e_x;
  real_T c43_b_A;
  real_T c43_f_x;
  real_T c43_g_x;
  real_T c43_h_x;
  real_T c43_b_y;
  real_T c43_i_x;
  real_T c43_j_x;
  real_T c43_k_x;
  real_T c43_l_x;
  real_T c43_m_x;
  real_T c43_n_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c43_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 0U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 1U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_v, 2U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_a, 3U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_p, 4U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pFlag, 5U, c43_c_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_vaFlag, 6U, c43_c_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_gazeArr, 7U, c43_b_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_mutDurFactor, 8U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_avertDurFactor, 9U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_avertHeadFreqFactor, 10U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_avertHeadSpeed, 11U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_avertDirsChance, 12U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_avertFreqFactor, 13U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_mutFreqFactor, 14U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_blinkFlag, 15U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_blinkPeriodMin, 16U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_blinkPeriodMax, 17U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 41);
  *c43_mutDurFactor = 1.0;
  c43_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 42);
  *c43_avertDurFactor = 1.0;
  c43_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 43);
  *c43_avertHeadFreqFactor = 20.0;
  c43_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 44);
  *c43_avertHeadSpeed = 1.0;
  c43_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 45);
  *c43_avertDirsChance = 0.0;
  c43_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 46);
  *c43_avertFreqFactor = 1.0;
  c43_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 47);
  *c43_mutFreqFactor = 1.0;
  c43_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 48);
  *c43_blinkFlag = 0.0;
  c43_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 49);
  *c43_blinkPeriodMin = 5.0;
  c43_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 50);
  *c43_blinkPeriodMax = 9.0;
  c43_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 52);
  if (CV_EML_IF(0, 1, 0, (real_T)c43_pFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 53);
    if (CV_EML_IF(0, 1, 1, c43_p == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 54);
      *c43_mutDurFactor = 2.0;
      c43_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 55);
      *c43_avertDurFactor = 0.5;
      c43_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 56);
      *c43_avertHeadFreqFactor = 30.0;
      c43_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 57);
      *c43_avertHeadSpeed = 2.0;
      c43_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 58);
      *c43_avertDirsChance = 1.0;
      c43_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 59);
      *c43_mutFreqFactor = 3.0;
      c43_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 60);
      *c43_avertFreqFactor = 0.5;
      c43_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 61);
      *c43_blinkFlag = 1.0;
      c43_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 62);
      *c43_blinkPeriodMin = 0.2;
      c43_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 63);
      *c43_blinkPeriodMax = 15.0;
      c43_updateDataWrittenToVector(chartInstance, 9U);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 64);
      if (CV_EML_IF(0, 1, 2, c43_p == 2.0)) {
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 65);
        *c43_mutDurFactor = 0.5;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 66);
        *c43_avertDurFactor = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 67);
        *c43_avertHeadFreqFactor = 15.0;
        c43_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 68);
        *c43_avertHeadSpeed = 3.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 69);
        *c43_avertDirsChance = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 70);
        *c43_mutFreqFactor = 0.5;
        c43_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 71);
        *c43_avertFreqFactor = 3.0;
        c43_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 72);
        *c43_blinkFlag = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 73);
        *c43_blinkPeriodMin = 0.2;
        c43_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 74);
        *c43_blinkPeriodMax = 9.0;
        c43_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 75);
        if (CV_EML_IF(0, 1, 3, c43_p == 3.0)) {
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 76);
          *c43_mutDurFactor = 4.0;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 77);
          *c43_avertDurFactor = 0.1;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 78);
          *c43_avertHeadFreqFactor = 25.0;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 79);
          *c43_avertHeadSpeed = 2.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 80);
          *c43_avertDirsChance = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 81);
          *c43_mutFreqFactor = 3.0;
          c43_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 82);
          *c43_avertFreqFactor = 0.5;
          c43_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 83);
          *c43_blinkFlag = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 84);
          *c43_blinkPeriodMin = 5.0;
          c43_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 85);
          *c43_blinkPeriodMax = 15.0;
          c43_updateDataWrittenToVector(chartInstance, 9U);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 87);
          *c43_mutDurFactor = 0.25;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 88);
          *c43_avertDurFactor = 0.5;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 89);
          *c43_avertHeadFreqFactor = 10.0;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 90);
          *c43_avertHeadSpeed = 3.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 91);
          *c43_avertDirsChance = 2.0;
          c43_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 92);
          *c43_mutFreqFactor = 0.5;
          c43_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 93);
          *c43_avertFreqFactor = 3.0;
          c43_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 94);
          *c43_blinkFlag = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 95);
          *c43_blinkPeriodMin = 5.0;
          c43_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 96);
          *c43_blinkPeriodMax = 9.0;
          c43_updateDataWrittenToVector(chartInstance, 9U);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 99);
  if (CV_EML_IF(0, 1, 4, (real_T)c43_vaFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 100);
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, c43_v > 50.0)) {
      if (CV_EML_COND(0, 1, 1, c43_a > 50.0)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 5, true);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 101);
        c43_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
        *c43_mutDurFactor *= 2.0;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 102);
        c43_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
        *c43_avertDurFactor *= 0.5;
        c43_b_round(chartInstance, c43_avertDurFactor);
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 103);
        c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
        c43_A = *c43_avertHeadFreqFactor;
        c43_x = c43_A;
        c43_b_x = c43_x;
        c43_c_x = c43_b_x;
        c43_y = c43_c_x / 3.0;
        *c43_avertHeadFreqFactor = c43_y;
        c43_b_round(chartInstance, c43_avertHeadFreqFactor);
        c43_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 104);
        *c43_avertHeadSpeed = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 105);
        *c43_blinkFlag = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 106);
        *c43_blinkPeriodMin = 0.5;
        c43_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 107);
        *c43_blinkPeriodMax = 5.0;
        c43_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 5, false);
      _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 109);
      guard2 = false;
      if (CV_EML_COND(0, 1, 2, c43_v < -50.0)) {
        if (CV_EML_COND(0, 1, 3, c43_a > 50.0)) {
          CV_EML_MCDC(0, 1, 1, true);
          CV_EML_IF(0, 1, 6, true);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 110);
          c43_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
          *c43_mutDurFactor *= 0.5;
          c43_b_round(chartInstance, c43_mutDurFactor);
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 111);
          c43_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          *c43_avertDurFactor *= 2.0;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 112);
          c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
          *c43_avertHeadFreqFactor += 30.0;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 113);
          *c43_avertHeadSpeed = 2.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 114);
          *c43_blinkFlag = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 115);
          *c43_blinkPeriodMin = 0.5;
          c43_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 116);
          *c43_blinkPeriodMax = 5.0;
          c43_updateDataWrittenToVector(chartInstance, 9U);
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 1, false);
        CV_EML_IF(0, 1, 6, false);
        _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 118);
        guard3 = false;
        if (CV_EML_COND(0, 1, 4, c43_v > 50.0)) {
          if (CV_EML_COND(0, 1, 5, c43_a < -50.0)) {
            CV_EML_MCDC(0, 1, 2, true);
            CV_EML_IF(0, 1, 7, true);
            _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 119);
            c43_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
            *c43_mutDurFactor *= 1.5;
            c43_b_round(chartInstance, c43_mutDurFactor);
            c43_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 120);
            c43_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
            c43_d_x = *c43_avertDurFactor * 0.75;
            *c43_avertDurFactor = c43_d_x;
            c43_e_x = *c43_avertDurFactor;
            *c43_avertDurFactor = c43_e_x;
            *c43_avertDurFactor = muDoubleScalarRound(*c43_avertDurFactor);
            c43_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 121);
            c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
            c43_b_A = *c43_avertHeadFreqFactor;
            c43_f_x = c43_b_A;
            c43_g_x = c43_f_x;
            c43_h_x = c43_g_x;
            c43_b_y = c43_h_x / 2.0;
            c43_i_x = c43_b_y;
            *c43_avertHeadFreqFactor = c43_i_x;
            c43_j_x = *c43_avertHeadFreqFactor;
            *c43_avertHeadFreqFactor = c43_j_x;
            *c43_avertHeadFreqFactor = muDoubleScalarRound
              (*c43_avertHeadFreqFactor);
            c43_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 122);
            *c43_avertHeadSpeed = 1.0;
            c43_updateDataWrittenToVector(chartInstance, 3U);
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(0, 1, 2, false);
          CV_EML_IF(0, 1, 7, false);
          _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 124);
          guard4 = false;
          if (CV_EML_COND(0, 1, 6, c43_v < -50.0)) {
            if (CV_EML_COND(0, 1, 7, c43_a < -50.0)) {
              CV_EML_MCDC(0, 1, 3, true);
              CV_EML_IF(0, 1, 8, true);
              _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 125);
              c43_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
              c43_k_x = *c43_mutDurFactor * 0.75;
              *c43_mutDurFactor = c43_k_x;
              c43_l_x = *c43_mutDurFactor;
              *c43_mutDurFactor = c43_l_x;
              *c43_mutDurFactor = muDoubleScalarRound(*c43_mutDurFactor);
              c43_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 126);
              c43_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
              c43_m_x = *c43_avertDurFactor * 1.5;
              *c43_avertDurFactor = c43_m_x;
              c43_n_x = *c43_avertDurFactor;
              *c43_avertDurFactor = c43_n_x;
              *c43_avertDurFactor = muDoubleScalarRound(*c43_avertDurFactor);
              c43_updateDataWrittenToVector(chartInstance, 1U);
              _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, MAX_int8_T);
              c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
              *c43_avertHeadFreqFactor += 20.0;
              c43_updateDataWrittenToVector(chartInstance, 2U);
              _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, 128U);
              *c43_avertHeadSpeed = 1.0;
              c43_updateDataWrittenToVector(chartInstance, 3U);
            } else {
              guard4 = true;
            }
          } else {
            guard4 = true;
          }

          if (guard4 == true) {
            CV_EML_MCDC(0, 1, 3, false);
            CV_EML_IF(0, 1, 8, false);
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c43_sfEvent, -128);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c43_setPoseFactorsc43_lib_affectiveChar_behavior
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c43_v,
   real_T c43_ar, real_T c43_p, boolean_T c43_pFlag, boolean_T c43_vaFlag,
   real_T c43_poseArr[6], real_T c43_personalityChange, real_T *c43_poseTwitch,
   real_T *c43_poseFreqFactor, real_T *c43_poseChanceFactor, real_T
   *c43_poseCatChance, real_T *c43_poseLean, real_T *c43_poseSpeed, real_T
   *c43_poseLeanFlag)
{
  uint32_T c43_debug_family_var_map[22];
  real_T c43_pose_custom_flag;
  real_T c43_pose_chance_custom;
  real_T c43_pose_selfAdaptor_chance_custom;
  real_T c43_pose_frequency_custom;
  real_T c43_pose_speed_custom;
  real_T c43_pose_lean_custom;
  real_T c43_nargin = 7.0;
  real_T c43_nargout = 7.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c43_b_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pose_custom_flag, 0U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pose_chance_custom, 1U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pose_selfAdaptor_chance_custom, 2U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pose_frequency_custom, 3U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pose_speed_custom, 4U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pose_lean_custom, 5U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 6U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 7U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_v, 8U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_ar, 9U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_p, 10U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_pFlag, 11U, c43_c_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_vaFlag, 12U, c43_c_sf_marshallOut,
    c43_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseArr, 13U, c43_b_sf_marshallOut,
    c43_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_personalityChange, 14U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseTwitch, 15U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseFreqFactor, 16U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseChanceFactor, 17U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseCatChance, 18U,
    c43_sf_marshallOut, c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseLean, 19U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseSpeed, 20U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c43_poseLeanFlag, 21U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 3);
  c43_pose_custom_flag = c43_poseArr[0];
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 4);
  c43_pose_chance_custom = c43_poseArr[2];
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 5);
  c43_pose_selfAdaptor_chance_custom = c43_poseArr[1];
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 6);
  c43_pose_frequency_custom = c43_poseArr[3];
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 7);
  c43_pose_speed_custom = c43_poseArr[4];
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 8);
  c43_pose_lean_custom = c43_poseArr[5];
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 10);
  *c43_poseCatChance = 70.0;
  c43_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 11);
  *c43_poseChanceFactor = 1.0;
  c43_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 12);
  *c43_poseFreqFactor = 20.0;
  c43_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 13);
  *c43_poseSpeed = 0.0;
  c43_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 14);
  *c43_poseLean = 10.0;
  c43_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 15);
  *c43_poseTwitch = 0.0;
  c43_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 16);
  *c43_poseLeanFlag = 0.0;
  c43_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 18);
  if (CV_EML_IF(1, 1, 0, c43_pose_custom_flag == 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 19);
    if (CV_EML_IF(1, 1, 1, (real_T)c43_pFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 20);
      if (CV_EML_IF(1, 1, 2, c43_personalityChange == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 21);
        *c43_poseLeanFlag = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 16U);
      }

      _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 23);
      if (CV_EML_IF(1, 1, 3, c43_p == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 24);
        *c43_poseTwitch = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 25);
        *c43_poseFreqFactor = 10.0;
        c43_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 26);
        *c43_poseLean = 11.0;
        c43_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 27);
        *c43_poseChanceFactor = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 28);
        *c43_poseCatChance = 90.0;
        c43_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 29);
        *c43_poseSpeed = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 15U);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 30);
        if (CV_EML_IF(1, 1, 4, c43_p == 2.0)) {
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 31);
          *c43_poseTwitch = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 32);
          *c43_poseFreqFactor = 17.0;
          c43_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 33);
          *c43_poseLean = 12.0;
          c43_updateDataWrittenToVector(chartInstance, 14U);
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 34);
          *c43_poseChanceFactor = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 12U);
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 35);
          *c43_poseCatChance = 10.0;
          c43_updateDataWrittenToVector(chartInstance, 13U);
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 36);
          *c43_poseSpeed = 3.0;
          c43_updateDataWrittenToVector(chartInstance, 15U);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 37);
          if (CV_EML_IF(1, 1, 5, c43_p == 3.0)) {
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 38);
            *c43_poseTwitch = 0.0;
            c43_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 39);
            *c43_poseFreqFactor = 12.0;
            c43_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 40);
            *c43_poseLean = 11.0;
            c43_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 41);
            *c43_poseChanceFactor = 2.0;
            c43_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 42);
            *c43_poseCatChance = 10.0;
            c43_updateDataWrittenToVector(chartInstance, 13U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 43);
            *c43_poseSpeed = 2.0;
            c43_updateDataWrittenToVector(chartInstance, 15U);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 45);
            *c43_poseTwitch = 0.0;
            c43_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 46);
            *c43_poseFreqFactor = 20.0;
            c43_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 47);
            *c43_poseLean = 12.0;
            c43_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 48);
            *c43_poseChanceFactor = 1.0;
            c43_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 49);
            *c43_poseCatChance = 90.0;
            c43_updateDataWrittenToVector(chartInstance, 13U);
            _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 50);
            *c43_poseSpeed = 3.0;
            c43_updateDataWrittenToVector(chartInstance, 15U);
          }
        }
      }
    }

    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 56);
    if (CV_EML_IF(1, 1, 6, (real_T)c43_vaFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 57);
      if (CV_EML_IF(1, 1, 7, c43_ar > 50.0)) {
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 58);
        *c43_poseSpeed = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 59);
        *c43_poseLeanFlag = 12.0;
        c43_updateDataWrittenToVector(chartInstance, 16U);
      }

      _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 61);
      if (CV_EML_IF(1, 1, 8, c43_ar < -50.0)) {
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 62);
        *c43_poseSpeed = 3.0;
        c43_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 63);
        *c43_poseLeanFlag = 11.0;
        c43_updateDataWrittenToVector(chartInstance, 16U);
      }
    }
  } else {
    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 67);
    *c43_poseFreqFactor = c43_pose_frequency_custom;
    c43_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 68);
    *c43_poseLean = c43_pose_lean_custom;
    c43_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 69);
    *c43_poseChanceFactor = c43_pose_chance_custom;
    c43_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 70);
    *c43_poseCatChance = c43_pose_selfAdaptor_chance_custom;
    c43_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, 71);
    *c43_poseSpeed = c43_pose_speed_custom;
    c43_updateDataWrittenToVector(chartInstance, 15U);
  }

  _SFD_EML_CALL(1U, chartInstance->c43_sfEvent, -71);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c43_round(SFc43_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c43_x)
{
  real_T c43_b_x;
  c43_b_x = c43_x;
  c43_b_round(chartInstance, &c43_b_x);
  return c43_b_x;
}

void sf_exported_user_c43_lib_affectiveChar_behavior_setGazeFactors(SimStruct
  *c43_S, real_T c43_v, real_T c43_a, real_T c43_p, boolean_T c43_pFlag,
  boolean_T c43_vaFlag, real_T c43_gazeArr[6], real_T *c43_mutDurFactor, real_T *
  c43_avertDurFactor, real_T *c43_avertHeadFreqFactor, real_T
  *c43_avertHeadSpeed, real_T *c43_avertDirsChance, real_T *c43_avertFreqFactor,
  real_T *c43_mutFreqFactor, real_T *c43_blinkFlag, real_T *c43_blinkPeriodMin,
  real_T *c43_blinkPeriodMax)
{
  int32_T c43_i4;
  real_T c43_b_gazeArr[6];
  real_T c43_b_blinkPeriodMax;
  real_T c43_b_blinkPeriodMin;
  real_T c43_b_blinkFlag;
  real_T c43_b_mutFreqFactor;
  real_T c43_b_avertFreqFactor;
  real_T c43_b_avertDirsChance;
  real_T c43_b_avertHeadSpeed;
  real_T c43_b_avertHeadFreqFactor;
  real_T c43_b_avertDurFactor;
  real_T c43_b_mutDurFactor;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  for (c43_i4 = 0; c43_i4 < 6; c43_i4++) {
    c43_b_gazeArr[c43_i4] = c43_gazeArr[c43_i4];
  }

  c43_setGazeFactorsc43_lib_affectiveChar_behavior(chartInstance, c43_v, c43_a,
    c43_p, c43_pFlag, c43_vaFlag, c43_b_gazeArr, &c43_b_mutDurFactor,
    &c43_b_avertDurFactor, &c43_b_avertHeadFreqFactor, &c43_b_avertHeadSpeed,
    &c43_b_avertDirsChance, &c43_b_avertFreqFactor, &c43_b_mutFreqFactor,
    &c43_b_blinkFlag, &c43_b_blinkPeriodMin, &c43_b_blinkPeriodMax);
  *c43_mutDurFactor = c43_b_mutDurFactor;
  *c43_avertDurFactor = c43_b_avertDurFactor;
  *c43_avertHeadFreqFactor = c43_b_avertHeadFreqFactor;
  *c43_avertHeadSpeed = c43_b_avertHeadSpeed;
  *c43_avertDirsChance = c43_b_avertDirsChance;
  *c43_avertFreqFactor = c43_b_avertFreqFactor;
  *c43_mutFreqFactor = c43_b_mutFreqFactor;
  *c43_blinkFlag = c43_b_blinkFlag;
  *c43_blinkPeriodMin = c43_b_blinkPeriodMin;
  *c43_blinkPeriodMax = c43_b_blinkPeriodMax;
}

void sf_exported_user_c43_lib_affectiveChar_behavior_setPoseFactors(SimStruct
  *c43_S, real_T c43_v, real_T c43_ar, real_T c43_p, boolean_T c43_pFlag,
  boolean_T c43_vaFlag, real_T c43_poseArr[6], real_T c43_personalityChange,
  real_T *c43_poseTwitch, real_T *c43_poseFreqFactor, real_T
  *c43_poseChanceFactor, real_T *c43_poseCatChance, real_T *c43_poseLean, real_T
  *c43_poseSpeed, real_T *c43_poseLeanFlag)
{
  int32_T c43_i5;
  real_T c43_b_poseArr[6];
  real_T c43_b_poseLeanFlag;
  real_T c43_b_poseSpeed;
  real_T c43_b_poseLean;
  real_T c43_b_poseCatChance;
  real_T c43_b_poseChanceFactor;
  real_T c43_b_poseFreqFactor;
  real_T c43_b_poseTwitch;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)
    ->chartInstance;
  for (c43_i5 = 0; c43_i5 < 6; c43_i5++) {
    c43_b_poseArr[c43_i5] = c43_poseArr[c43_i5];
  }

  c43_setPoseFactorsc43_lib_affectiveChar_behavior(chartInstance, c43_v, c43_ar,
    c43_p, c43_pFlag, c43_vaFlag, c43_b_poseArr, c43_personalityChange,
    &c43_b_poseTwitch, &c43_b_poseFreqFactor, &c43_b_poseChanceFactor,
    &c43_b_poseCatChance, &c43_b_poseLean, &c43_b_poseSpeed, &c43_b_poseLeanFlag);
  *c43_poseTwitch = c43_b_poseTwitch;
  *c43_poseFreqFactor = c43_b_poseFreqFactor;
  *c43_poseChanceFactor = c43_b_poseChanceFactor;
  *c43_poseCatChance = c43_b_poseCatChance;
  *c43_poseLean = c43_b_poseLean;
  *c43_poseSpeed = c43_b_poseSpeed;
  *c43_poseLeanFlag = c43_b_poseLeanFlag;
}

static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(int32_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static int32_T c43_d_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  int32_T c43_y;
  int32_T c43_i6;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_i6, 1, 6, 0U, 0, 0U, 0);
  c43_y = c43_i6;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_sfEvent;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  int32_T c43_y;
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c43_b_sfEvent = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_sfEvent),
    &c43_thisId);
  sf_mex_destroy(&c43_b_sfEvent);
  *(int32_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static uint8_T c43_e_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_b_is_active_c43_lib_affectiveChar_behavior, const char_T *c43_identifier)
{
  uint8_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_is_active_c43_lib_affectiveChar_behavior), &c43_thisId);
  sf_mex_destroy(&c43_b_is_active_c43_lib_affectiveChar_behavior);
  return c43_y;
}

static uint8_T c43_f_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  uint8_T c43_y;
  uint8_T c43_u0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_u0, 1, 3, 0U, 0, 0U, 0);
  c43_y = c43_u0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static const mxArray *c43_g_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_b_setSimStateSideEffectsInfo, const char_T *c43_identifier)
{
  const mxArray *c43_y = NULL;
  emlrtMsgIdentifier c43_thisId;
  c43_y = NULL;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  sf_mex_assign(&c43_y, c43_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_setSimStateSideEffectsInfo), &c43_thisId), false);
  sf_mex_destroy(&c43_b_setSimStateSideEffectsInfo);
  return c43_y;
}

static const mxArray *c43_h_emlrt_marshallIn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  const mxArray *c43_y = NULL;
  (void)chartInstance;
  (void)c43_parentId;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_duplicatearraysafe(&c43_u), false);
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_updateDataWrittenToVector
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c43_vectorIndex)
{
  (void)chartInstance;
  c43_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c43_vectorIndex, 0, 16, 1, 0)] = true;
}

static void c43_errorIfDataNotWrittenToFcn
  (SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c43_vectorIndex, uint32_T c43_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c43_dataNumber, c43_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c43_vectorIndex, 0, 16, 1,
    0)]);
}

static void c43_b_round(SFc43_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T *c43_x)
{
  (void)chartInstance;
  *c43_x = muDoubleScalarRound(*c43_x);
}

static void init_dsm_address_info(SFc43_lib_affectiveChar_behaviorInstanceStruct
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

void sf_c43_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1703856241U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(409122497U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3953863621U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2848578871U);
}

mxArray *sf_c43_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SLinMblF8LvrBWU1H7Yj3E");
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

mxArray *sf_c43_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c43_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c43_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c43_lib_affectiveChar_behavior\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c43_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           43,
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc43_lib_affectiveChar_behavior",
                             0,-1,6574);
        _SFD_CV_INIT_EML_IF(0,1,0,3117,3129,-1,5164);
        _SFD_CV_INIT_EML_IF(0,1,1,3138,3146,3814,5154);
        _SFD_CV_INIT_EML_IF(0,1,2,3814,3826,4288,5154);
        _SFD_CV_INIT_EML_IF(0,1,3,4288,4300,4730,5154);
        _SFD_CV_INIT_EML_IF(0,1,4,5169,5182,-1,6574);
        _SFD_CV_INIT_EML_IF(0,1,5,5195,5211,5586,5607);
        _SFD_CV_INIT_EML_IF(0,1,6,5586,5607,5966,6566);
        _SFD_CV_INIT_EML_IF(0,1,7,5966,5987,6271,6566);
        _SFD_CV_INIT_EML_IF(0,1,8,6271,6293,-1,6293);

        {
          static int condStart[] = { 5198, 5206 };

          static int condEnd[] = { 5202, 5210 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,5198,5210,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5593, 5602 };

          static int condEnd[] = { 5598, 5606 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,5593,5606,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5973, 5981 };

          static int condEnd[] = { 5977, 5986 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,5973,5986,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6278, 6287 };

          static int condEnd[] = { 6283, 6292 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,6278,6292,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,1,1,9,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc43_lib_affectiveChar_behavior",
                             0,-1,2596);
        _SFD_CV_INIT_EML_IF(1,1,0,574,597,2351,2595);
        _SFD_CV_INIT_EML_IF(1,1,1,610,622,-1,1983);
        _SFD_CV_INIT_EML_IF(1,1,2,635,659,-1,707);
        _SFD_CV_INIT_EML_IF(1,1,3,720,728,1149,1971);
        _SFD_CV_INIT_EML_IF(1,1,4,1149,1161,1451,1971);
        _SFD_CV_INIT_EML_IF(1,1,5,1451,1463,1729,1971);
        _SFD_CV_INIT_EML_IF(1,1,6,2058,2071,-1,2345);
        _SFD_CV_INIT_EML_IF(1,1,7,2080,2090,-1,2204);
        _SFD_CV_INIT_EML_IF(1,1,8,2213,2223,-1,2337);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_c_sf_marshallOut,(MexInFcnForType)
          c43_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_c_sf_marshallOut,(MexInFcnForType)
          c43_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)
            c43_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_c_sf_marshallOut,(MexInFcnForType)
          c43_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_c_sf_marshallOut,(MexInFcnForType)
          c43_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)
            c43_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
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
        _lib_affectiveChar_behaviorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "EEkwMQPTFGpyPXlMiEsqgB";
}

static void sf_opaque_initialize_c43_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc43_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c43_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c43_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c43_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c43_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c43_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c43_lib_affectiveChar_behavior(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c43_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c43_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c43_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c43_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc43_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c43_lib_affectiveChar_behavior
      ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc43_lib_affectiveChar_behavior
    ((SFc43_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c43_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c43_lib_affectiveChar_behavior
      ((SFc43_lib_affectiveChar_behaviorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c43_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      43);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,43,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,43,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,43);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,43);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3764566944U));
  ssSetChecksum1(S,(1918435304U));
  ssSetChecksum2(S,(3183064880U));
  ssSetChecksum3(S,(3868990245U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c43_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c43_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc43_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc43_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc43_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc43_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c43_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c43_lib_affectiveChar_behavior;
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

void c43_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c43_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c43_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c43_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c43_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
