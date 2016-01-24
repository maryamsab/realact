/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectAllReceiver_sfun.h"
#include "c2_testKinectAllReceiver.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectAllReceiver_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_stateEnableReceiver      ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void initialize_params_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void enable_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void disable_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void set_sim_state_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void finalize_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void sf_gateway_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void initSimStructsc2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_stateEnableReceiver, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_stateEnableReceiver = 0U;
  chartInstance->c2_is_active_c2_testKinectAllReceiver = 0U;
  chartInstance->c2_is_c2_testKinectAllReceiver = c2_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void disable_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

static void c2_update_debugger_state_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_testKinectAllReceiver == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_testKinectAllReceiver == c2_IN_stateEnableReceiver)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_testKinectAllReceiver;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_c2_testKinectAllReceiver;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  c2_u = sf_mex_dup(c2_st);
  chartInstance->c2_is_active_c2_testKinectAllReceiver = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
     "is_active_c2_testKinectAllReceiver");
  chartInstance->c2_is_c2_testKinectAllReceiver = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_c2_testKinectAllReceiver");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_testKinectAllReceiver(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_testKinectAllReceiver ==
        c2_IN_stateEnableReceiver) {
      chartInstance->c2_tp_stateEnableReceiver = 1U;
    } else {
      chartInstance->c2_tp_stateEnableReceiver = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  uint32_T c2_b_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[15];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[15];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_myarr256[256];
  int32_T c2_i0;
  static char_T c2_cv0[15] = { 'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r', ' ', 'e',
    'n', 'a', 'b', 'l', 'e' };

  int32_T c2_i1;
  static real_T c2_dv0[15] = { 114.0, 101.0, 99.0, 101.0, 105.0, 118.0, 101.0,
    114.0, 32.0, 101.0, 110.0, 97.0, 98.0, 108.0, 101.0 };

  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  real_T c2_arg[256];
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_set_sim_state_side_effects_c2_testKinectAllReceiver(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_testKinectAllReceiver == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_testKinectAllReceiver = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_testKinectAllReceiver = c2_IN_stateEnableReceiver;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateEnableReceiver = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_b_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_d_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_c_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 6U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 7U, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    for (c2_i0 = 0; c2_i0 < 15; c2_i0++) {
      c2_mystr[c2_i0] = c2_cv0[c2_i0];
    }

    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
    c2_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
    for (c2_i1 = 0; c2_i1 < 15; c2_i1++) {
      c2_arr[c2_i1] = c2_dv0[c2_i1];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
    c2_ss = 15.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
    c2_padsize = c2_maxarrsize - c2_ss;
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
    for (c2_i2 = 0; c2_i2 < 256; c2_i2++) {
      c2_tt[c2_i2] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
    for (c2_i3 = 0; c2_i3 < 15; c2_i3++) {
      c2_tt[c2_i3] = c2_arr[c2_i3];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
    for (c2_i4 = 0; c2_i4 < 256; c2_i4++) {
      c2_myarr256[c2_i4] = c2_tt[c2_i4];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
    for (c2_i5 = 0; c2_i5 < 256; c2_i5++) {
      c2_arg[c2_i5] = c2_myarr256[c2_i5];
    }

    for (c2_i6 = 0; c2_i6 < 256; c2_i6++) {
      _SFD_DATA_RANGE_CHECK(c2_arg[c2_i6], 0U);
    }

    _SFD_SET_DATA_VALUE_PTR(0U, c2_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_g_sf_marshallOut,
      c2_e_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    for (c2_i7 = 0; c2_i7 < 256; c2_i7++) {
      (*c2_b_arg)[c2_i7] = c2_arg[c2_i7];
    }

    for (c2_i8 = 0; c2_i8 < 256; c2_i8++) {
      _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i8], 0U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectAllReceiverMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_testKinectAllReceiver
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
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

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i9;
  real_T c2_b_inData[256];
  int32_T c2_i10;
  real_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i9 = 0; c2_i9 < 256; c2_i9++) {
    c2_b_inData[c2_i9] = (*(real_T (*)[256])c2_inData)[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 256; c2_i10++) {
    c2_u[c2_i10] = c2_b_inData[c2_i10];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_b_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv1[256];
  int32_T c2_i11;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 256);
  for (c2_i11 = 0; c2_i11 < 256; c2_i11++) {
    c2_y[c2_i11] = c2_dv1[c2_i11];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_myarr256;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i12;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_myarr256 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_myarr256), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_myarr256);
  for (c2_i12 = 0; c2_i12 < 256; c2_i12++) {
    (*(real_T (*)[256])c2_outData)[c2_i12] = c2_y[c2_i12];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i13;
  char_T c2_b_inData[15];
  int32_T c2_i14;
  char_T c2_u[15];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i13 = 0; c2_i13 < 15; c2_i13++) {
    c2_b_inData[c2_i13] = (*(char_T (*)[15])c2_inData)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 15; c2_i14++) {
    c2_u[c2_i14] = c2_b_inData[c2_i14];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 15), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  real_T c2_b_inData[15];
  int32_T c2_i16;
  real_T c2_u[15];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i15 = 0; c2_i15 < 15; c2_i15++) {
    c2_b_inData[c2_i15] = (*(real_T (*)[15])c2_inData)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 15; c2_i16++) {
    c2_u[c2_i16] = c2_b_inData[c2_i16];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 15), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_testKinectAllReceiver_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
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

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i17;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i17, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i17;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_stateEnableReceiver, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_tp_stateEnableReceiver), &c2_thisId);
  sf_mex_destroy(&c2_b_tp_stateEnableReceiver);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
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

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_stateEnableReceiver;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_b_tp_stateEnableReceiver = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_tp_stateEnableReceiver), &c2_thisId);
  sf_mex_destroy(&c2_b_tp_stateEnableReceiver);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i18;
  real_T c2_b_inData[256];
  int32_T c2_i19;
  real_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i18 = 0; c2_i18 < 256; c2_i18++) {
    c2_b_inData[c2_i18] = (*(real_T (*)[256])c2_inData)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 256; c2_i19++) {
    c2_u[c2_i19] = c2_b_inData[c2_i19];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_testKinectAllReceiverInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv2[256];
  int32_T c2_i20;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c2_i20 = 0; c2_i20 < 256; c2_i20++) {
    c2_y[c2_i20] = c2_dv2[c2_i20];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_arg;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i21;
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)chartInstanceVoid;
  c2_arg = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_arg), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_arg);
  for (c2_i21 = 0; c2_i21 < 256; c2_i21++) {
    (*(real_T (*)[256])c2_outData)[c2_i21] = c2_y[c2_i21];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_testKinectAllReceiverInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_testKinectAllReceiverInstanceStruct
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

void sf_c2_testKinectAllReceiver_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2742482438U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3186818516U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(813029733U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2628580866U);
}

