/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Pose_sfun.h"
#include "c44_Expriment_Pose.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Pose_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c44_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c44_IN_init                    ((uint8_T)1U)
#define c44_IN_setP                    ((uint8_T)2U)
#define c44_IN_setP1                   ((uint8_T)3U)
#define c44_IN_wait                    ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c44_subchartSimStateInfo;
static const char * c44_debug_family_names[2] = { "nargin", "nargout" };

static const char * c44_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c44_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c44_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c44_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c44_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c44_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void initialize_params_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static void enable_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void disable_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void c44_update_debugger_state_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static void set_sim_state_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c44_st);
static void c44_set_sim_state_side_effects_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static void finalize_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void sf_gateway_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void c44_enter_atomic_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static void c44_enter_internal_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static void c44_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void c44_exit_internal_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance);
static void c44_initc44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);
static void initSimStructsc44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c44_machineNumber, uint32_T
  c44_chartNumber, uint32_T c44_instanceNumber);
static const mxArray *c44_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static real_T c44_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_b_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static boolean_T c44_b_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_c_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static int32_T c44_c_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_d_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static uint8_T c44_d_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_b_tp_setP, const char_T *c44_identifier);
static uint8_T c44_e_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_e_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_f_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static void c44_f_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[11]);
static void c44_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_g_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_g_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c44_b_subchartSimStateInfo, const char_T
  *c44_identifier);
static const mxArray *c44_h_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static real_T c44_get_avert_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_avert_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_avert_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_avert_gaze_dirs_chance(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, uint32_T c44_b);
static void c44_set_avert_gaze_dirs_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_avert_gaze_dirs_chance
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static real_T c44_get_avert_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static void c44_set_avert_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b, real_T
   c44_c);
static real_T *c44_access_avert_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static real_T c44_get_avert_head_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static void c44_set_avert_head_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b, real_T
   c44_c);
static real_T *c44_access_avert_head_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static real_T c44_get_avert_head_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_avert_head_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_avert_head_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_emotion_amount_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_emotion_amount_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_emotion_amount_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static real_T c44_get_mut_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_mut_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_mut_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_mutual_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static void c44_set_mutual_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b, real_T
   c44_c);
static real_T *c44_access_mutual_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_cat_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_cat_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_cat_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_chanc_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_chanc_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_chanc_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_frequency_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_frequency_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_lean(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_lean(SFc44_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_lean(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_lean_flag(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_lean_flag(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_lean_flag(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_speed(SFc44_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static real_T c44_get_pose_twitch(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void c44_set_pose_twitch(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c);
static real_T *c44_access_pose_twitch(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b);
static void init_dsm_address_info(SFc44_Expriment_PoseInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c44_update_debugger_state_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  uint32_T c44_prevAniVal;
  c44_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c44_is_active_c44_Expriment_Pose == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 24U, chartInstance->c44_sfEvent);
  }

  if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_setP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c44_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c44_sfEvent);
  }

  if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
  }

  if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
  }

  if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_setP1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c44_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c44_sfEvent);
  }

  _SFD_SET_ANIMATION(c44_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  const mxArray *c44_st;
  const mxArray *c44_y = NULL;
  uint8_T c44_hoistedGlobal;
  uint8_T c44_u;
  const mxArray *c44_b_y = NULL;
  uint8_T c44_b_hoistedGlobal;
  uint8_T c44_b_u;
  const mxArray *c44_c_y = NULL;
  const mxArray *c44_c_u;
  const mxArray *c44_d_y = NULL;
  c44_st = NULL;
  c44_st = NULL;
  sf_mex_assign(&c44_subchartSimStateInfo,
                sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
                (chartInstance->c44_subchartSimstruct), true);
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_createcellmatrix(3, 1), false);
  c44_hoistedGlobal = chartInstance->c44_is_active_c44_Expriment_Pose;
  c44_u = c44_hoistedGlobal;
  c44_b_y = NULL;
  sf_mex_assign(&c44_b_y, sf_mex_create("y", &c44_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c44_y, 0, c44_b_y);
  c44_b_hoistedGlobal = chartInstance->c44_is_c44_Expriment_Pose;
  c44_b_u = c44_b_hoistedGlobal;
  c44_c_y = NULL;
  sf_mex_assign(&c44_c_y, sf_mex_create("y", &c44_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c44_y, 1, c44_c_y);
  c44_c_u = sf_mex_dup(c44_subchartSimStateInfo);
  c44_d_y = NULL;
  sf_mex_assign(&c44_d_y, sf_mex_duplicatearraysafe(&c44_c_u), false);
  sf_mex_destroy(&c44_c_u);
  sf_mex_setcell(c44_y, 2, c44_d_y);
  sf_mex_assign(&c44_st, c44_y, false);
  return c44_st;
}

static void set_sim_state_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c44_st)
{
  const mxArray *c44_u;
  c44_u = sf_mex_dup(c44_st);
  chartInstance->c44_is_active_c44_Expriment_Pose = c44_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c44_u, 0)),
     "is_active_c44_Expriment_Pose");
  chartInstance->c44_is_c44_Expriment_Pose = c44_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c44_u, 1)),
     "is_c44_Expriment_Pose");
  sf_mex_assign(&c44_subchartSimStateInfo, c44_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c44_u, 2)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c44_setSimStateSideEffectsInfo,
                c44_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c44_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c44_u);
  chartInstance->c44_doSetSimStateSideEffects = 1U;
  c44_update_debugger_state_c44_Expriment_Pose(chartInstance);
  sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct, sf_mex_dup(c44_subchartSimStateInfo));
  sf_mex_destroy(&c44_st);
}

