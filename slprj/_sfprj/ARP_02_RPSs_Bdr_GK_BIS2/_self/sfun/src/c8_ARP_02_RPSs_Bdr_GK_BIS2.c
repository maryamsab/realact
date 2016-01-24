/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSs_Bdr_GK_BIS2_sfun.h"
#include "c8_ARP_02_RPSs_Bdr_GK_BIS2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSs_Bdr_GK_BIS2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c8_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c8_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c8_IN_idle                     ((uint8_T)1U)
#define c8_IN_stateHeadNeutral         ((uint8_T)2U)
#define c8_IN_stateInit                ((uint8_T)3U)
#define c8_IN_stateWalkBack            ((uint8_T)4U)
#define c8_IN_walkFW                   ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c8_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c8_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void enable_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void disable_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_st);
static void c8_set_sim_state_side_effects_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void finalize_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void sf_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_enter_atomic_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_enter_internal_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_exit_internal_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_initc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void initSimStructsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_stateInit(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance);
static void c8_idle(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_stateHeadNeutral(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance);
static void c8_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_b_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void c8_c_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, real_T c8_myarr256[256]);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_b_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_bmlID, const char_T *c8_identifier);
static real_T c8_c_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static boolean_T c8_d_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_e_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u);
static void c8_activate_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_deactivate_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_increment_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_reset_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance);
static void c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, real_T c8_bmlID,
   real_T c8_poseBML[256]);
static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int8_T c8_f_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_g_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint8_T c8_h_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, const mxArray *c8_b_tp_stateInit, const char_T *c8_identifier);
static uint8_T c8_i_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_j_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_b_setSimStateSideEffectsInfo, const char_T *c8_identifier);
static const mxArray *c8_k_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_updateDataWrittenToVector
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex);
static void c8_errorIfDataNotWrittenToFcn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex, uint32_T c8_dataNumber);
static real_T c8_get_BML(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_BML(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c);
static real_T *c8_access_BML(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static real_T c8_get_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, uint32_T c8_b);
static real_T c8_get_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static void c8_set_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance,
                      uint32_T c8_b, real_T c8_c);
static real_T *c8_access_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b);
static void init_dsm_address_info(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_update_debugger_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  uint32_T c8_prevAniVal;
  c8_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_stateWalkBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_stateHeadNeutral)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_walkFW) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  }

  _SFD_SET_ANIMATION(c8_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_c_hoistedGlobal;
  uint8_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  uint8_T c8_d_hoistedGlobal;
  uint8_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(4, 1), false);
  c8_hoistedGlobal = *c8_gameState;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = chartInstance->c8_temporalCounter_i1;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  *c8_gameState = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 0)), "gameState");
  chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2");
  chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
     "is_c8_ARP_02_RPSs_Bdr_GK_BIS2");
  chartInstance->c8_temporalCounter_i1 = c8_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 3)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 4)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_idle) {
      chartInstance->c8_tp_idle = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_idle = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 ==
        c8_IN_stateHeadNeutral) {
      chartInstance->c8_tp_stateHeadNeutral = 1U;
    } else {
      chartInstance->c8_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_stateInit) {
      chartInstance->c8_tp_stateInit = 1U;
    } else {
      chartInstance->c8_tp_stateInit = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_stateWalkBack)
    {
      chartInstance->c8_tp_stateWalkBack = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateWalkBack = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 == c8_IN_walkFW) {
      chartInstance->c8_tp_walkFW = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_walkFW = 0U;
    }

    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  c8_set_sim_state_side_effects_c8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

static void c8_enter_atomic_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
}

