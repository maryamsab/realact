/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_FacialExpr_sfun.h"
#include "c55_Expriment_FacialExpr.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_FacialExpr_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c55_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c55_IN_init                    ((uint8_T)1U)
#define c55_IN_setBehavior             ((uint8_T)2U)
#define c55_IN_wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c55_subchartSimStateInfo;
static const char * c55_debug_family_names[2] = { "nargin", "nargout" };

static const char * c55_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c55_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c55_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c55_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c55_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void initialize_params_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void enable_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void disable_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_update_debugger_state_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void set_sim_state_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c55_st);
static void c55_set_sim_state_side_effects_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void finalize_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void sf_gateway_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_enter_atomic_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_enter_internal_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_exit_internal_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_initc55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void initSimStructsc55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void c55_enter_atomic_setBehavior
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber);
static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static real_T c55_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static boolean_T c55_b_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static int32_T c55_c_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_d_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static uint8_T c55_d_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_b_tp_init, const char_T *c55_identifier);
static uint8_T c55_e_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_e_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static const mxArray *c55_f_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static const mxArray *c55_f_emlrt_marshallIn
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c55_b_subchartSimStateInfo, const char_T *c55_identifier);
static const mxArray *c55_g_emlrt_marshallIn
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray *c55_u,
   const emlrtMsgIdentifier *c55_parentId);
static real_T c55_get_avert_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_avert_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_avert_freq_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_avert_gaze_dirs_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static void c55_set_avert_gaze_dirs_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c);
static real_T *c55_access_avert_gaze_dirs_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_avert_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static void c55_set_avert_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c);
static real_T *c55_access_avert_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_avert_head_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static void c55_set_avert_head_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c);
static real_T *c55_access_avert_head_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_avert_head_speed(SFc55_Expriment_FacialExprInstanceStruct *
  chartInstance, uint32_T c55_b);
static void c55_set_avert_head_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_avert_head_speed
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_mut_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_mut_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_mut_freq_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_mutual_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static void c55_set_mutual_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c);
static real_T *c55_access_mutual_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_cat_chance(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_pose_cat_chance(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_pose_cat_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_chanc_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_pose_chanc_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_pose_chanc_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static void c55_set_pose_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c);
static real_T *c55_access_pose_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_lean(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_pose_lean(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_pose_lean(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_lean_flag(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_pose_lean_flag(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_pose_lean_flag
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_pose_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_pose_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static real_T c55_get_pose_twitch(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void c55_set_pose_twitch(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c);
static real_T *c55_access_pose_twitch(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b);
static void init_dsm_address_info(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c55_update_debugger_state_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  uint32_T c55_prevAniVal;
  c55_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c55_is_active_c55_Expriment_FacialExpr == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 31U, chartInstance->c55_sfEvent);
  }

  if (chartInstance->c55_is_c55_Expriment_FacialExpr == c55_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
  }

  if (chartInstance->c55_is_c55_Expriment_FacialExpr == c55_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
  }

  if (chartInstance->c55_is_c55_Expriment_FacialExpr == c55_IN_setBehavior) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
  }

  _SFD_SET_ANIMATION(c55_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  const mxArray *c55_st;
  const mxArray *c55_y = NULL;
  uint8_T c55_hoistedGlobal;
  uint8_T c55_u;
  const mxArray *c55_b_y = NULL;
  uint8_T c55_b_hoistedGlobal;
  uint8_T c55_b_u;
  const mxArray *c55_c_y = NULL;
  const mxArray *c55_c_u;
  const mxArray *c55_d_y = NULL;
  c55_st = NULL;
  c55_st = NULL;
  sf_mex_assign(&c55_subchartSimStateInfo,
                sf_exported_auto_getSimstatec56_Expriment_FacialExpr
                (chartInstance->c55_subchartSimstruct), true);
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_createcellmatrix(3, 1), false);
  c55_hoistedGlobal = chartInstance->c55_is_active_c55_Expriment_FacialExpr;
  c55_u = c55_hoistedGlobal;
  c55_b_y = NULL;
  sf_mex_assign(&c55_b_y, sf_mex_create("y", &c55_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c55_y, 0, c55_b_y);
  c55_b_hoistedGlobal = chartInstance->c55_is_c55_Expriment_FacialExpr;
  c55_b_u = c55_b_hoistedGlobal;
  c55_c_y = NULL;
  sf_mex_assign(&c55_c_y, sf_mex_create("y", &c55_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c55_y, 1, c55_c_y);
  c55_c_u = sf_mex_dup(c55_subchartSimStateInfo);
  c55_d_y = NULL;
  sf_mex_assign(&c55_d_y, sf_mex_duplicatearraysafe(&c55_c_u), false);
  sf_mex_destroy(&c55_c_u);
  sf_mex_setcell(c55_y, 2, c55_d_y);
  sf_mex_assign(&c55_st, c55_y, false);
  return c55_st;
}

static void set_sim_state_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c55_st)
{
  const mxArray *c55_u;
  c55_u = sf_mex_dup(c55_st);
  chartInstance->c55_is_active_c55_Expriment_FacialExpr = c55_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 0)),
     "is_active_c55_Expriment_FacialExpr");
  chartInstance->c55_is_c55_Expriment_FacialExpr = c55_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 1)),
     "is_c55_Expriment_FacialExpr");
  sf_mex_assign(&c55_subchartSimStateInfo, c55_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c55_u, 2)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c55_setSimStateSideEffectsInfo,
                c55_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c55_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c55_u);
  chartInstance->c55_doSetSimStateSideEffects = 1U;
  c55_update_debugger_state_c55_Expriment_FacialExpr(chartInstance);
  sf_exported_auto_setSimstatec56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct, sf_mex_dup(c55_subchartSimStateInfo));
  sf_mex_destroy(&c55_st);
}

