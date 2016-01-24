/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectRPS_sfun.h"
#include "c3_testKinectRPS.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectRPS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_start                    ((uint8_T)1U)
#define c3_IN_stateBradWin             ((uint8_T)2U)
#define c3_IN_stateCompare             ((uint8_T)3U)
#define c3_IN_stateNoWin               ((uint8_T)4U)
#define c3_IN_statePlayHand            ((uint8_T)5U)
#define c3_IN_stateReadUserHand        ((uint8_T)6U)
#define c3_IN_stateShowGo              ((uint8_T)7U)
#define c3_IN_stateShowReady           ((uint8_T)8U)
#define c3_IN_stateShowResult          ((uint8_T)9U)
#define c3_IN_stateShowUserHand        ((uint8_T)10U)
#define c3_IN_stateUserWin             ((uint8_T)11U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void initialize_params_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct *
  chartInstance);
static void enable_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void disable_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_testKinectRPS
  (SFc3_testKinectRPSInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_testKinectRPS
  (SFc3_testKinectRPSInstanceStruct *chartInstance);
static void set_sim_state_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_testKinectRPS
  (SFc3_testKinectRPSInstanceStruct *chartInstance);
static void finalize_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void sf_gateway_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void initSimStructsc3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[256]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_b_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_bmlID, const char_T *c3_identifier);
static real_T c3_c_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_d_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
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
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_stateReadUserHand, const char_T
  *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint16_T c3_i_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_b_temporalCounter_i1, const char_T
  *c3_identifier);
static uint16_T c3_j_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_k_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_l_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_testKinectRPSInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_start = 0U;
  chartInstance->c3_tp_stateBradWin = 0U;
  chartInstance->c3_tp_stateCompare = 0U;
  chartInstance->c3_tp_stateNoWin = 0U;
  chartInstance->c3_tp_statePlayHand = 0U;
  chartInstance->c3_tp_stateReadUserHand = 0U;
  chartInstance->c3_tp_stateShowGo = 0U;
  chartInstance->c3_tp_stateShowReady = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateShowResult = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateShowUserHand = 0U;
  chartInstance->c3_tp_stateUserWin = 0U;
  chartInstance->c3_is_active_c3_testKinectRPS = 0U;
  chartInstance->c3_is_c3_testKinectRPS = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_bradHand = 0.0;
  chartInstance->c3_win = 0.0;
  chartInstance->c3_diff = 0.0;
  chartInstance->c3_userHand = 0.0;
  chartInstance->c3_temp = 0.0;
}

