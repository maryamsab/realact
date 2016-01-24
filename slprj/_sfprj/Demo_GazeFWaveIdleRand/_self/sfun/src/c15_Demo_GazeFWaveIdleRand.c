/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_GazeFWaveIdleRand_sfun.h"
#include "c15_Demo_GazeFWaveIdleRand.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_GazeFWaveIdleRand_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c15_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c15_IN_stateCreatePawn         ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c15_debug_family_names[2] = { "nargin", "nargout" };

static const char * c15_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c15_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void initialize_params_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void enable_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void disable_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void set_sim_state_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c15_st);
static void c15_set_sim_state_side_effects_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void finalize_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void sf_gateway_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void initSimStructsc15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance);
static void c15_encStr2Arr(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, real_T c15_myarr256[256]);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_b_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[256]);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(const char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u);
static const mxArray *c15_g_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_c_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_h_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static uint8_T c15_d_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_b_tp_stateCreatePawn, const char_T
  *c15_identifier);
static uint8_T c15_e_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_i_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_f_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[256]);
static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_g_emlrt_marshallIn
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c15_b_setSimStateSideEffectsInfo, const char_T *c15_identifier);
static const mxArray *c15_h_emlrt_marshallIn
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_doSetSimStateSideEffects = 0U;
  chartInstance->c15_setSimStateSideEffectsInfo = NULL;
  chartInstance->c15_tp_stateCreatePawn = 0U;
  chartInstance->c15_is_active_c15_Demo_GazeFWaveIdleRand = 0U;
  chartInstance->c15_is_c15_Demo_GazeFWaveIdleRand = c15_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendSBM", 0);
}

static void disable_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendSBM", 0);
}

static void c15_update_debugger_state_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  uint32_T c15_prevAniVal;
  c15_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c15_is_active_c15_Demo_GazeFWaveIdleRand == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 9U, chartInstance->c15_sfEvent);
  }

  if (chartInstance->c15_is_c15_Demo_GazeFWaveIdleRand == c15_IN_stateCreatePawn)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c15_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c15_sfEvent);
  }

  _SFD_SET_ANIMATION(c15_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_u;
  const mxArray *c15_b_y = NULL;
  uint8_T c15_b_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(2, 1), false);
  c15_hoistedGlobal = chartInstance->c15_is_active_c15_Demo_GazeFWaveIdleRand;
  c15_u = c15_hoistedGlobal;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = chartInstance->c15_is_c15_Demo_GazeFWaveIdleRand;
  c15_b_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c15_st)
{
  const mxArray *c15_u;
  c15_u = sf_mex_dup(c15_st);
  chartInstance->c15_is_active_c15_Demo_GazeFWaveIdleRand =
    c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
    "is_active_c15_Demo_GazeFWaveIdleRand");
  chartInstance->c15_is_c15_Demo_GazeFWaveIdleRand = c15_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
     "is_c15_Demo_GazeFWaveIdleRand");
  sf_mex_assign(&chartInstance->c15_setSimStateSideEffectsInfo,
                c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c15_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c15_u);
  chartInstance->c15_doSetSimStateSideEffects = 1U;
  c15_update_debugger_state_c15_Demo_GazeFWaveIdleRand(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void c15_set_sim_state_side_effects_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  if (chartInstance->c15_doSetSimStateSideEffects != 0) {
    if (chartInstance->c15_is_c15_Demo_GazeFWaveIdleRand ==
        c15_IN_stateCreatePawn) {
      chartInstance->c15_tp_stateCreatePawn = 1U;
    } else {
      chartInstance->c15_tp_stateCreatePawn = 0U;
    }

    chartInstance->c15_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c15_setSimStateSideEffectsInfo);
}