static void c44_set_sim_state_side_effects_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  if (chartInstance->c44_doSetSimStateSideEffects != 0) {
    if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_init) {
      chartInstance->c44_tp_init = 1U;
    } else {
      chartInstance->c44_tp_init = 0U;
    }

    if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_setP) {
      chartInstance->c44_tp_setP = 1U;
    } else {
      chartInstance->c44_tp_setP = 0U;
    }

    if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_setP1) {
      chartInstance->c44_tp_setP1 = 1U;
    } else {
      chartInstance->c44_tp_setP1 = 0U;
    }

    if (chartInstance->c44_is_c44_Expriment_Pose == c44_IN_wait) {
      chartInstance->c44_tp_wait = 1U;
    } else {
      chartInstance->c44_tp_wait = 0U;
    }

    chartInstance->c44_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c44_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c44_setSimStateSideEffectsInfo);
}

static void sf_gateway_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  c44_set_sim_state_side_effects_c44_Expriment_Pose(chartInstance);
}

static void c44_enter_atomic_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
  chartInstance->c44_is_active_c44_Expriment_Pose = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
}

static void c44_enter_internal_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  uint32_T c44_debug_family_var_map[2];
  real_T c44_nargin = 0.0;
  real_T c44_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c44_sfEvent);
  chartInstance->c44_isStable = false;
  chartInstance->c44_is_c44_Expriment_Pose = c44_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
  chartInstance->c44_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c44_b_debug_family_names,
    c44_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_nargin, 0U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_nargout, 1U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  c44_set_mutual_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c44_set_avert_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c44_set_avert_head_frequency_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c44_set_avert_head_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c44_set_avert_gaze_dirs_chance(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c44_set_avert_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  c44_set_mut_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c44_set_pose_frequency_factor(chartInstance, 0, 5.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c44_set_pose_chanc_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c44_set_pose_cat_chance(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c44_set_pose_lean(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c44_set_pose_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c44_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c44_c44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  uint32_T c44_debug_family_var_map[3];
  real_T c44_nargin = 0.0;
  real_T c44_nargout = 1.0;
  boolean_T c44_out;
  uint32_T c44_b_debug_family_var_map[2];
  real_T c44_b_nargin = 0.0;
  real_T c44_b_nargout = 0.0;
  real_T c44_hoistedGlobal;
  real_T c44_b_hoistedGlobal;
  real_T c44_c_hoistedGlobal;
  boolean_T c44_d_hoistedGlobal;
  boolean_T c44_e_hoistedGlobal;
  real_T c44_v;
  real_T c44_a;
  real_T c44_p;
  boolean_T c44_pFlag;
  boolean_T c44_vaFlag;
  real_T c44_b_v;
  real_T c44_b_a;
  real_T c44_b_p;
  boolean_T c44_b_pFlag;
  boolean_T c44_b_vaFlag;
  int32_T c44_i0;
  real_T c44_poseArr[6];
  int32_T c44_i1;
  real_T c44_b_poseArr[6];
  real_T c44_blinkPeriodMax;
  real_T c44_blinkPeriodMin;
  real_T c44_blinkFlag;
  real_T c44_mutFreqFactor;
  real_T c44_avertFreqFactor;
  real_T c44_avertDirsChance;
  real_T c44_avertHeadSpeed;
  real_T c44_avertHeadFreqFactor;
  real_T c44_avertDurFactor;
  real_T c44_mutDurFactor;
  real_T c44_b_mutDurFactor;
  real_T c44_b_avertDurFactor;
  real_T c44_b_avertHeadFreqFactor;
  real_T c44_b_avertHeadSpeed;
  real_T c44_b_avertDirsChance;
  real_T c44_b_avertFreqFactor;
  real_T c44_b_mutFreqFactor;
  real_T c44_mutual_gaze_duration_factor;
  real_T c44_avert_gaze_duration_factor;
  real_T c44_avert_head_frequency_factor;
  real_T c44_avert_head_speed;
  real_T c44_avert_gaze_dirs_chance;
  real_T c44_avert_freq_factor;
  real_T c44_mut_freq_factor;
  real_T c44_c_nargin = 0.0;
  real_T c44_c_nargout = 1.0;
  boolean_T c44_b_out;
  real_T c44_d_nargin = 0.0;
  real_T c44_d_nargout = 0.0;
  real_T c44_f_hoistedGlobal;
  real_T c44_g_hoistedGlobal;
  real_T c44_h_hoistedGlobal;
  boolean_T c44_i_hoistedGlobal;
  boolean_T c44_j_hoistedGlobal;
  boolean_T c44_k_hoistedGlobal;
  real_T c44_c_v;
  real_T c44_ar;
  real_T c44_c_p;
  boolean_T c44_c_pFlag;
  boolean_T c44_c_vaFlag;
  int32_T c44_i2;
  real_T c44_personalityChange;
  int32_T c44_i3;
  real_T c44_c_poseArr[6];
  real_T c44_poseLeanFlag;
  real_T c44_poseSpeed;
  real_T c44_poseLean;
  real_T c44_poseCatChance;
  real_T c44_poseChanceFactor;
  real_T c44_poseFreqFactor;
  real_T c44_poseTwitch;
  real_T c44_pose_twitch;
  real_T c44_pose_frequency_factor;
  real_T c44_pose_chanc_factor;
  real_T c44_pose_cat_chance;
  real_T c44_pose_lean;
  real_T c44_pose_speed;
  real_T c44_pose_lean_flag;
  real_T *c44_inV;
  real_T *c44_inA;
  real_T *c44_personality;
  boolean_T *c44_personalityFlag;
  boolean_T *c44_d_vaFlag;
  boolean_T *c44_b_personalityChange;
  real_T (*c44_gazeArray)[6];
  real_T (*c44_poseArray)[6];
  c44_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 7);
  c44_b_personalityChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
    6);
  c44_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c44_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 4);
  c44_personalityFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c44_d_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c44_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c44_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c44_isStable = true;
  switch (chartInstance->c44_is_c44_Expriment_Pose) {
   case c44_IN_init:
    CV_CHART_EVAL(24, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c44_sfEvent);
    chartInstance->c44_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
    chartInstance->c44_isStable = false;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
    chartInstance->c44_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c44_sfEvent);
    break;

   case c44_IN_setP:
    CV_CHART_EVAL(24, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c44_sfEvent);
    chartInstance->c44_tp_setP = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c44_sfEvent);
    chartInstance->c44_isStable = false;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
    chartInstance->c44_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c44_sfEvent);
    break;

   case c44_IN_setP1:
    CV_CHART_EVAL(24, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c44_sfEvent);
    chartInstance->c44_tp_setP1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c44_sfEvent);
    chartInstance->c44_isStable = false;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
    chartInstance->c44_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c44_sfEvent);
    break;

   case c44_IN_wait:
    CV_CHART_EVAL(24, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                 chartInstance->c44_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c44_d_debug_family_names,
      c44_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_nargin, 0U, c44_sf_marshallOut,
      c44_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_nargout, 1U, c44_sf_marshallOut,
      c44_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_out, 2U, c44_b_sf_marshallOut,
      c44_b_sf_marshallIn);
    c44_out = CV_EML_IF(0, 0, 0, (*c44_gazeArray)[0] == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c44_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
      chartInstance->c44_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
      chartInstance->c44_isStable = false;
      chartInstance->c44_is_c44_Expriment_Pose = c44_IN_setP;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c44_sfEvent);
      chartInstance->c44_tp_setP = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c44_debug_family_names,
        c44_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_b_nargin, 0U, c44_sf_marshallOut,
        c44_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_b_nargout, 1U,
        c44_sf_marshallOut, c44_sf_marshallIn);
      c44_hoistedGlobal = *c44_inV;
      c44_b_hoistedGlobal = *c44_inA;
      c44_c_hoistedGlobal = *c44_personality;
      c44_d_hoistedGlobal = *c44_personalityFlag;
      c44_e_hoistedGlobal = *c44_d_vaFlag;
      c44_v = c44_hoistedGlobal;
      c44_a = c44_b_hoistedGlobal;
      c44_p = c44_c_hoistedGlobal;
      c44_pFlag = c44_d_hoistedGlobal;
      c44_vaFlag = c44_e_hoistedGlobal;
      c44_b_v = c44_v;
      c44_b_a = c44_a;
      c44_b_p = c44_p;
      c44_b_pFlag = c44_pFlag;
      c44_b_vaFlag = c44_vaFlag;
      for (c44_i0 = 0; c44_i0 < 6; c44_i0++) {
        c44_poseArr[c44_i0] = (*c44_gazeArray)[c44_i0];
      }

      for (c44_i1 = 0; c44_i1 < 6; c44_i1++) {
        c44_b_poseArr[c44_i1] = c44_poseArr[c44_i1];
      }

      sf_exported_user_c50_lib_affectiveChar_behavior_setGazeFactors
        (chartInstance->c44_subchartSimstruct, c44_b_v, c44_b_a, c44_b_p,
         c44_b_pFlag, c44_b_vaFlag, c44_b_poseArr, &c44_mutDurFactor,
         &c44_avertDurFactor, &c44_avertHeadFreqFactor, &c44_avertHeadSpeed,
         &c44_avertDirsChance, &c44_avertFreqFactor, &c44_mutFreqFactor,
         &c44_blinkFlag, &c44_blinkPeriodMin, &c44_blinkPeriodMax);
      c44_b_mutDurFactor = c44_mutDurFactor;
      c44_b_avertDurFactor = c44_avertDurFactor;
      c44_b_avertHeadFreqFactor = c44_avertHeadFreqFactor;
      c44_b_avertHeadSpeed = c44_avertHeadSpeed;
      c44_b_avertDirsChance = c44_avertDirsChance;
      c44_b_avertFreqFactor = c44_avertFreqFactor;
      c44_b_mutFreqFactor = c44_mutFreqFactor;
      c44_mutual_gaze_duration_factor = c44_b_mutDurFactor;
      c44_avert_gaze_duration_factor = c44_b_avertDurFactor;
      c44_avert_head_frequency_factor = c44_b_avertHeadFreqFactor;
      c44_avert_head_speed = c44_b_avertHeadSpeed;
      c44_avert_gaze_dirs_chance = c44_b_avertDirsChance;
      c44_avert_freq_factor = c44_b_avertFreqFactor;
      c44_mut_freq_factor = c44_b_mutFreqFactor;
      c44_set_mutual_gaze_duration_factor(chartInstance, 0,
        c44_mutual_gaze_duration_factor);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      c44_set_avert_gaze_duration_factor(chartInstance, 0,
        c44_avert_gaze_duration_factor);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      c44_set_avert_head_frequency_factor(chartInstance, 0,
        c44_avert_head_frequency_factor);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      c44_set_avert_head_speed(chartInstance, 0, c44_avert_head_speed);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c44_set_avert_gaze_dirs_chance(chartInstance, 0,
        c44_avert_gaze_dirs_chance);
      ssUpdateDataStoreLog(chartInstance->S, 1);
      c44_set_avert_freq_factor(chartInstance, 0, c44_avert_freq_factor);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      c44_set_mut_freq_factor(chartInstance, 0, c44_mut_freq_factor);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c44_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c44_e_debug_family_names,
        c44_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_c_nargin, 0U, c44_sf_marshallOut,
        c44_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_c_nargout, 1U,
        c44_sf_marshallOut, c44_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_b_out, 2U, c44_b_sf_marshallOut,
        c44_b_sf_marshallIn);
      c44_b_out = CV_EML_IF(4, 0, 0, (*c44_poseArray)[0] == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c44_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
        chartInstance->c44_tp_wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
        chartInstance->c44_isStable = false;
        chartInstance->c44_is_c44_Expriment_Pose = c44_IN_setP1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c44_sfEvent);
        chartInstance->c44_tp_setP1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c44_c_debug_family_names,
          c44_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_d_nargin, 0U,
          c44_sf_marshallOut, c44_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c44_d_nargout, 1U,
          c44_sf_marshallOut, c44_sf_marshallIn);
        c44_f_hoistedGlobal = *c44_inV;
        c44_g_hoistedGlobal = *c44_inA;
        c44_h_hoistedGlobal = *c44_personality;
        c44_i_hoistedGlobal = *c44_personalityFlag;
        c44_j_hoistedGlobal = *c44_d_vaFlag;
        c44_k_hoistedGlobal = *c44_b_personalityChange;
        c44_c_v = c44_f_hoistedGlobal;
        c44_ar = c44_g_hoistedGlobal;
        c44_c_p = c44_h_hoistedGlobal;
        c44_c_pFlag = c44_i_hoistedGlobal;
        c44_c_vaFlag = c44_j_hoistedGlobal;
        for (c44_i2 = 0; c44_i2 < 6; c44_i2++) {
          c44_poseArr[c44_i2] = (*c44_poseArray)[c44_i2];
        }

        c44_personalityChange = (real_T)c44_k_hoistedGlobal;
        for (c44_i3 = 0; c44_i3 < 6; c44_i3++) {
          c44_c_poseArr[c44_i3] = c44_poseArr[c44_i3];
        }

        sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
          (chartInstance->c44_subchartSimstruct, c44_c_v, c44_ar, c44_c_p,
           c44_c_pFlag, c44_c_vaFlag, c44_c_poseArr, c44_personalityChange,
           &c44_poseTwitch, &c44_poseFreqFactor, &c44_poseChanceFactor,
           &c44_poseCatChance, &c44_poseLean, &c44_poseSpeed, &c44_poseLeanFlag);
        c44_pose_twitch = c44_poseTwitch;
        c44_pose_frequency_factor = c44_poseFreqFactor;
        c44_pose_chanc_factor = c44_poseChanceFactor;
        c44_pose_cat_chance = c44_poseCatChance;
        c44_pose_lean = c44_poseLean;
        c44_pose_speed = c44_poseSpeed;
        c44_pose_lean_flag = c44_poseLeanFlag;
        c44_set_pose_twitch(chartInstance, 0, c44_pose_twitch);
        ssUpdateDataStoreLog(chartInstance->S, 14);
        c44_set_pose_frequency_factor(chartInstance, 0,
          c44_pose_frequency_factor);
        ssUpdateDataStoreLog(chartInstance->S, 10);
        c44_set_pose_chanc_factor(chartInstance, 0, c44_pose_chanc_factor);
        ssUpdateDataStoreLog(chartInstance->S, 9);
        c44_set_pose_cat_chance(chartInstance, 0, c44_pose_cat_chance);
        ssUpdateDataStoreLog(chartInstance->S, 8);
        c44_set_pose_lean(chartInstance, 0, c44_pose_lean);
        ssUpdateDataStoreLog(chartInstance->S, 11);
        c44_set_pose_speed(chartInstance, 0, c44_pose_speed);
        ssUpdateDataStoreLog(chartInstance->S, 13);
        c44_set_pose_lean_flag(chartInstance, 0, c44_pose_lean_flag);
        ssUpdateDataStoreLog(chartInstance->S, 12);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c44_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c44_sfEvent);
    break;

   default:
    CV_CHART_EVAL(24, 0, 0);
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c44_sfEvent);
}

