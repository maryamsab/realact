/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Pose_sfun.h"
#include "c11_Expriment_Pose.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Pose_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_init                    ((uint8_T)1U)
#define c11_IN_setBehavior             ((uint8_T)2U)
#define c11_IN_wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c11_subchartSimStateInfo;
static const char * c11_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void initialize_params_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static void enable_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void disable_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static void set_sim_state_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static void finalize_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void sf_gateway_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void c11_enter_atomic_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static void c11_enter_internal_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static void c11_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void c11_exit_internal_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance);
static void c11_initc11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);
static void initSimStructsc11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_b_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_c_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_d_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_init, const char_T *c11_identifier);
static uint8_T c11_e_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c11_b_subchartSimStateInfo, const char_T
  *c11_identifier);
static const mxArray *c11_g_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static real_T c11_get_avert_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_avert_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_avert_gaze_dirs_chance(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, uint32_T c11_b);
static void c11_set_avert_gaze_dirs_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert_gaze_dirs_chance
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_avert_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static void c11_set_avert_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b, real_T
   c11_c);
static real_T *c11_access_avert_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_avert_head_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static void c11_set_avert_head_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b, real_T
   c11_c);
static real_T *c11_access_avert_head_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_avert_head_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_avert_head_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert_head_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_blink_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_blink_flag(SFc11_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_blink_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_blinkperiod_max(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_blinkperiod_max(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_blinkperiod_max(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_blinkperiod_min(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_blinkperiod_min(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_blinkperiod_min(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_mut_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_mut_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_mut_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_mutual_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static void c11_set_mutual_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b, real_T
   c11_c);
static real_T *c11_access_mutual_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_cat_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_cat_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_cat_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_chanc_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_chanc_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_chanc_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_frequency_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_frequency_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_lean(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_lean(SFc11_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_lean(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_lean_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_lean_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_lean_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_speed(SFc11_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_pose_twitch(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose_twitch(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose_twitch(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_Expriment_PoseInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_Expriment_Pose == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Expriment_Pose == c11_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Expriment_Pose == c11_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Expriment_Pose == c11_IN_setBehavior) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  const mxArray *c11_c_u;
  const mxArray *c11_d_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  sf_mex_assign(&c11_subchartSimStateInfo,
                sf_exported_auto_getSimstatec50_lib_affectiveChar_behavior
                (chartInstance->c11_subchartSimstruct), true);
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(3, 1), false);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_Expriment_Pose;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_is_c11_Expriment_Pose;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_c_u = sf_mex_dup(c11_subchartSimStateInfo);
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_duplicatearraysafe(&c11_c_u), false);
  sf_mex_destroy(&c11_c_u);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  c11_u = sf_mex_dup(c11_st);
  chartInstance->c11_is_active_c11_Expriment_Pose = c11_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
     "is_active_c11_Expriment_Pose");
  chartInstance->c11_is_c11_Expriment_Pose = c11_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_c11_Expriment_Pose");
  sf_mex_assign(&c11_subchartSimStateInfo, c11_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 2)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_Expriment_Pose(chartInstance);
  sf_exported_auto_setSimstatec50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct, sf_mex_dup(c11_subchartSimStateInfo));
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_Expriment_Pose == c11_IN_init) {
      chartInstance->c11_tp_init = 1U;
    } else {
      chartInstance->c11_tp_init = 0U;
    }

    if (chartInstance->c11_is_c11_Expriment_Pose == c11_IN_setBehavior) {
      chartInstance->c11_tp_setBehavior = 1U;
    } else {
      chartInstance->c11_tp_setBehavior = 0U;
    }

    if (chartInstance->c11_is_c11_Expriment_Pose == c11_IN_wait) {
      chartInstance->c11_tp_wait = 1U;
    } else {
      chartInstance->c11_tp_wait = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c11_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  c11_set_sim_state_side_effects_c11_Expriment_Pose(chartInstance);
}

static void c11_enter_atomic_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_Expriment_Pose = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_c11_Expriment_Pose = c11_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  c11_set_mutual_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c11_set_avert_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c11_set_avert_head_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c11_set_avert_head_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c11_set_avert_gaze_dirs_chance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c11_set_avert_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  c11_set_mut_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c11_set_pose_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c11_set_pose_chanc_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c11_set_pose_cat_chance(chartInstance, 0, 70.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c11_set_pose_lean(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c11_set_pose_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c11_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c11_set_blink_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c11_set_blinkperiod_min(chartInstance, 0, 5.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c11_set_blinkperiod_max(chartInstance, 0, 9.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 1.0;
  boolean_T c11_b_out;
  uint32_T c11_b_debug_family_var_map[2];
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 0.0;
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  boolean_T c11_d_hoistedGlobal;
  boolean_T c11_e_hoistedGlobal;
  boolean_T c11_f_hoistedGlobal;
  real_T c11_v;
  real_T c11_ar;
  real_T c11_p;
  boolean_T c11_pFlag;
  boolean_T c11_vaFlag;
  int32_T c11_i0;
  real_T c11_poseArr[6];
  real_T c11_personalityChange;
  int32_T c11_i1;
  real_T c11_b_poseArr[6];
  real_T c11_poseLeanFlag;
  real_T c11_poseSpeed;
  real_T c11_poseLean;
  real_T c11_poseCatChance;
  real_T c11_poseChanceFactor;
  real_T c11_poseFreqFactor;
  real_T c11_poseTwitch;
  real_T c11_pose_twitch;
  real_T c11_pose_frequency_factor;
  real_T c11_pose_chanc_factor;
  real_T c11_pose_cat_chance;
  real_T c11_pose_lean;
  real_T c11_pose_speed;
  real_T c11_pose_lean_flag;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 0.0;
  real_T c11_g_hoistedGlobal;
  real_T c11_h_hoistedGlobal;
  real_T c11_i_hoistedGlobal;
  boolean_T c11_j_hoistedGlobal;
  boolean_T c11_k_hoistedGlobal;
  boolean_T c11_l_hoistedGlobal;
  real_T c11_b_v;
  real_T c11_b_ar;
  real_T c11_b_p;
  boolean_T c11_b_pFlag;
  boolean_T c11_b_vaFlag;
  int32_T c11_i2;
  real_T c11_b_personalityChange;
  int32_T c11_i3;
  real_T c11_c_poseArr[6];
  real_T c11_b_poseLeanFlag;
  real_T c11_b_poseSpeed;
  real_T c11_b_poseLean;
  real_T c11_b_poseCatChance;
  real_T c11_b_poseChanceFactor;
  real_T c11_b_poseFreqFactor;
  real_T c11_b_poseTwitch;
  real_T c11_b_pose_twitch;
  real_T c11_b_pose_frequency_factor;
  real_T c11_b_pose_chanc_factor;
  real_T c11_b_pose_cat_chance;
  real_T c11_b_pose_lean;
  real_T c11_b_pose_speed;
  real_T c11_b_pose_lean_flag;
  boolean_T *c11_aChange;
  boolean_T *c11_vChange;
  real_T *c11_inV;
  real_T *c11_inA;
  real_T *c11_personality;
  boolean_T *c11_personalityFlag;
  boolean_T *c11_c_vaFlag;
  boolean_T *c11_c_personalityChange;
  real_T (*c11_poseArray)[6];
  c11_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c11_c_personalityChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
    8);
  c11_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 7);
  c11_c_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c11_personalityFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c11_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c11_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  switch (chartInstance->c11_is_c11_Expriment_Pose) {
   case c11_IN_init:
    CV_CHART_EVAL(7, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_c_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    c11_out = CV_EML_IF(3, 0, 0, c11_get_pose_speed(chartInstance, 0) == 100.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Expriment_Pose = c11_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_setBehavior:
    CV_CHART_EVAL(7, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_setBehavior = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_Expriment_Pose = c11_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_CHART_EVAL(7, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_e_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    c11_b_out = CV_EML_IF(1, 0, 0, (real_T)*c11_aChange == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Expriment_Pose = c11_IN_setBehavior;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_setBehavior = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_b_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      c11_hoistedGlobal = *c11_inV;
      c11_b_hoistedGlobal = *c11_inA;
      c11_c_hoistedGlobal = *c11_personality;
      c11_d_hoistedGlobal = *c11_personalityFlag;
      c11_e_hoistedGlobal = *c11_c_vaFlag;
      c11_f_hoistedGlobal = *c11_c_personalityChange;
      c11_v = c11_hoistedGlobal;
      c11_ar = c11_b_hoistedGlobal;
      c11_p = c11_c_hoistedGlobal;
      c11_pFlag = c11_d_hoistedGlobal;
      c11_vaFlag = c11_e_hoistedGlobal;
      for (c11_i0 = 0; c11_i0 < 6; c11_i0++) {
        c11_poseArr[c11_i0] = (*c11_poseArray)[c11_i0];
      }

      c11_personalityChange = (real_T)c11_f_hoistedGlobal;
      for (c11_i1 = 0; c11_i1 < 6; c11_i1++) {
        c11_b_poseArr[c11_i1] = c11_poseArr[c11_i1];
      }

      sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
        (chartInstance->c11_subchartSimstruct, c11_v, c11_ar, c11_p, c11_pFlag,
         c11_vaFlag, c11_b_poseArr, c11_personalityChange, &c11_poseTwitch,
         &c11_poseFreqFactor, &c11_poseChanceFactor, &c11_poseCatChance,
         &c11_poseLean, &c11_poseSpeed, &c11_poseLeanFlag);
      c11_pose_twitch = c11_poseTwitch;
      c11_pose_frequency_factor = c11_poseFreqFactor;
      c11_pose_chanc_factor = c11_poseChanceFactor;
      c11_pose_cat_chance = c11_poseCatChance;
      c11_pose_lean = c11_poseLean;
      c11_pose_speed = c11_poseSpeed;
      c11_pose_lean_flag = c11_poseLeanFlag;
      c11_set_pose_twitch(chartInstance, 0, c11_pose_twitch);
      ssUpdateDataStoreLog(chartInstance->S, 16);
      c11_set_pose_frequency_factor(chartInstance, 0, c11_pose_frequency_factor);
      ssUpdateDataStoreLog(chartInstance->S, 12);
      c11_set_pose_chanc_factor(chartInstance, 0, c11_pose_chanc_factor);
      ssUpdateDataStoreLog(chartInstance->S, 11);
      c11_set_pose_cat_chance(chartInstance, 0, c11_pose_cat_chance);
      ssUpdateDataStoreLog(chartInstance->S, 10);
      c11_set_pose_lean(chartInstance, 0, c11_pose_lean);
      ssUpdateDataStoreLog(chartInstance->S, 13);
      c11_set_pose_speed(chartInstance, 0, c11_pose_speed);
      ssUpdateDataStoreLog(chartInstance->S, 15);
      c11_set_pose_lean_flag(chartInstance, 0, c11_pose_lean_flag);
      ssUpdateDataStoreLog(chartInstance->S, 14);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_d_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_b_sf_marshallOut,
        c11_b_sf_marshallIn);
      c11_c_out = CV_EML_IF(4, 0, 0, (real_T)*c11_vChange == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_c11_Expriment_Pose = c11_IN_setBehavior;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_setBehavior = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_b_debug_family_names,
          c11_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U,
          c11_sf_marshallOut, c11_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
          c11_sf_marshallOut, c11_sf_marshallIn);
        c11_g_hoistedGlobal = *c11_inV;
        c11_h_hoistedGlobal = *c11_inA;
        c11_i_hoistedGlobal = *c11_personality;
        c11_j_hoistedGlobal = *c11_personalityFlag;
        c11_k_hoistedGlobal = *c11_c_vaFlag;
        c11_l_hoistedGlobal = *c11_c_personalityChange;
        c11_b_v = c11_g_hoistedGlobal;
        c11_b_ar = c11_h_hoistedGlobal;
        c11_b_p = c11_i_hoistedGlobal;
        c11_b_pFlag = c11_j_hoistedGlobal;
        c11_b_vaFlag = c11_k_hoistedGlobal;
        for (c11_i2 = 0; c11_i2 < 6; c11_i2++) {
          c11_poseArr[c11_i2] = (*c11_poseArray)[c11_i2];
        }

        c11_b_personalityChange = (real_T)c11_l_hoistedGlobal;
        for (c11_i3 = 0; c11_i3 < 6; c11_i3++) {
          c11_c_poseArr[c11_i3] = c11_poseArr[c11_i3];
        }

        sf_exported_user_c50_lib_affectiveChar_behavior_setPoseFactors
          (chartInstance->c11_subchartSimstruct, c11_b_v, c11_b_ar, c11_b_p,
           c11_b_pFlag, c11_b_vaFlag, c11_c_poseArr, c11_b_personalityChange,
           &c11_b_poseTwitch, &c11_b_poseFreqFactor, &c11_b_poseChanceFactor,
           &c11_b_poseCatChance, &c11_b_poseLean, &c11_b_poseSpeed,
           &c11_b_poseLeanFlag);
        c11_b_pose_twitch = c11_b_poseTwitch;
        c11_b_pose_frequency_factor = c11_b_poseFreqFactor;
        c11_b_pose_chanc_factor = c11_b_poseChanceFactor;
        c11_b_pose_cat_chance = c11_b_poseCatChance;
        c11_b_pose_lean = c11_b_poseLean;
        c11_b_pose_speed = c11_b_poseSpeed;
        c11_b_pose_lean_flag = c11_b_poseLeanFlag;
        c11_set_pose_twitch(chartInstance, 0, c11_b_pose_twitch);
        ssUpdateDataStoreLog(chartInstance->S, 16);
        c11_set_pose_frequency_factor(chartInstance, 0,
          c11_b_pose_frequency_factor);
        ssUpdateDataStoreLog(chartInstance->S, 12);
        c11_set_pose_chanc_factor(chartInstance, 0, c11_b_pose_chanc_factor);
        ssUpdateDataStoreLog(chartInstance->S, 11);
        c11_set_pose_cat_chance(chartInstance, 0, c11_b_pose_cat_chance);
        ssUpdateDataStoreLog(chartInstance->S, 10);
        c11_set_pose_lean(chartInstance, 0, c11_b_pose_lean);
        ssUpdateDataStoreLog(chartInstance->S, 13);
        c11_set_pose_speed(chartInstance, 0, c11_b_pose_speed);
        ssUpdateDataStoreLog(chartInstance->S, 15);
        c11_set_pose_lean_flag(chartInstance, 0, c11_b_pose_lean_flag);
        ssUpdateDataStoreLog(chartInstance->S, 14);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c11_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c11_is_c11_Expriment_Pose = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_Expriment_Pose
  (SFc11_Expriment_PoseInstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_c11_Expriment_Pose) {
   case c11_IN_init:
    CV_CHART_EVAL(7, 0, 1);
    chartInstance->c11_tp_init = 0U;
    chartInstance->c11_is_c11_Expriment_Pose = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_setBehavior:
    CV_CHART_EVAL(7, 0, 2);
    chartInstance->c11_tp_setBehavior = 0U;
    chartInstance->c11_is_c11_Expriment_Pose = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_CHART_EVAL(7, 0, 3);
    chartInstance->c11_tp_wait = 0U;
    chartInstance->c11_is_c11_Expriment_Pose = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c11_is_c11_Expriment_Pose = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }
}

static void c11_initc11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  sf_exported_auto_initc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_subchartSimStateInfo = NULL;
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_init = 0U;
  chartInstance->c11_tp_setBehavior = 0U;
  chartInstance->c11_tp_wait = 0U;
  chartInstance->c11_is_active_c11_Expriment_Pose = 0U;
  chartInstance->c11_is_c11_Expriment_Pose = c11_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc11_Expriment_Pose(SFc11_Expriment_PoseInstanceStruct *
  chartInstance)
{
  chartInstance->c11_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "sharedFunc");
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_b_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b0, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_sf_internal_predicateOutput;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_sf_internal_predicateOutput = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_sf_internal_predicateOutput), &c11_thisId);
  sf_mex_destroy(&c11_sf_internal_predicateOutput);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_Expriment_Pose_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c11_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_c11_Expriment_Pose(chartInstance);
}

void sf_exported_auto_enterc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
  c11_enter_atomic_c11_Expriment_Pose(chartInstance);
  c11_enter_internal_c11_Expriment_Pose(chartInstance);
}

void sf_exported_auto_exitc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_Expriment_Pose(chartInstance);
  sf_exported_auto_disablec50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_gatewayc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_enablec11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_disablec11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_disablec50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_stepBuffersc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_exported_auto_stepBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_initBuffersc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
  sf_exported_auto_initBuffersc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_activate_callc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
  sf_exported_auto_activate_callc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_increment_call_counterc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_exported_auto_increment_call_counterc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_reset_call_counterc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_exported_auto_reset_call_counterc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_deactivate_callc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_exported_auto_deactivate_callc50_lib_affectiveChar_behavior
    (chartInstance->c11_subchartSimstruct);
}

void sf_exported_auto_initc11_Expriment_Pose(SimStruct *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_initc11_Expriment_Pose(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_Expriment_Pose(SimStruct *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out, sf_internal_get_sim_state_c11_Expriment_Pose(c11_S),
                false);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_Expriment_Pose(SimStruct *c11_S, const
  mxArray *c11_in)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c11_Expriment_Pose(c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_Expriment_Pose(SimStruct
  *c11_S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_PoseMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_c_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i4;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i4, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i4;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_d_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_init, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_init),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_init);
  return c11_y;
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_init;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_b_tp_init = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_init),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_init);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i5;
  real_T c11_b_inData[6];
  int32_T c11_i6;
  real_T c11_u[6];
  const mxArray *c11_y = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i5 = 0; c11_i5 < 6; c11_i5++) {
    c11_b_inData[c11_i5] = (*(real_T (*)[6])c11_inData)[c11_i5];
  }

  for (c11_i6 = 0; c11_i6 < 6; c11_i6++) {
    c11_u[c11_i6] = c11_b_inData[c11_i6];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  const mxArray *c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = sf_mex_dup(*(const mxArray **)c11_inData);
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c11_b_subchartSimStateInfo, const char_T
  *c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_subchartSimStateInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_subchartSimStateInfo);
  return c11_y;
}

static const mxArray *c11_g_emlrt_marshallIn(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static real_T c11_get_avert_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#697) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_freq_factor_address;
}

static void c11_set_avert_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#697) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_freq_factor_address = c11_c;
}

static real_T *c11_access_avert_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#697) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_freq_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert_gaze_dirs_chance(SFc11_Expriment_PoseInstanceStruct *
  chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#688) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_gaze_dirs_chance_address;
}

static void c11_set_avert_gaze_dirs_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#688) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_gaze_dirs_chance_address = c11_c;
}

static real_T *c11_access_avert_gaze_dirs_chance
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#688) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_gaze_dirs_chance_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#685) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_gaze_duration_factor_address;
}

static void c11_set_avert_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b, real_T
   c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#685) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_gaze_duration_factor_address = c11_c;
}

static real_T *c11_access_avert_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#685) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_gaze_duration_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert_head_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#684) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_head_frequency_factor_address;
}

