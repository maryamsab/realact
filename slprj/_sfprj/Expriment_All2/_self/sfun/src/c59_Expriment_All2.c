/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_All2_sfun.h"
#include "c59_Expriment_All2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_All2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c59_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c59_debug_family_names[19] = { "nargin", "nargout", "v", "a",
  "p", "pFlag", "vaFlag", "gazeArr", "personalityChange", "mutDurFactor",
  "avertDurFactor", "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance",
  "avertFreqFactor", "mutFreqFactor", "blinkFlag", "blinkPeriodMin",
  "blinkPeriodMax" };

static const char * c59_b_debug_family_names[23] = { "pose_custom_flag",
  "pose_chance_custom", "pose_selfAdaptor_chance_custom",
  "pose_frequency_custom", "pose_speed_custom", "pose_lean_custom", "nargin",
  "nargout", "v", "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange",
  "poseTwitch", "poseFreqFactor", "poseChanceFactor", "poseCatChance",
  "poseLean", "poseSpeed", "poseSpace", "poseLeanFlag" };

static boolean_T c59_dataWrittenToVector[18];

/* Function Declarations */
static void initialize_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void initialize_params_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static void enable_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void disable_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void c59_update_debugger_state_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static void set_sim_state_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c59_st);
static void c59_set_sim_state_side_effects_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static void finalize_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void sf_gateway_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void c59_enter_atomic_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static void c59_enter_internal_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static void c59_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void c59_exit_internal_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance);
static void c59_initc59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance);
static void initSimStructsc59_Expriment_All2(SFc59_Expriment_All2InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c59_machineNumber, uint32_T
  c59_chartNumber, uint32_T c59_instanceNumber);
static const mxArray *c59_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static void c59_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static const mxArray *c59_b_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static void c59_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId,
  real_T c59_y[6]);
static void c59_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static const mxArray *c59_c_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static boolean_T c59_b_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static void c59_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static void c59_info_helper(const mxArray **c59_info);
static const mxArray *c59_emlrt_marshallOut(const char * c59_u);
static const mxArray *c59_b_emlrt_marshallOut(const uint32_T c59_u);
static void c59_setGazeFactorsc59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance, real_T c59_v, real_T c59_a,
   real_T c59_p, boolean_T c59_pFlag, boolean_T c59_vaFlag, real_T c59_gazeArr[6],
   real_T c59_personalityChange, real_T *c59_mutDurFactor, real_T
   *c59_avertDurFactor, real_T *c59_avertHeadFreqFactor, real_T
   *c59_avertHeadSpeed, real_T *c59_avertDirsChance, real_T *c59_avertFreqFactor,
   real_T *c59_mutFreqFactor, real_T *c59_blinkFlag, real_T *c59_blinkPeriodMin,
   real_T *c59_blinkPeriodMax);
static void c59_setPoseFactorsc59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance, real_T c59_v, real_T
   c59_ar, real_T c59_p, boolean_T c59_pFlag, boolean_T c59_vaFlag, real_T
   c59_poseArr[6], real_T c59_personalityChange, real_T *c59_poseTwitch, real_T *
   c59_poseFreqFactor, real_T *c59_poseChanceFactor, real_T *c59_poseCatChance,
   real_T *c59_poseLean, real_T *c59_poseSpeed, real_T *c59_poseSpace, real_T
   *c59_poseLeanFlag);
static real_T c59_round(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T c59_x);
static void c59_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance);
static void c59_isequal(SFc59_Expriment_All2InstanceStruct *chartInstance);
static real_T c59_b_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance);
static void c59_c_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T c59_formatSpec);
static real_T c59_d_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T c59_varargin_1);
static real_T c59_c_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_feval, const char_T *c59_identifier);
static real_T c59_d_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static const mxArray *c59_d_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static int32_T c59_e_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static void c59_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static uint8_T c59_f_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_b_is_active_c59_Expriment_All2, const
  char_T *c59_identifier);
static uint8_T c59_g_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static const mxArray *c59_h_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c59_b_setSimStateSideEffectsInfo, const char_T
  *c59_identifier);
static const mxArray *c59_i_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static void c59_updateDataWrittenToVector(SFc59_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c59_vectorIndex);
static void c59_errorIfDataNotWrittenToFcn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c59_vectorIndex, uint32_T c59_dataNumber);
static void c59_b_round(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T *c59_x);
static void init_dsm_address_info(SFc59_Expriment_All2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c59_update_debugger_state_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  const mxArray *c59_st;
  const mxArray *c59_y = NULL;
  uint8_T c59_hoistedGlobal;
  uint8_T c59_u;
  const mxArray *c59_b_y = NULL;
  c59_st = NULL;
  c59_st = NULL;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_createcellmatrix(1, 1), false);
  c59_hoistedGlobal = chartInstance->c59_is_active_c59_Expriment_All2;
  c59_u = c59_hoistedGlobal;
  c59_b_y = NULL;
  sf_mex_assign(&c59_b_y, sf_mex_create("y", &c59_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c59_y, 0, c59_b_y);
  sf_mex_assign(&c59_st, c59_y, false);
  return c59_st;
}

static void set_sim_state_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c59_st)
{
  const mxArray *c59_u;
  chartInstance->c59_doneDoubleBufferReInit = true;
  c59_u = sf_mex_dup(c59_st);
  chartInstance->c59_is_active_c59_Expriment_All2 = c59_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c59_u, 0)),
     "is_active_c59_Expriment_All2");
  sf_mex_assign(&chartInstance->c59_setSimStateSideEffectsInfo,
                c59_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c59_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c59_u);
  chartInstance->c59_doSetSimStateSideEffects = 1U;
  c59_update_debugger_state_c59_Expriment_All2(chartInstance);
  sf_mex_destroy(&c59_st);
}

static void c59_set_sim_state_side_effects_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  if (chartInstance->c59_doSetSimStateSideEffects != 0) {
    chartInstance->c59_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c59_setSimStateSideEffectsInfo);
}

static void sf_gateway_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  c59_set_sim_state_side_effects_c59_Expriment_All2(chartInstance);
}

static void c59_enter_atomic_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 34U, chartInstance->c59_sfEvent);
  chartInstance->c59_is_active_c59_Expriment_All2 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c59_sfEvent);
}

static void c59_enter_internal_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c59_c59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c59_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c59_sfEvent);
}

static void c59_exit_internal_c59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c59_initc59_Expriment_All2(SFc59_Expriment_All2InstanceStruct
  *chartInstance)
{
  chartInstance->c59_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c59_doSetSimStateSideEffects = 0U;
  chartInstance->c59_setSimStateSideEffectsInfo = NULL;
  chartInstance->c59_is_active_c59_Expriment_All2 = 0U;
}

static void initSimStructsc59_Expriment_All2(SFc59_Expriment_All2InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c59_machineNumber, uint32_T
  c59_chartNumber, uint32_T c59_instanceNumber)
{
  (void)c59_machineNumber;
  (void)c59_chartNumber;
  (void)c59_instanceNumber;
}

static const mxArray *c59_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  real_T c59_u;
  const mxArray *c59_y = NULL;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  c59_u = *(real_T *)c59_inData;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static void c59_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_feval;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  real_T c59_y;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_feval = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_feval),
    &c59_thisId);
  sf_mex_destroy(&c59_feval);
  *(real_T *)c59_outData = c59_y;
  sf_mex_destroy(&c59_mxArrayInData);
}

static const mxArray *c59_b_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_i0;
  real_T c59_b_inData[6];
  int32_T c59_i1;
  real_T c59_u[6];
  const mxArray *c59_y = NULL;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  for (c59_i0 = 0; c59_i0 < 6; c59_i0++) {
    c59_b_inData[c59_i0] = (*(real_T (*)[6])c59_inData)[c59_i0];
  }

  for (c59_i1 = 0; c59_i1 < 6; c59_i1++) {
    c59_u[c59_i1] = c59_b_inData[c59_i1];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static void c59_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId,
  real_T c59_y[6])
{
  real_T c59_dv0[6];
  int32_T c59_i2;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), c59_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c59_i2 = 0; c59_i2 < 6; c59_i2++) {
    c59_y[c59_i2] = c59_dv0[c59_i2];
  }

  sf_mex_destroy(&c59_u);
}

