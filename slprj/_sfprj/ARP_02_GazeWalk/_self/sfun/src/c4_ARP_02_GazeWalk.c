/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_GazeWalk_sfun.h"
#include "c4_ARP_02_GazeWalk.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_GazeWalk_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[7] = { "c", "mystr", "nargin",
  "nargout", "x", "y", "arrBML" };

static const char * c4_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c4_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

/* Function Declarations */
static void initialize_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void initialize_params_c4_ARP_02_GazeWalk
  (SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void enable_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void disable_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_ARP_02_GazeWalk
  (SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_ARP_02_GazeWalk
  (SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void set_sim_state_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c4_st);
static void finalize_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void sf_gateway_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void initSimStructsc4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static void c4_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_sprintf, const char_T *c4_identifier, char_T
  c4_y_data[], int32_T c4_y_sizes[2]);
static void c4_b_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y_data[], int32_T c4_y_sizes[2]);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_arrBML, const char_T *c4_identifier, real_T
  c4_y[256]);
static void c4_d_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c4_inData_data[], int32_T c4_inData_sizes[2]);
static void c4_f_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y_data[], int32_T c4_y_sizes[2]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, char_T c4_outData_data[], int32_T
  c4_outData_sizes[2]);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c4_inData_data[], int32_T *c4_inData_sizes);
static void c4_g_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y_data[], int32_T *c4_y_sizes);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, real_T c4_outData_data[], int32_T
  *c4_outData_sizes);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_h_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_i_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_ARP_02_GazeWalk, const char_T
  *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_ARP_02_GazeWalk = 0U;
}

static void initialize_params_c4_ARP_02_GazeWalk
  (SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_ARP_02_GazeWalk
  (SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_ARP_02_GazeWalk
  (SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[256];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_arrBML)[256];
  c4_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  for (c4_i0 = 0; c4_i0 < 256; c4_i0++) {
    c4_u[c4_i0] = (*c4_arrBML)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_ARP_02_GazeWalk;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[256];
  int32_T c4_i1;
  real_T (*c4_arrBML)[256];
  c4_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                        "arrBML", c4_dv0);
  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    (*c4_arrBML)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_ARP_02_GazeWalk = c4_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_ARP_02_GazeWalk");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_ARP_02_GazeWalk(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  real_T *c4_x;
  real_T *c4_y;
  real_T (*c4_arrBML)[256];
  c4_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_y, 1U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_ARP_02_GazeWalk(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_GazeWalkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i2 = 0; c4_i2 < 256; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_arrBML)[c4_i2], 2U);
  }
}

