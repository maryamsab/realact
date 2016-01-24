/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Gaze_sfun.h"
#include "c42_Expriment_Gaze.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Gaze_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c42_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c42_IN_init                    ((uint8_T)1U)
#define c42_IN_setP                    ((uint8_T)2U)
#define c42_IN_wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c42_subchartSimStateInfo;
static const char * c42_debug_family_names[2] = { "nargin", "nargout" };

static const char * c42_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c42_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c42_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void initialize_params_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static void enable_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void disable_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void c42_update_debugger_state_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static void set_sim_state_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c42_st);
static void c42_set_sim_state_side_effects_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static void finalize_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void sf_gateway_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void c42_enter_atomic_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static void c42_enter_internal_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static void c42_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void c42_exit_internal_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance);
static void c42_initc42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);
static void initSimStructsc42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c42_machineNumber, uint32_T
  c42_chartNumber, uint32_T c42_instanceNumber);
static const mxArray *c42_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static real_T c42_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_b_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static boolean_T c42_b_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_c_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static int32_T c42_c_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_d_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static uint8_T c42_d_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_b_tp_setP, const char_T *c42_identifier);
static uint8_T c42_e_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_e_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static const mxArray *c42_f_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static void c42_f_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[11]);
static void c42_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_g_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static const mxArray *c42_g_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c42_b_subchartSimStateInfo, const char_T
  *c42_identifier);
static const mxArray *c42_h_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static real_T c42_get_avert_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_avert_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_avert_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_avert_gaze_dirs_chance(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, uint32_T c42_b);
static void c42_set_avert_gaze_dirs_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_avert_gaze_dirs_chance
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static real_T c42_get_avert_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static void c42_set_avert_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b, real_T
   c42_c);
static real_T *c42_access_avert_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static real_T c42_get_avert_head_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static void c42_set_avert_head_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b, real_T
   c42_c);
static real_T *c42_access_avert_head_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static real_T c42_get_avert_head_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_avert_head_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_avert_head_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_blink_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_blink_flag(SFc42_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c42_b, real_T c42_c);
static real_T *c42_access_blink_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_blinkperiod_max(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_blinkperiod_max(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_blinkperiod_max(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_blinkperiod_min(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_blinkperiod_min(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_blinkperiod_min(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_emotion_amount_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_emotion_amount_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_emotion_amount_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static real_T c42_get_mut_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_mut_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_mut_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_mutual_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static void c42_set_mutual_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b, real_T
   c42_c);
static real_T *c42_access_mutual_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_cat_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_cat_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_cat_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_chanc_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_chanc_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_chanc_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_change_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_change_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_change_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_frequency_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_frequency_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_lean(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_lean(SFc42_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_lean(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_lean_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_lean_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_lean_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_speed(SFc42_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static real_T c42_get_pose_twitch(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void c42_set_pose_twitch(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c);
static real_T *c42_access_pose_twitch(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b);
static void init_dsm_address_info(SFc42_Expriment_GazeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c42_update_debugger_state_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c42_prevAniVal;
  c42_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c42_is_active_c42_Expriment_Gaze == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 22U, chartInstance->c42_sfEvent);
  }

  if (chartInstance->c42_is_c42_Expriment_Gaze == c42_IN_setP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c42_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c42_sfEvent);
  }

  if (chartInstance->c42_is_c42_Expriment_Gaze == c42_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
  }

  if (chartInstance->c42_is_c42_Expriment_Gaze == c42_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
  }

  _SFD_SET_ANIMATION(c42_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  const mxArray *c42_st;
  const mxArray *c42_y = NULL;
  uint8_T c42_hoistedGlobal;
  uint8_T c42_u;
  const mxArray *c42_b_y = NULL;
  uint8_T c42_b_hoistedGlobal;
  uint8_T c42_b_u;
  const mxArray *c42_c_y = NULL;
  const mxArray *c42_c_u;
  const mxArray *c42_d_y = NULL;
  c42_st = NULL;
  c42_st = NULL;
  sf_mex_assign(&c42_subchartSimStateInfo,
                sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
                (chartInstance->c42_subchartSimstruct), true);
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_createcellmatrix(3, 1), false);
  c42_hoistedGlobal = chartInstance->c42_is_active_c42_Expriment_Gaze;
  c42_u = c42_hoistedGlobal;
  c42_b_y = NULL;
  sf_mex_assign(&c42_b_y, sf_mex_create("y", &c42_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c42_y, 0, c42_b_y);
  c42_b_hoistedGlobal = chartInstance->c42_is_c42_Expriment_Gaze;
  c42_b_u = c42_b_hoistedGlobal;
  c42_c_y = NULL;
  sf_mex_assign(&c42_c_y, sf_mex_create("y", &c42_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c42_y, 1, c42_c_y);
  c42_c_u = sf_mex_dup(c42_subchartSimStateInfo);
  c42_d_y = NULL;
  sf_mex_assign(&c42_d_y, sf_mex_duplicatearraysafe(&c42_c_u), false);
  sf_mex_destroy(&c42_c_u);
  sf_mex_setcell(c42_y, 2, c42_d_y);
  sf_mex_assign(&c42_st, c42_y, false);
  return c42_st;
}

static void set_sim_state_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c42_st)
{
  const mxArray *c42_u;
  c42_u = sf_mex_dup(c42_st);
  chartInstance->c42_is_active_c42_Expriment_Gaze = c42_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c42_u, 0)),
     "is_active_c42_Expriment_Gaze");
  chartInstance->c42_is_c42_Expriment_Gaze = c42_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c42_u, 1)),
     "is_c42_Expriment_Gaze");
  sf_mex_assign(&c42_subchartSimStateInfo, c42_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c42_u, 2)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c42_setSimStateSideEffectsInfo,
                c42_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c42_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c42_u);
  chartInstance->c42_doSetSimStateSideEffects = 1U;
  c42_update_debugger_state_c42_Expriment_Gaze(chartInstance);
  sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct, sf_mex_dup(c42_subchartSimStateInfo));
  sf_mex_destroy(&c42_st);
}

