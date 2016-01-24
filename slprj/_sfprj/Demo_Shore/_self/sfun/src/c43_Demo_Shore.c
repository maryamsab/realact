/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_Shore_sfun.h"
#include "c43_Demo_Shore.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_Shore_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c43_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c43_IN_init                    ((uint8_T)1U)
#define c43_IN_setBehavior             ((uint8_T)2U)
#define c43_IN_wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c43_subchartSimStateInfo;
static const char * c43_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void initialize_params_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void enable_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance);
static void disable_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance);
static void c43_update_debugger_state_c43_Demo_Shore
  (SFc43_Demo_ShoreInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c43_Demo_Shore
  (SFc43_Demo_ShoreInstanceStruct *chartInstance);
static void set_sim_state_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_st);
static void c43_set_sim_state_side_effects_c43_Demo_Shore
  (SFc43_Demo_ShoreInstanceStruct *chartInstance);
static void finalize_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void sf_gateway_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void c43_enter_atomic_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void c43_enter_internal_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void c43_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance);
static void c43_exit_internal_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void c43_initc43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance);
static void initSimStructsc43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber);
static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static real_T c43_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static boolean_T c43_b_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static int32_T c43_c_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static uint8_T c43_d_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_b_tp_init, const char_T *c43_identifier);
static uint8_T c43_e_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_e_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static const mxArray *c43_f_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static const mxArray *c43_f_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_b_subchartSimStateInfo, const char_T
  *c43_identifier);
static const mxArray *c43_g_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static real_T c43_get_avert_gaze_dirs_chance(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_avert_gaze_dirs_chance(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_avert_gaze_dirs_chance(SFc43_Demo_ShoreInstanceStruct *
  chartInstance, uint32_T c43_b);
static real_T c43_get_avert_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct *
  chartInstance, uint32_T c43_b);
static void c43_set_avert_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_avert_gaze_duration_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b);
static real_T c43_get_avert_head_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_avert_head_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_avert_head_frequency_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b);
static real_T c43_get_avert_head_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_avert_head_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_avert_head_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static real_T c43_get_mutual_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_mutual_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_mutual_gaze_duration_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b);
static real_T c43_get_pose_chanc_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_pose_chanc_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_pose_chanc_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static real_T c43_get_pose_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_pose_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_pose_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static real_T c43_get_pose_lean(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b);
static void c43_set_pose_lean(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b, real_T c43_c);
static real_T *c43_access_pose_lean(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static real_T c43_get_pose_lean_flag(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void c43_set_pose_lean_flag(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b, real_T c43_c);
static real_T *c43_access_pose_lean_flag(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static real_T c43_get_pose_selfAdaptor_chance_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b);
static void c43_set_pose_selfAdaptor_chance_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b, real_T c43_c);
static real_T *c43_access_pose_selfAdaptor_chance_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b);
static real_T c43_get_pose_speed(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b);
static void c43_set_pose_speed(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b, real_T c43_c);
static real_T *c43_access_pose_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b);
static void init_dsm_address_info(SFc43_Demo_ShoreInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c43_update_debugger_state_c43_Demo_Shore
  (SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  uint32_T c43_prevAniVal;
  c43_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c43_is_active_c43_Demo_Shore == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 24U, chartInstance->c43_sfEvent);
  }

  if (chartInstance->c43_is_c43_Demo_Shore == c43_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
  }

  if (chartInstance->c43_is_c43_Demo_Shore == c43_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
  }

  if (chartInstance->c43_is_c43_Demo_Shore == c43_IN_setBehavior) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c43_sfEvent);
  }

  _SFD_SET_ANIMATION(c43_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c43_Demo_Shore
  (SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  const mxArray *c43_st;
  const mxArray *c43_y = NULL;
  uint8_T c43_hoistedGlobal;
  uint8_T c43_u;
  const mxArray *c43_b_y = NULL;
  uint8_T c43_b_hoistedGlobal;
  uint8_T c43_b_u;
  const mxArray *c43_c_y = NULL;
  const mxArray *c43_c_u;
  const mxArray *c43_d_y = NULL;
  c43_st = NULL;
  c43_st = NULL;
  sf_mex_assign(&c43_subchartSimStateInfo,
                sf_exported_auto_getSimstatec46_lib_affectiveChar_behavior
                (chartInstance->c43_subchartSimstruct), true);
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_createcellmatrix(3, 1), false);
  c43_hoistedGlobal = chartInstance->c43_is_active_c43_Demo_Shore;
  c43_u = c43_hoistedGlobal;
  c43_b_y = NULL;
  sf_mex_assign(&c43_b_y, sf_mex_create("y", &c43_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 0, c43_b_y);
  c43_b_hoistedGlobal = chartInstance->c43_is_c43_Demo_Shore;
  c43_b_u = c43_b_hoistedGlobal;
  c43_c_y = NULL;
  sf_mex_assign(&c43_c_y, sf_mex_create("y", &c43_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 1, c43_c_y);
  c43_c_u = sf_mex_dup(c43_subchartSimStateInfo);
  c43_d_y = NULL;
  sf_mex_assign(&c43_d_y, sf_mex_duplicatearraysafe(&c43_c_u), false);
  sf_mex_destroy(&c43_c_u);
  sf_mex_setcell(c43_y, 2, c43_d_y);
  sf_mex_assign(&c43_st, c43_y, false);
  return c43_st;
}

static void set_sim_state_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_st)
{
  const mxArray *c43_u;
  c43_u = sf_mex_dup(c43_st);
  chartInstance->c43_is_active_c43_Demo_Shore = c43_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 0)),
     "is_active_c43_Demo_Shore");
  chartInstance->c43_is_c43_Demo_Shore = c43_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 1)), "is_c43_Demo_Shore");
  sf_mex_assign(&c43_subchartSimStateInfo, c43_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 2)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c43_setSimStateSideEffectsInfo,
                c43_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c43_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c43_u);
  chartInstance->c43_doSetSimStateSideEffects = 1U;
  c43_update_debugger_state_c43_Demo_Shore(chartInstance);
  sf_exported_auto_setSimstatec46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct, sf_mex_dup(c43_subchartSimStateInfo));
  sf_mex_destroy(&c43_st);
}

