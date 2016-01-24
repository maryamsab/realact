/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_All2_sfun.h"
#include "c35_Expriment_All2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_All2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c35_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c35_IN_stateCreatePawn         ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c35_debug_family_names[2] = { "nargin", "nargout" };

static const char * c35_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance);
static void initialize_params_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance);
static void enable_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance);
static void disable_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance);
static void set_sim_state_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c35_st);
static void c35_set_sim_state_side_effects_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance);
static void finalize_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance);
static void sf_gateway_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance);
static void initSimStructsc35_Expriment_All2(SFc35_Expriment_All2InstanceStruct *
  chartInstance);
static void c35_enter_atomic_stateCreatePawn(SFc35_Expriment_All2InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_b_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[1000]);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_info_helper(const mxArray **c35_info);
static const mxArray *c35_emlrt_marshallOut(const char * c35_u);
static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u);
static void c35_sendSBM(SFc35_Expriment_All2InstanceStruct *chartInstance,
  real_T c35_In2[1000]);
static const mxArray *c35_e_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_c_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_f_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static uint8_T c35_d_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_b_tp_stateCreatePawn, const char_T
  *c35_identifier);
static uint8_T c35_e_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_g_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_f_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[1000]);
static void c35_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_g_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c35_b_setSimStateSideEffectsInfo, const char_T
  *c35_identifier);
static const mxArray *c35_h_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void init_dsm_address_info(SFc35_Expriment_All2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c35_doSetSimStateSideEffects = 0U;
  chartInstance->c35_setSimStateSideEffectsInfo = NULL;
  chartInstance->c35_tp_stateCreatePawn = 0U;
  chartInstance->c35_is_active_c35_Expriment_All2 = 0U;
  chartInstance->c35_is_c35_Expriment_All2 = c35_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void disable_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static void c35_update_debugger_state_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance)
{
  uint32_T c35_prevAniVal;
  c35_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c35_is_active_c35_Expriment_All2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 16U, chartInstance->c35_sfEvent);
  }

  if (chartInstance->c35_is_c35_Expriment_All2 == c35_IN_stateCreatePawn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c35_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c35_sfEvent);
  }

  _SFD_SET_ANIMATION(c35_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  uint8_T c35_hoistedGlobal;
  uint8_T c35_u;
  const mxArray *c35_b_y = NULL;
  uint8_T c35_b_hoistedGlobal;
  uint8_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellmatrix(2, 1), false);
  c35_hoistedGlobal = chartInstance->c35_is_active_c35_Expriment_All2;
  c35_u = c35_hoistedGlobal;
  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", &c35_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_b_hoistedGlobal = chartInstance->c35_is_c35_Expriment_All2;
  c35_b_u = c35_b_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  sf_mex_assign(&c35_st, c35_y, false);
  return c35_st;
}

