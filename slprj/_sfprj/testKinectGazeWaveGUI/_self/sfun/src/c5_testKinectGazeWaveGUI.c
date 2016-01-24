/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectGazeWaveGUI_sfun.h"
#include "c5_testKinectGazeWaveGUI.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectGazeWaveGUI_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[6] = { "mystr", "nargin", "nargout",
  "handUp", "extraversionW", "arrBML" };

static const char * c5_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c5_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void initialize_params_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void enable_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void disable_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void set_sim_state_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void sf_gateway_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void initSimStructsc5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c5_encStr2Arr(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, char_T c5_mystr[183], real_T c5_myarr256[256]);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static void c5_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_sprintf, const char_T *c5_identifier, char_T
  c5_y[183]);
static void c5_b_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  char_T c5_y[183]);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_c_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_arrBML, const char_T *c5_identifier, real_T
  c5_y[256]);
static void c5_d_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_e_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[183]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_g_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_h_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_testKinectGazeWaveGUI, const
  char_T *c5_identifier);
static uint8_T c5_i_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_testKinectGazeWaveGUI = 0U;
}

static void initialize_params_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[256];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_arrBML)[256];
  c5_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  for (c5_i0 = 0; c5_i0 < 256; c5_i0++) {
    c5_u[c5_i0] = (*c5_arrBML)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_testKinectGazeWaveGUI;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[256];
  int32_T c5_i1;
  real_T (*c5_arrBML)[256];
  c5_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                        "arrBML", c5_dv0);
  for (c5_i1 = 0; c5_i1 < 256; c5_i1++) {
    (*c5_arrBML)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_testKinectGazeWaveGUI = c5_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_testKinectGazeWaveGUI");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_testKinectGazeWaveGUI(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_handUp;
  real_T c5_extraversionW;
  uint32_T c5_debug_family_var_map[6];
  char_T c5_mystr[183];
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  real_T c5_arrBML[256];
  int32_T c5_i2;
  int32_T c5_i3;
  static char_T c5_cv0[209] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 't', 'y', 'p', 'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"',
    ' ', 's', 'i', 'd', 'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"',
    ' ', 'a', 'u', '=', '\\', '\"', '6', '\\', '\"', ' ', ' ', 's', 't', 'a',
    'r', 't', '=', '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\',
    '\"', '2', '0', '\\', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\',
    '\"', '1', '\\', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '1', '2', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '2', '0',
    '\\', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '1', '\\',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c5_u[209];
  const mxArray *c5_y = NULL;
  char_T c5_cv1[183];
  int32_T c5_i4;
  int32_T c5_i5;
  char_T c5_b_mystr[183];
  real_T c5_dv1[256];
  int32_T c5_i6;
  uint32_T c5_b_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr;
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_c_mystr;
  real_T c5_b_nargin = 1.0;
  real_T c5_b_nargout = 1.0;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  real_T *c5_b_handUp;
  real_T *c5_b_extraversionW;
  real_T (*c5_b_arrBML)[256];
  c5_b_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_handUp;
  c5_b_hoistedGlobal = *c5_b_extraversionW;
  c5_handUp = c5_hoistedGlobal;
  c5_extraversionW = c5_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_mystr, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_handUp, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_extraversionW, 4U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_arrBML, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c5_extraversionW > 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
    for (c5_i2 = 0; c5_i2 < 183; c5_i2++) {
      c5_mystr[c5_i2] = ' ';
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
    for (c5_i3 = 0; c5_i3 < 209; c5_i3++) {
      c5_u[c5_i3] = c5_cv0[c5_i3];
    }

    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 209),
                  false);
    c5_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14,
                         c5_y), "sprintf", c5_cv1);
    for (c5_i4 = 0; c5_i4 < 183; c5_i4++) {
      c5_mystr[c5_i4] = c5_cv1[c5_i4];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
    for (c5_i5 = 0; c5_i5 < 183; c5_i5++) {
      c5_b_mystr[c5_i5] = c5_mystr[c5_i5];
    }

    c5_encStr2Arr(chartInstance, c5_b_mystr, c5_dv1);
    for (c5_i6 = 0; c5_i6 < 256; c5_i6++) {
      c5_arrBML[c5_i6] = c5_dv1[c5_i6];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_c_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c5_arr, 1U, c5_b_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c5_c_mystr, 5U, c5_e_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 6U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 7U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_arrBML, 8U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    c5_c_mystr = ' ';
    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
    c5_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
    c5_arr = 32.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
    c5_ss = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
    c5_padsize = c5_maxarrsize - c5_ss;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
    for (c5_i7 = 0; c5_i7 < 256; c5_i7++) {
      c5_tt[c5_i7] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
    c5_tt[0] = c5_arr;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
    for (c5_i8 = 0; c5_i8 < 256; c5_i8++) {
      c5_arrBML[c5_i8] = c5_tt[c5_i8];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i9 = 0; c5_i9 < 256; c5_i9++) {
    (*c5_b_arrBML)[c5_i9] = c5_arrBML[c5_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectGazeWaveGUIMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i10 = 0; c5_i10 < 256; c5_i10++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_arrBML)[c5_i10], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_handUp, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_extraversionW, 2U);
}

static void initSimStructsc5_testKinectGazeWaveGUI
  (SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_encStr2Arr(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, char_T c5_mystr[183], real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[183];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_arr, 1U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_mystr, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i11 = 0; c5_i11 < 183; c5_i11++) {
    c5_arr[c5_i11] = (real_T)c5_mystr[c5_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 183.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i12 = 0; c5_i12 < 256; c5_i12++) {
    c5_tt[c5_i12] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i13 = 0; c5_i13 < 183; c5_i13++) {
    c5_tt[c5_i13] = c5_arr[c5_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i14 = 0; c5_i14 < 256; c5_i14++) {
    c5_myarr256[c5_i14] = c5_tt[c5_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static void c5_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_sprintf, const char_T *c5_identifier, char_T
  c5_y[183])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sprintf), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_sprintf);
}

static void c5_b_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  char_T c5_y[183])
{
  char_T c5_cv2[183];
  int32_T c5_i15;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_cv2, 1, 10, 0U, 1, 0U, 2, 1,
                183);
  for (c5_i15 = 0; c5_i15 < 183; c5_i15++) {
    c5_y[c5_i15] = c5_cv2[c5_i15];
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i16;
  real_T c5_b_inData[256];
  int32_T c5_i17;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i16 = 0; c5_i16 < 256; c5_i16++) {
    c5_b_inData[c5_i16] = (*(real_T (*)[256])c5_inData)[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 256; c5_i17++) {
    c5_u[c5_i17] = c5_b_inData[c5_i17];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_arrBML, const char_T *c5_identifier, real_T
  c5_y[256])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_arrBML), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_arrBML);
}

