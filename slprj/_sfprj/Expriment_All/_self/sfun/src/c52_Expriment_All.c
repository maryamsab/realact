/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_All_sfun.h"
#include "c52_Expriment_All.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_All_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c52_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "v1", "v2" };

/* Function Declarations */
static void initialize_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance);
static void initialize_params_c52_Expriment_All
  (SFc52_Expriment_AllInstanceStruct *chartInstance);
static void enable_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance);
static void disable_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance);
static void c52_update_debugger_state_c52_Expriment_All
  (SFc52_Expriment_AllInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c52_Expriment_All
  (SFc52_Expriment_AllInstanceStruct *chartInstance);
static void set_sim_state_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_st);
static void finalize_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance);
static void sf_gateway_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance);
static void initSimStructsc52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c52_machineNumber, uint32_T
  c52_chartNumber, uint32_T c52_instanceNumber);
static const mxArray *c52_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData);
static real_T c52_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_v2, const char_T *c52_identifier);
static real_T c52_b_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void c52_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData);
static const mxArray *c52_b_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData);
static boolean_T c52_c_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void c52_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData);
static const mxArray *c52_c_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData);
static int32_T c52_d_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void c52_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData);
static uint8_T c52_e_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_b_is_active_c52_Expriment_All, const char_T
  *c52_identifier);
static uint8_T c52_f_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId);
static void init_dsm_address_info(SFc52_Expriment_AllInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance)
{
  chartInstance->c52_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c52_is_active_c52_Expriment_All = 0U;
}

static void initialize_params_c52_Expriment_All
  (SFc52_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c52_update_debugger_state_c52_Expriment_All
  (SFc52_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c52_Expriment_All
  (SFc52_Expriment_AllInstanceStruct *chartInstance)
{
  const mxArray *c52_st;
  const mxArray *c52_y = NULL;
  real_T c52_hoistedGlobal;
  real_T c52_u;
  const mxArray *c52_b_y = NULL;
  uint8_T c52_b_hoistedGlobal;
  uint8_T c52_b_u;
  const mxArray *c52_c_y = NULL;
  real_T *c52_v2;
  c52_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c52_st = NULL;
  c52_st = NULL;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_createcellmatrix(2, 1), false);
  c52_hoistedGlobal = *c52_v2;
  c52_u = c52_hoistedGlobal;
  c52_b_y = NULL;
  sf_mex_assign(&c52_b_y, sf_mex_create("y", &c52_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c52_y, 0, c52_b_y);
  c52_b_hoistedGlobal = chartInstance->c52_is_active_c52_Expriment_All;
  c52_b_u = c52_b_hoistedGlobal;
  c52_c_y = NULL;
  sf_mex_assign(&c52_c_y, sf_mex_create("y", &c52_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c52_y, 1, c52_c_y);
  sf_mex_assign(&c52_st, c52_y, false);
  return c52_st;
}

static void set_sim_state_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_st)
{
  const mxArray *c52_u;
  real_T *c52_v2;
  c52_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c52_doneDoubleBufferReInit = true;
  c52_u = sf_mex_dup(c52_st);
  *c52_v2 = c52_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c52_u,
    0)), "v2");
  chartInstance->c52_is_active_c52_Expriment_All = c52_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c52_u, 1)),
     "is_active_c52_Expriment_All");
  sf_mex_destroy(&c52_u);
  c52_update_debugger_state_c52_Expriment_All(chartInstance);
  sf_mex_destroy(&c52_st);
}

static void finalize_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance)
{
  real_T c52_hoistedGlobal;
  real_T c52_v1;
  uint32_T c52_debug_family_var_map[6];
  boolean_T c52_aVarTruthTableCondition_1;
  boolean_T c52_aVarTruthTableCondition_2;
  real_T c52_nargin = 1.0;
  real_T c52_nargout = 1.0;
  real_T c52_v2;
  real_T *c52_b_v2;
  real_T *c52_b_v1;
  c52_b_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c52_b_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 27U, chartInstance->c52_sfEvent);
  chartInstance->c52_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c52_sfEvent);
  c52_hoistedGlobal = *c52_b_v1;
  c52_v1 = c52_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c52_debug_family_names,
    c52_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_aVarTruthTableCondition_1, 0U,
    c52_b_sf_marshallOut, c52_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_aVarTruthTableCondition_2, 1U,
    c52_b_sf_marshallOut, c52_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_nargin, 2U, c52_sf_marshallOut,
    c52_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_nargout, 3U, c52_sf_marshallOut,
    c52_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c52_v1, 4U, c52_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c52_v2, 5U, c52_sf_marshallOut,
    c52_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 3);
  c52_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 4);
  c52_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 8);
  c52_aVarTruthTableCondition_1 = (c52_v1 > 25.0);
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 11);
  c52_aVarTruthTableCondition_2 = (c52_v1 < -25.0);
  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, c52_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 14);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 24);
    c52_v2 = c52_v1;
    _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, -24);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 15);
    if (CV_EML_IF(0, 1, 1, c52_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 16);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 29);
      c52_v2 = c52_v1;
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, -29);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 18);
      CV_EML_FCN(0, 3);
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, 34);
      c52_v2 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, -34);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c52_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c52_b_v2 = c52_v2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c52_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_AllMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c52_b_v2, 0U);
  _SFD_DATA_RANGE_CHECK(*c52_b_v1, 1U);
}