static void c44_exit_internal_c44_Expriment_Pose
  (SFc44_Expriment_PoseInstanceStruct *chartInstance)
{
  switch (chartInstance->c44_is_c44_Expriment_Pose) {
   case c44_IN_init:
    CV_CHART_EVAL(24, 0, 1);
    chartInstance->c44_tp_init = 0U;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
    break;

   case c44_IN_setP:
    CV_CHART_EVAL(24, 0, 2);
    chartInstance->c44_tp_setP = 0U;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c44_sfEvent);
    break;

   case c44_IN_setP1:
    CV_CHART_EVAL(24, 0, 3);
    chartInstance->c44_tp_setP1 = 0U;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c44_sfEvent);
    break;

   case c44_IN_wait:
    CV_CHART_EVAL(24, 0, 4);
    chartInstance->c44_tp_wait = 0U;
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c44_sfEvent);
    break;

   default:
    CV_CHART_EVAL(24, 0, 0);
    chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c44_sfEvent);
    break;
  }
}

static void c44_initc44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  sf_exported_auto_initc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
  chartInstance->c44_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  c44_subchartSimStateInfo = NULL;
  chartInstance->c44_doSetSimStateSideEffects = 0U;
  chartInstance->c44_setSimStateSideEffectsInfo = NULL;
  chartInstance->c44_tp_init = 0U;
  chartInstance->c44_tp_setP = 0U;
  chartInstance->c44_tp_setP1 = 0U;
  chartInstance->c44_tp_wait = 0U;
  chartInstance->c44_is_active_c44_Expriment_Pose = 0U;
  chartInstance->c44_is_c44_Expriment_Pose = c44_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc44_Expriment_Pose(SFc44_Expriment_PoseInstanceStruct *
  chartInstance)
{
  chartInstance->c44_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "sharedFunc");
}

