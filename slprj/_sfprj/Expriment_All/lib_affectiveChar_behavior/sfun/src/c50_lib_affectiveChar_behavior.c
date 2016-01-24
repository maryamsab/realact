/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c50_lib_affectiveChar_behavior.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c50_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c50_debug_family_names[20] = { "nargin", "nargout", "v", "a",
  "p", "pFlag", "vaFlag", "gazeArr", "personalityChange", "firstTimeFlag",
  "mutDurFactor", "avertDurFactor", "avertHeadFreqFactor", "avertHeadSpeed",
  "avertDirsChance", "avertFreqFactor", "mutFreqFactor", "blinkFlag",
  "blinkPeriodMin", "blinkPeriodMax" };

static const char * c50_b_debug_family_names[23] = { "pose_custom_flag",
  "pose_chance_custom", "pose_selfAdaptor_chance_custom",
  "pose_frequency_custom", "pose_speed_custom", "pose_lean_custom", "nargin",
  "nargout", "v", "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange",
  "poseTwitch", "poseFreqFactor", "poseChanceFactor", "poseCatChance",
  "poseLean", "poseSpeed", "poseSpace", "poseLeanFlag" };

static boolean_T c50_dataWrittenToVector[18];

/* Function Declarations */
static void initialize_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c50_update_debugger_state_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_st);
static void c50_set_sim_state_side_effects_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c50_enter_atomic_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c50_enter_internal_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c50_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c50_exit_internal_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c50_initc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_emlrt_marshallIn(SFc50_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[6]);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static boolean_T c50_b_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static void c50_info_helper(const mxArray **c50_info);
static const mxArray *c50_emlrt_marshallOut(const char * c50_u);
static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u);
static void c50_setGazeFactorsc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c50_v,
   real_T c50_a, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag, real_T
   c50_gazeArr[6], real_T c50_personalityChange, real_T c50_firstTimeFlag,
   real_T *c50_mutDurFactor, real_T *c50_avertDurFactor, real_T
   *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
   *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
   real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax);
static void c50_setPoseFactorsc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c50_v,
   real_T c50_ar, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag,
   real_T c50_poseArr[6], real_T c50_personalityChange, real_T *c50_poseTwitch,
   real_T *c50_poseFreqFactor, real_T *c50_poseChanceFactor, real_T
   *c50_poseCatChance, real_T *c50_poseLean, real_T *c50_poseSpeed, real_T
   *c50_poseSpace, real_T *c50_poseLeanFlag);
static real_T c50_round(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c50_x);
static void c50_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c50_isequal(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static real_T c50_b_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c50_c_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c50_formatSpec);
static real_T c50_d_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c50_varargin_1);
static real_T c50_c_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_feval, const char_T *c50_identifier);
static real_T c50_d_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId);
static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int32_T c50_e_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static uint8_T c50_f_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_b_is_active_c50_lib_affectiveChar_behavior, const char_T *c50_identifier);
static uint8_T c50_g_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId);
static const mxArray *c50_h_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_b_setSimStateSideEffectsInfo, const char_T *c50_identifier);
static const mxArray *c50_i_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_updateDataWrittenToVector
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c50_vectorIndex);
static void c50_errorIfDataNotWrittenToFcn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c50_vectorIndex, uint32_T c50_dataNumber);
static void c50_b_round(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T *c50_x);
static void init_dsm_address_info(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_update_debugger_state_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
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
  c50_hoistedGlobal =
    chartInstance->c50_is_active_c50_lib_affectiveChar_behavior;
  c50_u = c50_hoistedGlobal;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  sf_mex_assign(&c50_st, c50_y, false);
  return c50_st;
}

static void set_sim_state_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_st)
{
  const mxArray *c50_u;
  chartInstance->c50_doneDoubleBufferReInit = true;
  c50_u = sf_mex_dup(c50_st);
  chartInstance->c50_is_active_c50_lib_affectiveChar_behavior =
    c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 0)),
    "is_active_c50_lib_affectiveChar_behavior");
  sf_mex_assign(&chartInstance->c50_setSimStateSideEffectsInfo,
                c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c50_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c50_u);
  chartInstance->c50_doSetSimStateSideEffects = 1U;
  c50_update_debugger_state_c50_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void c50_set_sim_state_side_effects_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c50_doSetSimStateSideEffects != 0) {
    chartInstance->c50_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c50_setSimStateSideEffectsInfo);
}

static void sf_gateway_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c50_set_sim_state_side_effects_c50_lib_affectiveChar_behavior(chartInstance);
}

static void c50_enter_atomic_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c50_sfEvent);
  chartInstance->c50_is_active_c50_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c50_sfEvent);
}

static void c50_enter_internal_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c50_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c50_sfEvent);
}

static void c50_exit_internal_c50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_initc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c50_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_doSetSimStateSideEffects = 0U;
  chartInstance->c50_setSimStateSideEffectsInfo = NULL;
  chartInstance->c50_is_active_c50_lib_affectiveChar_behavior = 0U;
}

static void initSimStructsc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_feval;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_feval = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_feval),
    &c50_thisId);
  sf_mex_destroy(&c50_feval);
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
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

static void c50_emlrt_marshallIn(SFc50_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_gazeArr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_gazeArr), &c50_thisId,
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(boolean_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static boolean_T c50_b_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId)
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_vaFlag = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_vaFlag),
    &c50_thisId);
  sf_mex_destroy(&c50_vaFlag);
  *(boolean_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

const mxArray *sf_c50_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_createstruct("structure", 2, 59, 1),
                false);
  c50_info_helper(&c50_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c50_nameCaptureInfo);
  return c50_nameCaptureInfo;
}

