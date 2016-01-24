/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DemoGazeFollowWaveIdle_sfun.h"
#include "c10_DemoGazeFollowWaveIdle.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DemoGazeFollowWaveIdle_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c10_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c10_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c10_IN_check                   ((uint8_T)1U)
#define c10_IN_flagOne                 ((uint8_T)2U)
#define c10_IN_flagZero                ((uint8_T)3U)
#define c10_IN_init                    ((uint8_T)4U)
#define c10_IN_wait                    ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c10_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c10_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void initialize_params_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void enable_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void disable_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void set_sim_state_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_st);
static void c10_set_sim_state_side_effects_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void finalize_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void sf_gateway_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_enter_atomic_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_enter_internal_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_exit_internal_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_initc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void initSimStructsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_nargout, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static boolean_T c10_c_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_activate_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_deactivate_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_increment_counters_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static void c10_reset_counters_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int8_T c10_d_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_e_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static uint8_T c10_f_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_b_tp_wait, const char_T *c10_identifier);
static uint8_T c10_g_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint32_T c10_h_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_b_temporalCounter_i1, const char_T *c10_identifier);
static uint32_T c10_i_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static const mxArray *c10_j_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier);
static const mxArray *c10_k_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_updateDataWrittenToVector
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex);
static void c10_errorIfDataNotWrittenToFcn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex, uint32_T c10_dataNumber);
static real_T c10_get_changeFlag(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_changeFlag(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_changeFlag(SFc10_DemoGazeFollowWaveIdleInstanceStruct *
  chartInstance, uint32_T c10_b);
static void init_dsm_address_info(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_update_debugger_state_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  uint32_T c10_prevAniVal;
  c10_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c10_is_active_c10_DemoGazeFollowWaveIdle == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_check) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_flagOne) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_flagZero) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  }

  _SFD_SET_ANIMATION(c10_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  uint8_T c10_c_hoistedGlobal;
  uint8_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  uint32_T c10_d_hoistedGlobal;
  uint32_T c10_d_u;
  const mxArray *c10_e_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(4, 1), false);
  c10_hoistedGlobal = chartInstance->c10_timer;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = chartInstance->c10_is_active_c10_DemoGazeFollowWaveIdle;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_hoistedGlobal = chartInstance->c10_is_c10_DemoGazeFollowWaveIdle;
  c10_c_u = c10_c_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  c10_d_hoistedGlobal = chartInstance->c10_temporalCounter_i1;
  c10_d_u = c10_d_hoistedGlobal;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_d_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_st)
{
  const mxArray *c10_u;
  c10_u = sf_mex_dup(c10_st);
  chartInstance->c10_timer = c10_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "timer");
  chartInstance->c10_is_active_c10_DemoGazeFollowWaveIdle =
    c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "is_active_c10_DemoGazeFollowWaveIdle");
  chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
     "is_c10_DemoGazeFollowWaveIdle");
  chartInstance->c10_temporalCounter_i1 = c10_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c10_u, 3)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c10_setSimStateSideEffectsInfo,
                c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 4)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c10_u);
  chartInstance->c10_doSetSimStateSideEffects = 1U;
  c10_update_debugger_state_c10_DemoGazeFollowWaveIdle(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void c10_set_sim_state_side_effects_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  if (chartInstance->c10_doSetSimStateSideEffects != 0) {
    if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_check) {
      chartInstance->c10_tp_check = 1U;
    } else {
      chartInstance->c10_tp_check = 0U;
    }

    if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_flagOne) {
      chartInstance->c10_tp_flagOne = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_flagOne = 0U;
    }

    if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_flagZero) {
      chartInstance->c10_tp_flagZero = 1U;
    } else {
      chartInstance->c10_tp_flagZero = 0U;
    }

    if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_init) {
      chartInstance->c10_tp_init = 1U;
    } else {
      chartInstance->c10_tp_init = 0U;
    }

    if (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle == c10_IN_wait) {
      chartInstance->c10_tp_wait = 1U;
    } else {
      chartInstance->c10_tp_wait = 0U;
    }

    chartInstance->c10_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c10_setSimStateSideEffectsInfo);
}

static void sf_gateway_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  c10_set_sim_state_side_effects_c10_DemoGazeFollowWaveIdle(chartInstance);
}

static void c10_enter_atomic_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  chartInstance->c10_is_active_c10_DemoGazeFollowWaveIdle = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
}

