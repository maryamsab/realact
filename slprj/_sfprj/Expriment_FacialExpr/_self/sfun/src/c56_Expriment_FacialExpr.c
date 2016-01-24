/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_FacialExpr_sfun.h"
#include "c56_Expriment_FacialExpr.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_FacialExpr_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c56_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c56_debug_family_names[15] = { "nargin", "nargout", "v", "a",
  "p", "pFlag", "vaFlag", "gazeArr", "mutDurFactor", "avertDurFactor",
  "avertHeadFreqFactor", "avertHeadSpeed", "avertDirsChance", "avertFreqFactor",
  "mutFreqFactor" };

static const char * c56_b_debug_family_names[16] = { "nargin", "nargout", "v",
  "ar", "p", "pFlag", "vaFlag", "poseArr", "personalityChange", "poseTwitch",
  "poseFreqFactor", "poseChanceFactor", "poseCatChance", "poseLean", "poseSpeed",
  "poseLeanFlag" };

static boolean_T c56_dataWrittenToVector[14];

/* Function Declarations */
static void initialize_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void initialize_params_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void enable_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void disable_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void c56_update_debugger_state_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void set_sim_state_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c56_st);
static void c56_set_sim_state_side_effects_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void finalize_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void sf_gateway_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void c56_enter_atomic_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void c56_enter_internal_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void c56_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void c56_exit_internal_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void c56_initc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void initSimStructsc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c56_machineNumber, uint32_T
  c56_chartNumber, uint32_T c56_instanceNumber);
static const mxArray *c56_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static real_T c56_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_b_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static void c56_b_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId,
  real_T c56_y[6]);
static void c56_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_c_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static boolean_T c56_c_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static void c56_info_helper(const mxArray **c56_info);
static const mxArray *c56_emlrt_marshallOut(const char * c56_u);
static const mxArray *c56_b_emlrt_marshallOut(const uint32_T c56_u);
static void c56_setGazeFactorsc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, real_T c56_v, real_T
   c56_a, real_T c56_p, boolean_T c56_pFlag, boolean_T c56_vaFlag, real_T
   c56_gazeArr[6], real_T *c56_mutDurFactor, real_T *c56_avertDurFactor, real_T *
   c56_avertHeadFreqFactor, real_T *c56_avertHeadSpeed, real_T
   *c56_avertDirsChance, real_T *c56_avertFreqFactor, real_T *c56_mutFreqFactor);
static void c56_setPoseFactorsc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, real_T c56_v, real_T
   c56_ar, real_T c56_p, boolean_T c56_pFlag, boolean_T c56_vaFlag, real_T
   c56_poseArr[6], real_T c56_personalityChange, real_T *c56_poseTwitch, real_T *
   c56_poseFreqFactor, real_T *c56_poseChanceFactor, real_T *c56_poseCatChance,
   real_T *c56_poseLean, real_T *c56_poseSpeed, real_T *c56_poseLeanFlag);
static const mxArray *c56_d_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static int32_T c56_d_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static uint8_T c56_e_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_b_is_active_c56_Expriment_FacialExpr, const
  char_T *c56_identifier);
static uint8_T c56_f_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static const mxArray *c56_g_emlrt_marshallIn
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c56_b_setSimStateSideEffectsInfo, const char_T *c56_identifier);
static const mxArray *c56_h_emlrt_marshallIn
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray *c56_u,
   const emlrtMsgIdentifier *c56_parentId);
static void c56_updateDataWrittenToVector
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T
   c56_vectorIndex);
static void c56_errorIfDataNotWrittenToFcn
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T
   c56_vectorIndex, uint32_T c56_dataNumber);
static void init_dsm_address_info(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c56_update_debugger_state_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  const mxArray *c56_st;
  const mxArray *c56_y = NULL;
  uint8_T c56_hoistedGlobal;
  uint8_T c56_u;
  const mxArray *c56_b_y = NULL;
  c56_st = NULL;
  c56_st = NULL;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_createcellmatrix(1, 1), false);
  c56_hoistedGlobal = chartInstance->c56_is_active_c56_Expriment_FacialExpr;
  c56_u = c56_hoistedGlobal;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", &c56_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c56_y, 0, c56_b_y);
  sf_mex_assign(&c56_st, c56_y, false);
  return c56_st;
}