static void c50_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs0 = NULL;
  const mxArray *c50_lhs0 = NULL;
  const mxArray *c50_rhs1 = NULL;
  const mxArray *c50_lhs1 = NULL;
  const mxArray *c50_rhs2 = NULL;
  const mxArray *c50_lhs2 = NULL;
  const mxArray *c50_rhs3 = NULL;
  const mxArray *c50_lhs3 = NULL;
  const mxArray *c50_rhs4 = NULL;
  const mxArray *c50_lhs4 = NULL;
  const mxArray *c50_rhs5 = NULL;
  const mxArray *c50_lhs5 = NULL;
  const mxArray *c50_rhs6 = NULL;
  const mxArray *c50_lhs6 = NULL;
  const mxArray *c50_rhs7 = NULL;
  const mxArray *c50_lhs7 = NULL;
  const mxArray *c50_rhs8 = NULL;
  const mxArray *c50_lhs8 = NULL;
  const mxArray *c50_rhs9 = NULL;
  const mxArray *c50_lhs9 = NULL;
  const mxArray *c50_rhs10 = NULL;
  const mxArray *c50_lhs10 = NULL;
  const mxArray *c50_rhs11 = NULL;
  const mxArray *c50_lhs11 = NULL;
  const mxArray *c50_rhs12 = NULL;
  const mxArray *c50_lhs12 = NULL;
  const mxArray *c50_rhs13 = NULL;
  const mxArray *c50_lhs13 = NULL;
  const mxArray *c50_rhs14 = NULL;
  const mxArray *c50_lhs14 = NULL;
  const mxArray *c50_rhs15 = NULL;
  const mxArray *c50_lhs15 = NULL;
  const mxArray *c50_rhs16 = NULL;
  const mxArray *c50_lhs16 = NULL;
  const mxArray *c50_rhs17 = NULL;
  const mxArray *c50_lhs17 = NULL;
  const mxArray *c50_rhs18 = NULL;
  const mxArray *c50_lhs18 = NULL;
  const mxArray *c50_rhs19 = NULL;
  const mxArray *c50_lhs19 = NULL;
  const mxArray *c50_rhs20 = NULL;
  const mxArray *c50_lhs20 = NULL;
  const mxArray *c50_rhs21 = NULL;
  const mxArray *c50_lhs21 = NULL;
  const mxArray *c50_rhs22 = NULL;
  const mxArray *c50_lhs22 = NULL;
  const mxArray *c50_rhs23 = NULL;
  const mxArray *c50_lhs23 = NULL;
  const mxArray *c50_rhs24 = NULL;
  const mxArray *c50_lhs24 = NULL;
  const mxArray *c50_rhs25 = NULL;
  const mxArray *c50_lhs25 = NULL;
  const mxArray *c50_rhs26 = NULL;
  const mxArray *c50_lhs26 = NULL;
  const mxArray *c50_rhs27 = NULL;
  const mxArray *c50_lhs27 = NULL;
  const mxArray *c50_rhs28 = NULL;
  const mxArray *c50_lhs28 = NULL;
  const mxArray *c50_rhs29 = NULL;
  const mxArray *c50_lhs29 = NULL;
  const mxArray *c50_rhs30 = NULL;
  const mxArray *c50_lhs30 = NULL;
  const mxArray *c50_rhs31 = NULL;
  const mxArray *c50_lhs31 = NULL;
  const mxArray *c50_rhs32 = NULL;
  const mxArray *c50_lhs32 = NULL;
  const mxArray *c50_rhs33 = NULL;
  const mxArray *c50_lhs33 = NULL;
  const mxArray *c50_rhs34 = NULL;
  const mxArray *c50_lhs34 = NULL;
  const mxArray *c50_rhs35 = NULL;
  const mxArray *c50_lhs35 = NULL;
  const mxArray *c50_rhs36 = NULL;
  const mxArray *c50_lhs36 = NULL;
  const mxArray *c50_rhs37 = NULL;
  const mxArray *c50_lhs37 = NULL;
  const mxArray *c50_rhs38 = NULL;
  const mxArray *c50_lhs38 = NULL;
  const mxArray *c50_rhs39 = NULL;
  const mxArray *c50_lhs39 = NULL;
  const mxArray *c50_rhs40 = NULL;
  const mxArray *c50_lhs40 = NULL;
  const mxArray *c50_rhs41 = NULL;
  const mxArray *c50_lhs41 = NULL;
  const mxArray *c50_rhs42 = NULL;
  const mxArray *c50_lhs42 = NULL;
  const mxArray *c50_rhs43 = NULL;
  const mxArray *c50_lhs43 = NULL;
  const mxArray *c50_rhs44 = NULL;
  const mxArray *c50_lhs44 = NULL;
  const mxArray *c50_rhs45 = NULL;
  const mxArray *c50_lhs45 = NULL;
  const mxArray *c50_rhs46 = NULL;
  const mxArray *c50_lhs46 = NULL;
  const mxArray *c50_rhs47 = NULL;
  const mxArray *c50_lhs47 = NULL;
  const mxArray *c50_rhs48 = NULL;
  const mxArray *c50_lhs48 = NULL;
  const mxArray *c50_rhs49 = NULL;
  const mxArray *c50_lhs49 = NULL;
  const mxArray *c50_rhs50 = NULL;
  const mxArray *c50_lhs50 = NULL;
  const mxArray *c50_rhs51 = NULL;
  const mxArray *c50_lhs51 = NULL;
  const mxArray *c50_rhs52 = NULL;
  const mxArray *c50_lhs52 = NULL;
  const mxArray *c50_rhs53 = NULL;
  const mxArray *c50_lhs53 = NULL;
  const mxArray *c50_rhs54 = NULL;
  const mxArray *c50_lhs54 = NULL;
  const mxArray *c50_rhs55 = NULL;
  const mxArray *c50_lhs55 = NULL;
  const mxArray *c50_rhs56 = NULL;
  const mxArray *c50_lhs56 = NULL;
  const mxArray *c50_rhs57 = NULL;
  const mxArray *c50_lhs57 = NULL;
  const mxArray *c50_rhs58 = NULL;
  const mxArray *c50_lhs58 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("disp"), "name", "name", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 0);
  sf_mex_assign(&c50_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("disp"), "name", "name", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 1);
  sf_mex_assign(&c50_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("round"), "name", "name", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c50_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c50_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c50_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mrdivide"), "name", "name",
                  5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c50_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c50_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("rdivide"), "name", "name", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c50_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c50_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c50_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_div"), "name", "name",
                  10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c50_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c50_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name",
                  12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c50_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isequal"), "name", "name",
                  13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c50_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c50_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isnan"), "name", "name", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c50_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c50_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c50_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name",
                  18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c50_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("upper"), "name", "name", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c50_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c50_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c50_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c50_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c50_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c50_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c50_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("colon"), "name", "name", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c50_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("colon"), "name", "name", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c50_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c50_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c50_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("floor"), "name", "name", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c50_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c50_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c50_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c50_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c50_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c50_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c50_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c50_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c50_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c50_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c50_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c50_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c50_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c50_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c50_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c50_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c50_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c50_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c50_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c50_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "name", "name", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c50_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fidCheck"), "name", "name",
                  51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c50_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("upper"), "name", "name", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c50_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c50_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c50_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c50_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c50_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c50_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c50_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs58), "lhs", "lhs",
                  58);
  sf_mex_destroy(&c50_rhs0);
  sf_mex_destroy(&c50_lhs0);
  sf_mex_destroy(&c50_rhs1);
  sf_mex_destroy(&c50_lhs1);
  sf_mex_destroy(&c50_rhs2);
  sf_mex_destroy(&c50_lhs2);
  sf_mex_destroy(&c50_rhs3);
  sf_mex_destroy(&c50_lhs3);
  sf_mex_destroy(&c50_rhs4);
  sf_mex_destroy(&c50_lhs4);
  sf_mex_destroy(&c50_rhs5);
  sf_mex_destroy(&c50_lhs5);
  sf_mex_destroy(&c50_rhs6);
  sf_mex_destroy(&c50_lhs6);
  sf_mex_destroy(&c50_rhs7);
  sf_mex_destroy(&c50_lhs7);
  sf_mex_destroy(&c50_rhs8);
  sf_mex_destroy(&c50_lhs8);
  sf_mex_destroy(&c50_rhs9);
  sf_mex_destroy(&c50_lhs9);
  sf_mex_destroy(&c50_rhs10);
  sf_mex_destroy(&c50_lhs10);
  sf_mex_destroy(&c50_rhs11);
  sf_mex_destroy(&c50_lhs11);
  sf_mex_destroy(&c50_rhs12);
  sf_mex_destroy(&c50_lhs12);
  sf_mex_destroy(&c50_rhs13);
  sf_mex_destroy(&c50_lhs13);
  sf_mex_destroy(&c50_rhs14);
  sf_mex_destroy(&c50_lhs14);
  sf_mex_destroy(&c50_rhs15);
  sf_mex_destroy(&c50_lhs15);
  sf_mex_destroy(&c50_rhs16);
  sf_mex_destroy(&c50_lhs16);
  sf_mex_destroy(&c50_rhs17);
  sf_mex_destroy(&c50_lhs17);
  sf_mex_destroy(&c50_rhs18);
  sf_mex_destroy(&c50_lhs18);
  sf_mex_destroy(&c50_rhs19);
  sf_mex_destroy(&c50_lhs19);
  sf_mex_destroy(&c50_rhs20);
  sf_mex_destroy(&c50_lhs20);
  sf_mex_destroy(&c50_rhs21);
  sf_mex_destroy(&c50_lhs21);
  sf_mex_destroy(&c50_rhs22);
  sf_mex_destroy(&c50_lhs22);
  sf_mex_destroy(&c50_rhs23);
  sf_mex_destroy(&c50_lhs23);
  sf_mex_destroy(&c50_rhs24);
  sf_mex_destroy(&c50_lhs24);
  sf_mex_destroy(&c50_rhs25);
  sf_mex_destroy(&c50_lhs25);
  sf_mex_destroy(&c50_rhs26);
  sf_mex_destroy(&c50_lhs26);
  sf_mex_destroy(&c50_rhs27);
  sf_mex_destroy(&c50_lhs27);
  sf_mex_destroy(&c50_rhs28);
  sf_mex_destroy(&c50_lhs28);
  sf_mex_destroy(&c50_rhs29);
  sf_mex_destroy(&c50_lhs29);
  sf_mex_destroy(&c50_rhs30);
  sf_mex_destroy(&c50_lhs30);
  sf_mex_destroy(&c50_rhs31);
  sf_mex_destroy(&c50_lhs31);
  sf_mex_destroy(&c50_rhs32);
  sf_mex_destroy(&c50_lhs32);
  sf_mex_destroy(&c50_rhs33);
  sf_mex_destroy(&c50_lhs33);
  sf_mex_destroy(&c50_rhs34);
  sf_mex_destroy(&c50_lhs34);
  sf_mex_destroy(&c50_rhs35);
  sf_mex_destroy(&c50_lhs35);
  sf_mex_destroy(&c50_rhs36);
  sf_mex_destroy(&c50_lhs36);
  sf_mex_destroy(&c50_rhs37);
  sf_mex_destroy(&c50_lhs37);
  sf_mex_destroy(&c50_rhs38);
  sf_mex_destroy(&c50_lhs38);
  sf_mex_destroy(&c50_rhs39);
  sf_mex_destroy(&c50_lhs39);
  sf_mex_destroy(&c50_rhs40);
  sf_mex_destroy(&c50_lhs40);
  sf_mex_destroy(&c50_rhs41);
  sf_mex_destroy(&c50_lhs41);
  sf_mex_destroy(&c50_rhs42);
  sf_mex_destroy(&c50_lhs42);
  sf_mex_destroy(&c50_rhs43);
  sf_mex_destroy(&c50_lhs43);
  sf_mex_destroy(&c50_rhs44);
  sf_mex_destroy(&c50_lhs44);
  sf_mex_destroy(&c50_rhs45);
  sf_mex_destroy(&c50_lhs45);
  sf_mex_destroy(&c50_rhs46);
  sf_mex_destroy(&c50_lhs46);
  sf_mex_destroy(&c50_rhs47);
  sf_mex_destroy(&c50_lhs47);
  sf_mex_destroy(&c50_rhs48);
  sf_mex_destroy(&c50_lhs48);
  sf_mex_destroy(&c50_rhs49);
  sf_mex_destroy(&c50_lhs49);
  sf_mex_destroy(&c50_rhs50);
  sf_mex_destroy(&c50_lhs50);
  sf_mex_destroy(&c50_rhs51);
  sf_mex_destroy(&c50_lhs51);
  sf_mex_destroy(&c50_rhs52);
  sf_mex_destroy(&c50_lhs52);
  sf_mex_destroy(&c50_rhs53);
  sf_mex_destroy(&c50_lhs53);
  sf_mex_destroy(&c50_rhs54);
  sf_mex_destroy(&c50_lhs54);
  sf_mex_destroy(&c50_rhs55);
  sf_mex_destroy(&c50_lhs55);
  sf_mex_destroy(&c50_rhs56);
  sf_mex_destroy(&c50_lhs56);
  sf_mex_destroy(&c50_rhs57);
  sf_mex_destroy(&c50_lhs57);
  sf_mex_destroy(&c50_rhs58);
  sf_mex_destroy(&c50_lhs58);
}