static void c59_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_gazeArr;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  real_T c59_y[6];
  int32_T c59_i3;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_gazeArr = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_gazeArr), &c59_thisId,
                       c59_y);
  sf_mex_destroy(&c59_gazeArr);
  for (c59_i3 = 0; c59_i3 < 6; c59_i3++) {
    (*(real_T (*)[6])c59_outData)[c59_i3] = c59_y[c59_i3];
  }

  sf_mex_destroy(&c59_mxArrayInData);
}

static const mxArray *c59_c_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  boolean_T c59_u;
  const mxArray *c59_y = NULL;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  c59_u = *(boolean_T *)c59_inData;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static boolean_T c59_b_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  boolean_T c59_y;
  boolean_T c59_b0;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_b0, 1, 11, 0U, 0, 0U, 0);
  c59_y = c59_b0;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static void c59_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_vaFlag;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  boolean_T c59_y;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_vaFlag = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_vaFlag),
    &c59_thisId);
  sf_mex_destroy(&c59_vaFlag);
  *(boolean_T *)c59_outData = c59_y;
  sf_mex_destroy(&c59_mxArrayInData);
}

const mxArray *sf_c59_Expriment_All2_get_eml_resolved_functions_info(void)
{
  const mxArray *c59_nameCaptureInfo = NULL;
  c59_nameCaptureInfo = NULL;
  sf_mex_assign(&c59_nameCaptureInfo, sf_mex_createstruct("structure", 2, 59, 1),
                false);
  c59_info_helper(&c59_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c59_nameCaptureInfo);
  return c59_nameCaptureInfo;
}