static void c8_enter_internal_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_f_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  *c8_gameState = c8_get_STATE_BEFORE(chartInstance, 0);
  c8_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 0.0;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_dv0[256];
  int32_T c8_i0;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 0.0;
  real_T c8_g_nargin = 0.0;
  real_T c8_g_nargout = 0.0;
  real_T c8_dv1[256];
  int32_T c8_i1;
  real_T c8_h_nargin = 0.0;
  real_T c8_h_nargout = 1.0;
  boolean_T c8_d_out;
  real_T c8_i_nargin = 0.0;
  real_T c8_i_nargout = 1.0;
  boolean_T c8_e_out;
  real_T c8_j_nargin = 0.0;
  real_T c8_j_nargout = 0.0;
  real_T c8_k_nargin = 0.0;
  real_T c8_k_nargout = 0.0;
  real_T c8_dv2[256];
  int32_T c8_i2;
  real_T c8_l_nargin = 0.0;
  real_T c8_l_nargout = 1.0;
  boolean_T c8_f_out;
  real_T c8_m_nargin = 0.0;
  real_T c8_m_nargout = 0.0;
  real_T c8_n_nargin = 0.0;
  real_T c8_n_nargout = 0.0;
  real_T c8_dv3[256];
  int32_T c8_i3;
  real_T *c8_isInvading;
  real_T *c8_gameState;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c8_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_isStable = true;
  switch (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2) {
   case c8_IN_idle:
    CV_CHART_EVAL(4, 0, 1);
    c8_idle(chartInstance);
    break;

   case c8_IN_stateHeadNeutral:
    CV_CHART_EVAL(4, 0, 2);
    c8_stateHeadNeutral(chartInstance);
    break;

   case c8_IN_stateInit:
    CV_CHART_EVAL(4, 0, 3);
    c8_stateInit(chartInstance);
    break;

   case c8_IN_stateWalkBack:
    CV_CHART_EVAL(4, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_t_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_out = CV_EML_IF(8, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                       (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    guard3 = false;
    if (c8_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_r_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_b_out = CV_EML_IF(7, 0, 0, *c8_isInvading == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_s_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c8_tp_stateWalkBack = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_walkFW;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_walkFW = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_j_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 3.0,
          c8_dv0);
        for (c8_i0 = 0; c8_i0 < 256; c8_i0++) {
          c8_set_BML(chartInstance, c8_i0, c8_dv0[c8_i0]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_p_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
          c8_c_sf_marshallIn);
        guard4 = false;
        if (CV_EML_COND(6, 0, 0, *c8_isInvading == 0.0)) {
          guard4 = true;
        } else {
          c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
          if (CV_EML_COND(6, 0, 1, *c8_gameState == c8_get_STATE_READY
                          (chartInstance, 0))) {
            guard4 = true;
          } else {
            CV_EML_MCDC(6, 0, 0, false);
            CV_EML_IF(6, 0, 0, false);
            c8_c_out = false;
          }
        }

        if (guard4 == true) {
          CV_EML_MCDC(6, 0, 0, true);
          CV_EML_IF(6, 0, 0, true);
          c8_c_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c8_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_q_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_set_pr(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 4);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c8_tp_stateWalkBack = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
          chartInstance->c8_temporalCounter_i1 = 0U;
          chartInstance->c8_tp_idle = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_g_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 1.0,
            c8_dv1);
          for (c8_i1 = 0; c8_i1 < 256; c8_i1++) {
            c8_set_BML(chartInstance, c8_i1, c8_dv1[c8_i1]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard3 = true;
        }
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_walkFW:
    CV_CHART_EVAL(4, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_fb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_d_out = CV_EML_IF(15, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c8_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_bb_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_e_out = CV_EML_IF(12, 0, 0, *c8_isInvading == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_cb_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c8_tp_walkFW = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_stateWalkBack;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_stateWalkBack = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_h_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_k_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_k_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 2.0,
          c8_dv2);
        for (c8_i2 = 0; c8_i2 < 256; c8_i2++) {
          c8_set_BML(chartInstance, c8_i2, c8_dv2[c8_i2]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_n_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_l_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_l_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_out, 2U, c8_c_sf_marshallOut,
          c8_c_sf_marshallIn);
        guard2 = false;
        if (CV_EML_COND(5, 0, 0, *c8_isInvading == 0.0)) {
          guard2 = true;
        } else {
          c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
          if (CV_EML_COND(5, 0, 1, *c8_gameState == c8_get_STATE_READY
                          (chartInstance, 0))) {
            guard2 = true;
          } else {
            CV_EML_MCDC(5, 0, 0, false);
            CV_EML_IF(5, 0, 0, false);
            c8_f_out = false;
          }
        }

        if (guard2 == true) {
          CV_EML_MCDC(5, 0, 0, true);
          CV_EML_IF(5, 0, 0, true);
          c8_f_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c8_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_o_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_m_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_m_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_set_pr(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 4);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c8_tp_walkFW = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
          chartInstance->c8_temporalCounter_i1 = 0U;
          chartInstance->c8_tp_idle = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_g_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_n_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_n_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 1.0,
            c8_dv3);
          for (c8_i3 = 0; c8_i3 < 256; c8_i3++) {
            c8_set_BML(chartInstance, c8_i3, c8_dv3[c8_i3]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
}

static void c8_exit_internal_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  switch (chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2) {
   case c8_IN_idle:
    CV_CHART_EVAL(4, 0, 1);
    chartInstance->c8_tp_idle = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateHeadNeutral:
    CV_CHART_EVAL(4, 0, 2);
    chartInstance->c8_tp_stateHeadNeutral = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateInit:
    CV_CHART_EVAL(4, 0, 3);
    chartInstance->c8_tp_stateInit = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateWalkBack:
    CV_CHART_EVAL(4, 0, 4);
    chartInstance->c8_tp_stateWalkBack = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_walkFW:
    CV_CHART_EVAL(4, 0, 5);
    chartInstance->c8_tp_walkFW = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }
}

static void c8_initc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_tp_idle = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateHeadNeutral = 0U;
  chartInstance->c8_tp_stateInit = 0U;
  chartInstance->c8_tp_stateWalkBack = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_walkFW = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2 = 0U;
  chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_stateInit(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 0.0;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_dv4[256];
  int32_T c8_i4;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 0.0;
  real_T c8_g_nargin = 0.0;
  real_T c8_g_nargout = 0.0;
  real_T c8_dv5[256];
  int32_T c8_i5;
  real_T c8_h_nargin = 0.0;
  real_T c8_h_nargout = 1.0;
  boolean_T c8_d_out;
  real_T c8_i_nargin = 0.0;
  real_T c8_i_nargout = 0.0;
  real_T c8_j_nargin = 0.0;
  real_T c8_j_nargout = 0.0;
  real_T c8_dv6[256];
  int32_T c8_i6;
  real_T *c8_gameState;
  real_T *c8_isInvading;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c8_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_l_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
  guard2 = false;
  if (CV_EML_COND(3, 0, 0, *c8_gameState == c8_get_STATE_OVER(chartInstance, 0)))
  {
    guard2 = true;
  } else {
    c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    if (CV_EML_COND(3, 0, 1, *c8_gameState == c8_get_STATE_BEFORE(chartInstance,
          0))) {
      guard2 = true;
    } else {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c8_out = false;
    }
  }

  if (guard2 == true) {
    CV_EML_MCDC(3, 0, 0, true);
    CV_EML_IF(3, 0, 0, true);
    c8_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_w_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(10, 0, 0, *c8_isInvading == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_x_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_set_pr(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 4);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c8_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_i_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 4.0, c8_dv4);
      for (c8_i4 = 0; c8_i4 < 256; c8_i4++) {
        c8_set_BML(chartInstance, c8_i4, c8_dv4[c8_i4]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_y_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_c_out = CV_EML_IF(11, 0, 0, *c8_isInvading == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ab_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c8_tp_stateInit = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_stateHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateHeadNeutral = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_i_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 4.0,
          c8_dv5);
        for (c8_i5 = 0; c8_i5 < 256; c8_i5++) {
          c8_set_BML(chartInstance, c8_i5, c8_dv5[c8_i5]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_u_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_c_sf_marshallOut,
          c8_c_sf_marshallIn);
        c8_d_out = CV_EML_IF(9, 0, 0, *c8_isInvading == 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c8_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_v_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_set_pr(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 4);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c8_tp_stateInit = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 =
            c8_IN_stateHeadNeutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_stateHeadNeutral = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_i_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 4.0,
            c8_dv6);
          for (c8_i6 = 0; c8_i6 < 256; c8_i6++) {
            c8_set_BML(chartInstance, c8_i6, c8_dv6[c8_i6]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
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
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c8_sfEvent);
}

static void c8_idle(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_c_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 0.0;
  real_T c8_dv7[256];
  int32_T c8_i7;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 1.0;
  boolean_T c8_d_out;
  real_T c8_g_nargin = 0.0;
  real_T c8_g_nargout = 0.0;
  real_T c8_h_nargin = 0.0;
  real_T c8_h_nargout = 0.0;
  real_T c8_dv8[256];
  int32_T c8_i8;
  real_T c8_i_nargin = 0.0;
  real_T c8_i_nargout = 1.0;
  boolean_T c8_e_out;
  real_T c8_j_nargin = 0.0;
  real_T c8_j_nargout = 0.0;
  real_T c8_k_nargin = 0.0;
  real_T c8_k_nargout = 0.0;
  real_T c8_dv9[256];
  int32_T c8_i9;
  real_T *c8_gameState;
  real_T *c8_isInvading;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c8_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_k_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(2, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 2));
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_l_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    guard2 = false;
    if (CV_EML_COND(3, 0, 0, *c8_gameState == c8_get_STATE_OVER(chartInstance, 0)))
    {
      guard2 = true;
    } else {
      c8_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
      if (CV_EML_COND(3, 0, 1, *c8_gameState == c8_get_STATE_BEFORE
                      (chartInstance, 0))) {
        guard2 = true;
      } else {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c8_b_out = false;
      }
    }

    if (guard2 == true) {
      CV_EML_MCDC(3, 0, 0, true);
      CV_EML_IF(3, 0, 0, true);
      c8_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_w_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_c_out = CV_EML_IF(10, 0, 0, *c8_isInvading == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_x_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_set_pr(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c8_tp_idle = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_stateHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateHeadNeutral = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_i_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 4.0,
          c8_dv7);
        for (c8_i7 = 0; c8_i7 < 256; c8_i7++) {
          c8_set_BML(chartInstance, c8_i7, c8_dv7[c8_i7]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c8_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_y_debug_family_names,
          c8_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_c_sf_marshallOut,
          c8_c_sf_marshallIn);
        c8_d_out = CV_EML_IF(11, 0, 0, *c8_isInvading == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c8_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ab_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_set_pr(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 4);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c8_tp_idle = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
          chartInstance->c8_isStable = false;
          chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 =
            c8_IN_stateHeadNeutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
          chartInstance->c8_tp_stateHeadNeutral = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_i_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 4.0,
            c8_dv8);
          for (c8_i8 = 0; c8_i8 < 256; c8_i8++) {
            c8_set_BML(chartInstance, c8_i8, c8_dv8[c8_i8]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                       chartInstance->c8_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_u_debug_family_names,
            c8_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargin, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_i_nargout, 1U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_out, 2U,
            c8_c_sf_marshallOut, c8_c_sf_marshallIn);
          c8_e_out = CV_EML_IF(9, 0, 0, *c8_isInvading == 0.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c8_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_v_debug_family_names,
              c8_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargin, 0U,
              c8_b_sf_marshallOut, c8_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_j_nargout, 1U,
              c8_b_sf_marshallOut, c8_b_sf_marshallIn);
            c8_set_pr(chartInstance, 0, 1.0);
            ssUpdateDataStoreLog(chartInstance->S, 4);
            _SFD_SYMBOL_SCOPE_POP();
            chartInstance->c8_tp_idle = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
            chartInstance->c8_isStable = false;
            chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 =
              c8_IN_stateHeadNeutral;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
            chartInstance->c8_tp_stateHeadNeutral = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_i_debug_family_names,
              c8_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_k_nargin, 0U,
              c8_b_sf_marshallOut, c8_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_k_nargout, 1U,
              c8_b_sf_marshallOut, c8_b_sf_marshallIn);
            c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 4.0,
              c8_dv9);
            for (c8_i9 = 0; c8_i9 < 256; c8_i9++) {
              c8_set_BML(chartInstance, c8_i9, c8_dv9[c8_i9]);
            }

            ssUpdateDataStoreLog(chartInstance->S, 0);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            guard1 = true;
          }
        }
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
}

static void c8_stateHeadNeutral(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_dv10[256];
  int32_T c8_i10;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_dv11[256];
  int32_T c8_i11;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 0.0;
  real_T c8_dv12[256];
  int32_T c8_i12;
  real_T *c8_isInvading;
  c8_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_db_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(13, 0, 0, *c8_isInvading == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateHeadNeutral = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_stateWalkBack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_stateWalkBack = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_h_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 2.0, c8_dv10);
    for (c8_i10 = 0; c8_i10 < 256; c8_i10++) {
      c8_set_BML(chartInstance, c8_i10, c8_dv10[c8_i10]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_eb_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(14, 0, 0, *c8_isInvading == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_walkFW;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_walkFW = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_j_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 3.0, c8_dv11);
      for (c8_i11 = 0; c8_i11 < 256; c8_i11++) {
        c8_set_BML(chartInstance, c8_i11, c8_dv11[c8_i11]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_m_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_c_out = CV_EML_IF(4, 0, 0, *c8_isInvading == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateHeadNeutral = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSs_Bdr_GK_BIS2 = c8_IN_idle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_idle = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_g_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, 1.0,
          c8_dv12);
        for (c8_i12 = 0; c8_i12 < 256; c8_i12++) {
          c8_set_BML(chartInstance, c8_i12, c8_dv12[c8_i12]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c8_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
}

static void c8_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[137];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[137];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i13;
  static char_T c8_cv0[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i14;
  static real_T c8_dv13[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_b_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i13 = 0; c8_i13 < 137; c8_i13++) {
    c8_mystr[c8_i13] = c8_cv0[c8_i13];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i14 = 0; c8_i14 < 137; c8_i14++) {
    c8_arr[c8_i14] = c8_dv13[c8_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i15 = 0; c8_i15 < 256; c8_i15++) {
    c8_tt[c8_i15] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i16 = 0; c8_i16 < 137; c8_i16++) {
    c8_tt[c8_i16] = c8_arr[c8_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i17 = 0; c8_i17 < 256; c8_i17++) {
    c8_myarr256[c8_i17] = c8_tt[c8_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_b_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[140];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[140];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i18;
  static char_T c8_cv1[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=', '\"',
    '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't', 'a',
    'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 'f', 'a', 'c', 'i', 'n',
    'g', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '-', '0', '.', '6', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i19;
  static real_T c8_dv14[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 32.0, 115.0, 98.0, 109.0, 58.0, 97.0, 99.0,
    99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0, 99.0, 99.0, 101.0,
    108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0,
    103.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 45.0, 48.0, 46.0,
    54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_c_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i18 = 0; c8_i18 < 140; c8_i18++) {
    c8_mystr[c8_i18] = c8_cv1[c8_i18];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i19 = 0; c8_i19 < 140; c8_i19++) {
    c8_arr[c8_i19] = c8_dv14[c8_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i20 = 0; c8_i20 < 256; c8_i20++) {
    c8_tt[c8_i20] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i21 = 0; c8_i21 < 140; c8_i21++) {
    c8_tt[c8_i21] = c8_arr[c8_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i22 = 0; c8_i22 < 256; c8_i22++) {
    c8_myarr256[c8_i22] = c8_tt[c8_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c_encStr2Arr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[139];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[139];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i23;
  static char_T c8_cv2[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', '0', ' ', '0', '.', '6', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i24;
  static real_T c8_dv15[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 46.0, 54.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_d_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i23 = 0; c8_i23 < 139; c8_i23++) {
    c8_mystr[c8_i23] = c8_cv2[c8_i23];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i24 = 0; c8_i24 < 139; c8_i24++) {
    c8_arr[c8_i24] = c8_dv15[c8_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i25 = 0; c8_i25 < 256; c8_i25++) {
    c8_tt[c8_i25] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i26 = 0; c8_i26 < 139; c8_i26++) {
    c8_tt[c8_i26] = c8_arr[c8_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i27 = 0; c8_i27 < 256; c8_i27++) {
    c8_myarr256[c8_i27] = c8_tt[c8_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, c8_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\6-7-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i28;
  real_T c8_b_inData[256];
  int32_T c8_i29;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i28 = 0; c8_i28 < 256; c8_i28++) {
    c8_b_inData[c8_i28] = (*(real_T (*)[256])c8_inData)[c8_i28];
  }

  for (c8_i29 = 0; c8_i29 < 256; c8_i29++) {
    c8_u[c8_i29] = c8_b_inData[c8_i29];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256])
{
  real_T c8_dv16[256];
  int32_T c8_i30;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv16, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c8_i30 = 0; c8_i30 < 256; c8_i30++) {
    c8_y[c8_i30] = c8_dv16[c8_i30];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_poseBML;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i31;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_poseBML = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_poseBML), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_poseBML);
  for (c8_i31 = 0; c8_i31 < 256; c8_i31++) {
    (*(real_T (*)[256])c8_outData)[c8_i31] = c8_y[c8_i31];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_b_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_bmlID, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_bmlID), &c8_thisId);
  sf_mex_destroy(&c8_bmlID);
  return c8_y;
}

static real_T c8_c_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_bmlID;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_bmlID = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_bmlID), &c8_thisId);
  sf_mex_destroy(&c8_bmlID);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  boolean_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(boolean_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static boolean_T c8_d_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_y;
  boolean_T c8_b0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b0, 1, 11, 0U, 0, 0U, 0);
  c8_y = c8_b0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_aVarTruthTableCondition_4;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  boolean_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_aVarTruthTableCondition_4 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_aVarTruthTableCondition_4), &c8_thisId);
  sf_mex_destroy(&c8_aVarTruthTableCondition_4);
  *(boolean_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i32;
  real_T c8_b_inData[256];
  int32_T c8_i33;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i32 = 0; c8_i32 < 256; c8_i32++) {
    c8_b_inData[c8_i32] = (*(real_T (*)[256])c8_inData)[c8_i32];
  }

  for (c8_i33 = 0; c8_i33 < 256; c8_i33++) {
    c8_u[c8_i33] = c8_b_inData[c8_i33];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[256])
{
  real_T c8_dv17[256];
  int32_T c8_i34;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv17, 1, 0, 0U, 1, 0U, 1, 256);
  for (c8_i34 = 0; c8_i34 < 256; c8_i34++) {
    c8_y[c8_i34] = c8_dv17[c8_i34];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_myarr256;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i35;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_myarr256 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_myarr256), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_myarr256);
  for (c8_i35 = 0; c8_i35 < 256; c8_i35++) {
    (*(real_T (*)[256])c8_outData)[c8_i35] = c8_y[c8_i35];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i36;
  char_T c8_b_inData[137];
  int32_T c8_i37;
  char_T c8_u[137];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i36 = 0; c8_i36 < 137; c8_i36++) {
    c8_b_inData[c8_i36] = (*(char_T (*)[137])c8_inData)[c8_i36];
  }

  for (c8_i37 = 0; c8_i37 < 137; c8_i37++) {
    c8_u[c8_i37] = c8_b_inData[c8_i37];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i38;
  real_T c8_b_inData[137];
  int32_T c8_i39;
  real_T c8_u[137];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i38 = 0; c8_i38 < 137; c8_i38++) {
    c8_b_inData[c8_i38] = (*(real_T (*)[137])c8_inData)[c8_i38];
  }

  for (c8_i39 = 0; c8_i39 < 137; c8_i39++) {
    c8_u[c8_i39] = c8_b_inData[c8_i39];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i40;
  char_T c8_b_inData[140];
  int32_T c8_i41;
  char_T c8_u[140];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i40 = 0; c8_i40 < 140; c8_i40++) {
    c8_b_inData[c8_i40] = (*(char_T (*)[140])c8_inData)[c8_i40];
  }

  for (c8_i41 = 0; c8_i41 < 140; c8_i41++) {
    c8_u[c8_i41] = c8_b_inData[c8_i41];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i42;
  real_T c8_b_inData[140];
  int32_T c8_i43;
  real_T c8_u[140];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i42 = 0; c8_i42 < 140; c8_i42++) {
    c8_b_inData[c8_i42] = (*(real_T (*)[140])c8_inData)[c8_i42];
  }

  for (c8_i43 = 0; c8_i43 < 140; c8_i43++) {
    c8_u[c8_i43] = c8_b_inData[c8_i43];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i44;
  char_T c8_b_inData[139];
  int32_T c8_i45;
  char_T c8_u[139];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i44 = 0; c8_i44 < 139; c8_i44++) {
    c8_b_inData[c8_i44] = (*(char_T (*)[139])c8_inData)[c8_i44];
  }

  for (c8_i45 = 0; c8_i45 < 139; c8_i45++) {
    c8_u[c8_i45] = c8_b_inData[c8_i45];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i46;
  real_T c8_b_inData[139];
  int32_T c8_i47;
  real_T c8_u[139];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i46 = 0; c8_i46 < 139; c8_i46++) {
    c8_b_inData[c8_i46] = (*(real_T (*)[139])c8_inData)[c8_i46];
  }

  for (c8_i47 = 0; c8_i47 < 139; c8_i47++) {
    c8_u[c8_i47] = c8_b_inData[c8_i47];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i48;
  char_T c8_b_inData[115];
  int32_T c8_i49;
  char_T c8_u[115];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i48 = 0; c8_i48 < 115; c8_i48++) {
    c8_b_inData[c8_i48] = (*(char_T (*)[115])c8_inData)[c8_i48];
  }

  for (c8_i49 = 0; c8_i49 < 115; c8_i49++) {
    c8_u[c8_i49] = c8_b_inData[c8_i49];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i50;
  real_T c8_b_inData[115];
  int32_T c8_i51;
  real_T c8_u[115];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i50 = 0; c8_i50 < 115; c8_i50++) {
    c8_b_inData[c8_i50] = (*(real_T (*)[115])c8_inData)[c8_i50];
  }

  for (c8_i51 = 0; c8_i51 < 115; c8_i51++) {
    c8_u[c8_i51] = c8_b_inData[c8_i51];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

const mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c8_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/6-7-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
}

static const mxArray *c8_emlrt_marshallOut(const char * c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_u)), false);
  return c8_y;
}

static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 7, 0U, 0U, 0U, 0), false);
  return c8_y;
}

static void c8_activate_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = c8_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_deactivate_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_increment_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  if (chartInstance->c8_temporalCounter_i1 < 3U) {
    chartInstance->c8_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c8_temporalCounter_i1 + 1);
  }
}

static void c8_reset_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c8_ARP_02_RPSs_Bdr_GK_BIS2_secs(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_activate_secsc8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS2_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_increment_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c8_ARP_02_RPSs_Bdr_GK_BIS2_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_reset_counters_secsc8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

void sf_exported_auto_deactivate_c8_ARP_02_RPSs_Bdr_GK_BIS2_secs(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_deactivate_secsc8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

boolean_T sf_exported_auto_isStablec8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c8_isStable;
}

void sf_exported_auto_duringc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_c8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

void sf_exported_auto_enterc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_enter_atomic_c8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
  c8_enter_internal_c8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

void sf_exported_auto_exitc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_exit_internal_c8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

void sf_exported_auto_gatewayc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  chartInstance->c8_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct
  *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct
  *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_initc8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *
  c8_S)
{
  const mxArray *c8_out = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_out = NULL;
  sf_mex_assign(&c8_out, sf_internal_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
                (c8_S), false);
  return c8_out;
}

void sf_exported_auto_setSimstatec8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *c8_S,
  const mxArray *c8_in)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2(c8_S, sf_mex_dup(c8_in));
  sf_mex_destroy(&c8_in);
}

void sf_exported_auto_check_state_inconsistency_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, real_T c8_bmlID,
   real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[8];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  boolean_T c8_aVarTruthTableCondition_3;
  boolean_T c8_aVarTruthTableCondition_4;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv18[256];
  int32_T c8_i52;
  int32_T c8_i53;
  int32_T c8_i54;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[115];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[115];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i55;
  static char_T c8_cv3[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i56;
  static real_T c8_dv19[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c8_i57;
  int32_T c8_i58;
  int32_T c8_i59;
  int32_T c8_i60;
  int32_T c8_i61;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_4, 3U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 6);
  c8_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 11);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 15);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 19);
  c8_aVarTruthTableCondition_3 = (c8_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 23);
  c8_aVarTruthTableCondition_4 = (c8_bmlID == 4.0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 25);
  if (CV_EML_IF(5, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 26);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 41);
    c8_encStr2Arr(chartInstance, c8_dv18);
    for (c8_i52 = 0; c8_i52 < 256; c8_i52++) {
      c8_poseBML[c8_i52] = c8_dv18[c8_i52];
    }

    c8_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -41);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 27);
    if (CV_EML_IF(5, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 28);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 47);
      c8_b_encStr2Arr(chartInstance, c8_dv18);
      for (c8_i53 = 0; c8_i53 < 256; c8_i53++) {
        c8_poseBML[c8_i53] = c8_dv18[c8_i53];
      }

      c8_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -47);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 29);
      if (CV_EML_IF(5, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 30);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 53);
        c8_c_encStr2Arr(chartInstance, c8_dv18);
        for (c8_i54 = 0; c8_i54 < 256; c8_i54++) {
          c8_poseBML[c8_i54] = c8_dv18[c8_i54];
        }

        c8_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -53);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 31);
        if (CV_EML_IF(5, 1, 3, c8_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 32);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 59);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_e_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_l_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
            c8_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_k_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U,
            c8_d_sf_marshallOut, c8_d_sf_marshallIn);
          for (c8_i55 = 0; c8_i55 < 115; c8_i55++) {
            c8_mystr[c8_i55] = c8_cv3[c8_i55];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
          c8_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
          for (c8_i56 = 0; c8_i56 < 115; c8_i56++) {
            c8_arr[c8_i56] = c8_dv19[c8_i56];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
          c8_ss = 115.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
          c8_padsize = c8_maxarrsize - c8_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
          for (c8_i57 = 0; c8_i57 < 256; c8_i57++) {
            c8_tt[c8_i57] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
          for (c8_i58 = 0; c8_i58 < 115; c8_i58++) {
            c8_tt[c8_i58] = c8_arr[c8_i58];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
          for (c8_i59 = 0; c8_i59 < 256; c8_i59++) {
            c8_myarr256[c8_i59] = c8_tt[c8_i59];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c8_i60 = 0; c8_i60 < 256; c8_i60++) {
            c8_poseBML[c8_i60] = c8_myarr256[c8_i60];
          }

          c8_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -59);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 34);
          CV_EML_FCN(5, 1);
          _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 41);
          c8_encStr2Arr(chartInstance, c8_dv18);
          for (c8_i61 = 0; c8_i61 < 256; c8_i61++) {
            c8_poseBML[c8_i61] = c8_dv18[c8_i61];
          }

          c8_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c8_ARP_02_RPSs_Bdr_GK_BIS2_walkInvadingTable(SimStruct
  *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2(chartInstance, c8_bmlID,
    c8_poseBML);
}

static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int8_T c8_f_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int8_T c8_y;
  int8_T c8_i62;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i62, 1, 2, 0U, 0, 0U, 0);
  c8_y = c8_i62;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_secs;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int8_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_secs = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_secs), &c8_thisId);
  sf_mex_destroy(&c8_secs);
  *(int8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_g_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i63;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i63, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i63;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint8_T c8_h_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, const mxArray *c8_b_tp_stateInit, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateInit),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateInit);
  return c8_y;
}

static uint8_T c8_i_emlrt_marshallIn(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_tp_stateInit;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
    chartInstanceVoid;
  c8_b_tp_stateInit = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateInit),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateInit);
  *(uint8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_j_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_b_setSimStateSideEffectsInfo, const char_T *c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  sf_mex_assign(&c8_y, c8_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_k_emlrt_marshallIn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_updateDataWrittenToVector
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex)
{
  (void)chartInstance;
  c8_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c8_vectorIndex, 0, 1, 1, 0)] = true;
}