static void init_script_number_translation(uint32_T c44_machineNumber, uint32_T
  c44_chartNumber, uint32_T c44_instanceNumber)
{
  (void)c44_machineNumber;
  (void)c44_chartNumber;
  (void)c44_instanceNumber;
}

static const mxArray *c44_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  real_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(real_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static real_T c44_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  real_T c44_y;
  real_T c44_d0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_d0, 1, 0, 0U, 0, 0U, 0);
  c44_y = c44_d0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_nargout;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_nargout = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_nargout),
    &c44_thisId);
  sf_mex_destroy(&c44_nargout);
  *(real_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_b_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  boolean_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(boolean_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static boolean_T c44_b_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  boolean_T c44_y;
  boolean_T c44_b0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_b0, 1, 11, 0U, 0, 0U, 0);
  c44_y = c44_b0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_sf_internal_predicateOutput;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  boolean_T c44_y;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_sf_internal_predicateOutput = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c44_sf_internal_predicateOutput), &c44_thisId);
  sf_mex_destroy(&c44_sf_internal_predicateOutput);
  *(boolean_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

const mxArray *sf_c44_Expriment_Pose_get_eml_resolved_functions_info(void)
{
  const mxArray *c44_nameCaptureInfo = NULL;
  c44_nameCaptureInfo = NULL;
  sf_mex_assign(&c44_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c44_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  return chartInstance->c44_isStable;
}

void sf_exported_auto_duringc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  c44_c44_Expriment_Pose(chartInstance);
}

void sf_exported_auto_enterc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
  c44_enter_atomic_c44_Expriment_Pose(chartInstance);
  c44_enter_internal_c44_Expriment_Pose(chartInstance);
}