static void c55_set_sim_state_side_effects_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  if (chartInstance->c55_doSetSimStateSideEffects != 0) {
    if (chartInstance->c55_is_c55_Expriment_FacialExpr == c55_IN_init) {
      chartInstance->c55_tp_init = 1U;
    } else {
      chartInstance->c55_tp_init = 0U;
    }

    if (chartInstance->c55_is_c55_Expriment_FacialExpr == c55_IN_setBehavior) {
      chartInstance->c55_tp_setBehavior = 1U;
    } else {
      chartInstance->c55_tp_setBehavior = 0U;
    }

    if (chartInstance->c55_is_c55_Expriment_FacialExpr == c55_IN_wait) {
      chartInstance->c55_tp_wait = 1U;
    } else {
      chartInstance->c55_tp_wait = 0U;
    }

    chartInstance->c55_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  sf_mex_destroy(&c55_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c55_setSimStateSideEffectsInfo);
}

static void sf_gateway_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  c55_set_sim_state_side_effects_c55_Expriment_FacialExpr(chartInstance);
}

static void c55_enter_atomic_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
  chartInstance->c55_is_active_c55_Expriment_FacialExpr = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
}

static void c55_enter_internal_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  uint32_T c55_debug_family_var_map[2];
  real_T c55_nargin = 0.0;
  real_T c55_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
  chartInstance->c55_isStable = false;
  chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
  chartInstance->c55_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c55_debug_family_names,
    c55_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargin, 0U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargout, 1U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  c55_set_mutual_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c55_set_avert_gaze_duration_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c55_set_avert_head_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c55_set_avert_head_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c55_set_avert_gaze_dirs_chance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c55_set_avert_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  c55_set_mut_freq_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c55_set_pose_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c55_set_pose_chanc_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c55_set_pose_cat_chance(chartInstance, 0, 70.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c55_set_pose_lean(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c55_set_pose_speed(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c55_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c55_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  uint32_T c55_debug_family_var_map[3];
  real_T c55_nargin = 0.0;
  real_T c55_nargout = 1.0;
  boolean_T c55_out;
  real_T c55_b_nargin = 0.0;
  real_T c55_b_nargout = 1.0;
  boolean_T c55_b_out;
  boolean_T *c55_aChange;
  boolean_T *c55_vChange;
  c55_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c55_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c55_isStable = true;
  switch (chartInstance->c55_is_c55_Expriment_FacialExpr) {
   case c55_IN_init:
    CV_CHART_EVAL(31, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
    chartInstance->c55_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
    chartInstance->c55_isStable = false;
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
    chartInstance->c55_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c55_sfEvent);
    break;

   case c55_IN_setBehavior:
    CV_CHART_EVAL(31, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c55_sfEvent);
    chartInstance->c55_tp_setBehavior = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
    chartInstance->c55_isStable = false;
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
    chartInstance->c55_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c55_sfEvent);
    break;

   case c55_IN_wait:
    CV_CHART_EVAL(31, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c55_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c55_d_debug_family_names,
      c55_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargin, 0U, c55_sf_marshallOut,
      c55_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargout, 1U, c55_sf_marshallOut,
      c55_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_out, 2U, c55_b_sf_marshallOut,
      c55_b_sf_marshallIn);
    c55_out = CV_EML_IF(1, 0, 0, (real_T)*c55_aChange == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c55_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
      chartInstance->c55_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
      chartInstance->c55_isStable = false;
      chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_setBehavior;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
      chartInstance->c55_tp_setBehavior = 1U;
      c55_enter_atomic_setBehavior(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c55_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c55_c_debug_family_names,
        c55_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_b_nargin, 0U, c55_sf_marshallOut,
        c55_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_b_nargout, 1U,
        c55_sf_marshallOut, c55_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_b_out, 2U, c55_b_sf_marshallOut,
        c55_b_sf_marshallIn);
      c55_b_out = CV_EML_IF(4, 0, 0, (real_T)*c55_vChange == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c55_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c55_sfEvent);
        chartInstance->c55_tp_wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
        chartInstance->c55_isStable = false;
        chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_setBehavior;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
        chartInstance->c55_tp_setBehavior = 1U;
        c55_enter_atomic_setBehavior(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c55_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c55_sfEvent);
    break;

   default:
    CV_CHART_EVAL(31, 0, 0);
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c55_sfEvent);
}

static void c55_exit_internal_c55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  switch (chartInstance->c55_is_c55_Expriment_FacialExpr) {
   case c55_IN_init:
    CV_CHART_EVAL(31, 0, 1);
    chartInstance->c55_tp_init = 0U;
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
    break;

   case c55_IN_setBehavior:
    CV_CHART_EVAL(31, 0, 2);
    chartInstance->c55_tp_setBehavior = 0U;
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c55_sfEvent);
    break;

   case c55_IN_wait:
    CV_CHART_EVAL(31, 0, 3);
    chartInstance->c55_tp_wait = 0U;
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c55_sfEvent);
    break;

   default:
    CV_CHART_EVAL(31, 0, 0);
    chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c55_sfEvent);
    break;
  }
}