static void c10_enter_internal_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[2];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  chartInstance->c10_isStable = false;
  chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  chartInstance->c10_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_b_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  c10_set_changeFlag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  chartInstance->c10_timer = 200.0;
  c10_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c10_timer, 2U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 0.0;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 1.0;
  boolean_T c10_c_out;
  boolean_T c10_temp;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_g_nargin = 0.0;
  real_T c10_g_nargout = 0.0;
  boolean_T *c10_inputChangeFlag;
  c10_inputChangeFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_isStable = true;
  switch (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle) {
   case c10_IN_check:
    CV_CHART_EVAL(7, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_f_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    c10_out = CV_EML_IF(0, 0, 0, (real_T)*c10_inputChangeFlag == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_check = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_flagOne;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_flagOne = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_c_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
        c10_sf_marshallOut, c10_sf_marshallIn);
      c10_set_changeFlag(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_flagOne:
    CV_CHART_EVAL(7, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_e_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    c10_b_out = CV_EML_IF(5, 0, 0, (real_T)*c10_inputChangeFlag == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_flagOne = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_wait = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
        c10_sf_marshallOut, c10_sf_marshallIn);
      chartInstance->c10_timer = 200.0;
      c10_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c10_timer, 2U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_g_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
        c10_sf_marshallOut, c10_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_b_sf_marshallOut,
        c10_b_sf_marshallIn);
      c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
      c10_temp = (chartInstance->c10_sfEvent == c10_event_secs);
      if (c10_temp) {
        c10_temp = (chartInstance->c10_temporalCounter_i1 >=
                    _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
          chartInstance->c10_timer, 32U, 1U));
      }

      c10_c_out = CV_EML_IF(1, 0, 0, c10_temp);
      _SFD_SYMBOL_SCOPE_POP();
      if (c10_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_flagOne = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_flagZero;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_flagZero = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_d_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
          c10_sf_marshallOut, c10_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
          c10_sf_marshallOut, c10_sf_marshallIn);
        c10_set_changeFlag(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c10_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_flagZero:
    CV_CHART_EVAL(7, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_flagZero = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_check;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_check = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_init:
    CV_CHART_EVAL(7, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_check;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_check = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_wait:
    CV_CHART_EVAL(7, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_wait = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_flagOne;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    chartInstance->c10_temporalCounter_i1 = 0U;
    chartInstance->c10_tp_flagOne = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_c_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargin, 0U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargout, 1U, c10_sf_marshallOut,
      c10_sf_marshallIn);
    c10_set_changeFlag(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
}

static void c10_exit_internal_c10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  switch (chartInstance->c10_is_c10_DemoGazeFollowWaveIdle) {
   case c10_IN_check:
    CV_CHART_EVAL(7, 0, 1);
    chartInstance->c10_tp_check = 0U;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_flagOne:
    CV_CHART_EVAL(7, 0, 2);
    chartInstance->c10_tp_flagOne = 0U;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_flagZero:
    CV_CHART_EVAL(7, 0, 3);
    chartInstance->c10_tp_flagZero = 0U;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_init:
    CV_CHART_EVAL(7, 0, 4);
    chartInstance->c10_tp_init = 0U;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_wait:
    CV_CHART_EVAL(7, 0, 5);
    chartInstance->c10_tp_wait = 0U;
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
    break;
  }
}

static void c10_initc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_doSetSimStateSideEffects = 0U;
  chartInstance->c10_setSimStateSideEffectsInfo = NULL;
  chartInstance->c10_tp_check = 0U;
  chartInstance->c10_tp_flagOne = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_flagZero = 0U;
  chartInstance->c10_tp_init = 0U;
  chartInstance->c10_tp_wait = 0U;
  chartInstance->c10_is_active_c10_DemoGazeFollowWaveIdle = 0U;
  chartInstance->c10_is_c10_DemoGazeFollowWaveIdle = c10_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_nargout, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  boolean_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(boolean_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static boolean_T c10_c_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  boolean_T c10_y;
  boolean_T c10_b0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_b0, 1, 11, 0U, 0, 0U, 0);
  c10_y = c10_b0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_sf_internal_predicateOutput;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  boolean_T c10_y;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_sf_internal_predicateOutput = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_sf_internal_predicateOutput), &c10_thisId);
  sf_mex_destroy(&c10_sf_internal_predicateOutput);
  *(boolean_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_DemoGazeFollowWaveIdle_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static void c10_activate_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = c10_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_deactivate_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_increment_counters_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  if (chartInstance->c10_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c10_temporalCounter_i1++;
  }
}

static void c10_reset_counters_secsc10_DemoGazeFollowWaveIdle
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c10_DemoGazeFollowWaveIdle_secs(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_activate_secsc10_DemoGazeFollowWaveIdle(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c10_DemoGazeFollowWaveIdle_secs
  (SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_increment_counters_secsc10_DemoGazeFollowWaveIdle(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c10_DemoGazeFollowWaveIdle_secs
  (SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_reset_counters_secsc10_DemoGazeFollowWaveIdle(chartInstance);
}

void sf_exported_auto_deactivate_c10_DemoGazeFollowWaveIdle_secs(SimStruct
  *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_deactivate_secsc10_DemoGazeFollowWaveIdle(chartInstance);
}

boolean_T sf_exported_auto_isStablec10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c10_isStable;
}

void sf_exported_auto_duringc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_c10_DemoGazeFollowWaveIdle(chartInstance);
}

void sf_exported_auto_enterc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_enter_atomic_c10_DemoGazeFollowWaveIdle(chartInstance);
  c10_enter_internal_c10_DemoGazeFollowWaveIdle(chartInstance);
}

void sf_exported_auto_exitc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_exit_internal_c10_DemoGazeFollowWaveIdle(chartInstance);
}

void sf_exported_auto_gatewayc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c10_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc10_DemoGazeFollowWaveIdle(SimStruct
  *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc10_DemoGazeFollowWaveIdle(SimStruct
  *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc10_DemoGazeFollowWaveIdle(SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_initc10_DemoGazeFollowWaveIdle(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec10_DemoGazeFollowWaveIdle(SimStruct *
  c10_S)
{
  const mxArray *c10_out = NULL;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_out = NULL;
  sf_mex_assign(&c10_out, sf_internal_get_sim_state_c10_DemoGazeFollowWaveIdle
                (c10_S), false);
  return c10_out;
}

void sf_exported_auto_setSimstatec10_DemoGazeFollowWaveIdle(SimStruct *c10_S,
  const mxArray *c10_in)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c10_DemoGazeFollowWaveIdle(c10_S, sf_mex_dup(c10_in));
  sf_mex_destroy(&c10_in);
}

void sf_exported_auto_check_state_inconsistency_c10_DemoGazeFollowWaveIdle
  (SimStruct *c10_S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DemoGazeFollowWaveIdleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int8_T c10_d_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int8_T c10_y;
  int8_T c10_i0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i0, 1, 2, 0U, 0, 0U, 0);
  c10_y = c10_i0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_secs;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int8_T c10_y;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_secs = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_secs),
    &c10_thisId);
  sf_mex_destroy(&c10_secs);
  *(int8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_e_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i1;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i1, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i1;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  uint8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(uint8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_b_tp_wait, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_wait),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_wait);
  return c10_y;
}

static uint8_T c10_g_emlrt_marshallIn(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_tp_wait;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
    chartInstanceVoid;
  c10_b_tp_wait = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_wait),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_wait);
  *(uint8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint32_T c10_h_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_b_temporalCounter_i1, const char_T *c10_identifier)
{
  uint32_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_temporalCounter_i1), &c10_thisId);
  sf_mex_destroy(&c10_b_temporalCounter_i1);
  return c10_y;
}