static void c42_set_sim_state_side_effects_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  if (chartInstance->c42_doSetSimStateSideEffects != 0) {
    if (chartInstance->c42_is_c42_Expriment_Gaze == c42_IN_init) {
      chartInstance->c42_tp_init = 1U;
    } else {
      chartInstance->c42_tp_init = 0U;
    }

    if (chartInstance->c42_is_c42_Expriment_Gaze == c42_IN_setP) {
      chartInstance->c42_tp_setP = 1U;
    } else {
      chartInstance->c42_tp_setP = 0U;
    }

    if (chartInstance->c42_is_c42_Expriment_Gaze == c42_IN_wait) {
      chartInstance->c42_tp_wait = 1U;
    } else {
      chartInstance->c42_tp_wait = 0U;
    }

    chartInstance->c42_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c42_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c42_setSimStateSideEffectsInfo);
}

static void sf_gateway_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  c42_set_sim_state_side_effects_c42_Expriment_Gaze(chartInstance);
}

static void c42_enter_atomic_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 22U, chartInstance->c42_sfEvent);
  chartInstance->c42_is_active_c42_Expriment_Gaze = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c42_sfEvent);
}

static void c42_enter_internal_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c42_debug_family_var_map[2];
  real_T c42_nargin = 0.0;
  real_T c42_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c42_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c42_sfEvent);
  chartInstance->c42_isStable = false;
  chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
  chartInstance->c42_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c42_b_debug_family_names,
    c42_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_nargin, 0U, c42_sf_marshallOut,
    c42_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_nargout, 1U, c42_sf_marshallOut,
    c42_sf_marshallIn);
  c42_set_mutual_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c42_set_avert_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c42_set_avert_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  c42_set_mut_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c42_set_avert_head_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c42_set_avert_head_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c42_set_avert_gaze_dirs_chance(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c42_set_blink_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c42_set_blinkperiod_min(chartInstance, 0, 5.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c42_set_blinkperiod_max(chartInstance, 0, 9.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c42_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 16);
  c42_set_pose_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c42_set_pose_chanc_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c42_set_pose_cat_chance(chartInstance, 0, 70.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c42_set_pose_lean(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c42_set_pose_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 17);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c42_c42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c42_debug_family_var_map[3];
  real_T c42_nargin = 0.0;
  real_T c42_nargout = 1.0;
  boolean_T c42_out;
  uint32_T c42_b_debug_family_var_map[2];
  real_T c42_b_nargin = 0.0;
  real_T c42_b_nargout = 0.0;
  real_T c42_hoistedGlobal;
  real_T c42_b_hoistedGlobal;
  real_T c42_c_hoistedGlobal;
  boolean_T c42_d_hoistedGlobal;
  boolean_T c42_e_hoistedGlobal;
  boolean_T c42_f_hoistedGlobal;
  real_T c42_v;
  real_T c42_ar;
  real_T c42_p;
  boolean_T c42_pFlag;
  boolean_T c42_vaFlag;
  int32_T c42_i0;
  real_T c42_poseArr[6];
  real_T c42_personalityChange;
  int32_T c42_i1;
  real_T c42_b_poseArr[6];
  real_T c42_poseLeanFlag;
  real_T c42_poseSpeed;
  real_T c42_poseLean;
  real_T c42_poseCatChance;
  real_T c42_poseChanceFactor;
  real_T c42_poseFreqFactor;
  real_T c42_poseTwitch;
  real_T c42_pose_twitch;
  real_T c42_pose_frequency_factor;
  real_T c42_pose_chanc_factor;
  real_T c42_pose_cat_chance;
  real_T c42_pose_lean;
  real_T c42_pose_speed;
  real_T c42_pose_lean_flag;
  boolean_T *c42_b_personalityChange;
  real_T *c42_inV;
  real_T *c42_inA;
  real_T *c42_personality;
  boolean_T *c42_personalityFlag;
  boolean_T *c42_b_vaFlag;
  real_T (*c42_poseArray)[6];
  c42_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 7);
  c42_b_personalityChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
    6);
  c42_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c42_personalityFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c42_b_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c42_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c42_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c42_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c42_isStable = true;
  switch (chartInstance->c42_is_c42_Expriment_Gaze) {
   case c42_IN_init:
    CV_CHART_EVAL(22, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
    chartInstance->c42_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
    chartInstance->c42_isStable = false;
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
    chartInstance->c42_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c42_sfEvent);
    break;

   case c42_IN_setP:
    CV_CHART_EVAL(22, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c42_sfEvent);
    chartInstance->c42_tp_setP = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c42_sfEvent);
    chartInstance->c42_isStable = false;
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
    chartInstance->c42_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c42_sfEvent);
    break;

   case c42_IN_wait:
    CV_CHART_EVAL(22, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                 chartInstance->c42_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c42_c_debug_family_names,
      c42_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_nargin, 0U, c42_sf_marshallOut,
      c42_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_nargout, 1U, c42_sf_marshallOut,
      c42_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_out, 2U, c42_b_sf_marshallOut,
      c42_b_sf_marshallIn);
    c42_out = CV_EML_IF(0, 0, 0, (real_T)*c42_b_personalityChange == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c42_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
      chartInstance->c42_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
      chartInstance->c42_isStable = false;
      chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_setP;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c42_sfEvent);
      chartInstance->c42_tp_setP = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c42_debug_family_names,
        c42_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_b_nargin, 0U, c42_sf_marshallOut,
        c42_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c42_b_nargout, 1U,
        c42_sf_marshallOut, c42_sf_marshallIn);
      c42_hoistedGlobal = *c42_inV;
      c42_b_hoistedGlobal = *c42_inA;
      c42_c_hoistedGlobal = *c42_personality;
      c42_d_hoistedGlobal = *c42_personalityFlag;
      c42_e_hoistedGlobal = *c42_b_vaFlag;
      c42_f_hoistedGlobal = *c42_b_personalityChange;
      c42_v = c42_hoistedGlobal;
      c42_ar = c42_b_hoistedGlobal;
      c42_p = c42_c_hoistedGlobal;
      c42_pFlag = c42_d_hoistedGlobal;
      c42_vaFlag = c42_e_hoistedGlobal;
      for (c42_i0 = 0; c42_i0 < 6; c42_i0++) {
        c42_poseArr[c42_i0] = (*c42_poseArray)[c42_i0];
      }

      c42_personalityChange = (real_T)c42_f_hoistedGlobal;
      for (c42_i1 = 0; c42_i1 < 6; c42_i1++) {
        c42_b_poseArr[c42_i1] = c42_poseArr[c42_i1];
      }

      sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
        (chartInstance->c42_subchartSimstruct, c42_v, c42_ar, c42_p, c42_pFlag,
         c42_vaFlag, c42_b_poseArr, c42_personalityChange, &c42_poseTwitch,
         &c42_poseFreqFactor, &c42_poseChanceFactor, &c42_poseCatChance,
         &c42_poseLean, &c42_poseSpeed, &c42_poseLeanFlag);
      c42_pose_twitch = c42_poseTwitch;
      c42_pose_frequency_factor = c42_poseFreqFactor;
      c42_pose_chanc_factor = c42_poseChanceFactor;
      c42_pose_cat_chance = c42_poseCatChance;
      c42_pose_lean = c42_poseLean;
      c42_pose_speed = c42_poseSpeed;
      c42_pose_lean_flag = c42_poseLeanFlag;
      c42_set_pose_twitch(chartInstance, 0, c42_pose_twitch);
      ssUpdateDataStoreLog(chartInstance->S, 18);
      c42_set_pose_frequency_factor(chartInstance, 0, c42_pose_frequency_factor);
      ssUpdateDataStoreLog(chartInstance->S, 14);
      c42_set_pose_chanc_factor(chartInstance, 0, c42_pose_chanc_factor);
      ssUpdateDataStoreLog(chartInstance->S, 12);
      c42_set_pose_cat_chance(chartInstance, 0, c42_pose_cat_chance);
      ssUpdateDataStoreLog(chartInstance->S, 11);
      c42_set_pose_lean(chartInstance, 0, c42_pose_lean);
      ssUpdateDataStoreLog(chartInstance->S, 15);
      c42_set_pose_speed(chartInstance, 0, c42_pose_speed);
      ssUpdateDataStoreLog(chartInstance->S, 17);
      c42_set_pose_lean_flag(chartInstance, 0, c42_pose_lean_flag);
      ssUpdateDataStoreLog(chartInstance->S, 16);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c42_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c42_sfEvent);
    break;

   default:
    CV_CHART_EVAL(22, 0, 0);
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c42_sfEvent);
}

