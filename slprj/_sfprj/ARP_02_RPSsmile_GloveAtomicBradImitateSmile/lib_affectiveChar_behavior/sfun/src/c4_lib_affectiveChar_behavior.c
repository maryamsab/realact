/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c4_lib_affectiveChar_behavior.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_stateCheck               ((uint8_T)1U)
#define c4_IN_stateInitial             ((uint8_T)2U)
#define c4_IN_stateSmile               ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c4_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c4_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_st);
static void c4_set_sim_state_side_effects_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_enter_atomic_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_enter_internal_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_exit_internal_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_initc4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_enter_atomic_stateSmile
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c4_encStr2Arr(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_b_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_c_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn(SFc4_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_sendBMLc4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c4_arg
   [256]);
static void c4_smileTablec4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c4_bmlID,
   real_T c4_poseBML[256]);
static void c4_sendBML(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c4_b_sendBML(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_f_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_b_tp_stateInitial, const char_T *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_h_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_b_setSimStateSideEffectsInfo, const char_T *c4_identifier);
static const mxArray *c4_i_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_updateDataWrittenToVector
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c4_vectorIndex);
static real_T c4_get_avert(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_avert(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_avert(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_isPosing(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_isPosing(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_isPosing(SFc4_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c4_b);
static void init_dsm_address_info(SFc4_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_debugger_state_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_lib_affectiveChar_behavior == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_lib_affectiveChar_behavior == c4_IN_stateInitial)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_lib_affectiveChar_behavior == c4_IN_stateCheck) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_lib_affectiveChar_behavior == c4_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_lib_affectiveChar_behavior;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_c4_lib_affectiveChar_behavior;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_st)
{
  const mxArray *c4_u;
  c4_u = sf_mex_dup(c4_st);
  chartInstance->c4_is_active_c4_lib_affectiveChar_behavior =
    c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "is_active_c4_lib_affectiveChar_behavior");
  chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_c4_lib_affectiveChar_behavior");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_lib_affectiveChar_behavior == c4_IN_stateCheck)
    {
      chartInstance->c4_tp_stateCheck = 1U;
    } else {
      chartInstance->c4_tp_stateCheck = 0U;
    }

    if (chartInstance->c4_is_c4_lib_affectiveChar_behavior == c4_IN_stateInitial)
    {
      chartInstance->c4_tp_stateInitial = 1U;
    } else {
      chartInstance->c4_tp_stateInitial = 0U;
    }

    if (chartInstance->c4_is_c4_lib_affectiveChar_behavior == c4_IN_stateSmile)
    {
      chartInstance->c4_tp_stateSmile = 1U;
    } else {
      chartInstance->c4_tp_stateSmile = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c4_set_sim_state_side_effects_c4_lib_affectiveChar_behavior(chartInstance);
}

static void c4_enter_atomic_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_active_c4_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
}

static void c4_enter_internal_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_d_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T *c4_isSmiling;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c4_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_isStable = true;
  switch (chartInstance->c4_is_c4_lib_affectiveChar_behavior) {
   case c4_IN_stateCheck:
    CV_CHART_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_g_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(3, 0, 0, *c4_isSmiling == 1.0)) {
      if (CV_EML_COND(3, 0, 1, c4_get_avert(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c4_out = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c4_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateCheck = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 1U;
      c4_enter_atomic_stateSmile(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateInitial:
    CV_CHART_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_stateCheck;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateCheck = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateSmile:
    CV_CHART_EVAL(1, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_f_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(2, 0, 0, *c4_isSmiling == 0.0)) {
      guard1 = true;
    } else if (CV_EML_COND(2, 0, 1, c4_get_avert(chartInstance, 0) != 0.0)) {
      guard1 = true;
    } else {
      CV_EML_MCDC(2, 0, 0, false);
      CV_EML_IF(2, 0, 0, false);
      c4_b_out = false;
    }

    if (guard1 == true) {
      CV_EML_MCDC(2, 0, 0, true);
      CV_EML_IF(2, 0, 0, true);
      c4_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_stateCheck;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateCheck = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 1U;
      c4_enter_atomic_stateSmile(chartInstance);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
}

static void c4_exit_internal_c4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  switch (chartInstance->c4_is_c4_lib_affectiveChar_behavior) {
   case c4_IN_stateCheck:
    CV_CHART_EVAL(1, 0, 1);
    chartInstance->c4_tp_stateCheck = 0U;
    chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateInitial:
    CV_CHART_EVAL(1, 0, 2);
    chartInstance->c4_tp_stateInitial = 0U;
    chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateSmile:
    CV_CHART_EVAL(1, 0, 3);
    chartInstance->c4_tp_stateSmile = 0U;
    chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;
  }
}

static void c4_initc4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_stateCheck = 0U;
  chartInstance->c4_tp_stateInitial = 0U;
  chartInstance->c4_tp_stateSmile = 0U;
  chartInstance->c4_is_active_c4_lib_affectiveChar_behavior = 0U;
  chartInstance->c4_is_c4_lib_affectiveChar_behavior = c4_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_enter_atomic_stateSmile
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv0[256];
  int32_T c4_i0;
  real_T c4_arg[256];
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_e_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c4_smileTablec4_lib_affectiveChar_behavior(chartInstance, 1.0, c4_dv0);
  for (c4_i0 = 0; c4_i0 < 256; c4_i0++) {
    c4_arg[c4_i0] = c4_dv0[c4_i0];
  }

  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i1], 3U);
  }

  _SFD_SET_DATA_VALUE_PTR(3U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 256; c4_i2++) {
    (*c4_b_arg)[c4_i2] = c4_arg[c4_i2];
  }

  for (c4_i3 = 0; c4_i3 < 256; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i3], 3U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(3U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_encStr2Arr(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[223];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[223];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i4;
  static char_T c4_cv0[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '8', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"', '6',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '8', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i5;
  static real_T c4_dv1[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 56.0, 34.0, 32.0, 114.0, 101.0,
    108.0, 97.0, 120.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0,
    61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0,
    32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 101.0, 110.0, 100.0,
    61.0, 34.0, 56.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0,
    54.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0, 34.0, 32.0,
    116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i4 = 0; c4_i4 < 223; c4_i4++) {
    c4_mystr[c4_i4] = c4_cv0[c4_i4];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i5 = 0; c4_i5 < 223; c4_i5++) {
    c4_arr[c4_i5] = c4_dv1[c4_i5];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i6 = 0; c4_i6 < 256; c4_i6++) {
    c4_tt[c4_i6] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i7 = 0; c4_i7 < 223; c4_i7++) {
    c4_tt[c4_i7] = c4_arr[c4_i7];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i8 = 0; c4_i8 < 256; c4_i8++) {
    c4_myarr256[c4_i8] = c4_tt[c4_i8];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i9;
  real_T c4_b_inData[256];
  int32_T c4_i10;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i9 = 0; c4_i9 < 256; c4_i9++) {
    c4_b_inData[c4_i9] = (*(real_T (*)[256])c4_inData)[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 256; c4_i10++) {
    c4_u[c4_i10] = c4_b_inData[c4_i10];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256])
{
  real_T c4_dv2[256];
  int32_T c4_i11;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c4_i11 = 0; c4_i11 < 256; c4_i11++) {
    c4_y[c4_i11] = c4_dv2[c4_i11];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_poseBML;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i12;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_poseBML = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_poseBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_poseBML);
  for (c4_i12 = 0; c4_i12 < 256; c4_i12++) {
    (*(real_T (*)[256])c4_outData)[c4_i12] = c4_y[c4_i12];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_b_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
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
  const mxArray *c4_bmlID;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_bmlID = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_bmlID), &c4_thisId);
  sf_mex_destroy(&c4_bmlID);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_c_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_aVarTruthTableCondition_2;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_aVarTruthTableCondition_2 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_aVarTruthTableCondition_2), &c4_thisId);
  sf_mex_destroy(&c4_aVarTruthTableCondition_2);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i13;
  real_T c4_b_inData[256];
  int32_T c4_i14;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i13 = 0; c4_i13 < 256; c4_i13++) {
    c4_b_inData[c4_i13] = (*(real_T (*)[256])c4_inData)[c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 256; c4_i14++) {
    c4_u[c4_i14] = c4_b_inData[c4_i14];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn(SFc4_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256])
{
  real_T c4_dv3[256];
  int32_T c4_i15;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv3, 1, 0, 0U, 1, 0U, 1, 256);
  for (c4_i15 = 0; c4_i15 < 256; c4_i15++) {
    c4_y[c4_i15] = c4_dv3[c4_i15];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_myarr256;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i16;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_myarr256 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
  for (c4_i16 = 0; c4_i16 < 256; c4_i16++) {
    (*(real_T (*)[256])c4_outData)[c4_i16] = c4_y[c4_i16];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i17;
  char_T c4_b_inData[223];
  int32_T c4_i18;
  char_T c4_u[223];
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i17 = 0; c4_i17 < 223; c4_i17++) {
    c4_b_inData[c4_i17] = (*(char_T (*)[223])c4_inData)[c4_i17];
  }

  for (c4_i18 = 0; c4_i18 < 223; c4_i18++) {
    c4_u[c4_i18] = c4_b_inData[c4_i18];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i19;
  real_T c4_b_inData[223];
  int32_T c4_i20;
  real_T c4_u[223];
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i19 = 0; c4_i19 < 223; c4_i19++) {
    c4_b_inData[c4_i19] = (*(real_T (*)[223])c4_inData)[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 223; c4_i20++) {
    c4_u[c4_i20] = c4_b_inData[c4_i20];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i21;
  char_T c4_b_inData[87];
  int32_T c4_i22;
  char_T c4_u[87];
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i21 = 0; c4_i21 < 87; c4_i21++) {
    c4_b_inData[c4_i21] = (*(char_T (*)[87])c4_inData)[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 87; c4_i22++) {
    c4_u[c4_i22] = c4_b_inData[c4_i22];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i23;
  real_T c4_b_inData[87];
  int32_T c4_i24;
  real_T c4_u[87];
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i23 = 0; c4_i23 < 87; c4_i23++) {
    c4_b_inData[c4_i23] = (*(real_T (*)[87])c4_inData)[c4_i23];
  }

  for (c4_i24 = 0; c4_i24 < 87; c4_i24++) {
    c4_u[c4_i24] = c4_b_inData[c4_i24];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
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

boolean_T sf_exported_auto_isStablec4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c4_isStable;
}

void sf_exported_auto_duringc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_c4_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_sendBML(chartInstance);
  c4_enter_atomic_c4_lib_affectiveChar_behavior(chartInstance);
  c4_enter_internal_c4_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_exit_internal_c4_lib_affectiveChar_behavior(chartInstance);
  c4_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_sendBML(chartInstance);
}

void sf_exported_auto_disablec4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  chartInstance->c4_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc4_lib_affectiveChar_behavior
  (SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc4_lib_affectiveChar_behavior(SimStruct *
  c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc4_lib_affectiveChar_behavior(SimStruct
  *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc4_lib_affectiveChar_behavior(SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_initc4_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec4_lib_affectiveChar_behavior
  (SimStruct *c4_S)
{
  const mxArray *c4_out = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_out = NULL;
  sf_mex_assign(&c4_out, sf_internal_get_sim_state_c4_lib_affectiveChar_behavior
                (c4_S), false);
  return c4_out;
}

void sf_exported_auto_setSimstatec4_lib_affectiveChar_behavior(SimStruct *c4_S,
  const mxArray *c4_in)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c4_lib_affectiveChar_behavior(c4_S, sf_mex_dup(c4_in));
  sf_mex_destroy(&c4_in);
}

void sf_exported_auto_check_state_inconsistency_c4_lib_affectiveChar_behavior
  (SimStruct *c4_S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_sendBMLc4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c4_arg
   [256])
{
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c4_i25 = 0; c4_i25 < 256; c4_i25++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i25], 3U);
  }

  _SFD_SET_DATA_VALUE_PTR(3U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  for (c4_i26 = 0; c4_i26 < 256; c4_i26++) {
    (*c4_b_arg)[c4_i26] = c4_arg[c4_i26];
  }

  for (c4_i27 = 0; c4_i27 < 256; c4_i27++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i27], 3U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(3U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
}

static void c4_smileTablec4_lib_affectiveChar_behavior
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c4_bmlID,
   real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[6];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv4[256];
  int32_T c4_i28;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[87];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[87];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i29;
  static char_T c4_cv1[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c4_i30;
  static real_T c4_dv5[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 15);
  if (CV_EML_IF(1, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 16);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 27);
    c4_encStr2Arr(chartInstance, c4_dv4);
    for (c4_i28 = 0; c4_i28 < 256; c4_i28++) {
      c4_poseBML[c4_i28] = c4_dv4[c4_i28];
    }

    c4_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -27);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 17);
    if (CV_EML_IF(1, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 18);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_c_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_h_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
        c4_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_g_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
        c4_d_sf_marshallIn);
      for (c4_i29 = 0; c4_i29 < 87; c4_i29++) {
        c4_mystr[c4_i29] = c4_cv1[c4_i29];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
      c4_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
      for (c4_i30 = 0; c4_i30 < 87; c4_i30++) {
        c4_arr[c4_i30] = c4_dv5[c4_i30];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
      c4_ss = 87.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
      c4_padsize = c4_maxarrsize - c4_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
      for (c4_i31 = 0; c4_i31 < 256; c4_i31++) {
        c4_tt[c4_i31] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
      for (c4_i32 = 0; c4_i32 < 87; c4_i32++) {
        c4_tt[c4_i32] = c4_arr[c4_i32];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
      for (c4_i33 = 0; c4_i33 < 256; c4_i33++) {
        c4_myarr256[c4_i33] = c4_tt[c4_i33];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c4_i34 = 0; c4_i34 < 256; c4_i34++) {
        c4_poseBML[c4_i34] = c4_myarr256[c4_i34];
      }

      c4_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -33);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 20);
      CV_EML_FCN(1, 1);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 27);
      c4_encStr2Arr(chartInstance, c4_dv4);
      for (c4_i35 = 0; c4_i35 < 256; c4_i35++) {
        c4_poseBML[c4_i35] = c4_dv4[c4_i35];
      }

      c4_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_sendBML(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c4_b_sendBML(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void sf_exported_user_c4_lib_affectiveChar_behavior_sendBML(SimStruct *c4_S,
  real_T c4_arg[256])
{
  int32_T c4_i36;
  real_T c4_b_arg[256];
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  for (c4_i36 = 0; c4_i36 < 256; c4_i36++) {
    c4_b_arg[c4_i36] = c4_arg[c4_i36];
  }

  c4_sendBMLc4_lib_affectiveChar_behavior(chartInstance, c4_b_arg);
}

void sf_exported_user_c4_lib_affectiveChar_behavior_smileTable(SimStruct *c4_S,
  real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_smileTablec4_lib_affectiveChar_behavior(chartInstance, c4_bmlID, c4_poseBML);
}

static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i37;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i37, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i37;
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
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_f_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_b_tp_stateInitial, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_stateInitial),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_stateInitial);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_stateInitial;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c4_b_tp_stateInitial = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_stateInitial),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_stateInitial);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_h_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_b_setSimStateSideEffectsInfo, const char_T *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  sf_mex_assign(&c4_y, c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_i_emlrt_marshallIn
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  (void)c4_parentId;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_updateDataWrittenToVector
  (SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c4_vectorIndex)
{
  (void)chartInstance;
  c4_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c4_vectorIndex, 0, 0, 1, 0)] = true;
}

static real_T c4_get_avert(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1202) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_avert_address;
}

static void c4_set_avert(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1202) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_avert_address = c4_c;
}

static real_T *c4_access_avert(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c4_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1202) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_avert_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c4_c;
}

static real_T c4_get_isPosing(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1200) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_isPosing_address;
}

