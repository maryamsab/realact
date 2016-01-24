/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testAtomicGaze_sfun.h"
#include "c3_testAtomicGaze.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testAtomicGaze_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[7] = { "c", "mystr", "nargin",
  "nargout", "x", "y", "arrBML" };

static const char * c3_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c3_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

/* Function Declarations */
static void initialize_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void initialize_params_c3_testAtomicGaze
  (SFc3_testAtomicGazeInstanceStruct *chartInstance);
static void enable_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void disable_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_testAtomicGaze
  (SFc3_testAtomicGazeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_testAtomicGaze
  (SFc3_testAtomicGazeInstanceStruct *chartInstance);
static void set_sim_state_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void sf_gateway_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void initSimStructsc3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static void c3_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct *chartInstance,
  const mxArray *c3_sprintf, const char_T *c3_identifier, char_T c3_y_data[],
  int32_T c3_y_sizes[2]);
static void c3_b_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2]);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_arrBML, const char_T *c3_identifier, real_T
  c3_y[256]);
static void c3_d_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c3_inData_data[], int32_T c3_inData_sizes[2]);
static void c3_f_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, char_T c3_outData_data[], int32_T
  c3_outData_sizes[2]);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T *c3_inData_sizes);
static void c3_g_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T *c3_y_sizes);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  *c3_outData_sizes);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_h_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_i_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_testAtomicGaze, const char_T *
  c3_identifier);
static uint8_T c3_j_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_testAtomicGazeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_testAtomicGaze = 0U;
}

static void initialize_params_c3_testAtomicGaze
  (SFc3_testAtomicGazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_testAtomicGaze
  (SFc3_testAtomicGazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_testAtomicGaze
  (SFc3_testAtomicGazeInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[256];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_arrBML)[256];
  c3_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(2, 1), false);
  for (c3_i0 = 0; c3_i0 < 256; c3_i0++) {
    c3_u[c3_i0] = (*c3_arrBML)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_testAtomicGaze;
  c3_b_u = c3_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[256];
  int32_T c3_i1;
  real_T (*c3_arrBML)[256];
  c3_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "arrBML", c3_dv0);
  for (c3_i1 = 0; c3_i1 < 256; c3_i1++) {
    (*c3_arrBML)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_is_active_c3_testAtomicGaze = c3_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_testAtomicGaze");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_testAtomicGaze(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  int32_T c3_i2;
  real_T *c3_x;
  real_T *c3_y;
  real_T (*c3_arrBML)[256];
  c3_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_y, 1U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_testAtomicGaze(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testAtomicGazeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_i2 = 0; c3_i2 < 256; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_arrBML)[c3_i2], 2U);
  }
}