static void set_sim_state_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c56_st)
{
  const mxArray *c56_u;
  chartInstance->c56_doneDoubleBufferReInit = true;
  c56_u = sf_mex_dup(c56_st);
  chartInstance->c56_is_active_c56_Expriment_FacialExpr = c56_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c56_u, 0)),
     "is_active_c56_Expriment_FacialExpr");
  sf_mex_assign(&chartInstance->c56_setSimStateSideEffectsInfo,
                c56_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c56_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c56_u);
  chartInstance->c56_doSetSimStateSideEffects = 1U;
  c56_update_debugger_state_c56_Expriment_FacialExpr(chartInstance);
  sf_mex_destroy(&c56_st);
}

static void c56_set_sim_state_side_effects_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  if (chartInstance->c56_doSetSimStateSideEffects != 0) {
    chartInstance->c56_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c56_setSimStateSideEffectsInfo);
}

static void sf_gateway_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  c56_set_sim_state_side_effects_c56_Expriment_FacialExpr(chartInstance);
}

static void c56_enter_atomic_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 32U, chartInstance->c56_sfEvent);
  chartInstance->c56_is_active_c56_Expriment_FacialExpr = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c56_sfEvent);
}

static void c56_enter_internal_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c56_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c56_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c56_sfEvent);
}

static void c56_exit_internal_c56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c56_initc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  chartInstance->c56_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c56_doSetSimStateSideEffects = 0U;
  chartInstance->c56_setSimStateSideEffectsInfo = NULL;
  chartInstance->c56_is_active_c56_Expriment_FacialExpr = 0U;
}

static void initSimStructsc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c56_machineNumber, uint32_T
  c56_chartNumber, uint32_T c56_instanceNumber)
{
  (void)c56_machineNumber;
  (void)c56_chartNumber;
  (void)c56_instanceNumber;
}

static const mxArray *c56_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  real_T c56_u;
  const mxArray *c56_y = NULL;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(real_T *)c56_inData;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static real_T c56_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  real_T c56_y;
  real_T c56_d0;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_d0, 1, 0, 0U, 0, 0U, 0);
  c56_y = c56_d0;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void c56_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_mutFreqFactor;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  real_T c56_y;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_mutFreqFactor = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_mutFreqFactor),
    &c56_thisId);
  sf_mex_destroy(&c56_mutFreqFactor);
  *(real_T *)c56_outData = c56_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_b_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_i0;
  real_T c56_b_inData[6];
  int32_T c56_i1;
  real_T c56_u[6];
  const mxArray *c56_y = NULL;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  for (c56_i0 = 0; c56_i0 < 6; c56_i0++) {
    c56_b_inData[c56_i0] = (*(real_T (*)[6])c56_inData)[c56_i0];
  }

  for (c56_i1 = 0; c56_i1 < 6; c56_i1++) {
    c56_u[c56_i1] = c56_b_inData[c56_i1];
  }

  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", c56_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static void c56_b_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId,
  real_T c56_y[6])
{
  real_T c56_dv0[6];
  int32_T c56_i2;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), c56_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c56_i2 = 0; c56_i2 < 6; c56_i2++) {
    c56_y[c56_i2] = c56_dv0[c56_i2];
  }

  sf_mex_destroy(&c56_u);
}

static void c56_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_gazeArr;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  real_T c56_y[6];
  int32_T c56_i3;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_gazeArr = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_gazeArr), &c56_thisId,
    c56_y);
  sf_mex_destroy(&c56_gazeArr);
  for (c56_i3 = 0; c56_i3 < 6; c56_i3++) {
    (*(real_T (*)[6])c56_outData)[c56_i3] = c56_y[c56_i3];
  }

  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_c_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  boolean_T c56_u;
  const mxArray *c56_y = NULL;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(boolean_T *)c56_inData;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static boolean_T c56_c_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  boolean_T c56_y;
  boolean_T c56_b0;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_b0, 1, 11, 0U, 0, 0U, 0);
  c56_y = c56_b0;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void c56_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_vaFlag;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  boolean_T c56_y;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_vaFlag = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_vaFlag),
    &c56_thisId);
  sf_mex_destroy(&c56_vaFlag);
  *(boolean_T *)c56_outData = c56_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