static void c43_set_sim_state_side_effects_c43_Demo_Shore
  (SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  if (chartInstance->c43_doSetSimStateSideEffects != 0) {
    if (chartInstance->c43_is_c43_Demo_Shore == c43_IN_init) {
      chartInstance->c43_tp_init = 1U;
    } else {
      chartInstance->c43_tp_init = 0U;
    }

    if (chartInstance->c43_is_c43_Demo_Shore == c43_IN_setBehavior) {
      chartInstance->c43_tp_setBehavior = 1U;
    } else {
      chartInstance->c43_tp_setBehavior = 0U;
    }

    if (chartInstance->c43_is_c43_Demo_Shore == c43_IN_wait) {
      chartInstance->c43_tp_wait = 1U;
    } else {
      chartInstance->c43_tp_wait = 0U;
    }

    chartInstance->c43_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c43_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c43_setSimStateSideEffectsInfo);
}

static void sf_gateway_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  c43_set_sim_state_side_effects_c43_Demo_Shore(chartInstance);
}

static void c43_enter_atomic_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 24U, chartInstance->c43_sfEvent);
  chartInstance->c43_is_active_c43_Demo_Shore = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c43_sfEvent);
}

static void c43_enter_internal_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  uint32_T c43_debug_family_var_map[2];
  real_T c43_nargin = 0.0;
  real_T c43_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c43_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
  chartInstance->c43_isStable = false;
  chartInstance->c43_is_c43_Demo_Shore = c43_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
  chartInstance->c43_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 0U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 1U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  c43_set_mutual_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c43_set_avert_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c43_set_avert_head_frequency_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c43_set_avert_head_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c43_set_avert_gaze_dirs_chance(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c43_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  uint32_T c43_debug_family_var_map[3];
  real_T c43_nargin = 0.0;
  real_T c43_nargout = 1.0;
  boolean_T c43_out;
  uint32_T c43_b_debug_family_var_map[2];
  real_T c43_b_nargin = 0.0;
  real_T c43_b_nargout = 0.0;
  real_T c43_hoistedGlobal;
  real_T c43_b_hoistedGlobal;
  real_T c43_c_hoistedGlobal;
  boolean_T c43_d_hoistedGlobal;
  boolean_T c43_e_hoistedGlobal;
  real_T c43_v;
  real_T c43_a;
  real_T c43_p;
  boolean_T c43_pFlag;
  boolean_T c43_vaFlag;
  int32_T c43_i0;
  real_T c43_gazeArr[6];
  int32_T c43_i1;
  real_T c43_b_gazeArr[6];
  real_T c43_avertDirsChance;
  real_T c43_avertHeadSpeed;
  real_T c43_avertHeadFreqFactor;
  real_T c43_avertDurFactor;
  real_T c43_mutDurFactor;
  real_T c43_mutual_gaze_duration_factor;
  real_T c43_avert_gaze_duration_factor;
  real_T c43_avert_head_frequency_factor;
  real_T c43_avert_head_speed;
  real_T c43_avert_gaze_dirs_chance;
  real_T c43_f_hoistedGlobal;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  real_T c43_g_hoistedGlobal;
  real_T c43_b_u;
  const mxArray *c43_b_y = NULL;
  real_T c43_h_hoistedGlobal;
  real_T c43_c_u;
  const mxArray *c43_c_y = NULL;
  real_T c43_i_hoistedGlobal;
  real_T c43_d_u;
  const mxArray *c43_d_y = NULL;
  real_T c43_j_hoistedGlobal;
  real_T c43_e_u;
  const mxArray *c43_e_y = NULL;
  real_T c43_k_hoistedGlobal;
  real_T c43_l_hoistedGlobal;
  real_T c43_m_hoistedGlobal;
  boolean_T c43_n_hoistedGlobal;
  boolean_T c43_o_hoistedGlobal;
  boolean_T c43_p_hoistedGlobal;
  real_T c43_b_v;
  real_T c43_ar;
  real_T c43_b_p;
  boolean_T c43_b_pFlag;
  boolean_T c43_b_vaFlag;
  int32_T c43_i2;
  real_T c43_personalityChange;
  int32_T c43_i3;
  real_T c43_c_gazeArr[6];
  real_T c43_poseLeanFlag;
  real_T c43_poseSpeed;
  real_T c43_poseLean;
  real_T c43_poseSelfAdaptChance;
  real_T c43_poseChanceFactor;
  real_T c43_poseFreqFactor;
  real_T c43_pose_frequency_factor;
  real_T c43_pose_chanc_factor;
  real_T c43_pose_selfAdaptor_chance_factor;
  real_T c43_pose_lean;
  real_T c43_pose_speed;
  real_T c43_pose_lean_flag;
  real_T c43_q_hoistedGlobal;
  real_T c43_f_u;
  const mxArray *c43_f_y = NULL;
  real_T c43_r_hoistedGlobal;
  real_T c43_g_u;
  const mxArray *c43_g_y = NULL;
  real_T c43_s_hoistedGlobal;
  real_T c43_h_u;
  const mxArray *c43_h_y = NULL;
  real_T c43_t_hoistedGlobal;
  real_T c43_i_u;
  const mxArray *c43_i_y = NULL;
  real_T c43_u_hoistedGlobal;
  real_T c43_j_u;
  const mxArray *c43_j_y = NULL;
  real_T c43_v_hoistedGlobal;
  real_T c43_k_u;
  const mxArray *c43_k_y = NULL;
  boolean_T *c43_emoChange;
  real_T *c43_inV;
  real_T *c43_inA;
  real_T *c43_personality;
  boolean_T *c43_personalityFlag;
  boolean_T *c43_c_vaFlag;
  boolean_T *c43_b_personalityChange;
  real_T (*c43_poseArray)[6];
  real_T (*c43_gazeArray)[6];
  c43_b_personalityChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
    8);
  c43_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 7);
  c43_c_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c43_personalityFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c43_emoChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c43_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c43_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c43_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c43_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c43_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c43_isStable = true;
  switch (chartInstance->c43_is_c43_Demo_Shore) {
   case c43_IN_init:
    CV_CHART_EVAL(24, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
    chartInstance->c43_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
    chartInstance->c43_isStable = false;
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
    chartInstance->c43_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c43_sfEvent);
    break;

   case c43_IN_setBehavior:
    CV_CHART_EVAL(24, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c43_sfEvent);
    chartInstance->c43_tp_setBehavior = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c43_sfEvent);
    chartInstance->c43_isStable = false;
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
    chartInstance->c43_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c43_sfEvent);
    break;

   case c43_IN_wait:
    CV_CHART_EVAL(24, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c43_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_c_debug_family_names,
      c43_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 0U, c43_sf_marshallOut,
      c43_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 1U, c43_sf_marshallOut,
      c43_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_out, 2U, c43_b_sf_marshallOut,
      c43_b_sf_marshallIn);
    c43_out = CV_EML_IF(1, 0, 0, (real_T)*c43_emoChange == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c43_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c43_sfEvent);
      chartInstance->c43_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
      chartInstance->c43_isStable = false;
      chartInstance->c43_is_c43_Demo_Shore = c43_IN_setBehavior;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c43_sfEvent);
      chartInstance->c43_tp_setBehavior = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_b_debug_family_names,
        c43_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_nargin, 0U, c43_sf_marshallOut,
        c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_nargout, 1U,
        c43_sf_marshallOut, c43_sf_marshallIn);
      c43_hoistedGlobal = *c43_inV;
      c43_b_hoistedGlobal = *c43_inA;
      c43_c_hoistedGlobal = *c43_personality;
      c43_d_hoistedGlobal = *c43_personalityFlag;
      c43_e_hoistedGlobal = *c43_c_vaFlag;
      c43_v = c43_hoistedGlobal;
      c43_a = c43_b_hoistedGlobal;
      c43_p = c43_c_hoistedGlobal;
      c43_pFlag = c43_d_hoistedGlobal;
      c43_vaFlag = c43_e_hoistedGlobal;
      for (c43_i0 = 0; c43_i0 < 6; c43_i0++) {
        c43_gazeArr[c43_i0] = (*c43_gazeArray)[c43_i0];
      }

      for (c43_i1 = 0; c43_i1 < 6; c43_i1++) {
        c43_b_gazeArr[c43_i1] = c43_gazeArr[c43_i1];
      }

      sf_exported_user_c46_lib_affectiveChar_behavior_setGazeFactors
        (chartInstance->c43_subchartSimstruct, c43_v, c43_a, c43_p, c43_pFlag,
         c43_vaFlag, c43_b_gazeArr, &c43_mutDurFactor, &c43_avertDurFactor,
         &c43_avertHeadFreqFactor, &c43_avertHeadSpeed, &c43_avertDirsChance);
      c43_mutual_gaze_duration_factor = c43_mutDurFactor;
      c43_avert_gaze_duration_factor = c43_avertDurFactor;
      c43_avert_head_frequency_factor = c43_avertHeadFreqFactor;
      c43_avert_head_speed = c43_avertHeadSpeed;
      c43_avert_gaze_dirs_chance = c43_avertDirsChance;
      c43_set_mutual_gaze_duration_factor(chartInstance, 0,
        c43_mutual_gaze_duration_factor);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c43_set_avert_gaze_duration_factor(chartInstance, 0,
        c43_avert_gaze_duration_factor);
      ssUpdateDataStoreLog(chartInstance->S, 1);
      c43_set_avert_head_frequency_factor(chartInstance, 0,
        c43_avert_head_frequency_factor);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      c43_set_avert_head_speed(chartInstance, 0, c43_avert_head_speed);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      c43_set_avert_gaze_dirs_chance(chartInstance, 0,
        c43_avert_gaze_dirs_chance);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      sf_mex_printf("%s =\\n", "mutual_gaze_duration_factor");
      c43_f_hoistedGlobal = c43_get_mutual_gaze_duration_factor(chartInstance, 0);
      c43_u = c43_f_hoistedGlobal;
      c43_y = NULL;
      sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_y);
      sf_mex_printf("%s =\\n", "avert_gaze_duration_factor");
      c43_g_hoistedGlobal = c43_get_avert_gaze_duration_factor(chartInstance, 0);
      c43_b_u = c43_g_hoistedGlobal;
      c43_b_y = NULL;
      sf_mex_assign(&c43_b_y, sf_mex_create("y", &c43_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_b_y);
      sf_mex_printf("%s =\\n", "avert_head_frequency_factor");
      c43_h_hoistedGlobal = c43_get_avert_head_frequency_factor(chartInstance, 0);
      c43_c_u = c43_h_hoistedGlobal;
      c43_c_y = NULL;
      sf_mex_assign(&c43_c_y, sf_mex_create("y", &c43_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_c_y);
      sf_mex_printf("%s =\\n", "avert_head_speed");
      c43_i_hoistedGlobal = c43_get_avert_head_speed(chartInstance, 0);
      c43_d_u = c43_i_hoistedGlobal;
      c43_d_y = NULL;
      sf_mex_assign(&c43_d_y, sf_mex_create("y", &c43_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_d_y);
      sf_mex_printf("%s =\\n", "avert_gaze_dirs_chance");
      c43_j_hoistedGlobal = c43_get_avert_gaze_dirs_chance(chartInstance, 0);
      c43_e_u = c43_j_hoistedGlobal;
      c43_e_y = NULL;
      sf_mex_assign(&c43_e_y, sf_mex_create("y", &c43_e_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_e_y);
      c43_k_hoistedGlobal = *c43_inV;
      c43_l_hoistedGlobal = *c43_inA;
      c43_m_hoistedGlobal = *c43_personality;
      c43_n_hoistedGlobal = *c43_personalityFlag;
      c43_o_hoistedGlobal = *c43_c_vaFlag;
      c43_p_hoistedGlobal = *c43_b_personalityChange;
      c43_b_v = c43_k_hoistedGlobal;
      c43_ar = c43_l_hoistedGlobal;
      c43_b_p = c43_m_hoistedGlobal;
      c43_b_pFlag = c43_n_hoistedGlobal;
      c43_b_vaFlag = c43_o_hoistedGlobal;
      for (c43_i2 = 0; c43_i2 < 6; c43_i2++) {
        c43_gazeArr[c43_i2] = (*c43_poseArray)[c43_i2];
      }

      c43_personalityChange = (real_T)c43_p_hoistedGlobal;
      for (c43_i3 = 0; c43_i3 < 6; c43_i3++) {
        c43_c_gazeArr[c43_i3] = c43_gazeArr[c43_i3];
      }

      sf_exported_user_c46_lib_affectiveChar_behavior_setPoseFactors
        (chartInstance->c43_subchartSimstruct, c43_b_v, c43_ar, c43_b_p,
         c43_b_pFlag, c43_b_vaFlag, c43_c_gazeArr, c43_personalityChange,
         &c43_poseFreqFactor, &c43_poseChanceFactor, &c43_poseSelfAdaptChance,
         &c43_poseLean, &c43_poseSpeed, &c43_poseLeanFlag);
      c43_pose_frequency_factor = c43_poseFreqFactor;
      c43_pose_chanc_factor = c43_poseChanceFactor;
      c43_pose_selfAdaptor_chance_factor = c43_poseSelfAdaptChance;
      c43_pose_lean = c43_poseLean;
      c43_pose_speed = c43_poseSpeed;
      c43_pose_lean_flag = c43_poseLeanFlag;
      c43_set_pose_frequency_factor(chartInstance, 0, c43_pose_frequency_factor);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      c43_set_pose_chanc_factor(chartInstance, 0, c43_pose_chanc_factor);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c43_set_pose_selfAdaptor_chance_factor(chartInstance, 0,
        c43_pose_selfAdaptor_chance_factor);
      ssUpdateDataStoreLog(chartInstance->S, 9);
      c43_set_pose_lean(chartInstance, 0, c43_pose_lean);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      c43_set_pose_speed(chartInstance, 0, c43_pose_speed);
      ssUpdateDataStoreLog(chartInstance->S, 10);
      c43_set_pose_lean_flag(chartInstance, 0, c43_pose_lean_flag);
      ssUpdateDataStoreLog(chartInstance->S, 8);
      sf_mex_printf("%s =\\n", "pose_frequency_factor");
      c43_q_hoistedGlobal = c43_get_pose_frequency_factor(chartInstance, 0);
      c43_f_u = c43_q_hoistedGlobal;
      c43_f_y = NULL;
      sf_mex_assign(&c43_f_y, sf_mex_create("y", &c43_f_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_f_y);
      sf_mex_printf("%s =\\n", "pose_chanc_factor");
      c43_r_hoistedGlobal = c43_get_pose_chanc_factor(chartInstance, 0);
      c43_g_u = c43_r_hoistedGlobal;
      c43_g_y = NULL;
      sf_mex_assign(&c43_g_y, sf_mex_create("y", &c43_g_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_g_y);
      sf_mex_printf("%s =\\n", "pose_selfAdaptor_chance_factor");
      c43_s_hoistedGlobal = c43_get_pose_selfAdaptor_chance_factor(chartInstance,
        0);
      c43_h_u = c43_s_hoistedGlobal;
      c43_h_y = NULL;
      sf_mex_assign(&c43_h_y, sf_mex_create("y", &c43_h_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_h_y);
      sf_mex_printf("%s =\\n", "pose_lean");
      c43_t_hoistedGlobal = c43_get_pose_lean(chartInstance, 0);
      c43_i_u = c43_t_hoistedGlobal;
      c43_i_y = NULL;
      sf_mex_assign(&c43_i_y, sf_mex_create("y", &c43_i_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_i_y);
      sf_mex_printf("%s =\\n", "pose_speed");
      c43_u_hoistedGlobal = c43_get_pose_speed(chartInstance, 0);
      c43_j_u = c43_u_hoistedGlobal;
      c43_j_y = NULL;
      sf_mex_assign(&c43_j_y, sf_mex_create("y", &c43_j_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_j_y);
      sf_mex_printf("%s =\\n", "pose_lean_flag");
      c43_v_hoistedGlobal = c43_get_pose_lean_flag(chartInstance, 0);
      c43_k_u = c43_v_hoistedGlobal;
      c43_k_y = NULL;
      sf_mex_assign(&c43_k_y, sf_mex_create("y", &c43_k_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c43_k_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c43_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c43_sfEvent);
    break;

   default:
    CV_CHART_EVAL(24, 0, 0);
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c43_sfEvent);
}

static void c43_exit_internal_c43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c43_is_c43_Demo_Shore) {
   case c43_IN_init:
    CV_CHART_EVAL(24, 0, 1);
    chartInstance->c43_tp_init = 0U;
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
    break;

   case c43_IN_setBehavior:
    CV_CHART_EVAL(24, 0, 2);
    chartInstance->c43_tp_setBehavior = 0U;
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c43_sfEvent);
    break;

   case c43_IN_wait:
    CV_CHART_EVAL(24, 0, 3);
    chartInstance->c43_tp_wait = 0U;
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c43_sfEvent);
    break;

   default:
    CV_CHART_EVAL(24, 0, 0);
    chartInstance->c43_is_c43_Demo_Shore = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c43_sfEvent);
    break;
  }
}

static void c43_initc43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  sf_exported_auto_initc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
  chartInstance->c43_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  c43_subchartSimStateInfo = NULL;
  chartInstance->c43_doSetSimStateSideEffects = 0U;
  chartInstance->c43_setSimStateSideEffectsInfo = NULL;
  chartInstance->c43_tp_init = 0U;
  chartInstance->c43_tp_setBehavior = 0U;
  chartInstance->c43_tp_wait = 0U;
  chartInstance->c43_is_active_c43_Demo_Shore = 0U;
  chartInstance->c43_is_c43_Demo_Shore = c43_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc43_Demo_Shore(SFc43_Demo_ShoreInstanceStruct
  *chartInstance)
{
  chartInstance->c43_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "sharedFunc");
}

static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber)
{
  (void)c43_machineNumber;
  (void)c43_chartNumber;
  (void)c43_instanceNumber;
}

static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(real_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static real_T c43_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  real_T c43_y;
  real_T c43_d0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_d0, 1, 0, 0U, 0, 0U, 0);
  c43_y = c43_d0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_nargout;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_nargout = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_nargout),
    &c43_thisId);
  sf_mex_destroy(&c43_nargout);
  *(real_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  boolean_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(boolean_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static boolean_T c43_b_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  boolean_T c43_y;
  boolean_T c43_b0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_b0, 1, 11, 0U, 0, 0U, 0);
  c43_y = c43_b0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_sf_internal_predicateOutput;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  boolean_T c43_y;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_sf_internal_predicateOutput = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_sf_internal_predicateOutput), &c43_thisId);
  sf_mex_destroy(&c43_sf_internal_predicateOutput);
  *(boolean_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

const mxArray *sf_c43_Demo_Shore_get_eml_resolved_functions_info(void)
{
  const mxArray *c43_nameCaptureInfo = NULL;
  c43_nameCaptureInfo = NULL;
  sf_mex_assign(&c43_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c43_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  return chartInstance->c43_isStable;
}

void sf_exported_auto_duringc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  c43_c43_Demo_Shore(chartInstance);
}

void sf_exported_auto_enterc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
  c43_enter_atomic_c43_Demo_Shore(chartInstance);
  c43_enter_internal_c43_Demo_Shore(chartInstance);
}