void sf_exported_auto_exitc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c44_exit_internal_c44_Expriment_Pose(chartInstance);
  sf_exported_auto_disablec50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_gatewayc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_enablec44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_disablec44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_disablec50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_stepBuffersc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_initBuffersc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
  sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_activate_callc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  chartInstance->c44_sfEvent = CALL_EVENT;
  sf_exported_auto_activate_callc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_increment_call_counterc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_reset_call_counterc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_deactivate_callc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior
    (chartInstance->c44_subchartSimstruct);
}

void sf_exported_auto_initc44_Expriment_Pose(SimStruct *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  c44_initc44_Expriment_Pose(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec44_Expriment_Pose(SimStruct *c44_S)
{
  const mxArray *c44_out = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  c44_out = NULL;
  sf_mex_assign(&c44_out, sf_internal_get_sim_state_c44_Expriment_Pose(c44_S),
                false);
  return c44_out;
}

void sf_exported_auto_setSimstatec44_Expriment_Pose(SimStruct *c44_S, const
  mxArray *c44_in)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c44_Expriment_Pose(c44_S, sf_mex_dup(c44_in));
  sf_mex_destroy(&c44_in);
}

void sf_exported_auto_check_state_inconsistency_c44_Expriment_Pose(SimStruct
  *c44_S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c44_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_PoseMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c44_c_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(int32_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static int32_T c44_c_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  int32_T c44_y;
  int32_T c44_i4;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_i4, 1, 6, 0U, 0, 0U, 0);
  c44_y = c44_i4;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_b_sfEvent;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  int32_T c44_y;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_b_sfEvent = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_b_sfEvent),
    &c44_thisId);
  sf_mex_destroy(&c44_b_sfEvent);
  *(int32_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_d_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  uint8_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(uint8_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static uint8_T c44_d_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_b_tp_setP, const char_T *c44_identifier)
{
  uint8_T c44_y;
  emlrtMsgIdentifier c44_thisId;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_b_tp_setP),
    &c44_thisId);
  sf_mex_destroy(&c44_b_tp_setP);
  return c44_y;
}