static void c55_initc55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  sf_exported_auto_initc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
  chartInstance->c55_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  c55_subchartSimStateInfo = NULL;
  chartInstance->c55_doSetSimStateSideEffects = 0U;
  chartInstance->c55_setSimStateSideEffectsInfo = NULL;
  chartInstance->c55_tp_init = 0U;
  chartInstance->c55_tp_setBehavior = 0U;
  chartInstance->c55_tp_wait = 0U;
  chartInstance->c55_is_active_c55_Expriment_FacialExpr = 0U;
  chartInstance->c55_is_c55_Expriment_FacialExpr = c55_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc55_Expriment_FacialExpr
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  chartInstance->c55_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "sharedFunc");
}

static void c55_enter_atomic_setBehavior
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance)
{
  uint32_T c55_debug_family_var_map[2];
  real_T c55_nargin = 0.0;
  real_T c55_nargout = 0.0;
  real_T c55_hoistedGlobal;
  real_T c55_b_hoistedGlobal;
  real_T c55_c_hoistedGlobal;
  boolean_T c55_d_hoistedGlobal;
  boolean_T c55_e_hoistedGlobal;
  real_T c55_v;
  real_T c55_a;
  real_T c55_p;
  boolean_T c55_pFlag;
  boolean_T c55_vaFlag;
  int32_T c55_i0;
  real_T c55_gazeArr[6];
  int32_T c55_i1;
  real_T c55_b_gazeArr[6];
  real_T c55_mutFreqFactor;
  real_T c55_avertFreqFactor;
  real_T c55_avertDirsChance;
  real_T c55_avertHeadSpeed;
  real_T c55_avertHeadFreqFactor;
  real_T c55_avertDurFactor;
  real_T c55_mutDurFactor;
  real_T c55_mutual_gaze_duration_factor;
  real_T c55_avert_gaze_duration_factor;
  real_T c55_avert_head_frequency_factor;
  real_T c55_avert_head_speed;
  real_T c55_avert_gaze_dirs_chance;
  real_T c55_avert_freq_factor;
  real_T c55_mut_freq_factor;
  real_T c55_f_hoistedGlobal;
  real_T c55_g_hoistedGlobal;
  real_T c55_h_hoistedGlobal;
  boolean_T c55_i_hoistedGlobal;
  boolean_T c55_j_hoistedGlobal;
  boolean_T c55_k_hoistedGlobal;
  real_T c55_b_v;
  real_T c55_ar;
  real_T c55_b_p;
  boolean_T c55_b_pFlag;
  boolean_T c55_b_vaFlag;
  int32_T c55_i2;
  real_T c55_personalityChange;
  int32_T c55_i3;
  real_T c55_c_gazeArr[6];
  real_T c55_poseLeanFlag;
  real_T c55_poseSpeed;
  real_T c55_poseLean;
  real_T c55_poseCatChance;
  real_T c55_poseChanceFactor;
  real_T c55_poseFreqFactor;
  real_T c55_poseTwitch;
  real_T c55_pose_twitch;
  real_T c55_pose_frequency_factor;
  real_T c55_pose_chanc_factor;
  real_T c55_pose_cat_chance;
  real_T c55_pose_lean;
  real_T c55_pose_speed;
  real_T c55_pose_lean_flag;
  real_T *c55_inV;
  real_T *c55_inA;
  real_T *c55_personality;
  boolean_T *c55_personalityFlag;
  boolean_T *c55_c_vaFlag;
  boolean_T *c55_b_personalityChange;
  real_T (*c55_poseArray)[6];
  real_T (*c55_gazeArray)[6];
  c55_b_personalityChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
    8);
  c55_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 7);
  c55_c_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c55_personalityFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c55_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c55_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c55_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c55_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c55_b_debug_family_names,
    c55_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargin, 0U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargout, 1U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  c55_hoistedGlobal = *c55_inV;
  c55_b_hoistedGlobal = *c55_inA;
  c55_c_hoistedGlobal = *c55_personality;
  c55_d_hoistedGlobal = *c55_personalityFlag;
  c55_e_hoistedGlobal = *c55_c_vaFlag;
  c55_v = c55_hoistedGlobal;
  c55_a = c55_b_hoistedGlobal;
  c55_p = c55_c_hoistedGlobal;
  c55_pFlag = c55_d_hoistedGlobal;
  c55_vaFlag = c55_e_hoistedGlobal;
  for (c55_i0 = 0; c55_i0 < 6; c55_i0++) {
    c55_gazeArr[c55_i0] = (*c55_gazeArray)[c55_i0];
  }

  for (c55_i1 = 0; c55_i1 < 6; c55_i1++) {
    c55_b_gazeArr[c55_i1] = c55_gazeArr[c55_i1];
  }

  sf_exported_user_c56_Expriment_FacialExpr_setGazeFactors
    (chartInstance->c55_subchartSimstruct, c55_v, c55_a, c55_p, c55_pFlag,
     c55_vaFlag, c55_b_gazeArr, &c55_mutDurFactor, &c55_avertDurFactor,
     &c55_avertHeadFreqFactor, &c55_avertHeadSpeed, &c55_avertDirsChance,
     &c55_avertFreqFactor, &c55_mutFreqFactor);
  c55_mutual_gaze_duration_factor = c55_mutDurFactor;
  c55_avert_gaze_duration_factor = c55_avertDurFactor;
  c55_avert_head_frequency_factor = c55_avertHeadFreqFactor;
  c55_avert_head_speed = c55_avertHeadSpeed;
  c55_avert_gaze_dirs_chance = c55_avertDirsChance;
  c55_avert_freq_factor = c55_avertFreqFactor;
  c55_mut_freq_factor = c55_mutFreqFactor;
  c55_set_mutual_gaze_duration_factor(chartInstance, 0,
    c55_mutual_gaze_duration_factor);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c55_set_avert_gaze_duration_factor(chartInstance, 0,
    c55_avert_gaze_duration_factor);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c55_set_avert_head_frequency_factor(chartInstance, 0,
    c55_avert_head_frequency_factor);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c55_set_avert_head_speed(chartInstance, 0, c55_avert_head_speed);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c55_set_avert_gaze_dirs_chance(chartInstance, 0, c55_avert_gaze_dirs_chance);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c55_set_avert_freq_factor(chartInstance, 0, c55_avert_freq_factor);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  c55_set_mut_freq_factor(chartInstance, 0, c55_mut_freq_factor);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c55_f_hoistedGlobal = *c55_inV;
  c55_g_hoistedGlobal = *c55_inA;
  c55_h_hoistedGlobal = *c55_personality;
  c55_i_hoistedGlobal = *c55_personalityFlag;
  c55_j_hoistedGlobal = *c55_c_vaFlag;
  c55_k_hoistedGlobal = *c55_b_personalityChange;
  c55_b_v = c55_f_hoistedGlobal;
  c55_ar = c55_g_hoistedGlobal;
  c55_b_p = c55_h_hoistedGlobal;
  c55_b_pFlag = c55_i_hoistedGlobal;
  c55_b_vaFlag = c55_j_hoistedGlobal;
  for (c55_i2 = 0; c55_i2 < 6; c55_i2++) {
    c55_gazeArr[c55_i2] = (*c55_poseArray)[c55_i2];
  }

  c55_personalityChange = (real_T)c55_k_hoistedGlobal;
  for (c55_i3 = 0; c55_i3 < 6; c55_i3++) {
    c55_c_gazeArr[c55_i3] = c55_gazeArr[c55_i3];
  }

  sf_exported_user_c56_Expriment_FacialExpr_setPoseFactors
    (chartInstance->c55_subchartSimstruct, c55_b_v, c55_ar, c55_b_p, c55_b_pFlag,
     c55_b_vaFlag, c55_c_gazeArr, c55_personalityChange, &c55_poseTwitch,
     &c55_poseFreqFactor, &c55_poseChanceFactor, &c55_poseCatChance,
     &c55_poseLean, &c55_poseSpeed, &c55_poseLeanFlag);
  c55_pose_twitch = c55_poseTwitch;
  c55_pose_frequency_factor = c55_poseFreqFactor;
  c55_pose_chanc_factor = c55_poseChanceFactor;
  c55_pose_cat_chance = c55_poseCatChance;
  c55_pose_lean = c55_poseLean;
  c55_pose_speed = c55_poseSpeed;
  c55_pose_lean_flag = c55_poseLeanFlag;
  c55_set_pose_twitch(chartInstance, 0, c55_pose_twitch);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c55_set_pose_frequency_factor(chartInstance, 0, c55_pose_frequency_factor);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c55_set_pose_chanc_factor(chartInstance, 0, c55_pose_chanc_factor);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c55_set_pose_cat_chance(chartInstance, 0, c55_pose_cat_chance);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c55_set_pose_lean(chartInstance, 0, c55_pose_lean);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c55_set_pose_speed(chartInstance, 0, c55_pose_speed);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c55_set_pose_lean_flag(chartInstance, 0, c55_pose_lean_flag);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber)
{
  (void)c55_machineNumber;
  (void)c55_chartNumber;
  (void)c55_instanceNumber;
}