static void c42_exit_internal_c42_Expriment_Gaze
  (SFc42_Expriment_GazeInstanceStruct *chartInstance)
{
  switch (chartInstance->c42_is_c42_Expriment_Gaze) {
   case c42_IN_init:
    CV_CHART_EVAL(22, 0, 1);
    chartInstance->c42_tp_init = 0U;
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
    break;

   case c42_IN_setP:
    CV_CHART_EVAL(22, 0, 2);
    chartInstance->c42_tp_setP = 0U;
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c42_sfEvent);
    break;

   case c42_IN_wait:
    CV_CHART_EVAL(22, 0, 3);
    chartInstance->c42_tp_wait = 0U;
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c42_sfEvent);
    break;

   default:
    CV_CHART_EVAL(22, 0, 0);
    chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c42_sfEvent);
    break;
  }
}

static void c42_initc42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  sf_exported_auto_initc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
  chartInstance->c42_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  c42_subchartSimStateInfo = NULL;
  chartInstance->c42_doSetSimStateSideEffects = 0U;
  chartInstance->c42_setSimStateSideEffectsInfo = NULL;
  chartInstance->c42_tp_init = 0U;
  chartInstance->c42_tp_setP = 0U;
  chartInstance->c42_tp_wait = 0U;
  chartInstance->c42_is_active_c42_Expriment_Gaze = 0U;
  chartInstance->c42_is_c42_Expriment_Gaze = c42_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc42_Expriment_Gaze(SFc42_Expriment_GazeInstanceStruct *
  chartInstance)
{
  chartInstance->c42_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "sharedFunc");
}