static void c5_d_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256])
{
  real_T c5_dv2[256];
  int32_T c5_i18;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 1, 256);
  for (c5_i18 = 0; c5_i18 < 256; c5_i18++) {
    c5_y[c5_i18] = c5_dv2[c5_i18];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_arrBML;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[256];
  int32_T c5_i19;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_arrBML = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_arrBML), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_arrBML);
  for (c5_i19 = 0; c5_i19 < 256; c5_i19++) {
    (*(real_T (*)[256])c5_outData)[c5_i19] = c5_y[c5_i19];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_e_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
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

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i20;
  char_T c5_b_inData[183];
  int32_T c5_i21;
  char_T c5_u[183];
  const mxArray *c5_y = NULL;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i20 = 0; c5_i20 < 183; c5_i20++) {
    c5_b_inData[c5_i20] = (*(char_T (*)[183])c5_inData)[c5_i20];
  }

  for (c5_i21 = 0; c5_i21 < 183; c5_i21++) {
    c5_u[c5_i21] = c5_b_inData[c5_i21];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 183),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_sprintf;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  char_T c5_y[183];
  int32_T c5_i22;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_sprintf = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sprintf), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_sprintf);
  for (c5_i22 = 0; c5_i22 < 183; c5_i22++) {
    (*(char_T (*)[183])c5_outData)[c5_i22] = c5_y[c5_i22];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i23;
  real_T c5_b_inData[183];
  int32_T c5_i24;
  real_T c5_u[183];
  const mxArray *c5_y = NULL;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i23 = 0; c5_i23 < 183; c5_i23++) {
    c5_b_inData[c5_i23] = (*(real_T (*)[183])c5_inData)[c5_i23];
  }

  for (c5_i24 = 0; c5_i24 < 183; c5_i24++) {
    c5_u[c5_i24] = c5_b_inData[c5_i24];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 183), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_f_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[183])
{
  real_T c5_dv3[183];
  int32_T c5_i25;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv3, 1, 0, 0U, 1, 0U, 1, 183);
  for (c5_i25 = 0; c5_i25 < 183; c5_i25++) {
    c5_y[c5_i25] = c5_dv3[c5_i25];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_arr;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[183];
  int32_T c5_i26;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_arr = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_arr), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_arr);
  for (c5_i26 = 0; c5_i26 < 183; c5_i26++) {
    (*(real_T (*)[183])c5_outData)[c5_i26] = c5_y[c5_i26];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  char_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(char_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_testKinectGazeWaveGUI_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("blanks"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_g_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i27;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i27, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i27;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_testKinectGazeWaveGUI, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_testKinectGazeWaveGUI), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_testKinectGazeWaveGUI);
  return c5_y;
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_testKinectGazeWaveGUIInstanceStruct
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

static void init_dsm_address_info(SFc5_testKinectGazeWaveGUIInstanceStruct
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

void sf_c5_testKinectGazeWaveGUI_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1177503836U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4794084U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3845836687U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3494249738U);
}