static void c11_set_avert_head_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b, real_T
   c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#684) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_head_frequency_factor_address = c11_c;
}

static real_T *c11_access_avert_head_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#684) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_head_frequency_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert_head_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#687) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_head_speed_address;
}

static void c11_set_avert_head_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#687) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_head_speed_address = c11_c;
}

static real_T *c11_access_avert_head_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c11_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#687) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_head_speed_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c11_c;
}

static real_T c11_get_blink_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#703) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_blink_flag_address;
}

static void c11_set_blink_flag(SFc11_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#703) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_blink_flag_address = c11_c;
}

static real_T *c11_access_blink_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c11_blink_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blink_flag\' (#703) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_blink_flag_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c11_c;
}

static real_T c11_get_blinkperiod_max(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#702) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_blinkperiod_max_address;
}

static void c11_set_blinkperiod_max(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#702) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_blinkperiod_max_address = c11_c;
}

static real_T *c11_access_blinkperiod_max(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c11_blinkperiod_max_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_max\' (#702) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_blinkperiod_max_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c11_c;
}

static real_T c11_get_blinkperiod_min(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#701) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_blinkperiod_min_address;
}

static void c11_set_blinkperiod_min(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#701) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_blinkperiod_min_address = c11_c;
}

static real_T *c11_access_blinkperiod_min(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c11_blinkperiod_min_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'blinkperiod_min\' (#701) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_blinkperiod_min_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c11_c;
}

