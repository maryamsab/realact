/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testPriorityQueue_sfun.h"
#include "c3_testPriorityQueue.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testPriorityQueue_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_secs                  (2)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_A2                       ((uint8_T)1U)
#define c3_IN_B2                       ((uint8_T)2U)
#define c3_IN_A1                       ((uint8_T)1U)
#define c3_IN_B1                       ((uint8_T)2U)
#define c3_IN_A3                       ((uint8_T)1U)
#define c3_IN_B3                       ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance);
static void initialize_params_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance);
static void enable_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance);
static void disable_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance);
static void set_sim_state_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance);
static void finalize_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance);
static void sf_gateway_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance);
static void initSimStructsc3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int8_T c3_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_b_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_c_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_A1, const char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_BML, const char_T *c3_identifier);
static real_T c3_f_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_h_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_testPriorityQueueInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance)
{
  real_T *c3_BML;
  c3_BML = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_pr1 = 0U;
  chartInstance->c3_is_pr1 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_pr1 = 0U;
  chartInstance->c3_tp_A1 = 0U;
  chartInstance->c3_tp_B1 = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_is_active_pr2 = 0U;
  chartInstance->c3_is_pr2 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_pr2 = 0U;
  chartInstance->c3_tp_A2 = 0U;
  chartInstance->c3_tp_B2 = 0U;
  chartInstance->c3_temporalCounter_i2 = 0U;
  chartInstance->c3_is_active_pr3 = 0U;
  chartInstance->c3_is_pr3 = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_pr3 = 0U;
  chartInstance->c3_tp_A3 = 0U;
  chartInstance->c3_tp_B3 = 0U;
  chartInstance->c3_temporalCounter_i3 = 0U;
  chartInstance->c3_is_active_c3_testPriorityQueue = 0U;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c3_BML = 0.0;
  }
}

static void initialize_params_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "fcn_out1", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "fcn_out2", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "fcn_out3", 0);
}

static void disable_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "fcn_out1", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "fcn_out2", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "fcn_out3", 0);
}