void sf_exported_auto_exitc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c43_exit_internal_c43_Demo_Shore(chartInstance);
  sf_exported_auto_disablec46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_gatewayc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_enablec43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_disablec43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_disablec46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_stepBuffersc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  sf_exported_auto_stepBuffersc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_initBuffersc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  sf_exported_auto_initBuffersc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
  sf_exported_auto_initBuffersc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_activate_callc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  chartInstance->c43_sfEvent = CALL_EVENT;
  sf_exported_auto_activate_callc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_increment_call_counterc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  sf_exported_auto_increment_call_counterc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_reset_call_counterc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  sf_exported_auto_reset_call_counterc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_deactivate_callc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  sf_exported_auto_deactivate_callc46_lib_affectiveChar_behavior
    (chartInstance->c43_subchartSimstruct);
}

void sf_exported_auto_initc43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  c43_initc43_Demo_Shore(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec43_Demo_Shore(SimStruct *c43_S)
{
  const mxArray *c43_out = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  c43_out = NULL;
  sf_mex_assign(&c43_out, sf_internal_get_sim_state_c43_Demo_Shore(c43_S), false);
  return c43_out;
}

void sf_exported_auto_setSimstatec43_Demo_Shore(SimStruct *c43_S, const mxArray *
  c43_in)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c43_Demo_Shore(c43_S, sf_mex_dup(c43_in));
  sf_mex_destroy(&c43_in);
}