static const mxArray *c50_emlrt_marshallOut(const char * c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c50_u)), false);
  return c50_y;
}

static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 7, 0U, 0U, 0U, 0), false);
  return c50_y;
}

boolean_T sf_exported_auto_isStablec50_lib_affectiveChar_behavior(SimStruct
  *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  return true;
}

void sf_exported_auto_duringc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  c50_c50_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_enter_atomic_c50_lib_affectiveChar_behavior(chartInstance);
  c50_enter_internal_c50_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_exit_internal_c50_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_gatewayc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc50_lib_affectiveChar_behavior(SimStruct
  *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c50_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
  (SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior(SimStruct
  *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior(SimStruct
  *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc50_lib_affectiveChar_behavior(SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  c50_initc50_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
  (SimStruct *c50_S)
{
  const mxArray *c50_out = NULL;
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  c50_out = NULL;
  sf_mex_assign(&c50_out,
                sf_internal_get_sim_state_c50_lib_affectiveChar_behavior(c50_S),
                false);
  return c50_out;
}

void sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior(SimStruct *c50_S,
  const mxArray *c50_in)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c50_lib_affectiveChar_behavior(c50_S, sf_mex_dup
    (c50_in));
  sf_mex_destroy(&c50_in);
}

void sf_exported_auto_check_state_inconsistency_c50_lib_affectiveChar_behavior
  (SimStruct *c50_S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c50_setGazeFactorsc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c50_v,
   real_T c50_a, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag, real_T
   c50_gazeArr[6], real_T c50_personalityChange, real_T c50_firstTimeFlag,
   real_T *c50_mutDurFactor, real_T *c50_avertDurFactor, real_T
   *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
   *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
   real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax)
{
  uint32_T c50_debug_family_var_map[20];
  real_T c50_nargin = 8.0;
  real_T c50_nargout = 10.0;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  int32_T c50_i4;
  static char_T c50_cv0[20] = { 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 't',
    'y', ' ', 'c', 'h', 'a', 'n', 'g', 'e', 'd', '.' };

  char_T c50_b_u[20];
  const mxArray *c50_b_y = NULL;
  real_T c50_A;
  real_T c50_x;
  real_T c50_b_x;
  real_T c50_c_x;
  real_T c50_c_y;
  real_T c50_b_A;
  real_T c50_d_x;
  real_T c50_e_x;
  real_T c50_f_x;
  real_T c50_c_A;
  real_T c50_g_x;
  real_T c50_h_x;
  real_T c50_i_x;
  real_T c50_d_A;
  real_T c50_j_x;
  real_T c50_k_x;
  real_T c50_l_x;
  real_T c50_e_A;
  real_T c50_m_x;
  real_T c50_n_x;
  real_T c50_o_x;
  real_T c50_p_x;
  real_T c50_q_x;
  real_T c50_r_x;
  real_T c50_s_x;
  real_T c50_f_A;
  real_T c50_t_x;
  real_T c50_u_x;
  real_T c50_v_x;
  real_T c50_d_y;
  real_T c50_w_x;
  real_T c50_x_x;
  real_T c50_y_x;
  real_T c50_ab_x;
  real_T c50_bb_x;
  real_T c50_cb_x;
  int32_T c50_i5;
  static char_T c50_cv1[28] = { 'f', 'i', 'r', 's', 't', ' ', 't', 'i', 'm', 'e',
    ' ', 'e', 'm', 'o', ' ', 'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ',
    '4', '0', '.' };

  char_T c50_c_u[28];
  const mxArray *c50_e_y = NULL;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c50_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_personalityChange, 8U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_firstTimeFlag, 9U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mutDurFactor, 10U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertDurFactor, 11U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertHeadFreqFactor, 12U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertHeadSpeed, 13U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertDirsChance, 14U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_avertFreqFactor, 15U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mutFreqFactor, 16U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_blinkFlag, 17U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_blinkPeriodMin, 18U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_blinkPeriodMax, 19U,
    c50_sf_marshallOut, c50_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 40);
  c50_u = c50_firstTimeFlag;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c50_y);
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
    if (CV_EML_IF(0, 1, 1, c50_personalityChange == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 54);
      *c50_blinkFlag = 1.0;
      c50_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 54);
      for (c50_i4 = 0; c50_i4 < 20; c50_i4++) {
        c50_b_u[c50_i4] = c50_cv0[c50_i4];
      }

      c50_b_y = NULL;
      sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_b_u, 10, 0U, 1U, 0U, 2, 1,
        20), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c50_b_y);
    }

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 56);
    if (CV_EML_IF(0, 1, 2, c50_p == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 57);
      *c50_mutDurFactor = 2.0;
      c50_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 58);
      *c50_avertDurFactor = 0.5;
      c50_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 59);
      *c50_mutFreqFactor = 4.0;
      c50_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 60);
      *c50_avertFreqFactor = 0.25;
      c50_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 62);
      *c50_avertHeadFreqFactor = 30.0;
      c50_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 63);
      *c50_avertHeadSpeed = 2.0;
      c50_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 64);
      *c50_avertDirsChance = 1.0;
      c50_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 66);
      *c50_blinkPeriodMin = 0.15;
      c50_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 67);
      *c50_blinkPeriodMax = 6.0;
      c50_updateDataWrittenToVector(chartInstance, 9U);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 68);
      if (CV_EML_IF(0, 1, 3, c50_p == 2.0)) {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 69);
        *c50_mutDurFactor = 0.5;
        c50_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 70);
        *c50_avertDurFactor = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 71);
        *c50_mutFreqFactor = 0.15;
        c50_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 72);
        *c50_avertFreqFactor = 4.0;
        c50_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 74);
        *c50_avertHeadFreqFactor = 15.0;
        c50_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 75);
        *c50_avertHeadSpeed = 3.0;
        c50_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 76);
        *c50_avertDirsChance = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 78);
        *c50_blinkPeriodMin = 0.2;
        c50_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 79);
        *c50_blinkPeriodMax = 5.0;
        c50_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 80);
        if (CV_EML_IF(0, 1, 4, c50_p == 3.0)) {
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 81);
          *c50_mutDurFactor = 4.0;
          c50_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 82);
          *c50_avertDurFactor = 0.1;
          c50_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 83);
          *c50_mutFreqFactor = 4.0;
          c50_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 84);
          *c50_avertFreqFactor = 0.25;
          c50_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 86);
          *c50_avertHeadFreqFactor = 25.0;
          c50_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 87);
          *c50_avertHeadSpeed = 2.0;
          c50_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 88);
          *c50_avertDirsChance = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 4U);
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
          *c50_mutFreqFactor = 0.25;
          c50_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 96);
          *c50_avertFreqFactor = 4.0;
          c50_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 98);
          *c50_avertHeadFreqFactor = 10.0;
          c50_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 99);
          *c50_avertHeadSpeed = 3.0;
          c50_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 100);
          *c50_avertDirsChance = 2.0;
          c50_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 102);
          *c50_blinkPeriodMin = 5.0;
          c50_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 103);
          *c50_blinkPeriodMax = 9.0;
          c50_updateDataWrittenToVector(chartInstance, 9U);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 107);
  if (CV_EML_IF(0, 1, 5, (real_T)c50_vaFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 108);
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, c50_v > 40.0)) {
      if (CV_EML_COND(0, 1, 1, c50_a > 40.0)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 6, true);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 109);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
        *c50_mutDurFactor *= 2.0;
        c50_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 110);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
        *c50_avertDurFactor *= 0.5;
        c50_b_round(chartInstance, c50_avertDurFactor);
        c50_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 111);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
        c50_A = *c50_avertHeadFreqFactor;
        c50_x = c50_A;
        c50_b_x = c50_x;
        c50_c_x = c50_b_x;
        c50_c_y = c50_c_x / 3.0;
        *c50_avertHeadFreqFactor = c50_c_y;
        c50_b_round(chartInstance, c50_avertHeadFreqFactor);
        c50_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 120);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 8U, 14U);
        c50_b_A = *c50_blinkPeriodMin;
        c50_d_x = c50_b_A;
        c50_e_x = c50_d_x;
        c50_f_x = c50_e_x;
        *c50_blinkPeriodMin = c50_f_x / 1.5;
        c50_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 121);
        c50_errorIfDataNotWrittenToFcn(chartInstance, 9U, 15U);
        c50_c_A = *c50_blinkPeriodMax;
        c50_g_x = c50_c_A;
        c50_h_x = c50_g_x;
        c50_i_x = c50_h_x;
        *c50_blinkPeriodMax = c50_i_x / 1.5;
        c50_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 6, false);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 123);
      guard2 = false;
      if (CV_EML_COND(0, 1, 2, c50_v < -40.0)) {
        if (CV_EML_COND(0, 1, 3, c50_a > 40.0)) {
          CV_EML_MCDC(0, 1, 1, true);
          CV_EML_IF(0, 1, 7, true);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 124);
          c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
          *c50_mutDurFactor *= 0.5;
          c50_b_round(chartInstance, c50_mutDurFactor);
          c50_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 125);
          c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          *c50_avertDurFactor *= 2.0;
          c50_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 126);
          c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
          *c50_avertHeadFreqFactor += 30.0;
          c50_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 128U);
          c50_errorIfDataNotWrittenToFcn(chartInstance, 8U, 14U);
          c50_d_A = *c50_blinkPeriodMin;
          c50_j_x = c50_d_A;
          c50_k_x = c50_j_x;
          c50_l_x = c50_k_x;
          *c50_blinkPeriodMin = c50_l_x / 1.5;
          c50_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 129U);
          c50_errorIfDataNotWrittenToFcn(chartInstance, 9U, 15U);
          c50_e_A = *c50_blinkPeriodMax;
          c50_m_x = c50_e_A;
          c50_n_x = c50_m_x;
          c50_o_x = c50_n_x;
          *c50_blinkPeriodMax = c50_o_x / 1.5;
          c50_updateDataWrittenToVector(chartInstance, 9U);
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 1, false);
        CV_EML_IF(0, 1, 7, false);
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 131U);
        guard3 = false;
        if (CV_EML_COND(0, 1, 4, c50_v > 40.0)) {
          if (CV_EML_COND(0, 1, 5, c50_a < -40.0)) {
            CV_EML_MCDC(0, 1, 2, true);
            CV_EML_IF(0, 1, 8, true);
            _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 132U);
            c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
            c50_p_x = *c50_mutDurFactor * 1.5;
            *c50_mutDurFactor = c50_p_x;
            c50_q_x = *c50_mutDurFactor;
            *c50_mutDurFactor = c50_q_x;
            *c50_mutDurFactor = muDoubleScalarRound(*c50_mutDurFactor);
            c50_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 133U);
            c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
            c50_r_x = *c50_avertDurFactor * 0.75;
            *c50_avertDurFactor = c50_r_x;
            c50_s_x = *c50_avertDurFactor;
            *c50_avertDurFactor = c50_s_x;
            *c50_avertDurFactor = muDoubleScalarRound(*c50_avertDurFactor);
            c50_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 134U);
            c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
            c50_f_A = *c50_avertHeadFreqFactor;
            c50_t_x = c50_f_A;
            c50_u_x = c50_t_x;
            c50_v_x = c50_u_x;
            c50_d_y = c50_v_x / 2.0;
            c50_w_x = c50_d_y;
            *c50_avertHeadFreqFactor = c50_w_x;
            c50_x_x = *c50_avertHeadFreqFactor;
            *c50_avertHeadFreqFactor = c50_x_x;
            *c50_avertHeadFreqFactor = muDoubleScalarRound
              (*c50_avertHeadFreqFactor);
            c50_updateDataWrittenToVector(chartInstance, 2U);
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(0, 1, 2, false);
          CV_EML_IF(0, 1, 8, false);
          _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 137U);
          guard4 = false;
          if (CV_EML_COND(0, 1, 6, c50_v < -40.0)) {
            if (CV_EML_COND(0, 1, 7, c50_a < -40.0)) {
              CV_EML_MCDC(0, 1, 3, true);
              CV_EML_IF(0, 1, 9, true);
              _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 138U);
              c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
              c50_y_x = *c50_mutDurFactor * 0.75;
              *c50_mutDurFactor = c50_y_x;
              c50_ab_x = *c50_mutDurFactor;
              *c50_mutDurFactor = c50_ab_x;
              *c50_mutDurFactor = muDoubleScalarRound(*c50_mutDurFactor);
              c50_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 139U);
              c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
              c50_bb_x = *c50_avertDurFactor * 1.5;
              *c50_avertDurFactor = c50_bb_x;
              c50_cb_x = *c50_avertDurFactor;
              *c50_avertDurFactor = c50_cb_x;
              *c50_avertDurFactor = muDoubleScalarRound(*c50_avertDurFactor);
              c50_updateDataWrittenToVector(chartInstance, 1U);
              _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 140U);
              c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
              *c50_avertHeadFreqFactor += 20.0;
              c50_updateDataWrittenToVector(chartInstance, 2U);
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

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 144U);
    if (CV_EML_IF(0, 1, 10, c50_firstTimeFlag == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 145U);
      *c50_blinkFlag = 1.0;
      c50_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 146U);
      c50_firstTimeFlag = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 147U);
      for (c50_i5 = 0; c50_i5 < 28; c50_i5++) {
        c50_c_u[c50_i5] = c50_cv1[c50_i5];
      }

      c50_e_y = NULL;
      sf_mex_assign(&c50_e_y, sf_mex_create("y", c50_c_u, 10, 0U, 1U, 0U, 2, 1,
        28), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c50_e_y);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -147);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_setPoseFactorsc50_lib_affectiveChar_behavior
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c50_v,
   real_T c50_ar, real_T c50_p, boolean_T c50_pFlag, boolean_T c50_vaFlag,
   real_T c50_poseArr[6], real_T c50_personalityChange, real_T *c50_poseTwitch,
   real_T *c50_poseFreqFactor, real_T *c50_poseChanceFactor, real_T
   *c50_poseCatChance, real_T *c50_poseLean, real_T *c50_poseSpeed, real_T
   *c50_poseSpace, real_T *c50_poseLeanFlag)
{
  uint32_T c50_debug_family_var_map[23];
  real_T c50_pose_custom_flag;
  real_T c50_pose_chance_custom;
  real_T c50_pose_selfAdaptor_chance_custom;
  real_T c50_pose_frequency_custom;
  real_T c50_pose_speed_custom;
  real_T c50_pose_lean_custom;
  real_T c50_nargin = 7.0;
  real_T c50_nargout = 8.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 23U, 23U, c50_b_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseSpace, 21U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_poseLeanFlag, 22U, c50_sf_marshallOut,
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
  *c50_poseCatChance = 50.0;
  c50_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 11);
  *c50_poseChanceFactor = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 12);
  *c50_poseFreqFactor = 40.0;
  c50_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 13);
  *c50_poseSpeed = 1.0;
  c50_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 14);
  *c50_poseLean = 18.0;
  c50_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 15);
  *c50_poseTwitch = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 16);
  *c50_poseLeanFlag = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 17U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 17);
  *c50_poseSpace = 0.0;
  c50_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 19);
  if (CV_EML_IF(1, 1, 0, c50_pose_custom_flag == 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 20);
    if (CV_EML_IF(1, 1, 1, (real_T)c50_pFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 21);
      if (CV_EML_IF(1, 1, 2, c50_personalityChange == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 22);
        *c50_poseLeanFlag = 1.0;
        c50_updateDataWrittenToVector(chartInstance, 17U);
      }

      _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 24);
      if (CV_EML_IF(1, 1, 3, c50_p == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 25);
        *c50_poseTwitch = 1.0;
        c50_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 26);
        *c50_poseFreqFactor = 15.0;
        c50_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 27);
        *c50_poseLean = 18.0;
        c50_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 28);
        *c50_poseChanceFactor = 4.0;
        c50_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 29);
        *c50_poseCatChance = 90.0;
        c50_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 30);
        *c50_poseSpeed = 2.0;
        c50_updateDataWrittenToVector(chartInstance, 15U);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 32);
        if (CV_EML_IF(1, 1, 4, c50_p == 2.0)) {
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 33);
          *c50_poseTwitch = 1.0;
          c50_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 34);
          *c50_poseFreqFactor = 20.0;
          c50_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 35);
          *c50_poseLean = 19.0;
          c50_updateDataWrittenToVector(chartInstance, 14U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 36);
          *c50_poseChanceFactor = 4.0;
          c50_updateDataWrittenToVector(chartInstance, 12U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 37);
          *c50_poseCatChance = 10.0;
          c50_updateDataWrittenToVector(chartInstance, 13U);
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 38);
          *c50_poseSpeed = 3.0;
          c50_updateDataWrittenToVector(chartInstance, 15U);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 40);
          if (CV_EML_IF(1, 1, 5, c50_p == 3.0)) {
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 41);
            *c50_poseTwitch = 0.0;
            c50_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 42);
            *c50_poseFreqFactor = 50.0;
            c50_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 43);
            *c50_poseLean = 18.0;
            c50_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 44);
            *c50_poseChanceFactor = 1.0;
            c50_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 45);
            *c50_poseCatChance = 10.0;
            c50_updateDataWrittenToVector(chartInstance, 13U);
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 46);
            *c50_poseSpeed = 2.0;
            c50_updateDataWrittenToVector(chartInstance, 15U);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 48);
            if (CV_EML_IF(1, 1, 6, c50_p == 4.0)) {
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 49);
              *c50_poseTwitch = 0.0;
              c50_updateDataWrittenToVector(chartInstance, 10U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 50);
              *c50_poseFreqFactor = 60.0;
              c50_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 51);
              *c50_poseLean = 19.0;
              c50_updateDataWrittenToVector(chartInstance, 14U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 52);
              *c50_poseChanceFactor = 1.0;
              c50_updateDataWrittenToVector(chartInstance, 12U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 53);
              *c50_poseCatChance = 90.0;
              c50_updateDataWrittenToVector(chartInstance, 13U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 54);
              *c50_poseSpeed = 3.0;
              c50_updateDataWrittenToVector(chartInstance, 15U);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 57);
              c50_fprintf(chartInstance);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 57);
              c50_c_fprintf(chartInstance, c50_p);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 58);
              *c50_poseCatChance = 70.0;
              c50_updateDataWrittenToVector(chartInstance, 13U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 59);
              *c50_poseChanceFactor = 1.0;
              c50_updateDataWrittenToVector(chartInstance, 12U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 60);
              *c50_poseFreqFactor = 40.0;
              c50_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 61);
              *c50_poseSpeed = 1.0;
              c50_updateDataWrittenToVector(chartInstance, 15U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 62);
              *c50_poseLean = 18.0;
              c50_updateDataWrittenToVector(chartInstance, 14U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 63);
              *c50_poseTwitch = 0.0;
              c50_updateDataWrittenToVector(chartInstance, 10U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 64);
              *c50_poseLeanFlag = 0.0;
              c50_updateDataWrittenToVector(chartInstance, 17U);
              _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 65);
              *c50_poseSpace = 0.0;
              c50_updateDataWrittenToVector(chartInstance, 16U);
            }
          }
        }
      }
    }
  } else {
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 83);
    *c50_poseFreqFactor = c50_pose_frequency_custom;
    c50_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 84);
    *c50_poseLean = c50_pose_lean_custom;
    c50_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 85);
    *c50_poseChanceFactor = c50_pose_chance_custom;
    c50_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 86);
    *c50_poseCatChance = c50_pose_selfAdaptor_chance_custom;
    c50_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 87);
    *c50_poseSpeed = c50_pose_speed_custom;
    c50_updateDataWrittenToVector(chartInstance, 15U);
  }

  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, -87);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c50_round(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c50_x)
{
  real_T c50_b_x;
  c50_b_x = c50_x;
  c50_b_round(chartInstance, &c50_b_x);
  return c50_b_x;
}