static uint8_T c44_e_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  uint8_T c44_y;
  uint8_T c44_u0;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_u0, 1, 3, 0U, 0, 0U, 0);
  c44_y = c44_u0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_b_tp_setP;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  uint8_T c44_y;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_b_tp_setP = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_b_tp_setP),
    &c44_thisId);
  sf_mex_destroy(&c44_b_tp_setP);
  *(uint8_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_e_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i5;
  real_T c44_b_inData[6];
  int32_T c44_i6;
  real_T c44_u[6];
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i5 = 0; c44_i5 < 6; c44_i5++) {
    c44_b_inData[c44_i5] = (*(real_T (*)[6])c44_inData)[c44_i5];
  }

  for (c44_i6 = 0; c44_i6 < 6; c44_i6++) {
    c44_u[c44_i6] = c44_b_inData[c44_i6];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static const mxArray *c44_f_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i7;
  real_T c44_b_inData[11];
  int32_T c44_i8;
  real_T c44_u[11];
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i7 = 0; c44_i7 < 11; c44_i7++) {
    c44_b_inData[c44_i7] = (*(real_T (*)[11])c44_inData)[c44_i7];
  }

  for (c44_i8 = 0; c44_i8 < 11; c44_i8++) {
    c44_u[c44_i8] = c44_b_inData[c44_i8];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static void c44_f_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[11])
{
  real_T c44_dv0[11];
  int32_T c44_i9;
  (void)chartInstance;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                11);
  for (c44_i9 = 0; c44_i9 < 11; c44_i9++) {
    c44_y[c44_i9] = c44_dv0[c44_i9];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_emotion_amount_factor;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[11];
  int32_T c44_i10;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_emotion_amount_factor = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_emotion_amount_factor),
    &c44_thisId, c44_y);
  sf_mex_destroy(&c44_emotion_amount_factor);
  for (c44_i10 = 0; c44_i10 < 11; c44_i10++) {
    (*(real_T (*)[11])c44_outData)[c44_i10] = c44_y[c44_i10];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_g_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  const mxArray *c44_u;
  const mxArray *c44_y = NULL;
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = sf_mex_dup(*(const mxArray **)c44_inData);
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_duplicatearraysafe(&c44_u), false);
  sf_mex_destroy(&c44_u);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, false);
  return c44_mxArrayOutData;
}

static const mxArray *c44_g_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c44_b_subchartSimStateInfo, const char_T
  *c44_identifier)
{
  const mxArray *c44_y = NULL;
  emlrtMsgIdentifier c44_thisId;
  c44_y = NULL;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  sf_mex_assign(&c44_y, c44_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c44_b_subchartSimStateInfo), &c44_thisId), false);
  sf_mex_destroy(&c44_b_subchartSimStateInfo);
  return c44_y;
}

static const mxArray *c44_h_emlrt_marshallIn(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  const mxArray *c44_y = NULL;
  (void)chartInstance;
  (void)c44_parentId;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_duplicatearraysafe(&c44_u), false);
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static real_T c44_get_avert_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c44_b);
  if (chartInstance->c44_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#1089) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_avert_freq_factor_address;
}

static void c44_set_avert_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c44_b);
  if (chartInstance->c44_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#1089) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_avert_freq_factor_address = c44_c;
}

static real_T *c44_access_avert_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c44_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#1089) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_avert_freq_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c44_c;
}

static real_T c44_get_avert_gaze_dirs_chance(SFc44_Expriment_PoseInstanceStruct *
  chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c44_b);
  if (chartInstance->c44_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#1078) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_avert_gaze_dirs_chance_address;
}

static void c44_set_avert_gaze_dirs_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c44_b);
  if (chartInstance->c44_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#1078) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_avert_gaze_dirs_chance_address = c44_c;
}

static real_T *c44_access_avert_gaze_dirs_chance
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c44_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#1078) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_avert_gaze_dirs_chance_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c44_c;
}

static real_T c44_get_avert_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c44_b);
  if (chartInstance->c44_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#1076) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_avert_gaze_duration_factor_address;
}

static void c44_set_avert_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b, real_T
   c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c44_b);
  if (chartInstance->c44_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#1076) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_avert_gaze_duration_factor_address = c44_c;
}

static real_T *c44_access_avert_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c44_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#1076) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_avert_gaze_duration_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c44_c;
}

static real_T c44_get_avert_head_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c44_b);
  if (chartInstance->c44_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#1075) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_avert_head_frequency_factor_address;
}

static void c44_set_avert_head_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b, real_T
   c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c44_b);
  if (chartInstance->c44_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#1075) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_avert_head_frequency_factor_address = c44_c;
}

static real_T *c44_access_avert_head_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c44_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#1075) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_avert_head_frequency_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c44_c;
}

static real_T c44_get_avert_head_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c44_b);
  if (chartInstance->c44_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#1077) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_avert_head_speed_address;
}

static void c44_set_avert_head_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c44_b);
  if (chartInstance->c44_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#1077) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_avert_head_speed_address = c44_c;
}

static real_T *c44_access_avert_head_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c44_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#1077) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_avert_head_speed_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c44_c;
}

static real_T c44_get_emotion_amount_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c44_b);
  if (chartInstance->c44_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#1087) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c44_emotion_amount_factor_address)[c44_b];
}

static void c44_set_emotion_amount_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c44_b);
  if (chartInstance->c44_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#1087) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c44_emotion_amount_factor_address)[c44_b] = c44_c;
}

static real_T *c44_access_emotion_amount_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c44_emotion_amount_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'emotion_amount_factor\' (#1087) in the initialization routine of the chart.\n");
  }

  c44_c = *chartInstance->c44_emotion_amount_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c44_c;
}

static real_T c44_get_mut_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c44_b);
  if (chartInstance->c44_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#1088) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_mut_freq_factor_address;
}

static void c44_set_mut_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c44_b);
  if (chartInstance->c44_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#1088) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_mut_freq_factor_address = c44_c;
}

static real_T *c44_access_mut_freq_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c44_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#1088) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_mut_freq_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c44_c;
}

