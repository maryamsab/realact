/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectBeatSmile_sfun.h"
#include "c2_testKinectBeatSmile.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectBeatSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[5] = { "mystr", "nargin", "nargout",
  "handUp", "arrBML" };

static const char * c2_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c2_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void initialize_params_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void enable_c2_testKinectBeatSmile(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance);
static void disable_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void set_sim_state_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void sf_gateway_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void initSimStructsc2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance);
static void c2_encStr2Arr(SFc2_testKinectBeatSmileInstanceStruct *chartInstance,
  char_T c2_mystr[181], real_T c2_myarr256[256]);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static void c2_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_y[181]);
static void c2_b_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[181]);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_arrBML, const char_T *c2_identifier, real_T
  c2_y[256]);
static void c2_d_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[181]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_g_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_h_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_testKinectBeatSmile, const
  char_T *c2_identifier);
static uint8_T c2_i_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_testKinectBeatSmile = 0U;
}

static void initialize_params_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_testKinectBeatSmile(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[256];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_arrBML)[256];
  c2_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  for (c2_i0 = 0; c2_i0 < 256; c2_i0++) {
    c2_u[c2_i0] = (*c2_arrBML)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_testKinectBeatSmile;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[256];
  int32_T c2_i1;
  real_T (*c2_arrBML)[256];
  c2_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "arrBML", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 256; c2_i1++) {
    (*c2_arrBML)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_testKinectBeatSmile = c2_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_testKinectBeatSmile");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_testKinectBeatSmile(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_handUp;
  uint32_T c2_debug_family_var_map[5];
  char_T c2_mystr[181];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_arrBML[256];
  int32_T c2_i2;
  int32_T c2_i3;
  static char_T c2_cv0[207] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 't', 'y', 'p', 'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"',
    ' ', 's', 'i', 'd', 'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"',
    ' ', 'a', 'u', '=', '\\', '\"', '6', '\\', '\"', ' ', ' ', 's', 't', 'a',
    'r', 't', '=', '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\',
    '\"', '2', '\\', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\', '\"',
    '1', '\\', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=', '\\',
    '\"', '1', '2', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\\',
    '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '2', '\\', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '1', '\\', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c2_u[207];
  const mxArray *c2_y = NULL;
  char_T c2_cv1[181];
  int32_T c2_i4;
  int32_T c2_i5;
  char_T c2_b_mystr[181];
  real_T c2_dv1[256];
  int32_T c2_i6;
  uint32_T c2_b_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr;
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_c_mystr;
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T *c2_b_handUp;
  real_T (*c2_b_arrBML)[256];
  c2_b_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_handUp;
  c2_handUp = c2_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_mystr, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_handUp, 3U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_arrBML, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c2_handUp == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
    for (c2_i2 = 0; c2_i2 < 181; c2_i2++) {
      c2_mystr[c2_i2] = ' ';
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
    for (c2_i3 = 0; c2_i3 < 207; c2_i3++) {
      c2_u[c2_i3] = c2_cv0[c2_i3];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 207),
                  false);
    c2_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14,
                         c2_y), "sprintf", c2_cv1);
    for (c2_i4 = 0; c2_i4 < 181; c2_i4++) {
      c2_mystr[c2_i4] = c2_cv1[c2_i4];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
    for (c2_i5 = 0; c2_i5 < 181; c2_i5++) {
      c2_b_mystr[c2_i5] = c2_mystr[c2_i5];
    }

    c2_encStr2Arr(chartInstance, c2_b_mystr, c2_dv1);
    for (c2_i6 = 0; c2_i6 < 256; c2_i6++) {
      c2_arrBML[c2_i6] = c2_dv1[c2_i6];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_c_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c2_arr, 1U, c2_b_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c2_c_mystr, 5U, c2_e_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 6U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 7U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_arrBML, 8U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    c2_c_mystr = ' ';
    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
    c2_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
    c2_arr = 32.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
    c2_ss = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
    c2_padsize = c2_maxarrsize - c2_ss;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
    for (c2_i7 = 0; c2_i7 < 256; c2_i7++) {
      c2_tt[c2_i7] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
    c2_tt[0] = c2_arr;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
    for (c2_i8 = 0; c2_i8 < 256; c2_i8++) {
      c2_arrBML[c2_i8] = c2_tt[c2_i8];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i9 = 0; c2_i9 < 256; c2_i9++) {
    (*c2_b_arrBML)[c2_i9] = c2_arrBML[c2_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectBeatSmileMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i10 = 0; c2_i10 < 256; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arrBML)[c2_i10], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_handUp, 1U);
}

static void initSimStructsc2_testKinectBeatSmile
  (SFc2_testKinectBeatSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_encStr2Arr(SFc2_testKinectBeatSmileInstanceStruct *chartInstance,
  char_T c2_mystr[181], real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[181];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_arr, 1U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_mystr, 7U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i11 = 0; c2_i11 < 181; c2_i11++) {
    c2_arr[c2_i11] = (real_T)c2_mystr[c2_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 181.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i12 = 0; c2_i12 < 256; c2_i12++) {
    c2_tt[c2_i12] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i13 = 0; c2_i13 < 181; c2_i13++) {
    c2_tt[c2_i13] = c2_arr[c2_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i14 = 0; c2_i14 < 256; c2_i14++) {
    c2_myarr256[c2_i14] = c2_tt[c2_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\17-10-2015-Matlab-Demo\\encStr2Arr.m"));
}

static void c2_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_y[181])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_b_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[181])
{
  char_T c2_cv2[181];
  int32_T c2_i15;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv2, 1, 10, 0U, 1, 0U, 2, 1,
                181);
  for (c2_i15 = 0; c2_i15 < 181; c2_i15++) {
    c2_y[c2_i15] = c2_cv2[c2_i15];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i16;
  real_T c2_b_inData[256];
  int32_T c2_i17;
  real_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i16 = 0; c2_i16 < 256; c2_i16++) {
    c2_b_inData[c2_i16] = (*(real_T (*)[256])c2_inData)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 256; c2_i17++) {
    c2_u[c2_i17] = c2_b_inData[c2_i17];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_arrBML, const char_T *c2_identifier, real_T
  c2_y[256])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arrBML), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_arrBML);
}

static void c2_d_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv2[256];
  int32_T c2_i18;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 256);
  for (c2_i18 = 0; c2_i18 < 256; c2_i18++) {
    c2_y[c2_i18] = c2_dv2[c2_i18];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_arrBML;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i19;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_arrBML = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arrBML), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_arrBML);
  for (c2_i19 = 0; c2_i19 < 256; c2_i19++) {
    (*(real_T (*)[256])c2_outData)[c2_i19] = c2_y[c2_i19];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i20;
  char_T c2_b_inData[181];
  int32_T c2_i21;
  char_T c2_u[181];
  const mxArray *c2_y = NULL;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i20 = 0; c2_i20 < 181; c2_i20++) {
    c2_b_inData[c2_i20] = (*(char_T (*)[181])c2_inData)[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 181; c2_i21++) {
    c2_u[c2_i21] = c2_b_inData[c2_i21];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 181),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sprintf;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  char_T c2_y[181];
  int32_T c2_i22;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_sprintf = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
  for (c2_i22 = 0; c2_i22 < 181; c2_i22++) {
    (*(char_T (*)[181])c2_outData)[c2_i22] = c2_y[c2_i22];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i23;
  real_T c2_b_inData[181];
  int32_T c2_i24;
  real_T c2_u[181];
  const mxArray *c2_y = NULL;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i23 = 0; c2_i23 < 181; c2_i23++) {
    c2_b_inData[c2_i23] = (*(real_T (*)[181])c2_inData)[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 181; c2_i24++) {
    c2_u[c2_i24] = c2_b_inData[c2_i24];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 181), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[181])
{
  real_T c2_dv3[181];
  int32_T c2_i25;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 181);
  for (c2_i25 = 0; c2_i25 < 181; c2_i25++) {
    c2_y[c2_i25] = c2_dv3[c2_i25];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_arr;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[181];
  int32_T c2_i26;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_arr = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arr), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_arr);
  for (c2_i26 = 0; c2_i26 < 181; c2_i26++) {
    (*(real_T (*)[181])c2_outData)[c2_i26] = c2_y[c2_i26];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  char_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(char_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_testKinectBeatSmile_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("blanks"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/17-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1445215678U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_g_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i27;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i27, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i27;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_testKinectBeatSmile, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_testKinectBeatSmile), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_testKinectBeatSmile);
  return c2_y;
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_testKinectBeatSmileInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_testKinectBeatSmileInstanceStruct
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

void sf_c2_testKinectBeatSmile_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1148549601U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2313011862U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2876484834U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2422395843U);
}