static void c50_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  c50_isequal(chartInstance);
  c50_b_fprintf(chartInstance);
}

static void c50_isequal(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c50_b_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  real_T c50_nbytes;
  int32_T c50_i6;
  static char_T c50_cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c50_u[7];
  const mxArray *c50_y = NULL;
  real_T c50_b_u;
  const mxArray *c50_b_y = NULL;
  int32_T c50_i7;
  static char_T c50_formatSpec[59] = { ' ', 'E', 'r', 'r', 'o', 'r', ':', ' ',
    't', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 't', 'y',
    ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'l', 'i', 's', 't', 'e', 'd', ',',
    ' ', 'b', 'a', 'c', 'k', ' ', 't', 'o', ' ', 'n', 'o', 'r', 'm', 'a', 'l',
    ',', ' ', 'p', '=', ':', ' ' };

  char_T c50_c_u[59];
  const mxArray *c50_c_y = NULL;
  const mxArray *c50_cfmt = NULL;
  const mxArray *c50_convs = NULL;
  c50_isequal(chartInstance);
  for (c50_i6 = 0; c50_i6 < 7; c50_i6++) {
    c50_u[c50_i6] = c50_cv2[c50_i6];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c50_b_u = 1.0;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c50_i7 = 0; c50_i7 < 59; c50_i7++) {
    c50_c_u[c50_i7] = c50_formatSpec[c50_i7];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_c_u, 10, 0U, 1U, 0U, 2, 1, 59),
                false);
  c50_nbytes = c50_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 3U, 14, c50_y, 14, c50_b_y, 14,
     c50_c_y), "feval");
  sf_mex_destroy(&c50_cfmt);
  sf_mex_destroy(&c50_convs);
  return c50_nbytes;
}