static void initialize_params_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void disable_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static void c3_update_debugger_state_c3_testKinectRPS
  (SFc3_testKinectRPSInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_testKinectRPS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_statePlayHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_testKinectRPS
  (SFc3_testKinectRPSInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint16_T c3_h_hoistedGlobal;
  uint16_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(8, 1), false);
  c3_hoistedGlobal = chartInstance->c3_bradHand;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_diff;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_temp;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_userHand;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_win;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_active_c3_testKinectRPS;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_c3_testKinectRPS;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_bradHand = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "bradHand");
  chartInstance->c3_diff = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "diff");
  chartInstance->c3_temp = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "temp");
  chartInstance->c3_userHand = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "userHand");
  chartInstance->c3_win = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "win");
  chartInstance->c3_is_active_c3_testKinectRPS = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
     "is_active_c3_testKinectRPS");
  chartInstance->c3_is_c3_testKinectRPS = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 6)), "is_c3_testKinectRPS");
  chartInstance->c3_temporalCounter_i1 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 7)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_testKinectRPS(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_testKinectRPS
  (SFc3_testKinectRPSInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_start) {
      chartInstance->c3_tp_start = 1U;
    } else {
      chartInstance->c3_tp_start = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateBradWin) {
      chartInstance->c3_tp_stateBradWin = 1U;
    } else {
      chartInstance->c3_tp_stateBradWin = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateCompare) {
      chartInstance->c3_tp_stateCompare = 1U;
    } else {
      chartInstance->c3_tp_stateCompare = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateNoWin) {
      chartInstance->c3_tp_stateNoWin = 1U;
    } else {
      chartInstance->c3_tp_stateNoWin = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_statePlayHand) {
      chartInstance->c3_tp_statePlayHand = 1U;
    } else {
      chartInstance->c3_tp_statePlayHand = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateReadUserHand) {
      chartInstance->c3_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c3_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowGo) {
      chartInstance->c3_tp_stateShowGo = 1U;
    } else {
      chartInstance->c3_tp_stateShowGo = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowReady) {
      chartInstance->c3_tp_stateShowReady = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateShowReady = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowResult) {
      chartInstance->c3_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateShowResult = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateShowUserHand) {
      chartInstance->c3_tp_stateShowUserHand = 1U;
    } else {
      chartInstance->c3_tp_stateShowUserHand = 0U;
    }

    if (chartInstance->c3_is_c3_testKinectRPS == c3_IN_stateUserWin) {
      chartInstance->c3_tp_stateUserWin = 1U;
    } else {
      chartInstance->c3_tp_stateUserWin = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance)
{
  real_T *c3_inputUser;
  c3_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_testKinectRPS(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_temporalCounter_i1 < 511U) {
    chartInstance->c3_temporalCounter_i1++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_inputUser, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_bradHand, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_win, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_diff, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_userHand, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_temp, 5U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_testKinectRPS(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectRPSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
  *chartInstance)
{
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_b_temp;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  boolean_T c3_f_out;
  boolean_T c3_c_temp;
  boolean_T c3_d_temp;
  boolean_T c3_g_out;
  boolean_T c3_e_temp;
  boolean_T c3_h_out;
  real_T *c3_inputUser;
  c3_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_testKinectRPS == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_testKinectRPS = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_testKinectRPS = c3_IN_start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_start = 1U;
  } else {
    switch (chartInstance->c3_is_c3_testKinectRPS) {
     case c3_IN_start:
      CV_CHART_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_start = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateShowReady = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateBradWin:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateBradWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateShowResult = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateCompare:
      CV_CHART_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      c3_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
                  chartInstance->c3_diff == 1.0 != 0U, chartInstance->c3_sfEvent))
                != 0);
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateBradWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateBradWin = 1U;
        chartInstance->c3_win = 2.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_win, 2U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c3_sfEvent);
        c3_b_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
          chartInstance->c3_diff == 2.0 != 0U, chartInstance->c3_sfEvent)) != 0);
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateCompare = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateUserWin;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateUserWin = 1U;
          chartInstance->c3_win = 1.0;
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_win, 2U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                       chartInstance->c3_sfEvent);
          c3_b_temp = (_SFD_CCP_CALL(14U, 0, chartInstance->c3_diff != 1.0 != 0U,
            chartInstance->c3_sfEvent) != 0);
          if (c3_b_temp) {
            c3_b_temp = (_SFD_CCP_CALL(14U, 1, chartInstance->c3_diff != 2.0 !=
              0U, chartInstance->c3_sfEvent) != 0);
          }

          c3_c_out = (CV_TRANSITION_EVAL(14U, (int32_T)c3_b_temp) != 0);
          if (c3_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_stateCompare = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateNoWin;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_stateNoWin = 1U;
            chartInstance->c3_win = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_win, 2U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                         chartInstance->c3_sfEvent);
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateNoWin:
      CV_CHART_EVAL(1, 0, 4);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateNoWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateShowResult = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_statePlayHand:
      CV_CHART_EVAL(1, 0, 5);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_statePlayHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateReadUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateReadUserHand = 1U;
      chartInstance->c3_userHand = *c3_inputUser;
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_userHand, 4U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateReadUserHand:
      CV_CHART_EVAL(1, 0, 6);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c3_sfEvent);
      c3_d_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
        chartInstance->c3_userHand != 3.0 != 0U, chartInstance->c3_sfEvent)) !=
                  0);
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowUserHand;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateShowUserHand = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c3_sfEvent);
        c3_e_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0,
          chartInstance->c3_userHand == 3.0 != 0U, chartInstance->c3_sfEvent))
                    != 0);
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateReadUserHand = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateReadUserHand;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateReadUserHand = 1U;
          chartInstance->c3_userHand = *c3_inputUser;
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_userHand, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateShowGo:
      CV_CHART_EVAL(1, 0, 7);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateShowGo = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_statePlayHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_statePlayHand = 1U;
      chartInstance->c3_bradHand = 1.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bradHand, 1U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateShowReady:
      CV_CHART_EVAL(1, 0, 8);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                   chartInstance->c3_sfEvent);
      c3_f_out = (CV_TRANSITION_EVAL(13U, (int32_T)_SFD_CCP_CALL(13U, 0,
        chartInstance->c3_userHand == 3.0 != 0U, chartInstance->c3_sfEvent)) !=
                  0);
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateShowReady = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateShowReady = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c3_sfEvent);
        c3_c_temp = (_SFD_CCP_CALL(2U, 0, 1 != 0U, chartInstance->c3_sfEvent) !=
                     0);
        if (c3_c_temp) {
          c3_c_temp = (_SFD_CCP_CALL(2U, 1, chartInstance->c3_temporalCounter_i1
            >= 30U != 0U, chartInstance->c3_sfEvent) != 0);
        }

        c3_d_temp = c3_c_temp;
        if (c3_d_temp) {
          c3_d_temp = (_SFD_CCP_CALL(2U, 2, chartInstance->c3_userHand != 3.0 !=
            0U, chartInstance->c3_sfEvent) != 0);
        }

        c3_g_out = (CV_TRANSITION_EVAL(2U, (int32_T)c3_d_temp) != 0);
        if (c3_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateShowReady = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowGo;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateShowGo = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateShowResult:
      CV_CHART_EVAL(1, 0, 9);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c3_sfEvent);
      c3_e_temp = (_SFD_CCP_CALL(10U, 0, 1 != 0U, chartInstance->c3_sfEvent) !=
                   0);
      if (c3_e_temp) {
        c3_e_temp = (_SFD_CCP_CALL(10U, 1, chartInstance->c3_temporalCounter_i1 >=
          500U != 0U, chartInstance->c3_sfEvent) != 0);
      }

      c3_h_out = (CV_TRANSITION_EVAL(10U, (int32_T)c3_e_temp) != 0);
      if (c3_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateShowReady = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateShowUserHand:
      CV_CHART_EVAL(1, 0, 10);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateShowUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateCompare;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateCompare = 1U;
      chartInstance->c3_temp = chartInstance->c3_userHand -
        chartInstance->c3_bradHand;
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_temp, 5U);
      chartInstance->c3_diff = chartInstance->c3_temp - 3. * muDoubleScalarFloor
        (chartInstance->c3_temp / 3.0);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_diff, 3U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateUserWin:
      CV_CHART_EVAL(1, 0, 11);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateUserWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateShowResult = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c3_is_c3_testKinectRPS = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_testKinectRPS(SFc3_testKinectRPSInstanceStruct
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
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i0;
  real_T c3_b_inData[256];
  int32_T c3_i1;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i0 = 0; c3_i0 < 256; c3_i0++) {
    c3_b_inData[c3_i0] = (*(real_T (*)[256])c3_inData)[c3_i0];
  }

  for (c3_i1 = 0; c3_i1 < 256; c3_i1++) {
    c3_u[c3_i1] = c3_b_inData[c3_i1];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[256])
{
  real_T c3_dv0[256];
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c3_i2 = 0; c3_i2 < 256; c3_i2++) {
    c3_y[c3_i2] = c3_dv0[c3_i2];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_poseBML;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i3;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_poseBML = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_poseBML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_poseBML);
  for (c3_i3 = 0; c3_i3 < 256; c3_i3++) {
    (*(real_T (*)[256])c3_outData)[c3_i3] = c3_y[c3_i3];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_b_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_bmlID, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_bmlID), &c3_thisId);
  sf_mex_destroy(&c3_bmlID);
  return c3_y;
}

