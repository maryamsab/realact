/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_GazeWalk_sfun.h"
#include "c5_ARP_02_GazeWalk.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_GazeWalk_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c5_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c5_IN_stateCreatePawn          ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void initialize_params_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void enable_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void disable_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void set_sim_state_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c5_st);
static void c5_set_sim_state_side_effects_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void finalize_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void sf_gateway_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void initSimStructsc5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct *
  chartInstance);
static void c5_encStr2Arr(SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c5_myarr256[256]);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_b_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_b_tp_stateCreatePawn, const char_T
  *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256]);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier);
static const mxArray *c5_h_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_doSetSimStateSideEffects = 0U;
  chartInstance->c5_setSimStateSideEffectsInfo = NULL;
  chartInstance->c5_tp_stateCreatePawn = 0U;
  chartInstance->c5_is_active_c5_ARP_02_GazeWalk = 0U;
  chartInstance->c5_is_c5_ARP_02_GazeWalk = c5_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void disable_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

static void c5_update_debugger_state_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c5_prevAniVal;
  c5_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c5_is_active_c5_ARP_02_GazeWalk == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_ARP_02_GazeWalk == c5_IN_stateCreatePawn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  }

  _SFD_SET_ANIMATION(c5_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_ARP_02_GazeWalk;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_c5_ARP_02_GazeWalk;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  c5_u = sf_mex_dup(c5_st);
  chartInstance->c5_is_active_c5_ARP_02_GazeWalk = c5_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
     "is_active_c5_ARP_02_GazeWalk");
  chartInstance->c5_is_c5_ARP_02_GazeWalk = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_c5_ARP_02_GazeWalk");
  sf_mex_assign(&chartInstance->c5_setSimStateSideEffectsInfo,
                c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c5_u);
  chartInstance->c5_doSetSimStateSideEffects = 1U;
  c5_update_debugger_state_c5_ARP_02_GazeWalk(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void c5_set_sim_state_side_effects_c5_ARP_02_GazeWalk
  (SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  if (chartInstance->c5_doSetSimStateSideEffects != 0) {
    if (chartInstance->c5_is_c5_ARP_02_GazeWalk == c5_IN_stateCreatePawn) {
      chartInstance->c5_tp_stateCreatePawn = 1U;
    } else {
      chartInstance->c5_tp_stateCreatePawn = 0U;
    }

    chartInstance->c5_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c5_setSimStateSideEffectsInfo);
}

static void sf_gateway_c5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_dv0[256];
  int32_T c5_i0;
  real_T c5_arg[256];
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  uint32_T c5_b_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[99];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[99];
  real_T c5_b_nargin = 1.0;
  real_T c5_b_nargout = 1.0;
  real_T c5_myarr256[256];
  int32_T c5_i4;
  static char_T c5_cv0[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i5;
  static real_T c5_dv1[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_b_arg[256];
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  real_T (*c5_c_arg)[256];
  real_T (*c5_d_arg)[256];
  c5_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_set_sim_state_side_effects_c5_ARP_02_GazeWalk(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  if (chartInstance->c5_is_active_c5_ARP_02_GazeWalk == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_active_c5_ARP_02_GazeWalk = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    chartInstance->c5_is_c5_ARP_02_GazeWalk = c5_IN_stateCreatePawn;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateCreatePawn = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    c5_encStr2Arr(chartInstance, c5_dv0);
    for (c5_i0 = 0; c5_i0 < 256; c5_i0++) {
      c5_arg[c5_i0] = c5_dv0[c5_i0];
    }

    for (c5_i1 = 0; c5_i1 < 256; c5_i1++) {
      _SFD_DATA_RANGE_CHECK(c5_arg[c5_i1], 0U);
    }

    _SFD_SET_DATA_VALUE_PTR(0U, c5_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c5_arg, c5_i_sf_marshallOut,
      c5_e_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
    for (c5_i2 = 0; c5_i2 < 256; c5_i2++) {
      (*c5_d_arg)[c5_i2] = c5_arg[c5_i2];
    }

    for (c5_i3 = 0; c5_i3 < 256; c5_i3++) {
      _SFD_DATA_RANGE_CHECK((*c5_d_arg)[c5_i3], 0U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_c_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_f_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_e_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 6U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 7U, c5_sf_marshallOut,
      c5_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    for (c5_i4 = 0; c5_i4 < 99; c5_i4++) {
      c5_mystr[c5_i4] = c5_cv0[c5_i4];
    }

    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
    c5_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
    for (c5_i5 = 0; c5_i5 < 99; c5_i5++) {
      c5_arr[c5_i5] = c5_dv1[c5_i5];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
    c5_ss = 99.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
    c5_padsize = c5_maxarrsize - c5_ss;
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
    for (c5_i6 = 0; c5_i6 < 256; c5_i6++) {
      c5_tt[c5_i6] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
    for (c5_i7 = 0; c5_i7 < 99; c5_i7++) {
      c5_tt[c5_i7] = c5_arr[c5_i7];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
    for (c5_i8 = 0; c5_i8 < 256; c5_i8++) {
      c5_myarr256[c5_i8] = c5_tt[c5_i8];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
    for (c5_i9 = 0; c5_i9 < 256; c5_i9++) {
      c5_b_arg[c5_i9] = c5_myarr256[c5_i9];
    }

    for (c5_i10 = 0; c5_i10 < 256; c5_i10++) {
      _SFD_DATA_RANGE_CHECK(c5_b_arg[c5_i10], 1U);
    }

    _SFD_SET_DATA_VALUE_PTR(1U, c5_b_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c5_b_arg, c5_i_sf_marshallOut,
      c5_e_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
    for (c5_i11 = 0; c5_i11 < 256; c5_i11++) {
      (*c5_c_arg)[c5_i11] = c5_b_arg[c5_i11];
    }

    for (c5_i12 = 0; c5_i12 < 256; c5_i12++) {
      _SFD_DATA_RANGE_CHECK((*c5_c_arg)[c5_i12], 1U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(1U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_GazeWalkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_ARP_02_GazeWalk(SFc5_ARP_02_GazeWalkInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c5_encStr2Arr(SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[35];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[35];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i13;
  static char_T c5_cv1[35] = { 'g', 't', ' ', '=', ' ', 's', 'c', 'e', 'n', 'e',
    '.', 'c', 'r', 'e', 'a', 't', 'e', 'P', 'a', 'w', 'n', '(', '\"', 'g', 'a',
    'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', ')' };

  int32_T c5_i14;
  static real_T c5_dv2[35] = { 103.0, 116.0, 32.0, 61.0, 32.0, 115.0, 99.0,
    101.0, 110.0, 101.0, 46.0, 99.0, 114.0, 101.0, 97.0, 116.0, 101.0, 80.0,
    97.0, 119.0, 110.0, 40.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 41.0 };

  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  for (c5_i13 = 0; c5_i13 < 35; c5_i13++) {
    c5_mystr[c5_i13] = c5_cv1[c5_i13];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i14 = 0; c5_i14 < 35; c5_i14++) {
    c5_arr[c5_i14] = c5_dv2[c5_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 35.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i15 = 0; c5_i15 < 256; c5_i15++) {
    c5_tt[c5_i15] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i16 = 0; c5_i16 < 35; c5_i16++) {
    c5_tt[c5_i16] = c5_arr[c5_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i17 = 0; c5_i17 < 256; c5_i17++) {
    c5_myarr256[c5_i17] = c5_tt[c5_i17];
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

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
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
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i18;
  real_T c5_b_inData[256];
  int32_T c5_i19;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i18 = 0; c5_i18 < 256; c5_i18++) {
    c5_b_inData[c5_i18] = (*(real_T (*)[256])c5_inData)[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 256; c5_i19++) {
    c5_u[c5_i19] = c5_b_inData[c5_i19];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_b_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256])
{
  real_T c5_dv3[256];
  int32_T c5_i20;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv3, 1, 0, 0U, 1, 0U, 1, 256);
  for (c5_i20 = 0; c5_i20 < 256; c5_i20++) {
    c5_y[c5_i20] = c5_dv3[c5_i20];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_myarr256;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[256];
  int32_T c5_i21;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_myarr256 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_myarr256), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_myarr256);
  for (c5_i21 = 0; c5_i21 < 256; c5_i21++) {
    (*(real_T (*)[256])c5_outData)[c5_i21] = c5_y[c5_i21];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i22;
  char_T c5_b_inData[35];
  int32_T c5_i23;
  char_T c5_u[35];
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i22 = 0; c5_i22 < 35; c5_i22++) {
    c5_b_inData[c5_i22] = (*(char_T (*)[35])c5_inData)[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 35; c5_i23++) {
    c5_u[c5_i23] = c5_b_inData[c5_i23];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 35), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i24;
  real_T c5_b_inData[35];
  int32_T c5_i25;
  real_T c5_u[35];
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i24 = 0; c5_i24 < 35; c5_i24++) {
    c5_b_inData[c5_i24] = (*(real_T (*)[35])c5_inData)[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 35; c5_i25++) {
    c5_u[c5_i25] = c5_b_inData[c5_i25];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 35), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i26;
  char_T c5_b_inData[99];
  int32_T c5_i27;
  char_T c5_u[99];
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i26 = 0; c5_i26 < 99; c5_i26++) {
    c5_b_inData[c5_i26] = (*(char_T (*)[99])c5_inData)[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 99; c5_i27++) {
    c5_u[c5_i27] = c5_b_inData[c5_i27];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 99), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i28;
  real_T c5_b_inData[99];
  int32_T c5_i29;
  real_T c5_u[99];
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i28 = 0; c5_i28 < 99; c5_i28++) {
    c5_b_inData[c5_i28] = (*(real_T (*)[99])c5_inData)[c5_i28];
  }

  for (c5_i29 = 0; c5_i29 < 99; c5_i29++) {
    c5_u[c5_i29] = c5_b_inData[c5_i29];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_ARP_02_GazeWalk_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
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

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i30;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i30, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i30;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
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

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  uint8_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(uint8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_b_tp_stateCreatePawn, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_stateCreatePawn),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_stateCreatePawn);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
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

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_tp_stateCreatePawn;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_b_tp_stateCreatePawn = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_stateCreatePawn),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_stateCreatePawn);
  *(uint8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i31;
  real_T c5_b_inData[256];
  int32_T c5_i32;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i31 = 0; c5_i31 < 256; c5_i31++) {
    c5_b_inData[c5_i31] = (*(real_T (*)[256])c5_inData)[c5_i31];
  }

  for (c5_i32 = 0; c5_i32 < 256; c5_i32++) {
    c5_u[c5_i32] = c5_b_inData[c5_i32];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_f_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256])
{
  real_T c5_dv4[256];
  int32_T c5_i33;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv4, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c5_i33 = 0; c5_i33 < 256; c5_i33++) {
    c5_y[c5_i33] = c5_dv4[c5_i33];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_arg;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[256];
  int32_T c5_i34;
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c5_arg = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_arg), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_arg);
  for (c5_i34 = 0; c5_i34 < 256; c5_i34++) {
    (*(real_T (*)[256])c5_outData)[c5_i34] = c5_y[c5_i34];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier)
{
  const mxArray *c5_y = NULL;
  emlrtMsgIdentifier c5_thisId;
  c5_y = NULL;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  sf_mex_assign(&c5_y, c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_setSimStateSideEffectsInfo), &c5_thisId), false);
  sf_mex_destroy(&c5_b_setSimStateSideEffectsInfo);
  return c5_y;
}

static const mxArray *c5_h_emlrt_marshallIn(SFc5_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  (void)c5_parentId;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u), false);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_ARP_02_GazeWalkInstanceStruct
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

void sf_c5_ARP_02_GazeWalk_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2173412560U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(180775905U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(271831406U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(200258531U);
}

mxArray *sf_c5_ARP_02_GazeWalk_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nXZRq3E4ZUB2RMzRpUECK");
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

mxArray *sf_c5_ARP_02_GazeWalk_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_ARP_02_GazeWalk_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_ARP_02_GazeWalk(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c5_ARP_02_GazeWalk\",},{M[9],M[0],T\"is_c5_ARP_02_GazeWalk\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_ARP_02_GazeWalk_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_GazeWalkMachineNumber_,
           5,
           3,
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
          _SFD_SET_DATA_PROPS(0,8,0,0,"");
          _SFD_SET_DATA_PROPS(1,8,0,0,"");
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_i_sf_marshallOut,(MexInFcnForType)
            c5_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_i_sf_marshallOut,(MexInFcnForType)
            c5_e_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(1,(void *)(NULL));
        (void)chartInstance;
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
  return "iJVKyZ50THCIdoCWXvazjG";
}

static void sf_opaque_initialize_c5_ARP_02_GazeWalk(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
  initialize_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_ARP_02_GazeWalk(void *chartInstanceVar)
{
  enable_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_ARP_02_GazeWalk(void *chartInstanceVar)
{
  disable_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_ARP_02_GazeWalk(void *chartInstanceVar)
{
  sf_gateway_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_ARP_02_GazeWalk(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_ARP_02_GazeWalk
    ((SFc5_ARP_02_GazeWalkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_ARP_02_GazeWalk();/* state var info */
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

extern void sf_internal_set_sim_state_c5_ARP_02_GazeWalk(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_ARP_02_GazeWalk();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_ARP_02_GazeWalk(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_ARP_02_GazeWalk(S);
}

static void sf_opaque_set_sim_state_c5_ARP_02_GazeWalk(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_ARP_02_GazeWalk(S, st);
}

static void sf_opaque_terminate_c5_ARP_02_GazeWalk(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_ARP_02_GazeWalkInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_GazeWalk_optimization_info();
    }

    finalize_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
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
  initSimStructsc5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_ARP_02_GazeWalk(SimStruct *S)
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
    initialize_params_c5_ARP_02_GazeWalk((SFc5_ARP_02_GazeWalkInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_ARP_02_GazeWalk(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_GazeWalk_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,5,2);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3671872054U));
  ssSetChecksum1(S,(227390499U));
  ssSetChecksum2(S,(2696352039U));
  ssSetChecksum3(S,(2843584498U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_ARP_02_GazeWalk(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c5_ARP_02_GazeWalk(SimStruct *S)
{
  SFc5_ARP_02_GazeWalkInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_ARP_02_GazeWalkInstanceStruct *)utMalloc(sizeof
    (SFc5_ARP_02_GazeWalkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_ARP_02_GazeWalkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_ARP_02_GazeWalk;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_ARP_02_GazeWalk;
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

void c5_ARP_02_GazeWalk_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_ARP_02_GazeWalk(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_ARP_02_GazeWalk(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_ARP_02_GazeWalk(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_ARP_02_GazeWalk_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