static void c59_info_helper(const mxArray **c59_info)
{
  const mxArray *c59_rhs0 = NULL;
  const mxArray *c59_lhs0 = NULL;
  const mxArray *c59_rhs1 = NULL;
  const mxArray *c59_lhs1 = NULL;
  const mxArray *c59_rhs2 = NULL;
  const mxArray *c59_lhs2 = NULL;
  const mxArray *c59_rhs3 = NULL;
  const mxArray *c59_lhs3 = NULL;
  const mxArray *c59_rhs4 = NULL;
  const mxArray *c59_lhs4 = NULL;
  const mxArray *c59_rhs5 = NULL;
  const mxArray *c59_lhs5 = NULL;
  const mxArray *c59_rhs6 = NULL;
  const mxArray *c59_lhs6 = NULL;
  const mxArray *c59_rhs7 = NULL;
  const mxArray *c59_lhs7 = NULL;
  const mxArray *c59_rhs8 = NULL;
  const mxArray *c59_lhs8 = NULL;
  const mxArray *c59_rhs9 = NULL;
  const mxArray *c59_lhs9 = NULL;
  const mxArray *c59_rhs10 = NULL;
  const mxArray *c59_lhs10 = NULL;
  const mxArray *c59_rhs11 = NULL;
  const mxArray *c59_lhs11 = NULL;
  const mxArray *c59_rhs12 = NULL;
  const mxArray *c59_lhs12 = NULL;
  const mxArray *c59_rhs13 = NULL;
  const mxArray *c59_lhs13 = NULL;
  const mxArray *c59_rhs14 = NULL;
  const mxArray *c59_lhs14 = NULL;
  const mxArray *c59_rhs15 = NULL;
  const mxArray *c59_lhs15 = NULL;
  const mxArray *c59_rhs16 = NULL;
  const mxArray *c59_lhs16 = NULL;
  const mxArray *c59_rhs17 = NULL;
  const mxArray *c59_lhs17 = NULL;
  const mxArray *c59_rhs18 = NULL;
  const mxArray *c59_lhs18 = NULL;
  const mxArray *c59_rhs19 = NULL;
  const mxArray *c59_lhs19 = NULL;
  const mxArray *c59_rhs20 = NULL;
  const mxArray *c59_lhs20 = NULL;
  const mxArray *c59_rhs21 = NULL;
  const mxArray *c59_lhs21 = NULL;
  const mxArray *c59_rhs22 = NULL;
  const mxArray *c59_lhs22 = NULL;
  const mxArray *c59_rhs23 = NULL;
  const mxArray *c59_lhs23 = NULL;
  const mxArray *c59_rhs24 = NULL;
  const mxArray *c59_lhs24 = NULL;
  const mxArray *c59_rhs25 = NULL;
  const mxArray *c59_lhs25 = NULL;
  const mxArray *c59_rhs26 = NULL;
  const mxArray *c59_lhs26 = NULL;
  const mxArray *c59_rhs27 = NULL;
  const mxArray *c59_lhs27 = NULL;
  const mxArray *c59_rhs28 = NULL;
  const mxArray *c59_lhs28 = NULL;
  const mxArray *c59_rhs29 = NULL;
  const mxArray *c59_lhs29 = NULL;
  const mxArray *c59_rhs30 = NULL;
  const mxArray *c59_lhs30 = NULL;
  const mxArray *c59_rhs31 = NULL;
  const mxArray *c59_lhs31 = NULL;
  const mxArray *c59_rhs32 = NULL;
  const mxArray *c59_lhs32 = NULL;
  const mxArray *c59_rhs33 = NULL;
  const mxArray *c59_lhs33 = NULL;
  const mxArray *c59_rhs34 = NULL;
  const mxArray *c59_lhs34 = NULL;
  const mxArray *c59_rhs35 = NULL;
  const mxArray *c59_lhs35 = NULL;
  const mxArray *c59_rhs36 = NULL;
  const mxArray *c59_lhs36 = NULL;
  const mxArray *c59_rhs37 = NULL;
  const mxArray *c59_lhs37 = NULL;
  const mxArray *c59_rhs38 = NULL;
  const mxArray *c59_lhs38 = NULL;
  const mxArray *c59_rhs39 = NULL;
  const mxArray *c59_lhs39 = NULL;
  const mxArray *c59_rhs40 = NULL;
  const mxArray *c59_lhs40 = NULL;
  const mxArray *c59_rhs41 = NULL;
  const mxArray *c59_lhs41 = NULL;
  const mxArray *c59_rhs42 = NULL;
  const mxArray *c59_lhs42 = NULL;
  const mxArray *c59_rhs43 = NULL;
  const mxArray *c59_lhs43 = NULL;
  const mxArray *c59_rhs44 = NULL;
  const mxArray *c59_lhs44 = NULL;
  const mxArray *c59_rhs45 = NULL;
  const mxArray *c59_lhs45 = NULL;
  const mxArray *c59_rhs46 = NULL;
  const mxArray *c59_lhs46 = NULL;
  const mxArray *c59_rhs47 = NULL;
  const mxArray *c59_lhs47 = NULL;
  const mxArray *c59_rhs48 = NULL;
  const mxArray *c59_lhs48 = NULL;
  const mxArray *c59_rhs49 = NULL;
  const mxArray *c59_lhs49 = NULL;
  const mxArray *c59_rhs50 = NULL;
  const mxArray *c59_lhs50 = NULL;
  const mxArray *c59_rhs51 = NULL;
  const mxArray *c59_lhs51 = NULL;
  const mxArray *c59_rhs52 = NULL;
  const mxArray *c59_lhs52 = NULL;
  const mxArray *c59_rhs53 = NULL;
  const mxArray *c59_lhs53 = NULL;
  const mxArray *c59_rhs54 = NULL;
  const mxArray *c59_lhs54 = NULL;
  const mxArray *c59_rhs55 = NULL;
  const mxArray *c59_lhs55 = NULL;
  const mxArray *c59_rhs56 = NULL;
  const mxArray *c59_lhs56 = NULL;
  const mxArray *c59_rhs57 = NULL;
  const mxArray *c59_lhs57 = NULL;
  const mxArray *c59_rhs58 = NULL;
  const mxArray *c59_lhs58 = NULL;
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("disp"), "name", "name", 0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 0);
  sf_mex_assign(&c59_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("round"), "name", "name", 1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c59_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c59_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c59_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("mrdivide"), "name", "name",
                  4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c59_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c59_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("rdivide"), "name", "name", 6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c59_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c59_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c59_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_div"), "name", "name", 9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c59_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c59_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("disp"), "name", "name", 11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 11);
  sf_mex_assign(&c59_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("fprintf"), "name", "name",
                  12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c59_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("isequal"), "name", "name",
                  13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c59_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c59_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("isnan"), "name", "name", 15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c59_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c59_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c59_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("fprintf"), "name", "name",
                  18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c59_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("upper"), "name", "name", 19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c59_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c59_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c59_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c59_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c59_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c59_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c59_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("colon"), "name", "name", 26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c59_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("colon"), "name", "name", 27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c59_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c59_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c59_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("floor"), "name", "name", 30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c59_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c59_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c59_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmin"), "name", "name", 33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c59_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c59_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmax"), "name", "name", 35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c59_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 36);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmin"), "name", "name", 36);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c59_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 37);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c59_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 38);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 38);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c59_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 39);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c59_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 40);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 40);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c59_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 41);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c59_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 42);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 42);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c59_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 43);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 43);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c59_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 44);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmax"), "name", "name", 44);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c59_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 45);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 45);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c59_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 46);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 46);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c59_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 47);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c59_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 48);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 48);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c59_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 49);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmax"), "name", "name", 49);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c59_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "name", "name", 50);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c59_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("fidCheck"), "name", "name",
                  51);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c59_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("upper"), "name", "name", 52);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c59_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 53);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 53);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c59_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 54);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 54);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c59_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 55);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 55);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c59_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 56);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c59_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 57);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 57);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c59_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 58);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 58);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c59_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs58), "lhs", "lhs",
                  58);
  sf_mex_destroy(&c59_rhs0);
  sf_mex_destroy(&c59_lhs0);
  sf_mex_destroy(&c59_rhs1);
  sf_mex_destroy(&c59_lhs1);
  sf_mex_destroy(&c59_rhs2);
  sf_mex_destroy(&c59_lhs2);
  sf_mex_destroy(&c59_rhs3);
  sf_mex_destroy(&c59_lhs3);
  sf_mex_destroy(&c59_rhs4);
  sf_mex_destroy(&c59_lhs4);
  sf_mex_destroy(&c59_rhs5);
  sf_mex_destroy(&c59_lhs5);
  sf_mex_destroy(&c59_rhs6);
  sf_mex_destroy(&c59_lhs6);
  sf_mex_destroy(&c59_rhs7);
  sf_mex_destroy(&c59_lhs7);
  sf_mex_destroy(&c59_rhs8);
  sf_mex_destroy(&c59_lhs8);
  sf_mex_destroy(&c59_rhs9);
  sf_mex_destroy(&c59_lhs9);
  sf_mex_destroy(&c59_rhs10);
  sf_mex_destroy(&c59_lhs10);
  sf_mex_destroy(&c59_rhs11);
  sf_mex_destroy(&c59_lhs11);
  sf_mex_destroy(&c59_rhs12);
  sf_mex_destroy(&c59_lhs12);
  sf_mex_destroy(&c59_rhs13);
  sf_mex_destroy(&c59_lhs13);
  sf_mex_destroy(&c59_rhs14);
  sf_mex_destroy(&c59_lhs14);
  sf_mex_destroy(&c59_rhs15);
  sf_mex_destroy(&c59_lhs15);
  sf_mex_destroy(&c59_rhs16);
  sf_mex_destroy(&c59_lhs16);
  sf_mex_destroy(&c59_rhs17);
  sf_mex_destroy(&c59_lhs17);
  sf_mex_destroy(&c59_rhs18);
  sf_mex_destroy(&c59_lhs18);
  sf_mex_destroy(&c59_rhs19);
  sf_mex_destroy(&c59_lhs19);
  sf_mex_destroy(&c59_rhs20);
  sf_mex_destroy(&c59_lhs20);
  sf_mex_destroy(&c59_rhs21);
  sf_mex_destroy(&c59_lhs21);
  sf_mex_destroy(&c59_rhs22);
  sf_mex_destroy(&c59_lhs22);
  sf_mex_destroy(&c59_rhs23);
  sf_mex_destroy(&c59_lhs23);
  sf_mex_destroy(&c59_rhs24);
  sf_mex_destroy(&c59_lhs24);
  sf_mex_destroy(&c59_rhs25);
  sf_mex_destroy(&c59_lhs25);
  sf_mex_destroy(&c59_rhs26);
  sf_mex_destroy(&c59_lhs26);
  sf_mex_destroy(&c59_rhs27);
  sf_mex_destroy(&c59_lhs27);
  sf_mex_destroy(&c59_rhs28);
  sf_mex_destroy(&c59_lhs28);
  sf_mex_destroy(&c59_rhs29);
  sf_mex_destroy(&c59_lhs29);
  sf_mex_destroy(&c59_rhs30);
  sf_mex_destroy(&c59_lhs30);
  sf_mex_destroy(&c59_rhs31);
  sf_mex_destroy(&c59_lhs31);
  sf_mex_destroy(&c59_rhs32);
  sf_mex_destroy(&c59_lhs32);
  sf_mex_destroy(&c59_rhs33);
  sf_mex_destroy(&c59_lhs33);
  sf_mex_destroy(&c59_rhs34);
  sf_mex_destroy(&c59_lhs34);
  sf_mex_destroy(&c59_rhs35);
  sf_mex_destroy(&c59_lhs35);
  sf_mex_destroy(&c59_rhs36);
  sf_mex_destroy(&c59_lhs36);
  sf_mex_destroy(&c59_rhs37);
  sf_mex_destroy(&c59_lhs37);
  sf_mex_destroy(&c59_rhs38);
  sf_mex_destroy(&c59_lhs38);
  sf_mex_destroy(&c59_rhs39);
  sf_mex_destroy(&c59_lhs39);
  sf_mex_destroy(&c59_rhs40);
  sf_mex_destroy(&c59_lhs40);
  sf_mex_destroy(&c59_rhs41);
  sf_mex_destroy(&c59_lhs41);
  sf_mex_destroy(&c59_rhs42);
  sf_mex_destroy(&c59_lhs42);
  sf_mex_destroy(&c59_rhs43);
  sf_mex_destroy(&c59_lhs43);
  sf_mex_destroy(&c59_rhs44);
  sf_mex_destroy(&c59_lhs44);
  sf_mex_destroy(&c59_rhs45);
  sf_mex_destroy(&c59_lhs45);
  sf_mex_destroy(&c59_rhs46);
  sf_mex_destroy(&c59_lhs46);
  sf_mex_destroy(&c59_rhs47);
  sf_mex_destroy(&c59_lhs47);
  sf_mex_destroy(&c59_rhs48);
  sf_mex_destroy(&c59_lhs48);
  sf_mex_destroy(&c59_rhs49);
  sf_mex_destroy(&c59_lhs49);
  sf_mex_destroy(&c59_rhs50);
  sf_mex_destroy(&c59_lhs50);
  sf_mex_destroy(&c59_rhs51);
  sf_mex_destroy(&c59_lhs51);
  sf_mex_destroy(&c59_rhs52);
  sf_mex_destroy(&c59_lhs52);
  sf_mex_destroy(&c59_rhs53);
  sf_mex_destroy(&c59_lhs53);
  sf_mex_destroy(&c59_rhs54);
  sf_mex_destroy(&c59_lhs54);
  sf_mex_destroy(&c59_rhs55);
  sf_mex_destroy(&c59_lhs55);
  sf_mex_destroy(&c59_rhs56);
  sf_mex_destroy(&c59_lhs56);
  sf_mex_destroy(&c59_rhs57);
  sf_mex_destroy(&c59_lhs57);
  sf_mex_destroy(&c59_rhs58);
  sf_mex_destroy(&c59_lhs58);
}

static const mxArray *c59_emlrt_marshallOut(const char * c59_u)
{
  const mxArray *c59_y = NULL;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c59_u)), false);
  return c59_y;
}

static const mxArray *c59_b_emlrt_marshallOut(const uint32_T c59_u)
{
  const mxArray *c59_y = NULL;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 7, 0U, 0U, 0U, 0), false);
  return c59_y;
}