const mxArray *sf_c56_Expriment_FacialExpr_get_eml_resolved_functions_info(void)
{
  const mxArray *c56_nameCaptureInfo = NULL;
  c56_nameCaptureInfo = NULL;
  sf_mex_assign(&c56_nameCaptureInfo, sf_mex_createstruct("structure", 2, 10, 1),
                false);
  c56_info_helper(&c56_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c56_nameCaptureInfo);
  return c56_nameCaptureInfo;
}

static void c56_info_helper(const mxArray **c56_info)
{
  const mxArray *c56_rhs0 = NULL;
  const mxArray *c56_lhs0 = NULL;
  const mxArray *c56_rhs1 = NULL;
  const mxArray *c56_lhs1 = NULL;
  const mxArray *c56_rhs2 = NULL;
  const mxArray *c56_lhs2 = NULL;
  const mxArray *c56_rhs3 = NULL;
  const mxArray *c56_lhs3 = NULL;
  const mxArray *c56_rhs4 = NULL;
  const mxArray *c56_lhs4 = NULL;
  const mxArray *c56_rhs5 = NULL;
  const mxArray *c56_lhs5 = NULL;
  const mxArray *c56_rhs6 = NULL;
  const mxArray *c56_lhs6 = NULL;
  const mxArray *c56_rhs7 = NULL;
  const mxArray *c56_lhs7 = NULL;
  const mxArray *c56_rhs8 = NULL;
  const mxArray *c56_lhs8 = NULL;
  const mxArray *c56_rhs9 = NULL;
  const mxArray *c56_lhs9 = NULL;
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c56_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c56_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c56_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c56_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c56_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c56_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c56_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("abs"), "name", "name", 7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c56_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c56_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c56_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs9), "lhs", "lhs",
                  9);
  sf_mex_destroy(&c56_rhs0);
  sf_mex_destroy(&c56_lhs0);
  sf_mex_destroy(&c56_rhs1);
  sf_mex_destroy(&c56_lhs1);
  sf_mex_destroy(&c56_rhs2);
  sf_mex_destroy(&c56_lhs2);
  sf_mex_destroy(&c56_rhs3);
  sf_mex_destroy(&c56_lhs3);
  sf_mex_destroy(&c56_rhs4);
  sf_mex_destroy(&c56_lhs4);
  sf_mex_destroy(&c56_rhs5);
  sf_mex_destroy(&c56_lhs5);
  sf_mex_destroy(&c56_rhs6);
  sf_mex_destroy(&c56_lhs6);
  sf_mex_destroy(&c56_rhs7);
  sf_mex_destroy(&c56_lhs7);
  sf_mex_destroy(&c56_rhs8);
  sf_mex_destroy(&c56_lhs8);
  sf_mex_destroy(&c56_rhs9);
  sf_mex_destroy(&c56_lhs9);
}

static const mxArray *c56_emlrt_marshallOut(const char * c56_u)
{
  const mxArray *c56_y = NULL;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", c56_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c56_u)), false);
  return c56_y;
}

static const mxArray *c56_b_emlrt_marshallOut(const uint32_T c56_u)
{
  const mxArray *c56_y = NULL;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 7, 0U, 0U, 0U, 0), false);
  return c56_y;
}

boolean_T sf_exported_auto_isStablec56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  return true;
}

void sf_exported_auto_duringc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  c56_c56_Expriment_FacialExpr(chartInstance);
}

void sf_exported_auto_enterc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c56_enter_atomic_c56_Expriment_FacialExpr(chartInstance);
  c56_enter_internal_c56_Expriment_FacialExpr(chartInstance);
}