static void initSimStructsc52_Expriment_All(SFc52_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c52_machineNumber, uint32_T
  c52_chartNumber, uint32_T c52_instanceNumber)
{
  (void)c52_machineNumber;
  (void)c52_chartNumber;
  (void)c52_instanceNumber;
}

static const mxArray *c52_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData)
{
  const mxArray *c52_mxArrayOutData = NULL;
  real_T c52_u;
  const mxArray *c52_y = NULL;
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c52_mxArrayOutData = NULL;
  c52_u = *(real_T *)c52_inData;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_create("y", &c52_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c52_mxArrayOutData, c52_y, false);
  return c52_mxArrayOutData;
}

static real_T c52_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_v2, const char_T *c52_identifier)
{
  real_T c52_y;
  emlrtMsgIdentifier c52_thisId;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_v2), &c52_thisId);
  sf_mex_destroy(&c52_v2);
  return c52_y;
}

static real_T c52_b_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  real_T c52_y;
  real_T c52_d0;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_d0, 1, 0, 0U, 0, 0U, 0);
  c52_y = c52_d0;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void c52_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData)
{
  const mxArray *c52_v2;
  const char_T *c52_identifier;
  emlrtMsgIdentifier c52_thisId;
  real_T c52_y;
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c52_v2 = sf_mex_dup(c52_mxArrayInData);
  c52_identifier = c52_varName;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_v2), &c52_thisId);
  sf_mex_destroy(&c52_v2);
  *(real_T *)c52_outData = c52_y;
  sf_mex_destroy(&c52_mxArrayInData);
}

static const mxArray *c52_b_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData)
{
  const mxArray *c52_mxArrayOutData = NULL;
  boolean_T c52_u;
  const mxArray *c52_y = NULL;
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c52_mxArrayOutData = NULL;
  c52_u = *(boolean_T *)c52_inData;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_create("y", &c52_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c52_mxArrayOutData, c52_y, false);
  return c52_mxArrayOutData;
}

static boolean_T c52_c_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  boolean_T c52_y;
  boolean_T c52_b0;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_b0, 1, 11, 0U, 0, 0U, 0);
  c52_y = c52_b0;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void c52_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData)
{
  const mxArray *c52_aVarTruthTableCondition_2;
  const char_T *c52_identifier;
  emlrtMsgIdentifier c52_thisId;
  boolean_T c52_y;
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c52_aVarTruthTableCondition_2 = sf_mex_dup(c52_mxArrayInData);
  c52_identifier = c52_varName;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c52_aVarTruthTableCondition_2), &c52_thisId);
  sf_mex_destroy(&c52_aVarTruthTableCondition_2);
  *(boolean_T *)c52_outData = c52_y;
  sf_mex_destroy(&c52_mxArrayInData);
}

const mxArray *sf_c52_Expriment_All_get_eml_resolved_functions_info(void)
{
  const mxArray *c52_nameCaptureInfo = NULL;
  c52_nameCaptureInfo = NULL;
  sf_mex_assign(&c52_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c52_nameCaptureInfo;
}

static const mxArray *c52_c_sf_marshallOut(void *chartInstanceVoid, void
  *c52_inData)
{
  const mxArray *c52_mxArrayOutData = NULL;
  int32_T c52_u;
  const mxArray *c52_y = NULL;
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c52_mxArrayOutData = NULL;
  c52_u = *(int32_T *)c52_inData;
  c52_y = NULL;
  sf_mex_assign(&c52_y, sf_mex_create("y", &c52_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c52_mxArrayOutData, c52_y, false);
  return c52_mxArrayOutData;
}

static int32_T c52_d_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  int32_T c52_y;
  int32_T c52_i0;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_i0, 1, 6, 0U, 0, 0U, 0);
  c52_y = c52_i0;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void c52_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c52_mxArrayInData, const char_T *c52_varName, void *c52_outData)
{
  const mxArray *c52_b_sfEvent;
  const char_T *c52_identifier;
  emlrtMsgIdentifier c52_thisId;
  int32_T c52_y;
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c52_b_sfEvent = sf_mex_dup(c52_mxArrayInData);
  c52_identifier = c52_varName;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c52_b_sfEvent),
    &c52_thisId);
  sf_mex_destroy(&c52_b_sfEvent);
  *(int32_T *)c52_outData = c52_y;
  sf_mex_destroy(&c52_mxArrayInData);
}