static void c3_chartstep_c3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_x;
  real_T c3_y;
  uint32_T c3_debug_family_var_map[7];
  real_T c3_c;
  int32_T c3_mystr_sizes[2];
  char_T c3_mystr_data[70];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_arrBML[256];
  real_T c3_A;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  uint32_T c3_b_debug_family_var_map[4];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_n;
  real_T c3_dv1[2];
  int32_T c3_iv0[2];
  int32_T c3_mystr;
  int32_T c3_b_mystr;
  int32_T c3_loop_ub;
  int32_T c3_i3;
  int32_T c3_i4;
  static char_T c3_cv0[64] = { 's', 'c', 'e', 'n', 'e', '.', 'g', 'e', 't', 'P',
    'a', 'w', 'n', '(', '\\', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\\', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 'i', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'V', 'e', 'c', '(', '%', '0', '.', '1', 'f', ' ', ',',
    ' ', '%', 'd', ' ', ',', '%', 'd', ')', ')' };

  char_T c3_u[64];
  const mxArray *c3_b_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[70];
  int32_T c3_c_mystr;
  int32_T c3_d_mystr;
  int32_T c3_b_loop_ub;
  int32_T c3_i5;
  int32_T c3_b_mystr_sizes[2];
  int32_T c3_e_mystr;
  int32_T c3_f_mystr;
  int32_T c3_c_loop_ub;
  int32_T c3_i6;
  char_T c3_b_mystr_data[70];
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_maxarrsize;
  int32_T c3_arr_sizes;
  real_T c3_arr_data[70];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  int32_T c3_d_loop_ub;
  int32_T c3_i7;
  int32_T c3_i8;
  boolean_T c3_b0;
  boolean_T c3_b1;
  boolean_T c3_b2;
  int32_T c3_i9;
  int32_T c3_b_tmp_sizes;
  int32_T c3_e_loop_ub;
  int32_T c3_i10;
  int32_T c3_b_tmp_data[70];
  int32_T c3_iv1[1];
  int32_T c3_f_loop_ub;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  real_T *c3_h_x;
  real_T *c3_f_y;
  real_T (*c3_b_arrBML)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c3_b_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_f_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_h_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_h_x;
  c3_b_hoistedGlobal = *c3_f_y;
  c3_x = c3_hoistedGlobal;
  c3_y = c3_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_mystr_data, (const int32_T *)
    &c3_mystr_sizes, NULL, 0, 1, (void *)c3_c_sf_marshallOut, (void *)
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_x, 4U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_y, 5U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_A = c3_x - 170.0;
  c3_b_x = c3_A;
  c3_c_x = c3_b_x;
  c3_d_x = c3_c_x;
  c3_x = c3_d_x / 300.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_e_x = c3_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_b_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_x, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 2);
  c3_c = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  if (CV_SCRIPT_IF(0, 0, c3_e_x < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
    c3_c = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 5);
    c3_f_x = c3_e_x;
    c3_g_x = c3_f_x;
    c3_e_x = muDoubleScalarAbs(c3_g_x);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  guard1 = false;
  if (CV_SCRIPT_COND(0, 0, c3_e_x > 0.0)) {
    if (CV_SCRIPT_COND(0, 1, c3_e_x < 9.0)) {
      CV_SCRIPT_MCDC(0, 0, true);
      CV_SCRIPT_IF(0, 1, true);
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
      c3_c++;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(0, 0, false);
    CV_SCRIPT_IF(0, 1, false);
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
    guard2 = false;
    if (CV_SCRIPT_COND(0, 2, c3_e_x > 10.0)) {
      if (CV_SCRIPT_COND(0, 3, c3_e_x < 99.0)) {
        CV_SCRIPT_MCDC(0, 1, true);
        CV_SCRIPT_IF(0, 2, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
        c3_c += 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_SCRIPT_MCDC(0, 1, false);
      CV_SCRIPT_IF(0, 2, false);
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
      guard3 = false;
      if (CV_SCRIPT_COND(0, 4, c3_e_x > 100.0)) {
        if (CV_SCRIPT_COND(0, 5, c3_e_x < 999.0)) {
          CV_SCRIPT_MCDC(0, 2, true);
          CV_SCRIPT_IF(0, 3, true);
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 12);
          c3_c += 3.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_SCRIPT_MCDC(0, 2, false);
        CV_SCRIPT_IF(0, 3, false);
      }
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_n = 66.0 + c3_c;
  c3_dv1[0] = 1.0;
  c3_dv1[1] = c3_n;
  c3_mystr_sizes[0] = 1;
  c3_iv0[0] = 1;
  c3_iv0[1] = (int32_T)c3_dv1[1];
  c3_mystr_sizes[1] = c3_iv0[1];
  c3_mystr = c3_mystr_sizes[0];
  c3_b_mystr = c3_mystr_sizes[1];
  c3_loop_ub = (int32_T)c3_dv1[1] - 1;
  for (c3_i3 = 0; c3_i3 <= c3_loop_ub; c3_i3++) {
    c3_mystr_data[c3_i3] = ' ';
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i4 = 0; c3_i4 < 64; c3_i4++) {
    c3_u[c3_i4] = c3_cv0[c3_i4];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 64),
                false);
  c3_b_u = c3_x;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  c3_c_u = 1.7;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  c3_d_u = 2.0;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  c3_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 4U, 14,
                       c3_b_y, 14, c3_c_y, 14, c3_d_y, 14, c3_e_y), "sprintf",
                      c3_tmp_data, c3_tmp_sizes);
  c3_mystr_sizes[0] = 1;
  c3_mystr_sizes[1] = c3_tmp_sizes[1];
  c3_c_mystr = c3_mystr_sizes[0];
  c3_d_mystr = c3_mystr_sizes[1];
  c3_b_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i5 = 0; c3_i5 <= c3_b_loop_ub; c3_i5++) {
    c3_mystr_data[c3_i5] = c3_tmp_data[c3_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_b_mystr_sizes[0] = 1;
  c3_b_mystr_sizes[1] = c3_mystr_sizes[1];
  c3_e_mystr = c3_b_mystr_sizes[0];
  c3_f_mystr = c3_b_mystr_sizes[1];
  c3_c_loop_ub = c3_mystr_sizes[0] * c3_mystr_sizes[1] - 1;
  for (c3_i6 = 0; c3_i6 <= c3_c_loop_ub; c3_i6++) {
    c3_b_mystr_data[c3_i6] = c3_mystr_data[c3_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_c_debug_family_names,
    c3_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_arr_data, (const int32_T *)
    &c3_arr_sizes, NULL, 0, 1, (void *)c3_d_sf_marshallOut, (void *)
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ss, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_b_mystr_data, (const int32_T *)
    &c3_b_mystr_sizes, NULL, 1, 7, (void *)c3_c_sf_marshallOut, (void *)
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arrBML, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 6);
  c3_arr_sizes = c3_b_mystr_sizes[1];
  c3_d_loop_ub = c3_b_mystr_sizes[1] - 1;
  for (c3_i7 = 0; c3_i7 <= c3_d_loop_ub; c3_i7++) {
    c3_arr_data[c3_i7] = (real_T)c3_b_mystr_data[c3_b_mystr_sizes[0] * c3_i7];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 7);
  c3_ss = (real_T)c3_arr_sizes;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 256.0 - c3_ss;
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 9);
  for (c3_i8 = 0; c3_i8 < 256; c3_i8++) {
    c3_tt[c3_i8] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 10);
  c3_b0 = (1.0 > c3_ss);
  c3_b1 = c3_b0;
  c3_b2 = c3_b1;
  if (c3_b2) {
    c3_i9 = 0;
  } else {
    c3_i9 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c3_ss, 1, 256, 0, 0);
  }

  c3_b_tmp_sizes = c3_i9;
  c3_e_loop_ub = c3_i9 - 1;
  for (c3_i10 = 0; c3_i10 <= c3_e_loop_ub; c3_i10++) {
    c3_b_tmp_data[c3_i10] = c3_i10;
  }

  c3_iv1[0] = c3_b_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c3_iv1, 1, *(int32_T (*)[1])&c3_arr_sizes, 1);
  c3_f_loop_ub = c3_arr_sizes - 1;
  for (c3_i11 = 0; c3_i11 <= c3_f_loop_ub; c3_i11++) {
    c3_tt[c3_b_tmp_data[c3_i11]] = c3_arr_data[c3_i11];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 11);
  for (c3_i12 = 0; c3_i12 < 256; c3_i12++) {
    c3_arrBML[c3_i12] = c3_tt[c3_i12];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i13 = 0; c3_i13 < 256; c3_i13++) {
    (*c3_b_arrBML)[c3_i13] = c3_arrBML[c3_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_testAtomicGaze(SFc3_testAtomicGazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\countDigits.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static void c3_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct *chartInstance,
  const mxArray *c3_sprintf, const char_T *c3_identifier, char_T c3_y_data[],
  int32_T c3_y_sizes[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_b_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i14;
  uint32_T c3_uv0[2];
  int32_T c3_i15;
  static boolean_T c3_bv0[2] = { false, true };

  boolean_T c3_bv1[2];
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[70];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i16;
  (void)chartInstance;
  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    c3_uv0[c3_i14] = 1U + 69U * (uint32_T)c3_i14;
  }

  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    c3_bv1[c3_i15] = c3_bv0[c3_i15];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c3_bv1, c3_uv0, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i16 = 0; c3_i16 <= c3_loop_ub; c3_i16++) {
    c3_y_data[c3_i16] = c3_tmp_data[c3_i16];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i17;
  real_T c3_b_inData[256];
  int32_T c3_i18;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i17 = 0; c3_i17 < 256; c3_i17++) {
    c3_b_inData[c3_i17] = (*(real_T (*)[256])c3_inData)[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 256; c3_i18++) {
    c3_u[c3_i18] = c3_b_inData[c3_i18];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_arrBML, const char_T *c3_identifier, real_T
  c3_y[256])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arrBML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arrBML);
}

static void c3_d_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv2[256];
  int32_T c3_i19;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i19 = 0; c3_i19 < 256; c3_i19++) {
    c3_y[c3_i19] = c3_dv2[c3_i19];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arrBML;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i20;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_arrBML = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arrBML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arrBML);
  for (c3_i20 = 0; c3_i20 < 256; c3_i20++) {
    (*(real_T (*)[256])c3_outData)[c3_i20] = c3_y[c3_i20];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c3_inData_data[], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i21;
  char_T c3_b_inData_data[70];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i22;
  char_T c3_u_data[70];
  const mxArray *c3_y = NULL;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 1;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i21 = 0; c3_i21 <= c3_loop_ub; c3_i21++) {
    c3_b_inData_data[c3_b_inData_sizes[0] * c3_i21] =
      c3_inData_data[c3_inData_sizes[0] * c3_i21];
  }

  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i22 = 0; c3_i22 <= c3_b_loop_ub; c3_i22++) {
    c3_u_data[c3_u_sizes[0] * c3_i22] = c3_b_inData_data[c3_b_inData_sizes[0] *
      c3_i22];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 10, 0U, 1U, 0U, 2,
    c3_u_sizes[0], c3_u_sizes[1]), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_f_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i23;
  uint32_T c3_uv1[2];
  int32_T c3_i24;
  static boolean_T c3_bv2[2] = { false, true };

  boolean_T c3_bv3[2];
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[70];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i25;
  (void)chartInstance;
  for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
    c3_uv1[c3_i23] = 1U + 69U * (uint32_T)c3_i23;
  }

  for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
    c3_bv3[c3_i24] = c3_bv2[c3_i24];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c3_bv3, c3_uv1, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i25 = 0; c3_i25 <= c3_loop_ub; c3_i25++) {
    c3_y_data[c3_i25] = c3_tmp_data[c3_i25];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, char_T c3_outData_data[], int32_T
  c3_outData_sizes[2])
{
  const mxArray *c3_mystr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  char_T c3_y_data[70];
  int32_T c3_loop_ub;
  int32_T c3_i26;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_mystr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mystr), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_mystr);
  c3_outData_sizes[0] = 1;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i26 = 0; c3_i26 <= c3_loop_ub; c3_i26++) {
    c3_outData_data[c3_outData_sizes[0] * c3_i26] = c3_y_data[c3_y_sizes[0] *
      c3_i26];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T *c3_inData_sizes)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes;
  int32_T c3_loop_ub;
  int32_T c3_i27;
  real_T c3_b_inData_data[70];
  int32_T c3_u_sizes;
  int32_T c3_b_loop_ub;
  int32_T c3_i28;
  real_T c3_u_data[70];
  const mxArray *c3_y = NULL;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes = *c3_inData_sizes;
  c3_loop_ub = *c3_inData_sizes - 1;
  for (c3_i27 = 0; c3_i27 <= c3_loop_ub; c3_i27++) {
    c3_b_inData_data[c3_i27] = c3_inData_data[c3_i27];
  }

  c3_u_sizes = c3_b_inData_sizes;
  c3_b_loop_ub = c3_b_inData_sizes - 1;
  for (c3_i28 = 0; c3_i28 <= c3_b_loop_ub; c3_i28++) {
    c3_u_data[c3_i28] = c3_b_inData_data[c3_i28];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 1,
    c3_u_sizes), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T *c3_y_sizes)
{
  static uint32_T c3_uv2[1] = { 70U };

  uint32_T c3_uv3[1];
  static boolean_T c3_bv4[1] = { true };

  boolean_T c3_bv5[1];
  int32_T c3_tmp_sizes;
  real_T c3_tmp_data[70];
  int32_T c3_loop_ub;
  int32_T c3_i29;
  (void)chartInstance;
  c3_uv3[0] = c3_uv2[0];
  c3_bv5[0] = c3_bv4[0];
  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c3_bv5, c3_uv3, &c3_tmp_sizes);
  *c3_y_sizes = c3_tmp_sizes;
  c3_loop_ub = c3_tmp_sizes - 1;
  for (c3_i29 = 0; c3_i29 <= c3_loop_ub; c3_i29++) {
    c3_y_data[c3_i29] = c3_tmp_data[c3_i29];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  *c3_outData_sizes)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes;
  real_T c3_y_data[70];
  int32_T c3_loop_ub;
  int32_T c3_i30;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y_data,
                        &c3_y_sizes);
  sf_mex_destroy(&c3_arr);
  *c3_outData_sizes = c3_y_sizes;
  c3_loop_ub = c3_y_sizes - 1;
  for (c3_i30 = 0; c3_i30 <= c3_loop_ub; c3_i30++) {
    c3_outData_data[c3_i30] = c3_y_data[c3_i30];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_testAtomicGaze_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("countDigits"), "name", "name",
                  7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/countDigits.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/countDigits.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_h_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i31;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i31, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i31;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_testAtomicGaze, const char_T *
  c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_testAtomicGaze), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_testAtomicGaze);
  return c3_y;
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_testAtomicGazeInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_testAtomicGazeInstanceStruct
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