void sf_exported_auto_check_state_inconsistency_c43_Demo_Shore(SimStruct *c43_S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c43_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_ShoreMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(int32_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static int32_T c43_c_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  int32_T c43_y;
  int32_T c43_i4;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_i4, 1, 6, 0U, 0, 0U, 0);
  c43_y = c43_i4;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_sfEvent;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  int32_T c43_y;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_b_sfEvent = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_sfEvent),
    &c43_thisId);
  sf_mex_destroy(&c43_b_sfEvent);
  *(int32_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  uint8_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(uint8_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static uint8_T c43_d_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_b_tp_init, const char_T *c43_identifier)
{
  uint8_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_tp_init),
    &c43_thisId);
  sf_mex_destroy(&c43_b_tp_init);
  return c43_y;
}

static uint8_T c43_e_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  uint8_T c43_y;
  uint8_T c43_u0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_u0, 1, 3, 0U, 0, 0U, 0);
  c43_y = c43_u0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_tp_init;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  uint8_T c43_y;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_b_tp_init = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_tp_init),
    &c43_thisId);
  sf_mex_destroy(&c43_b_tp_init);
  *(uint8_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_e_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i5;
  real_T c43_b_inData[6];
  int32_T c43_i6;
  real_T c43_u[6];
  const mxArray *c43_y = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i5 = 0; c43_i5 < 6; c43_i5++) {
    c43_b_inData[c43_i5] = (*(real_T (*)[6])c43_inData)[c43_i5];
  }

  for (c43_i6 = 0; c43_i6 < 6; c43_i6++) {
    c43_u[c43_i6] = c43_b_inData[c43_i6];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static const mxArray *c43_f_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  const mxArray *c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = sf_mex_dup(*(const mxArray **)c43_inData);
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_duplicatearraysafe(&c43_u), false);
  sf_mex_destroy(&c43_u);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static const mxArray *c43_f_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_b_subchartSimStateInfo, const char_T
  *c43_identifier)
{
  const mxArray *c43_y = NULL;
  emlrtMsgIdentifier c43_thisId;
  c43_y = NULL;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  sf_mex_assign(&c43_y, c43_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_subchartSimStateInfo), &c43_thisId), false);
  sf_mex_destroy(&c43_b_subchartSimStateInfo);
  return c43_y;
}