static void init_script_number_translation(uint32_T c42_machineNumber, uint32_T
  c42_chartNumber, uint32_T c42_instanceNumber)
{
  (void)c42_machineNumber;
  (void)c42_chartNumber;
  (void)c42_instanceNumber;
}

static const mxArray *c42_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  real_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(real_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static real_T c42_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  real_T c42_y;
  real_T c42_d0;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_d0, 1, 0, 0U, 0, 0U, 0);
  c42_y = c42_d0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_nargout;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_nargout = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_nargout),
    &c42_thisId);
  sf_mex_destroy(&c42_nargout);
  *(real_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_b_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  boolean_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(boolean_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static boolean_T c42_b_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  boolean_T c42_y;
  boolean_T c42_b0;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_b0, 1, 11, 0U, 0, 0U, 0);
  c42_y = c42_b0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_sf_internal_predicateOutput;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  boolean_T c42_y;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_sf_internal_predicateOutput = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c42_sf_internal_predicateOutput), &c42_thisId);
  sf_mex_destroy(&c42_sf_internal_predicateOutput);
  *(boolean_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

const mxArray *sf_c42_Expriment_Gaze_get_eml_resolved_functions_info(void)
{
  const mxArray *c42_nameCaptureInfo = NULL;
  c42_nameCaptureInfo = NULL;
  sf_mex_assign(&c42_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c42_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  return chartInstance->c42_isStable;
}

void sf_exported_auto_duringc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  c42_c42_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_enterc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
  c42_enter_atomic_c42_Expriment_Gaze(chartInstance);
  c42_enter_internal_c42_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_exitc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c42_exit_internal_c42_Expriment_Gaze(chartInstance);
  sf_exported_auto_disablec50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_gatewayc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_enablec42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_disablec42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_disablec50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_stepBuffersc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_initBuffersc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
  sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_activate_callc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  chartInstance->c42_sfEvent = CALL_EVENT;
  sf_exported_auto_activate_callc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_increment_call_counterc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_reset_call_counterc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_deactivate_callc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior
    (chartInstance->c42_subchartSimstruct);
}

void sf_exported_auto_initc42_Expriment_Gaze(SimStruct *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  c42_initc42_Expriment_Gaze(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec42_Expriment_Gaze(SimStruct *c42_S)
{
  const mxArray *c42_out = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  c42_out = NULL;
  sf_mex_assign(&c42_out, sf_internal_get_sim_state_c42_Expriment_Gaze(c42_S),
                false);
  return c42_out;
}

void sf_exported_auto_setSimstatec42_Expriment_Gaze(SimStruct *c42_S, const
  mxArray *c42_in)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c42_Expriment_Gaze(c42_S, sf_mex_dup(c42_in));
  sf_mex_destroy(&c42_in);
}

void sf_exported_auto_check_state_inconsistency_c42_Expriment_Gaze(SimStruct
  *c42_S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c42_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_GazeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c42_c_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(int32_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static int32_T c42_c_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  int32_T c42_y;
  int32_T c42_i2;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_i2, 1, 6, 0U, 0, 0U, 0);
  c42_y = c42_i2;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_b_sfEvent;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  int32_T c42_y;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_b_sfEvent = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_b_sfEvent),
    &c42_thisId);
  sf_mex_destroy(&c42_b_sfEvent);
  *(int32_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_d_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  uint8_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(uint8_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static uint8_T c42_d_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_b_tp_setP, const char_T *c42_identifier)
{
  uint8_T c42_y;
  emlrtMsgIdentifier c42_thisId;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_b_tp_setP),
    &c42_thisId);
  sf_mex_destroy(&c42_b_tp_setP);
  return c42_y;
}