static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  real_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(real_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static real_T c55_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  real_T c55_y;
  real_T c55_d0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_d0, 1, 0, 0U, 0, 0U, 0);
  c55_y = c55_d0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_nargout;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  real_T c55_y;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_nargout = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_nargout),
    &c55_thisId);
  sf_mex_destroy(&c55_nargout);
  *(real_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  boolean_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(boolean_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static boolean_T c55_b_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  boolean_T c55_y;
  boolean_T c55_b0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_b0, 1, 11, 0U, 0, 0U, 0);
  c55_y = c55_b0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_sf_internal_predicateOutput;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  boolean_T c55_y;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_sf_internal_predicateOutput = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c55_sf_internal_predicateOutput), &c55_thisId);
  sf_mex_destroy(&c55_sf_internal_predicateOutput);
  *(boolean_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

const mxArray *sf_c55_Expriment_FacialExpr_get_eml_resolved_functions_info(void)
{
  const mxArray *c55_nameCaptureInfo = NULL;
  c55_nameCaptureInfo = NULL;
  sf_mex_assign(&c55_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c55_nameCaptureInfo;
}

boolean_T sf_exported_auto_isStablec55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  return chartInstance->c55_isStable;
}

void sf_exported_auto_duringc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  c55_c55_Expriment_FacialExpr(chartInstance);
}