static const mxArray *c43_g_emlrt_marshallIn(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  const mxArray *c43_y = NULL;
  (void)chartInstance;
  (void)c43_parentId;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_duplicatearraysafe(&c43_u), false);
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static real_T c43_get_avert_gaze_dirs_chance(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c43_b);
  if (chartInstance->c43_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#725) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_avert_gaze_dirs_chance_address;
}

static void c43_set_avert_gaze_dirs_chance(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c43_b);
  if (chartInstance->c43_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#725) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_avert_gaze_dirs_chance_address = c43_c;
}

static real_T *c43_access_avert_gaze_dirs_chance(SFc43_Demo_ShoreInstanceStruct *
  chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c43_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#725) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_avert_gaze_dirs_chance_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c43_c;
}

static real_T c43_get_avert_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct *
  chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c43_b);
  if (chartInstance->c43_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#722) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_avert_gaze_duration_factor_address;
}

static void c43_set_avert_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c43_b);
  if (chartInstance->c43_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#722) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_avert_gaze_duration_factor_address = c43_c;
}

static real_T *c43_access_avert_gaze_duration_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c43_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#722) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_avert_gaze_duration_factor_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c43_c;
}

static real_T c43_get_avert_head_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c43_b);
  if (chartInstance->c43_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#721) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_avert_head_frequency_factor_address;
}