mxArray *sf_c2_testKinectAllReceiver_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3rxeGLeL9tppsTM01Slb8C");
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

mxArray *sf_c2_testKinectAllReceiver_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_testKinectAllReceiver_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_testKinectAllReceiver(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_testKinectAllReceiver\",},{M[9],M[0],T\"is_c2_testKinectAllReceiver\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_testKinectAllReceiver_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectAllReceiverMachineNumber_,
           2,
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
        init_script_number_translation(_testKinectAllReceiverMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectAllReceiverMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectAllReceiverMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(1,(void *)(NULL));
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectAllReceiverMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "LFMyX9inU7yxvOKUsJ6kzD";
}

static void sf_opaque_initialize_c2_testKinectAllReceiver(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_testKinectAllReceiver
    ((SFc2_testKinectAllReceiverInstanceStruct*) chartInstanceVar);
  initialize_c2_testKinectAllReceiver((SFc2_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_testKinectAllReceiver(void *chartInstanceVar)
{
  enable_c2_testKinectAllReceiver((SFc2_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_testKinectAllReceiver(void *chartInstanceVar)
{
  disable_c2_testKinectAllReceiver((SFc2_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_testKinectAllReceiver(void *chartInstanceVar)
{
  sf_gateway_c2_testKinectAllReceiver((SFc2_testKinectAllReceiverInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_testKinectAllReceiver
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_testKinectAllReceiver
    ((SFc2_testKinectAllReceiverInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_testKinectAllReceiver();/* state var info */
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

extern void sf_internal_set_sim_state_c2_testKinectAllReceiver(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_testKinectAllReceiver();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_testKinectAllReceiver
    ((SFc2_testKinectAllReceiverInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_testKinectAllReceiver(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_testKinectAllReceiver(S);
}

static void sf_opaque_set_sim_state_c2_testKinectAllReceiver(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_testKinectAllReceiver(S, st);
}

static void sf_opaque_terminate_c2_testKinectAllReceiver(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_testKinectAllReceiverInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectAllReceiver_optimization_info();
    }

    finalize_c2_testKinectAllReceiver((SFc2_testKinectAllReceiverInstanceStruct*)
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
  initSimStructsc2_testKinectAllReceiver
    ((SFc2_testKinectAllReceiverInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_testKinectAllReceiver(SimStruct *S)
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
    initialize_params_c2_testKinectAllReceiver
      ((SFc2_testKinectAllReceiverInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_testKinectAllReceiver(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectAllReceiver_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,2,2);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1099632708U));
  ssSetChecksum1(S,(3393831249U));
  ssSetChecksum2(S,(3492499369U));
  ssSetChecksum3(S,(2146473594U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_testKinectAllReceiver(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_testKinectAllReceiver(SimStruct *S)
{
  SFc2_testKinectAllReceiverInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_testKinectAllReceiverInstanceStruct *)utMalloc(sizeof
    (SFc2_testKinectAllReceiverInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_testKinectAllReceiverInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_testKinectAllReceiver;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_testKinectAllReceiver;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_testKinectAllReceiver;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_testKinectAllReceiver;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_testKinectAllReceiver;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_testKinectAllReceiver;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_testKinectAllReceiver;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_testKinectAllReceiver;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_testKinectAllReceiver;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_testKinectAllReceiver;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_testKinectAllReceiver;
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

void c2_testKinectAllReceiver_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_testKinectAllReceiver(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_testKinectAllReceiver(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_testKinectAllReceiver(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_testKinectAllReceiver_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