static void c8_errorIfDataNotWrittenToFcn
  (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance, uint32_T
   c8_vectorIndex, uint32_T c8_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c8_dataNumber, c8_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c8_vectorIndex, 0, 1, 1,
    0)]);
}

static real_T c8_get_BML(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1649) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c8_BML_address)[c8_b];
}

static void c8_set_BML(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance,
  uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1649) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c8_BML_address)[c8_b] = c8_c;
}

static real_T *c8_access_BML(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c8_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1649) in the initialization routine of the chart.\n");
  }

  c8_c = *chartInstance->c8_BML_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1648) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_BEFORE_address;
}

static void c8_set_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1648) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_BEFORE_address = c8_c;
}

static real_T *c8_access_STATE_BEFORE(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c8_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1648) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_BEFORE_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1646) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_OVER_address;
}

static void c8_set_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1646) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_OVER_address = c8_c;
}

static real_T *c8_access_STATE_OVER(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c8_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1646) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_OVER_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c8_c;
}

static real_T c8_get_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1645) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_STATE_READY_address;
}

static void c8_set_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1645) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_STATE_READY_address = c8_c;
}

static real_T *c8_access_STATE_READY(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *
  chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c8_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1645) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_STATE_READY_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c8_c;
}

static real_T c8_get_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#1650) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_pr_address;
}