static void c43_set_avert_head_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c43_b);
  if (chartInstance->c43_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#721) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_avert_head_frequency_factor_address = c43_c;
}

static real_T *c43_access_avert_head_frequency_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c43_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#721) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_avert_head_frequency_factor_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c43_c;
}

static real_T c43_get_avert_head_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c43_b);
  if (chartInstance->c43_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#724) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_avert_head_speed_address;
}

static void c43_set_avert_head_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c43_b);
  if (chartInstance->c43_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#724) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_avert_head_speed_address = c43_c;
}

static real_T *c43_access_avert_head_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c43_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#724) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_avert_head_speed_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c43_c;
}

static real_T c43_get_mutual_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c43_b);
  if (chartInstance->c43_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#723) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_mutual_gaze_duration_factor_address;
}

static void c43_set_mutual_gaze_duration_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c43_b);
  if (chartInstance->c43_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#723) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_mutual_gaze_duration_factor_address = c43_c;
}

static real_T *c43_access_mutual_gaze_duration_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c43_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#723) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_mutual_gaze_duration_factor_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c43_c;
}

static real_T c43_get_pose_chanc_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c43_b);
  if (chartInstance->c43_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#732) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_pose_chanc_factor_address;
}

static void c43_set_pose_chanc_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c43_b);
  if (chartInstance->c43_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#732) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_pose_chanc_factor_address = c43_c;
}