void sf_exported_auto_exitc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c56_exit_internal_c56_Expriment_FacialExpr(chartInstance);
}

void sf_exported_auto_gatewayc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  chartInstance->c56_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc56_Expriment_FacialExpr(SimStruct
  *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc56_Expriment_FacialExpr(SimStruct
  *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc56_Expriment_FacialExpr(SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  c56_initc56_Expriment_FacialExpr(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec56_Expriment_FacialExpr(SimStruct
  *c56_S)
{
  const mxArray *c56_out = NULL;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  c56_out = NULL;
  sf_mex_assign(&c56_out, sf_internal_get_sim_state_c56_Expriment_FacialExpr
                (c56_S), false);
  return c56_out;
}

void sf_exported_auto_setSimstatec56_Expriment_FacialExpr(SimStruct *c56_S,
  const mxArray *c56_in)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c56_Expriment_FacialExpr(c56_S, sf_mex_dup(c56_in));
  sf_mex_destroy(&c56_in);
}

void sf_exported_auto_check_state_inconsistency_c56_Expriment_FacialExpr
  (SimStruct *c56_S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_FacialExprMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c56_setGazeFactorsc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, real_T c56_v, real_T
   c56_a, real_T c56_p, boolean_T c56_pFlag, boolean_T c56_vaFlag, real_T
   c56_gazeArr[6], real_T *c56_mutDurFactor, real_T *c56_avertDurFactor, real_T *
   c56_avertHeadFreqFactor, real_T *c56_avertHeadSpeed, real_T
   *c56_avertDirsChance, real_T *c56_avertFreqFactor, real_T *c56_mutFreqFactor)
{
  uint32_T c56_debug_family_var_map[15];
  real_T c56_nargin = 6.0;
  real_T c56_nargout = 7.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c56_debug_family_names,
    c56_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargin, 0U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargout, 1U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_v, 2U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_a, 3U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_p, 4U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_pFlag, 5U, c56_c_sf_marshallOut,
    c56_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_vaFlag, 6U, c56_c_sf_marshallOut,
    c56_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_gazeArr, 7U, c56_b_sf_marshallOut,
    c56_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_mutDurFactor, 8U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_avertDurFactor, 9U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_avertHeadFreqFactor, 10U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_avertHeadSpeed, 11U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_avertDirsChance, 12U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_avertFreqFactor, 13U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_mutFreqFactor, 14U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 29);
  *c56_mutDurFactor = 1.0;
  c56_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 30);
  *c56_avertDurFactor = 1.0;
  c56_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 31);
  *c56_avertHeadFreqFactor = 20.0;
  c56_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 32);
  *c56_avertHeadSpeed = 1.0;
  c56_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 33);
  *c56_avertDirsChance = 0.0;
  c56_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 34);
  *c56_avertFreqFactor = 1.0;
  c56_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 35);
  *c56_mutFreqFactor = 1.0;
  c56_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 37);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, c56_v > 50.0)) {
    if (CV_EML_COND(0, 1, 1, c56_a > 50.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 38);
      *c56_mutDurFactor = 2.0;
      c56_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 39);
      *c56_avertDurFactor = 0.5;
      c56_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 40);
      *c56_avertHeadFreqFactor = 6.666666666666667;
      c56_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 41);
      *c56_avertHeadSpeed = 2.0;
      c56_updateDataWrittenToVector(chartInstance, 3U);
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 42);
    guard2 = false;
    if (CV_EML_COND(0, 1, 2, c56_v < -50.0)) {
      if (CV_EML_COND(0, 1, 3, c56_a > 50.0)) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 43);
        *c56_mutDurFactor = 0.5;
        c56_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 44);
        *c56_avertDurFactor = 2.0;
        c56_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 45);
        c56_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
        *c56_avertHeadFreqFactor += 30.0;
        c56_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 46);
        *c56_avertHeadSpeed = 2.0;
        c56_updateDataWrittenToVector(chartInstance, 3U);
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 1, false);
      _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 47);
      guard3 = false;
      if (CV_EML_COND(0, 1, 4, c56_v > 50.0)) {
        if (CV_EML_COND(0, 1, 5, c56_a < -50.0)) {
          CV_EML_MCDC(0, 1, 2, true);
          CV_EML_IF(0, 1, 2, true);
          _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 48);
          *c56_mutDurFactor = 1.5;
          c56_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 49);
          *c56_avertDurFactor = 0.75;
          c56_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 50);
          *c56_avertHeadFreqFactor = 10.0;
          c56_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 51);
          *c56_avertHeadSpeed = 1.0;
          c56_updateDataWrittenToVector(chartInstance, 3U);
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 2, false);
        _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 52);
        guard4 = false;
        if (CV_EML_COND(0, 1, 6, c56_v < -50.0)) {
          if (CV_EML_COND(0, 1, 7, c56_a < -50.0)) {
            CV_EML_MCDC(0, 1, 3, true);
            CV_EML_IF(0, 1, 3, true);
            _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 53);
            *c56_mutDurFactor = 0.75;
            c56_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 54);
            *c56_avertDurFactor = 1.5;
            c56_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 55);
            c56_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
            *c56_avertHeadFreqFactor += 20.0;
            c56_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 56);
            *c56_avertHeadSpeed = 1.0;
            c56_updateDataWrittenToVector(chartInstance, 3U);
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4 == true) {
          CV_EML_MCDC(0, 1, 3, false);
          CV_EML_IF(0, 1, 3, false);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, -56);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c56_setPoseFactorsc56_Expriment_FacialExpr
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, real_T c56_v, real_T
   c56_ar, real_T c56_p, boolean_T c56_pFlag, boolean_T c56_vaFlag, real_T
   c56_poseArr[6], real_T c56_personalityChange, real_T *c56_poseTwitch, real_T *
   c56_poseFreqFactor, real_T *c56_poseChanceFactor, real_T *c56_poseCatChance,
   real_T *c56_poseLean, real_T *c56_poseSpeed, real_T *c56_poseLeanFlag)
{
  uint32_T c56_debug_family_var_map[16];
  real_T c56_nargin = 7.0;
  real_T c56_nargout = 7.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c56_b_debug_family_names,
    c56_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargin, 0U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargout, 1U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_v, 2U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_ar, 3U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_p, 4U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_pFlag, 5U, c56_c_sf_marshallOut,
    c56_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_vaFlag, 6U, c56_c_sf_marshallOut,
    c56_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseArr, 7U, c56_b_sf_marshallOut,
    c56_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_personalityChange, 8U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseTwitch, 9U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseFreqFactor, 10U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseChanceFactor, 11U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseCatChance, 12U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseLean, 13U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseSpeed, 14U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c56_poseLeanFlag, 15U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 2);
  *c56_poseCatChance = 70.0;
  c56_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 3);
  *c56_poseChanceFactor = 1.0;
  c56_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 4);
  *c56_poseFreqFactor = 20.0;
  c56_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 5);
  *c56_poseSpeed = 0.0;
  c56_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 6);
  *c56_poseLean = 10.0;
  c56_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 7);
  *c56_poseTwitch = 0.0;
  c56_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 8);
  *c56_poseLeanFlag = 0.0;
  c56_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 12);
  if (CV_EML_IF(1, 1, 0, (real_T)c56_vaFlag == 1.0)) {
    _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 13);
    if (CV_EML_IF(1, 1, 1, c56_ar > 50.0)) {
      _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 14);
      *c56_poseSpeed = 2.0;
      c56_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 15);
      *c56_poseLeanFlag = 12.0;
      c56_updateDataWrittenToVector(chartInstance, 13U);
    }

    _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 17);
    if (CV_EML_IF(1, 1, 2, c56_ar < -50.0)) {
      _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 18);
      *c56_poseSpeed = 1.0;
      c56_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, 19);
      *c56_poseLeanFlag = 11.0;
      c56_updateDataWrittenToVector(chartInstance, 13U);
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c56_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c56_Expriment_FacialExpr_setGazeFactors(SimStruct *c56_S,
  real_T c56_v, real_T c56_a, real_T c56_p, boolean_T c56_pFlag, boolean_T
  c56_vaFlag, real_T c56_gazeArr[6], real_T *c56_mutDurFactor, real_T
  *c56_avertDurFactor, real_T *c56_avertHeadFreqFactor, real_T
  *c56_avertHeadSpeed, real_T *c56_avertDirsChance, real_T *c56_avertFreqFactor,
  real_T *c56_mutFreqFactor)
{
  int32_T c56_i4;
  real_T c56_b_gazeArr[6];
  real_T c56_b_mutFreqFactor;
  real_T c56_b_avertFreqFactor;
  real_T c56_b_avertDirsChance;
  real_T c56_b_avertHeadSpeed;
  real_T c56_b_avertHeadFreqFactor;
  real_T c56_b_avertDurFactor;
  real_T c56_b_mutDurFactor;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  for (c56_i4 = 0; c56_i4 < 6; c56_i4++) {
    c56_b_gazeArr[c56_i4] = c56_gazeArr[c56_i4];
  }

  c56_setGazeFactorsc56_Expriment_FacialExpr(chartInstance, c56_v, c56_a, c56_p,
    c56_pFlag, c56_vaFlag, c56_b_gazeArr, &c56_b_mutDurFactor,
    &c56_b_avertDurFactor, &c56_b_avertHeadFreqFactor, &c56_b_avertHeadSpeed,
    &c56_b_avertDirsChance, &c56_b_avertFreqFactor, &c56_b_mutFreqFactor);
  *c56_mutDurFactor = c56_b_mutDurFactor;
  *c56_avertDurFactor = c56_b_avertDurFactor;
  *c56_avertHeadFreqFactor = c56_b_avertHeadFreqFactor;
  *c56_avertHeadSpeed = c56_b_avertHeadSpeed;
  *c56_avertDirsChance = c56_b_avertDirsChance;
  *c56_avertFreqFactor = c56_b_avertFreqFactor;
  *c56_mutFreqFactor = c56_b_mutFreqFactor;
}