boolean_T sf_exported_auto_isStablec59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  return true;
}

void sf_exported_auto_duringc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  c59_c59_Expriment_All2(chartInstance);
}

void sf_exported_auto_enterc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c59_enter_atomic_c59_Expriment_All2(chartInstance);
  c59_enter_internal_c59_Expriment_All2(chartInstance);
}

void sf_exported_auto_exitc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c59_exit_internal_c59_Expriment_All2(chartInstance);
}

void sf_exported_auto_gatewayc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  chartInstance->c59_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc59_Expriment_All2(SimStruct *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  c59_initc59_Expriment_All2(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec59_Expriment_All2(SimStruct *c59_S)
{
  const mxArray *c59_out = NULL;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  c59_out = NULL;
  sf_mex_assign(&c59_out, sf_internal_get_sim_state_c59_Expriment_All2(c59_S),
                false);
  return c59_out;
}

void sf_exported_auto_setSimstatec59_Expriment_All2(SimStruct *c59_S, const
  mxArray *c59_in)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c59_Expriment_All2(c59_S, sf_mex_dup(c59_in));
  sf_mex_destroy(&c59_in);
}

void sf_exported_auto_check_state_inconsistency_c59_Expriment_All2(SimStruct
  *c59_S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_All2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c59_setGazeFactorsc59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance, real_T c59_v, real_T c59_a,
   real_T c59_p, boolean_T c59_pFlag, boolean_T c59_vaFlag, real_T c59_gazeArr[6],
   real_T c59_personalityChange, real_T *c59_mutDurFactor, real_T
   *c59_avertDurFactor, real_T *c59_avertHeadFreqFactor, real_T
   *c59_avertHeadSpeed, real_T *c59_avertDirsChance, real_T *c59_avertFreqFactor,
   real_T *c59_mutFreqFactor, real_T *c59_blinkFlag, real_T *c59_blinkPeriodMin,
   real_T *c59_blinkPeriodMax)
{
  uint32_T c59_debug_family_var_map[19];
  real_T c59_nargin = 7.0;
  real_T c59_nargout = 10.0;
  int32_T c59_i4;
  static char_T c59_cv0[20] = { 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 't',
    'y', ' ', 'c', 'h', 'a', 'n', 'g', 'e', 'd', '.' };

  char_T c59_u[20];
  const mxArray *c59_y = NULL;
  real_T c59_A;
  real_T c59_x;
  real_T c59_b_x;
  real_T c59_c_x;
  real_T c59_b_y;
  real_T c59_b_A;
  real_T c59_d_x;
  real_T c59_e_x;
  real_T c59_f_x;
  real_T c59_c_A;
  real_T c59_g_x;
  real_T c59_h_x;
  real_T c59_i_x;
  real_T c59_b_u;
  const mxArray *c59_c_y = NULL;
  real_T c59_d_A;
  real_T c59_j_x;
  real_T c59_k_x;
  real_T c59_l_x;
  real_T c59_e_A;
  real_T c59_m_x;
  real_T c59_n_x;
  real_T c59_o_x;
  real_T c59_p_x;
  real_T c59_q_x;
  real_T c59_r_x;
  real_T c59_s_x;
  real_T c59_f_A;
  real_T c59_t_x;
  real_T c59_u_x;
  real_T c59_v_x;
  real_T c59_d_y;
  real_T c59_w_x;
  real_T c59_x_x;
  real_T c59_y_x;
  real_T c59_ab_x;
  real_T c59_bb_x;
  real_T c59_cb_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c59_debug_family_names,
    c59_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_nargin, 0U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_nargout, 1U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_v, 2U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_a, 3U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_p, 4U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pFlag, 5U, c59_c_sf_marshallOut,
    c59_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_vaFlag, 6U, c59_c_sf_marshallOut,
    c59_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_gazeArr, 7U, c59_b_sf_marshallOut,
    c59_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_personalityChange, 8U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_mutDurFactor, 9U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_avertDurFactor, 10U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_avertHeadFreqFactor, 11U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_avertHeadSpeed, 12U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_avertDirsChance, 13U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_avertFreqFactor, 14U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_mutFreqFactor, 15U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_blinkFlag, 16U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_blinkPeriodMin, 17U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_blinkPeriodMax, 18U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 41);
  *c59_mutDurFactor = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 42);
  *c59_avertDurFactor = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 43);
  *c59_avertHeadFreqFactor = 20.0;
  c59_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 44);
  *c59_avertHeadSpeed = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 45);
  *c59_avertDirsChance = 0.0;
  c59_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 46);
  *c59_avertFreqFactor = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 47);
  *c59_mutFreqFactor = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 48);
  *c59_blinkFlag = 0.0;
  c59_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 49);
  *c59_blinkPeriodMin = 5.0;
  c59_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 50);
  *c59_blinkPeriodMax = 9.0;
  c59_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 52);
  if (CV_EML_IF(0, 1, 0, (real_T)c59_pFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 53);
    if (CV_EML_IF(0, 1, 1, c59_personalityChange == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 54);
      *c59_blinkFlag = 1.0;
      c59_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 54);
      for (c59_i4 = 0; c59_i4 < 20; c59_i4++) {
        c59_u[c59_i4] = c59_cv0[c59_i4];
      }

      c59_y = NULL;
      sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 10, 0U, 1U, 0U, 2, 1, 20),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c59_y);
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 56);
    if (CV_EML_IF(0, 1, 2, c59_p == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 57);
      *c59_mutDurFactor = 2.0;
      c59_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 58);
      *c59_avertDurFactor = 0.5;
      c59_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 59);
      *c59_mutFreqFactor = 4.0;
      c59_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 60);
      *c59_avertFreqFactor = 0.25;
      c59_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 62);
      *c59_avertHeadFreqFactor = 30.0;
      c59_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 63);
      *c59_avertHeadSpeed = 2.0;
      c59_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 64);
      *c59_avertDirsChance = 1.0;
      c59_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 66);
      *c59_blinkPeriodMin = 0.15;
      c59_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 67);
      *c59_blinkPeriodMax = 6.0;
      c59_updateDataWrittenToVector(chartInstance, 9U);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 68);
      if (CV_EML_IF(0, 1, 3, c59_p == 2.0)) {
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 69);
        *c59_mutDurFactor = 0.5;
        c59_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 70);
        *c59_avertDurFactor = 2.0;
        c59_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 71);
        *c59_mutFreqFactor = 0.15;
        c59_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 72);
        *c59_avertFreqFactor = 4.0;
        c59_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 74);
        *c59_avertHeadFreqFactor = 15.0;
        c59_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 75);
        *c59_avertHeadSpeed = 3.0;
        c59_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 76);
        *c59_avertDirsChance = 2.0;
        c59_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 78);
        *c59_blinkPeriodMin = 0.2;
        c59_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 79);
        *c59_blinkPeriodMax = 5.0;
        c59_updateDataWrittenToVector(chartInstance, 9U);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 80);
        if (CV_EML_IF(0, 1, 4, c59_p == 3.0)) {
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 81);
          *c59_mutDurFactor = 4.0;
          c59_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 82);
          *c59_avertDurFactor = 0.1;
          c59_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 83);
          *c59_mutFreqFactor = 4.0;
          c59_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 84);
          *c59_avertFreqFactor = 0.25;
          c59_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 86);
          *c59_avertHeadFreqFactor = 25.0;
          c59_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 87);
          *c59_avertHeadSpeed = 2.0;
          c59_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 88);
          *c59_avertDirsChance = 1.0;
          c59_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 90);
          *c59_blinkPeriodMin = 5.0;
          c59_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 91);
          *c59_blinkPeriodMax = 15.0;
          c59_updateDataWrittenToVector(chartInstance, 9U);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 93);
          *c59_mutDurFactor = 0.25;
          c59_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 94);
          *c59_avertDurFactor = 0.5;
          c59_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 95);
          *c59_mutFreqFactor = 0.25;
          c59_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 96);
          *c59_avertFreqFactor = 4.0;
          c59_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 98);
          *c59_avertHeadFreqFactor = 10.0;
          c59_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 99);
          *c59_avertHeadSpeed = 3.0;
          c59_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 100);
          *c59_avertDirsChance = 2.0;
          c59_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 102);
          *c59_blinkPeriodMin = 5.0;
          c59_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 103);
          *c59_blinkPeriodMax = 9.0;
          c59_updateDataWrittenToVector(chartInstance, 9U);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 113);
  if (CV_EML_IF(0, 1, 5, (real_T)c59_vaFlag == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 114);
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, c59_v > 40.0)) {
      if (CV_EML_COND(0, 1, 1, c59_a > 40.0)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 6, true);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 115);
        c59_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
        *c59_mutDurFactor *= 2.0;
        c59_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 116);
        c59_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
        *c59_avertDurFactor *= 0.5;
        c59_b_round(chartInstance, c59_avertDurFactor);
        c59_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 117);
        c59_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
        c59_A = *c59_avertHeadFreqFactor;
        c59_x = c59_A;
        c59_b_x = c59_x;
        c59_c_x = c59_b_x;
        c59_b_y = c59_c_x / 3.0;
        *c59_avertHeadFreqFactor = c59_b_y;
        c59_b_round(chartInstance, c59_avertHeadFreqFactor);
        c59_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 126);
        c59_errorIfDataNotWrittenToFcn(chartInstance, 8U, 14U);
        c59_b_A = *c59_blinkPeriodMin;
        c59_d_x = c59_b_A;
        c59_e_x = c59_d_x;
        c59_f_x = c59_e_x;
        *c59_blinkPeriodMin = c59_f_x / 1.5;
        c59_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, MAX_int8_T);
        c59_errorIfDataNotWrittenToFcn(chartInstance, 9U, 15U);
        c59_c_A = *c59_blinkPeriodMax;
        c59_g_x = c59_c_A;
        c59_h_x = c59_g_x;
        c59_i_x = c59_h_x;
        *c59_blinkPeriodMax = c59_i_x / 1.5;
        c59_updateDataWrittenToVector(chartInstance, 9U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 128U);
        *c59_blinkFlag = 1.0;
        c59_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 129U);
        c59_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
        c59_b_u = *c59_mutDurFactor;
        c59_c_y = NULL;
        sf_mex_assign(&c59_c_y, sf_mex_create("y", &c59_b_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c59_c_y);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 6, false);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 130U);
      guard2 = false;
      if (CV_EML_COND(0, 1, 2, c59_v < -40.0)) {
        if (CV_EML_COND(0, 1, 3, c59_a > 40.0)) {
          CV_EML_MCDC(0, 1, 1, true);
          CV_EML_IF(0, 1, 7, true);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 131U);
          c59_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
          *c59_mutDurFactor *= 0.5;
          c59_b_round(chartInstance, c59_mutDurFactor);
          c59_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 132U);
          c59_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          *c59_avertDurFactor *= 2.0;
          c59_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 133U);
          c59_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
          *c59_avertHeadFreqFactor += 30.0;
          c59_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 135U);
          c59_errorIfDataNotWrittenToFcn(chartInstance, 8U, 14U);
          c59_d_A = *c59_blinkPeriodMin;
          c59_j_x = c59_d_A;
          c59_k_x = c59_j_x;
          c59_l_x = c59_k_x;
          *c59_blinkPeriodMin = c59_l_x / 1.5;
          c59_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 136U);
          c59_errorIfDataNotWrittenToFcn(chartInstance, 9U, 15U);
          c59_e_A = *c59_blinkPeriodMax;
          c59_m_x = c59_e_A;
          c59_n_x = c59_m_x;
          c59_o_x = c59_n_x;
          *c59_blinkPeriodMax = c59_o_x / 1.5;
          c59_updateDataWrittenToVector(chartInstance, 9U);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 137U);
          *c59_blinkFlag = 1.0;
          c59_updateDataWrittenToVector(chartInstance, 7U);
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 1, false);
        CV_EML_IF(0, 1, 7, false);
        _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 138U);
        guard3 = false;
        if (CV_EML_COND(0, 1, 4, c59_v > 40.0)) {
          if (CV_EML_COND(0, 1, 5, c59_a < -40.0)) {
            CV_EML_MCDC(0, 1, 2, true);
            CV_EML_IF(0, 1, 8, true);
            _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 139U);
            c59_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
            c59_p_x = *c59_mutDurFactor * 1.5;
            *c59_mutDurFactor = c59_p_x;
            c59_q_x = *c59_mutDurFactor;
            *c59_mutDurFactor = c59_q_x;
            *c59_mutDurFactor = muDoubleScalarRound(*c59_mutDurFactor);
            c59_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 140U);
            c59_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
            c59_r_x = *c59_avertDurFactor * 0.75;
            *c59_avertDurFactor = c59_r_x;
            c59_s_x = *c59_avertDurFactor;
            *c59_avertDurFactor = c59_s_x;
            *c59_avertDurFactor = muDoubleScalarRound(*c59_avertDurFactor);
            c59_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 141U);
            c59_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
            c59_f_A = *c59_avertHeadFreqFactor;
            c59_t_x = c59_f_A;
            c59_u_x = c59_t_x;
            c59_v_x = c59_u_x;
            c59_d_y = c59_v_x / 2.0;
            c59_w_x = c59_d_y;
            *c59_avertHeadFreqFactor = c59_w_x;
            c59_x_x = *c59_avertHeadFreqFactor;
            *c59_avertHeadFreqFactor = c59_x_x;
            *c59_avertHeadFreqFactor = muDoubleScalarRound
              (*c59_avertHeadFreqFactor);
            c59_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 143U);
            *c59_blinkFlag = 0.0;
            c59_updateDataWrittenToVector(chartInstance, 7U);
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(0, 1, 2, false);
          CV_EML_IF(0, 1, 8, false);
          _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 144U);
          guard4 = false;
          if (CV_EML_COND(0, 1, 6, c59_v < -40.0)) {
            if (CV_EML_COND(0, 1, 7, c59_a < -40.0)) {
              CV_EML_MCDC(0, 1, 3, true);
              CV_EML_IF(0, 1, 9, true);
              _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 145U);
              c59_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
              c59_y_x = *c59_mutDurFactor * 0.75;
              *c59_mutDurFactor = c59_y_x;
              c59_ab_x = *c59_mutDurFactor;
              *c59_mutDurFactor = c59_ab_x;
              *c59_mutDurFactor = muDoubleScalarRound(*c59_mutDurFactor);
              c59_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 146U);
              c59_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
              c59_bb_x = *c59_avertDurFactor * 1.5;
              *c59_avertDurFactor = c59_bb_x;
              c59_cb_x = *c59_avertDurFactor;
              *c59_avertDurFactor = c59_cb_x;
              *c59_avertDurFactor = muDoubleScalarRound(*c59_avertDurFactor);
              c59_updateDataWrittenToVector(chartInstance, 1U);
              _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 147U);
              c59_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
              *c59_avertHeadFreqFactor += 20.0;
              c59_updateDataWrittenToVector(chartInstance, 2U);
              _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 149U);
              *c59_blinkFlag = 0.0;
              c59_updateDataWrittenToVector(chartInstance, 7U);
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

  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, -149);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c59_setPoseFactorsc59_Expriment_All2
  (SFc59_Expriment_All2InstanceStruct *chartInstance, real_T c59_v, real_T
   c59_ar, real_T c59_p, boolean_T c59_pFlag, boolean_T c59_vaFlag, real_T
   c59_poseArr[6], real_T c59_personalityChange, real_T *c59_poseTwitch, real_T *
   c59_poseFreqFactor, real_T *c59_poseChanceFactor, real_T *c59_poseCatChance,
   real_T *c59_poseLean, real_T *c59_poseSpeed, real_T *c59_poseSpace, real_T
   *c59_poseLeanFlag)
{
  uint32_T c59_debug_family_var_map[23];
  real_T c59_pose_custom_flag;
  real_T c59_pose_chance_custom;
  real_T c59_pose_selfAdaptor_chance_custom;
  real_T c59_pose_frequency_custom;
  real_T c59_pose_speed_custom;
  real_T c59_pose_lean_custom;
  real_T c59_nargin = 7.0;
  real_T c59_nargout = 8.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 23U, 23U, c59_b_debug_family_names,
    c59_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pose_custom_flag, 0U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pose_chance_custom, 1U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pose_selfAdaptor_chance_custom, 2U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pose_frequency_custom, 3U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pose_speed_custom, 4U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pose_lean_custom, 5U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_nargin, 6U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_nargout, 7U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_v, 8U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_ar, 9U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_p, 10U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_pFlag, 11U, c59_c_sf_marshallOut,
    c59_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_vaFlag, 12U, c59_c_sf_marshallOut,
    c59_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseArr, 13U, c59_b_sf_marshallOut,
    c59_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_personalityChange, 14U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseTwitch, 15U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseFreqFactor, 16U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseChanceFactor, 17U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseCatChance, 18U,
    c59_sf_marshallOut, c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseLean, 19U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseSpeed, 20U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseSpace, 21U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_poseLeanFlag, 22U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 3);
  c59_pose_custom_flag = c59_poseArr[0];
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 4);
  c59_pose_chance_custom = c59_poseArr[2];
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 5);
  c59_pose_selfAdaptor_chance_custom = c59_poseArr[1];
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 6);
  c59_pose_frequency_custom = c59_poseArr[3];
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 7);
  c59_pose_speed_custom = c59_poseArr[4];
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 8);
  c59_pose_lean_custom = c59_poseArr[5];
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 10);
  *c59_poseCatChance = 50.0;
  c59_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 11);
  *c59_poseChanceFactor = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 12);
  *c59_poseFreqFactor = 40.0;
  c59_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 13);
  *c59_poseSpeed = 1.0;
  c59_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 14);
  *c59_poseLean = 18.0;
  c59_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 15);
  *c59_poseTwitch = 0.0;
  c59_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 16);
  *c59_poseLeanFlag = 0.0;
  c59_updateDataWrittenToVector(chartInstance, 17U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 17);
  *c59_poseSpace = 0.0;
  c59_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 19);
  if (CV_EML_IF(1, 1, 0, c59_pose_custom_flag == 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 20);
    if (CV_EML_IF(1, 1, 1, (real_T)c59_pFlag == 1.0)) {
      _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 21);
      if (CV_EML_IF(1, 1, 2, c59_personalityChange == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 22);
        *c59_poseLeanFlag = 1.0;
        c59_updateDataWrittenToVector(chartInstance, 17U);
      }

      _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 24);
      if (CV_EML_IF(1, 1, 3, c59_p == 1.0)) {
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 25);
        *c59_poseTwitch = 1.0;
        c59_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 26);
        *c59_poseFreqFactor = 15.0;
        c59_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 27);
        *c59_poseLean = 18.0;
        c59_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 28);
        *c59_poseChanceFactor = 4.0;
        c59_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 29);
        *c59_poseCatChance = 90.0;
        c59_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 30);
        *c59_poseSpeed = 2.0;
        c59_updateDataWrittenToVector(chartInstance, 15U);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 32);
        if (CV_EML_IF(1, 1, 4, c59_p == 2.0)) {
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 33);
          *c59_poseTwitch = 1.0;
          c59_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 34);
          *c59_poseFreqFactor = 20.0;
          c59_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 35);
          *c59_poseLean = 19.0;
          c59_updateDataWrittenToVector(chartInstance, 14U);
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 36);
          *c59_poseChanceFactor = 4.0;
          c59_updateDataWrittenToVector(chartInstance, 12U);
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 37);
          *c59_poseCatChance = 10.0;
          c59_updateDataWrittenToVector(chartInstance, 13U);
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 38);
          *c59_poseSpeed = 3.0;
          c59_updateDataWrittenToVector(chartInstance, 15U);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 40);
          if (CV_EML_IF(1, 1, 5, c59_p == 3.0)) {
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 41);
            *c59_poseTwitch = 0.0;
            c59_updateDataWrittenToVector(chartInstance, 10U);
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 42);
            *c59_poseFreqFactor = 50.0;
            c59_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 43);
            *c59_poseLean = 18.0;
            c59_updateDataWrittenToVector(chartInstance, 14U);
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 44);
            *c59_poseChanceFactor = 1.0;
            c59_updateDataWrittenToVector(chartInstance, 12U);
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 45);
            *c59_poseCatChance = 10.0;
            c59_updateDataWrittenToVector(chartInstance, 13U);
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 46);
            *c59_poseSpeed = 2.0;
            c59_updateDataWrittenToVector(chartInstance, 15U);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 48);
            if (CV_EML_IF(1, 1, 6, c59_p == 4.0)) {
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 49);
              *c59_poseTwitch = 0.0;
              c59_updateDataWrittenToVector(chartInstance, 10U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 50);
              *c59_poseFreqFactor = 60.0;
              c59_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 51);
              *c59_poseLean = 19.0;
              c59_updateDataWrittenToVector(chartInstance, 14U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 52);
              *c59_poseChanceFactor = 1.0;
              c59_updateDataWrittenToVector(chartInstance, 12U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 53);
              *c59_poseCatChance = 90.0;
              c59_updateDataWrittenToVector(chartInstance, 13U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 54);
              *c59_poseSpeed = 3.0;
              c59_updateDataWrittenToVector(chartInstance, 15U);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 57);
              c59_fprintf(chartInstance);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 57);
              c59_c_fprintf(chartInstance, c59_p);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 58);
              *c59_poseCatChance = 70.0;
              c59_updateDataWrittenToVector(chartInstance, 13U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 59);
              *c59_poseChanceFactor = 1.0;
              c59_updateDataWrittenToVector(chartInstance, 12U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 60);
              *c59_poseFreqFactor = 40.0;
              c59_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 61);
              *c59_poseSpeed = 1.0;
              c59_updateDataWrittenToVector(chartInstance, 15U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 62);
              *c59_poseLean = 18.0;
              c59_updateDataWrittenToVector(chartInstance, 14U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 63);
              *c59_poseTwitch = 0.0;
              c59_updateDataWrittenToVector(chartInstance, 10U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 64);
              *c59_poseLeanFlag = 0.0;
              c59_updateDataWrittenToVector(chartInstance, 17U);
              _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 65);
              *c59_poseSpace = 0.0;
              c59_updateDataWrittenToVector(chartInstance, 16U);
            }
          }
        }
      }
    }
  } else {
    _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 83);
    *c59_poseFreqFactor = c59_pose_frequency_custom;
    c59_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 84);
    *c59_poseLean = c59_pose_lean_custom;
    c59_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 85);
    *c59_poseChanceFactor = c59_pose_chance_custom;
    c59_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 86);
    *c59_poseCatChance = c59_pose_selfAdaptor_chance_custom;
    c59_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, 87);
    *c59_poseSpeed = c59_pose_speed_custom;
    c59_updateDataWrittenToVector(chartInstance, 15U);
  }

  _SFD_EML_CALL(1U, chartInstance->c59_sfEvent, -87);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c59_round(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T c59_x)
{
  real_T c59_b_x;
  c59_b_x = c59_x;
  c59_b_round(chartInstance, &c59_b_x);
  return c59_b_x;
}

