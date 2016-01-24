/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testYarpSendText_cpp1_sfun.h"
#include "c1_testYarpSendText_cpp1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testYarpSendText_cpp1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[3] = { "nargin", "nargout", "y" };

static const char * c1_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void initialize_params_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void enable_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void disable_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void set_sim_state_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void sf_gateway_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void initSimStructsc1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_y, const char_T *c1_identifier, real_T
  c1_b_y[256]);
static void c1_b_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_testYarpSendText_cpp1, const
  char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_testYarpSendText_cpp1 = 0U;
}

static void initialize_params_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[256];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_d_y)[256];
  c1_d_y = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  for (c1_i0 = 0; c1_i0 < 256; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_testYarpSendText_cpp1;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[256];
  int32_T c1_i1;
  real_T (*c1_y)[256];
  c1_y = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    (*c1_y)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_testYarpSendText_cpp1 = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_testYarpSendText_cpp1");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_testYarpSendText_cpp1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[256];
  uint32_T c1_b_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[13];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[13];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i2;
  static char_T c1_cv0[13] = { 't', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n',
    'g', ' ', '2' };

  int32_T c1_i3;
  static real_T c1_dv1[13] = { 116.0, 101.0, 115.0, 116.0, 32.0, 115.0, 116.0,
    114.0, 105.0, 110.0, 103.0, 32.0, 50.0 };

  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T (*c1_b_y)[256];
  c1_b_y = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  for (c1_i2 = 0; c1_i2 < 13; c1_i2++) {
    c1_mystr[c1_i2] = c1_cv0[c1_i2];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i3 = 0; c1_i3 < 13; c1_i3++) {
    c1_arr[c1_i3] = c1_dv1[c1_i3];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 13.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
    c1_tt[c1_i4] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i5 = 0; c1_i5 < 13; c1_i5++) {
    c1_tt[c1_i5] = c1_arr[c1_i5];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i6 = 0; c1_i6 < 256; c1_i6++) {
    c1_y[c1_i6] = c1_tt[c1_i6];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -2);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
    (*c1_b_y)[c1_i7] = c1_y[c1_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testYarpSendText_cpp1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i8 = 0; c1_i8 < 256; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_y)[c1_i8], 0U);
  }
}

static void initSimStructsc1_testYarpSendText_cpp1
  (SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i9;
  real_T c1_b_inData[256];
  int32_T c1_i10;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i9 = 0; c1_i9 < 256; c1_i9++) {
    c1_b_inData[c1_i9] = (*(real_T (*)[256])c1_inData)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 256; c1_i10++) {
    c1_u[c1_i10] = c1_b_inData[c1_i10];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_y, const char_T *c1_identifier, real_T
  c1_b_y[256])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
}

static void c1_b_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256])
{
  real_T c1_dv2[256];
  int32_T c1_i11;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 256);
  for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
    c1_y[c1_i11] = c1_dv2[c1_i11];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[256];
  int32_T c1_i12;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
    (*(real_T (*)[256])c1_outData)[c1_i12] = c1_b_y[c1_i12];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i13;
  char_T c1_b_inData[13];
  int32_T c1_i14;
  char_T c1_u[13];
  const mxArray *c1_y = NULL;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i13 = 0; c1_i13 < 13; c1_i13++) {
    c1_b_inData[c1_i13] = (*(char_T (*)[13])c1_inData)[c1_i13];
  }

  for (c1_i14 = 0; c1_i14 < 13; c1_i14++) {
    c1_u[c1_i14] = c1_b_inData[c1_i14];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 13), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i15;
  real_T c1_b_inData[13];
  int32_T c1_i16;
  real_T c1_u[13];
  const mxArray *c1_y = NULL;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i15 = 0; c1_i15 < 13; c1_i15++) {
    c1_b_inData[c1_i15] = (*(real_T (*)[13])c1_inData)[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 13; c1_i16++) {
    c1_u[c1_i16] = c1_b_inData[c1_i16];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_testYarpSendText_cpp1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i17;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i17, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i17;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_testYarpSendText_cpp1, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_testYarpSendText_cpp1), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_testYarpSendText_cpp1);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_testYarpSendText_cpp1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_testYarpSendText_cpp1InstanceStruct
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