static void c8_set_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance,
                      uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#1650) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_pr_address = c8_c;
}

static real_T *c8_access_pr(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c8_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#1650) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_pr_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c8_c;
}

static void init_dsm_address_info(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c8_BML_address, &chartInstance->c8_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c8_STATE_BEFORE_address,
    &chartInstance->c8_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c8_STATE_OVER_address, &chartInstance->c8_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c8_STATE_READY_address, &chartInstance->c8_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pr", (void **)
    &chartInstance->c8_pr_address, &chartInstance->c8_pr_index);
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

void sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3350616703U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3138140437U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3529698363U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1894018815U);
}

mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("CUtaesdz1RW2ur4fqzTDdD");
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

mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[27],T\"gameState\",},{M[8],M[0],T\"is_active_c8_ARP_02_RPSs_Bdr_GK_BIS2\",},{M[9],M[0],T\"is_c8_ARP_02_RPSs_Bdr_GK_BIS2\",},{M[11],M[33],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x3[23 24 26],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_ARP_02_RPSs_Bdr_GK_BIS2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,
           8,
           6,
           16,
           0,
           9,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(2,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(3,1,1,0,"isInvading");
          _SFD_SET_DATA_PROPS(4,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(5,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(6,11,0,0,"pr");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,2);
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

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(5,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"walkInvadingTablec8_ARP_02_RPSs_Bdr_GK_BIS2",0,
                             -1,704);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",704,-1,913);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",913,-1,1122);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",1122,-1,1333);
        _SFD_CV_INIT_EML_FCN(5,4,"aFcnTruthTableAction_4",1333,-1,1522);
        _SFD_CV_INIT_EML_IF(5,1,0,398,428,459,702);
        _SFD_CV_INIT_EML_IF(5,1,1,459,493,524,702);
        _SFD_CV_INIT_EML_IF(5,1,2,524,558,589,702);
        _SFD_CV_INIT_EML_IF(5,1,3,589,623,654,702);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,55,1,48);

        {
          static int condStart[] = { 2, 29 };

          static int condEnd[] = { 25, 54 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,55,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,46,1,46);

        {
          static int condStart[] = { 2, 21 };

          static int condEnd[] = { 17, 45 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,46,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,46,1,46);

        {
          static int condStart[] = { 2, 21 };

          static int condEnd[] = { 17, 45 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,46,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));

        {
          real_T *c8_gameState;
          real_T *c8_isInvading;
          c8_isInvading = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c8_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_isInvading);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c8_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c8_BML_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c8_pr_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSs_Bdr_GK_BIS2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "L11bSfQay4wwlal1upqKvH";
}

static void sf_opaque_initialize_c8_ARP_02_RPSs_Bdr_GK_BIS2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS2
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*) chartInstanceVar);
  initialize_c8_ARP_02_RPSs_Bdr_GK_BIS2
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_ARP_02_RPSs_Bdr_GK_BIS2(void *chartInstanceVar)
{
  enable_c8_ARP_02_RPSs_Bdr_GK_BIS2((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_ARP_02_RPSs_Bdr_GK_BIS2(void *chartInstanceVar)
{
  disable_c8_ARP_02_RPSs_Bdr_GK_BIS2((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS2(void *chartInstanceVar)
{
  sf_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS2
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS2();/* state var info */
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

extern void sf_internal_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c8_ARP_02_RPSs_Bdr_GK_BIS2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSs_Bdr_GK_BIS2_optimization_info();
    }

    finalize_c8_ARP_02_RPSs_Bdr_GK_BIS2
      ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_ARP_02_RPSs_Bdr_GK_BIS2
    ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *S)
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
    initialize_params_c8_ARP_02_RPSs_Bdr_GK_BIS2
      ((SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSs_Bdr_GK_BIS2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3555637817U));
  ssSetChecksum1(S,(3438130285U));
  ssSetChecksum2(S,(501516890U));
  ssSetChecksum3(S,(1635581777U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_ARP_02_RPSs_Bdr_GK_BIS2(SimStruct *S)
{
  SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct *)utMalloc(sizeof
    (SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_ARP_02_RPSs_Bdr_GK_BIS2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_ARP_02_RPSs_Bdr_GK_BIS2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_ARP_02_RPSs_Bdr_GK_BIS2;
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

void c8_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_ARP_02_RPSs_Bdr_GK_BIS2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_ARP_02_RPSs_Bdr_GK_BIS2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_ARP_02_RPSs_Bdr_GK_BIS2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_ARP_02_RPSs_Bdr_GK_BIS2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