static void c59_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  c59_isequal(chartInstance);
  c59_b_fprintf(chartInstance);
}

static void c59_isequal(SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c59_b_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance)
{
  real_T c59_nbytes;
  int32_T c59_i5;
  static char_T c59_cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c59_u[7];
  const mxArray *c59_y = NULL;
  real_T c59_b_u;
  const mxArray *c59_b_y = NULL;
  int32_T c59_i6;
  static char_T c59_formatSpec[59] = { ' ', 'E', 'r', 'r', 'o', 'r', ':', ' ',
    't', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 't', 'y',
    ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'l', 'i', 's', 't', 'e', 'd', ',',
    ' ', 'b', 'a', 'c', 'k', ' ', 't', 'o', ' ', 'n', 'o', 'r', 'm', 'a', 'l',
    ',', ' ', 'p', '=', ':', ' ' };

  char_T c59_c_u[59];
  const mxArray *c59_c_y = NULL;
  const mxArray *c59_cfmt = NULL;
  const mxArray *c59_convs = NULL;
  c59_isequal(chartInstance);
  for (c59_i5 = 0; c59_i5 < 7; c59_i5++) {
    c59_u[c59_i5] = c59_cv1[c59_i5];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c59_b_u = 1.0;
  c59_b_y = NULL;
  sf_mex_assign(&c59_b_y, sf_mex_create("y", &c59_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c59_i6 = 0; c59_i6 < 59; c59_i6++) {
    c59_c_u[c59_i6] = c59_formatSpec[c59_i6];
  }

  c59_c_y = NULL;
  sf_mex_assign(&c59_c_y, sf_mex_create("y", c59_c_u, 10, 0U, 1U, 0U, 2, 1, 59),
                false);
  c59_nbytes = c59_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 3U, 14, c59_y, 14, c59_b_y, 14,
     c59_c_y), "feval");
  sf_mex_destroy(&c59_cfmt);
  sf_mex_destroy(&c59_convs);
  return c59_nbytes;
}