static real_T *c43_access_pose_chanc_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c43_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#732) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_pose_chanc_factor_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c43_c;
}

static real_T c43_get_pose_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c43_b);
  if (chartInstance->c43_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#731) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_pose_frequency_factor_address;
}

static void c43_set_pose_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c43_b);
  if (chartInstance->c43_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#731) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_pose_frequency_factor_address = c43_c;
}

static real_T *c43_access_pose_frequency_factor(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c43_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#731) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_pose_frequency_factor_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c43_c;
}

static real_T c43_get_pose_lean(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c43_b);
  if (chartInstance->c43_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#727) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_pose_lean_address;
}

static void c43_set_pose_lean(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c43_b);
  if (chartInstance->c43_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#727) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_pose_lean_address = c43_c;
}

static real_T *c43_access_pose_lean(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c43_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#727) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_pose_lean_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c43_c;
}

static real_T c43_get_pose_lean_flag(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c43_b);
  if (chartInstance->c43_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#729) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_pose_lean_flag_address;
}

static void c43_set_pose_lean_flag(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c43_b);
  if (chartInstance->c43_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#729) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_pose_lean_flag_address = c43_c;
}

static real_T *c43_access_pose_lean_flag(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c43_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#729) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_pose_lean_flag_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c43_c;
}

static real_T c43_get_pose_selfAdaptor_chance_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c43_b);
  if (chartInstance->c43_pose_selfAdaptor_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_selfAdaptor_chance_factor\' (#730) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_pose_selfAdaptor_chance_factor_address;
}

static void c43_set_pose_selfAdaptor_chance_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c43_b);
  if (chartInstance->c43_pose_selfAdaptor_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_selfAdaptor_chance_factor\' (#730) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_pose_selfAdaptor_chance_factor_address = c43_c;
}

static real_T *c43_access_pose_selfAdaptor_chance_factor
  (SFc43_Demo_ShoreInstanceStruct *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c43_pose_selfAdaptor_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_selfAdaptor_chance_factor\' (#730) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_pose_selfAdaptor_chance_factor_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c43_c;
}

static real_T c43_get_pose_speed(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c43_b);
  if (chartInstance->c43_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#728) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c43_pose_speed_address;
}

static void c43_set_pose_speed(SFc43_Demo_ShoreInstanceStruct *chartInstance,
  uint32_T c43_b, real_T c43_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c43_b);
  if (chartInstance->c43_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#728) in the initialization routine of the chart.\n");
  }

  *chartInstance->c43_pose_speed_address = c43_c;
}

static real_T *c43_access_pose_speed(SFc43_Demo_ShoreInstanceStruct
  *chartInstance, uint32_T c43_b)
{
  real_T *c43_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c43_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#728) in the initialization routine of the chart.\n");
  }

  c43_c = chartInstance->c43_pose_speed_address;
  if (c43_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c43_c;
}

static void init_dsm_address_info(SFc43_Demo_ShoreInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_dirs_chance",
    (void **)&chartInstance->c43_avert_gaze_dirs_chance_address,
    &chartInstance->c43_avert_gaze_dirs_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_duration_factor",
                                (void **)
    &chartInstance->c43_avert_gaze_duration_factor_address,
    &chartInstance->c43_avert_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_frequency_factor",
                                (void **)
    &chartInstance->c43_avert_head_frequency_factor_address,
    &chartInstance->c43_avert_head_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_speed", (void **)
    &chartInstance->c43_avert_head_speed_address,
    &chartInstance->c43_avert_head_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mutual_gaze_duration_factor",
                                (void **)
    &chartInstance->c43_mutual_gaze_duration_factor_address,
    &chartInstance->c43_mutual_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chanc_factor", (void **)
    &chartInstance->c43_pose_chanc_factor_address,
    &chartInstance->c43_pose_chanc_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c43_pose_frequency_factor_address,
    &chartInstance->c43_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c43_pose_lean_address, &chartInstance->c43_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c43_pose_lean_flag_address,
    &chartInstance->c43_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S,
    "pose_selfAdaptor_chance_factor", (void **)
    &chartInstance->c43_pose_selfAdaptor_chance_factor_address,
    &chartInstance->c43_pose_selfAdaptor_chance_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c43_pose_speed_address, &chartInstance->c43_pose_speed_index);
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

void sf_c43_Demo_Shore_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3432588400U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3180306522U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4107873200U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(198897737U);
}