static real_T c3_c_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
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
  const mxArray *c3_bmlID;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_bmlID = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_bmlID), &c3_thisId);
  sf_mex_destroy(&c3_bmlID);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
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
  const mxArray *c3_aVarTruthTableCondition_3;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_aVarTruthTableCondition_3 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_aVarTruthTableCondition_3), &c3_thisId);
  sf_mex_destroy(&c3_aVarTruthTableCondition_3);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i4;
  real_T c3_b_inData[256];
  int32_T c3_i5;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i4 = 0; c3_i4 < 256; c3_i4++) {
    c3_b_inData[c3_i4] = (*(real_T (*)[256])c3_inData)[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 256; c3_i5++) {
    c3_u[c3_i5] = c3_b_inData[c3_i5];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv1[256];
  int32_T c3_i6;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i6 = 0; c3_i6 < 256; c3_i6++) {
    c3_y[c3_i6] = c3_dv1[c3_i6];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i7;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i7 = 0; c3_i7 < 256; c3_i7++) {
    (*(real_T (*)[256])c3_outData)[c3_i7] = c3_y[c3_i7];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i8;
  char_T c3_b_inData[86];
  int32_T c3_i9;
  char_T c3_u[86];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i8 = 0; c3_i8 < 86; c3_i8++) {
    c3_b_inData[c3_i8] = (*(char_T (*)[86])c3_inData)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 86; c3_i9++) {
    c3_u[c3_i9] = c3_b_inData[c3_i9];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i10;
  real_T c3_b_inData[86];
  int32_T c3_i11;
  real_T c3_u[86];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i10 = 0; c3_i10 < 86; c3_i10++) {
    c3_b_inData[c3_i10] = (*(real_T (*)[86])c3_inData)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 86; c3_i11++) {
    c3_u[c3_i11] = c3_b_inData[c3_i11];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i12;
  char_T c3_b_inData[90];
  int32_T c3_i13;
  char_T c3_u[90];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i12 = 0; c3_i12 < 90; c3_i12++) {
    c3_b_inData[c3_i12] = (*(char_T (*)[90])c3_inData)[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 90; c3_i13++) {
    c3_u[c3_i13] = c3_b_inData[c3_i13];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 90), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i14;
  real_T c3_b_inData[90];
  int32_T c3_i15;
  real_T c3_u[90];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i14 = 0; c3_i14 < 90; c3_i14++) {
    c3_b_inData[c3_i14] = (*(real_T (*)[90])c3_inData)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 90; c3_i15++) {
    c3_u[c3_i15] = c3_b_inData[c3_i15];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 90), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i16;
  char_T c3_b_inData[94];
  int32_T c3_i17;
  char_T c3_u[94];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i16 = 0; c3_i16 < 94; c3_i16++) {
    c3_b_inData[c3_i16] = (*(char_T (*)[94])c3_inData)[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 94; c3_i17++) {
    c3_u[c3_i17] = c3_b_inData[c3_i17];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i18;
  real_T c3_b_inData[94];
  int32_T c3_i19;
  real_T c3_u[94];
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i18 = 0; c3_i18 < 94; c3_i18++) {
    c3_b_inData[c3_i18] = (*(real_T (*)[94])c3_inData)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 94; c3_i19++) {
    c3_u[c3_i19] = c3_b_inData[c3_i19];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_testKinectRPS_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
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

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i20;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i20, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i20;
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
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
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
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_stateReadUserHand, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_tp_stateReadUserHand), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_stateReadUserHand);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
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

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_stateReadUserHand;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)chartInstanceVoid;
  c3_b_tp_stateReadUserHand = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_tp_stateReadUserHand), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_stateReadUserHand);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint16_T c3_i_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_b_temporalCounter_i1, const char_T
  *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_temporalCounter_i1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_temporalCounter_i1);
  return c3_y;
}