void sf_exported_user_c56_Expriment_FacialExpr_setPoseFactors(SimStruct *c56_S,
  real_T c56_v, real_T c56_ar, real_T c56_p, boolean_T c56_pFlag, boolean_T
  c56_vaFlag, real_T c56_poseArr[6], real_T c56_personalityChange, real_T
  *c56_poseTwitch, real_T *c56_poseFreqFactor, real_T *c56_poseChanceFactor,
  real_T *c56_poseCatChance, real_T *c56_poseLean, real_T *c56_poseSpeed, real_T
  *c56_poseLeanFlag)
{
  int32_T c56_i5;
  real_T c56_b_poseArr[6];
  real_T c56_b_poseLeanFlag;
  real_T c56_b_poseSpeed;
  real_T c56_b_poseLean;
  real_T c56_b_poseCatChance;
  real_T c56_b_poseChanceFactor;
  real_T c56_b_poseFreqFactor;
  real_T c56_b_poseTwitch;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c56_S))->instanceInfo)->chartInstance;
  for (c56_i5 = 0; c56_i5 < 6; c56_i5++) {
    c56_b_poseArr[c56_i5] = c56_poseArr[c56_i5];
  }

  c56_setPoseFactorsc56_Expriment_FacialExpr(chartInstance, c56_v, c56_ar, c56_p,
    c56_pFlag, c56_vaFlag, c56_b_poseArr, c56_personalityChange,
    &c56_b_poseTwitch, &c56_b_poseFreqFactor, &c56_b_poseChanceFactor,
    &c56_b_poseCatChance, &c56_b_poseLean, &c56_b_poseSpeed, &c56_b_poseLeanFlag);
  *c56_poseTwitch = c56_b_poseTwitch;
  *c56_poseFreqFactor = c56_b_poseFreqFactor;
  *c56_poseChanceFactor = c56_b_poseChanceFactor;
  *c56_poseCatChance = c56_b_poseCatChance;
  *c56_poseLean = c56_b_poseLean;
  *c56_poseSpeed = c56_b_poseSpeed;
  *c56_poseLeanFlag = c56_b_poseLeanFlag;
}