static void set_sim_state_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  c35_u = sf_mex_dup(c35_st);
  chartInstance->c35_is_active_c35_Expriment_All2 = c35_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 0)),
     "is_active_c35_Expriment_All2");
  chartInstance->c35_is_c35_Expriment_All2 = c35_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 1)),
     "is_c35_Expriment_All2");
  sf_mex_assign(&chartInstance->c35_setSimStateSideEffectsInfo,
                c35_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c35_u);
  chartInstance->c35_doSetSimStateSideEffects = 1U;
  c35_update_debugger_state_c35_Expriment_All2(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void c35_set_sim_state_side_effects_c35_Expriment_All2
  (SFc35_Expriment_All2InstanceStruct *chartInstance)
{
  if (chartInstance->c35_doSetSimStateSideEffects != 0) {
    if (chartInstance->c35_is_c35_Expriment_All2 == c35_IN_stateCreatePawn) {
      chartInstance->c35_tp_stateCreatePawn = 1U;
    } else {
      chartInstance->c35_tp_stateCreatePawn = 0U;
    }

    chartInstance->c35_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c35_setSimStateSideEffectsInfo);
}

static void sf_gateway_c35_Expriment_All2(SFc35_Expriment_All2InstanceStruct
  *chartInstance)
{
  c35_set_sim_state_side_effects_c35_Expriment_All2(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c35_sfEvent);
  chartInstance->c35_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c35_sfEvent);
  if (chartInstance->c35_is_active_c35_Expriment_All2 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 16U, chartInstance->c35_sfEvent);
    chartInstance->c35_is_active_c35_Expriment_All2 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c35_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c35_sfEvent);
    chartInstance->c35_is_c35_Expriment_All2 = c35_IN_stateCreatePawn;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c35_sfEvent);
    chartInstance->c35_tp_stateCreatePawn = 1U;
    c35_enter_atomic_stateCreatePawn(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c35_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c35_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c35_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_All2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc35_Expriment_All2(SFc35_Expriment_All2InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c35_enter_atomic_stateCreatePawn(SFc35_Expriment_All2InstanceStruct *
  chartInstance)
{
  uint32_T c35_debug_family_var_map[2];
  real_T c35_nargin = 0.0;
  real_T c35_nargout = 0.0;
  uint32_T c35_b_debug_family_var_map[9];
  real_T c35_maxarrsize;
  real_T c35_arr[58];
  real_T c35_ss;
  real_T c35_padsize;
  real_T c35_tt[1000];
  char_T c35_mystr[58];
  real_T c35_b_nargin = 1.0;
  real_T c35_b_nargout = 1.0;
  real_T c35_myarr256[1000];
  int32_T c35_i0;
  static char_T c35_cv0[58] = { 's', 'c', 'e', 'n', 'e', '.', 'g', 'e', 't', 'P',
    'a', 'w', 'n', '(', '\\', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\\', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 'i', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'V', 'e', 'c', '(', '0', ',', '1', '.', '6', ',', '1',
    '0', ')', ')' };

  int32_T c35_i1;
  static real_T c35_dv0[58] = { 115.0, 99.0, 101.0, 110.0, 101.0, 46.0, 103.0,
    101.0, 116.0, 80.0, 97.0, 119.0, 110.0, 40.0, 92.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 92.0, 34.0, 41.0, 46.0, 115.0,
    101.0, 116.0, 80.0, 111.0, 115.0, 105.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 86.0, 101.0, 99.0, 40.0, 48.0, 44.0, 49.0, 46.0, 54.0, 44.0,
    49.0, 48.0, 41.0, 41.0 };

  int32_T c35_i2;
  int32_T c35_i3;
  int32_T c35_i4;
  int32_T c35_i5;
  real_T c35_b_myarr256[1000];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 0U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 1U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c35_b_debug_family_names,
    c35_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_maxarrsize, 0U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_arr, 1U, c35_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_ss, 2U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_padsize, 3U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_tt, 4U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_mystr, 5U, c35_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_b_nargin, 6U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_b_nargout, 7U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_myarr256, 8U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  for (c35_i0 = 0; c35_i0 < 58; c35_i0++) {
    c35_mystr[c35_i0] = c35_cv0[c35_i0];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 4);
  c35_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 6);
  for (c35_i1 = 0; c35_i1 < 58; c35_i1++) {
    c35_arr[c35_i1] = c35_dv0[c35_i1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 7);
  c35_ss = 58.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 8);
  c35_padsize = c35_maxarrsize - c35_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 9);
  for (c35_i2 = 0; c35_i2 < 1000; c35_i2++) {
    c35_tt[c35_i2] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 10);
  for (c35_i3 = 0; c35_i3 < 58; c35_i3++) {
    c35_tt[c35_i3] = c35_arr[c35_i3];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, 11);
  for (c35_i4 = 0; c35_i4 < 1000; c35_i4++) {
    c35_myarr256[c35_i4] = c35_tt[c35_i4];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c35_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i5 = 0; c35_i5 < 1000; c35_i5++) {
    c35_b_myarr256[c35_i5] = c35_myarr256[c35_i5];
  }

  c35_sendSBM(chartInstance, c35_b_myarr256);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber)
{
  (void)c35_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c35_chartNumber, c35_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\28-12-2015-Matlab\\encStr2Arr.m"));
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static real_T c35_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_nargout;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_nargout = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_nargout),
    &c35_thisId);
  sf_mex_destroy(&c35_nargout);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i6;
  real_T c35_b_inData[1000];
  int32_T c35_i7;
  real_T c35_u[1000];
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i6 = 0; c35_i6 < 1000; c35_i6++) {
    c35_b_inData[c35_i6] = (*(real_T (*)[1000])c35_inData)[c35_i6];
  }

  for (c35_i7 = 0; c35_i7 < 1000; c35_i7++) {
    c35_u[c35_i7] = c35_b_inData[c35_i7];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_b_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[1000])
{
  real_T c35_dv1[1000];
  int32_T c35_i8;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv1, 1, 0, 0U, 1, 0U, 1,
                1000);
  for (c35_i8 = 0; c35_i8 < 1000; c35_i8++) {
    c35_y[c35_i8] = c35_dv1[c35_i8];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_myarr256;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[1000];
  int32_T c35_i9;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_myarr256 = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_myarr256), &c35_thisId,
    c35_y);
  sf_mex_destroy(&c35_myarr256);
  for (c35_i9 = 0; c35_i9 < 1000; c35_i9++) {
    (*(real_T (*)[1000])c35_outData)[c35_i9] = c35_y[c35_i9];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i10;
  char_T c35_b_inData[58];
  int32_T c35_i11;
  char_T c35_u[58];
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i10 = 0; c35_i10 < 58; c35_i10++) {
    c35_b_inData[c35_i10] = (*(char_T (*)[58])c35_inData)[c35_i10];
  }

  for (c35_i11 = 0; c35_i11 < 58; c35_i11++) {
    c35_u[c35_i11] = c35_b_inData[c35_i11];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 58),
                false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i12;
  real_T c35_b_inData[58];
  int32_T c35_i13;
  real_T c35_u[58];
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i12 = 0; c35_i12 < 58; c35_i12++) {
    c35_b_inData[c35_i12] = (*(real_T (*)[58])c35_inData)[c35_i12];
  }

  for (c35_i13 = 0; c35_i13 < 58; c35_i13++) {
    c35_u[c35_i13] = c35_b_inData[c35_i13];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 58), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