mxArray *sf_c43_Demo_Shore_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("igkLZV55kAIWbKxYE5SKVC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c43_Demo_Shore_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c43_Demo_Shore_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c43_Demo_Shore(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c43_Demo_Shore\",},{M[9],M[0],T\"is_c43_Demo_Shore\",},{M[14],M[119],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c43_Demo_Shore_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc43_Demo_ShoreInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc43_Demo_ShoreInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_ShoreMachineNumber_,
           43,
           4,
           4,
           0,
           20,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_ShoreMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_ShoreMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_ShoreMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(2,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gazeArray");
          _SFD_SET_DATA_PROPS(4,1,1,0,"emoChange");
          _SFD_SET_DATA_PROPS(5,1,1,0,"personalityFlag");
          _SFD_SET_DATA_PROPS(6,1,1,0,"vaFlag");
          _SFD_SET_DATA_PROPS(7,11,0,0,"avert_head_frequency_factor");
          _SFD_SET_DATA_PROPS(8,11,0,0,"avert_gaze_duration_factor");
          _SFD_SET_DATA_PROPS(9,11,0,0,"mutual_gaze_duration_factor");
          _SFD_SET_DATA_PROPS(10,11,0,0,"avert_head_speed");
          _SFD_SET_DATA_PROPS(11,11,0,0,"avert_gaze_dirs_chance");
          _SFD_SET_DATA_PROPS(12,1,1,0,"poseArray");
          _SFD_SET_DATA_PROPS(13,11,0,0,"pose_lean");
          _SFD_SET_DATA_PROPS(14,11,0,0,"pose_speed");
          _SFD_SET_DATA_PROPS(15,11,0,0,"pose_lean_flag");
          _SFD_SET_DATA_PROPS(16,11,0,0,"pose_selfAdaptor_chance_factor");
          _SFD_SET_DATA_PROPS(17,11,0,0,"pose_frequency_factor");
          _SFD_SET_DATA_PROPS(18,11,0,0,"pose_chanc_factor");
          _SFD_SET_DATA_PROPS(19,1,1,0,"personalityChange");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,13,1,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c43_inA;
          real_T *c43_inV;
          real_T *c43_personality;
          boolean_T *c43_emoChange;
          boolean_T *c43_personalityFlag;
          boolean_T *c43_vaFlag;
          boolean_T *c43_personalityChange;
          real_T (*c43_gazeArray)[6];
          real_T (*c43_poseArray)[6];
          c43_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 8);
          c43_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            7);
          c43_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c43_personalityFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 5);
          c43_emoChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c43_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            3);
          c43_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c43_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c43_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c43_inA);
          _SFD_SET_DATA_VALUE_PTR(1U, c43_inV);
          _SFD_SET_DATA_VALUE_PTR(2U, c43_personality);
          _SFD_SET_DATA_VALUE_PTR(3U, *c43_gazeArray);
          _SFD_SET_DATA_VALUE_PTR(4U, c43_emoChange);
          _SFD_SET_DATA_VALUE_PTR(5U, c43_personalityFlag);
          _SFD_SET_DATA_VALUE_PTR(6U, c43_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(7U,
            chartInstance->c43_avert_head_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c43_avert_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(9U,
            chartInstance->c43_mutual_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c43_avert_head_speed_address);
          _SFD_SET_DATA_VALUE_PTR(11U,
            chartInstance->c43_avert_gaze_dirs_chance_address);
          _SFD_SET_DATA_VALUE_PTR(12U, *c43_poseArray);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c43_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c43_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c43_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(16U,
            chartInstance->c43_pose_selfAdaptor_chance_factor_address);
          _SFD_SET_DATA_VALUE_PTR(17U,
            chartInstance->c43_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(18U,
            chartInstance->c43_pose_chanc_factor_address);
          _SFD_SET_DATA_VALUE_PTR(19U, c43_personalityChange);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_ShoreMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "py27Enma4o6YIZYys2hZ8G";
}

static void sf_opaque_initialize_c43_Demo_Shore(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*)
    chartInstanceVar);
  initialize_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c43_Demo_Shore(void *chartInstanceVar)
{
  enable_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c43_Demo_Shore(void *chartInstanceVar)
{
  disable_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c43_Demo_Shore(void *chartInstanceVar)
{
  sf_gateway_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c43_Demo_Shore(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c43_Demo_Shore
    ((SFc43_Demo_ShoreInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c43_Demo_Shore();/* state var info */
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

extern void sf_internal_set_sim_state_c43_Demo_Shore(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c43_Demo_Shore();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c43_Demo_Shore(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c43_Demo_Shore(SimStruct* S, const mxArray
  *st)
{
}

static void sf_opaque_terminate_c43_Demo_Shore(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_Shore_optimization_info();
    }

    finalize_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c43_Demo_Shore(SimStruct *S)
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
    initialize_params_c43_Demo_Shore((SFc43_Demo_ShoreInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c43_Demo_Shore(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_Shore_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      43);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,43,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,43,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,43);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,43,9);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,43);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3017923724U));
  ssSetChecksum1(S,(3425969185U));
  ssSetChecksum2(S,(1194249242U));
  ssSetChecksum3(S,(1069553834U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c43_Demo_Shore(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c43_Demo_Shore(SimStruct *S)
{
  SFc43_Demo_ShoreInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc43_Demo_ShoreInstanceStruct *)utMalloc(sizeof
    (SFc43_Demo_ShoreInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc43_Demo_ShoreInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c43_Demo_Shore;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c43_Demo_Shore;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c43_Demo_Shore;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c43_Demo_Shore;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c43_Demo_Shore;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c43_Demo_Shore;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c43_Demo_Shore;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c43_Demo_Shore;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c43_Demo_Shore;
  chartInstance->chartInfo.mdlStart = mdlStart_c43_Demo_Shore;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c43_Demo_Shore;
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

void c43_Demo_Shore_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c43_Demo_Shore(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c43_Demo_Shore(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c43_Demo_Shore(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c43_Demo_Shore_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