static void sf_gateway_c15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  uint32_T c15_debug_family_var_map[2];
  real_T c15_nargin = 0.0;
  real_T c15_nargout = 0.0;
  real_T c15_dv0[256];
  int32_T c15_i0;
  real_T c15_arg[256];
  int32_T c15_i1;
  int32_T c15_i2;
  int32_T c15_i3;
  uint32_T c15_b_debug_family_var_map[9];
  real_T c15_maxarrsize;
  real_T c15_arr[99];
  real_T c15_ss;
  real_T c15_padsize;
  real_T c15_tt[256];
  char_T c15_mystr[99];
  real_T c15_b_nargin = 1.0;
  real_T c15_b_nargout = 1.0;
  real_T c15_myarr256[256];
  int32_T c15_i4;
  static char_T c15_cv0[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c15_i5;
  static real_T c15_dv1[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_i8;
  int32_T c15_i9;
  real_T c15_b_arg[256];
  int32_T c15_i10;
  int32_T c15_i11;
  int32_T c15_i12;
  real_T (*c15_c_arg)[256];
  real_T (*c15_d_arg)[256];
  c15_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_set_sim_state_side_effects_c15_Demo_GazeFWaveIdleRand(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
  chartInstance->c15_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
  if (chartInstance->c15_is_active_c15_Demo_GazeFWaveIdleRand == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
    chartInstance->c15_is_active_c15_Demo_GazeFWaveIdleRand = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
    chartInstance->c15_is_c15_Demo_GazeFWaveIdleRand = c15_IN_stateCreatePawn;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c15_sfEvent);
    chartInstance->c15_tp_stateCreatePawn = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c15_debug_family_names,
      c15_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 0U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 1U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    c15_encStr2Arr(chartInstance, c15_dv0);
    for (c15_i0 = 0; c15_i0 < 256; c15_i0++) {
      c15_arg[c15_i0] = c15_dv0[c15_i0];
    }

    for (c15_i1 = 0; c15_i1 < 256; c15_i1++) {
      _SFD_DATA_RANGE_CHECK(c15_arg[c15_i1], 1U);
    }

    _SFD_SET_DATA_VALUE_PTR(1U, c15_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c15_arg, c15_i_sf_marshallOut,
      c15_e_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c15_sfEvent);
    for (c15_i2 = 0; c15_i2 < 256; c15_i2++) {
      (*c15_d_arg)[c15_i2] = c15_arg[c15_i2];
    }

    for (c15_i3 = 0; c15_i3 < 256; c15_i3++) {
      _SFD_DATA_RANGE_CHECK((*c15_d_arg)[c15_i3], 1U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendSBM", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c15_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(1U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c15_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c15_c_debug_family_names,
      c15_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_maxarrsize, 0U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c15_arr, 1U, c15_f_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c15_ss, 2U, c15_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_padsize, 3U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_tt, 4U, c15_b_sf_marshallOut,
      c15_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c15_mystr, 5U, c15_e_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_nargin, 6U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_nargout, 7U, c15_sf_marshallOut,
      c15_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_myarr256, 8U, c15_b_sf_marshallOut,
      c15_b_sf_marshallIn);
    for (c15_i4 = 0; c15_i4 < 99; c15_i4++) {
      c15_mystr[c15_i4] = c15_cv0[c15_i4];
    }

    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 4);
    c15_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 6);
    for (c15_i5 = 0; c15_i5 < 99; c15_i5++) {
      c15_arr[c15_i5] = c15_dv1[c15_i5];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 7);
    c15_ss = 99.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 8);
    c15_padsize = c15_maxarrsize - c15_ss;
    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 9);
    for (c15_i6 = 0; c15_i6 < 256; c15_i6++) {
      c15_tt[c15_i6] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 10);
    for (c15_i7 = 0; c15_i7 < 99; c15_i7++) {
      c15_tt[c15_i7] = c15_arr[c15_i7];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 11);
    for (c15_i8 = 0; c15_i8 < 256; c15_i8++) {
      c15_myarr256[c15_i8] = c15_tt[c15_i8];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
    for (c15_i9 = 0; c15_i9 < 256; c15_i9++) {
      c15_b_arg[c15_i9] = c15_myarr256[c15_i9];
    }

    for (c15_i10 = 0; c15_i10 < 256; c15_i10++) {
      _SFD_DATA_RANGE_CHECK(c15_b_arg[c15_i10], 0U);
    }

    _SFD_SET_DATA_VALUE_PTR(0U, c15_b_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c15_b_arg, c15_i_sf_marshallOut,
      c15_e_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c15_sfEvent);
    for (c15_i11 = 0; c15_i11 < 256; c15_i11++) {
      (*c15_c_arg)[c15_i11] = c15_b_arg[c15_i11];
    }

    for (c15_i12 = 0; c15_i12 < 256; c15_i12++) {
      _SFD_DATA_RANGE_CHECK((*c15_c_arg)[c15_i12], 0U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c15_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c15_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c15_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c15_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c15_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_GazeFWaveIdleRandMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc15_Demo_GazeFWaveIdleRand
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c15_encStr2Arr(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, real_T c15_myarr256[256])
{
  uint32_T c15_debug_family_var_map[9];
  real_T c15_maxarrsize;
  real_T c15_arr[35];
  real_T c15_ss;
  real_T c15_padsize;
  real_T c15_tt[256];
  char_T c15_mystr[35];
  real_T c15_nargin = 1.0;
  real_T c15_nargout = 1.0;
  int32_T c15_i13;
  static char_T c15_cv1[35] = { 'g', 't', ' ', '=', ' ', 's', 'c', 'e', 'n', 'e',
    '.', 'c', 'r', 'e', 'a', 't', 'e', 'P', 'a', 'w', 'n', '(', '\"', 'g', 'a',
    'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', ')' };

  int32_T c15_i14;
  static real_T c15_dv2[35] = { 103.0, 116.0, 32.0, 61.0, 32.0, 115.0, 99.0,
    101.0, 110.0, 101.0, 46.0, 99.0, 114.0, 101.0, 97.0, 116.0, 101.0, 80.0,
    97.0, 119.0, 110.0, 40.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 41.0 };

  int32_T c15_i15;
  int32_T c15_i16;
  int32_T c15_i17;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c15_b_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_maxarrsize, 0U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_arr, 1U, c15_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_ss, 2U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_padsize, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_tt, 4U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_mystr, 5U, c15_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 6U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 7U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_myarr256, 8U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  for (c15_i13 = 0; c15_i13 < 35; c15_i13++) {
    c15_mystr[c15_i13] = c15_cv1[c15_i13];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 4);
  c15_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 6);
  for (c15_i14 = 0; c15_i14 < 35; c15_i14++) {
    c15_arr[c15_i14] = c15_dv2[c15_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 7);
  c15_ss = 35.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_padsize = c15_maxarrsize - c15_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 9);
  for (c15_i15 = 0; c15_i15 < 256; c15_i15++) {
    c15_tt[c15_i15] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 10);
  for (c15_i16 = 0; c15_i16 < 35; c15_i16++) {
    c15_tt[c15_i16] = c15_arr[c15_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, 11);
  for (c15_i17 = 0; c15_i17 < 256; c15_i17++) {
    c15_myarr256[c15_i17] = c15_tt[c15_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c15_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c15_chartNumber, c15_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\encStr2Arr.m"));
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_nargout;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_nargout = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_nargout),
    &c15_thisId);
  sf_mex_destroy(&c15_nargout);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i18;
  real_T c15_b_inData[256];
  int32_T c15_i19;
  real_T c15_u[256];
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i18 = 0; c15_i18 < 256; c15_i18++) {
    c15_b_inData[c15_i18] = (*(real_T (*)[256])c15_inData)[c15_i18];
  }

  for (c15_i19 = 0; c15_i19 < 256; c15_i19++) {
    c15_u[c15_i19] = c15_b_inData[c15_i19];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_b_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[256])
{
  real_T c15_dv3[256];
  int32_T c15_i20;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv3, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c15_i20 = 0; c15_i20 < 256; c15_i20++) {
    c15_y[c15_i20] = c15_dv3[c15_i20];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_myarr256;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[256];
  int32_T c15_i21;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_myarr256 = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_myarr256), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_myarr256);
  for (c15_i21 = 0; c15_i21 < 256; c15_i21++) {
    (*(real_T (*)[256])c15_outData)[c15_i21] = c15_y[c15_i21];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i22;
  char_T c15_b_inData[35];
  int32_T c15_i23;
  char_T c15_u[35];
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i22 = 0; c15_i22 < 35; c15_i22++) {
    c15_b_inData[c15_i22] = (*(char_T (*)[35])c15_inData)[c15_i22];
  }

  for (c15_i23 = 0; c15_i23 < 35; c15_i23++) {
    c15_u[c15_i23] = c15_b_inData[c15_i23];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 10, 0U, 1U, 0U, 2, 1, 35),
                false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i24;
  real_T c15_b_inData[35];
  int32_T c15_i25;
  real_T c15_u[35];
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i24 = 0; c15_i24 < 35; c15_i24++) {
    c15_b_inData[c15_i24] = (*(real_T (*)[35])c15_inData)[c15_i24];
  }

  for (c15_i25 = 0; c15_i25 < 35; c15_i25++) {
    c15_u[c15_i25] = c15_b_inData[c15_i25];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 35), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i26;
  char_T c15_b_inData[99];
  int32_T c15_i27;
  char_T c15_u[99];
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i26 = 0; c15_i26 < 99; c15_i26++) {
    c15_b_inData[c15_i26] = (*(char_T (*)[99])c15_inData)[c15_i26];
  }

  for (c15_i27 = 0; c15_i27 < 99; c15_i27++) {
    c15_u[c15_i27] = c15_b_inData[c15_i27];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 10, 0U, 1U, 0U, 2, 1, 99),
                false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i28;
  real_T c15_b_inData[99];
  int32_T c15_i29;
  real_T c15_u[99];
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i28 = 0; c15_i28 < 99; c15_i28++) {
    c15_b_inData[c15_i28] = (*(real_T (*)[99])c15_inData)[c15_i28];
  }

  for (c15_i29 = 0; c15_i29 < 99; c15_i29++) {
    c15_u[c15_i29] = c15_b_inData[c15_i29];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

const mxArray *sf_c15_Demo_GazeFWaveIdleRand_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c15_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
}