static const mxArray *c56_d_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_u;
  const mxArray *c56_y = NULL;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(int32_T *)c56_inData;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_create("y", &c56_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_y, false);
  return c56_mxArrayOutData;
}

static int32_T c56_d_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  int32_T c56_y;
  int32_T c56_i6;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_i6, 1, 6, 0U, 0, 0U, 0);
  c56_y = c56_i6;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void c56_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_b_sfEvent;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  int32_T c56_y;
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c56_b_sfEvent = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_sfEvent),
    &c56_thisId);
  sf_mex_destroy(&c56_b_sfEvent);
  *(int32_T *)c56_outData = c56_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static uint8_T c56_e_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_b_is_active_c56_Expriment_FacialExpr, const
  char_T *c56_identifier)
{
  uint8_T c56_y;
  emlrtMsgIdentifier c56_thisId;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_y = c56_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c56_b_is_active_c56_Expriment_FacialExpr), &c56_thisId);
  sf_mex_destroy(&c56_b_is_active_c56_Expriment_FacialExpr);
  return c56_y;
}

static uint8_T c56_f_emlrt_marshallIn(SFc56_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  uint8_T c56_y;
  uint8_T c56_u0;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_u0, 1, 3, 0U, 0, 0U, 0);
  c56_y = c56_u0;
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static const mxArray *c56_g_emlrt_marshallIn
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c56_b_setSimStateSideEffectsInfo, const char_T *c56_identifier)
{
  const mxArray *c56_y = NULL;
  emlrtMsgIdentifier c56_thisId;
  c56_y = NULL;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  sf_mex_assign(&c56_y, c56_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c56_b_setSimStateSideEffectsInfo), &c56_thisId), false);
  sf_mex_destroy(&c56_b_setSimStateSideEffectsInfo);
  return c56_y;
}