static void c4_chartstep_c4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_x;
  real_T c4_y;
  uint32_T c4_debug_family_var_map[7];
  real_T c4_c;
  int32_T c4_mystr_sizes[2];
  char_T c4_mystr_data[70];
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  real_T c4_arrBML[256];
  real_T c4_A;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  uint32_T c4_b_debug_family_var_map[4];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_n;
  real_T c4_dv1[2];
  int32_T c4_iv0[2];
  int32_T c4_mystr;
  int32_T c4_b_mystr;
  int32_T c4_loop_ub;
  int32_T c4_i3;
  int32_T c4_i4;
  static char_T c4_cv0[64] = { 's', 'c', 'e', 'n', 'e', '.', 'g', 'e', 't', 'P',
    'a', 'w', 'n', '(', '\\', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\\', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 'i', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'V', 'e', 'c', '(', '%', '0', '.', '1', 'f', ' ', ',',
    ' ', '%', 'd', ' ', ',', '%', 'd', ')', ')' };

  char_T c4_u[64];
  const mxArray *c4_b_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  int32_T c4_tmp_sizes[2];
  char_T c4_tmp_data[70];
  int32_T c4_c_mystr;
  int32_T c4_d_mystr;
  int32_T c4_b_loop_ub;
  int32_T c4_i5;
  int32_T c4_b_mystr_sizes[2];
  int32_T c4_e_mystr;
  int32_T c4_f_mystr;
  int32_T c4_c_loop_ub;
  int32_T c4_i6;
  char_T c4_b_mystr_data[70];
  uint32_T c4_c_debug_family_var_map[9];
  real_T c4_maxarrsize;
  int32_T c4_arr_sizes;
  real_T c4_arr_data[70];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  real_T c4_c_nargin = 1.0;
  real_T c4_c_nargout = 1.0;
  int32_T c4_d_loop_ub;
  int32_T c4_i7;
  int32_T c4_i8;
  boolean_T c4_b0;
  boolean_T c4_b1;
  boolean_T c4_b2;
  int32_T c4_i9;
  int32_T c4_b_tmp_sizes;
  int32_T c4_e_loop_ub;
  int32_T c4_i10;
  int32_T c4_b_tmp_data[70];
  int32_T c4_iv1[1];
  int32_T c4_f_loop_ub;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  real_T *c4_h_x;
  real_T *c4_f_y;
  real_T (*c4_b_arrBML)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c4_b_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_f_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_h_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_h_x;
  c4_b_hoistedGlobal = *c4_f_y;
  c4_x = c4_hoistedGlobal;
  c4_y = c4_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c4_mystr_data, (const int32_T *)
    &c4_mystr_sizes, NULL, 0, 1, (void *)c4_c_sf_marshallOut, (void *)
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_x, 4U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_y, 5U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_arrBML, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
  c4_A = c4_x - 180.0;
  c4_b_x = c4_A;
  c4_c_x = c4_b_x;
  c4_d_x = c4_c_x;
  c4_x = c4_d_x / 300.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 40);
  c4_e_x = c4_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_b_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_x, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 2);
  c4_c = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  if (CV_SCRIPT_IF(0, 0, c4_e_x < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
    c4_c = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 5);
    c4_f_x = c4_e_x;
    c4_g_x = c4_f_x;
    c4_e_x = muDoubleScalarAbs(c4_g_x);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  guard1 = false;
  if (CV_SCRIPT_COND(0, 0, c4_e_x > 0.0)) {
    if (CV_SCRIPT_COND(0, 1, c4_e_x < 9.0)) {
      CV_SCRIPT_MCDC(0, 0, true);
      CV_SCRIPT_IF(0, 1, true);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
      c4_c++;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(0, 0, false);
    CV_SCRIPT_IF(0, 1, false);
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
    guard2 = false;
    if (CV_SCRIPT_COND(0, 2, c4_e_x > 10.0)) {
      if (CV_SCRIPT_COND(0, 3, c4_e_x < 99.0)) {
        CV_SCRIPT_MCDC(0, 1, true);
        CV_SCRIPT_IF(0, 2, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
        c4_c += 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_SCRIPT_MCDC(0, 1, false);
      CV_SCRIPT_IF(0, 2, false);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
      guard3 = false;
      if (CV_SCRIPT_COND(0, 4, c4_e_x > 100.0)) {
        if (CV_SCRIPT_COND(0, 5, c4_e_x < 999.0)) {
          CV_SCRIPT_MCDC(0, 2, true);
          CV_SCRIPT_IF(0, 3, true);
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 12);
          c4_c += 3.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
  c4_n = 66.0 + c4_c;
  c4_dv1[0] = 1.0;
  c4_dv1[1] = c4_n;
  c4_mystr_sizes[0] = 1;
  c4_iv0[0] = 1;
  c4_iv0[1] = (int32_T)c4_dv1[1];
  c4_mystr_sizes[1] = c4_iv0[1];
  c4_mystr = c4_mystr_sizes[0];
  c4_b_mystr = c4_mystr_sizes[1];
  c4_loop_ub = (int32_T)c4_dv1[1] - 1;
  for (c4_i3 = 0; c4_i3 <= c4_loop_ub; c4_i3++) {
    c4_mystr_data[c4_i3] = ' ';
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
  for (c4_i4 = 0; c4_i4 < 64; c4_i4++) {
    c4_u[c4_i4] = c4_cv0[c4_i4];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 64),
                false);
  c4_b_u = c4_x;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  c4_c_u = 1.7;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  c4_d_u = 2.0;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  c4_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 4U, 14,
                       c4_b_y, 14, c4_c_y, 14, c4_d_y, 14, c4_e_y), "sprintf",
                      c4_tmp_data, c4_tmp_sizes);
  c4_mystr_sizes[0] = 1;
  c4_mystr_sizes[1] = c4_tmp_sizes[1];
  c4_c_mystr = c4_mystr_sizes[0];
  c4_d_mystr = c4_mystr_sizes[1];
  c4_b_loop_ub = c4_tmp_sizes[0] * c4_tmp_sizes[1] - 1;
  for (c4_i5 = 0; c4_i5 <= c4_b_loop_ub; c4_i5++) {
    c4_mystr_data[c4_i5] = c4_tmp_data[c4_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
  c4_b_mystr_sizes[0] = 1;
  c4_b_mystr_sizes[1] = c4_mystr_sizes[1];
  c4_e_mystr = c4_b_mystr_sizes[0];
  c4_f_mystr = c4_b_mystr_sizes[1];
  c4_c_loop_ub = c4_mystr_sizes[0] * c4_mystr_sizes[1] - 1;
  for (c4_i6 = 0; c4_i6 <= c4_c_loop_ub; c4_i6++) {
    c4_b_mystr_data[c4_i6] = c4_mystr_data[c4_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_c_debug_family_names,
    c4_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c4_arr_data, (const int32_T *)
    &c4_arr_sizes, NULL, 0, 1, (void *)c4_d_sf_marshallOut, (void *)
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ss, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c4_b_mystr_data, (const int32_T *)
    &c4_b_mystr_sizes, NULL, 1, 7, (void *)c4_c_sf_marshallOut, (void *)
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_arrBML, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 6);
  c4_arr_sizes = c4_b_mystr_sizes[1];
  c4_d_loop_ub = c4_b_mystr_sizes[1] - 1;
  for (c4_i7 = 0; c4_i7 <= c4_d_loop_ub; c4_i7++) {
    c4_arr_data[c4_i7] = (real_T)c4_b_mystr_data[c4_b_mystr_sizes[0] * c4_i7];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 7);
  c4_ss = (real_T)c4_arr_sizes;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 256.0 - c4_ss;
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 9);
  for (c4_i8 = 0; c4_i8 < 256; c4_i8++) {
    c4_tt[c4_i8] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 10);
  c4_b0 = (1.0 > c4_ss);
  c4_b1 = c4_b0;
  c4_b2 = c4_b1;
  if (c4_b2) {
    c4_i9 = 0;
  } else {
    c4_i9 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c4_ss, 1, 256, 0, 0);
  }

  c4_b_tmp_sizes = c4_i9;
  c4_e_loop_ub = c4_i9 - 1;
  for (c4_i10 = 0; c4_i10 <= c4_e_loop_ub; c4_i10++) {
    c4_b_tmp_data[c4_i10] = c4_i10;
  }

  c4_iv1[0] = c4_b_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c4_iv1, 1, *(int32_T (*)[1])&c4_arr_sizes, 1);
  c4_f_loop_ub = c4_arr_sizes - 1;
  for (c4_i11 = 0; c4_i11 <= c4_f_loop_ub; c4_i11++) {
    c4_tt[c4_b_tmp_data[c4_i11]] = c4_arr_data[c4_i11];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 11);
  for (c4_i12 = 0; c4_i12 < 256; c4_i12++) {
    c4_arrBML[c4_i12] = c4_tt[c4_i12];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -44);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i13 = 0; c4_i13 < 256; c4_i13++) {
    (*c4_b_arrBML)[c4_i13] = c4_arrBML[c4_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_ARP_02_GazeWalk(SFc4_ARP_02_GazeWalkInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\countDigits.m"));
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static void c4_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_sprintf, const char_T *c4_identifier, char_T
  c4_y_data[], int32_T c4_y_sizes[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_sprintf), &c4_thisId,
                        c4_y_data, c4_y_sizes);
  sf_mex_destroy(&c4_sprintf);
}

static void c4_b_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y_data[], int32_T c4_y_sizes[2])
{
  int32_T c4_i14;
  uint32_T c4_uv0[2];
  int32_T c4_i15;
  static boolean_T c4_bv0[2] = { false, true };

  boolean_T c4_bv1[2];
  int32_T c4_tmp_sizes[2];
  char_T c4_tmp_data[70];
  int32_T c4_y;
  int32_T c4_b_y;
  int32_T c4_loop_ub;
  int32_T c4_i16;
  (void)chartInstance;
  for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
    c4_uv0[c4_i14] = 1U + 69U * (uint32_T)c4_i14;
  }

  for (c4_i15 = 0; c4_i15 < 2; c4_i15++) {
    c4_bv1[c4_i15] = c4_bv0[c4_i15];
  }

  sf_mex_import_vs(c4_parentId, sf_mex_dup(c4_u), c4_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c4_bv1, c4_uv0, c4_tmp_sizes);
  c4_y_sizes[0] = 1;
  c4_y_sizes[1] = c4_tmp_sizes[1];
  c4_y = c4_y_sizes[0];
  c4_b_y = c4_y_sizes[1];
  c4_loop_ub = c4_tmp_sizes[0] * c4_tmp_sizes[1] - 1;
  for (c4_i16 = 0; c4_i16 <= c4_loop_ub; c4_i16++) {
    c4_y_data[c4_i16] = c4_tmp_data[c4_i16];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i17;
  real_T c4_b_inData[256];
  int32_T c4_i18;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i17 = 0; c4_i17 < 256; c4_i17++) {
    c4_b_inData[c4_i17] = (*(real_T (*)[256])c4_inData)[c4_i17];
  }

  for (c4_i18 = 0; c4_i18 < 256; c4_i18++) {
    c4_u[c4_i18] = c4_b_inData[c4_i18];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_arrBML, const char_T *c4_identifier, real_T
  c4_y[256])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_arrBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_arrBML);
}

static void c4_d_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256])
{
  real_T c4_dv2[256];
  int32_T c4_i19;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 1, 256);
  for (c4_i19 = 0; c4_i19 < 256; c4_i19++) {
    c4_y[c4_i19] = c4_dv2[c4_i19];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_arrBML;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i20;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_arrBML = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_arrBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_arrBML);
  for (c4_i20 = 0; c4_i20 < 256; c4_i20++) {
    (*(real_T (*)[256])c4_outData)[c4_i20] = c4_y[c4_i20];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, char_T
  c4_inData_data[], int32_T c4_inData_sizes[2])
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_b_inData_sizes[2];
  int32_T c4_loop_ub;
  int32_T c4_i21;
  char_T c4_b_inData_data[70];
  int32_T c4_u_sizes[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i22;
  char_T c4_u_data[70];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_b_inData_sizes[0] = 1;
  c4_b_inData_sizes[1] = c4_inData_sizes[1];
  c4_loop_ub = c4_inData_sizes[1] - 1;
  for (c4_i21 = 0; c4_i21 <= c4_loop_ub; c4_i21++) {
    c4_b_inData_data[c4_b_inData_sizes[0] * c4_i21] =
      c4_inData_data[c4_inData_sizes[0] * c4_i21];
  }

  c4_u_sizes[0] = 1;
  c4_u_sizes[1] = c4_b_inData_sizes[1];
  c4_b_loop_ub = c4_b_inData_sizes[1] - 1;
  for (c4_i22 = 0; c4_i22 <= c4_b_loop_ub; c4_i22++) {
    c4_u_data[c4_u_sizes[0] * c4_i22] = c4_b_inData_data[c4_b_inData_sizes[0] *
      c4_i22];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u_data, 10, 0U, 1U, 0U, 2,
    c4_u_sizes[0], c4_u_sizes[1]), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y_data[], int32_T c4_y_sizes[2])
{
  int32_T c4_i23;
  uint32_T c4_uv1[2];
  int32_T c4_i24;
  static boolean_T c4_bv2[2] = { false, true };

  boolean_T c4_bv3[2];
  int32_T c4_tmp_sizes[2];
  char_T c4_tmp_data[70];
  int32_T c4_y;
  int32_T c4_b_y;
  int32_T c4_loop_ub;
  int32_T c4_i25;
  (void)chartInstance;
  for (c4_i23 = 0; c4_i23 < 2; c4_i23++) {
    c4_uv1[c4_i23] = 1U + 69U * (uint32_T)c4_i23;
  }

  for (c4_i24 = 0; c4_i24 < 2; c4_i24++) {
    c4_bv3[c4_i24] = c4_bv2[c4_i24];
  }

  sf_mex_import_vs(c4_parentId, sf_mex_dup(c4_u), c4_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c4_bv3, c4_uv1, c4_tmp_sizes);
  c4_y_sizes[0] = 1;
  c4_y_sizes[1] = c4_tmp_sizes[1];
  c4_y = c4_y_sizes[0];
  c4_b_y = c4_y_sizes[1];
  c4_loop_ub = c4_tmp_sizes[0] * c4_tmp_sizes[1] - 1;
  for (c4_i25 = 0; c4_i25 <= c4_loop_ub; c4_i25++) {
    c4_y_data[c4_i25] = c4_tmp_data[c4_i25];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, char_T c4_outData_data[], int32_T
  c4_outData_sizes[2])
{
  const mxArray *c4_mystr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y_sizes[2];
  char_T c4_y_data[70];
  int32_T c4_loop_ub;
  int32_T c4_i26;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_mystr = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_mystr), &c4_thisId,
                        c4_y_data, c4_y_sizes);
  sf_mex_destroy(&c4_mystr);
  c4_outData_sizes[0] = 1;
  c4_outData_sizes[1] = c4_y_sizes[1];
  c4_loop_ub = c4_y_sizes[1] - 1;
  for (c4_i26 = 0; c4_i26 <= c4_loop_ub; c4_i26++) {
    c4_outData_data[c4_outData_sizes[0] * c4_i26] = c4_y_data[c4_y_sizes[0] *
      c4_i26];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c4_inData_data[], int32_T *c4_inData_sizes)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_b_inData_sizes;
  int32_T c4_loop_ub;
  int32_T c4_i27;
  real_T c4_b_inData_data[70];
  int32_T c4_u_sizes;
  int32_T c4_b_loop_ub;
  int32_T c4_i28;
  real_T c4_u_data[70];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_b_inData_sizes = *c4_inData_sizes;
  c4_loop_ub = *c4_inData_sizes - 1;
  for (c4_i27 = 0; c4_i27 <= c4_loop_ub; c4_i27++) {
    c4_b_inData_data[c4_i27] = c4_inData_data[c4_i27];
  }

  c4_u_sizes = c4_b_inData_sizes;
  c4_b_loop_ub = c4_b_inData_sizes - 1;
  for (c4_i28 = 0; c4_i28 <= c4_b_loop_ub; c4_i28++) {
    c4_u_data[c4_i28] = c4_b_inData_data[c4_i28];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u_data, 0, 0U, 1U, 0U, 1,
    c4_u_sizes), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_g_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y_data[], int32_T *c4_y_sizes)
{
  static uint32_T c4_uv2[1] = { 70U };

  uint32_T c4_uv3[1];
  static boolean_T c4_bv4[1] = { true };

  boolean_T c4_bv5[1];
  int32_T c4_tmp_sizes;
  real_T c4_tmp_data[70];
  int32_T c4_loop_ub;
  int32_T c4_i29;
  (void)chartInstance;
  c4_uv3[0] = c4_uv2[0];
  c4_bv5[0] = c4_bv4[0];
  sf_mex_import_vs(c4_parentId, sf_mex_dup(c4_u), c4_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c4_bv5, c4_uv3, &c4_tmp_sizes);
  *c4_y_sizes = c4_tmp_sizes;
  c4_loop_ub = c4_tmp_sizes - 1;
  for (c4_i29 = 0; c4_i29 <= c4_loop_ub; c4_i29++) {
    c4_y_data[c4_i29] = c4_tmp_data[c4_i29];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, real_T c4_outData_data[], int32_T
  *c4_outData_sizes)
{
  const mxArray *c4_arr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y_sizes;
  real_T c4_y_data[70];
  int32_T c4_loop_ub;
  int32_T c4_i30;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_arr = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_arr), &c4_thisId, c4_y_data,
                        &c4_y_sizes);
  sf_mex_destroy(&c4_arr);
  *c4_outData_sizes = c4_y_sizes;
  c4_loop_ub = c4_y_sizes - 1;
  for (c4_i30 = 0; c4_i30 <= c4_loop_ub; c4_i30++) {
    c4_outData_data[c4_i30] = c4_y_data[c4_i30];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_ARP_02_GazeWalk_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  const mxArray *c4_rhs11 = NULL;
  const mxArray *c4_lhs11 = NULL;
  const mxArray *c4_rhs12 = NULL;
  const mxArray *c4_lhs12 = NULL;
  const mxArray *c4_rhs13 = NULL;
  const mxArray *c4_lhs13 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("countDigits"), "name", "name",
                  7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/countDigits.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/countDigits.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("abs"), "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("blanks"), "name", "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c4_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c4_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c4_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
  sf_mex_destroy(&c4_rhs11);
  sf_mex_destroy(&c4_lhs11);
  sf_mex_destroy(&c4_rhs12);
  sf_mex_destroy(&c4_lhs12);
  sf_mex_destroy(&c4_rhs13);
  sf_mex_destroy(&c4_lhs13);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_h_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i31;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i31, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i31;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_ARP_02_GazeWalk, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_ARP_02_GazeWalk), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_ARP_02_GazeWalk);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_ARP_02_GazeWalkInstanceStruct
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