static uint16_T c3_j_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_k_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_l_emlrt_marshallIn(SFc3_testKinectRPSInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_testKinectRPSInstanceStruct
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

void sf_c3_testKinectRPS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2264955498U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1278544893U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(683867674U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4269423617U);
}

mxArray *sf_c3_testKinectRPS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zYMrClcLAsQfvcNXJPmtPG");
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

mxArray *sf_c3_testKinectRPS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_testKinectRPS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_testKinectRPS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[3],M[39],T\"bradHand\",},{M[3],M[41],T\"diff\",},{M[3],M[46],T\"temp\",},{M[3],M[42],T\"userHand\",},{M[3],M[40],T\"win\",},{M[8],M[0],T\"is_active_c3_testKinectRPS\",},{M[9],M[0],T\"is_c3_testKinectRPS\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[4 6],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_testKinectRPS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testKinectRPSInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_testKinectRPSInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectRPSMachineNumber_,
           3,
           13,
           16,
           0,
           9,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testKinectRPSMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectRPSMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectRPSMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inputUser");
          _SFD_SET_DATA_PROPS(1,0,0,0,"bradHand");
          _SFD_SET_DATA_PROPS(2,0,0,0,"win");
          _SFD_SET_DATA_PROPS(3,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(4,0,0,0,"userHand");
          _SFD_SET_DATA_PROPS(5,0,0,0,"temp");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,9,0,0,"");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(11);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,5);
          _SFD_CH_SUBSTATE_INDEX(4,6);
          _SFD_CH_SUBSTATE_INDEX(5,7);
          _SFD_CH_SUBSTATE_INDEX(6,8);
          _SFD_CH_SUBSTATE_INDEX(7,9);
          _SFD_CH_SUBSTATE_INDEX(8,10);
          _SFD_CH_SUBSTATE_INDEX(9,11);
          _SFD_CH_SUBSTATE_INDEX(10,12);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
        }

        _SFD_CV_INIT_CHART(11,1,0,0);

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
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 8, 0, 13 };

          static unsigned int sEndGuardMap[] = { 11, 12, 24 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(2,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 9, 0 };

          static unsigned int sEndGuardMap[] = { 12, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(10,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(13,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 12 };

          static unsigned int sEndGuardMap[] = { 8, 19 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(14,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"handPose",0,-1,557);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",557,-1,714);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",714,-1,872);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",872,-1,1032);
        _SFD_CV_INIT_EML_IF(0,1,0,316,346,377,555);
        _SFD_CV_INIT_EML_IF(0,1,1,377,411,442,555);
        _SFD_CV_INIT_EML_IF(0,1,2,442,476,507,555);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));

        {
          real_T *c3_inputUser;
          c3_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_inputUser);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c3_bradHand);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c3_win);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c3_diff);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c3_userHand);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c3_temp);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectRPSMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5wOemSvjUvA46bYsZ0zFf";
}