static uint32_T c10_i_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint32_T c10_y;
  uint32_T c10_u1;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u1, 1, 7, 0U, 0, 0U, 0);
  c10_y = c10_u1;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static const mxArray *c10_j_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier)
{
  const mxArray *c10_y = NULL;
  emlrtMsgIdentifier c10_thisId;
  c10_y = NULL;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  sf_mex_assign(&c10_y, c10_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_setSimStateSideEffectsInfo), &c10_thisId), false);
  sf_mex_destroy(&c10_b_setSimStateSideEffectsInfo);
  return c10_y;
}

static const mxArray *c10_k_emlrt_marshallIn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  const mxArray *c10_y = NULL;
  (void)chartInstance;
  (void)c10_parentId;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_duplicatearraysafe(&c10_u), false);
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_updateDataWrittenToVector
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex)
{
  (void)chartInstance;
  c10_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c10_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c10_errorIfDataNotWrittenToFcn
  (SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex, uint32_T c10_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c10_dataNumber, c10_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c10_vectorIndex, 0, 0, 1,
    0)]);
}

static real_T c10_get_changeFlag(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1112) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_changeFlag_address;
}

static void c10_set_changeFlag(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1112) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_changeFlag_address = c10_c;
}

static real_T *c10_access_changeFlag(SFc10_DemoGazeFollowWaveIdleInstanceStruct *
  chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c10_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1112) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_changeFlag_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c10_c;
}

