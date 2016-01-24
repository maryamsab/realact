/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSs_Bdr_GK_BIS_sfun.h"
#include "c10_ARP_02_RPSs_Bdr_GK_BIS.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSs_Bdr_GK_BIS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c10_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c10_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c10_IN_gazeMiddle              ((uint8_T)1U)
#define c10_IN_gazeRight               ((uint8_T)2U)
#define c10_IN_stateGazeLeft           ((uint8_T)3U)
#define c10_IN_stateIdleL              ((uint8_T)4U)
#define c10_IN_stateIdleM              ((uint8_T)5U)
#define c10_IN_stateIdleR              ((uint8_T)6U)
#define c10_IN_stateInit               ((uint8_T)7U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c10_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "gazeBML" };

static const char * c10_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c10_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void initialize_params_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void enable_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void disable_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c10_st);
static void c10_set_sim_state_side_effects_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void finalize_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void sf_gateway_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_enter_atomic_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_enter_internal_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_exit_internal_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_initc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void initSimStructsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_gazeMiddle(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);
static void c10_stateIdleL(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);
static void c10_stateGazeLeft(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);
static void c10_stateIdleM(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);
static void c10_gazeRight(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);
static void c10_encStr2Arr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_b_encStr2Arr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_c_encStr2Arr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_b_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, const mxArray *c10_bmlID, const char_T *c10_identifier);
static real_T c10_c_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static boolean_T c10_d_emlrt_marshallIn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_e_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256]);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_activate_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_deactivate_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_increment_counters_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_reset_counters_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance);
static void c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, real_T c10_bmlID,
   real_T c10_gazeBML[256]);
static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int8_T c10_f_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_g_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_m_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static uint8_T c10_h_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_b_tp_stateInit, const char_T
  *c10_identifier);
static uint8_T c10_i_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_j_emlrt_marshallIn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier);
static const mxArray *c10_k_emlrt_marshallIn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_updateDataWrittenToVector
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex);
static void c10_errorIfDataNotWrittenToFcn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex, uint32_T c10_dataNumber);
static real_T c10_get_BML(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_BML(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_BML(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_STATE_BEFORE(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_STATE_BEFORE(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_STATE_BEFORE
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c10_b);
static real_T c10_get_STATE_OVER(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_STATE_OVER(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_STATE_OVER(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c10_b);
static real_T c10_get_STATE_READY(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_STATE_READY(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_STATE_READY(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_isPosing(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_isPosing(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_isPosing(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_pr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_pr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c10_b, real_T c10_c);
static real_T *c10_access_pr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b);
static void init_dsm_address_info(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_update_debugger_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  uint32_T c10_prevAniVal;
  c10_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c10_is_active_c10_ARP_02_RPSs_Bdr_GK_BIS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_gazeMiddle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateIdleL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateGazeLeft)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateIdleR) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateIdleM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_gazeRight) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  }

  _SFD_SET_ANIMATION(c10_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
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
  uint8_T c10_d_hoistedGlobal;
  uint8_T c10_d_u;
  const mxArray *c10_e_y = NULL;
  real_T *c10_gameState;
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(4, 1), false);
  c10_hoistedGlobal = *c10_gameState;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = chartInstance->c10_is_active_c10_ARP_02_RPSs_Bdr_GK_BIS;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_hoistedGlobal = chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS;
  c10_c_u = c10_c_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  c10_d_hoistedGlobal = chartInstance->c10_temporalCounter_i1;
  c10_d_u = c10_d_hoistedGlobal;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
   *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_gameState;
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_u = sf_mex_dup(c10_st);
  *c10_gameState = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "gameState");
  chartInstance->c10_is_active_c10_ARP_02_RPSs_Bdr_GK_BIS =
    c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "is_active_c10_ARP_02_RPSs_Bdr_GK_BIS");
  chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
     "is_c10_ARP_02_RPSs_Bdr_GK_BIS");
  chartInstance->c10_temporalCounter_i1 = c10_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c10_u, 3)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c10_setSimStateSideEffectsInfo,
                c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 4)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c10_u);
  chartInstance->c10_doSetSimStateSideEffects = 1U;
  c10_update_debugger_state_c10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void c10_set_sim_state_side_effects_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  if (chartInstance->c10_doSetSimStateSideEffects != 0) {
    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_gazeMiddle) {
      chartInstance->c10_tp_gazeMiddle = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_gazeMiddle = 0U;
    }

    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_gazeRight) {
      chartInstance->c10_tp_gazeRight = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_gazeRight = 0U;
    }

    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateGazeLeft)
    {
      chartInstance->c10_tp_stateGazeLeft = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_stateGazeLeft = 0U;
    }

    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateIdleL) {
      chartInstance->c10_tp_stateIdleL = 1U;
    } else {
      chartInstance->c10_tp_stateIdleL = 0U;
    }

    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateIdleM) {
      chartInstance->c10_tp_stateIdleM = 1U;
    } else {
      chartInstance->c10_tp_stateIdleM = 0U;
    }

    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateIdleR) {
      chartInstance->c10_tp_stateIdleR = 1U;
    } else {
      chartInstance->c10_tp_stateIdleR = 0U;
    }

    if (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS == c10_IN_stateInit) {
      chartInstance->c10_tp_stateInit = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_stateInit = 0U;
    }

    chartInstance->c10_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c10_setSimStateSideEffectsInfo);
}

static void sf_gateway_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  c10_set_sim_state_side_effects_c10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

static void c10_enter_atomic_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
  chartInstance->c10_is_active_c10_ARP_02_RPSs_Bdr_GK_BIS = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
}