static void sf_opaque_initialize_c3_testKinectRPS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testKinectRPSInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
    chartInstanceVar);
  initialize_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_testKinectRPS(void *chartInstanceVar)
{
  enable_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_testKinectRPS(void *chartInstanceVar)
{
  disable_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_testKinectRPS(void *chartInstanceVar)
{
  sf_gateway_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_testKinectRPS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_testKinectRPS
    ((SFc3_testKinectRPSInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_testKinectRPS();/* state var info */
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

extern void sf_internal_set_sim_state_c3_testKinectRPS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_testKinectRPS();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_testKinectRPS(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_testKinectRPS(S);
}

static void sf_opaque_set_sim_state_c3_testKinectRPS(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_testKinectRPS(S, st);
}

static void sf_opaque_terminate_c3_testKinectRPS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testKinectRPSInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectRPS_optimization_info();
    }

    finalize_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
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
  initSimStructsc3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_testKinectRPS(SimStruct *S)
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
    initialize_params_c3_testKinectRPS((SFc3_testKinectRPSInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_testKinectRPS(SimStruct *S)
{
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectRPS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
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
  ssSetChecksum0(S,(1238581813U));
  ssSetChecksum1(S,(3645177426U));
  ssSetChecksum2(S,(2416121696U));
  ssSetChecksum3(S,(2905399818U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_testKinectRPS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_testKinectRPS(SimStruct *S)
{
  SFc3_testKinectRPSInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_testKinectRPSInstanceStruct *)utMalloc(sizeof
    (SFc3_testKinectRPSInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testKinectRPSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_testKinectRPS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_testKinectRPS;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_testKinectRPS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_testKinectRPS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_testKinectRPS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_testKinectRPS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_testKinectRPS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_testKinectRPS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_testKinectRPS;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_testKinectRPS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_testKinectRPS;
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

void c3_testKinectRPS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_testKinectRPS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_testKinectRPS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_testKinectRPS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_testKinectRPS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
