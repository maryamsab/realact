/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_FacialExpr_sfun.h"
#include "c44_Expriment_FacialExpr.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_FacialExpr_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c44_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "a1", "a2" };

/* Function Declarations */
static void initialize_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void initialize_params_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void enable_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void disable_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void c44_update_debugger_state_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void set_sim_state_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c44_st);
static void finalize_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void sf_gateway_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void initSimStructsc44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c44_machineNumber, uint32_T
  c44_chartNumber, uint32_T c44_instanceNumber);
static const mxArray *c44_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static real_T c44_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_a2, const char_T *c44_identifier);
static real_T c44_b_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_b_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static boolean_T c44_c_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_c_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static int32_T c44_d_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static uint8_T c44_e_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_b_is_active_c44_Expriment_FacialExpr, const
  char_T *c44_identifier);
static uint8_T c44_f_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void init_dsm_address_info(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  chartInstance->c44_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c44_is_active_c44_Expriment_FacialExpr = 0U;
}

static void initialize_params_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c44_update_debugger_state_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  const mxArray *c44_st;
  const mxArray *c44_y = NULL;
  real_T c44_hoistedGlobal;
  real_T c44_u;
  const mxArray *c44_b_y = NULL;
  uint8_T c44_b_hoistedGlobal;
  uint8_T c44_b_u;
  const mxArray *c44_c_y = NULL;
  real_T *c44_a2;
  c44_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c44_st = NULL;
  c44_st = NULL;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_createcellmatrix(2, 1), false);
  c44_hoistedGlobal = *c44_a2;
  c44_u = c44_hoistedGlobal;
  c44_b_y = NULL;
  sf_mex_assign(&c44_b_y, sf_mex_create("y", &c44_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c44_y, 0, c44_b_y);
  c44_b_hoistedGlobal = chartInstance->c44_is_active_c44_Expriment_FacialExpr;
  c44_b_u = c44_b_hoistedGlobal;
  c44_c_y = NULL;
  sf_mex_assign(&c44_c_y, sf_mex_create("y", &c44_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c44_y, 1, c44_c_y);
  sf_mex_assign(&c44_st, c44_y, false);
  return c44_st;
}

static void set_sim_state_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c44_st)
{
  const mxArray *c44_u;
  real_T *c44_a2;
  c44_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c44_doneDoubleBufferReInit = true;
  c44_u = sf_mex_dup(c44_st);
  *c44_a2 = c44_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c44_u,
    0)), "a2");
  chartInstance->c44_is_active_c44_Expriment_FacialExpr = c44_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c44_u, 1)),
     "is_active_c44_Expriment_FacialExpr");
  sf_mex_destroy(&c44_u);
  c44_update_debugger_state_c44_Expriment_FacialExpr(chartInstance);
  sf_mex_destroy(&c44_st);
}

static void finalize_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  real_T c44_hoistedGlobal;
  real_T c44_a1;
  uint32_T c44_debug_family_var_map[6];
  boolean_T c44_aVarTruthTableCondition_1;
  boolean_T c44_aVarTruthTableCondition_2;
  real_T c44_nargin = 1.0;
  real_T c44_nargout = 1.0;
  real_T c44_a2;
  real_T *c44_b_a2;
  real_T *c44_b_a1;
  c44_b_a1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c44_b_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
  chartInstance->c44_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
  c44_hoistedGlobal = *c44_b_a1;
  c44_a1 = c44_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c44_debug_family_names,
    c44_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_aVarTruthTableCondition_1, 0U,
    c44_b_sf_marshallOut, c44_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_aVarTruthTableCondition_2, 1U,
    c44_b_sf_marshallOut, c44_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_nargin, 2U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_nargout, 3U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c44_a1, 4U, c44_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_a2, 5U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 3);
  c44_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 4);
  c44_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 8);
  c44_aVarTruthTableCondition_1 = (c44_a1 > 10.0);
  _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 11);
  c44_aVarTruthTableCondition_2 = (c44_a1 < -10.0);
  _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, c44_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 14);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 24);
    c44_a2 = c44_a1;
    _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, -24);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 15);
    if (CV_EML_IF(0, 1, 1, c44_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 16);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 29);
      c44_a2 = c44_a1;
      _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, -29);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 18);
      CV_EML_FCN(0, 3);
      _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, 34);
      c44_a2 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, -34);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c44_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c44_b_a2 = c44_a2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_FacialExprMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c44_b_a2, 0U);
  _SFD_DATA_RANGE_CHECK(*c44_b_a1, 1U);
}

static void initSimStructsc44_Expriment_FacialExpr
  (SFc44_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c44_machineNumber, uint32_T
  c44_chartNumber, uint32_T c44_instanceNumber)
{
  (void)c44_machineNumber;
  (void)c44_chartNumber;
  (void)c44_instanceNumber;
}

static const mxArray *c44_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  real_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(real_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static real_T c44_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_a2, const char_T *c44_identifier)
{
  real_T c44_y;
  emlrtMsgIdentifier c44_thisId;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_a2), &c44_thisId);
  sf_mex_destroy(&c44_a2);
  return c44_y;
}