mxArray *sf_c2_testKinectBeatSmile_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("63I6j8HJuCi20UBDc1plFF");
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

mxArray *sf_c2_testKinectBeatSmile_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_testKinectBeatSmile_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_testKinectBeatSmile(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"arrBML\",},{M[8],M[0],T\"is_active_c2_testKinectBeatSmile\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_testKinectBeatSmile_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectBeatSmileMachineNumber_,
           2,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testKinectBeatSmileMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectBeatSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectBeatSmileMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"arrBML");
          _SFD_SET_DATA_PROPS(1,1,1,0,"handUp");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,693);
        _SFD_CV_INIT_EML_IF(0,1,0,59,72,510,692);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_handUp;
          real_T (*c2_arrBML)[256];
          c2_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_arrBML);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_handUp);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectBeatSmileMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "hFsxRBFQDJG3Sl3NqjJbWE";
}

static void sf_opaque_initialize_c2_testKinectBeatSmile(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_testKinectBeatSmile
    ((SFc2_testKinectBeatSmileInstanceStruct*) chartInstanceVar);
  initialize_c2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_testKinectBeatSmile(void *chartInstanceVar)
{
  enable_c2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_testKinectBeatSmile(void *chartInstanceVar)
{
  disable_c2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_testKinectBeatSmile(void *chartInstanceVar)
{
  sf_gateway_c2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_testKinectBeatSmile(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_testKinectBeatSmile
    ((SFc2_testKinectBeatSmileInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_testKinectBeatSmile();/* state var info */
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

extern void sf_internal_set_sim_state_c2_testKinectBeatSmile(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_testKinectBeatSmile();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_testKinectBeatSmile(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_testKinectBeatSmile(S);
}

static void sf_opaque_set_sim_state_c2_testKinectBeatSmile(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_testKinectBeatSmile(S, st);
}

static void sf_opaque_terminate_c2_testKinectBeatSmile(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_testKinectBeatSmileInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectBeatSmile_optimization_info();
    }

    finalize_c2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
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
  initSimStructsc2_testKinectBeatSmile((SFc2_testKinectBeatSmileInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_testKinectBeatSmile(SimStruct *S)
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
    initialize_params_c2_testKinectBeatSmile
      ((SFc2_testKinectBeatSmileInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_testKinectBeatSmile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectBeatSmile_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1748592071U));
  ssSetChecksum1(S,(337222760U));
  ssSetChecksum2(S,(2604590875U));
  ssSetChecksum3(S,(713934548U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_testKinectBeatSmile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_testKinectBeatSmile(SimStruct *S)
{
  SFc2_testKinectBeatSmileInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_testKinectBeatSmileInstanceStruct *)utMalloc(sizeof
    (SFc2_testKinectBeatSmileInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_testKinectBeatSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_testKinectBeatSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_testKinectBeatSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_testKinectBeatSmile;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_testKinectBeatSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_testKinectBeatSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_testKinectBeatSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_testKinectBeatSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_testKinectBeatSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_testKinectBeatSmile;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_testKinectBeatSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_testKinectBeatSmile;
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

void c2_testKinectBeatSmile_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_testKinectBeatSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_testKinectBeatSmile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_testKinectBeatSmile(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_testKinectBeatSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