static real_T c11_get_mut_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#698) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_mut_freq_factor_address;
}

static void c11_set_mut_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#698) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_mut_freq_factor_address = c11_c;
}

static real_T *c11_access_mut_freq_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c11_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#698) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_mut_freq_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c11_c;
}

static real_T c11_get_mutual_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#686) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_mutual_gaze_duration_factor_address;
}

static void c11_set_mutual_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b, real_T
   c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#686) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_mutual_gaze_duration_factor_address = c11_c;
}

static real_T *c11_access_mutual_gaze_duration_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c11_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#686) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_mutual_gaze_duration_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_cat_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c11_b);
  if (chartInstance->c11_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#693) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_cat_chance_address;
}

static void c11_set_pose_cat_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c11_b);
  if (chartInstance->c11_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#693) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_cat_chance_address = c11_c;
}

static real_T *c11_access_pose_cat_chance(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c11_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#693) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_cat_chance_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_chanc_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c11_b);
  if (chartInstance->c11_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#695) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_chanc_factor_address;
}

static void c11_set_pose_chanc_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c11_b);
  if (chartInstance->c11_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#695) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_chanc_factor_address = c11_c;
}

static real_T *c11_access_pose_chanc_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c11_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#695) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_chanc_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_frequency_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c11_b);
  if (chartInstance->c11_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#694) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_frequency_factor_address;
}