static uint8_T c42_e_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  uint8_T c42_y;
  uint8_T c42_u0;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_u0, 1, 3, 0U, 0, 0U, 0);
  c42_y = c42_u0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_b_tp_setP;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  uint8_T c42_y;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_b_tp_setP = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_b_tp_setP),
    &c42_thisId);
  sf_mex_destroy(&c42_b_tp_setP);
  *(uint8_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_e_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i3;
  real_T c42_b_inData[6];
  int32_T c42_i4;
  real_T c42_u[6];
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  for (c42_i3 = 0; c42_i3 < 6; c42_i3++) {
    c42_b_inData[c42_i3] = (*(real_T (*)[6])c42_inData)[c42_i3];
  }

  for (c42_i4 = 0; c42_i4 < 6; c42_i4++) {
    c42_u[c42_i4] = c42_b_inData[c42_i4];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static const mxArray *c42_f_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i5;
  real_T c42_b_inData[11];
  int32_T c42_i6;
  real_T c42_u[11];
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  for (c42_i5 = 0; c42_i5 < 11; c42_i5++) {
    c42_b_inData[c42_i5] = (*(real_T (*)[11])c42_inData)[c42_i5];
  }

  for (c42_i6 = 0; c42_i6 < 11; c42_i6++) {
    c42_u[c42_i6] = c42_b_inData[c42_i6];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static void c42_f_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[11])
{
  real_T c42_dv0[11];
  int32_T c42_i7;
  (void)chartInstance;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), c42_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                11);
  for (c42_i7 = 0; c42_i7 < 11; c42_i7++) {
    c42_y[c42_i7] = c42_dv0[c42_i7];
  }

  sf_mex_destroy(&c42_u);
}

static void c42_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_emotion_amount_factor;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y[11];
  int32_T c42_i8;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_emotion_amount_factor = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_emotion_amount_factor),
    &c42_thisId, c42_y);
  sf_mex_destroy(&c42_emotion_amount_factor);
  for (c42_i8 = 0; c42_i8 < 11; c42_i8++) {
    (*(real_T (*)[11])c42_outData)[c42_i8] = c42_y[c42_i8];
  }

  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_g_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  const mxArray *c42_u;
  const mxArray *c42_y = NULL;
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = sf_mex_dup(*(const mxArray **)c42_inData);
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_duplicatearraysafe(&c42_u), false);
  sf_mex_destroy(&c42_u);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, false);
  return c42_mxArrayOutData;
}

static const mxArray *c42_g_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c42_b_subchartSimStateInfo, const char_T
  *c42_identifier)
{
  const mxArray *c42_y = NULL;
  emlrtMsgIdentifier c42_thisId;
  c42_y = NULL;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  sf_mex_assign(&c42_y, c42_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c42_b_subchartSimStateInfo), &c42_thisId), false);
  sf_mex_destroy(&c42_b_subchartSimStateInfo);
  return c42_y;
}

static const mxArray *c42_h_emlrt_marshallIn(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  const mxArray *c42_y = NULL;
  (void)chartInstance;
  (void)c42_parentId;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_duplicatearraysafe(&c42_u), false);
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static real_T c42_get_avert_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c42_b);
  if (chartInstance->c42_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#1332) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_avert_freq_factor_address;
}

static void c42_set_avert_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c42_b);
  if (chartInstance->c42_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#1332) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_avert_freq_factor_address = c42_c;
}

static real_T *c42_access_avert_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c42_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#1332) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_avert_freq_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c42_c;
}

static real_T c42_get_avert_gaze_dirs_chance(SFc42_Expriment_GazeInstanceStruct *
  chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c42_b);
  if (chartInstance->c42_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#1319) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_avert_gaze_dirs_chance_address;
}

static void c42_set_avert_gaze_dirs_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c42_b);
  if (chartInstance->c42_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#1319) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_avert_gaze_dirs_chance_address = c42_c;
}

static real_T *c42_access_avert_gaze_dirs_chance
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c42_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#1319) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_avert_gaze_dirs_chance_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c42_c;
}

static real_T c42_get_avert_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c42_b);
  if (chartInstance->c42_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#1317) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_avert_gaze_duration_factor_address;
}

static void c42_set_avert_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b, real_T
   c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c42_b);
  if (chartInstance->c42_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#1317) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_avert_gaze_duration_factor_address = c42_c;
}

static real_T *c42_access_avert_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c42_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#1317) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_avert_gaze_duration_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c42_c;
}

static real_T c42_get_avert_head_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c42_b);
  if (chartInstance->c42_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#1316) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_avert_head_frequency_factor_address;
}

static void c42_set_avert_head_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b, real_T
   c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c42_b);
  if (chartInstance->c42_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#1316) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_avert_head_frequency_factor_address = c42_c;
}

static real_T *c42_access_avert_head_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c42_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#1316) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_avert_head_frequency_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c42_c;
}

static real_T c42_get_avert_head_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c42_b);
  if (chartInstance->c42_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#1318) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_avert_head_speed_address;
}

static void c42_set_avert_head_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c42_b);
  if (chartInstance->c42_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#1318) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_avert_head_speed_address = c42_c;
}

static real_T *c42_access_avert_head_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c42_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#1318) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_avert_head_speed_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c42_c;
}

static real_T c42_get_blink_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c42_b);
  if (chartInstance->c42_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#1335) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_blink_flag_address;
}

static void c42_set_blink_flag(SFc42_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c42_b);
  if (chartInstance->c42_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#1335) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_blink_flag_address = c42_c;
}

static real_T *c42_access_blink_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c42_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#1335) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_blink_flag_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c42_c;
}