void sf_c3_testAtomicGaze_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1103486492U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(666708517U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3671796212U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3689740797U);
}

mxArray *sf_c3_testAtomicGaze_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lB44lZh7EuHAwlud3mFkxF");
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

mxArray *sf_c3_testAtomicGaze_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_testAtomicGaze_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_testAtomicGaze(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"arrBML\",},{M[8],M[0],T\"is_active_c3_testAtomicGaze\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_testAtomicGaze_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testAtomicGazeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_testAtomicGazeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testAtomicGazeMachineNumber_,
           3,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testAtomicGazeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testAtomicGazeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testAtomicGazeMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,2,0,1,"arrBML");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,498);
        _SFD_CV_INIT_SCRIPT(0,1,4,0,0,0,0,0,6,3);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"countDigits",0,-1,267);
        _SFD_CV_INIT_SCRIPT_IF(0,0,43,49,-1,94);
        _SFD_CV_INIT_SCRIPT_IF(0,1,103,120,152,175);
        _SFD_CV_INIT_SCRIPT_IF(0,2,152,175,207,263);
        _SFD_CV_INIT_SCRIPT_IF(0,3,207,232,-1,232);

        {
          static int condStart[] = { 107, 116 };

          static int condEnd[] = { 110, 119 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,106,120,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 160, 170 };

          static int condEnd[] = { 164, 174 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,159,175,2,2,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 215, 226 };

          static int condEnd[] = { 220, 231 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,2,214,232,2,4,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"encStr2Arr",0,-1,436);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          real_T *c3_x;
          real_T *c3_y;
          real_T (*c3_arrBML)[256];
          c3_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_arrBML);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testAtomicGazeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XW7VTIXYP7QZ4uIAg6ixyB";
}