static void c10_enter_internal_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[2];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 0.0;
  real_T *c10_gameState;
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  chartInstance->c10_isStable = false;
  chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_e_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  *c10_gameState = c10_get_STATE_BEFORE(chartInstance, 0);
  c10_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_dv0[256];
  int32_T c10_i0;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 0.0;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_dv1[256];
  int32_T c10_i1;
  real_T c10_g_nargin = 0.0;
  real_T c10_g_nargout = 1.0;
  boolean_T c10_c_out;
  real_T c10_h_nargin = 0.0;
  real_T c10_h_nargout = 1.0;
  boolean_T c10_d_out;
  real_T c10_i_nargin = 0.0;
  real_T c10_i_nargout = 0.0;
  real_T c10_j_nargin = 0.0;
  real_T c10_j_nargout = 0.0;
  real_T c10_dv2[256];
  int32_T c10_i2;
  real_T c10_k_nargin = 0.0;
  real_T c10_k_nargout = 1.0;
  boolean_T c10_e_out;
  real_T c10_l_nargin = 0.0;
  real_T c10_l_nargout = 0.0;
  real_T c10_m_nargin = 0.0;
  real_T c10_m_nargout = 0.0;
  real_T c10_dv3[256];
  int32_T c10_i3;
  real_T c10_n_nargin = 0.0;
  real_T c10_n_nargout = 1.0;
  boolean_T c10_f_out;
  real_T c10_o_nargin = 0.0;
  real_T c10_o_nargout = 0.0;
  real_T *c10_isMoving;
  real_T *c10_gameState;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_isStable = true;
  switch (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS) {
   case c10_IN_gazeMiddle:
    CV_CHART_EVAL(6, 0, 1);
    c10_gazeMiddle(chartInstance);
    break;

   case c10_IN_gazeRight:
    CV_CHART_EVAL(6, 0, 2);
    c10_gazeRight(chartInstance);
    break;

   case c10_IN_stateGazeLeft:
    CV_CHART_EVAL(6, 0, 3);
    c10_stateGazeLeft(chartInstance);
    break;

   case c10_IN_stateIdleL:
    CV_CHART_EVAL(6, 0, 4);
    c10_stateIdleL(chartInstance);
    break;

   case c10_IN_stateIdleM:
    CV_CHART_EVAL(6, 0, 5);
    c10_stateIdleM(chartInstance);
    break;

   case c10_IN_stateIdleR:
    CV_CHART_EVAL(6, 0, 6);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_p_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_out = CV_EML_IF(20, 0, 0, *c10_isMoving == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_q_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c10_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c10_tp_stateIdleR = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateGazeLeft;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_stateGazeLeft = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_h_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 2.0,
        c10_dv0);
      for (c10_i0 = 0; c10_i0 < 256; c10_i0++) {
        c10_set_BML(chartInstance, c10_i0, c10_dv0[c10_i0]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c10_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_m_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      guard3 = false;
      if (CV_EML_COND(18, 0, 0, *c10_isMoving == 0.0)) {
        guard3 = true;
      } else {
        c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        if (CV_EML_COND(18, 0, 1, *c10_gameState == c10_get_STATE_READY
                        (chartInstance, 0))) {
          guard3 = true;
        } else {
          CV_EML_MCDC(18, 0, 0, false);
          CV_EML_IF(18, 0, 0, false);
          c10_b_out = false;
        }
      }

      if (guard3 == true) {
        CV_EML_MCDC(18, 0, 0, true);
        CV_EML_IF(18, 0, 0, true);
        c10_b_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c10_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_n_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        c10_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c10_tp_stateIdleR = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeMiddle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
        chartInstance->c10_temporalCounter_i1 = 0U;
        chartInstance->c10_tp_gazeMiddle = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_f_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 3.0,
          c10_dv1);
        for (c10_i1 = 0; c10_i1 < 256; c10_i1++) {
          c10_set_BML(chartInstance, c10_i1, c10_dv1[c10_i1]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c10_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateInit:
    CV_CHART_EVAL(6, 0, 7);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_l_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    guard2 = false;
    if (CV_EML_COND(6, 0, 0, *c10_gameState == c10_get_STATE_OVER(chartInstance,
          0))) {
      guard2 = true;
    } else {
      c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
      if (CV_EML_COND(6, 0, 1, *c10_gameState == c10_get_STATE_BEFORE
                      (chartInstance, 0))) {
        guard2 = true;
      } else {
        CV_EML_MCDC(6, 0, 0, false);
        CV_EML_IF(6, 0, 0, false);
        c10_c_out = false;
      }
    }

    if (guard2 == true) {
      CV_EML_MCDC(6, 0, 0, true);
      CV_EML_IF(6, 0, 0, true);
      c10_c_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c10_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_p_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      c10_d_out = CV_EML_IF(20, 0, 0, *c10_isMoving == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c10_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_q_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_i_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_i_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        c10_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c10_tp_stateInit = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateGazeLeft;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
        chartInstance->c10_temporalCounter_i1 = 0U;
        chartInstance->c10_tp_stateGazeLeft = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_h_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_j_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_j_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 2.0,
          c10_dv2);
        for (c10_i2 = 0; c10_i2 < 256; c10_i2++) {
          c10_set_BML(chartInstance, c10_i2, c10_dv2[c10_i2]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c10_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_t_debug_family_names,
          c10_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_k_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_k_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_out, 2U,
          c10_c_sf_marshallOut, c10_c_sf_marshallIn);
        c10_e_out = CV_EML_IF(19, 0, 0, *c10_isMoving == 2.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c10_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c10_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_u_debug_family_names,
            c10_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_l_nargin, 0U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_l_nargout, 1U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          c10_set_isPosing(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 4);
          c10_set_pr(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 5);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c10_tp_stateInit = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
          chartInstance->c10_isStable = false;
          chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeRight;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
          chartInstance->c10_temporalCounter_i1 = 0U;
          chartInstance->c10_tp_gazeRight = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_k_debug_family_names,
            c10_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_m_nargin, 0U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_m_nargout, 1U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 1.0,
            c10_dv3);
          for (c10_i3 = 0; c10_i3 < 256; c10_i3++) {
            c10_set_BML(chartInstance, c10_i3, c10_dv3[c10_i3]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                       chartInstance->c10_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_r_debug_family_names,
            c10_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_n_nargin, 0U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_n_nargout, 1U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_out, 2U,
            c10_c_sf_marshallOut, c10_c_sf_marshallIn);
          c10_f_out = CV_EML_IF(23, 0, 0, (chartInstance->c10_sfEvent ==
            c10_event_secs) && (chartInstance->c10_temporalCounter_i1 >= 10));
          _SFD_SYMBOL_SCOPE_POP();
          if (c10_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c10_sfEvent);
            chartInstance->c10_tp_stateInit = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
            chartInstance->c10_isStable = false;
            chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateIdleM;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
            chartInstance->c10_tp_stateIdleM = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_j_debug_family_names,
              c10_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_o_nargin, 0U,
              c10_b_sf_marshallOut, c10_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_o_nargout, 1U,
              c10_b_sf_marshallOut, c10_b_sf_marshallIn);
            c10_set_isPosing(chartInstance, 0, 0.0);
            ssUpdateDataStoreLog(chartInstance->S, 4);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            guard1 = true;
          }
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(6, 0, 0);
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
}

static void c10_exit_internal_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  switch (chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS) {
   case c10_IN_gazeMiddle:
    CV_CHART_EVAL(6, 0, 1);
    chartInstance->c10_tp_gazeMiddle = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_gazeRight:
    CV_CHART_EVAL(6, 0, 2);
    chartInstance->c10_tp_gazeRight = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateGazeLeft:
    CV_CHART_EVAL(6, 0, 3);
    chartInstance->c10_tp_stateGazeLeft = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateIdleL:
    CV_CHART_EVAL(6, 0, 4);
    chartInstance->c10_tp_stateIdleL = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateIdleM:
    CV_CHART_EVAL(6, 0, 5);
    chartInstance->c10_tp_stateIdleM = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateIdleR:
    CV_CHART_EVAL(6, 0, 6);
    chartInstance->c10_tp_stateIdleR = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateInit:
    CV_CHART_EVAL(6, 0, 7);
    chartInstance->c10_tp_stateInit = 0U;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(6, 0, 0);
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    break;
  }
}

static void c10_initc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_doSetSimStateSideEffects = 0U;
  chartInstance->c10_setSimStateSideEffectsInfo = NULL;
  chartInstance->c10_tp_gazeMiddle = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_gazeRight = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateGazeLeft = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateIdleL = 0U;
  chartInstance->c10_tp_stateIdleM = 0U;
  chartInstance->c10_tp_stateIdleR = 0U;
  chartInstance->c10_tp_stateInit = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_is_active_c10_ARP_02_RPSs_Bdr_GK_BIS = 0U;
  chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_gazeMiddle(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 1.0;
  boolean_T c10_b_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 0.0;
  real_T c10_dv4[256];
  int32_T c10_i4;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 1.0;
  boolean_T c10_c_out;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_g_nargin = 0.0;
  real_T c10_g_nargout = 0.0;
  real_T c10_dv5[256];
  int32_T c10_i5;
  real_T c10_h_nargin = 0.0;
  real_T c10_h_nargout = 1.0;
  boolean_T c10_d_out;
  real_T c10_i_nargin = 0.0;
  real_T c10_i_nargout = 0.0;
  real_T *c10_gameState;
  real_T *c10_isMoving;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_l_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
  guard2 = false;
  if (CV_EML_COND(6, 0, 0, *c10_gameState == c10_get_STATE_OVER(chartInstance, 0)))
  {
    guard2 = true;
  } else {
    c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    if (CV_EML_COND(6, 0, 1, *c10_gameState == c10_get_STATE_BEFORE
                    (chartInstance, 0))) {
      guard2 = true;
    } else {
      CV_EML_MCDC(6, 0, 0, false);
      CV_EML_IF(6, 0, 0, false);
      c10_out = false;
    }
  }

  if (guard2 == true) {
    CV_EML_MCDC(6, 0, 0, true);
    CV_EML_IF(6, 0, 0, true);
    c10_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c10_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_p_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_b_out = CV_EML_IF(20, 0, 0, *c10_isMoving == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_q_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c10_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c10_tp_gazeMiddle = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateGazeLeft;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_stateGazeLeft = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_h_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 2.0,
        c10_dv4);
      for (c10_i4 = 0; c10_i4 < 256; c10_i4++) {
        c10_set_BML(chartInstance, c10_i4, c10_dv4[c10_i4]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c10_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_t_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      c10_c_out = CV_EML_IF(19, 0, 0, *c10_isMoving == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c10_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_u_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        c10_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c10_tp_gazeMiddle = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeRight;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
        chartInstance->c10_temporalCounter_i1 = 0U;
        chartInstance->c10_tp_gazeRight = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_k_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 1.0,
          c10_dv5);
        for (c10_i5 = 0; c10_i5 < 256; c10_i5++) {
          c10_set_BML(chartInstance, c10_i5, c10_dv5[c10_i5]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                     chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_r_debug_family_names,
          c10_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_out, 2U,
          c10_c_sf_marshallOut, c10_c_sf_marshallIn);
        c10_d_out = CV_EML_IF(23, 0, 0, (chartInstance->c10_sfEvent ==
          c10_event_secs) && (chartInstance->c10_temporalCounter_i1 >= 10));
        _SFD_SYMBOL_SCOPE_POP();
        if (c10_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c10_sfEvent);
          chartInstance->c10_tp_gazeMiddle = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
          chartInstance->c10_isStable = false;
          chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateIdleM;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
          chartInstance->c10_tp_stateIdleM = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_j_debug_family_names,
            c10_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_i_nargin, 0U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_i_nargout, 1U,
            c10_b_sf_marshallOut, c10_b_sf_marshallIn);
          c10_set_isPosing(chartInstance, 0, 0.0);
          ssUpdateDataStoreLog(chartInstance->S, 4);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard1 = true;
        }
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
}

static void c10_stateIdleL(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_dv6[256];
  int32_T c10_i6;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 0.0;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_dv7[256];
  int32_T c10_i7;
  real_T *c10_isMoving;
  real_T *c10_gameState;
  boolean_T guard1 = false;
  c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_t_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  c10_out = CV_EML_IF(19, 0, 0, *c10_isMoving == 2.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c10_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_u_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    c10_set_pr(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c10_tp_stateIdleL = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeRight;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    chartInstance->c10_temporalCounter_i1 = 0U;
    chartInstance->c10_tp_gazeRight = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_k_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 1.0, c10_dv6);
    for (c10_i6 = 0; c10_i6 < 256; c10_i6++) {
      c10_set_BML(chartInstance, c10_i6, c10_dv6[c10_i6]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_m_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(18, 0, 0, *c10_isMoving == 0.0)) {
      guard1 = true;
    } else {
      c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
      if (CV_EML_COND(18, 0, 1, *c10_gameState == c10_get_STATE_READY
                      (chartInstance, 0))) {
        guard1 = true;
      } else {
        CV_EML_MCDC(18, 0, 0, false);
        CV_EML_IF(18, 0, 0, false);
        c10_b_out = false;
      }
    }

    if (guard1 == true) {
      CV_EML_MCDC(18, 0, 0, true);
      CV_EML_IF(18, 0, 0, true);
      c10_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_n_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c10_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c10_tp_stateIdleL = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeMiddle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_gazeMiddle = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_f_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 3.0,
        c10_dv7);
      for (c10_i7 = 0; c10_i7 < 256; c10_i7++) {
        c10_set_BML(chartInstance, c10_i7, c10_dv7[c10_i7]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c10_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
}

static void c10_stateGazeLeft(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_dv8[256];
  int32_T c10_i8;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 0.0;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_dv9[256];
  int32_T c10_i9;
  real_T c10_g_nargin = 0.0;
  real_T c10_g_nargout = 1.0;
  boolean_T c10_c_out;
  real_T c10_h_nargin = 0.0;
  real_T c10_h_nargout = 0.0;
  real_T *c10_isMoving;
  real_T *c10_gameState;
  boolean_T guard1 = false;
  c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_m_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(18, 0, 0, *c10_isMoving == 0.0)) {
    guard1 = true;
  } else {
    c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    if (CV_EML_COND(18, 0, 1, *c10_gameState == c10_get_STATE_READY
                    (chartInstance, 0))) {
      guard1 = true;
    } else {
      CV_EML_MCDC(18, 0, 0, false);
      CV_EML_IF(18, 0, 0, false);
      c10_out = false;
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(18, 0, 0, true);
    CV_EML_IF(18, 0, 0, true);
    c10_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c10_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_n_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    c10_set_pr(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c10_tp_stateGazeLeft = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeMiddle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    chartInstance->c10_temporalCounter_i1 = 0U;
    chartInstance->c10_tp_gazeMiddle = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_f_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 3.0, c10_dv8);
    for (c10_i8 = 0; c10_i8 < 256; c10_i8++) {
      c10_set_BML(chartInstance, c10_i8, c10_dv8[c10_i8]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_t_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_b_out = CV_EML_IF(19, 0, 0, *c10_isMoving == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_u_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c10_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c10_tp_stateGazeLeft = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeRight;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_gazeRight = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_k_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 1.0,
        c10_dv9);
      for (c10_i9 = 0; c10_i9 < 256; c10_i9++) {
        c10_set_BML(chartInstance, c10_i9, c10_dv9[c10_i9]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_o_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      c10_c_out = CV_EML_IF(15, 0, 0, (chartInstance->c10_sfEvent ==
        c10_event_secs) && (chartInstance->c10_temporalCounter_i1 >= 10));
      _SFD_SYMBOL_SCOPE_POP();
      if (c10_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_stateGazeLeft = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateIdleL;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_stateIdleL = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_g_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_set_isPosing(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c10_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
}

static void c10_stateIdleM(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_dv10[256];
  int32_T c10_i10;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 0.0;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_dv11[256];
  int32_T c10_i11;
  real_T *c10_isMoving;
  c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_p_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  c10_out = CV_EML_IF(20, 0, 0, *c10_isMoving == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c10_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_q_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    c10_set_pr(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c10_tp_stateIdleM = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateGazeLeft;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    chartInstance->c10_temporalCounter_i1 = 0U;
    chartInstance->c10_tp_stateGazeLeft = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_h_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 2.0,
      c10_dv10);
    for (c10_i10 = 0; c10_i10 < 256; c10_i10++) {
      c10_set_BML(chartInstance, c10_i10, c10_dv10[c10_i10]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_t_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_b_out = CV_EML_IF(19, 0, 0, *c10_isMoving == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_u_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c10_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c10_tp_stateIdleM = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeRight;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_gazeRight = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_k_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 1.0,
        c10_dv11);
      for (c10_i11 = 0; c10_i11 < 256; c10_i11++) {
        c10_set_BML(chartInstance, c10_i11, c10_dv11[c10_i11]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c10_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c10_sfEvent);
}

static void c10_gazeRight(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_dv12[256];
  int32_T c10_i12;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_b_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 0.0;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 0.0;
  real_T c10_dv13[256];
  int32_T c10_i13;
  real_T c10_g_nargin = 0.0;
  real_T c10_g_nargout = 1.0;
  boolean_T c10_c_out;
  real_T c10_h_nargin = 0.0;
  real_T c10_h_nargout = 0.0;
  real_T *c10_isMoving;
  real_T *c10_gameState;
  boolean_T guard1 = false;
  c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_m_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(18, 0, 0, *c10_isMoving == 0.0)) {
    guard1 = true;
  } else {
    c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    if (CV_EML_COND(18, 0, 1, *c10_gameState == c10_get_STATE_READY
                    (chartInstance, 0))) {
      guard1 = true;
    } else {
      CV_EML_MCDC(18, 0, 0, false);
      CV_EML_IF(18, 0, 0, false);
      c10_out = false;
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(18, 0, 0, true);
    CV_EML_IF(18, 0, 0, true);
    c10_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c10_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_n_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    c10_set_pr(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c10_tp_gazeRight = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_gazeMiddle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
    chartInstance->c10_temporalCounter_i1 = 0U;
    chartInstance->c10_tp_gazeMiddle = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_f_debug_family_names,
      c10_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 3.0,
      c10_dv12);
    for (c10_i12 = 0; c10_i12 < 256; c10_i12++) {
      c10_set_BML(chartInstance, c10_i12, c10_dv12[c10_i12]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_p_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_b_out = CV_EML_IF(20, 0, 0, *c10_isMoving == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_q_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      c10_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c10_tp_gazeRight = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateGazeLeft;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_stateGazeLeft = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_h_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, 2.0,
        c10_dv13);
      for (c10_i13 = 0; c10_i13 < 256; c10_i13++) {
        c10_set_BML(chartInstance, c10_i13, c10_dv13[c10_i13]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_s_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_g_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      c10_c_out = CV_EML_IF(12, 0, 0, (chartInstance->c10_sfEvent ==
        c10_event_secs) && (chartInstance->c10_temporalCounter_i1 >= 10));
      _SFD_SYMBOL_SCOPE_POP();
      if (c10_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_gazeRight = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_ARP_02_RPSs_Bdr_GK_BIS = c10_IN_stateIdleR;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_stateIdleR = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_i_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_h_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_set_isPosing(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c10_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
}

static void c10_encStr2Arr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[218];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[218];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i14;
  static char_T c10_cv0[218] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'H', 'E', 'A', 'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':',
    't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '7', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a',
    '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e', '=',
    '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"',
    'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n',
    't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i15;
  static real_T c10_dv14[218] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0,
    66.0, 65.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 55.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0,
    32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0,
    105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i16;
  int32_T c10_i17;
  int32_T c10_i18;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_b_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i14 = 0; c10_i14 < 218; c10_i14++) {
    c10_mystr[c10_i14] = c10_cv0[c10_i14];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i15 = 0; c10_i15 < 218; c10_i15++) {
    c10_arr[c10_i15] = c10_dv14[c10_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 218.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i16 = 0; c10_i16 < 256; c10_i16++) {
    c10_tt[c10_i16] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i17 = 0; c10_i17 < 218; c10_i17++) {
    c10_tt[c10_i17] = c10_arr[c10_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i18 = 0; c10_i18 < 256; c10_i18++) {
    c10_myarr256[c10_i18] = c10_tt[c10_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_b_encStr2Arr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[216];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[216];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i19;
  static char_T c10_cv1[216] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H',
    'E', 'A', 'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '7', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"',
    '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i20;
  static real_T c10_dv15[216] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 66.0,
    65.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 55.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0,
    97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0,
    114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i21;
  int32_T c10_i22;
  int32_T c10_i23;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_c_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i19 = 0; c10_i19 < 216; c10_i19++) {
    c10_mystr[c10_i19] = c10_cv1[c10_i19];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i20 = 0; c10_i20 < 216; c10_i20++) {
    c10_arr[c10_i20] = c10_dv15[c10_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 216.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i21 = 0; c10_i21 < 256; c10_i21++) {
    c10_tt[c10_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i22 = 0; c10_i22 < 216; c10_i22++) {
    c10_tt[c10_i22] = c10_arr[c10_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i23 = 0; c10_i23 < 256; c10_i23++) {
    c10_myarr256[c10_i23] = c10_tt[c10_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_c_encStr2Arr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[87];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[87];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i24;
  static char_T c10_cv2[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c10_i25;
  static real_T c10_dv16[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i26;
  int32_T c10_i27;
  int32_T c10_i28;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_d_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i24 = 0; c10_i24 < 87; c10_i24++) {
    c10_mystr[c10_i24] = c10_cv2[c10_i24];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i25 = 0; c10_i25 < 87; c10_i25++) {
    c10_arr[c10_i25] = c10_dv16[c10_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i26 = 0; c10_i26 < 256; c10_i26++) {
    c10_tt[c10_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i27 = 0; c10_i27 < 87; c10_i27++) {
    c10_tt[c10_i27] = c10_arr[c10_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i28 = 0; c10_i28 < 256; c10_i28++) {
    c10_myarr256[c10_i28] = c10_tt[c10_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, c10_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\6-7-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i29;
  real_T c10_b_inData[256];
  int32_T c10_i30;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i29 = 0; c10_i29 < 256; c10_i29++) {
    c10_b_inData[c10_i29] = (*(real_T (*)[256])c10_inData)[c10_i29];
  }

  for (c10_i30 = 0; c10_i30 < 256; c10_i30++) {
    c10_u[c10_i30] = c10_b_inData[c10_i30];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256])
{
  real_T c10_dv17[256];
  int32_T c10_i31;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv17, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c10_i31 = 0; c10_i31 < 256; c10_i31++) {
    c10_y[c10_i31] = c10_dv17[c10_i31];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_gazeBML;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[256];
  int32_T c10_i32;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_gazeBML = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_gazeBML), &c10_thisId,
                       c10_y);
  sf_mex_destroy(&c10_gazeBML);
  for (c10_i32 = 0; c10_i32 < 256; c10_i32++) {
    (*(real_T (*)[256])c10_outData)[c10_i32] = c10_y[c10_i32];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_b_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, const mxArray *c10_bmlID, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_bmlID),
    &c10_thisId);
  sf_mex_destroy(&c10_bmlID);
  return c10_y;
}

static real_T c10_c_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
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

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_bmlID;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_bmlID = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_bmlID),
    &c10_thisId);
  sf_mex_destroy(&c10_bmlID);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  boolean_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(boolean_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static boolean_T c10_d_emlrt_marshallIn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
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

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_aVarTruthTableCondition_3;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  boolean_T c10_y;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_aVarTruthTableCondition_3 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_aVarTruthTableCondition_3), &c10_thisId);
  sf_mex_destroy(&c10_aVarTruthTableCondition_3);
  *(boolean_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i33;
  real_T c10_b_inData[256];
  int32_T c10_i34;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i33 = 0; c10_i33 < 256; c10_i33++) {
    c10_b_inData[c10_i33] = (*(real_T (*)[256])c10_inData)[c10_i33];
  }

  for (c10_i34 = 0; c10_i34 < 256; c10_i34++) {
    c10_u[c10_i34] = c10_b_inData[c10_i34];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_e_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256])
{
  real_T c10_dv18[256];
  int32_T c10_i35;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv18, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c10_i35 = 0; c10_i35 < 256; c10_i35++) {
    c10_y[c10_i35] = c10_dv18[c10_i35];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_myarr256;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[256];
  int32_T c10_i36;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_myarr256 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_myarr256), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_myarr256);
  for (c10_i36 = 0; c10_i36 < 256; c10_i36++) {
    (*(real_T (*)[256])c10_outData)[c10_i36] = c10_y[c10_i36];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i37;
  char_T c10_b_inData[218];
  int32_T c10_i38;
  char_T c10_u[218];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i37 = 0; c10_i37 < 218; c10_i37++) {
    c10_b_inData[c10_i37] = (*(char_T (*)[218])c10_inData)[c10_i37];
  }

  for (c10_i38 = 0; c10_i38 < 218; c10_i38++) {
    c10_u[c10_i38] = c10_b_inData[c10_i38];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 218),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i39;
  real_T c10_b_inData[218];
  int32_T c10_i40;
  real_T c10_u[218];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i39 = 0; c10_i39 < 218; c10_i39++) {
    c10_b_inData[c10_i39] = (*(real_T (*)[218])c10_inData)[c10_i39];
  }

  for (c10_i40 = 0; c10_i40 < 218; c10_i40++) {
    c10_u[c10_i40] = c10_b_inData[c10_i40];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 218), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i41;
  char_T c10_b_inData[216];
  int32_T c10_i42;
  char_T c10_u[216];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i41 = 0; c10_i41 < 216; c10_i41++) {
    c10_b_inData[c10_i41] = (*(char_T (*)[216])c10_inData)[c10_i41];
  }

  for (c10_i42 = 0; c10_i42 < 216; c10_i42++) {
    c10_u[c10_i42] = c10_b_inData[c10_i42];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 216),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i43;
  real_T c10_b_inData[216];
  int32_T c10_i44;
  real_T c10_u[216];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i43 = 0; c10_i43 < 216; c10_i43++) {
    c10_b_inData[c10_i43] = (*(real_T (*)[216])c10_inData)[c10_i43];
  }

  for (c10_i44 = 0; c10_i44 < 216; c10_i44++) {
    c10_u[c10_i44] = c10_b_inData[c10_i44];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 216), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i45;
  char_T c10_b_inData[87];
  int32_T c10_i46;
  char_T c10_u[87];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i45 = 0; c10_i45 < 87; c10_i45++) {
    c10_b_inData[c10_i45] = (*(char_T (*)[87])c10_inData)[c10_i45];
  }

  for (c10_i46 = 0; c10_i46 < 87; c10_i46++) {
    c10_u[c10_i46] = c10_b_inData[c10_i46];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 87),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i47;
  real_T c10_b_inData[87];
  int32_T c10_i48;
  real_T c10_u[87];
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i47 = 0; c10_i47 < 87; c10_i47++) {
    c10_b_inData[c10_i47] = (*(real_T (*)[87])c10_inData)[c10_i47];
  }

  for (c10_i48 = 0; c10_i48 < 87; c10_i48++) {
    c10_u[c10_i48] = c10_b_inData[c10_i48];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

const mxArray *sf_c10_ARP_02_RPSs_Bdr_GK_BIS_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/6-7-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c10_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
}

static const mxArray *c10_emlrt_marshallOut(const char * c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c10_u)), false);
  return c10_y;
}

static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u)
{
  const mxArray *c10_y = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  return c10_y;
}

static void c10_activate_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = c10_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_deactivate_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_increment_counters_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  if (chartInstance->c10_temporalCounter_i1 < 15U) {
    chartInstance->c10_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c10_temporalCounter_i1 + 1);
  }
}

static void c10_reset_counters_secsc10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c10_ARP_02_RPSs_Bdr_GK_BIS_secs(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_activate_secsc10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c10_ARP_02_RPSs_Bdr_GK_BIS_secs
  (SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_increment_counters_secsc10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c10_ARP_02_RPSs_Bdr_GK_BIS_secs
  (SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_reset_counters_secsc10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

void sf_exported_auto_deactivate_c10_ARP_02_RPSs_Bdr_GK_BIS_secs(SimStruct
  *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_deactivate_secsc10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

boolean_T sf_exported_auto_isStablec10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c10_isStable;
}

void sf_exported_auto_duringc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_c10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

void sf_exported_auto_enterc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_enter_atomic_c10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
  c10_enter_internal_c10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

void sf_exported_auto_exitc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_exit_internal_c10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

void sf_exported_auto_gatewayc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c10_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct
  *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_initc10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *
  c10_S)
{
  const mxArray *c10_out = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_out = NULL;
  sf_mex_assign(&c10_out, sf_internal_get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
                (c10_S), false);
  return c10_out;
}

void sf_exported_auto_setSimstatec10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *c10_S,
  const mxArray *c10_in)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS(c10_S, sf_mex_dup(c10_in));
  sf_mex_destroy(&c10_in);
}

void sf_exported_auto_check_state_inconsistency_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct *c10_S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, real_T c10_bmlID,
   real_T c10_gazeBML[256])
{
  uint32_T c10_debug_family_var_map[7];
  boolean_T c10_aVarTruthTableCondition_1;
  boolean_T c10_aVarTruthTableCondition_2;
  boolean_T c10_aVarTruthTableCondition_3;
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  real_T c10_dv19[256];
  int32_T c10_i49;
  int32_T c10_i50;
  int32_T c10_i51;
  int32_T c10_i52;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_1, 0U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_2, 1U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_3, 2U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 4U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_bmlID, 5U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_gazeBML, 6U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  c10_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  c10_aVarTruthTableCondition_1 = (c10_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
  c10_aVarTruthTableCondition_2 = (c10_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 18);
  c10_aVarTruthTableCondition_3 = (c10_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 20);
  if (CV_EML_IF(0, 1, 0, c10_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 21);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 34);
    c10_encStr2Arr(chartInstance, c10_dv19);
    for (c10_i49 = 0; c10_i49 < 256; c10_i49++) {
      c10_gazeBML[c10_i49] = c10_dv19[c10_i49];
    }

    c10_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -34);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 22);
    if (CV_EML_IF(0, 1, 1, c10_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 23);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 40);
      c10_b_encStr2Arr(chartInstance, c10_dv19);
      for (c10_i50 = 0; c10_i50 < 256; c10_i50++) {
        c10_gazeBML[c10_i50] = c10_dv19[c10_i50];
      }

      c10_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -40);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 24);
      if (CV_EML_IF(0, 1, 2, c10_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 25);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 46);
        c10_c_encStr2Arr(chartInstance, c10_dv19);
        for (c10_i51 = 0; c10_i51 < 256; c10_i51++) {
          c10_gazeBML[c10_i51] = c10_dv19[c10_i51];
        }

        c10_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -46);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 27);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 46);
        c10_c_encStr2Arr(chartInstance, c10_dv19);
        for (c10_i52 = 0; c10_i52 < 256; c10_i52++) {
          c10_gazeBML[c10_i52] = c10_dv19[c10_i52];
        }

        c10_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -46);
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c10_ARP_02_RPSs_Bdr_GK_BIS_gazeFollowUserMove(SimStruct
  *c10_S, real_T c10_bmlID, real_T c10_gazeBML[256])
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS(chartInstance, c10_bmlID,
    c10_gazeBML);
}

static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int8_T c10_f_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int8_T c10_y;
  int8_T c10_i53;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i53, 1, 2, 0U, 0, 0U, 0);
  c10_y = c10_i53;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_secs;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int8_T c10_y;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_secs = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_secs),
    &c10_thisId);
  sf_mex_destroy(&c10_secs);
  *(int8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_g_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i54;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i54, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i54;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_m_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  uint8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(uint8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static uint8_T c10_h_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, const mxArray *c10_b_tp_stateInit, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_stateInit),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_stateInit);
  return c10_y;
}

static uint8_T c10_i_emlrt_marshallIn(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
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

static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_tp_stateInit;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
    chartInstanceVoid;
  c10_b_tp_stateInit = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_stateInit),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_stateInit);
  *(uint8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_j_emlrt_marshallIn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
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
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, const mxArray
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
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex)
{
  (void)chartInstance;
  c10_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c10_vectorIndex, 0, 1, 1, 0)] = true;
}

static void c10_errorIfDataNotWrittenToFcn
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex, uint32_T c10_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c10_dataNumber, c10_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c10_vectorIndex, 0, 1, 1,
    0)]);
}

static real_T c10_get_BML(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#509) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c10_BML_address)[c10_b];
}

static void c10_set_BML(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#509) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c10_BML_address)[c10_b] = c10_c;
}

static real_T *c10_access_BML(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c10_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#509) in the initialization routine of the chart.\n");
  }

  c10_c = *chartInstance->c10_BML_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c10_c;
}