mxArray *sf_c5_testKinectGazeWaveGUI_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fGiR7cyOQBMaZbaOUlJVXF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

mxArray *sf_c5_testKinectGazeWaveGUI_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_testKinectGazeWaveGUI_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_testKinectGazeWaveGUI(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"arrBML\",},{M[8],M[0],T\"is_active_c5_testKinectGazeWaveGUI\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_testKinectGazeWaveGUI_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectGazeWaveGUIMachineNumber_,
           5,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testKinectGazeWaveGUIMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectGazeWaveGUIMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectGazeWaveGUIMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"arrBML");
          _SFD_SET_DATA_PROPS(1,1,1,0,"handUp");
          _SFD_SET_DATA_PROPS(2,1,1,0,"extraversionW");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,469);
        _SFD_CV_INIT_EML_IF(0,1,0,74,93,426,468);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_handUp;
          real_T *c5_extraversionW;
          real_T (*c5_arrBML)[256];
          c5_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_arrBML);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_handUp);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_extraversionW);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectGazeWaveGUIMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "IAJxlTGOKlcndq8fgl7cJ";
}

static void sf_opaque_initialize_c5_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_testKinectGazeWaveGUI
    ((SFc5_testKinectGazeWaveGUIInstanceStruct*) chartInstanceVar);
  initialize_c5_testKinectGazeWaveGUI((SFc5_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  enable_c5_testKinectGazeWaveGUI((SFc5_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  disable_c5_testKinectGazeWaveGUI((SFc5_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  sf_gateway_c5_testKinectGazeWaveGUI((SFc5_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_testKinectGazeWaveGUI
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_testKinectGazeWaveGUI
    ((SFc5_testKinectGazeWaveGUIInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_testKinectGazeWaveGUI();/* state var info */
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

extern void sf_internal_set_sim_state_c5_testKinectGazeWaveGUI(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_testKinectGazeWaveGUI();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_testKinectGazeWaveGUI
    ((SFc5_testKinectGazeWaveGUIInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_testKinectGazeWaveGUI(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c5_testKinectGazeWaveGUI(S);
}

static void sf_opaque_set_sim_state_c5_testKinectGazeWaveGUI(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_testKinectGazeWaveGUI(S, st);
}

static void sf_opaque_terminate_c5_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_testKinectGazeWaveGUIInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectGazeWaveGUI_optimization_info();
    }

    finalize_c5_testKinectGazeWaveGUI((SFc5_testKinectGazeWaveGUIInstanceStruct*)
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
  initSimStructsc5_testKinectGazeWaveGUI
    ((SFc5_testKinectGazeWaveGUIInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_testKinectGazeWaveGUI(SimStruct *S)
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
    initialize_params_c5_testKinectGazeWaveGUI
      ((SFc5_testKinectGazeWaveGUIInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_testKinectGazeWaveGUI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectGazeWaveGUI_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
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
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3592098655U));
  ssSetChecksum1(S,(744073647U));
  ssSetChecksum2(S,(1325672081U));
  ssSetChecksum3(S,(1598403233U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_testKinectGazeWaveGUI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_testKinectGazeWaveGUI(SimStruct *S)
{
  SFc5_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_testKinectGazeWaveGUIInstanceStruct *)utMalloc(sizeof
    (SFc5_testKinectGazeWaveGUIInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_testKinectGazeWaveGUIInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_testKinectGazeWaveGUI;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_testKinectGazeWaveGUI;
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

void c5_testKinectGazeWaveGUI_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_testKinectGazeWaveGUI(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_testKinectGazeWaveGUI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_testKinectGazeWaveGUI(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_testKinectGazeWaveGUI_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
