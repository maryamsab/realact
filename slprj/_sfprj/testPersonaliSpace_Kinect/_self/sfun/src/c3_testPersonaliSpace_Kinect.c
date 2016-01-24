/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testPersonaliSpace_Kinect_sfun.h"
#include "c3_testPersonaliSpace_Kinect.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testPersonaliSpace_Kinect_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_init                     ((uint8_T)1U)
#define c3_IN_stateGoBack              ((uint8_T)2U)
#define c3_IN_stateGoForward           ((uint8_T)3U)
#define c3_IN_stateGoMiddle            ((uint8_T)4U)
#define c3_const_BACK                  (0.0)
#define c3_const_FORWARD               (0.0)
#define c3_const_MIDDLE                (0.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void initialize_params_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void enable_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void disable_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void set_sim_state_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void c3_set_sim_state_side_effects_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void finalize_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void sf_gateway_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void c3_chartstep_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void initSimStructsc3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void c3_enter_atomic_stateGoMiddle
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void c3_enter_atomic_stateGoBack
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void c3_enter_atomic_stateGoForward
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_b_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static void c3_sendBML(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, real_T c3_arg[256]);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_d_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_b_tp_init, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_h_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_init = 0U;
  chartInstance->c3_tp_stateGoBack = 0U;
  chartInstance->c3_tp_stateGoForward = 0U;
  chartInstance->c3_tp_stateGoMiddle = 0U;
  chartInstance->c3_is_active_c3_testPersonaliSpace_Kinect = 0U;
  chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_BACK = 0.0;
  chartInstance->c3_FORWARD = 0.0;
  chartInstance->c3_MIDDLE = 0.0;
}