static real_T c10_get_STATE_BEFORE(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c10_b);
  if (chartInstance->c10_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#508) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_STATE_BEFORE_address;
}

static void c10_set_STATE_BEFORE(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c10_b);
  if (chartInstance->c10_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#508) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_STATE_BEFORE_address = c10_c;
}

static real_T *c10_access_STATE_BEFORE
  (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c10_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#508) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_STATE_BEFORE_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c10_c;
}

static real_T c10_get_STATE_OVER(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c10_b);
  if (chartInstance->c10_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#506) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_STATE_OVER_address;
}

static void c10_set_STATE_OVER(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c10_b);
  if (chartInstance->c10_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#506) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_STATE_OVER_address = c10_c;
}

static real_T *c10_access_STATE_OVER(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *
  chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c10_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#506) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_STATE_OVER_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c10_c;
}

static real_T c10_get_STATE_READY(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c10_b);
  if (chartInstance->c10_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#505) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_STATE_READY_address;
}

static void c10_set_STATE_READY(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c10_b);
  if (chartInstance->c10_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#505) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_STATE_READY_address = c10_c;
}

static real_T *c10_access_STATE_READY(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c10_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#505) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_STATE_READY_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c10_c;
}

static real_T c10_get_isPosing(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c10_b);
  if (chartInstance->c10_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#504) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_isPosing_address;
}