const mxArray *sf_c35_Expriment_All2_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  sf_mex_assign(&c35_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c35_info_helper(&c35_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(const mxArray **c35_info)
{
  const mxArray *c35_rhs0 = NULL;
  const mxArray *c35_lhs0 = NULL;
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/28-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c35_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c35_rhs0);
  sf_mex_destroy(&c35_lhs0);
}

static const mxArray *c35_emlrt_marshallOut(const char * c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c35_u)), false);
  return c35_y;
}

static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 7, 0U, 0U, 0U, 0), false);
  return c35_y;
}

static void c35_sendSBM(SFc35_Expriment_All2InstanceStruct *chartInstance,
  real_T c35_In2[1000])
{
  int32_T c35_i14;
  int32_T c35_i15;
  int32_T c35_i16;
  real_T (*c35_b_In2)[1000];
  c35_b_In2 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c35_i14 = 0; c35_i14 < 1000; c35_i14++) {
    _SFD_DATA_RANGE_CHECK(c35_In2[c35_i14], 0U);
  }

  _SFD_SET_DATA_VALUE_PTR(0U, c35_In2);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c35_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In2", c35_In2, c35_g_sf_marshallOut,
    c35_e_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c35_sfEvent);
  for (c35_i15 = 0; c35_i15 < 1000; c35_i15++) {
    (*c35_b_In2)[c35_i15] = c35_In2[c35_i15];
  }

  for (c35_i16 = 0; c35_i16 < 1000; c35_i16++) {
    _SFD_DATA_RANGE_CHECK((*c35_b_In2)[c35_i16], 0U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c35_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(0U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c35_sfEvent);
}

static const mxArray *c35_e_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static int32_T c35_c_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i17;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i17, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i17;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_f_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  uint8_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(uint8_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static uint8_T c35_d_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_b_tp_stateCreatePawn, const char_T
  *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_tp_stateCreatePawn), &c35_thisId);
  sf_mex_destroy(&c35_b_tp_stateCreatePawn);
  return c35_y;
}