static real_T c42_get_blinkperiod_max(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c42_b);
  if (chartInstance->c42_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#1336) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_blinkperiod_max_address;
}

static void c42_set_blinkperiod_max(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c42_b);
  if (chartInstance->c42_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#1336) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_blinkperiod_max_address = c42_c;
}

static real_T *c42_access_blinkperiod_max(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c42_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#1336) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_blinkperiod_max_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c42_c;
}

static real_T c42_get_blinkperiod_min(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c42_b);
  if (chartInstance->c42_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#1334) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_blinkperiod_min_address;
}

static void c42_set_blinkperiod_min(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c42_b);
  if (chartInstance->c42_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#1334) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_blinkperiod_min_address = c42_c;
}

static real_T *c42_access_blinkperiod_min(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c42_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#1334) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_blinkperiod_min_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c42_c;
}

static real_T c42_get_emotion_amount_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c42_b);
  if (chartInstance->c42_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#1330) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c42_emotion_amount_factor_address)[c42_b];
}

static void c42_set_emotion_amount_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c42_b);
  if (chartInstance->c42_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#1330) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c42_emotion_amount_factor_address)[c42_b] = c42_c;
}

static real_T *c42_access_emotion_amount_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c42_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#1330) in the initialization routine of the chart.\n");
  }

  c42_c = *chartInstance->c42_emotion_amount_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c42_c;
}

static real_T c42_get_mut_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c42_b);
  if (chartInstance->c42_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#1331) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_mut_freq_factor_address;
}

static void c42_set_mut_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c42_b);
  if (chartInstance->c42_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#1331) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_mut_freq_factor_address = c42_c;
}

static real_T *c42_access_mut_freq_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c42_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#1331) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_mut_freq_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c42_c;
}

static real_T c42_get_mutual_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c42_b);
  if (chartInstance->c42_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#1315) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_mutual_gaze_duration_factor_address;
}

static void c42_set_mutual_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b, real_T
   c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c42_b);
  if (chartInstance->c42_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#1315) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_mutual_gaze_duration_factor_address = c42_c;
}

static real_T *c42_access_mutual_gaze_duration_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c42_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#1315) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_mutual_gaze_duration_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_cat_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c42_b);
  if (chartInstance->c42_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#1327) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_cat_chance_address;
}

static void c42_set_pose_cat_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c42_b);
  if (chartInstance->c42_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#1327) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_cat_chance_address = c42_c;
}

static real_T *c42_access_pose_cat_chance(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c42_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#1327) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_cat_chance_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_chanc_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c42_b);
  if (chartInstance->c42_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#1321) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_chanc_factor_address;
}

static void c42_set_pose_chanc_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c42_b);
  if (chartInstance->c42_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#1321) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_chanc_factor_address = c42_c;
}

static real_T *c42_access_pose_chanc_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c42_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#1321) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_chanc_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_change_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c42_b);
  if (chartInstance->c42_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#1324) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_change_flag_address;
}

static void c42_set_pose_change_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c42_b);
  if (chartInstance->c42_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#1324) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_change_flag_address = c42_c;
}

static real_T *c42_access_pose_change_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c42_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#1324) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_change_flag_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_frequency_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c42_b);
  if (chartInstance->c42_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#1322) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_frequency_factor_address;
}

static void c42_set_pose_frequency_factor(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c42_b);
  if (chartInstance->c42_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#1322) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_frequency_factor_address = c42_c;
}