static void initialize_params_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void disable_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static void c3_update_debugger_state_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_testPersonaliSpace_Kinect == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_stateGoMiddle)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_stateGoBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_stateGoForward)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(2, 1), false);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_testPersonaliSpace_Kinect;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_c3_testPersonaliSpace_Kinect;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_is_active_c3_testPersonaliSpace_Kinect =
    c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "is_active_c3_testPersonaliSpace_Kinect");
  chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_c3_testPersonaliSpace_Kinect");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_testPersonaliSpace_Kinect(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_init) {
      chartInstance->c3_tp_init = 1U;
    } else {
      chartInstance->c3_tp_init = 0U;
    }

    if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_stateGoBack)
    {
      chartInstance->c3_tp_stateGoBack = 1U;
    } else {
      chartInstance->c3_tp_stateGoBack = 0U;
    }

    if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect ==
        c3_IN_stateGoForward) {
      chartInstance->c3_tp_stateGoForward = 1U;
    } else {
      chartInstance->c3_tp_stateGoForward = 0U;
    }

    if (chartInstance->c3_is_c3_testPersonaliSpace_Kinect == c3_IN_stateGoMiddle)
    {
      chartInstance->c3_tp_stateGoMiddle = 1U;
    } else {
      chartInstance->c3_tp_stateGoMiddle = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  real_T *c3_invaded;
  c3_invaded = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_testPersonaliSpace_Kinect(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_invaded, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_BACK, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_FORWARD, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_MIDDLE, 3U);
  chartInstance->c3_sfEvent = c3_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  c3_chartstep_c3_testPersonaliSpace_Kinect(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testPersonaliSpace_KinectMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_h_out;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_i_out;
  real_T *c3_invaded;
  c3_invaded = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_testPersonaliSpace_Kinect == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_testPersonaliSpace_Kinect = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_init = 1U;
  } else {
    switch (chartInstance->c3_is_c3_testPersonaliSpace_Kinect) {
     case c3_IN_init:
      CV_CHART_EVAL(2, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_i_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_out = CV_EML_IF(5, 0, 0, *c3_invaded == (real_T)(int32_T)
                         invadeStandingSpots_MIDDLE);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_init = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_stateGoMiddle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoMiddle = 1U;
        c3_enter_atomic_stateGoMiddle(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_i_sf_marshallOut,
          c3_c_sf_marshallIn);
        c3_b_out = CV_EML_IF(6, 0, 0, *c3_invaded == (real_T)(int32_T)
                             invadeStandingSpots_BACK);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_init = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_stateGoBack;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoBack = 1U;
          c3_enter_atomic_stateGoBack(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U,
            c3_i_sf_marshallOut, c3_c_sf_marshallIn);
          c3_c_out = CV_EML_IF(7, 0, 0, *c3_invaded == (real_T)(int32_T)
                               invadeStandingSpots_FORWARD);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_init = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_c3_testPersonaliSpace_Kinect =
              c3_IN_stateGoForward;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_stateGoForward = 1U;
            c3_enter_atomic_stateGoForward(chartInstance);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                         chartInstance->c3_sfEvent);
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateGoBack:
      CV_CHART_EVAL(2, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_i_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_d_out = CV_EML_IF(2, 0, 0, *c3_invaded == (real_T)(int32_T)
                           invadeStandingSpots_MIDDLE);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoBack = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_stateGoMiddle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoMiddle = 1U;
        c3_enter_atomic_stateGoMiddle(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_i_sf_marshallOut,
          c3_c_sf_marshallIn);
        c3_e_out = CV_EML_IF(9, 0, 0, *c3_invaded == (real_T)(int32_T)
                             invadeStandingSpots_FORWARD);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoBack = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testPersonaliSpace_Kinect =
            c3_IN_stateGoForward;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoForward = 1U;
          c3_enter_atomic_stateGoForward(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateGoForward:
      CV_CHART_EVAL(2, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_i_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_f_out = CV_EML_IF(4, 0, 0, *c3_invaded == (real_T)(int32_T)
                           invadeStandingSpots_MIDDLE);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoForward = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_stateGoMiddle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoMiddle = 1U;
        c3_enter_atomic_stateGoMiddle(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U, c3_i_sf_marshallOut,
          c3_c_sf_marshallIn);
        c3_g_out = CV_EML_IF(8, 0, 0, *c3_invaded == (real_T)(int32_T)
                             invadeStandingSpots_BACK);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoForward = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_stateGoBack;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoBack = 1U;
          c3_enter_atomic_stateGoBack(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateGoMiddle:
      CV_CHART_EVAL(2, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U, c3_i_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_h_out = CV_EML_IF(1, 0, 0, *c3_invaded == (real_T)(int32_T)
                           invadeStandingSpots_BACK);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoMiddle = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_stateGoBack;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateGoBack = 1U;
        c3_enter_atomic_stateGoBack(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U, c3_i_sf_marshallOut,
          c3_c_sf_marshallIn);
        c3_i_out = CV_EML_IF(3, 0, 0, *c3_invaded == (real_T)(int32_T)
                             invadeStandingSpots_FORWARD);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoMiddle = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testPersonaliSpace_Kinect =
            c3_IN_stateGoForward;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateGoForward = 1U;
          c3_enter_atomic_stateGoForward(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(2, 0, 0);
      chartInstance->c3_is_c3_testPersonaliSpace_Kinect = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_testPersonaliSpace_Kinect
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_atomic_stateGoMiddle
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[137];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[137];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i0;
  static char_T c3_cv0[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i1;
  static real_T c3_dv0[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  real_T c3_b_myarr256[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_b_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i0 = 0; c3_i0 < 137; c3_i0++) {
    c3_mystr[c3_i0] = c3_cv0[c3_i0];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i1 = 0; c3_i1 < 137; c3_i1++) {
    c3_arr[c3_i1] = c3_dv0[c3_i1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i2 = 0; c3_i2 < 256; c3_i2++) {
    c3_tt[c3_i2] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i3 = 0; c3_i3 < 137; c3_i3++) {
    c3_tt[c3_i3] = c3_arr[c3_i3];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i4 = 0; c3_i4 < 256; c3_i4++) {
    c3_myarr256[c3_i4] = c3_tt[c3_i4];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i5 = 0; c3_i5 < 256; c3_i5++) {
    c3_b_myarr256[c3_i5] = c3_myarr256[c3_i5];
  }

  c3_sendBML(chartInstance, c3_b_myarr256);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_stateGoBack
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[140];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[140];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i6;
  static char_T c3_cv1[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=', '\"',
    '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't', 'a',
    'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 'f', 'a', 'c', 'i', 'n',
    'g', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '-', '0', '.', '7', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i7;
  static real_T c3_dv1[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 32.0, 115.0, 98.0, 109.0, 58.0, 97.0, 99.0,
    99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0, 99.0, 99.0, 101.0,
    108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0,
    103.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 45.0, 48.0, 46.0,
    55.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  real_T c3_b_myarr256[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_d_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i6 = 0; c3_i6 < 140; c3_i6++) {
    c3_mystr[c3_i6] = c3_cv1[c3_i6];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i7 = 0; c3_i7 < 140; c3_i7++) {
    c3_arr[c3_i7] = c3_dv1[c3_i7];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i8 = 0; c3_i8 < 256; c3_i8++) {
    c3_tt[c3_i8] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i9 = 0; c3_i9 < 140; c3_i9++) {
    c3_tt[c3_i9] = c3_arr[c3_i9];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i10 = 0; c3_i10 < 256; c3_i10++) {
    c3_myarr256[c3_i10] = c3_tt[c3_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i11 = 0; c3_i11 < 256; c3_i11++) {
    c3_b_myarr256[c3_i11] = c3_myarr256[c3_i11];
  }

  c3_sendBML(chartInstance, c3_b_myarr256);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_stateGoForward
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[139];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[139];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i12;
  static char_T c3_cv2[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '0', '.', '7', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i13;
  static real_T c3_dv2[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 46.0, 55.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  real_T c3_b_myarr256[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_f_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i12 = 0; c3_i12 < 139; c3_i12++) {
    c3_mystr[c3_i12] = c3_cv2[c3_i12];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i13 = 0; c3_i13 < 139; c3_i13++) {
    c3_arr[c3_i13] = c3_dv2[c3_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i14 = 0; c3_i14 < 256; c3_i14++) {
    c3_tt[c3_i14] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i15 = 0; c3_i15 < 139; c3_i15++) {
    c3_tt[c3_i15] = c3_arr[c3_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i16 = 0; c3_i16 < 256; c3_i16++) {
    c3_myarr256[c3_i16] = c3_tt[c3_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i17 = 0; c3_i17 < 256; c3_i17++) {
    c3_b_myarr256[c3_i17] = c3_myarr256[c3_i17];
  }

  c3_sendBML(chartInstance, c3_b_myarr256);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\4-6-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
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

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i18;
  real_T c3_b_inData[256];
  int32_T c3_i19;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i18 = 0; c3_i18 < 256; c3_i18++) {
    c3_b_inData[c3_i18] = (*(real_T (*)[256])c3_inData)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 256; c3_i19++) {
    c3_u[c3_i19] = c3_b_inData[c3_i19];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_b_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv3[256];
  int32_T c3_i20;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i20 = 0; c3_i20 < 256; c3_i20++) {
    c3_y[c3_i20] = c3_dv3[c3_i20];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i21;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i21 = 0; c3_i21 < 256; c3_i21++) {
    (*(real_T (*)[256])c3_outData)[c3_i21] = c3_y[c3_i21];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i22;
  char_T c3_b_inData[137];
  int32_T c3_i23;
  char_T c3_u[137];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i22 = 0; c3_i22 < 137; c3_i22++) {
    c3_b_inData[c3_i22] = (*(char_T (*)[137])c3_inData)[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 137; c3_i23++) {
    c3_u[c3_i23] = c3_b_inData[c3_i23];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i24;
  real_T c3_b_inData[137];
  int32_T c3_i25;
  real_T c3_u[137];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i24 = 0; c3_i24 < 137; c3_i24++) {
    c3_b_inData[c3_i24] = (*(real_T (*)[137])c3_inData)[c3_i24];
  }

  for (c3_i25 = 0; c3_i25 < 137; c3_i25++) {
    c3_u[c3_i25] = c3_b_inData[c3_i25];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i26;
  char_T c3_b_inData[140];
  int32_T c3_i27;
  char_T c3_u[140];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i26 = 0; c3_i26 < 140; c3_i26++) {
    c3_b_inData[c3_i26] = (*(char_T (*)[140])c3_inData)[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 140; c3_i27++) {
    c3_u[c3_i27] = c3_b_inData[c3_i27];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i28;
  real_T c3_b_inData[140];
  int32_T c3_i29;
  real_T c3_u[140];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i28 = 0; c3_i28 < 140; c3_i28++) {
    c3_b_inData[c3_i28] = (*(real_T (*)[140])c3_inData)[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 140; c3_i29++) {
    c3_u[c3_i29] = c3_b_inData[c3_i29];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i30;
  char_T c3_b_inData[139];
  int32_T c3_i31;
  char_T c3_u[139];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i30 = 0; c3_i30 < 139; c3_i30++) {
    c3_b_inData[c3_i30] = (*(char_T (*)[139])c3_inData)[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 139; c3_i31++) {
    c3_u[c3_i31] = c3_b_inData[c3_i31];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i32;
  real_T c3_b_inData[139];
  int32_T c3_i33;
  real_T c3_u[139];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i32 = 0; c3_i32 < 139; c3_i32++) {
    c3_b_inData[c3_i32] = (*(real_T (*)[139])c3_inData)[c3_i32];
  }

  for (c3_i33 = 0; c3_i33 < 139; c3_i33++) {
    c3_u[c3_i33] = c3_b_inData[c3_i33];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_testPersonaliSpace_Kinect_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("invadeStandingSpots"), "name",
                  "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[N]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/invadeStandingSpots.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1434669350U), "fileTimeLo",
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
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
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

static void c3_sendBML(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, real_T c3_arg[256])
{
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c3_i34 = 0; c3_i34 < 256; c3_i34++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i34], 4U);
  }

  _SFD_SET_DATA_VALUE_PTR(4U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_m_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i35 = 0; c3_i35 < 256; c3_i35++) {
    (*c3_b_arg)[c3_i35] = c3_arg[c3_i35];
  }

  for (c3_i36 = 0; c3_i36 < 256; c3_i36++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i36], 4U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(4U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_d_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i37;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i37, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i37;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_secs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_secs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_secs), &c3_thisId);
  sf_mex_destroy(&c3_secs);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i38;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i38, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i38;
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
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_b_tp_init, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_init),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_init);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_init;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_b_tp_init = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_init),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_init);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i39;
  real_T c3_b_inData[256];
  int32_T c3_i40;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i39 = 0; c3_i39 < 256; c3_i39++) {
    c3_b_inData[c3_i39] = (*(real_T (*)[256])c3_inData)[c3_i39];
  }

  for (c3_i40 = 0; c3_i40 < 256; c3_i40++) {
    c3_u[c3_i40] = c3_b_inData[c3_i40];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_h_emlrt_marshallIn(SFc3_testPersonaliSpace_KinectInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv4[256];
  int32_T c3_i41;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv4, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c3_i41 = 0; c3_i41 < 256; c3_i41++) {
    c3_y[c3_i41] = c3_dv4[c3_i41];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arg;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i42;
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
    chartInstanceVoid;
  c3_arg = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arg), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arg);
  for (c3_i42 = 0; c3_i42 < 256; c3_i42++) {
    (*(real_T (*)[256])c3_outData)[c3_i42] = c3_y[c3_i42];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_testPersonaliSpace_KinectInstanceStruct
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

void sf_c3_testPersonaliSpace_Kinect_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2650758114U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1301047372U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2414352047U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1787776902U);
}

mxArray *sf_c3_testPersonaliSpace_Kinect_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("G8MQi7KKfpwgD5BZDBuMJG");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_testPersonaliSpace_Kinect_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_testPersonaliSpace_Kinect_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_testPersonaliSpace_Kinect(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_testPersonaliSpace_Kinect\",},{M[9],M[0],T\"is_c3_testPersonaliSpace_Kinect\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_testPersonaliSpace_Kinect_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testPersonaliSpace_KinectMachineNumber_,
           3,
           5,
           10,
           0,
           5,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testPersonaliSpace_KinectMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _testPersonaliSpace_KinectMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testPersonaliSpace_KinectMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"invaded");
          _SFD_SET_DATA_PROPS(1,7,0,0,"BACK");
          _SFD_SET_DATA_PROPS(2,7,0,0,"FORWARD");
          _SFD_SET_DATA_PROPS(3,7,0,0,"MIDDLE");
          _SFD_SET_DATA_PROPS(4,8,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,36,1,36);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,34,1,34);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,37,1,37);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,34,1,34);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,37,1,37);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,36,1,36);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,36,1,36);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,37,1,37);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,34,1,34);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_m_sf_marshallOut,(MexInFcnForType)
            c3_g_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));

        {
          real_T *c3_invaded;
          c3_invaded = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_invaded);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c3_BACK);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c3_FORWARD);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c3_MIDDLE);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testPersonaliSpace_KinectMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "SgJRddNap3xCREnB5UCpDG";
}

static void sf_opaque_initialize_c3_testPersonaliSpace_Kinect(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testPersonaliSpace_KinectInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
  initialize_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_testPersonaliSpace_Kinect(void *chartInstanceVar)
{
  enable_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_testPersonaliSpace_Kinect(void
  *chartInstanceVar)
{
  disable_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_testPersonaliSpace_Kinect(void
  *chartInstanceVar)
{
  sf_gateway_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_testPersonaliSpace_Kinect
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_testPersonaliSpace_Kinect();/* state var info */
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

extern void sf_internal_set_sim_state_c3_testPersonaliSpace_Kinect(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_testPersonaliSpace_Kinect();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_testPersonaliSpace_Kinect
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_testPersonaliSpace_Kinect(S);
}

static void sf_opaque_set_sim_state_c3_testPersonaliSpace_Kinect(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_testPersonaliSpace_Kinect(S, st);
}

static void sf_opaque_terminate_c3_testPersonaliSpace_Kinect(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testPersonaliSpace_KinectInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testPersonaliSpace_Kinect_optimization_info();
    }

    finalize_c3_testPersonaliSpace_Kinect
      ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_testPersonaliSpace_Kinect
    ((SFc3_testPersonaliSpace_KinectInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_testPersonaliSpace_Kinect(SimStruct *S)
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
    initialize_params_c3_testPersonaliSpace_Kinect
      ((SFc3_testPersonaliSpace_KinectInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_testPersonaliSpace_Kinect(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testPersonaliSpace_Kinect_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,3,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2288987664U));
  ssSetChecksum1(S,(1853821057U));
  ssSetChecksum2(S,(3802678156U));
  ssSetChecksum3(S,(3627769487U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_testPersonaliSpace_Kinect(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_testPersonaliSpace_Kinect(SimStruct *S)
{
  SFc3_testPersonaliSpace_KinectInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_testPersonaliSpace_KinectInstanceStruct *)utMalloc
    (sizeof(SFc3_testPersonaliSpace_KinectInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testPersonaliSpace_KinectInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_testPersonaliSpace_Kinect;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_testPersonaliSpace_Kinect;
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

void c3_testPersonaliSpace_Kinect_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_testPersonaliSpace_Kinect(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_testPersonaliSpace_Kinect(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_testPersonaliSpace_Kinect(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_testPersonaliSpace_Kinect_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