static const mxArray *c15_emlrt_marshallOut(const char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), false);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(const uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), false);
  return c15_y;
}

static const mxArray *c15_g_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_c_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i30;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i30, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i30;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_h_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  uint8_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(uint8_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static uint8_T c15_d_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_b_tp_stateCreatePawn, const char_T
  *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_tp_stateCreatePawn), &c15_thisId);
  sf_mex_destroy(&c15_b_tp_stateCreatePawn);
  return c15_y;
}

static uint8_T c15_e_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_tp_stateCreatePawn;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  uint8_T c15_y;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_b_tp_stateCreatePawn = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_tp_stateCreatePawn), &c15_thisId);
  sf_mex_destroy(&c15_b_tp_stateCreatePawn);
  *(uint8_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_i_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i31;
  real_T c15_b_inData[256];
  int32_T c15_i32;
  real_T c15_u[256];
  const mxArray *c15_y = NULL;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i31 = 0; c15_i31 < 256; c15_i31++) {
    c15_b_inData[c15_i31] = (*(real_T (*)[256])c15_inData)[c15_i31];
  }

  for (c15_i32 = 0; c15_i32 < 256; c15_i32++) {
    c15_u[c15_i32] = c15_b_inData[c15_i32];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_f_emlrt_marshallIn(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[256])
{
  real_T c15_dv4[256];
  int32_T c15_i33;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv4, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c15_i33 = 0; c15_i33 < 256; c15_i33++) {
    c15_y[c15_i33] = c15_dv4[c15_i33];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_arg;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[256];
  int32_T c15_i34;
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
    chartInstanceVoid;
  c15_arg = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_arg), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_arg);
  for (c15_i34 = 0; c15_i34 < 256; c15_i34++) {
    (*(real_T (*)[256])c15_outData)[c15_i34] = c15_y[c15_i34];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_g_emlrt_marshallIn
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c15_b_setSimStateSideEffectsInfo, const char_T *c15_identifier)
{
  const mxArray *c15_y = NULL;
  emlrtMsgIdentifier c15_thisId;
  c15_y = NULL;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  sf_mex_assign(&c15_y, c15_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_setSimStateSideEffectsInfo), &c15_thisId), false);
  sf_mex_destroy(&c15_b_setSimStateSideEffectsInfo);
  return c15_y;
}