static real_T c44_get_mutual_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c44_b);
  if (chartInstance->c44_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#1074) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_mutual_gaze_duration_factor_address;
}

static void c44_set_mutual_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b, real_T
   c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c44_b);
  if (chartInstance->c44_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#1074) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_mutual_gaze_duration_factor_address = c44_c;
}

static real_T *c44_access_mutual_gaze_duration_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c44_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#1074) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_mutual_gaze_duration_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_cat_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c44_b);
  if (chartInstance->c44_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#1084) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_cat_chance_address;
}

static void c44_set_pose_cat_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c44_b);
  if (chartInstance->c44_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#1084) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_cat_chance_address = c44_c;
}

static real_T *c44_access_pose_cat_chance(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c44_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#1084) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_cat_chance_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_chanc_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c44_b);
  if (chartInstance->c44_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#1082) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_chanc_factor_address;
}

static void c44_set_pose_chanc_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c44_b);
  if (chartInstance->c44_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#1082) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_chanc_factor_address = c44_c;
}

static real_T *c44_access_pose_chanc_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c44_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#1082) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_chanc_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_frequency_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c44_b);
  if (chartInstance->c44_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#1083) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_frequency_factor_address;
}

static void c44_set_pose_frequency_factor(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c44_b);
  if (chartInstance->c44_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#1083) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_frequency_factor_address = c44_c;
}