void sf_exported_auto_enterc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
  c55_enter_atomic_c55_Expriment_FacialExpr(chartInstance);
  c55_enter_internal_c55_Expriment_FacialExpr(chartInstance);
}

void sf_exported_auto_exitc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c55_exit_internal_c55_Expriment_FacialExpr(chartInstance);
  sf_exported_auto_disablec56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_gatewayc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_enablec55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_enablec56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_disablec55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_disablec56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_stepBuffersc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  sf_exported_auto_stepBuffersc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_initBuffersc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  sf_exported_auto_initBuffersc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
  sf_exported_auto_initBuffersc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_activate_callc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  chartInstance->c55_sfEvent = CALL_EVENT;
  sf_exported_auto_activate_callc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_increment_call_counterc55_Expriment_FacialExpr(SimStruct
  *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  sf_exported_auto_increment_call_counterc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_reset_call_counterc55_Expriment_FacialExpr(SimStruct
  *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  sf_exported_auto_reset_call_counterc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_deactivate_callc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  sf_exported_auto_deactivate_callc56_Expriment_FacialExpr
    (chartInstance->c55_subchartSimstruct);
}

void sf_exported_auto_initc55_Expriment_FacialExpr(SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  c55_initc55_Expriment_FacialExpr(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec55_Expriment_FacialExpr(SimStruct
  *c55_S)
{
  const mxArray *c55_out = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  c55_out = NULL;
  sf_mex_assign(&c55_out, sf_internal_get_sim_state_c55_Expriment_FacialExpr
                (c55_S), false);
  return c55_out;
}

void sf_exported_auto_setSimstatec55_Expriment_FacialExpr(SimStruct *c55_S,
  const mxArray *c55_in)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c55_Expriment_FacialExpr(c55_S, sf_mex_dup(c55_in));
  sf_mex_destroy(&c55_in);
}

void sf_exported_auto_check_state_inconsistency_c55_Expriment_FacialExpr
  (SimStruct *c55_S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c55_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_FacialExprMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(int32_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static int32_T c55_c_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  int32_T c55_y;
  int32_T c55_i4;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_i4, 1, 6, 0U, 0, 0U, 0);
  c55_y = c55_i4;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_sfEvent;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  int32_T c55_y;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_b_sfEvent = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_sfEvent),
    &c55_thisId);
  sf_mex_destroy(&c55_b_sfEvent);
  *(int32_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static const mxArray *c55_d_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  uint8_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(uint8_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static uint8_T c55_d_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_b_tp_init, const char_T *c55_identifier)
{
  uint8_T c55_y;
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_tp_init),
    &c55_thisId);
  sf_mex_destroy(&c55_b_tp_init);
  return c55_y;
}