static void c50_c_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c50_formatSpec)
{
  c50_isequal(chartInstance);
  c50_d_fprintf(chartInstance, c50_formatSpec);
}

static real_T c50_d_fprintf(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c50_varargin_1)
{
  real_T c50_nbytes;
  int32_T c50_i8;
  static char_T c50_cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c50_u[7];
  const mxArray *c50_y = NULL;
  real_T c50_b_u;
  const mxArray *c50_b_y = NULL;
  int32_T c50_i9;
  static char_T c50_formatSpec[5] = { '%', '0', '.', '0', 'f' };

  char_T c50_c_u[5];
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  const mxArray *c50_cfmt = NULL;
  const mxArray *c50_convs = NULL;
  c50_isequal(chartInstance);
  for (c50_i8 = 0; c50_i8 < 7; c50_i8++) {
    c50_u[c50_i8] = c50_cv3[c50_i8];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c50_b_u = 1.0;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c50_i9 = 0; c50_i9 < 5; c50_i9++) {
    c50_c_u[c50_i9] = c50_formatSpec[c50_i9];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c50_d_u = c50_varargin_1;
  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0), false);
  c50_nbytes = c50_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c50_y, 14, c50_b_y, 14,
     c50_c_y, 14, c50_d_y), "feval");
  sf_mex_destroy(&c50_cfmt);
  sf_mex_destroy(&c50_convs);
  return c50_nbytes;
}