static void sf_opaque_initialize_c3_testAtomicGaze(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testAtomicGazeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
    chartInstanceVar);
  initialize_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_testAtomicGaze(void *chartInstanceVar)
{
  enable_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_testAtomicGaze(void *chartInstanceVar)
{
  disable_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_testAtomicGaze(void *chartInstanceVar)
{
  sf_gateway_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_testAtomicGaze(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_testAtomicGaze
    ((SFc3_testAtomicGazeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_testAtomicGaze();/* state var info */
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

extern void sf_internal_set_sim_state_c3_testAtomicGaze(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_testAtomicGaze();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_testAtomicGaze(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_testAtomicGaze(S);
}

static void sf_opaque_set_sim_state_c3_testAtomicGaze(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_testAtomicGaze(S, st);
}

static void sf_opaque_terminate_c3_testAtomicGaze(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testAtomicGazeInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testAtomicGaze_optimization_info();
    }

    finalize_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
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
  initSimStructsc3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_testAtomicGaze(SimStruct *S)
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
    initialize_params_c3_testAtomicGaze((SFc3_testAtomicGazeInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_testAtomicGaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testAtomicGaze_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(19268629U));
  ssSetChecksum1(S,(361912167U));
  ssSetChecksum2(S,(1679837747U));
  ssSetChecksum3(S,(102758952U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_testAtomicGaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_testAtomicGaze(SimStruct *S)
{
  SFc3_testAtomicGazeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_testAtomicGazeInstanceStruct *)utMalloc(sizeof
    (SFc3_testAtomicGazeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testAtomicGazeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_testAtomicGaze;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_testAtomicGaze;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_testAtomicGaze;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_testAtomicGaze;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_testAtomicGaze;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_testAtomicGaze;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_testAtomicGaze;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_testAtomicGaze;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_testAtomicGaze;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_testAtomicGaze;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_testAtomicGaze;
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

void c3_testAtomicGaze_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_testAtomicGaze(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_testAtomicGaze(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_testAtomicGaze(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_testAtomicGaze_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
