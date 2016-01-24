/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testYarpReadSHORE_sfun.h"
#include "c5_testYarpReadSHORE.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testYarpReadSHORE_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[9] = { "nx", "cx", "ox", "nargin",
  "nargout", "nextX", "currentX", "oldX", "y" };

/* Function Declarations */
static void initialize_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance);
static void initialize_params_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance);
static void enable_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance);
static void disable_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance);
static void set_sim_state_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance);
static void sf_gateway_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance);
static void initSimStructsc5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_y, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_testYarpReadSHORE, const
  char_T *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_testYarpReadSHORE = 0U;
}

static void initialize_params_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_d_y;
  c5_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  c5_hoistedGlobal = *c5_d_y;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_testYarpReadSHORE;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_y;
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "y");
  chartInstance->c5_is_active_c5_testYarpReadSHORE = c5_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_testYarpReadSHORE");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_testYarpReadSHORE(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_testYarpReadSHORE(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_nextX;
  real_T c5_currentX;
  real_T c5_oldX;
  uint32_T c5_debug_family_var_map[9];
  real_T c5_nx;
  real_T c5_cx;
  real_T c5_ox;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_y;
  real_T *c5_b_nextX;
  real_T *c5_b_currentX;
  real_T *c5_b_y;
  real_T *c5_b_oldX;
  boolean_T guard1 = false;
  c5_b_oldX = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_currentX = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_nextX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_nextX, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_currentX, 1U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_nextX;
  c5_b_hoistedGlobal = *c5_b_currentX;
  c5_c_hoistedGlobal = *c5_b_oldX;
  c5_nextX = c5_hoistedGlobal;
  c5_currentX = c5_b_hoistedGlobal;
  c5_oldX = c5_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nx, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_cx, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_ox, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_nextX, 5U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_currentX, 6U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_oldX, 7U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_y, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, c5_nextX > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
    c5_nx = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
    c5_nx = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  if (CV_EML_IF(0, 1, 1, c5_currentX > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
    c5_cx = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
    c5_cx = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  if (CV_EML_IF(0, 1, 2, c5_oldX > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
    c5_ox = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
    c5_ox = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, c5_nx != c5_cx)) {
    if (CV_EML_COND(0, 1, 1, c5_cx != c5_ox)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 3, true);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
      c5_currentX = c5_oldX;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 3, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_y = c5_currentX;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  *c5_b_y = c5_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testYarpReadSHOREMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c5_b_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_oldX, 3U);
}

static void initSimStructsc5_testYarpReadSHORE
  (SFc5_testYarpReadSHOREInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testYarpReadSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc5_testYarpReadSHOREInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_y, const char_T *c5_identifier)
{
  real_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId);
  sf_mex_destroy(&c5_y);
  return c5_b_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  SFc5_testYarpReadSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc5_testYarpReadSHOREInstanceStruct *)chartInstanceVoid;
  c5_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId);
  sf_mex_destroy(&c5_y);
  *(real_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_testYarpReadSHORE_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testYarpReadSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc5_testYarpReadSHOREInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i0, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_testYarpReadSHOREInstanceStruct *chartInstance;
  chartInstance = (SFc5_testYarpReadSHOREInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_testYarpReadSHORE, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_testYarpReadSHORE), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_testYarpReadSHORE);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_testYarpReadSHOREInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_testYarpReadSHOREInstanceStruct
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

void sf_c5_testYarpReadSHORE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2061020856U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3336847349U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2109010748U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1007215531U);
}

mxArray *sf_c5_testYarpReadSHORE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vCJTxbg06TDcA7VUfARU0E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c5_testYarpReadSHORE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_testYarpReadSHORE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_testYarpReadSHORE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_testYarpReadSHORE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_testYarpReadSHORE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_testYarpReadSHOREInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_testYarpReadSHOREInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testYarpReadSHOREMachineNumber_,
           5,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testYarpReadSHOREMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testYarpReadSHOREMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testYarpReadSHOREMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"nextX");
          _SFD_SET_DATA_PROPS(1,1,1,0,"currentX");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"oldX");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,428);
        _SFD_CV_INIT_EML_IF(0,1,0,241,252,264,282);
        _SFD_CV_INIT_EML_IF(0,1,1,283,297,309,327);
        _SFD_CV_INIT_EML_IF(0,1,2,328,338,349,367);
        _SFD_CV_INIT_EML_IF(0,1,3,369,389,-1,414);

        {
          static int condStart[] = { 372, 382 };

          static int condEnd[] = { 378, 388 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,371,389,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_nextX;
          real_T *c5_currentX;
          real_T *c5_y;
          real_T *c5_oldX;
          c5_oldX = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_currentX = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_nextX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_nextX);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_currentX);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_oldX);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testYarpReadSHOREMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3VE1PeCdGgbX9ZNGzeY23D";
}

static void sf_opaque_initialize_c5_testYarpReadSHORE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar);
  initialize_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_testYarpReadSHORE(void *chartInstanceVar)
{
  enable_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_testYarpReadSHORE(void *chartInstanceVar)
{
  disable_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_testYarpReadSHORE(void *chartInstanceVar)
{
  sf_gateway_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_testYarpReadSHORE(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_testYarpReadSHORE
    ((SFc5_testYarpReadSHOREInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_testYarpReadSHORE();/* state var info */
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

extern void sf_internal_set_sim_state_c5_testYarpReadSHORE(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_testYarpReadSHORE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_testYarpReadSHORE(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_testYarpReadSHORE(S);
}

static void sf_opaque_set_sim_state_c5_testYarpReadSHORE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_testYarpReadSHORE(S, st);
}

static void sf_opaque_terminate_c5_testYarpReadSHORE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_testYarpReadSHOREInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testYarpReadSHORE_optimization_info();
    }

    finalize_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
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
  initSimStructsc5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_testYarpReadSHORE(SimStruct *S)
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
    initialize_params_c5_testYarpReadSHORE((SFc5_testYarpReadSHOREInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_testYarpReadSHORE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testYarpReadSHORE_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1653211081U));
  ssSetChecksum1(S,(495447997U));
  ssSetChecksum2(S,(1561699203U));
  ssSetChecksum3(S,(1945917740U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_testYarpReadSHORE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_testYarpReadSHORE(SimStruct *S)
{
  SFc5_testYarpReadSHOREInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_testYarpReadSHOREInstanceStruct *)utMalloc(sizeof
    (SFc5_testYarpReadSHOREInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_testYarpReadSHOREInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_testYarpReadSHORE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_testYarpReadSHORE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_testYarpReadSHORE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_testYarpReadSHORE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_testYarpReadSHORE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_testYarpReadSHORE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_testYarpReadSHORE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_testYarpReadSHORE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_testYarpReadSHORE;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_testYarpReadSHORE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_testYarpReadSHORE;
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

void c5_testYarpReadSHORE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_testYarpReadSHORE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_testYarpReadSHORE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_testYarpReadSHORE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_testYarpReadSHORE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