static real_T c50_c_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_feval, const char_T *c50_identifier)
{
  real_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_feval),
    &c50_thisId);
  sf_mex_destroy(&c50_feval);
  return c50_y;
}

static real_T c50_d_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d0, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

void sf_exported_user_c50_lib_affectiveChar_behavior_setGazeFactors(SimStruct
  *c50_S, real_T c50_v, real_T c50_a, real_T c50_p, boolean_T c50_pFlag,
  boolean_T c50_vaFlag, real_T c50_gazeArr[6], real_T c50_personalityChange,
  real_T c50_firstTimeFlag, real_T *c50_mutDurFactor, real_T *c50_avertDurFactor,
  real_T *c50_avertHeadFreqFactor, real_T *c50_avertHeadSpeed, real_T
  *c50_avertDirsChance, real_T *c50_avertFreqFactor, real_T *c50_mutFreqFactor,
  real_T *c50_blinkFlag, real_T *c50_blinkPeriodMin, real_T *c50_blinkPeriodMax)
{
  int32_T c50_i10;
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  for (c50_i10 = 0; c50_i10 < 6; c50_i10++) {
    c50_b_gazeArr[c50_i10] = c50_gazeArr[c50_i10];
  }

  c50_setGazeFactorsc50_lib_affectiveChar_behavior(chartInstance, c50_v, c50_a,
    c50_p, c50_pFlag, c50_vaFlag, c50_b_gazeArr, c50_personalityChange,
    c50_firstTimeFlag, &c50_b_mutDurFactor, &c50_b_avertDurFactor,
    &c50_b_avertHeadFreqFactor, &c50_b_avertHeadSpeed, &c50_b_avertDirsChance,
    &c50_b_avertFreqFactor, &c50_b_mutFreqFactor, &c50_b_blinkFlag,
    &c50_b_blinkPeriodMin, &c50_b_blinkPeriodMax);
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

void sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors(SimStruct
  *c50_S, real_T c50_v, real_T c50_ar, real_T c50_p, boolean_T c50_pFlag,
  boolean_T c50_vaFlag, real_T c50_poseArr[6], real_T c50_personalityChange,
  real_T *c50_poseTwitch, real_T *c50_poseFreqFactor, real_T
  *c50_poseChanceFactor, real_T *c50_poseCatChance, real_T *c50_poseLean, real_T
  *c50_poseSpeed, real_T *c50_poseSpace, real_T *c50_poseLeanFlag)
{
  int32_T c50_i11;
  real_T c50_b_poseArr[6];
  real_T c50_b_poseLeanFlag;
  real_T c50_b_poseSpace;
  real_T c50_b_poseSpeed;
  real_T c50_b_poseLean;
  real_T c50_b_poseCatChance;
  real_T c50_b_poseChanceFactor;
  real_T c50_b_poseFreqFactor;
  real_T c50_b_poseTwitch;
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)
    ->chartInstance;
  for (c50_i11 = 0; c50_i11 < 6; c50_i11++) {
    c50_b_poseArr[c50_i11] = c50_poseArr[c50_i11];
  }

  c50_setPoseFactorsc50_lib_affectiveChar_behavior(chartInstance, c50_v, c50_ar,
    c50_p, c50_pFlag, c50_vaFlag, c50_b_poseArr, c50_personalityChange,
    &c50_b_poseTwitch, &c50_b_poseFreqFactor, &c50_b_poseChanceFactor,
    &c50_b_poseCatChance, &c50_b_poseLean, &c50_b_poseSpeed, &c50_b_poseSpace,
    &c50_b_poseLeanFlag);
  *c50_poseTwitch = c50_b_poseTwitch;
  *c50_poseFreqFactor = c50_b_poseFreqFactor;
  *c50_poseChanceFactor = c50_b_poseChanceFactor;
  *c50_poseCatChance = c50_b_poseCatChance;
  *c50_poseLean = c50_b_poseLean;
  *c50_poseSpeed = c50_b_poseSpeed;
  *c50_poseSpace = c50_b_poseSpace;
  *c50_poseLeanFlag = c50_b_poseLeanFlag;
}