static real_T c44_b_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  real_T c44_y;
  real_T c44_d0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_d0, 1, 0, 0U, 0, 0U, 0);
  c44_y = c44_d0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_a2;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y;
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c44_a2 = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_a2), &c44_thisId);
  sf_mex_destroy(&c44_a2);
  *(real_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_b_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  boolean_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(boolean_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static boolean_T c44_c_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  boolean_T c44_y;
  boolean_T c44_b0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_b0, 1, 11, 0U, 0, 0U, 0);
  c44_y = c44_b0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_aVarTruthTableCondition_2;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  boolean_T c44_y;
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c44_aVarTruthTableCondition_2 = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c44_aVarTruthTableCondition_2), &c44_thisId);
  sf_mex_destroy(&c44_aVarTruthTableCondition_2);
  *(boolean_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

const mxArray *sf_c44_Expriment_FacialExpr_get_eml_resolved_functions_info(void)
{
  const mxArray *c44_nameCaptureInfo = NULL;
  c44_nameCaptureInfo = NULL;
  sf_mex_assign(&c44_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c44_nameCaptureInfo;
}

static const mxArray *c44_c_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(int32_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static int32_T c44_d_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  int32_T c44_y;
  int32_T c44_i0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_i0, 1, 6, 0U, 0, 0U, 0);
  c44_y = c44_i0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_b_sfEvent;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  int32_T c44_y;
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c44_b_sfEvent = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_b_sfEvent),
    &c44_thisId);
  sf_mex_destroy(&c44_b_sfEvent);
  *(int32_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static uint8_T c44_e_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_b_is_active_c44_Expriment_FacialExpr, const
  char_T *c44_identifier)
{
  uint8_T c44_y;
  emlrtMsgIdentifier c44_thisId;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c44_b_is_active_c44_Expriment_FacialExpr), &c44_thisId);
  sf_mex_destroy(&c44_b_is_active_c44_Expriment_FacialExpr);
  return c44_y;
}

static uint8_T c44_f_emlrt_marshallIn(SFc44_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  uint8_T c44_y;
  uint8_T c44_u0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_u0, 1, 3, 0U, 0, 0U, 0);
  c44_y = c44_u0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void init_dsm_address_info(SFc44_Expriment_FacialExprInstanceStruct
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

void sf_c44_Expriment_FacialExpr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(78602949U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2537543991U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2918652615U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2140883148U);
}

mxArray *sf_c44_Expriment_FacialExpr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DhoVYgIDduzaygrqenV8YH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c44_Expriment_FacialExpr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c44_Expriment_FacialExpr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c44_Expriment_FacialExpr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"a2\",},{M[8],M[0],T\"is_active_c44_Expriment_FacialExpr\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c44_Expriment_FacialExpr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_FacialExprMachineNumber_,
           44,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"a2");
          _SFD_SET_DATA_PROPS(1,1,1,0,"a1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,364);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",364,-1,408);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",408,-1,452);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",452,-1,494);
        _SFD_CV_INIT_EML_IF(0,1,0,188,218,249,362);
        _SFD_CV_INIT_EML_IF(0,1,1,249,283,314,362);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c44_a2;
          real_T *c44_a1;
          c44_a1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c44_a2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c44_a2);
          _SFD_SET_DATA_VALUE_PTR(1U, c44_a1);
        }
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
  return "5u7Cw7rrbDyE00DesPxmND";
}

static void sf_opaque_initialize_c44_Expriment_FacialExpr(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc44_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c44_Expriment_FacialExpr
    ((SFc44_Expriment_FacialExprInstanceStruct*) chartInstanceVar);
  initialize_c44_Expriment_FacialExpr((SFc44_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c44_Expriment_FacialExpr(void *chartInstanceVar)
{
  enable_c44_Expriment_FacialExpr((SFc44_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c44_Expriment_FacialExpr(void *chartInstanceVar)
{
  disable_c44_Expriment_FacialExpr((SFc44_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c44_Expriment_FacialExpr(void *chartInstanceVar)
{
  sf_gateway_c44_Expriment_FacialExpr((SFc44_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c44_Expriment_FacialExpr
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c44_Expriment_FacialExpr
    ((SFc44_Expriment_FacialExprInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c44_Expriment_FacialExpr();/* state var info */
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

extern void sf_internal_set_sim_state_c44_Expriment_FacialExpr(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c44_Expriment_FacialExpr();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c44_Expriment_FacialExpr
    ((SFc44_Expriment_FacialExprInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c44_Expriment_FacialExpr(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c44_Expriment_FacialExpr(S);
}

static void sf_opaque_set_sim_state_c44_Expriment_FacialExpr(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c44_Expriment_FacialExpr(S, st);
}

static void sf_opaque_terminate_c44_Expriment_FacialExpr(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc44_Expriment_FacialExprInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_FacialExpr_optimization_info();
    }

    finalize_c44_Expriment_FacialExpr((SFc44_Expriment_FacialExprInstanceStruct*)
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
  initSimStructsc44_Expriment_FacialExpr
    ((SFc44_Expriment_FacialExprInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c44_Expriment_FacialExpr(SimStruct *S)
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
    initialize_params_c44_Expriment_FacialExpr
      ((SFc44_Expriment_FacialExprInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c44_Expriment_FacialExpr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_FacialExpr_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      44);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,44,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,44,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,44);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,44,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,44,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,44);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(601486908U));
  ssSetChecksum1(S,(2126662679U));
  ssSetChecksum2(S,(2146104272U));
  ssSetChecksum3(S,(1490131804U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c44_Expriment_FacialExpr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c44_Expriment_FacialExpr(SimStruct *S)
{
  SFc44_Expriment_FacialExprInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc44_Expriment_FacialExprInstanceStruct *)utMalloc(sizeof
    (SFc44_Expriment_FacialExprInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc44_Expriment_FacialExprInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.mdlStart = mdlStart_c44_Expriment_FacialExpr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c44_Expriment_FacialExpr;
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

void c44_Expriment_FacialExpr_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c44_Expriment_FacialExpr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c44_Expriment_FacialExpr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c44_Expriment_FacialExpr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c44_Expriment_FacialExpr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