static void c11_set_pose_frequency_factor(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c11_b);
  if (chartInstance->c11_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#694) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_frequency_factor_address = c11_c;
}

static real_T *c11_access_pose_frequency_factor
  (SFc11_Expriment_PoseInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c11_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#694) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_frequency_factor_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_lean(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c11_b);
  if (chartInstance->c11_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#690) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_lean_address;
}

static void c11_set_pose_lean(SFc11_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c11_b);
  if (chartInstance->c11_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#690) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_lean_address = c11_c;
}

static real_T *c11_access_pose_lean(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c11_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#690) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_lean_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_lean_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c11_b);
  if (chartInstance->c11_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#692) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_lean_flag_address;
}

static void c11_set_pose_lean_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c11_b);
  if (chartInstance->c11_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#692) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_lean_flag_address = c11_c;
}

static real_T *c11_access_pose_lean_flag(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c11_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#692) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_lean_flag_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c11_b);
  if (chartInstance->c11_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#691) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_speed_address;
}

static void c11_set_pose_speed(SFc11_Expriment_PoseInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c11_b);
  if (chartInstance->c11_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#691) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_speed_address = c11_c;
}

static real_T *c11_access_pose_speed(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c11_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#691) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_speed_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose_twitch(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c11_b);
  if (chartInstance->c11_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#699) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_twitch_address;
}

static void c11_set_pose_twitch(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c11_b);
  if (chartInstance->c11_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#699) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_twitch_address = c11_c;
}

static real_T *c11_access_pose_twitch(SFc11_Expriment_PoseInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c11_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#699) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_twitch_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_Expriment_PoseInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_freq_factor", (void **)
    &chartInstance->c11_avert_freq_factor_address,
    &chartInstance->c11_avert_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_dirs_chance",
    (void **)&chartInstance->c11_avert_gaze_dirs_chance_address,
    &chartInstance->c11_avert_gaze_dirs_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_duration_factor",
                                (void **)
    &chartInstance->c11_avert_gaze_duration_factor_address,
    &chartInstance->c11_avert_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_frequency_factor",
                                (void **)
    &chartInstance->c11_avert_head_frequency_factor_address,
    &chartInstance->c11_avert_head_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_speed", (void **)
    &chartInstance->c11_avert_head_speed_address,
    &chartInstance->c11_avert_head_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blink_flag", (void **)
    &chartInstance->c11_blink_flag_address, &chartInstance->c11_blink_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blinkperiod_max", (void **)
    &chartInstance->c11_blinkperiod_max_address,
    &chartInstance->c11_blinkperiod_max_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "blinkperiod_min", (void **)
    &chartInstance->c11_blinkperiod_min_address,
    &chartInstance->c11_blinkperiod_min_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mut_freq_factor", (void **)
    &chartInstance->c11_mut_freq_factor_address,
    &chartInstance->c11_mut_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mutual_gaze_duration_factor",
                                (void **)
    &chartInstance->c11_mutual_gaze_duration_factor_address,
    &chartInstance->c11_mutual_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_cat_chance", (void **)
    &chartInstance->c11_pose_cat_chance_address,
    &chartInstance->c11_pose_cat_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chanc_factor", (void **)
    &chartInstance->c11_pose_chanc_factor_address,
    &chartInstance->c11_pose_chanc_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c11_pose_frequency_factor_address,
    &chartInstance->c11_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c11_pose_lean_address, &chartInstance->c11_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c11_pose_lean_flag_address,
    &chartInstance->c11_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c11_pose_speed_address, &chartInstance->c11_pose_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_twitch", (void **)
    &chartInstance->c11_pose_twitch_address,
    &chartInstance->c11_pose_twitch_index);
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

void sf_c11_Expriment_Pose_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2583398160U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(818661932U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1441057776U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3328010925U);
}

mxArray *sf_c11_Expriment_Pose_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("s1oeJOY4xY9kyRm5c3Q1I");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

mxArray *sf_c11_Expriment_Pose_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Expriment_Pose_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_Expriment_Pose(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c11_Expriment_Pose\",},{M[9],M[0],T\"is_c11_Expriment_Pose\",},{M[14],M[119],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Expriment_Pose_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Expriment_PoseInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_Expriment_PoseInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_PoseMachineNumber_,
           11,
           4,
           5,
           0,
           27,
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
          _SFD_SET_DATA_PROPS(2,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gazeArray");
          _SFD_SET_DATA_PROPS(4,1,1,0,"aChange");
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
          _SFD_SET_DATA_PROPS(16,11,0,0,"pose_cat_chance");
          _SFD_SET_DATA_PROPS(17,11,0,0,"pose_frequency_factor");
          _SFD_SET_DATA_PROPS(18,11,0,0,"pose_chanc_factor");
          _SFD_SET_DATA_PROPS(19,1,1,0,"personalityChange");
          _SFD_SET_DATA_PROPS(20,11,0,0,"avert_freq_factor");
          _SFD_SET_DATA_PROPS(21,11,0,0,"mut_freq_factor");
          _SFD_SET_DATA_PROPS(22,11,0,0,"pose_twitch");
          _SFD_SET_DATA_PROPS(23,1,1,0,"vChange");
          _SFD_SET_DATA_PROPS(24,11,0,0,"blinkperiod_min");
          _SFD_SET_DATA_PROPS(25,11,0,0,"blinkperiod_max");
          _SFD_SET_DATA_PROPS(26,11,0,0,"blink_flag");
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
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,11,1,11);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);

        {
          real_T *c11_inA;
          real_T *c11_inV;
          real_T *c11_personality;
          boolean_T *c11_aChange;
          boolean_T *c11_personalityFlag;
          boolean_T *c11_vaFlag;
          boolean_T *c11_personalityChange;
          boolean_T *c11_vChange;
          real_T (*c11_gazeArray)[6];
          real_T (*c11_poseArray)[6];
          c11_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c11_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 8);
          c11_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            7);
          c11_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c11_personalityFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 5);
          c11_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c11_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            3);
          c11_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_inA);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_inV);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_personality);
          _SFD_SET_DATA_VALUE_PTR(3U, *c11_gazeArray);
          _SFD_SET_DATA_VALUE_PTR(4U, c11_aChange);
          _SFD_SET_DATA_VALUE_PTR(5U, c11_personalityFlag);
          _SFD_SET_DATA_VALUE_PTR(6U, c11_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(7U,
            chartInstance->c11_avert_head_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c11_avert_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(9U,
            chartInstance->c11_mutual_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c11_avert_head_speed_address);
          _SFD_SET_DATA_VALUE_PTR(11U,
            chartInstance->c11_avert_gaze_dirs_chance_address);
          _SFD_SET_DATA_VALUE_PTR(12U, *c11_poseArray);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c11_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c11_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c11_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(16U,
            chartInstance->c11_pose_cat_chance_address);
          _SFD_SET_DATA_VALUE_PTR(17U,
            chartInstance->c11_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(18U,
            chartInstance->c11_pose_chanc_factor_address);
          _SFD_SET_DATA_VALUE_PTR(19U, c11_personalityChange);
          _SFD_SET_DATA_VALUE_PTR(20U,
            chartInstance->c11_avert_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(21U,
            chartInstance->c11_mut_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c11_pose_twitch_address);
          _SFD_SET_DATA_VALUE_PTR(23U, c11_vChange);
          _SFD_SET_DATA_VALUE_PTR(24U,
            chartInstance->c11_blinkperiod_min_address);
          _SFD_SET_DATA_VALUE_PTR(25U,
            chartInstance->c11_blinkperiod_max_address);
          _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c11_blink_flag_address);
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
  return "Bi1UvSLMdL51l56dLnoKWF";
}

static void sf_opaque_initialize_c11_Expriment_Pose(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
  initialize_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_Expriment_Pose(void *chartInstanceVar)
{
  enable_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_Expriment_Pose(void *chartInstanceVar)
{
  disable_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_Expriment_Pose(void *chartInstanceVar)
{
  sf_gateway_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_Expriment_Pose(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_Expriment_Pose
    ((SFc11_Expriment_PoseInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Expriment_Pose();/* state var info */
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

extern void sf_internal_set_sim_state_c11_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_Expriment_Pose();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_Expriment_Pose(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_Expriment_Pose(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c11_Expriment_Pose(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Expriment_PoseInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Pose_optimization_info();
    }

    finalize_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
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
  initSimStructsc11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Expriment_Pose(SimStruct *S)
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
    initialize_params_c11_Expriment_Pose((SFc11_Expriment_PoseInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Pose_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
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
        infoStruct,11,10);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2223449126U));
  ssSetChecksum1(S,(3925289732U));
  ssSetChecksum2(S,(26161954U));
  ssSetChecksum3(S,(1816386923U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Expriment_Pose(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_Expriment_Pose(SimStruct *S)
{
  SFc11_Expriment_PoseInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_Expriment_PoseInstanceStruct *)utMalloc(sizeof
    (SFc11_Expriment_PoseInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Expriment_PoseInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Expriment_Pose;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Expriment_Pose;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Expriment_Pose;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_Expriment_Pose;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_Expriment_Pose;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Expriment_Pose;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Expriment_Pose;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Expriment_Pose;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Expriment_Pose;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Expriment_Pose;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Expriment_Pose;
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

void c11_Expriment_Pose_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Expriment_Pose(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Expriment_Pose(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Expriment_Pose_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