static uint8_T c52_e_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_b_is_active_c52_Expriment_All, const char_T
  *c52_identifier)
{
  uint8_T c52_y;
  emlrtMsgIdentifier c52_thisId;
  c52_thisId.fIdentifier = c52_identifier;
  c52_thisId.fParent = NULL;
  c52_y = c52_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c52_b_is_active_c52_Expriment_All), &c52_thisId);
  sf_mex_destroy(&c52_b_is_active_c52_Expriment_All);
  return c52_y;
}

static uint8_T c52_f_emlrt_marshallIn(SFc52_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c52_u, const emlrtMsgIdentifier *c52_parentId)
{
  uint8_T c52_y;
  uint8_T c52_u0;
  (void)chartInstance;
  sf_mex_import(c52_parentId, sf_mex_dup(c52_u), &c52_u0, 1, 3, 0U, 0, 0U, 0);
  c52_y = c52_u0;
  sf_mex_destroy(&c52_u);
  return c52_y;
}

static void init_dsm_address_info(SFc52_Expriment_AllInstanceStruct
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

void sf_c52_Expriment_All_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4026600077U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(629412063U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(709736593U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1843946743U);
}

mxArray *sf_c52_Expriment_All_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EuZRnyhPFvbAKeV9Xs3xlD");
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

mxArray *sf_c52_Expriment_All_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c52_Expriment_All_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c52_Expriment_All(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"v2\",},{M[8],M[0],T\"is_active_c52_Expriment_All\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c52_Expriment_All_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc52_Expriment_AllInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc52_Expriment_AllInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_AllMachineNumber_,
           52,
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
        init_script_number_translation(_Expriment_AllMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_AllMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_AllMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"v2");
          _SFD_SET_DATA_PROPS(1,1,1,0,"v1");
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
          (MexFcnForType)c52_sf_marshallOut,(MexInFcnForType)c52_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c52_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c52_v2;
          real_T *c52_v1;
          c52_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c52_v2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c52_v2);
          _SFD_SET_DATA_VALUE_PTR(1U, c52_v1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_AllMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "G8dVEy14Q9jhJKpvmXcxPD";
}

static void sf_opaque_initialize_c52_Expriment_All(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc52_Expriment_AllInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
    chartInstanceVar);
  initialize_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c52_Expriment_All(void *chartInstanceVar)
{
  enable_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c52_Expriment_All(void *chartInstanceVar)
{
  disable_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c52_Expriment_All(void *chartInstanceVar)
{
  sf_gateway_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c52_Expriment_All(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c52_Expriment_All
    ((SFc52_Expriment_AllInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c52_Expriment_All();/* state var info */
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

extern void sf_internal_set_sim_state_c52_Expriment_All(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c52_Expriment_All();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c52_Expriment_All(SimStruct* S)
{
  return sf_internal_get_sim_state_c52_Expriment_All(S);
}

static void sf_opaque_set_sim_state_c52_Expriment_All(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c52_Expriment_All(S, st);
}

static void sf_opaque_terminate_c52_Expriment_All(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc52_Expriment_AllInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_All_optimization_info();
    }

    finalize_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
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
  initSimStructsc52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c52_Expriment_All(SimStruct *S)
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
    initialize_params_c52_Expriment_All((SFc52_Expriment_AllInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c52_Expriment_All(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_All_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      52);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,52,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,52,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,52);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,52,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,52,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,52);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2104411969U));
  ssSetChecksum1(S,(4031701563U));
  ssSetChecksum2(S,(3206155808U));
  ssSetChecksum3(S,(2273650533U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c52_Expriment_All(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c52_Expriment_All(SimStruct *S)
{
  SFc52_Expriment_AllInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc52_Expriment_AllInstanceStruct *)utMalloc(sizeof
    (SFc52_Expriment_AllInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc52_Expriment_AllInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c52_Expriment_All;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c52_Expriment_All;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c52_Expriment_All;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c52_Expriment_All;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c52_Expriment_All;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c52_Expriment_All;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c52_Expriment_All;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c52_Expriment_All;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c52_Expriment_All;
  chartInstance->chartInfo.mdlStart = mdlStart_c52_Expriment_All;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c52_Expriment_All;
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

void c52_Expriment_All_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c52_Expriment_All(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c52_Expriment_All(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c52_Expriment_All(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c52_Expriment_All_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