void sf_c1_testYarpSendText_cpp1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2996985919U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1381112666U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2515449797U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4046344746U);
}

mxArray *sf_c1_testYarpSendText_cpp1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hO6PRZcAl6uR1QLPtsonMG");
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
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

mxArray *sf_c1_testYarpSendText_cpp1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_testYarpSendText_cpp1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_testYarpSendText_cpp1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_testYarpSendText_cpp1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_testYarpSendText_cpp1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testYarpSendText_cpp1MachineNumber_,
           1,
           1,
           1,
           0,
           1,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testYarpSendText_cpp1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testYarpSendText_cpp1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testYarpSendText_cpp1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,51);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T (*c1_y)[256];
          c1_y = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testYarpSendText_cpp1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3DxJSfnPGhNlQvZgHwnHjE";
}

static void sf_opaque_initialize_c1_testYarpSendText_cpp1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_testYarpSendText_cpp1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_testYarpSendText_cpp1
    ((SFc1_testYarpSendText_cpp1InstanceStruct*) chartInstanceVar);
  initialize_c1_testYarpSendText_cpp1((SFc1_testYarpSendText_cpp1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_testYarpSendText_cpp1(void *chartInstanceVar)
{
  enable_c1_testYarpSendText_cpp1((SFc1_testYarpSendText_cpp1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_testYarpSendText_cpp1(void *chartInstanceVar)
{
  disable_c1_testYarpSendText_cpp1((SFc1_testYarpSendText_cpp1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_testYarpSendText_cpp1(void *chartInstanceVar)
{
  sf_gateway_c1_testYarpSendText_cpp1((SFc1_testYarpSendText_cpp1InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_testYarpSendText_cpp1
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_testYarpSendText_cpp1
    ((SFc1_testYarpSendText_cpp1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_testYarpSendText_cpp1();/* state var info */
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

extern void sf_internal_set_sim_state_c1_testYarpSendText_cpp1(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_testYarpSendText_cpp1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_testYarpSendText_cpp1
    ((SFc1_testYarpSendText_cpp1InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_testYarpSendText_cpp1(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_testYarpSendText_cpp1(S);
}

static void sf_opaque_set_sim_state_c1_testYarpSendText_cpp1(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_testYarpSendText_cpp1(S, st);
}

static void sf_opaque_terminate_c1_testYarpSendText_cpp1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_testYarpSendText_cpp1InstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testYarpSendText_cpp1_optimization_info();
    }

    finalize_c1_testYarpSendText_cpp1((SFc1_testYarpSendText_cpp1InstanceStruct*)
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
  initSimStructsc1_testYarpSendText_cpp1
    ((SFc1_testYarpSendText_cpp1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_testYarpSendText_cpp1(SimStruct *S)
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
    initialize_params_c1_testYarpSendText_cpp1
      ((SFc1_testYarpSendText_cpp1InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_testYarpSendText_cpp1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testYarpSendText_cpp1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3182406406U));
  ssSetChecksum1(S,(4060674286U));
  ssSetChecksum2(S,(1015061516U));
  ssSetChecksum3(S,(3894719939U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_testYarpSendText_cpp1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_testYarpSendText_cpp1(SimStruct *S)
{
  SFc1_testYarpSendText_cpp1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_testYarpSendText_cpp1InstanceStruct *)utMalloc(sizeof
    (SFc1_testYarpSendText_cpp1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_testYarpSendText_cpp1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_testYarpSendText_cpp1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_testYarpSendText_cpp1;
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

void c1_testYarpSendText_cpp1_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_testYarpSendText_cpp1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_testYarpSendText_cpp1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_testYarpSendText_cpp1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_testYarpSendText_cpp1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