static void c10_set_isPosing(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c10_b);
  if (chartInstance->c10_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#504) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_isPosing_address = c10_c;
}

static real_T *c10_access_isPosing(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c10_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#504) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_isPosing_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c10_c;
}

static real_T c10_get_pr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c10_b);
  if (chartInstance->c10_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#510) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_pr_address;
}

static void c10_set_pr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance,
  uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c10_b);
  if (chartInstance->c10_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#510) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_pr_address = c10_c;
}

static real_T *c10_access_pr(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c10_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#510) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_pr_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c10_c;
}

static void init_dsm_address_info(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c10_BML_address, &chartInstance->c10_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c10_STATE_BEFORE_address,
    &chartInstance->c10_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c10_STATE_OVER_address, &chartInstance->c10_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c10_STATE_READY_address,
    &chartInstance->c10_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c10_isPosing_address, &chartInstance->c10_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pr", (void **)
    &chartInstance->c10_pr_address, &chartInstance->c10_pr_index);
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

void sf_c10_ARP_02_RPSs_Bdr_GK_BIS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1942209225U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(129220701U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2139769508U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(406545452U);
}

mxArray *sf_c10_ARP_02_RPSs_Bdr_GK_BIS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fkoZbPCGfqaqCfvC8QAd7D");
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