static void c3_update_debugger_state_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_testPriorityQueue == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_pr1 == c3_IN_A1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_pr1 == c3_IN_B1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_pr2 == c3_IN_A2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_pr2 == c3_IN_B2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_pr2 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_pr1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_pr3 == c3_IN_A3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_pr3 == c3_IN_B3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_pr3 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  uint8_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  uint8_T c3_k_hoistedGlobal;
  uint8_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T *c3_BML;
  c3_BML = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(11, 1), false);
  c3_hoistedGlobal = *c3_BML;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_testPriorityQueue;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_pr2;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_is_active_pr1;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_pr3;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_pr2;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_pr1;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_pr3;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = chartInstance->c3_temporalCounter_i2;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = chartInstance->c3_temporalCounter_i3;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_BML;
  c3_BML = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_BML = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "BML");
  chartInstance->c3_is_active_c3_testPriorityQueue = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_testPriorityQueue");
  chartInstance->c3_is_active_pr2 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "is_active_pr2");
  chartInstance->c3_is_active_pr1 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 3)), "is_active_pr1");
  chartInstance->c3_is_active_pr3 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 4)), "is_active_pr3");
  chartInstance->c3_is_pr2 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "is_pr2");
  chartInstance->c3_is_pr1 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "is_pr1");
  chartInstance->c3_is_pr3 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "is_pr3");
  chartInstance->c3_temporalCounter_i1 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 8)), "temporalCounter_i1");
  chartInstance->c3_temporalCounter_i2 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 9)), "temporalCounter_i2");
  chartInstance->c3_temporalCounter_i3 = c3_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 10)), "temporalCounter_i3");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 11)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_testPriorityQueue(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_active_pr1 == 1U) {
      chartInstance->c3_tp_pr1 = 1U;
    } else {
      chartInstance->c3_tp_pr1 = 0U;
    }

    if (chartInstance->c3_is_pr1 == c3_IN_A1) {
      chartInstance->c3_tp_A1 = 1U;
    } else {
      chartInstance->c3_tp_A1 = 0U;
    }

    if (chartInstance->c3_is_pr1 == c3_IN_B1) {
      chartInstance->c3_tp_B1 = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_B1 = 0U;
    }

    if (chartInstance->c3_is_active_pr2 == 1U) {
      chartInstance->c3_tp_pr2 = 1U;
    } else {
      chartInstance->c3_tp_pr2 = 0U;
    }

    if (chartInstance->c3_is_pr2 == c3_IN_A2) {
      chartInstance->c3_tp_A2 = 1U;
    } else {
      chartInstance->c3_tp_A2 = 0U;
    }

    if (chartInstance->c3_is_pr2 == c3_IN_B2) {
      chartInstance->c3_tp_B2 = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c3_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c3_tp_B2 = 0U;
    }

    if (chartInstance->c3_is_active_pr3 == 1U) {
      chartInstance->c3_tp_pr3 = 1U;
    } else {
      chartInstance->c3_tp_pr3 = 0U;
    }

    if (chartInstance->c3_is_pr3 == c3_IN_A3) {
      chartInstance->c3_tp_A3 = 1U;
    } else {
      chartInstance->c3_tp_A3 = 0U;
    }

    if (chartInstance->c3_is_pr3 == c3_IN_B3) {
      chartInstance->c3_tp_B3 = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c3_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c3_tp_B3 = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_testPriorityQueue(SFc3_testPriorityQueueInstanceStruct
  *chartInstance)
{
  real_T *c3_BML;
  c3_BML = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_set_sim_state_side_effects_c3_testPriorityQueue(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_BML, 0U);
  if (chartInstance->c3_temporalCounter_i1 < 3U) {
    chartInstance->c3_temporalCounter_i1++;
  }

  if (chartInstance->c3_temporalCounter_i2 < 7U) {
    chartInstance->c3_temporalCounter_i2++;
  }

  if (chartInstance->c3_temporalCounter_i3 < 15U) {
    chartInstance->c3_temporalCounter_i3++;
  }

  chartInstance->c3_sfEvent = c3_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  c3_chartstep_c3_testPriorityQueue(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testPriorityQueueMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_out;
  boolean_T c3_b_temp;
  boolean_T c3_b_out;
  boolean_T c3_c_temp;
  boolean_T c3_c_out;
  real_T *c3_BML;
  c3_BML = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_testPriorityQueue == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_testPriorityQueue = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_pr1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_pr1 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_pr1 = c3_IN_A1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_A1 = 1U;
    chartInstance->c3_is_active_pr2 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_pr2 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_pr2 = c3_IN_A2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_A2 = 1U;
    chartInstance->c3_is_active_pr3 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_pr3 = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_pr3 = c3_IN_A3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_A3 = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_pr1) {
     case c3_IN_A1:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_A1 = 0U;
      chartInstance->c3_is_pr1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 0U,
                   chartInstance->c3_sfEvent);
      sf_mex_printf("%s\\n", "fcn_out1");
      sf_call_output_fcn_call(chartInstance->S, 0, "fcn_out1", 0);
      chartInstance->c3_is_pr1 = c3_IN_B1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_B1 = 1U;
      *c3_BML = 1.0;
      _SFD_DATA_RANGE_CHECK(*c3_BML, 0U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_B1:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c3_sfEvent);
      c3_temp = (_SFD_CCP_CALL(4U, 0, chartInstance->c3_sfEvent == c3_event_secs
                  != 0U, chartInstance->c3_sfEvent) != 0);
      if (c3_temp) {
        c3_temp = (_SFD_CCP_CALL(4U, 1, chartInstance->c3_temporalCounter_i1 >=
                    1 != 0U, chartInstance->c3_sfEvent) != 0);
      }

      c3_out = (CV_TRANSITION_EVAL(4U, (int32_T)c3_temp) != 0);
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_B1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_pr1 = c3_IN_A1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_A1 = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c3_is_pr1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_pr2) {
     case c3_IN_A2:
      CV_STATE_EVAL(3, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_A2 = 0U;
      chartInstance->c3_is_pr2 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 1U,
                   chartInstance->c3_sfEvent);
      sf_mex_printf("%s\\n", "fcn_out2");
      sf_call_output_fcn_call(chartInstance->S, 1, "fcn_out2", 0);
      chartInstance->c3_is_pr2 = c3_IN_B2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i2 = 0U;
      chartInstance->c3_tp_B2 = 1U;
      *c3_BML = 2.0;
      _SFD_DATA_RANGE_CHECK(*c3_BML, 0U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_B2:
      CV_STATE_EVAL(3, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c3_sfEvent);
      c3_b_temp = (_SFD_CCP_CALL(5U, 0, chartInstance->c3_sfEvent ==
        c3_event_secs != 0U, chartInstance->c3_sfEvent) != 0);
      if (c3_b_temp) {
        c3_b_temp = (_SFD_CCP_CALL(5U, 1, chartInstance->c3_temporalCounter_i2 >=
          5 != 0U, chartInstance->c3_sfEvent) != 0);
      }

      c3_b_out = (CV_TRANSITION_EVAL(5U, (int32_T)c3_b_temp) != 0);
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_B2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_pr2 = c3_IN_A2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_A2 = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(3, 0, 0);
      chartInstance->c3_is_pr2 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_pr3) {
     case c3_IN_A3:
      CV_STATE_EVAL(6, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_A3 = 0U;
      chartInstance->c3_is_pr3 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 7U,
                   chartInstance->c3_sfEvent);
      sf_mex_printf("%s\\n", "fcn_out3");
      sf_call_output_fcn_call(chartInstance->S, 2, "fcn_out3", 0);
      chartInstance->c3_is_pr3 = c3_IN_B3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i3 = 0U;
      chartInstance->c3_tp_B3 = 1U;
      *c3_BML = 3.0;
      _SFD_DATA_RANGE_CHECK(*c3_BML, 0U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_B3:
      CV_STATE_EVAL(6, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c3_sfEvent);
      c3_c_temp = (_SFD_CCP_CALL(8U, 0, chartInstance->c3_sfEvent ==
        c3_event_secs != 0U, chartInstance->c3_sfEvent) != 0);
      if (c3_c_temp) {
        c3_c_temp = (_SFD_CCP_CALL(8U, 1, chartInstance->c3_temporalCounter_i3 >=
          10 != 0U, chartInstance->c3_sfEvent) != 0);
      }

      c3_c_out = (CV_TRANSITION_EVAL(8U, (int32_T)c3_c_temp) != 0);
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_B3 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_pr3 = c3_IN_A3;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_A3 = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(6, 0, 0);
      chartInstance->c3_is_pr3 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_testPriorityQueue
  (SFc3_testPriorityQueueInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

const mxArray *sf_c3_testPriorityQueue_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_secs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_secs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_secs), &c3_thisId);
  sf_mex_destroy(&c3_secs);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_b_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_A1, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_A1), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_A1);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
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

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_A1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_b_tp_A1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_A1), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_A1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_BML, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_BML), &c3_thisId);
  sf_mex_destroy(&c3_BML);
  return c3_y;
}