static const mxArray *c15_h_emlrt_marshallIn
  (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance, const mxArray
   *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  const mxArray *c15_y = NULL;
  (void)chartInstance;
  (void)c15_parentId;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_duplicatearraysafe(&c15_u), false);
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_Demo_GazeFWaveIdleRandInstanceStruct
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

void sf_c15_Demo_GazeFWaveIdleRand_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(116771913U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3966301853U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(32545304U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1114272100U);
}

mxArray *sf_c15_Demo_GazeFWaveIdleRand_get_autoinheritance_info(void)
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

mxArray *sf_c15_Demo_GazeFWaveIdleRand_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_Demo_GazeFWaveIdleRand_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c15_Demo_GazeFWaveIdleRand(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c15_Demo_GazeFWaveIdleRand\",},{M[9],M[0],T\"is_c15_Demo_GazeFWaveIdleRand\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_Demo_GazeFWaveIdleRand_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_GazeFWaveIdleRandMachineNumber_,
           15,
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
        init_script_number_translation(_Demo_GazeFWaveIdleRandMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_GazeFWaveIdleRandMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_GazeFWaveIdleRandMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c15_i_sf_marshallOut,(MexInFcnForType)
            c15_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_i_sf_marshallOut,(MexInFcnForType)
            c15_e_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(1,(void *)(NULL));
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_GazeFWaveIdleRandMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "UhzuqpsAzlsRfgj8i0QCiH";
}

static void sf_opaque_initialize_c15_Demo_GazeFWaveIdleRand(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_Demo_GazeFWaveIdleRand
    ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*) chartInstanceVar);
  initialize_c15_Demo_GazeFWaveIdleRand
    ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_Demo_GazeFWaveIdleRand(void *chartInstanceVar)
{
  enable_c15_Demo_GazeFWaveIdleRand((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_Demo_GazeFWaveIdleRand(void *chartInstanceVar)
{
  disable_c15_Demo_GazeFWaveIdleRand((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_Demo_GazeFWaveIdleRand(void *chartInstanceVar)
{
  sf_gateway_c15_Demo_GazeFWaveIdleRand
    ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_Demo_GazeFWaveIdleRand
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_Demo_GazeFWaveIdleRand
    ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_Demo_GazeFWaveIdleRand();/* state var info */
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

extern void sf_internal_set_sim_state_c15_Demo_GazeFWaveIdleRand(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c15_Demo_GazeFWaveIdleRand();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_Demo_GazeFWaveIdleRand
    ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_Demo_GazeFWaveIdleRand
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c15_Demo_GazeFWaveIdleRand(S);
}

static void sf_opaque_set_sim_state_c15_Demo_GazeFWaveIdleRand(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c15_Demo_GazeFWaveIdleRand(S, st);
}

static void sf_opaque_terminate_c15_Demo_GazeFWaveIdleRand(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_GazeFWaveIdleRand_optimization_info();
    }

    finalize_c15_Demo_GazeFWaveIdleRand
      ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_Demo_GazeFWaveIdleRand
    ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_Demo_GazeFWaveIdleRand(SimStruct *S)
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
    initialize_params_c15_Demo_GazeFWaveIdleRand
      ((SFc15_Demo_GazeFWaveIdleRandInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_Demo_GazeFWaveIdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_GazeFWaveIdleRand_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,15,2);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3850096097U));
  ssSetChecksum1(S,(1579838263U));
  ssSetChecksum2(S,(325879302U));
  ssSetChecksum3(S,(1427811683U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_Demo_GazeFWaveIdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c15_Demo_GazeFWaveIdleRand(SimStruct *S)
{
  SFc15_Demo_GazeFWaveIdleRandInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc15_Demo_GazeFWaveIdleRandInstanceStruct *)utMalloc(sizeof
    (SFc15_Demo_GazeFWaveIdleRandInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_Demo_GazeFWaveIdleRandInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_Demo_GazeFWaveIdleRand;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_Demo_GazeFWaveIdleRand;
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

void c15_Demo_GazeFWaveIdleRand_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_Demo_GazeFWaveIdleRand(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_Demo_GazeFWaveIdleRand(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_Demo_GazeFWaveIdleRand(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_Demo_GazeFWaveIdleRand_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