mxArray *sf_c10_ARP_02_RPSs_Bdr_GK_BIS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_ARP_02_RPSs_Bdr_GK_BIS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_ARP_02_RPSs_Bdr_GK_BIS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[22],T\"gameState\",},{M[8],M[0],T\"is_active_c10_ARP_02_RPSs_Bdr_GK_BIS\",},{M[9],M[0],T\"is_c10_ARP_02_RPSs_Bdr_GK_BIS\",},{M[11],M[28],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x4[20 19 18 21],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_ARP_02_RPSs_Bdr_GK_BIS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
           10,
           8,
           24,
           0,
           10,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSs_Bdr_GK_BISMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(2,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(3,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(4,1,1,0,"isMoving");
          _SFD_SET_DATA_PROPS(5,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(6,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(7,11,0,0,"pr");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(7);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,2);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_CH_SUBSTATE_INDEX(4,5);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_CH_SUBSTATE_INDEX(6,7);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(7,1,0,0);

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
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"gazeFollowUserMovec10_ARP_02_RPSs_Bdr_GK_BIS",
                             0,-1,551);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",551,-1,843);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",843,-1,1132);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1132,-1,1290);
        _SFD_CV_INIT_EML_IF(0,1,0,310,340,371,549);
        _SFD_CV_INIT_EML_IF(0,1,1,371,405,436,549);
        _SFD_CV_INIT_EML_IF(0,1,2,436,470,501,549);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,55,1,48);

        {
          static int condStart[] = { 2, 29 };

          static int condEnd[] = { 25, 54 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,55,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(18,0,0,1,44,1,44);

        {
          static int condStart[] = { 2, 19 };

          static int condEnd[] = { 15, 43 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(18,0,0,1,44,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,12,1,12);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));

        {
          real_T *c10_gameState;
          real_T *c10_isMoving;
          c10_isMoving = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c10_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c10_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c10_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c10_isMoving);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c10_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c10_BML_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c10_pr_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSs_Bdr_GK_BISMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "MnI4wDF5KLBdkfpzZ1d5pG";
}

static void sf_opaque_initialize_c10_ARP_02_RPSs_Bdr_GK_BIS(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
  initialize_c10_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  enable_c10_ARP_02_RPSs_Bdr_GK_BIS((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  disable_c10_ARP_02_RPSs_Bdr_GK_BIS((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_ARP_02_RPSs_Bdr_GK_BIS(void *chartInstanceVar)
{
  sf_gateway_c10_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_ARP_02_RPSs_Bdr_GK_BIS();/* state var info */
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

extern void sf_internal_set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c10_ARP_02_RPSs_Bdr_GK_BIS();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c10_ARP_02_RPSs_Bdr_GK_BIS(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSs_Bdr_GK_BIS_optimization_info();
    }

    finalize_c10_ARP_02_RPSs_Bdr_GK_BIS
      ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_ARP_02_RPSs_Bdr_GK_BIS
    ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
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
    initialize_params_c10_ARP_02_RPSs_Bdr_GK_BIS
      ((SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSs_Bdr_GK_BIS_optimization_info();
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
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2578274418U));
  ssSetChecksum1(S,(3205248514U));
  ssSetChecksum2(S,(1695245909U));
  ssSetChecksum3(S,(3606039500U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c10_ARP_02_RPSs_Bdr_GK_BIS(SimStruct *S)
{
  SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct *)utMalloc(sizeof
    (SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_ARP_02_RPSs_Bdr_GK_BISInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_ARP_02_RPSs_Bdr_GK_BIS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_ARP_02_RPSs_Bdr_GK_BIS;
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

void c10_ARP_02_RPSs_Bdr_GK_BIS_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_ARP_02_RPSs_Bdr_GK_BIS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_ARP_02_RPSs_Bdr_GK_BIS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_ARP_02_RPSs_Bdr_GK_BIS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_ARP_02_RPSs_Bdr_GK_BIS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