static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int32_T c50_e_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i12;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i12, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i12;
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
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static uint8_T c50_f_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_b_is_active_c50_lib_affectiveChar_behavior, const char_T *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_is_active_c50_lib_affectiveChar_behavior), &c50_thisId);
  sf_mex_destroy(&c50_b_is_active_c50_lib_affectiveChar_behavior);
  return c50_y;
}

static uint8_T c50_g_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static const mxArray *c50_h_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_b_setSimStateSideEffectsInfo, const char_T *c50_identifier)
{
  const mxArray *c50_y = NULL;
  emlrtMsgIdentifier c50_thisId;
  c50_y = NULL;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  sf_mex_assign(&c50_y, c50_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_setSimStateSideEffectsInfo), &c50_thisId), false);
  sf_mex_destroy(&c50_b_setSimStateSideEffectsInfo);
  return c50_y;
}

static const mxArray *c50_i_emlrt_marshallIn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  const mxArray *c50_y = NULL;
  (void)chartInstance;
  (void)c50_parentId;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_duplicatearraysafe(&c50_u), false);
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_updateDataWrittenToVector
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c50_vectorIndex)
{
  (void)chartInstance;
  c50_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c50_vectorIndex, 0, 17, 1, 0)] = true;
}

static void c50_errorIfDataNotWrittenToFcn
  (SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c50_vectorIndex, uint32_T c50_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c50_dataNumber, c50_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c50_vectorIndex, 0, 17, 1,
    0)]);
}