static real_T *c42_access_pose_frequency_factor
  (SFc42_Expriment_GazeInstanceStruct *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c42_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#1322) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_frequency_factor_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_lean(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c42_b);
  if (chartInstance->c42_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#1323) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_lean_address;
}

static void c42_set_pose_lean(SFc42_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c42_b);
  if (chartInstance->c42_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#1323) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_lean_address = c42_c;
}

static real_T *c42_access_pose_lean(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c42_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#1323) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_lean_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_lean_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c42_b);
  if (chartInstance->c42_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#1325) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_lean_flag_address;
}

static void c42_set_pose_lean_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c42_b);
  if (chartInstance->c42_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#1325) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_lean_flag_address = c42_c;
}

static real_T *c42_access_pose_lean_flag(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c42_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#1325) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_lean_flag_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c42_b);
  if (chartInstance->c42_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#1326) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_speed_address;
}

static void c42_set_pose_speed(SFc42_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c42_b);
  if (chartInstance->c42_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#1326) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_speed_address = c42_c;
}

static real_T *c42_access_pose_speed(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c42_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#1326) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_speed_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c42_c;
}

static real_T c42_get_pose_twitch(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c42_b);
  if (chartInstance->c42_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#1333) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c42_pose_twitch_address;
}

static void c42_set_pose_twitch(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b, real_T c42_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c42_b);
  if (chartInstance->c42_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#1333) in the initialization routine of the chart.\n");
  }

  *chartInstance->c42_pose_twitch_address = c42_c;
}

static real_T *c42_access_pose_twitch(SFc42_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c42_b)
{
  real_T *c42_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c42_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#1333) in the initialization routine of the chart.\n");
  }

  c42_c = chartInstance->c42_pose_twitch_address;
  if (c42_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c42_c;
}

static void init_dsm_address_info(SFc42_Expriment_GazeInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_freq_factor", (void **)
    &chartInstance->c42_avert_freq_factor_address,
    &chartInstance->c42_avert_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_dirs_chance",
    (void **)&chartInstance->c42_avert_gaze_dirs_chance_address,
    &chartInstance->c42_avert_gaze_dirs_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_duration_factor",
                                (void **)
    &chartInstance->c42_avert_gaze_duration_factor_address,
    &chartInstance->c42_avert_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_frequency_factor",
                                (void **)
    &chartInstance->c42_avert_head_frequency_factor_address,
    &chartInstance->c42_avert_head_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_speed", (void **)
    &chartInstance->c42_avert_head_speed_address,
    &chartInstance->c42_avert_head_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blink_flag", (void **)
    &chartInstance->c42_blink_flag_address, &chartInstance->c42_blink_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blinkperiod_max", (void **)
    &chartInstance->c42_blinkperiod_max_address,
    &chartInstance->c42_blinkperiod_max_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blinkperiod_min", (void **)
    &chartInstance->c42_blinkperiod_min_address,
    &chartInstance->c42_blinkperiod_min_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "emotion_amount_factor", (void
    **)&chartInstance->c42_emotion_amount_factor_address,
    &chartInstance->c42_emotion_amount_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mut_freq_factor", (void **)
    &chartInstance->c42_mut_freq_factor_address,
    &chartInstance->c42_mut_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mutual_gaze_duration_factor",
                                (void **)
    &chartInstance->c42_mutual_gaze_duration_factor_address,
    &chartInstance->c42_mutual_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_cat_chance", (void **)
    &chartInstance->c42_pose_cat_chance_address,
    &chartInstance->c42_pose_cat_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chanc_factor", (void **)
    &chartInstance->c42_pose_chanc_factor_address,
    &chartInstance->c42_pose_chanc_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_change_flag", (void **)
    &chartInstance->c42_pose_change_flag_address,
    &chartInstance->c42_pose_change_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c42_pose_frequency_factor_address,
    &chartInstance->c42_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c42_pose_lean_address, &chartInstance->c42_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c42_pose_lean_flag_address,
    &chartInstance->c42_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c42_pose_speed_address, &chartInstance->c42_pose_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_twitch", (void **)
    &chartInstance->c42_pose_twitch_address,
    &chartInstance->c42_pose_twitch_index);
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

void sf_c42_Expriment_Gaze_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1003437324U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2133924583U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4238924268U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1299902864U);
}