static uint8_T c55_e_emlrt_marshallIn(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  uint8_T c55_y;
  uint8_T c55_u0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_u0, 1, 3, 0U, 0, 0U, 0);
  c55_y = c55_u0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_tp_init;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  uint8_T c55_y;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_b_tp_init = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_tp_init),
    &c55_thisId);
  sf_mex_destroy(&c55_b_tp_init);
  *(uint8_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static const mxArray *c55_e_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_i5;
  real_T c55_b_inData[6];
  int32_T c55_i6;
  real_T c55_u[6];
  const mxArray *c55_y = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  for (c55_i5 = 0; c55_i5 < 6; c55_i5++) {
    c55_b_inData[c55_i5] = (*(real_T (*)[6])c55_inData)[c55_i5];
  }

  for (c55_i6 = 0; c55_i6 < 6; c55_i6++) {
    c55_u[c55_i6] = c55_b_inData[c55_i6];
  }

  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", c55_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static const mxArray *c55_f_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  const mxArray *c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = sf_mex_dup(*(const mxArray **)c55_inData);
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_duplicatearraysafe(&c55_u), false);
  sf_mex_destroy(&c55_u);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static const mxArray *c55_f_emlrt_marshallIn
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray
   *c55_b_subchartSimStateInfo, const char_T *c55_identifier)
{
  const mxArray *c55_y = NULL;
  emlrtMsgIdentifier c55_thisId;
  c55_y = NULL;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  sf_mex_assign(&c55_y, c55_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c55_b_subchartSimStateInfo), &c55_thisId), false);
  sf_mex_destroy(&c55_b_subchartSimStateInfo);
  return c55_y;
}

static const mxArray *c55_g_emlrt_marshallIn
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, const mxArray *c55_u,
   const emlrtMsgIdentifier *c55_parentId)
{
  const mxArray *c55_y = NULL;
  (void)chartInstance;
  (void)c55_parentId;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_duplicatearraysafe(&c55_u), false);
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static real_T c55_get_avert_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c55_b);
  if (chartInstance->c55_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#3534) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_avert_freq_factor_address;
}

static void c55_set_avert_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c55_b);
  if (chartInstance->c55_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#3534) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_avert_freq_factor_address = c55_c;
}

static real_T *c55_access_avert_freq_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c55_avert_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_freq_factor\' (#3534) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_avert_freq_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c55_c;
}

static real_T c55_get_avert_gaze_dirs_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c55_b);
  if (chartInstance->c55_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#3525) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_avert_gaze_dirs_chance_address;
}

static void c55_set_avert_gaze_dirs_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c55_b);
  if (chartInstance->c55_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#3525) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_avert_gaze_dirs_chance_address = c55_c;
}

static real_T *c55_access_avert_gaze_dirs_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c55_avert_gaze_dirs_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_dirs_chance\' (#3525) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_avert_gaze_dirs_chance_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c55_c;
}

static real_T c55_get_avert_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c55_b);
  if (chartInstance->c55_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#3522) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_avert_gaze_duration_factor_address;
}

static void c55_set_avert_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c55_b);
  if (chartInstance->c55_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#3522) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_avert_gaze_duration_factor_address = c55_c;
}

static real_T *c55_access_avert_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c55_avert_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_gaze_duration_factor\' (#3522) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_avert_gaze_duration_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c55_c;
}

static real_T c55_get_avert_head_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c55_b);
  if (chartInstance->c55_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#3521) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_avert_head_frequency_factor_address;
}

static void c55_set_avert_head_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c55_b);
  if (chartInstance->c55_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#3521) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_avert_head_frequency_factor_address = c55_c;
}

static real_T *c55_access_avert_head_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c55_avert_head_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_frequency_factor\' (#3521) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_avert_head_frequency_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c55_c;
}

static real_T c55_get_avert_head_speed(SFc55_Expriment_FacialExprInstanceStruct *
  chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c55_b);
  if (chartInstance->c55_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#3524) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_avert_head_speed_address;
}

static void c55_set_avert_head_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c55_b);
  if (chartInstance->c55_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#3524) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_avert_head_speed_address = c55_c;
}

static real_T *c55_access_avert_head_speed
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c55_avert_head_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert_head_speed\' (#3524) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_avert_head_speed_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c55_c;
}

static real_T c55_get_mut_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c55_b);
  if (chartInstance->c55_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#3535) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_mut_freq_factor_address;
}

static void c55_set_mut_freq_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c55_b);
  if (chartInstance->c55_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#3535) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_mut_freq_factor_address = c55_c;
}

static real_T *c55_access_mut_freq_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c55_mut_freq_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mut_freq_factor\' (#3535) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_mut_freq_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c55_c;
}

static real_T c55_get_mutual_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c55_b);
  if (chartInstance->c55_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#3523) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_mutual_gaze_duration_factor_address;
}

static void c55_set_mutual_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c55_b);
  if (chartInstance->c55_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#3523) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_mutual_gaze_duration_factor_address = c55_c;
}

static real_T *c55_access_mutual_gaze_duration_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c55_mutual_gaze_duration_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mutual_gaze_duration_factor\' (#3523) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_mutual_gaze_duration_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_cat_chance(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c55_b);
  if (chartInstance->c55_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#3530) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_cat_chance_address;
}

static void c55_set_pose_cat_chance(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c55_b);
  if (chartInstance->c55_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#3530) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_cat_chance_address = c55_c;
}

static real_T *c55_access_pose_cat_chance
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c55_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#3530) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_cat_chance_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_chanc_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c55_b);
  if (chartInstance->c55_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#3532) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_chanc_factor_address;
}