static void init_dsm_address_info(SFc10_DemoGazeFollowWaveIdleInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "changeFlag", (void **)
    &chartInstance->c10_changeFlag_address, &chartInstance->c10_changeFlag_index);
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

void sf_c10_DemoGazeFollowWaveIdle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1223181036U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(324548511U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1526320622U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2260303613U);
}

mxArray *sf_c10_DemoGazeFollowWaveIdle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xxkNGChDflDrWWfbQBqRE");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_DemoGazeFollowWaveIdle_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_DemoGazeFollowWaveIdle_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_DemoGazeFollowWaveIdle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[3],M[19],T\"timer\",},{M[8],M[0],T\"is_active_c10_DemoGazeFollowWaveIdle\",},{M[9],M[0],T\"is_c10_DemoGazeFollowWaveIdle\",},{M[11],M[11],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[7],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_DemoGazeFollowWaveIdle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DemoGazeFollowWaveIdleMachineNumber_,
           10,
           5,
           7,
           0,
           3,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_DemoGazeFollowWaveIdleMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DemoGazeFollowWaveIdleMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DemoGazeFollowWaveIdleMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"changeFlag");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inputChangeFlag");
          _SFD_SET_DATA_PROPS(2,0,0,0,"timer");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(5,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,17,0,17);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);

        {
          boolean_T *c10_inputChangeFlag;
          c10_inputChangeFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_changeFlag_address);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_inputChangeFlag);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c10_timer);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DemoGazeFollowWaveIdleMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "x4XoHyulE6A6JDEmygUxxF";
}

static void sf_opaque_initialize_c10_DemoGazeFollowWaveIdle(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_DemoGazeFollowWaveIdle
    ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*) chartInstanceVar);
  initialize_c10_DemoGazeFollowWaveIdle
    ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_DemoGazeFollowWaveIdle(void *chartInstanceVar)
{
  enable_c10_DemoGazeFollowWaveIdle((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_DemoGazeFollowWaveIdle(void *chartInstanceVar)
{
  disable_c10_DemoGazeFollowWaveIdle((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_DemoGazeFollowWaveIdle(void *chartInstanceVar)
{
  sf_gateway_c10_DemoGazeFollowWaveIdle
    ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_DemoGazeFollowWaveIdle
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_DemoGazeFollowWaveIdle
    ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_DemoGazeFollowWaveIdle();/* state var info */
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

extern void sf_internal_set_sim_state_c10_DemoGazeFollowWaveIdle(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c10_DemoGazeFollowWaveIdle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_DemoGazeFollowWaveIdle
    ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_DemoGazeFollowWaveIdle
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c10_DemoGazeFollowWaveIdle(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c10_DemoGazeFollowWaveIdle(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DemoGazeFollowWaveIdle_optimization_info();
    }

    finalize_c10_DemoGazeFollowWaveIdle
      ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_DemoGazeFollowWaveIdle
    ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_DemoGazeFollowWaveIdle(SimStruct *S)
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
    initialize_params_c10_DemoGazeFollowWaveIdle
      ((SFc10_DemoGazeFollowWaveIdleInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_DemoGazeFollowWaveIdle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DemoGazeFollowWaveIdle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3165849979U));
  ssSetChecksum1(S,(11655064U));
  ssSetChecksum2(S,(3554712098U));
  ssSetChecksum3(S,(1782299367U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_DemoGazeFollowWaveIdle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c10_DemoGazeFollowWaveIdle(SimStruct *S)
{
  SFc10_DemoGazeFollowWaveIdleInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_DemoGazeFollowWaveIdleInstanceStruct *)utMalloc(sizeof
    (SFc10_DemoGazeFollowWaveIdleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_DemoGazeFollowWaveIdleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_DemoGazeFollowWaveIdle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_DemoGazeFollowWaveIdle;
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

void c10_DemoGazeFollowWaveIdle_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_DemoGazeFollowWaveIdle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_DemoGazeFollowWaveIdle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_DemoGazeFollowWaveIdle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_DemoGazeFollowWaveIdle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