mxArray *sf_c42_Expriment_Gaze_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hjYKfAatEuC2c3x7oJD87B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c42_Expriment_Gaze_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c42_Expriment_Gaze_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c42_Expriment_Gaze(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c42_Expriment_Gaze\",},{M[9],M[0],T\"is_c42_Expriment_Gaze\",},{M[14],M[123],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c42_Expriment_Gaze_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc42_Expriment_GazeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc42_Expriment_GazeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_GazeMachineNumber_,
           42,
           4,
           4,
           0,
           29,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_GazeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_GazeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_GazeMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(2,1,1,0,"vaFlag");
          _SFD_SET_DATA_PROPS(3,1,1,0,"personalityFlag");
          _SFD_SET_DATA_PROPS(4,1,1,0,"gazeArray");
          _SFD_SET_DATA_PROPS(5,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(6,1,1,0,"personalityChange");
          _SFD_SET_DATA_PROPS(7,11,0,0,"mutual_gaze_duration_factor");
          _SFD_SET_DATA_PROPS(8,11,0,0,"avert_head_frequency_factor");
          _SFD_SET_DATA_PROPS(9,11,0,0,"avert_gaze_duration_factor");
          _SFD_SET_DATA_PROPS(10,11,0,0,"avert_head_speed");
          _SFD_SET_DATA_PROPS(11,11,0,0,"avert_gaze_dirs_chance");
          _SFD_SET_DATA_PROPS(12,1,1,0,"poseArray");
          _SFD_SET_DATA_PROPS(13,11,0,0,"pose_chanc_factor");
          _SFD_SET_DATA_PROPS(14,11,0,0,"pose_frequency_factor");
          _SFD_SET_DATA_PROPS(15,11,0,0,"pose_lean");
          _SFD_SET_DATA_PROPS(16,11,0,0,"pose_change_flag");
          _SFD_SET_DATA_PROPS(17,11,0,0,"pose_lean_flag");
          _SFD_SET_DATA_PROPS(18,11,0,0,"pose_speed");
          _SFD_SET_DATA_PROPS(19,11,0,0,"pose_cat_chance");
          _SFD_SET_DATA_PROPS(20,1,1,0,"internalE");
          _SFD_SET_DATA_PROPS(21,1,1,0,"emotion_amount_custom");
          _SFD_SET_DATA_PROPS(22,11,0,0,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(23,11,0,0,"mut_freq_factor");
          _SFD_SET_DATA_PROPS(24,11,0,0,"avert_freq_factor");
          _SFD_SET_DATA_PROPS(25,11,0,0,"pose_twitch");
          _SFD_SET_DATA_PROPS(26,11,0,0,"blinkperiod_min");
          _SFD_SET_DATA_PROPS(27,11,0,0,"blink_flag");
          _SFD_SET_DATA_PROPS(28,11,0,0,"blinkperiod_max");
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

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,21,1,21);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_f_sf_marshallOut,(MexInFcnForType)
            c42_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)c42_sf_marshallIn);

        {
          real_T *c42_inA;
          real_T *c42_inV;
          boolean_T *c42_vaFlag;
          boolean_T *c42_personalityFlag;
          real_T *c42_personality;
          boolean_T *c42_personalityChange;
          real_T *c42_internalE;
          real_T *c42_emotion_amount_custom;
          real_T (*c42_gazeArray)[6];
          real_T (*c42_poseArray)[6];
          c42_emotion_amount_custom = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 9);
          c42_internalE = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c42_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            7);
          c42_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 6);
          c42_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c42_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            4);
          c42_personalityFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 3);
          c42_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c42_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c42_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c42_inA);
          _SFD_SET_DATA_VALUE_PTR(1U, c42_inV);
          _SFD_SET_DATA_VALUE_PTR(2U, c42_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(3U, c42_personalityFlag);
          _SFD_SET_DATA_VALUE_PTR(4U, *c42_gazeArray);
          _SFD_SET_DATA_VALUE_PTR(5U, c42_personality);
          _SFD_SET_DATA_VALUE_PTR(6U, c42_personalityChange);
          _SFD_SET_DATA_VALUE_PTR(7U,
            chartInstance->c42_mutual_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c42_avert_head_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(9U,
            chartInstance->c42_avert_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c42_avert_head_speed_address);
          _SFD_SET_DATA_VALUE_PTR(11U,
            chartInstance->c42_avert_gaze_dirs_chance_address);
          _SFD_SET_DATA_VALUE_PTR(12U, *c42_poseArray);
          _SFD_SET_DATA_VALUE_PTR(13U,
            chartInstance->c42_pose_chanc_factor_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c42_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c42_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(16U,
            chartInstance->c42_pose_change_flag_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c42_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c42_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(19U,
            chartInstance->c42_pose_cat_chance_address);
          _SFD_SET_DATA_VALUE_PTR(20U, c42_internalE);
          _SFD_SET_DATA_VALUE_PTR(21U, c42_emotion_amount_custom);
          _SFD_SET_DATA_VALUE_PTR(22U,
            *chartInstance->c42_emotion_amount_factor_address);
          _SFD_SET_DATA_VALUE_PTR(23U,
            chartInstance->c42_mut_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(24U,
            chartInstance->c42_avert_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c42_pose_twitch_address);
          _SFD_SET_DATA_VALUE_PTR(26U,
            chartInstance->c42_blinkperiod_min_address);
          _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c42_blink_flag_address);
          _SFD_SET_DATA_VALUE_PTR(28U,
            chartInstance->c42_blinkperiod_max_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_GazeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "IEJpXsuebE2TOTqMuRL2CD";
}

static void sf_opaque_initialize_c42_Expriment_Gaze(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
  initialize_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c42_Expriment_Gaze(void *chartInstanceVar)
{
  enable_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c42_Expriment_Gaze(void *chartInstanceVar)
{
  disable_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c42_Expriment_Gaze(void *chartInstanceVar)
{
  sf_gateway_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c42_Expriment_Gaze(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c42_Expriment_Gaze
    ((SFc42_Expriment_GazeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c42_Expriment_Gaze();/* state var info */
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

extern void sf_internal_set_sim_state_c42_Expriment_Gaze(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c42_Expriment_Gaze();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c42_Expriment_Gaze(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c42_Expriment_Gaze(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c42_Expriment_Gaze(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc42_Expriment_GazeInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Gaze_optimization_info();
    }

    finalize_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
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
  initSimStructsc42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c42_Expriment_Gaze(SimStruct *S)
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
    initialize_params_c42_Expriment_Gaze((SFc42_Expriment_GazeInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c42_Expriment_Gaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Gaze_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      42);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,42,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,42,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,42);
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
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,42,10);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,42);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(372587348U));
  ssSetChecksum1(S,(1056700330U));
  ssSetChecksum2(S,(4074114343U));
  ssSetChecksum3(S,(1035370462U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c42_Expriment_Gaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c42_Expriment_Gaze(SimStruct *S)
{
  SFc42_Expriment_GazeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc42_Expriment_GazeInstanceStruct *)utMalloc(sizeof
    (SFc42_Expriment_GazeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc42_Expriment_GazeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c42_Expriment_Gaze;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c42_Expriment_Gaze;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c42_Expriment_Gaze;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c42_Expriment_Gaze;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c42_Expriment_Gaze;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c42_Expriment_Gaze;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c42_Expriment_Gaze;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c42_Expriment_Gaze;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c42_Expriment_Gaze;
  chartInstance->chartInfo.mdlStart = mdlStart_c42_Expriment_Gaze;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c42_Expriment_Gaze;
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

void c42_Expriment_Gaze_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c42_Expriment_Gaze(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c42_Expriment_Gaze(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c42_Expriment_Gaze(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c42_Expriment_Gaze_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