void sf_c4_ARP_02_GazeWalk_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(192986783U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3629385887U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1906916351U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3188189390U);
}

mxArray *sf_c4_ARP_02_GazeWalk_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("pnniBZDQJnWn7yFUeHVrTE");
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

mxArray *sf_c4_ARP_02_GazeWalk_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_ARP_02_GazeWalk_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_ARP_02_GazeWalk(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"arrBML\",},{M[8],M[0],T\"is_active_c4_ARP_02_GazeWalk\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_ARP_02_GazeWalk_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_GazeWalkMachineNumber_,
           4,
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
        init_script_number_translation(_ARP_02_GazeWalkMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_GazeWalkMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_GazeWalkMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1753);
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
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real_T *c4_x;
          real_T *c4_y;
          real_T (*c4_arrBML)[256];
          c4_arrBML = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_arrBML);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_GazeWalkMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "uwlasFE500yem7sF5bpiaB";
}

static void sf_opaque_initialize_c4_ARP_02_GazeWalk(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
  initialize_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_ARP_02_GazeWalk(void *chartInstanceVar)
{
  enable_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_ARP_02_GazeWalk(void *chartInstanceVar)
{
  disable_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_ARP_02_GazeWalk(void *chartInstanceVar)
{
  sf_gateway_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_ARP_02_GazeWalk(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_ARP_02_GazeWalk
    ((SFc4_ARP_02_GazeWalkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_ARP_02_GazeWalk();/* state var info */
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

extern void sf_internal_set_sim_state_c4_ARP_02_GazeWalk(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_ARP_02_GazeWalk();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_ARP_02_GazeWalk(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_ARP_02_GazeWalk(S);
}

static void sf_opaque_set_sim_state_c4_ARP_02_GazeWalk(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_ARP_02_GazeWalk(S, st);
}

static void sf_opaque_terminate_c4_ARP_02_GazeWalk(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_ARP_02_GazeWalkInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_GazeWalk_optimization_info();
    }

    finalize_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
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
  initSimStructsc4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_ARP_02_GazeWalk(SimStruct *S)
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
    initialize_params_c4_ARP_02_GazeWalk((SFc4_ARP_02_GazeWalkInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_ARP_02_GazeWalk(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_GazeWalk_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2054772143U));
  ssSetChecksum1(S,(4075141473U));
  ssSetChecksum2(S,(1000954821U));
  ssSetChecksum3(S,(1494043480U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_ARP_02_GazeWalk(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_ARP_02_GazeWalk(SimStruct *S)
{
  SFc4_ARP_02_GazeWalkInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_ARP_02_GazeWalkInstanceStruct *)utMalloc(sizeof
    (SFc4_ARP_02_GazeWalkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_ARP_02_GazeWalkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_ARP_02_GazeWalk;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_ARP_02_GazeWalk;
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

void c4_ARP_02_GazeWalk_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_ARP_02_GazeWalk(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_ARP_02_GazeWalk(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_ARP_02_GazeWalk(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_ARP_02_GazeWalk_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