static const mxArray *c56_h_emlrt_marshallIn
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray *c56_u,
   const emlrtMsgIdentifier *c56_parentId)
{
  const mxArray *c56_y = NULL;
  (void)chartInstance;
  (void)c56_parentId;
  c56_y = NULL;
  sf_mex_assign(&c56_y, sf_mex_duplicatearraysafe(&c56_u), false);
  sf_mex_destroy(&c56_u);
  return c56_y;
}

static void c56_updateDataWrittenToVector
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T
   c56_vectorIndex)
{
  (void)chartInstance;
  c56_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c56_vectorIndex, 0, 13, 1, 0)] = true;
}

static void c56_errorIfDataNotWrittenToFcn
  (SFc56_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T
   c56_vectorIndex, uint32_T c56_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c56_dataNumber, c56_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c56_vectorIndex, 0, 13, 1,
    0)]);
}

static void init_dsm_address_info(SFc56_Expriment_FacialExprInstanceStruct
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

void sf_c56_Expriment_FacialExpr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3621211203U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(860410655U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(112477690U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(711105709U);
}

mxArray *sf_c56_Expriment_FacialExpr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("38pcUp7yIxpOdSEQWx6ifC");
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

mxArray *sf_c56_Expriment_FacialExpr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c56_Expriment_FacialExpr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c56_Expriment_FacialExpr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c56_Expriment_FacialExpr\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c56_Expriment_FacialExpr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_FacialExprMachineNumber_,
           56,
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
        init_script_number_translation(_Expriment_FacialExprMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_FacialExprMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_FacialExprMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"setGazeFactorsc56_Expriment_FacialExpr",0,-1,
                             3071);
        _SFD_CV_INIT_EML_IF(0,1,0,2039,2055,2306,2327);
        _SFD_CV_INIT_EML_IF(0,1,1,2306,2327,2556,3070);
        _SFD_CV_INIT_EML_IF(0,1,2,2556,2577,2819,3070);
        _SFD_CV_INIT_EML_IF(0,1,3,2819,2841,-1,2841);

        {
          static int condStart[] = { 2042, 2050 };

          static int condEnd[] = { 2046, 2054 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,2042,2054,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2313, 2322 };

          static int condEnd[] = { 2318, 2326 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,2313,2326,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2563, 2571 };

          static int condEnd[] = { 2567, 2576 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,2563,2576,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2826, 2835 };

          static int condEnd[] = { 2831, 2840 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,2826,2840,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"setPoseFactorsc56_Expriment_FacialExpr",0,-1,
                             678);
        _SFD_CV_INIT_EML_IF(1,1,0,389,402,-1,676);
        _SFD_CV_INIT_EML_IF(1,1,1,411,421,-1,535);
        _SFD_CV_INIT_EML_IF(1,1,2,544,554,-1,668);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_c_sf_marshallOut,(MexInFcnForType)
          c56_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_c_sf_marshallOut,(MexInFcnForType)
          c56_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_b_sf_marshallOut,(MexInFcnForType)
            c56_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_c_sf_marshallOut,(MexInFcnForType)
          c56_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_c_sf_marshallOut,(MexInFcnForType)
          c56_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_b_sf_marshallOut,(MexInFcnForType)
            c56_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
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
        _Expriment_FacialExprMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ZW3N3c86PxNK3WJp4Ft4rC";
}

static void sf_opaque_initialize_c56_Expriment_FacialExpr(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc56_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c56_Expriment_FacialExpr
    ((SFc56_Expriment_FacialExprInstanceStruct*) chartInstanceVar);
  initialize_c56_Expriment_FacialExpr((SFc56_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c56_Expriment_FacialExpr(void *chartInstanceVar)
{
  enable_c56_Expriment_FacialExpr((SFc56_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c56_Expriment_FacialExpr(void *chartInstanceVar)
{
  disable_c56_Expriment_FacialExpr((SFc56_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c56_Expriment_FacialExpr(void *chartInstanceVar)
{
  sf_gateway_c56_Expriment_FacialExpr((SFc56_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c56_Expriment_FacialExpr
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c56_Expriment_FacialExpr
    ((SFc56_Expriment_FacialExprInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c56_Expriment_FacialExpr();/* state var info */
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

extern void sf_internal_set_sim_state_c56_Expriment_FacialExpr(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c56_Expriment_FacialExpr();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c56_Expriment_FacialExpr
    ((SFc56_Expriment_FacialExprInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c56_Expriment_FacialExpr(SimStruct*
  S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c56_Expriment_FacialExpr(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c56_Expriment_FacialExpr(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc56_Expriment_FacialExprInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_FacialExpr_optimization_info();
    }

    finalize_c56_Expriment_FacialExpr((SFc56_Expriment_FacialExprInstanceStruct*)
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
  initSimStructsc56_Expriment_FacialExpr
    ((SFc56_Expriment_FacialExprInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c56_Expriment_FacialExpr(SimStruct *S)
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
    initialize_params_c56_Expriment_FacialExpr
      ((SFc56_Expriment_FacialExprInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c56_Expriment_FacialExpr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_FacialExpr_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      56);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,56,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,56,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,56);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,56);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1233564068U));
  ssSetChecksum1(S,(488767209U));
  ssSetChecksum2(S,(1386414694U));
  ssSetChecksum3(S,(2308469503U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c56_Expriment_FacialExpr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c56_Expriment_FacialExpr(SimStruct *S)
{
  SFc56_Expriment_FacialExprInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc56_Expriment_FacialExprInstanceStruct *)utMalloc(sizeof
    (SFc56_Expriment_FacialExprInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc56_Expriment_FacialExprInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.mdlStart = mdlStart_c56_Expriment_FacialExpr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c56_Expriment_FacialExpr;
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

void c56_Expriment_FacialExpr_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c56_Expriment_FacialExpr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c56_Expriment_FacialExpr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c56_Expriment_FacialExpr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c56_Expriment_FacialExpr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