static void c4_set_isPosing(SFc4_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1200) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_isPosing_address = c4_c;
}

static real_T *c4_access_isPosing(SFc4_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c4_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1200) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_isPosing_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c4_c;
}

static void init_dsm_address_info(SFc4_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c4_avert_address, &chartInstance->c4_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c4_isPosing_address, &chartInstance->c4_isPosing_index);
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

void sf_c4_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(837318046U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3948722790U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1799547419U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1639841841U);
}

mxArray *sf_c4_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nUXMIuadCFn7H5tBNxvITB");
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

mxArray *sf_c4_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c4_lib_affectiveChar_behavior\",},{M[9],M[0],T\"is_c4_lib_affectiveChar_behavior\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           4,
           5,
           5,
           0,
           6,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_lib_affectiveChar_behaviorMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _lib_affectiveChar_behaviorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lib_affectiveChar_behaviorMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(1,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(2,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(3,8,0,0,"");
          _SFD_SET_DATA_PROPS(4,8,0,0,"");
          _SFD_SET_DATA_PROPS(5,9,0,0,"");
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

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
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"smileTablec4_lib_affectiveChar_behavior",0,-1,
                             410);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",410,-1,702);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",702,-1,867);
        _SFD_CV_INIT_EML_IF(1,1,0,234,264,295,408);
        _SFD_CV_INIT_EML_IF(1,1,1,295,329,360,408);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,31,1,31);

        {
          static int condStart[] = { 2, 20 };

          static int condEnd[] = { 16, 30 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,31,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,30,1,30);

        {
          static int condStart[] = { 2, 19 };

          static int condEnd[] = { 16, 29 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,30,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(3,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));

        {
          real_T *c4_isSmiling;
          c4_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_avert_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lib_affectiveChar_behaviorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "7FQEvg8ca4fQyPYEI54DBE";
}

static void sf_opaque_initialize_c4_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c4_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c4_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c4_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c4_lib_affectiveChar_behavior
      ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_lib_affectiveChar_behavior
    ((SFc4_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c4_lib_affectiveChar_behavior
      ((SFc4_lib_affectiveChar_behaviorInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,4,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
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
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3142624495U));
  ssSetChecksum1(S,(1016373654U));
  ssSetChecksum2(S,(3498964558U));
  ssSetChecksum3(S,(4247533006U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc4_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc4_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_lib_affectiveChar_behavior;
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

void c4_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