static void c50_b_round(SFc50_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T *c50_x)
{
  (void)chartInstance;
  *c50_x = muDoubleScalarRound(*c50_x);
}

static void init_dsm_address_info(SFc50_lib_affectiveChar_behaviorInstanceStruct
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

void sf_c50_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2123344937U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1543905841U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4173782893U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(93097223U);
}

mxArray *sf_c50_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zN855fNTlKMzcKrVOWp4YH");
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

mxArray *sf_c50_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c50_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c50_lib_affectiveChar_behavior\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           50,
           2,
           0,
           0,
           33,
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
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,8,0,0,"");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,9,0,0,"");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,9,0,0,"");
          _SFD_SET_DATA_PROPS(30,8,0,0,"");
          _SFD_SET_DATA_PROPS(31,9,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
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
        _SFD_CV_INIT_EML(0,1,1,11,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc50_lib_affectiveChar_behavior",
                             0,-1,7658);
        _SFD_CV_INIT_EML_IF(0,1,0,3176,3188,-1,5346);
        _SFD_CV_INIT_EML_IF(0,1,1,3197,3221,-1,3287);
        _SFD_CV_INIT_EML_IF(0,1,2,3296,3304,3969,5336);
        _SFD_CV_INIT_EML_IF(0,1,3,3969,3981,4440,5336);
        _SFD_CV_INIT_EML_IF(0,1,4,4440,4452,4903,5336);
        _SFD_CV_INIT_EML_IF(0,1,5,5354,5367,-1,7658);
        _SFD_CV_INIT_EML_IF(0,1,6,5376,5392,6395,6416);
        _SFD_CV_INIT_EML_IF(0,1,7,6395,6416,6780,7452);
        _SFD_CV_INIT_EML_IF(0,1,8,6780,6801,7086,7452);
        _SFD_CV_INIT_EML_IF(0,1,9,7086,7108,-1,7108);
        _SFD_CV_INIT_EML_IF(0,1,10,7470,7490,-1,7641);

        {
          static int condStart[] = { 5379, 5387 };

          static int condEnd[] = { 5383, 5391 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,5379,5391,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6402, 6411 };

          static int condEnd[] = { 6407, 6415 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,6402,6415,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6787, 6795 };

          static int condEnd[] = { 6791, 6800 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,6787,6800,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 7093, 7102 };

          static int condEnd[] = { 7098, 7107 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,7093,7107,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,1,1,7,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc50_lib_affectiveChar_behavior",
                             0,-1,3523);
        _SFD_CV_INIT_EML_IF(1,1,0,756,779,3278,3522);
        _SFD_CV_INIT_EML_IF(1,1,1,792,804,-1,2805);
        _SFD_CV_INIT_EML_IF(1,1,2,817,841,-1,889);
        _SFD_CV_INIT_EML_IF(1,1,3,902,910,1368,2793);
        _SFD_CV_INIT_EML_IF(1,1,4,1368,1380,1705,2793);
        _SFD_CV_INIT_EML_IF(1,1,5,1705,1717,2017,2793);
        _SFD_CV_INIT_EML_IF(1,1,6,2017,2029,2303,2793);
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
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
          c50_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
          c50_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
            c50_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)c50_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
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
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
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
  return "AXOenljaOyFp6OcZ9IVdYB";
}

static void sf_opaque_initialize_c50_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c50_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c50_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c50_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c50_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c50_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c50_lib_affectiveChar_behavior(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c50_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c50_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c50_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c50_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c50_lib_affectiveChar_behavior
      ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc50_lib_affectiveChar_behavior
    ((SFc50_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c50_lib_affectiveChar_behavior
      ((SFc50_lib_affectiveChar_behaviorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
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
  ssSetChecksum0(S,(1703683781U));
  ssSetChecksum1(S,(2027551850U));
  ssSetChecksum2(S,(1301663497U));
  ssSetChecksum3(S,(203676106U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c50_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc50_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc50_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc50_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c50_lib_affectiveChar_behavior;
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

void c50_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