static void c55_set_pose_chanc_factor(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c55_b);
  if (chartInstance->c55_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#3532) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_chanc_factor_address = c55_c;
}

static real_T *c55_access_pose_chanc_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c55_pose_chanc_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chanc_factor\' (#3532) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_chanc_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c55_b);
  if (chartInstance->c55_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#3531) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_frequency_factor_address;
}

static void c55_set_pose_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b,
   real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c55_b);
  if (chartInstance->c55_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#3531) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_frequency_factor_address = c55_c;
}

static real_T *c55_access_pose_frequency_factor
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c55_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#3531) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_frequency_factor_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_lean(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c55_b);
  if (chartInstance->c55_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#3527) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_lean_address;
}

static void c55_set_pose_lean(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c55_b);
  if (chartInstance->c55_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#3527) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_lean_address = c55_c;
}

static real_T *c55_access_pose_lean(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c55_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#3527) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_lean_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_lean_flag(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c55_b);
  if (chartInstance->c55_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#3529) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_lean_flag_address;
}

static void c55_set_pose_lean_flag(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c55_b);
  if (chartInstance->c55_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#3529) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_lean_flag_address = c55_c;
}

static real_T *c55_access_pose_lean_flag
  (SFc55_Expriment_FacialExprInstanceStruct *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c55_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#3529) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_lean_flag_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c55_b);
  if (chartInstance->c55_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#3528) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_speed_address;
}

static void c55_set_pose_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c55_b);
  if (chartInstance->c55_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#3528) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_speed_address = c55_c;
}

static real_T *c55_access_pose_speed(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c55_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#3528) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_speed_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c55_c;
}

static real_T c55_get_pose_twitch(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c55_b);
  if (chartInstance->c55_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#3536) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c55_pose_twitch_address;
}

static void c55_set_pose_twitch(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b, real_T c55_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c55_b);
  if (chartInstance->c55_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#3536) in the initialization routine of the chart.\n");
  }

  *chartInstance->c55_pose_twitch_address = c55_c;
}

static real_T *c55_access_pose_twitch(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance, uint32_T c55_b)
{
  real_T *c55_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c55_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#3536) in the initialization routine of the chart.\n");
  }

  c55_c = chartInstance->c55_pose_twitch_address;
  if (c55_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c55_c;
}

static void init_dsm_address_info(SFc55_Expriment_FacialExprInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_freq_factor", (void **)
    &chartInstance->c55_avert_freq_factor_address,
    &chartInstance->c55_avert_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_dirs_chance",
    (void **)&chartInstance->c55_avert_gaze_dirs_chance_address,
    &chartInstance->c55_avert_gaze_dirs_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_gaze_duration_factor",
                                (void **)
    &chartInstance->c55_avert_gaze_duration_factor_address,
    &chartInstance->c55_avert_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_frequency_factor",
                                (void **)
    &chartInstance->c55_avert_head_frequency_factor_address,
    &chartInstance->c55_avert_head_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert_head_speed", (void **)
    &chartInstance->c55_avert_head_speed_address,
    &chartInstance->c55_avert_head_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mut_freq_factor", (void **)
    &chartInstance->c55_mut_freq_factor_address,
    &chartInstance->c55_mut_freq_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mutual_gaze_duration_factor",
                                (void **)
    &chartInstance->c55_mutual_gaze_duration_factor_address,
    &chartInstance->c55_mutual_gaze_duration_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_cat_chance", (void **)
    &chartInstance->c55_pose_cat_chance_address,
    &chartInstance->c55_pose_cat_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chanc_factor", (void **)
    &chartInstance->c55_pose_chanc_factor_address,
    &chartInstance->c55_pose_chanc_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c55_pose_frequency_factor_address,
    &chartInstance->c55_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c55_pose_lean_address, &chartInstance->c55_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c55_pose_lean_flag_address,
    &chartInstance->c55_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c55_pose_speed_address, &chartInstance->c55_pose_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_twitch", (void **)
    &chartInstance->c55_pose_twitch_address,
    &chartInstance->c55_pose_twitch_index);
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

void sf_c55_Expriment_FacialExpr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2252776908U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(145340164U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1823028372U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2657154140U);
}

mxArray *sf_c55_Expriment_FacialExpr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KyWBx21i0O5a4e6Sey9VzD");
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