static real_T c3_f_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
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

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_BML;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)chartInstanceVoid;
  c3_BML = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_BML), &c3_thisId);
  sf_mex_destroy(&c3_BML);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallIn(SFc3_testPriorityQueueInstanceStruct
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

static void init_dsm_address_info(SFc3_testPriorityQueueInstanceStruct
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

void sf_c3_testPriorityQueue_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4180115401U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2389308699U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2202255219U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3839543772U);
}

mxArray *sf_c3_testPriorityQueue_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NRSCbQXXzRGigAfs990RZD");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_testPriorityQueue_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_testPriorityQueue_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_testPriorityQueue(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[11],T\"BML\",},{M[8],M[0],T\"is_active_c3_testPriorityQueue\",},{M[8],M[9],T\"is_active_pr2\",},{M[8],M[10],T\"is_active_pr1\",},{M[8],M[21],T\"is_active_pr3\",},{M[9],M[9],T\"is_pr2\",},{M[9],M[10],T\"is_pr1\",},{M[9],M[21],T\"is_pr3\",},{M[11],M[16],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[2],M[1]}}},{M[11],M[16],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M[5],M[1]}}}}",
    "100 S'type','srcId','name','auxInfo'{{M[11],M[16],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[20],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_testPriorityQueue_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testPriorityQueueInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_testPriorityQueueInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testPriorityQueueMachineNumber_,
           3,
           9,
           9,
           0,
           1,
           4,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testPriorityQueueMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testPriorityQueueMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testPriorityQueueMachineNumber_,
            chartInstance->chartNumber,
            4,
            4,
            4);
          _SFD_SET_DATA_PROPS(0,2,0,1,"BML");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,1);
          _SFD_EVENT_SCOPE(3,2);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,6);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,2);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 12, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 8, 0 };

          static unsigned int sEndGuardMap[] = { 12, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(5,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 9, 0 };

          static unsigned int sEndGuardMap[] = { 13, 14 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(8,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);

        {
          real_T *c3_BML;
          c3_BML = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_BML);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testPriorityQueueMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "WaSPIaCFtlP0YJLBxmalaF";
}

static void sf_opaque_initialize_c3_testPriorityQueue(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar);
  initialize_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_testPriorityQueue(void *chartInstanceVar)
{
  enable_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_testPriorityQueue(void *chartInstanceVar)
{
  disable_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_testPriorityQueue(void *chartInstanceVar)
{
  sf_gateway_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_testPriorityQueue(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_testPriorityQueue
    ((SFc3_testPriorityQueueInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_testPriorityQueue();/* state var info */
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

extern void sf_internal_set_sim_state_c3_testPriorityQueue(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_testPriorityQueue();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_testPriorityQueue(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_testPriorityQueue(S);
}

static void sf_opaque_set_sim_state_c3_testPriorityQueue(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_testPriorityQueue(S, st);
}

static void sf_opaque_terminate_c3_testPriorityQueue(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testPriorityQueueInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testPriorityQueue_optimization_info();
    }

    finalize_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
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
  initSimStructsc3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_testPriorityQueue(SimStruct *S)
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
    initialize_params_c3_testPriorityQueue((SFc3_testPriorityQueueInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_testPriorityQueue(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testPriorityQueue_optimization_info();
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
      (),infoStruct,3,3);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(216253703U));
  ssSetChecksum1(S,(947562870U));
  ssSetChecksum2(S,(2840946374U));
  ssSetChecksum3(S,(4159980891U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_testPriorityQueue(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_testPriorityQueue(SimStruct *S)
{
  SFc3_testPriorityQueueInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_testPriorityQueueInstanceStruct *)utMalloc(sizeof
    (SFc3_testPriorityQueueInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testPriorityQueueInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_testPriorityQueue;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_testPriorityQueue;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_testPriorityQueue;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_testPriorityQueue;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_testPriorityQueue;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_testPriorityQueue;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_testPriorityQueue;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_testPriorityQueue;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_testPriorityQueue;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_testPriorityQueue;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_testPriorityQueue;
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

void c3_testPriorityQueue_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_testPriorityQueue(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_testPriorityQueue(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_testPriorityQueue(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_testPriorityQueue_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