static void c59_c_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T c59_formatSpec)
{
  c59_isequal(chartInstance);
  c59_d_fprintf(chartInstance, c59_formatSpec);
}

static real_T c59_d_fprintf(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T c59_varargin_1)
{
  real_T c59_nbytes;
  int32_T c59_i7;
  static char_T c59_cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c59_u[7];
  const mxArray *c59_y = NULL;
  real_T c59_b_u;
  const mxArray *c59_b_y = NULL;
  int32_T c59_i8;
  static char_T c59_formatSpec[5] = { '%', '0', '.', '0', 'f' };

  char_T c59_c_u[5];
  const mxArray *c59_c_y = NULL;
  real_T c59_d_u;
  const mxArray *c59_d_y = NULL;
  const mxArray *c59_cfmt = NULL;
  const mxArray *c59_convs = NULL;
  c59_isequal(chartInstance);
  for (c59_i7 = 0; c59_i7 < 7; c59_i7++) {
    c59_u[c59_i7] = c59_cv2[c59_i7];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c59_b_u = 1.0;
  c59_b_y = NULL;
  sf_mex_assign(&c59_b_y, sf_mex_create("y", &c59_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c59_i8 = 0; c59_i8 < 5; c59_i8++) {
    c59_c_u[c59_i8] = c59_formatSpec[c59_i8];
  }

  c59_c_y = NULL;
  sf_mex_assign(&c59_c_y, sf_mex_create("y", c59_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c59_d_u = c59_varargin_1;
  c59_d_y = NULL;
  sf_mex_assign(&c59_d_y, sf_mex_create("y", &c59_d_u, 0, 0U, 0U, 0U, 0), false);
  c59_nbytes = c59_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14, c59_y, 14, c59_b_y, 14,
     c59_c_y, 14, c59_d_y), "feval");
  sf_mex_destroy(&c59_cfmt);
  sf_mex_destroy(&c59_convs);
  return c59_nbytes;
}

static real_T c59_c_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_feval, const char_T *c59_identifier)
{
  real_T c59_y;
  emlrtMsgIdentifier c59_thisId;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_feval),
    &c59_thisId);
  sf_mex_destroy(&c59_feval);
  return c59_y;
}