mxArray *sf_c55_Expriment_FacialExpr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c55_Expriment_FacialExpr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c55_Expriment_FacialExpr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c55_Expriment_FacialExpr\",},{M[9],M[0],T\"is_c55_Expriment_FacialExpr\",},{M[14],M[119],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c55_Expriment_FacialExpr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_FacialExprMachineNumber_,
           55,
           4,
           5,
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
        init_script_number_translation(_Expriment_FacialExprMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_FacialExprMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_FacialExprMachineNumber_,
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
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,11,1,11);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)c55_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c55_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c55_inA;
          real_T *c55_inV;
          real_T *c55_personality;
          boolean_T *c55_aChange;
          boolean_T *c55_personalityFlag;
          boolean_T *c55_vaFlag;
          boolean_T *c55_personalityChange;
          boolean_T *c55_vChange;
          real_T (*c55_gazeArray)[6];
          real_T (*c55_poseArray)[6];
          c55_vChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c55_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 8);
          c55_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            7);
          c55_vaFlag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c55_personalityFlag = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 5);
          c55_aChange = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c55_gazeArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            3);
          c55_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c55_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c55_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c55_inA);
          _SFD_SET_DATA_VALUE_PTR(1U, c55_inV);
          _SFD_SET_DATA_VALUE_PTR(2U, c55_personality);
          _SFD_SET_DATA_VALUE_PTR(3U, *c55_gazeArray);
          _SFD_SET_DATA_VALUE_PTR(4U, c55_aChange);
          _SFD_SET_DATA_VALUE_PTR(5U, c55_personalityFlag);
          _SFD_SET_DATA_VALUE_PTR(6U, c55_vaFlag);
          _SFD_SET_DATA_VALUE_PTR(7U,
            chartInstance->c55_avert_head_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c55_avert_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(9U,
            chartInstance->c55_mutual_gaze_duration_factor_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c55_avert_head_speed_address);
          _SFD_SET_DATA_VALUE_PTR(11U,
            chartInstance->c55_avert_gaze_dirs_chance_address);
          _SFD_SET_DATA_VALUE_PTR(12U, *c55_poseArray);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c55_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c55_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c55_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(16U,
            chartInstance->c55_pose_cat_chance_address);
          _SFD_SET_DATA_VALUE_PTR(17U,
            chartInstance->c55_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(18U,
            chartInstance->c55_pose_chanc_factor_address);
          _SFD_SET_DATA_VALUE_PTR(19U, c55_personalityChange);
          _SFD_SET_DATA_VALUE_PTR(20U,
            chartInstance->c55_avert_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(21U,
            chartInstance->c55_mut_freq_factor_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c55_pose_twitch_address);
          _SFD_SET_DATA_VALUE_PTR(23U, c55_vChange);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_FacialExprMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "KtFpBaCeZx3xzpufYy9tIH";
}

static void sf_opaque_initialize_c55_Expriment_FacialExpr(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc55_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c55_Expriment_FacialExpr
    ((SFc55_Expriment_FacialExprInstanceStruct*) chartInstanceVar);
  initialize_c55_Expriment_FacialExpr((SFc55_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c55_Expriment_FacialExpr(void *chartInstanceVar)
{
  enable_c55_Expriment_FacialExpr((SFc55_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c55_Expriment_FacialExpr(void *chartInstanceVar)
{
  disable_c55_Expriment_FacialExpr((SFc55_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c55_Expriment_FacialExpr(void *chartInstanceVar)
{
  sf_gateway_c55_Expriment_FacialExpr((SFc55_Expriment_FacialExprInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c55_Expriment_FacialExpr
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c55_Expriment_FacialExpr
    ((SFc55_Expriment_FacialExprInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c55_Expriment_FacialExpr();/* state var info */
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

extern void sf_internal_set_sim_state_c55_Expriment_FacialExpr(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c55_Expriment_FacialExpr();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c55_Expriment_FacialExpr
    ((SFc55_Expriment_FacialExprInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c55_Expriment_FacialExpr(SimStruct*
  S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c55_Expriment_FacialExpr(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c55_Expriment_FacialExpr(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc55_Expriment_FacialExprInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_FacialExpr_optimization_info();
    }

    finalize_c55_Expriment_FacialExpr((SFc55_Expriment_FacialExprInstanceStruct*)
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
  initSimStructsc55_Expriment_FacialExpr
    ((SFc55_Expriment_FacialExprInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c55_Expriment_FacialExpr(SimStruct *S)
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
    initialize_params_c55_Expriment_FacialExpr
      ((SFc55_Expriment_FacialExprInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c55_Expriment_FacialExpr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_FacialExpr_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      55);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,55,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,55,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,55);
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
        infoStruct,55,10);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,55);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2486093121U));
  ssSetChecksum1(S,(1329946693U));
  ssSetChecksum2(S,(612445662U));
  ssSetChecksum3(S,(3202068293U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c55_Expriment_FacialExpr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c55_Expriment_FacialExpr(SimStruct *S)
{
  SFc55_Expriment_FacialExprInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc55_Expriment_FacialExprInstanceStruct *)utMalloc(sizeof
    (SFc55_Expriment_FacialExprInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc55_Expriment_FacialExprInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.mdlStart = mdlStart_c55_Expriment_FacialExpr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c55_Expriment_FacialExpr;
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

void c55_Expriment_FacialExpr_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c55_Expriment_FacialExpr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c55_Expriment_FacialExpr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c55_Expriment_FacialExpr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c55_Expriment_FacialExpr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