static uint8_T c35_e_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_tp_stateCreatePawn;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  uint8_T c35_y;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_b_tp_stateCreatePawn = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_tp_stateCreatePawn), &c35_thisId);
  sf_mex_destroy(&c35_b_tp_stateCreatePawn);
  *(uint8_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_g_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i18;
  real_T c35_b_inData[1000];
  int32_T c35_i19;
  real_T c35_u[1000];
  const mxArray *c35_y = NULL;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i18 = 0; c35_i18 < 1000; c35_i18++) {
    c35_b_inData[c35_i18] = (*(real_T (*)[1000])c35_inData)[c35_i18];
  }

  for (c35_i19 = 0; c35_i19 < 1000; c35_i19++) {
    c35_u[c35_i19] = c35_b_inData[c35_i19];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_f_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[1000])
{
  real_T c35_dv2[1000];
  int32_T c35_i20;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv2, 1, 0, 0U, 1, 0U, 2,
                1000, 1);
  for (c35_i20 = 0; c35_i20 < 1000; c35_i20++) {
    c35_y[c35_i20] = c35_dv2[c35_i20];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_In2;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[1000];
  int32_T c35_i21;
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)chartInstanceVoid;
  c35_In2 = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_In2), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_In2);
  for (c35_i21 = 0; c35_i21 < 1000; c35_i21++) {
    (*(real_T (*)[1000])c35_outData)[c35_i21] = c35_y[c35_i21];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_g_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c35_b_setSimStateSideEffectsInfo, const char_T
  *c35_identifier)
{
  const mxArray *c35_y = NULL;
  emlrtMsgIdentifier c35_thisId;
  c35_y = NULL;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  sf_mex_assign(&c35_y, c35_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_setSimStateSideEffectsInfo), &c35_thisId), false);
  sf_mex_destroy(&c35_b_setSimStateSideEffectsInfo);
  return c35_y;
}

static const mxArray *c35_h_emlrt_marshallIn(SFc35_Expriment_All2InstanceStruct *
  chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  const mxArray *c35_y = NULL;
  (void)chartInstance;
  (void)c35_parentId;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_duplicatearraysafe(&c35_u), false);
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void init_dsm_address_info(SFc35_Expriment_All2InstanceStruct
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

void sf_c35_Expriment_All2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2684936576U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3480711118U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2730102659U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3691122099U);
}

mxArray *sf_c35_Expriment_All2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gmHZYixc2ddsg0UFuGrrHC");
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

mxArray *sf_c35_Expriment_All2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c35_Expriment_All2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c35_Expriment_All2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c35_Expriment_All2\",},{M[9],M[0],T\"is_c35_Expriment_All2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_Expriment_All2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_Expriment_All2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc35_Expriment_All2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_All2MachineNumber_,
           35,
           2,
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
        init_script_number_translation(_Expriment_All2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_All2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_All2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,8,0,0,"");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_g_sf_marshallOut,(MexInFcnForType)
            c35_e_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0,(void *)(NULL));
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_All2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tJuDfgpll5BrF182OjlB8E";
}

static void sf_opaque_initialize_c35_Expriment_All2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar);
  initialize_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_Expriment_All2(void *chartInstanceVar)
{
  enable_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c35_Expriment_All2(void *chartInstanceVar)
{
  disable_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_Expriment_All2(void *chartInstanceVar)
{
  sf_gateway_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c35_Expriment_All2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c35_Expriment_All2
    ((SFc35_Expriment_All2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_Expriment_All2();/* state var info */
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

extern void sf_internal_set_sim_state_c35_Expriment_All2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c35_Expriment_All2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c35_Expriment_All2(SimStruct* S)
{
  return sf_internal_get_sim_state_c35_Expriment_All2(S);
}

static void sf_opaque_set_sim_state_c35_Expriment_All2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c35_Expriment_All2(S, st);
}

static void sf_opaque_terminate_c35_Expriment_All2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_Expriment_All2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_All2_optimization_info();
    }

    finalize_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
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
  initSimStructsc35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_Expriment_All2(SimStruct *S)
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
    initialize_params_c35_Expriment_All2((SFc35_Expriment_All2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_Expriment_All2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_All2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,35,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,35);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,35,1);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3926232517U));
  ssSetChecksum1(S,(474351385U));
  ssSetChecksum2(S,(1162358669U));
  ssSetChecksum3(S,(2501123835U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_Expriment_All2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c35_Expriment_All2(SimStruct *S)
{
  SFc35_Expriment_All2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc35_Expriment_All2InstanceStruct *)utMalloc(sizeof
    (SFc35_Expriment_All2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_Expriment_All2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_Expriment_All2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_Expriment_All2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_Expriment_All2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_Expriment_All2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_Expriment_All2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_Expriment_All2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_Expriment_All2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_Expriment_All2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_Expriment_All2;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_Expriment_All2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c35_Expriment_All2;
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

void c35_Expriment_All2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_Expriment_All2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_Expriment_All2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_Expriment_All2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_Expriment_All2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