static real_T c59_d_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  real_T c59_y;
  real_T c59_d0;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_d0, 1, 0, 0U, 0, 0U, 0);
  c59_y = c59_d0;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

void sf_exported_user_c59_Expriment_All2_setGazeFactors(SimStruct *c59_S, real_T
  c59_v, real_T c59_a, real_T c59_p, boolean_T c59_pFlag, boolean_T c59_vaFlag,
  real_T c59_gazeArr[6], real_T c59_personalityChange, real_T *c59_mutDurFactor,
  real_T *c59_avertDurFactor, real_T *c59_avertHeadFreqFactor, real_T
  *c59_avertHeadSpeed, real_T *c59_avertDirsChance, real_T *c59_avertFreqFactor,
  real_T *c59_mutFreqFactor, real_T *c59_blinkFlag, real_T *c59_blinkPeriodMin,
  real_T *c59_blinkPeriodMax)
{
  int32_T c59_i9;
  real_T c59_b_gazeArr[6];
  real_T c59_b_blinkPeriodMax;
  real_T c59_b_blinkPeriodMin;
  real_T c59_b_blinkFlag;
  real_T c59_b_mutFreqFactor;
  real_T c59_b_avertFreqFactor;
  real_T c59_b_avertDirsChance;
  real_T c59_b_avertHeadSpeed;
  real_T c59_b_avertHeadFreqFactor;
  real_T c59_b_avertDurFactor;
  real_T c59_b_mutDurFactor;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  for (c59_i9 = 0; c59_i9 < 6; c59_i9++) {
    c59_b_gazeArr[c59_i9] = c59_gazeArr[c59_i9];
  }

  c59_setGazeFactorsc59_Expriment_All2(chartInstance, c59_v, c59_a, c59_p,
    c59_pFlag, c59_vaFlag, c59_b_gazeArr, c59_personalityChange,
    &c59_b_mutDurFactor, &c59_b_avertDurFactor, &c59_b_avertHeadFreqFactor,
    &c59_b_avertHeadSpeed, &c59_b_avertDirsChance, &c59_b_avertFreqFactor,
    &c59_b_mutFreqFactor, &c59_b_blinkFlag, &c59_b_blinkPeriodMin,
    &c59_b_blinkPeriodMax);
  *c59_mutDurFactor = c59_b_mutDurFactor;
  *c59_avertDurFactor = c59_b_avertDurFactor;
  *c59_avertHeadFreqFactor = c59_b_avertHeadFreqFactor;
  *c59_avertHeadSpeed = c59_b_avertHeadSpeed;
  *c59_avertDirsChance = c59_b_avertDirsChance;
  *c59_avertFreqFactor = c59_b_avertFreqFactor;
  *c59_mutFreqFactor = c59_b_mutFreqFactor;
  *c59_blinkFlag = c59_b_blinkFlag;
  *c59_blinkPeriodMin = c59_b_blinkPeriodMin;
  *c59_blinkPeriodMax = c59_b_blinkPeriodMax;
}

void sf_exported_user_c59_Expriment_All2_setPoseFactors(SimStruct *c59_S, real_T
  c59_v, real_T c59_ar, real_T c59_p, boolean_T c59_pFlag, boolean_T c59_vaFlag,
  real_T c59_poseArr[6], real_T c59_personalityChange, real_T *c59_poseTwitch,
  real_T *c59_poseFreqFactor, real_T *c59_poseChanceFactor, real_T
  *c59_poseCatChance, real_T *c59_poseLean, real_T *c59_poseSpeed, real_T
  *c59_poseSpace, real_T *c59_poseLeanFlag)
{
  int32_T c59_i10;
  real_T c59_b_poseArr[6];
  real_T c59_b_poseLeanFlag;
  real_T c59_b_poseSpace;
  real_T c59_b_poseSpeed;
  real_T c59_b_poseLean;
  real_T c59_b_poseCatChance;
  real_T c59_b_poseChanceFactor;
  real_T c59_b_poseFreqFactor;
  real_T c59_b_poseTwitch;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c59_S))->instanceInfo)->chartInstance;
  for (c59_i10 = 0; c59_i10 < 6; c59_i10++) {
    c59_b_poseArr[c59_i10] = c59_poseArr[c59_i10];
  }

  c59_setPoseFactorsc59_Expriment_All2(chartInstance, c59_v, c59_ar, c59_p,
    c59_pFlag, c59_vaFlag, c59_b_poseArr, c59_personalityChange,
    &c59_b_poseTwitch, &c59_b_poseFreqFactor, &c59_b_poseChanceFactor,
    &c59_b_poseCatChance, &c59_b_poseLean, &c59_b_poseSpeed, &c59_b_poseSpace,
    &c59_b_poseLeanFlag);
  *c59_poseTwitch = c59_b_poseTwitch;
  *c59_poseFreqFactor = c59_b_poseFreqFactor;
  *c59_poseChanceFactor = c59_b_poseChanceFactor;
  *c59_poseCatChance = c59_b_poseCatChance;
  *c59_poseLean = c59_b_poseLean;
  *c59_poseSpeed = c59_b_poseSpeed;
  *c59_poseSpace = c59_b_poseSpace;
  *c59_poseLeanFlag = c59_b_poseLeanFlag;
}