static real_T *c44_access_pose_frequency_factor
  (SFc44_Expriment_PoseInstanceStruct *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c44_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#1083) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_frequency_factor_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_lean(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c44_b);
  if (chartInstance->c44_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#1080) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_lean_address;
}

static void c44_set_pose_lean(SFc44_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c44_b);
  if (chartInstance->c44_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#1080) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_lean_address = c44_c;
}

static real_T *c44_access_pose_lean(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c44_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#1080) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_lean_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_lean_flag(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c44_b);
  if (chartInstance->c44_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#1085) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_lean_flag_address;
}

static void c44_set_pose_lean_flag(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c44_b);
  if (chartInstance->c44_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#1085) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_lean_flag_address = c44_c;
}

static real_T *c44_access_pose_lean_flag(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c44_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#1085) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_lean_flag_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c44_b);
  if (chartInstance->c44_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#1081) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_speed_address;
}

static void c44_set_pose_speed(SFc44_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c44_b);
  if (chartInstance->c44_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#1081) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_speed_address = c44_c;
}

static real_T *c44_access_pose_speed(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c44_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#1081) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_speed_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c44_c;
}

static real_T c44_get_pose_twitch(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c44_b);
  if (chartInstance->c44_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#1090) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c44_pose_twitch_address;
}

static void c44_set_pose_twitch(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b, real_T c44_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c44_b);
  if (chartInstance->c44_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#1090) in the initialization routine of the chart.\n");
  }

  *chartInstance->c44_pose_twitch_address = c44_c;
}

static real_T *c44_access_pose_twitch(SFc44_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c44_b)
{
  real_T *c44_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c44_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#1090) in the initialization routine of the chart.\n");
  }

  c44_c = chartInstance->c44_pose_twitch_address;
  if (c44_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c44_c;
}

static void init_dsm_address_info(SFc44_Expriment_PoseInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_freq_factor", (void **)
    &chartInstance->c44_avert_freq_factor_address,
    &chartInstance->c44_avert_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_dirs_chance",
    (void **)&chartInstance->c44_avert_gaze_dirs_chance_address,
    &chartInstance->c44_avert_gaze_dirs_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_duration_factor",
                                (void **)
    &chartInstance->c44_avert_gaze_duration_factor_address,
    &chartInstance->c44_avert_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_frequency_factor",
                                (void **)
    &chartInstance->c44_avert_head_frequency_factor_address,
    &chartInstance->c44_avert_head_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_speed", (void **)
    &chartInstance->c44_avert_head_speed_address,
    &chartInstance->c44_avert_head_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "emotion_amount_factor", (void
    **)&chartInstance->c44_emotion_amount_factor_address,
    &chartInstance->c44_emotion_amount_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mut_freq_factor", (void **)
    &chartInstance->c44_mut_freq_factor_address,
    &chartInstance->c44_mut_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mutual_gaze_duration_factor",
                                (void **)
    &chartInstance->c44_mutual_gaze_duration_factor_address,
    &chartInstance->c44_mutual_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_cat_chance", (void **)
    &chartInstance->c44_pose_cat_chance_address,
    &chartInstance->c44_pose_cat_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chanc_factor", (void **)
    &chartInstance->c44_pose_chanc_factor_address,
    &chartInstance->c44_pose_chanc_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c44_pose_frequency_factor_address,
    &chartInstance->c44_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c44_pose_lean_address, &chartInstance->c44_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c44_pose_lean_flag_address,
    &chartInstance->c44_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c44_pose_speed_address, &chartInstance->c44_pose_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_twitch", (void **)
    &chartInstance->c44_pose_twitch_address,
    &chartInstance->c44_pose_twitch_index);
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

void sf_c44_Expriment_Pose_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(607996873U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2268418597U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3462030670U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1748286698U);
}

mxArray *sf_c44_Expriment_Pose_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("it3IJwiChHzZthFdSexajD");
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

mxArray *sf_c44_Expriment_Pose_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c44_Expriment_Pose_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c44_Expriment_Pose(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c44_Expriment_Pose\",},{M[9],M[0],T\"is_c44_Expriment_Pose\",},{M[14],M[123],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c44_Expriment_Pose_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc44_Expriment_PoseInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc44_Expriment_PoseInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_PoseMachineNumber_,
           44,
           5,
           6,
           0,
           24,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_PoseMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_PoseMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_PoseMachineNumber_,
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
          _SFD_SET_DATA_PROPS(13,11,0,0,"pose_lean");
          _SFD_SET_DATA_PROPS(14,11,0,0,"pose_speed");
          _SFD_SET_DATA_PROPS(15,11,0,0,"pose_chanc_factor");
          _SFD_SET_DATA_PROPS(16,11,0,0,"pose_frequency_factor");
          _SFD_SET_DATA_PROPS(17,11,0,0,"pose_cat_chance");
          _SFD_SET_DATA_PROPS(18,11,0,0,"pose_lean_flag");
          _SFD_SET_DATA_PROPS(19,1,1,0,"emotion_amount_custom");
          _SFD_SET_DATA_PROPS(20,11,0,0,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(21,11,0,0,"mut_freq_factor");
          _SFD_SET_DATA_PROPS(22,11,0,0,"avert_freq_factor");
          _SFD_SET_DATA_PROPS(23,11,0,0,"pose_twitch");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

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
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,18,1,18);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_f_sf_marshallOut,(MexInFcnForType)
            c44_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);

        {
          real_T *c44_inA;
          real_T *c44_inV;
          boolean_T *c44_vaFlag;
          boolean_T *c44_personalityFlag;
          real_T *c44_personality;
          boolean_T *c44_personalityChange;
          real_T *c44_emotion_amount_custom;
          real_T (*c44_gazeArray)[6];
          real_T (*c44_poseArray)[6];
          c44_emotion_amount_custom = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 8);
          c44_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            7);
          c44_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 6);
          c44_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c44_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            4);
          c44_personalityFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 3);
          c44_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c44_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c44_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c44_inA);
          _SFD_SET_DATA_VALUE_PTR(1U, c44_inV);
          _SFD_SET_DATA_VALUE_PTR(2U, c44_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(3U, c44_personalityFlag);
          _SFD_SET_DATA_VALUE_PTR(4U, *c44_gazeArray);
          _SFD_SET_DATA_VALUE_PTR(5U, c44_personality);
          _SFD_SET_DATA_VALUE_PTR(6U, c44_personalityChange);
          _SFD_SET_DATA_VALUE_PTR(7U,
            chartInstance->c44_mutual_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c44_avert_head_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(9U,
            chartInstance->c44_avert_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c44_avert_head_speed_address);
          _SFD_SET_DATA_VALUE_PTR(11U,
            chartInstance->c44_avert_gaze_dirs_chance_address);
          _SFD_SET_DATA_VALUE_PTR(12U, *c44_poseArray);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c44_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c44_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(15U,
            chartInstance->c44_pose_chanc_factor_address);
          _SFD_SET_DATA_VALUE_PTR(16U,
            chartInstance->c44_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(17U,
            chartInstance->c44_pose_cat_chance_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c44_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(19U, c44_emotion_amount_custom);
          _SFD_SET_DATA_VALUE_PTR(20U,
            *chartInstance->c44_emotion_amount_factor_address);
          _SFD_SET_DATA_VALUE_PTR(21U,
            chartInstance->c44_mut_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(22U,
            chartInstance->c44_avert_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c44_pose_twitch_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_PoseMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "FtbliyM4V3UAb35sLOw0Z";
}

static void sf_opaque_initialize_c44_Expriment_Pose(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
  initialize_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c44_Expriment_Pose(void *chartInstanceVar)
{
  enable_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c44_Expriment_Pose(void *chartInstanceVar)
{
  disable_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c44_Expriment_Pose(void *chartInstanceVar)
{
  sf_gateway_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c44_Expriment_Pose(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c44_Expriment_Pose
    ((SFc44_Expriment_PoseInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c44_Expriment_Pose();/* state var info */
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

extern void sf_internal_set_sim_state_c44_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c44_Expriment_Pose();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c44_Expriment_Pose(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c44_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c44_Expriment_Pose(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc44_Expriment_PoseInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Pose_optimization_info();
    }

    finalize_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
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
  initSimStructsc44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c44_Expriment_Pose(SimStruct *S)
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
    initialize_params_c44_Expriment_Pose((SFc44_Expriment_PoseInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c44_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Pose_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      44);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,44,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,44,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,44);
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
        infoStruct,44,9);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,44);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3522855627U));
  ssSetChecksum1(S,(3996630515U));
  ssSetChecksum2(S,(1514407369U));
  ssSetChecksum3(S,(2253194740U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c44_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c44_Expriment_Pose(SimStruct *S)
{
  SFc44_Expriment_PoseInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc44_Expriment_PoseInstanceStruct *)utMalloc(sizeof
    (SFc44_Expriment_PoseInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc44_Expriment_PoseInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c44_Expriment_Pose;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c44_Expriment_Pose;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c44_Expriment_Pose;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c44_Expriment_Pose;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c44_Expriment_Pose;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c44_Expriment_Pose;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c44_Expriment_Pose;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c44_Expriment_Pose;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c44_Expriment_Pose;
  chartInstance->chartInfo.mdlStart = mdlStart_c44_Expriment_Pose;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c44_Expriment_Pose;
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

void c44_Expriment_Pose_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c44_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c44_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c44_Expriment_Pose(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c44_Expriment_Pose_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