static const mxArray *c59_d_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_u;
  const mxArray *c59_y = NULL;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  c59_u = *(int32_T *)c59_inData;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static int32_T c59_e_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  int32_T c59_y;
  int32_T c59_i11;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_i11, 1, 6, 0U, 0, 0U, 0);
  c59_y = c59_i11;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static void c59_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_b_sfEvent;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  int32_T c59_y;
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c59_b_sfEvent = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_b_sfEvent),
    &c59_thisId);
  sf_mex_destroy(&c59_b_sfEvent);
  *(int32_T *)c59_outData = c59_y;
  sf_mex_destroy(&c59_mxArrayInData);
}

static uint8_T c59_f_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_b_is_active_c59_Expriment_All2, const
  char_T *c59_identifier)
{
  uint8_T c59_y;
  emlrtMsgIdentifier c59_thisId;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c59_b_is_active_c59_Expriment_All2), &c59_thisId);
  sf_mex_destroy(&c59_b_is_active_c59_Expriment_All2);
  return c59_y;
}

static uint8_T c59_g_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  uint8_T c59_y;
  uint8_T c59_u0;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_u0, 1, 3, 0U, 0, 0U, 0);
  c59_y = c59_u0;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static const mxArray *c59_h_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c59_b_setSimStateSideEffectsInfo, const char_T
  *c59_identifier)
{
  const mxArray *c59_y = NULL;
  emlrtMsgIdentifier c59_thisId;
  c59_y = NULL;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  sf_mex_assign(&c59_y, c59_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c59_b_setSimStateSideEffectsInfo), &c59_thisId), false);
  sf_mex_destroy(&c59_b_setSimStateSideEffectsInfo);
  return c59_y;
}

static const mxArray *c59_i_emlrt_marshallIn(SFc59_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  const mxArray *c59_y = NULL;
  (void)chartInstance;
  (void)c59_parentId;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_duplicatearraysafe(&c59_u), false);
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static void c59_updateDataWrittenToVector(SFc59_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c59_vectorIndex)
{
  (void)chartInstance;
  c59_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c59_vectorIndex, 0, 17, 1, 0)] = true;
}

static void c59_errorIfDataNotWrittenToFcn(SFc59_Expriment_All2InstanceStruct
  *chartInstance, uint32_T c59_vectorIndex, uint32_T c59_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c59_dataNumber, c59_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c59_vectorIndex, 0, 17, 1,
    0)]);
}

static void c59_b_round(SFc59_Expriment_All2InstanceStruct *chartInstance,
  real_T *c59_x)
{
  (void)chartInstance;
  *c59_x = muDoubleScalarRound(*c59_x);
}

static void init_dsm_address_info(SFc59_Expriment_All2InstanceStruct
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

void sf_c59_Expriment_All2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2683569126U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2650435138U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1865127295U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3271904933U);
}

mxArray *sf_c59_Expriment_All2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XWK2AdjbEnhIcFB7aLpEKH");
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

mxArray *sf_c59_Expriment_All2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c59_Expriment_All2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c59_Expriment_All2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c59_Expriment_All2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c59_Expriment_All2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc59_Expriment_All2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc59_Expriment_All2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_All2MachineNumber_,
           59,
           2,
           0,
           0,
           32,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_All2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_All2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_All2MachineNumber_,
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
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,9,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,9,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_SET_DATA_PROPS(30,9,0,0,"");
          _SFD_SET_DATA_PROPS(31,8,0,0,"");
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
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc59_Expriment_All2",0,-1,7960);
        _SFD_CV_INIT_EML_IF(0,1,0,3139,3151,-1,5309);
        _SFD_CV_INIT_EML_IF(0,1,1,3160,3184,-1,3250);
        _SFD_CV_INIT_EML_IF(0,1,2,3259,3267,3932,5299);
        _SFD_CV_INIT_EML_IF(0,1,3,3932,3944,4403,5299);
        _SFD_CV_INIT_EML_IF(0,1,4,4403,4415,4866,5299);
        _SFD_CV_INIT_EML_IF(0,1,5,5723,5736,-1,7960);
        _SFD_CV_INIT_EML_IF(0,1,6,5745,5761,6820,6841);
        _SFD_CV_INIT_EML_IF(0,1,7,6820,6841,7229,7950);
        _SFD_CV_INIT_EML_IF(0,1,8,7229,7250,7559,7950);
        _SFD_CV_INIT_EML_IF(0,1,9,7559,7581,-1,7581);

        {
          static int condStart[] = { 5748, 5756 };

          static int condEnd[] = { 5752, 5760 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,5748,5760,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 6827, 6836 };

          static int condEnd[] = { 6832, 6840 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,6827,6840,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 7236, 7244 };

          static int condEnd[] = { 7240, 7249 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,7236,7249,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 7566, 7575 };

          static int condEnd[] = { 7571, 7580 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,7566,7580,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,1,1,7,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc59_Expriment_All2",0,-1,3523);
        _SFD_CV_INIT_EML_IF(1,1,0,756,779,3278,3522);
        _SFD_CV_INIT_EML_IF(1,1,1,792,804,-1,2805);
        _SFD_CV_INIT_EML_IF(1,1,2,817,841,-1,889);
        _SFD_CV_INIT_EML_IF(1,1,3,902,910,1368,2793);
        _SFD_CV_INIT_EML_IF(1,1,4,1368,1380,1705,2793);
        _SFD_CV_INIT_EML_IF(1,1,5,1705,1717,2017,2793);
        _SFD_CV_INIT_EML_IF(1,1,6,2017,2029,2303,2793);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_c_sf_marshallOut,(MexInFcnForType)
          c59_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_c_sf_marshallOut,(MexInFcnForType)
          c59_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_b_sf_marshallOut,(MexInFcnForType)
            c59_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_c_sf_marshallOut,(MexInFcnForType)
          c59_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_c_sf_marshallOut,(MexInFcnForType)
          c59_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_b_sf_marshallOut,(MexInFcnForType)
            c59_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)c59_sf_marshallIn);
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
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_All2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "xsdNzPZXNefyxdunvDtN8";
}

static void sf_opaque_initialize_c59_Expriment_All2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar);
  initialize_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c59_Expriment_All2(void *chartInstanceVar)
{
  enable_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c59_Expriment_All2(void *chartInstanceVar)
{
  disable_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c59_Expriment_All2(void *chartInstanceVar)
{
  sf_gateway_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c59_Expriment_All2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c59_Expriment_All2
    ((SFc59_Expriment_All2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c59_Expriment_All2();/* state var info */
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

extern void sf_internal_set_sim_state_c59_Expriment_All2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c59_Expriment_All2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c59_Expriment_All2(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c59_Expriment_All2(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c59_Expriment_All2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc59_Expriment_All2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_All2_optimization_info();
    }

    finalize_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
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
  initSimStructsc59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c59_Expriment_All2(SimStruct *S)
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
    initialize_params_c59_Expriment_All2((SFc59_Expriment_All2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c59_Expriment_All2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_All2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      59);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,59,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,59,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,59);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,59);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3868708622U));
  ssSetChecksum1(S,(1087499898U));
  ssSetChecksum2(S,(3524039496U));
  ssSetChecksum3(S,(17155891U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c59_Expriment_All2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c59_Expriment_All2(SimStruct *S)
{
  SFc59_Expriment_All2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc59_Expriment_All2InstanceStruct *)utMalloc(sizeof
    (SFc59_Expriment_All2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc59_Expriment_All2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c59_Expriment_All2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c59_Expriment_All2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c59_Expriment_All2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c59_Expriment_All2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c59_Expriment_All2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c59_Expriment_All2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c59_Expriment_All2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c59_Expriment_All2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c59_Expriment_All2;
  chartInstance->chartInfo.mdlStart = mdlStart_c59_Expriment_All2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c59_Expriment_All2;
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

void c59_Expriment_All2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c59_Expriment_All2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c59_Expriment_All2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c59_Expriment_All2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c59_Expriment_All2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
