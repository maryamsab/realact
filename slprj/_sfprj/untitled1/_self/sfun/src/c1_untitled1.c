/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled1_sfun.h"
#include "c1_untitled1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_stateStart               ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_j_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_m_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_n_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c1_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_u_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_hb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ib_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_kb_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[35];

/* Function Declarations */
static void initialize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void initialize_params_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void enable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void disable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void set_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_untitled1
  (SFc1_untitled1InstanceStruct *chartInstance);
static void finalize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void sf_gateway_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance);
static void initSimStructsc1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance);
static void c1_enter_atomic_stateStart(SFc1_untitled1InstanceStruct
  *chartInstance);
static void c1_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_b_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_c_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_d_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_e_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_f_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_g_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_h_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_i_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_j_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void c1_k_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_b_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_bmlID, const char_T *c1_identifier);
static real_T c1_c_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_d_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_myarr256, const char_T *c1_identifier, real_T c1_y[256]);
static void c1_f_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_r_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_u_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_v_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_w_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_x_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_y_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_db_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_boredPoseS(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_bmlID, real_T c1_poseBML[256]);
static const mxArray *c1_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_g_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_h_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_b_tp_stateGame, const char_T *c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_l_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_untitled1InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void init_dsm_address_info(SFc1_untitled1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_stateGame = 0U;
  chartInstance->c1_is_stateGame = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_stateGame = 0U;
  chartInstance->c1_tp_stateStart = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_is_active_c1_untitled1 = 0U;
}

static void initialize_params_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendSBM", 0);
}

static void disable_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendSBM", 0);
}

static void c1_update_debugger_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_untitled1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateGame == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i0;
  real_T c1_e_u[256];
  const mxArray *c1_f_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_m_hoistedGlobal;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_n_hoistedGlobal;
  real_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_o_hoistedGlobal;
  real_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_p_hoistedGlobal;
  real_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_q_hoistedGlobal;
  real_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_r_hoistedGlobal;
  real_T c1_s_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_s_hoistedGlobal;
  real_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_t_hoistedGlobal;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_u_hoistedGlobal;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_v_hoistedGlobal;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_w_hoistedGlobal;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_x_hoistedGlobal;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_y_hoistedGlobal;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  uint8_T c1_ab_hoistedGlobal;
  uint8_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  uint8_T c1_bb_hoistedGlobal;
  uint8_T c1_cb_u;
  const mxArray *c1_db_y = NULL;
  uint8_T c1_cb_hoistedGlobal;
  uint8_T c1_db_u;
  const mxArray *c1_eb_y = NULL;
  uint8_T c1_db_hoistedGlobal;
  uint8_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_round;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T (*c1_t)[256];
  c1_t = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(30, 1), false);
  c1_hoistedGlobal = *c1_bWinT;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_bradHand;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_gameState;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_round;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i0 = 0; c1_i0 < 256; c1_i0++) {
    c1_e_u[c1_i0] = (*c1_t)[c1_i0];
  }

  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_e_hoistedGlobal = *c1_uWinT;
  c1_f_u = c1_e_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_f_hoistedGlobal = *c1_userHand;
  c1_g_u = c1_f_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_g_hoistedGlobal = *c1_win;
  c1_h_u = c1_g_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_h_hoistedGlobal = chartInstance->c1_BOREDOMT;
  c1_i_u = c1_h_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_i_hoistedGlobal = chartInstance->c1_b;
  c1_j_u = c1_i_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_j_hoistedGlobal = chartInstance->c1_bHand;
  c1_k_u = c1_j_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_k_hoistedGlobal = chartInstance->c1_bored;
  c1_l_u = c1_k_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_l_hoistedGlobal = chartInstance->c1_diff;
  c1_m_u = c1_l_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_m_hoistedGlobal = chartInstance->c1_p;
  c1_n_u = c1_m_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_n_hoistedGlobal = chartInstance->c1_pose;
  c1_o_u = c1_n_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_o_hoistedGlobal = chartInstance->c1_r;
  c1_p_u = c1_o_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_p_hoistedGlobal = chartInstance->c1_randomD;
  c1_q_u = c1_p_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_q_hoistedGlobal = chartInstance->c1_randomG;
  c1_r_u = c1_q_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_r_hoistedGlobal = chartInstance->c1_randomH;
  c1_s_u = c1_r_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_s_hoistedGlobal = chartInstance->c1_randomP;
  c1_t_u = c1_s_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_t_hoistedGlobal = chartInstance->c1_s;
  c1_u_u = c1_t_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_u_hoistedGlobal = chartInstance->c1_smileN;
  c1_v_u = c1_u_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_v_hoistedGlobal = chartInstance->c1_smileYN;
  c1_w_u = c1_v_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_w_hoistedGlobal = chartInstance->c1_temp;
  c1_x_u = c1_w_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_x_hoistedGlobal = chartInstance->c1_uHand;
  c1_y_u = c1_x_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_y_hoistedGlobal = chartInstance->c1_wristRotate;
  c1_ab_u = c1_y_hoistedGlobal;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_ab_hoistedGlobal = chartInstance->c1_is_active_c1_untitled1;
  c1_bb_u = c1_ab_hoistedGlobal;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_bb_hoistedGlobal = chartInstance->c1_is_active_stateGame;
  c1_cb_u = c1_bb_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_cb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_cb_hoistedGlobal = chartInstance->c1_is_stateGame;
  c1_db_u = c1_cb_hoistedGlobal;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_db_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_db_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_eb_u = c1_db_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[256];
  int32_T c1_i1;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_round;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T (*c1_t)[256];
  c1_t = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_bWinT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "bWinT");
  *c1_bradHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "bradHand");
  *c1_gameState = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "gameState");
  *c1_round = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "round");
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)), "t",
                        c1_dv0);
  for (c1_i1 = 0; c1_i1 < 256; c1_i1++) {
    (*c1_t)[c1_i1] = c1_dv0[c1_i1];
  }

  *c1_uWinT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "uWinT");
  *c1_userHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 6)), "userHand");
  *c1_win = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    7)), "win");
  chartInstance->c1_BOREDOMT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "BOREDOMT");
  chartInstance->c1_b = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "b");
  chartInstance->c1_bHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 10)), "bHand");
  chartInstance->c1_bored = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "bored");
  chartInstance->c1_diff = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "diff");
  chartInstance->c1_p = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 13)), "p");
  chartInstance->c1_pose = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 14)), "pose");
  chartInstance->c1_r = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 15)), "r");
  chartInstance->c1_randomD = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 16)), "randomD");
  chartInstance->c1_randomG = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 17)), "randomG");
  chartInstance->c1_randomH = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 18)), "randomH");
  chartInstance->c1_randomP = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 19)), "randomP");
  chartInstance->c1_s = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 20)), "s");
  chartInstance->c1_smileN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 21)), "smileN");
  chartInstance->c1_smileYN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 22)), "smileYN");
  chartInstance->c1_temp = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 23)), "temp");
  chartInstance->c1_uHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 24)), "uHand");
  chartInstance->c1_wristRotate = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 25)), "wristRotate");
  chartInstance->c1_is_active_c1_untitled1 = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 26)), "is_active_c1_untitled1");
  chartInstance->c1_is_active_stateGame = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 27)), "is_active_stateGame");
  chartInstance->c1_is_stateGame = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 28)), "is_stateGame");
  chartInstance->c1_temporalCounter_i1 = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 29)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 30)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_untitled1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_untitled1
  (SFc1_untitled1InstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_stateGame == 1U) {
      chartInstance->c1_tp_stateGame = 1U;
    } else {
      chartInstance->c1_tp_stateGame = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateStart) {
      chartInstance->c1_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateStart = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_untitled1(SFc1_untitled1InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T *c1_gameState;
  real_T *c1_inputUser;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  real_T *c1_round;
  real_T (*c1_t)[256];
  c1_t = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_untitled1(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_inputUser, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_temp, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_bHand, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_bored, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_BOREDOMT, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomG, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 17U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_b, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_r, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_p, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_s, 21U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomD, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_wristRotate, 23U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomH, 24U);
  _SFD_DATA_RANGE_CHECK(*c1_round, 25U);
  for (c1_i2 = 0; c1_i2 < 256; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_t)[c1_i2], 26U);
  }

  if (chartInstance->c1_temporalCounter_i1 < 3U) {
    chartInstance->c1_temporalCounter_i1++;
  }

  chartInstance->c1_sfEvent = c1_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_untitled1 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_untitled1 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_stateGame = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateGame = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateStart;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateStart = 1U;
    c1_enter_atomic_stateStart(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_lb_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_out = CV_EML_IF(1, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                       (chartInstance->c1_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateStart;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateStart = 1U;
      c1_enter_atomic_stateStart(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitled1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_untitled1(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_enter_atomic_stateStart(SFc1_untitled1InstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv1[256];
  int32_T c1_i3;
  int32_T c1_i4;
  real_T *c1_round;
  real_T *c1_userHand;
  real_T *c1_bradHand;
  real_T *c1_win;
  real_T *c1_gameState;
  real_T *c1_uWinT;
  real_T *c1_bWinT;
  real_T (*c1_t)[256];
  c1_t = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_x_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  *c1_round = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 24U);
  _SFD_DATA_RANGE_CHECK(*c1_round, 25U);
  chartInstance->c1_uHand = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
  chartInstance->c1_smileYN = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
  *c1_userHand = 3.0;
  c1_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
  *c1_bradHand = 3.0;
  c1_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
  *c1_win = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
  chartInstance->c1_BOREDOMT = 10.0;
  c1_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_BOREDOMT, 14U);
  *c1_gameState = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  chartInstance->c1_randomP = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 16U);
  *c1_uWinT = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
  *c1_bWinT = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
  chartInstance->c1_pose = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 17U);
  chartInstance->c1_bored = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_bored, 13U);
  chartInstance->c1_randomG = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomG, 15U);
  c1_boredPoseS(chartInstance, 2.0, c1_dv1);
  for (c1_i3 = 0; c1_i3 < 256; c1_i3++) {
    (*c1_t)[c1_i3] = c1_dv1[c1_i3];
  }

  c1_updateDataWrittenToVector(chartInstance, 25U);
  for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_t)[c1_i4], 26U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[91];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[91];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i5;
  static char_T c1_cv0[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i6;
  static real_T c1_dv2[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_y_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i5 = 0; c1_i5 < 91; c1_i5++) {
    c1_mystr[c1_i5] = c1_cv0[c1_i5];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i6 = 0; c1_i6 < 91; c1_i6++) {
    c1_arr[c1_i6] = c1_dv2[c1_i6];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
    c1_tt[c1_i7] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i8 = 0; c1_i8 < 91; c1_i8++) {
    c1_tt[c1_i8] = c1_arr[c1_i8];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i9 = 0; c1_i9 < 256; c1_i9++) {
    c1_myarr256[c1_i9] = c1_tt[c1_i9];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_b_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[87];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[87];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i10;
  static char_T c1_cv1[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i11;
  static real_T c1_dv3[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ab_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i10 = 0; c1_i10 < 87; c1_i10++) {
    c1_mystr[c1_i10] = c1_cv1[c1_i10];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i11 = 0; c1_i11 < 87; c1_i11++) {
    c1_arr[c1_i11] = c1_dv3[c1_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
    c1_tt[c1_i12] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i13 = 0; c1_i13 < 87; c1_i13++) {
    c1_tt[c1_i13] = c1_arr[c1_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i14 = 0; c1_i14 < 256; c1_i14++) {
    c1_myarr256[c1_i14] = c1_tt[c1_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_c_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[93];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[93];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i15;
  static char_T c1_cv2[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i16;
  static real_T c1_dv4[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_bb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i15 = 0; c1_i15 < 93; c1_i15++) {
    c1_mystr[c1_i15] = c1_cv2[c1_i15];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i16 = 0; c1_i16 < 93; c1_i16++) {
    c1_arr[c1_i16] = c1_dv4[c1_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i17 = 0; c1_i17 < 256; c1_i17++) {
    c1_tt[c1_i17] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i18 = 0; c1_i18 < 93; c1_i18++) {
    c1_tt[c1_i18] = c1_arr[c1_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i19 = 0; c1_i19 < 256; c1_i19++) {
    c1_myarr256[c1_i19] = c1_tt[c1_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_d_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[94];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[94];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i20;
  static char_T c1_cv3[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i21;
  static real_T c1_dv5[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_cb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i20 = 0; c1_i20 < 94; c1_i20++) {
    c1_mystr[c1_i20] = c1_cv3[c1_i20];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i21 = 0; c1_i21 < 94; c1_i21++) {
    c1_arr[c1_i21] = c1_dv5[c1_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i22 = 0; c1_i22 < 256; c1_i22++) {
    c1_tt[c1_i22] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i23 = 0; c1_i23 < 94; c1_i23++) {
    c1_tt[c1_i23] = c1_arr[c1_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i24 = 0; c1_i24 < 256; c1_i24++) {
    c1_myarr256[c1_i24] = c1_tt[c1_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_e_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[95];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[95];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i25;
  static char_T c1_cv4[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i26;
  static real_T c1_dv6[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_db_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i25 = 0; c1_i25 < 95; c1_i25++) {
    c1_mystr[c1_i25] = c1_cv4[c1_i25];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i26 = 0; c1_i26 < 95; c1_i26++) {
    c1_arr[c1_i26] = c1_dv6[c1_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i27 = 0; c1_i27 < 256; c1_i27++) {
    c1_tt[c1_i27] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i28 = 0; c1_i28 < 95; c1_i28++) {
    c1_tt[c1_i28] = c1_arr[c1_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i29 = 0; c1_i29 < 256; c1_i29++) {
    c1_myarr256[c1_i29] = c1_tt[c1_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_f_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[88];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[88];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i30;
  static char_T c1_cv5[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c1_i31;
  static real_T c1_dv7[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_eb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i30 = 0; c1_i30 < 88; c1_i30++) {
    c1_mystr[c1_i30] = c1_cv5[c1_i30];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i31 = 0; c1_i31 < 88; c1_i31++) {
    c1_arr[c1_i31] = c1_dv7[c1_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i32 = 0; c1_i32 < 256; c1_i32++) {
    c1_tt[c1_i32] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i33 = 0; c1_i33 < 88; c1_i33++) {
    c1_tt[c1_i33] = c1_arr[c1_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i34 = 0; c1_i34 < 256; c1_i34++) {
    c1_myarr256[c1_i34] = c1_tt[c1_i34];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_g_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[93];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[93];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i35;
  static char_T c1_cv6[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i36;
  static real_T c1_dv8[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_fb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i35 = 0; c1_i35 < 93; c1_i35++) {
    c1_mystr[c1_i35] = c1_cv6[c1_i35];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i36 = 0; c1_i36 < 93; c1_i36++) {
    c1_arr[c1_i36] = c1_dv8[c1_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i37 = 0; c1_i37 < 256; c1_i37++) {
    c1_tt[c1_i37] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i38 = 0; c1_i38 < 93; c1_i38++) {
    c1_tt[c1_i38] = c1_arr[c1_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i39 = 0; c1_i39 < 256; c1_i39++) {
    c1_myarr256[c1_i39] = c1_tt[c1_i39];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_h_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[93];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[93];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i40;
  static char_T c1_cv7[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i41;
  static real_T c1_dv9[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_gb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i40 = 0; c1_i40 < 93; c1_i40++) {
    c1_mystr[c1_i40] = c1_cv7[c1_i40];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i41 = 0; c1_i41 < 93; c1_i41++) {
    c1_arr[c1_i41] = c1_dv9[c1_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i42 = 0; c1_i42 < 256; c1_i42++) {
    c1_tt[c1_i42] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i43 = 0; c1_i43 < 93; c1_i43++) {
    c1_tt[c1_i43] = c1_arr[c1_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i44 = 0; c1_i44 < 256; c1_i44++) {
    c1_myarr256[c1_i44] = c1_tt[c1_i44];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_i_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[97];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[97];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i45;
  static char_T c1_cv8[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i46;
  static real_T c1_dv10[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_hb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i45 = 0; c1_i45 < 97; c1_i45++) {
    c1_mystr[c1_i45] = c1_cv8[c1_i45];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i46 = 0; c1_i46 < 97; c1_i46++) {
    c1_arr[c1_i46] = c1_dv10[c1_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i47 = 0; c1_i47 < 256; c1_i47++) {
    c1_tt[c1_i47] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i48 = 0; c1_i48 < 97; c1_i48++) {
    c1_tt[c1_i48] = c1_arr[c1_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i49 = 0; c1_i49 < 256; c1_i49++) {
    c1_myarr256[c1_i49] = c1_tt[c1_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_j_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[97];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[97];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i50;
  static char_T c1_cv9[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i51;
  static real_T c1_dv11[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ib_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i50 = 0; c1_i50 < 97; c1_i50++) {
    c1_mystr[c1_i50] = c1_cv9[c1_i50];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i51 = 0; c1_i51 < 97; c1_i51++) {
    c1_arr[c1_i51] = c1_dv11[c1_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i52 = 0; c1_i52 < 256; c1_i52++) {
    c1_tt[c1_i52] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i53 = 0; c1_i53 < 97; c1_i53++) {
    c1_tt[c1_i53] = c1_arr[c1_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i54 = 0; c1_i54 < 256; c1_i54++) {
    c1_myarr256[c1_i54] = c1_tt[c1_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_k_encStr2Arr(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[92];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[92];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i55;
  static char_T c1_cv10[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i56;
  static real_T c1_dv12[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_jb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i55 = 0; c1_i55 < 92; c1_i55++) {
    c1_mystr[c1_i55] = c1_cv10[c1_i55];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i56 = 0; c1_i56 < 92; c1_i56++) {
    c1_arr[c1_i56] = c1_dv12[c1_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i57 = 0; c1_i57 < 256; c1_i57++) {
    c1_tt[c1_i57] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i58 = 0; c1_i58 < 92; c1_i58++) {
    c1_tt[c1_i58] = c1_arr[c1_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i59 = 0; c1_i59 < 256; c1_i59++) {
    c1_myarr256[c1_i59] = c1_tt[c1_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i60;
  real_T c1_b_inData[256];
  int32_T c1_i61;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i60 = 0; c1_i60 < 256; c1_i60++) {
    c1_b_inData[c1_i60] = (*(real_T (*)[256])c1_inData)[c1_i60];
  }

  for (c1_i61 = 0; c1_i61 < 256; c1_i61++) {
    c1_u[c1_i61] = c1_b_inData[c1_i61];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256])
{
  real_T c1_dv13[256];
  int32_T c1_i62;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv13, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c1_i62 = 0; c1_i62 < 256; c1_i62++) {
    c1_y[c1_i62] = c1_dv13[c1_i62];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_poseBML;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[256];
  int32_T c1_i63;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_poseBML = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_poseBML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_poseBML);
  for (c1_i63 = 0; c1_i63 < 256; c1_i63++) {
    (*(real_T (*)[256])c1_outData)[c1_i63] = c1_y[c1_i63];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_b_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_bmlID, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bmlID), &c1_thisId);
  sf_mex_destroy(&c1_bmlID);
  return c1_y;
}

static real_T c1_c_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_bmlID;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_bmlID = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bmlID), &c1_thisId);
  sf_mex_destroy(&c1_bmlID);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_aVarTruthTableCondition_8;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_aVarTruthTableCondition_8 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_8), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_8);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i64;
  real_T c1_b_inData[256];
  int32_T c1_i65;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i64 = 0; c1_i64 < 256; c1_i64++) {
    c1_b_inData[c1_i64] = (*(real_T (*)[256])c1_inData)[c1_i64];
  }

  for (c1_i65 = 0; c1_i65 < 256; c1_i65++) {
    c1_u[c1_i65] = c1_b_inData[c1_i65];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_myarr256, const char_T *c1_identifier, real_T c1_y[256])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_myarr256), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_myarr256);
}

static void c1_f_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256])
{
  real_T c1_dv14[256];
  int32_T c1_i66;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv14, 1, 0, 0U, 1, 0U, 1, 256);
  for (c1_i66 = 0; c1_i66 < 256; c1_i66++) {
    c1_y[c1_i66] = c1_dv14[c1_i66];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_myarr256;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[256];
  int32_T c1_i67;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_myarr256 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_myarr256), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_myarr256);
  for (c1_i67 = 0; c1_i67 < 256; c1_i67++) {
    (*(real_T (*)[256])c1_outData)[c1_i67] = c1_y[c1_i67];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i68;
  char_T c1_b_inData[147];
  int32_T c1_i69;
  char_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i68 = 0; c1_i68 < 147; c1_i68++) {
    c1_b_inData[c1_i68] = (*(char_T (*)[147])c1_inData)[c1_i68];
  }

  for (c1_i69 = 0; c1_i69 < 147; c1_i69++) {
    c1_u[c1_i69] = c1_b_inData[c1_i69];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i70;
  real_T c1_b_inData[147];
  int32_T c1_i71;
  real_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i70 = 0; c1_i70 < 147; c1_i70++) {
    c1_b_inData[c1_i70] = (*(real_T (*)[147])c1_inData)[c1_i70];
  }

  for (c1_i71 = 0; c1_i71 < 147; c1_i71++) {
    c1_u[c1_i71] = c1_b_inData[c1_i71];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i72;
  char_T c1_b_inData[164];
  int32_T c1_i73;
  char_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i72 = 0; c1_i72 < 164; c1_i72++) {
    c1_b_inData[c1_i72] = (*(char_T (*)[164])c1_inData)[c1_i72];
  }

  for (c1_i73 = 0; c1_i73 < 164; c1_i73++) {
    c1_u[c1_i73] = c1_b_inData[c1_i73];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i74;
  real_T c1_b_inData[164];
  int32_T c1_i75;
  real_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i74 = 0; c1_i74 < 164; c1_i74++) {
    c1_b_inData[c1_i74] = (*(real_T (*)[164])c1_inData)[c1_i74];
  }

  for (c1_i75 = 0; c1_i75 < 164; c1_i75++) {
    c1_u[c1_i75] = c1_b_inData[c1_i75];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i76;
  char_T c1_b_inData[68];
  int32_T c1_i77;
  char_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i76 = 0; c1_i76 < 68; c1_i76++) {
    c1_b_inData[c1_i76] = (*(char_T (*)[68])c1_inData)[c1_i76];
  }

  for (c1_i77 = 0; c1_i77 < 68; c1_i77++) {
    c1_u[c1_i77] = c1_b_inData[c1_i77];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i78;
  real_T c1_b_inData[68];
  int32_T c1_i79;
  real_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i78 = 0; c1_i78 < 68; c1_i78++) {
    c1_b_inData[c1_i78] = (*(real_T (*)[68])c1_inData)[c1_i78];
  }

  for (c1_i79 = 0; c1_i79 < 68; c1_i79++) {
    c1_u[c1_i79] = c1_b_inData[c1_i79];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i80;
  char_T c1_b_inData[223];
  int32_T c1_i81;
  char_T c1_u[223];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i80 = 0; c1_i80 < 223; c1_i80++) {
    c1_b_inData[c1_i80] = (*(char_T (*)[223])c1_inData)[c1_i80];
  }

  for (c1_i81 = 0; c1_i81 < 223; c1_i81++) {
    c1_u[c1_i81] = c1_b_inData[c1_i81];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i82;
  real_T c1_b_inData[223];
  int32_T c1_i83;
  real_T c1_u[223];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i82 = 0; c1_i82 < 223; c1_i82++) {
    c1_b_inData[c1_i82] = (*(real_T (*)[223])c1_inData)[c1_i82];
  }

  for (c1_i83 = 0; c1_i83 < 223; c1_i83++) {
    c1_u[c1_i83] = c1_b_inData[c1_i83];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i84;
  char_T c1_b_inData[225];
  int32_T c1_i85;
  char_T c1_u[225];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i84 = 0; c1_i84 < 225; c1_i84++) {
    c1_b_inData[c1_i84] = (*(char_T (*)[225])c1_inData)[c1_i84];
  }

  for (c1_i85 = 0; c1_i85 < 225; c1_i85++) {
    c1_u[c1_i85] = c1_b_inData[c1_i85];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i86;
  real_T c1_b_inData[225];
  int32_T c1_i87;
  real_T c1_u[225];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i86 = 0; c1_i86 < 225; c1_i86++) {
    c1_b_inData[c1_i86] = (*(real_T (*)[225])c1_inData)[c1_i86];
  }

  for (c1_i87 = 0; c1_i87 < 225; c1_i87++) {
    c1_u[c1_i87] = c1_b_inData[c1_i87];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i88;
  char_T c1_b_inData[87];
  int32_T c1_i89;
  char_T c1_u[87];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i88 = 0; c1_i88 < 87; c1_i88++) {
    c1_b_inData[c1_i88] = (*(char_T (*)[87])c1_inData)[c1_i88];
  }

  for (c1_i89 = 0; c1_i89 < 87; c1_i89++) {
    c1_u[c1_i89] = c1_b_inData[c1_i89];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i90;
  real_T c1_b_inData[87];
  int32_T c1_i91;
  real_T c1_u[87];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i90 = 0; c1_i90 < 87; c1_i90++) {
    c1_b_inData[c1_i90] = (*(real_T (*)[87])c1_inData)[c1_i90];
  }

  for (c1_i91 = 0; c1_i91 < 87; c1_i91++) {
    c1_u[c1_i91] = c1_b_inData[c1_i91];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i92;
  char_T c1_b_inData[88];
  int32_T c1_i93;
  char_T c1_u[88];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i92 = 0; c1_i92 < 88; c1_i92++) {
    c1_b_inData[c1_i92] = (*(char_T (*)[88])c1_inData)[c1_i92];
  }

  for (c1_i93 = 0; c1_i93 < 88; c1_i93++) {
    c1_u[c1_i93] = c1_b_inData[c1_i93];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_r_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i94;
  real_T c1_b_inData[88];
  int32_T c1_i95;
  real_T c1_u[88];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i94 = 0; c1_i94 < 88; c1_i94++) {
    c1_b_inData[c1_i94] = (*(real_T (*)[88])c1_inData)[c1_i94];
  }

  for (c1_i95 = 0; c1_i95 < 88; c1_i95++) {
    c1_u[c1_i95] = c1_b_inData[c1_i95];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i96;
  char_T c1_b_inData[86];
  int32_T c1_i97;
  char_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i96 = 0; c1_i96 < 86; c1_i96++) {
    c1_b_inData[c1_i96] = (*(char_T (*)[86])c1_inData)[c1_i96];
  }

  for (c1_i97 = 0; c1_i97 < 86; c1_i97++) {
    c1_u[c1_i97] = c1_b_inData[c1_i97];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i98;
  real_T c1_b_inData[86];
  int32_T c1_i99;
  real_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i98 = 0; c1_i98 < 86; c1_i98++) {
    c1_b_inData[c1_i98] = (*(real_T (*)[86])c1_inData)[c1_i98];
  }

  for (c1_i99 = 0; c1_i99 < 86; c1_i99++) {
    c1_u[c1_i99] = c1_b_inData[c1_i99];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_u_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i100;
  char_T c1_b_inData[161];
  int32_T c1_i101;
  char_T c1_u[161];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i100 = 0; c1_i100 < 161; c1_i100++) {
    c1_b_inData[c1_i100] = (*(char_T (*)[161])c1_inData)[c1_i100];
  }

  for (c1_i101 = 0; c1_i101 < 161; c1_i101++) {
    c1_u[c1_i101] = c1_b_inData[c1_i101];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_v_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i102;
  real_T c1_b_inData[161];
  int32_T c1_i103;
  real_T c1_u[161];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i102 = 0; c1_i102 < 161; c1_i102++) {
    c1_b_inData[c1_i102] = (*(real_T (*)[161])c1_inData)[c1_i102];
  }

  for (c1_i103 = 0; c1_i103 < 161; c1_i103++) {
    c1_u[c1_i103] = c1_b_inData[c1_i103];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_w_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i104;
  char_T c1_b_inData[157];
  int32_T c1_i105;
  char_T c1_u[157];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i104 = 0; c1_i104 < 157; c1_i104++) {
    c1_b_inData[c1_i104] = (*(char_T (*)[157])c1_inData)[c1_i104];
  }

  for (c1_i105 = 0; c1_i105 < 157; c1_i105++) {
    c1_u[c1_i105] = c1_b_inData[c1_i105];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 157),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_x_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i106;
  real_T c1_b_inData[157];
  int32_T c1_i107;
  real_T c1_u[157];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i106 = 0; c1_i106 < 157; c1_i106++) {
    c1_b_inData[c1_i106] = (*(real_T (*)[157])c1_inData)[c1_i106];
  }

  for (c1_i107 = 0; c1_i107 < 157; c1_i107++) {
    c1_u[c1_i107] = c1_b_inData[c1_i107];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 157), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_y_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i108;
  char_T c1_b_inData[92];
  int32_T c1_i109;
  char_T c1_u[92];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i108 = 0; c1_i108 < 92; c1_i108++) {
    c1_b_inData[c1_i108] = (*(char_T (*)[92])c1_inData)[c1_i108];
  }

  for (c1_i109 = 0; c1_i109 < 92; c1_i109++) {
    c1_u[c1_i109] = c1_b_inData[c1_i109];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i110;
  real_T c1_b_inData[92];
  int32_T c1_i111;
  real_T c1_u[92];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i110 = 0; c1_i110 < 92; c1_i110++) {
    c1_b_inData[c1_i110] = (*(real_T (*)[92])c1_inData)[c1_i110];
  }

  for (c1_i111 = 0; c1_i111 < 92; c1_i111++) {
    c1_u[c1_i111] = c1_b_inData[c1_i111];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i112;
  char_T c1_b_inData[89];
  int32_T c1_i113;
  char_T c1_u[89];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i112 = 0; c1_i112 < 89; c1_i112++) {
    c1_b_inData[c1_i112] = (*(char_T (*)[89])c1_inData)[c1_i112];
  }

  for (c1_i113 = 0; c1_i113 < 89; c1_i113++) {
    c1_u[c1_i113] = c1_b_inData[c1_i113];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 89), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i114;
  real_T c1_b_inData[89];
  int32_T c1_i115;
  real_T c1_u[89];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i114 = 0; c1_i114 < 89; c1_i114++) {
    c1_b_inData[c1_i114] = (*(real_T (*)[89])c1_inData)[c1_i114];
  }

  for (c1_i115 = 0; c1_i115 < 89; c1_i115++) {
    c1_u[c1_i115] = c1_b_inData[c1_i115];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 89), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_db_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i116;
  char_T c1_b_inData[81];
  int32_T c1_i117;
  char_T c1_u[81];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i116 = 0; c1_i116 < 81; c1_i116++) {
    c1_b_inData[c1_i116] = (*(char_T (*)[81])c1_inData)[c1_i116];
  }

  for (c1_i117 = 0; c1_i117 < 81; c1_i117++) {
    c1_u[c1_i117] = c1_b_inData[c1_i117];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 81), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i118;
  real_T c1_b_inData[81];
  int32_T c1_i119;
  real_T c1_u[81];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i118 = 0; c1_i118 < 81; c1_i118++) {
    c1_b_inData[c1_i118] = (*(real_T (*)[81])c1_inData)[c1_i118];
  }

  for (c1_i119 = 0; c1_i119 < 81; c1_i119++) {
    c1_u[c1_i119] = c1_b_inData[c1_i119];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 81), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i120;
  char_T c1_b_inData[78];
  int32_T c1_i121;
  char_T c1_u[78];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i120 = 0; c1_i120 < 78; c1_i120++) {
    c1_b_inData[c1_i120] = (*(char_T (*)[78])c1_inData)[c1_i120];
  }

  for (c1_i121 = 0; c1_i121 < 78; c1_i121++) {
    c1_u[c1_i121] = c1_b_inData[c1_i121];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 78), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i122;
  real_T c1_b_inData[78];
  int32_T c1_i123;
  real_T c1_u[78];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i122 = 0; c1_i122 < 78; c1_i122++) {
    c1_b_inData[c1_i122] = (*(real_T (*)[78])c1_inData)[c1_i122];
  }

  for (c1_i123 = 0; c1_i123 < 78; c1_i123++) {
    c1_u[c1_i123] = c1_b_inData[c1_i123];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 78), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i124;
  char_T c1_b_inData[94];
  int32_T c1_i125;
  char_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i124 = 0; c1_i124 < 94; c1_i124++) {
    c1_b_inData[c1_i124] = (*(char_T (*)[94])c1_inData)[c1_i124];
  }

  for (c1_i125 = 0; c1_i125 < 94; c1_i125++) {
    c1_u[c1_i125] = c1_b_inData[c1_i125];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i126;
  real_T c1_b_inData[94];
  int32_T c1_i127;
  real_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i126 = 0; c1_i126 < 94; c1_i126++) {
    c1_b_inData[c1_i126] = (*(real_T (*)[94])c1_inData)[c1_i126];
  }

  for (c1_i127 = 0; c1_i127 < 94; c1_i127++) {
    c1_u[c1_i127] = c1_b_inData[c1_i127];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i128;
  char_T c1_b_inData[91];
  int32_T c1_i129;
  char_T c1_u[91];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i128 = 0; c1_i128 < 91; c1_i128++) {
    c1_b_inData[c1_i128] = (*(char_T (*)[91])c1_inData)[c1_i128];
  }

  for (c1_i129 = 0; c1_i129 < 91; c1_i129++) {
    c1_u[c1_i129] = c1_b_inData[c1_i129];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i130;
  real_T c1_b_inData[91];
  int32_T c1_i131;
  real_T c1_u[91];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i130 = 0; c1_i130 < 91; c1_i130++) {
    c1_b_inData[c1_i130] = (*(real_T (*)[91])c1_inData)[c1_i130];
  }

  for (c1_i131 = 0; c1_i131 < 91; c1_i131++) {
    c1_u[c1_i131] = c1_b_inData[c1_i131];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i132;
  char_T c1_b_inData[93];
  int32_T c1_i133;
  char_T c1_u[93];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i132 = 0; c1_i132 < 93; c1_i132++) {
    c1_b_inData[c1_i132] = (*(char_T (*)[93])c1_inData)[c1_i132];
  }

  for (c1_i133 = 0; c1_i133 < 93; c1_i133++) {
    c1_u[c1_i133] = c1_b_inData[c1_i133];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i134;
  real_T c1_b_inData[93];
  int32_T c1_i135;
  real_T c1_u[93];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i134 = 0; c1_i134 < 93; c1_i134++) {
    c1_b_inData[c1_i134] = (*(real_T (*)[93])c1_inData)[c1_i134];
  }

  for (c1_i135 = 0; c1_i135 < 93; c1_i135++) {
    c1_u[c1_i135] = c1_b_inData[c1_i135];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i136;
  char_T c1_b_inData[95];
  int32_T c1_i137;
  char_T c1_u[95];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i136 = 0; c1_i136 < 95; c1_i136++) {
    c1_b_inData[c1_i136] = (*(char_T (*)[95])c1_inData)[c1_i136];
  }

  for (c1_i137 = 0; c1_i137 < 95; c1_i137++) {
    c1_u[c1_i137] = c1_b_inData[c1_i137];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i138;
  real_T c1_b_inData[95];
  int32_T c1_i139;
  real_T c1_u[95];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i138 = 0; c1_i138 < 95; c1_i138++) {
    c1_b_inData[c1_i138] = (*(real_T (*)[95])c1_inData)[c1_i138];
  }

  for (c1_i139 = 0; c1_i139 < 95; c1_i139++) {
    c1_u[c1_i139] = c1_b_inData[c1_i139];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i140;
  char_T c1_b_inData[97];
  int32_T c1_i141;
  char_T c1_u[97];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i140 = 0; c1_i140 < 97; c1_i140++) {
    c1_b_inData[c1_i140] = (*(char_T (*)[97])c1_inData)[c1_i140];
  }

  for (c1_i141 = 0; c1_i141 < 97; c1_i141++) {
    c1_u[c1_i141] = c1_b_inData[c1_i141];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i142;
  real_T c1_b_inData[97];
  int32_T c1_i143;
  real_T c1_u[97];
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i142 = 0; c1_i142 < 97; c1_i142++) {
    c1_b_inData[c1_i142] = (*(real_T (*)[97])c1_inData)[c1_i142];
  }

  for (c1_i143 = 0; c1_i143 < 97; c1_i143++) {
    c1_u[c1_i143] = c1_b_inData[c1_i143];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_untitled1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static void c1_boredPoseS(SFc1_untitled1InstanceStruct *chartInstance, real_T
  c1_bmlID, real_T c1_poseBML[256])
{
  uint32_T c1_debug_family_var_map[22];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  boolean_T c1_aVarTruthTableCondition_5;
  boolean_T c1_aVarTruthTableCondition_6;
  boolean_T c1_aVarTruthTableCondition_7;
  boolean_T c1_aVarTruthTableCondition_8;
  boolean_T c1_aVarTruthTableCondition_9;
  boolean_T c1_aVarTruthTableCondition_10;
  boolean_T c1_aVarTruthTableCondition_11;
  boolean_T c1_aVarTruthTableCondition_12;
  boolean_T c1_aVarTruthTableCondition_13;
  boolean_T c1_aVarTruthTableCondition_14;
  boolean_T c1_aVarTruthTableCondition_15;
  boolean_T c1_aVarTruthTableCondition_16;
  boolean_T c1_aVarTruthTableCondition_17;
  boolean_T c1_aVarTruthTableCondition_18;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv15[256];
  int32_T c1_i144;
  real_T c1_dv16[256];
  int32_T c1_i145;
  real_T c1_dv17[256];
  int32_T c1_i146;
  real_T c1_dv18[256];
  int32_T c1_i147;
  real_T c1_dv19[256];
  int32_T c1_i148;
  real_T c1_dv20[256];
  int32_T c1_i149;
  real_T c1_dv21[256];
  int32_T c1_i150;
  real_T c1_dv22[256];
  int32_T c1_i151;
  real_T c1_dv23[256];
  int32_T c1_i152;
  real_T c1_dv24[256];
  int32_T c1_i153;
  real_T c1_dv25[256];
  int32_T c1_i154;
  real_T c1_dv26[256];
  int32_T c1_i155;
  real_T c1_dv27[256];
  int32_T c1_i156;
  real_T c1_dv28[256];
  int32_T c1_i157;
  real_T c1_dv29[256];
  int32_T c1_i158;
  real_T c1_dv30[256];
  int32_T c1_i159;
  real_T c1_dv31[256];
  int32_T c1_i160;
  real_T c1_dv32[256];
  int32_T c1_i161;
  real_T c1_dv33[256];
  int32_T c1_i162;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c1_kb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_5, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_6, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_7, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_8, 7U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_9, 8U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_10, 9U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_11, 10U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_12, 11U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_13, 12U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_14, 13U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_15, 14U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_16, 15U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_17, 16U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_18, 17U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 18U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 19U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 20U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 21U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 7);
  c1_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 8);
  c1_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 10);
  c1_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 11);
  c1_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 12);
  c1_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 13);
  c1_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 14);
  c1_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 15);
  c1_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 16);
  c1_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 17);
  c1_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 18);
  c1_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 19);
  c1_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 20);
  c1_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 24);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 27);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 30);
  c1_aVarTruthTableCondition_3 = (c1_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 33);
  c1_aVarTruthTableCondition_4 = (c1_bmlID == 4.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 36);
  c1_aVarTruthTableCondition_5 = (c1_bmlID == 5.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 39);
  c1_aVarTruthTableCondition_6 = (c1_bmlID == 6.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 42);
  c1_aVarTruthTableCondition_7 = (c1_bmlID == 7.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 45);
  c1_aVarTruthTableCondition_8 = (c1_bmlID == 8.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 48);
  c1_aVarTruthTableCondition_9 = (c1_bmlID == 9.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 51);
  c1_aVarTruthTableCondition_10 = (c1_bmlID == 10.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 54);
  c1_aVarTruthTableCondition_11 = (c1_bmlID == 11.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 57);
  c1_aVarTruthTableCondition_12 = (c1_bmlID == 12.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 60);
  c1_aVarTruthTableCondition_13 = (c1_bmlID == 13.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 63);
  c1_aVarTruthTableCondition_14 = (c1_bmlID == 14.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 66);
  c1_aVarTruthTableCondition_15 = (c1_bmlID == 15.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 69);
  c1_aVarTruthTableCondition_16 = (c1_bmlID == 16.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 72);
  c1_aVarTruthTableCondition_17 = (c1_bmlID == 17.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 75);
  c1_aVarTruthTableCondition_18 = (c1_bmlID == 18.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 77);
  if (CV_EML_IF(3, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 78);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 121);
    c1_encStr2Arr(chartInstance, c1_dv15);
    for (c1_i144 = 0; c1_i144 < 256; c1_i144++) {
      c1_poseBML[c1_i144] = c1_dv15[c1_i144];
    }

    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -121);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 79);
    if (CV_EML_IF(3, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 80);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, MAX_int8_T);
      c1_b_encStr2Arr(chartInstance, c1_dv16);
      for (c1_i145 = 0; c1_i145 < 256; c1_i145++) {
        c1_poseBML[c1_i145] = c1_dv16[c1_i145];
      }

      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -127);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 81);
      if (CV_EML_IF(3, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 82);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 133U);
        c1_c_encStr2Arr(chartInstance, c1_dv17);
        for (c1_i146 = 0; c1_i146 < 256; c1_i146++) {
          c1_poseBML[c1_i146] = c1_dv17[c1_i146];
        }

        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -133);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 83);
        if (CV_EML_IF(3, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 84);
          CV_EML_FCN(3, 4);
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 139U);
          c1_d_encStr2Arr(chartInstance, c1_dv18);
          for (c1_i147 = 0; c1_i147 < 256; c1_i147++) {
            c1_poseBML[c1_i147] = c1_dv18[c1_i147];
          }

          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -139);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 85);
          if (CV_EML_IF(3, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 86);
            CV_EML_FCN(3, 5);
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 145U);
            c1_e_encStr2Arr(chartInstance, c1_dv19);
            for (c1_i148 = 0; c1_i148 < 256; c1_i148++) {
              c1_poseBML[c1_i148] = c1_dv19[c1_i148];
            }

            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -145);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 87);
            if (CV_EML_IF(3, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 88);
              CV_EML_FCN(3, 11);
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 181U);
              c1_f_encStr2Arr(chartInstance, c1_dv20);
              for (c1_i149 = 0; c1_i149 < 256; c1_i149++) {
                c1_poseBML[c1_i149] = c1_dv20[c1_i149];
              }

              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -181);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 89);
              if (CV_EML_IF(3, 1, 6, c1_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 90);
                CV_EML_FCN(3, 3);
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 133U);
                c1_c_encStr2Arr(chartInstance, c1_dv21);
                for (c1_i150 = 0; c1_i150 < 256; c1_i150++) {
                  c1_poseBML[c1_i150] = c1_dv21[c1_i150];
                }

                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -133);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 91);
                if (CV_EML_IF(3, 1, 7, c1_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 92);
                  CV_EML_FCN(3, 5);
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 145U);
                  c1_e_encStr2Arr(chartInstance, c1_dv22);
                  for (c1_i151 = 0; c1_i151 < 256; c1_i151++) {
                    c1_poseBML[c1_i151] = c1_dv22[c1_i151];
                  }

                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 93);
                  if (CV_EML_IF(3, 1, 8, c1_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 94);
                    CV_EML_FCN(3, 3);
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 133U);
                    c1_c_encStr2Arr(chartInstance, c1_dv23);
                    for (c1_i152 = 0; c1_i152 < 256; c1_i152++) {
                      c1_poseBML[c1_i152] = c1_dv23[c1_i152];
                    }

                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 95);
                    if (CV_EML_IF(3, 1, 9, c1_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 96);
                      CV_EML_FCN(3, 10);
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 175U);
                      c1_g_encStr2Arr(chartInstance, c1_dv24);
                      for (c1_i153 = 0; c1_i153 < 256; c1_i153++) {
                        c1_poseBML[c1_i153] = c1_dv24[c1_i153];
                      }

                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 97);
                      if (CV_EML_IF(3, 1, 10, c1_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 98);
                        CV_EML_FCN(3, 11);
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 181U);
                        c1_f_encStr2Arr(chartInstance, c1_dv25);
                        for (c1_i154 = 0; c1_i154 < 256; c1_i154++) {
                          c1_poseBML[c1_i154] = c1_dv25[c1_i154];
                        }

                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 99);
                        if (CV_EML_IF(3, 1, 11, c1_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 100);
                          CV_EML_FCN(3, 8);
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 163U);
                          c1_h_encStr2Arr(chartInstance, c1_dv26);
                          for (c1_i155 = 0; c1_i155 < 256; c1_i155++) {
                            c1_poseBML[c1_i155] = c1_dv26[c1_i155];
                          }

                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 101);
                          if (CV_EML_IF(3, 1, 12, c1_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 102);
                            CV_EML_FCN(3, 8);
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 163U);
                            c1_h_encStr2Arr(chartInstance, c1_dv27);
                            for (c1_i156 = 0; c1_i156 < 256; c1_i156++) {
                              c1_poseBML[c1_i156] = c1_dv27[c1_i156];
                            }

                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 103);
                            if (CV_EML_IF(3, 1, 13,
                                          c1_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 104);
                              CV_EML_FCN(3, 7);
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 157U);
                              c1_i_encStr2Arr(chartInstance, c1_dv28);
                              for (c1_i157 = 0; c1_i157 < 256; c1_i157++) {
                                c1_poseBML[c1_i157] = c1_dv28[c1_i157];
                              }

                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 105);
                              if (CV_EML_IF(3, 1, 14,
                                            c1_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 106);
                                CV_EML_FCN(3, 6);
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                              151U);
                                c1_j_encStr2Arr(chartInstance, c1_dv29);
                                for (c1_i158 = 0; c1_i158 < 256; c1_i158++) {
                                  c1_poseBML[c1_i158] = c1_dv29[c1_i158];
                                }

                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 107);
                                if (CV_EML_IF(3, 1, 15,
                                              c1_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                108);
                                  CV_EML_FCN(3, 5);
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                145U);
                                  c1_e_encStr2Arr(chartInstance, c1_dv30);
                                  for (c1_i159 = 0; c1_i159 < 256; c1_i159++) {
                                    c1_poseBML[c1_i159] = c1_dv30[c1_i159];
                                  }

                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                109);
                                  if (CV_EML_IF(3, 1, 16,
                                                c1_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  110);
                                    CV_EML_FCN(3, 8);
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  163U);
                                    c1_h_encStr2Arr(chartInstance, c1_dv31);
                                    for (c1_i160 = 0; c1_i160 < 256; c1_i160++)
                                    {
                                      c1_poseBML[c1_i160] = c1_dv31[c1_i160];
                                    }

                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  111);
                                    if (CV_EML_IF(3, 1, 17,
                                                  c1_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    112);
                                      CV_EML_FCN(3, 9);
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    169U);
                                      c1_k_encStr2Arr(chartInstance, c1_dv32);
                                      for (c1_i161 = 0; c1_i161 < 256; c1_i161++)
                                      {
                                        c1_poseBML[c1_i161] = c1_dv32[c1_i161];
                                      }

                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    114);
                                      CV_EML_FCN(3, 3);
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    133U);
                                      c1_c_encStr2Arr(chartInstance, c1_dv33);
                                      for (c1_i162 = 0; c1_i162 < 256; c1_i162++)
                                      {
                                        c1_poseBML[c1_i162] = c1_dv33[c1_i162];
                                      }

                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    -133);
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c1_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_g_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i163;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i163, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i163;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_secs;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_secs = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_secs), &c1_thisId);
  sf_mex_destroy(&c1_secs);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_h_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i164;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i164, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i164;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_b_tp_stateGame, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_stateGame),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_stateGame);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_untitled1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_stateGame;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_untitled1InstanceStruct *chartInstance;
  chartInstance = (SFc1_untitled1InstanceStruct *)chartInstanceVoid;
  c1_b_tp_stateGame = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_stateGame),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_stateGame);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_l_emlrt_marshallIn(SFc1_untitled1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_untitled1InstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 34, 1, 0)] = true;
}

static void init_dsm_address_info(SFc1_untitled1InstanceStruct *chartInstance)
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

void sf_c1_untitled1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4156684460U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1415803537U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(619345988U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(344323571U);
}

mxArray *sf_c1_untitled1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Xl4o1uZr4dL17gKIe17DiD");
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

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      pr[1] = (double)(1);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
      pr[1] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,18,3,dataFields);

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
      pr[1] = (double)(1);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_untitled1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_untitled1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_untitled1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[713],T\"round\",},{M[1],M[732],T\"t\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[568],T\"BOREDOMT\",},{M[3],M[641],T\"b\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[468],T\"bHand\",},{M[3],M[567],T\"bored\",},{M[3],M[462],T\"diff\",},{M[3],M[660],T\"p\",},{M[3],M[636],T\"pose\",},{M[3],M[659],T\"r\",},{M[3],M[688],T\"randomD\",},{M[3],M[596],T\"randomG\",},{M[3],M[701],T\"randomH\",},{M[3],M[635],T\"randomP\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[661],T\"s\",},{M[3],M[482],T\"smileN\",},{M[3],M[566],T\"smileYN\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",},{M[3],M[689],T\"wristRotate\",},{M[8],M[0],T\"is_active_c1_untitled1\",},{M[8],M[618],T\"is_active_stateGame\",},{M[9],M[618],T\"is_stateGame\",},{M[11],M[510],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[432],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 30, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_untitled1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_untitled1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_untitled1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitled1MachineNumber_,
           1,
           13,
           2,
           0,
           47,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_untitled1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_untitled1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _untitled1MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inputUser");
          _SFD_SET_DATA_PROPS(2,2,0,1,"bradHand");
          _SFD_SET_DATA_PROPS(3,2,0,1,"userHand");
          _SFD_SET_DATA_PROPS(4,2,0,1,"win");
          _SFD_SET_DATA_PROPS(5,0,0,0,"temp");
          _SFD_SET_DATA_PROPS(6,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(7,0,0,0,"uHand");
          _SFD_SET_DATA_PROPS(8,0,0,0,"bHand");
          _SFD_SET_DATA_PROPS(9,2,0,1,"bWinT");
          _SFD_SET_DATA_PROPS(10,2,0,1,"uWinT");
          _SFD_SET_DATA_PROPS(11,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(12,0,0,0,"smileYN");
          _SFD_SET_DATA_PROPS(13,0,0,0,"bored");
          _SFD_SET_DATA_PROPS(14,0,0,0,"BOREDOMT");
          _SFD_SET_DATA_PROPS(15,0,0,0,"randomG");
          _SFD_SET_DATA_PROPS(16,0,0,0,"randomP");
          _SFD_SET_DATA_PROPS(17,0,0,0,"pose");
          _SFD_SET_DATA_PROPS(18,0,0,0,"b");
          _SFD_SET_DATA_PROPS(19,0,0,0,"r");
          _SFD_SET_DATA_PROPS(20,0,0,0,"p");
          _SFD_SET_DATA_PROPS(21,0,0,0,"s");
          _SFD_SET_DATA_PROPS(22,0,0,0,"randomD");
          _SFD_SET_DATA_PROPS(23,0,0,0,"wristRotate");
          _SFD_SET_DATA_PROPS(24,0,0,0,"randomH");
          _SFD_SET_DATA_PROPS(25,2,0,1,"round");
          _SFD_SET_DATA_PROPS(26,2,0,1,"t");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,8,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_SET_DATA_PROPS(30,9,0,0,"");
          _SFD_SET_DATA_PROPS(31,8,0,0,"");
          _SFD_SET_DATA_PROPS(32,9,0,0,"");
          _SFD_SET_DATA_PROPS(33,8,0,0,"");
          _SFD_SET_DATA_PROPS(34,9,0,0,"");
          _SFD_SET_DATA_PROPS(35,8,0,0,"");
          _SFD_SET_DATA_PROPS(36,9,0,0,"");
          _SFD_SET_DATA_PROPS(37,8,0,0,"");
          _SFD_SET_DATA_PROPS(38,9,0,0,"");
          _SFD_SET_DATA_PROPS(39,8,0,0,"");
          _SFD_SET_DATA_PROPS(40,9,0,0,"");
          _SFD_SET_DATA_PROPS(41,8,0,0,"");
          _SFD_SET_DATA_PROPS(42,9,0,0,"");
          _SFD_SET_DATA_PROPS(43,8,0,0,"");
          _SFD_SET_DATA_PROPS(44,9,0,0,"");
          _SFD_SET_DATA_PROPS(45,8,0,0,"");
          _SFD_SET_DATA_PROPS(46,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(11,0,1);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,11);
          _SFD_ST_SUBSTATE_COUNT(11,1);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_COUNT(12,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(11,1,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

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

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,27,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"boredGaze",0,-1,2810);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",2810,-1,2996);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",2996,-1,3184);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",3184,-1,3366);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",3366,-1,3552);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",3552,-1,3742);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",3742,-1,3934);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",3934,-1,4128);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",4128,-1,4324);
        _SFD_CV_INIT_EML_FCN(1,9,"aFcnTruthTableAction_9",4324,-1,4524);
        _SFD_CV_INIT_EML_FCN(1,10,"aFcnTruthTableAction_10",4524,-1,4733);
        _SFD_CV_INIT_EML_FCN(1,11,"aFcnTruthTableAction_11",4733,-1,4944);
        _SFD_CV_INIT_EML_FCN(1,12,"aFcnTruthTableAction_12",4944,-1,5151);
        _SFD_CV_INIT_EML_FCN(1,13,"aFcnTruthTableAction_13",5151,-1,5356);
        _SFD_CV_INIT_EML_FCN(1,14,"aFcnTruthTableAction_14",5356,-1,5553);
        _SFD_CV_INIT_EML_FCN(1,15,"aFcnTruthTableAction_15",5553,-1,5756);
        _SFD_CV_INIT_EML_FCN(1,16,"aFcnTruthTableAction_16",5756,-1,5957);
        _SFD_CV_INIT_EML_FCN(1,17,"aFcnTruthTableAction_17",5957,-1,6170);
        _SFD_CV_INIT_EML_FCN(1,18,"aFcnTruthTableAction_18",6170,-1,6385);
        _SFD_CV_INIT_EML_FCN(1,19,"aFcnTruthTableAction_19",6385,-1,6599);
        _SFD_CV_INIT_EML_FCN(1,20,"aFcnTruthTableAction_20",6599,-1,6812);
        _SFD_CV_INIT_EML_FCN(1,21,"aFcnTruthTableAction_21",6812,-1,7029);
        _SFD_CV_INIT_EML_FCN(1,22,"aFcnTruthTableAction_22",7029,-1,7248);
        _SFD_CV_INIT_EML_FCN(1,23,"aFcnTruthTableAction_23",7248,-1,7469);
        _SFD_CV_INIT_EML_FCN(1,24,"aFcnTruthTableAction_24",7469,-1,7692);
        _SFD_CV_INIT_EML_FCN(1,25,"aFcnTruthTableAction_25",7692,-1,7858);
        _SFD_CV_INIT_EML_FCN(1,26,"aFcnTruthTableAction_26",7858,-1,8155);
        _SFD_CV_INIT_EML_IF(1,1,0,1576,1606,1637,2808);
        _SFD_CV_INIT_EML_IF(1,1,1,1637,1671,1702,2808);
        _SFD_CV_INIT_EML_IF(1,1,2,1702,1736,1767,2808);
        _SFD_CV_INIT_EML_IF(1,1,3,1767,1801,1832,2808);
        _SFD_CV_INIT_EML_IF(1,1,4,1832,1866,1897,2808);
        _SFD_CV_INIT_EML_IF(1,1,5,1897,1931,1962,2808);
        _SFD_CV_INIT_EML_IF(1,1,6,1962,1996,2027,2808);
        _SFD_CV_INIT_EML_IF(1,1,7,2027,2061,2092,2808);
        _SFD_CV_INIT_EML_IF(1,1,8,2092,2126,2157,2808);
        _SFD_CV_INIT_EML_IF(1,1,9,2157,2192,2224,2808);
        _SFD_CV_INIT_EML_IF(1,1,10,2224,2259,2291,2808);
        _SFD_CV_INIT_EML_IF(1,1,11,2291,2326,2358,2808);
        _SFD_CV_INIT_EML_IF(1,1,12,2358,2393,2425,2808);
        _SFD_CV_INIT_EML_IF(1,1,13,2425,2460,2492,2808);
        _SFD_CV_INIT_EML_IF(1,1,14,2492,2527,2559,2808);
        _SFD_CV_INIT_EML_IF(1,1,15,2559,2594,2626,2808);
        _SFD_CV_INIT_EML_IF(1,1,16,2626,2661,2693,2808);
        _SFD_CV_INIT_EML_IF(1,1,17,2693,2728,2760,2808);
        _SFD_CV_INIT_EML(3,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"boredPoseS",0,-1,2805);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",2805,-1,2977);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",2977,-1,3140);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",3140,-1,3308);
        _SFD_CV_INIT_EML_FCN(3,4,"aFcnTruthTableAction_4",3308,-1,3478);
        _SFD_CV_INIT_EML_FCN(3,5,"aFcnTruthTableAction_5",3478,-1,3648);
        _SFD_CV_INIT_EML_FCN(3,6,"aFcnTruthTableAction_6",3648,-1,3830);
        _SFD_CV_INIT_EML_FCN(3,7,"aFcnTruthTableAction_7",3830,-1,4010);
        _SFD_CV_INIT_EML_FCN(3,8,"aFcnTruthTableAction_8",4010,-1,4180);
        _SFD_CV_INIT_EML_FCN(3,9,"aFcnTruthTableAction_9",4180,-1,4348);
        _SFD_CV_INIT_EML_FCN(3,10,"aFcnTruthTableAction_10",4348,-1,4518);
        _SFD_CV_INIT_EML_FCN(3,11,"aFcnTruthTableAction_11",4518,-1,4685);
        _SFD_CV_INIT_EML_IF(3,1,0,1577,1607,1638,2803);
        _SFD_CV_INIT_EML_IF(3,1,1,1638,1672,1703,2803);
        _SFD_CV_INIT_EML_IF(3,1,2,1703,1737,1768,2803);
        _SFD_CV_INIT_EML_IF(3,1,3,1768,1802,1833,2803);
        _SFD_CV_INIT_EML_IF(3,1,4,1833,1867,1898,2803);
        _SFD_CV_INIT_EML_IF(3,1,5,1898,1932,1964,2803);
        _SFD_CV_INIT_EML_IF(3,1,6,1964,1998,2029,2803);
        _SFD_CV_INIT_EML_IF(3,1,7,2029,2063,2094,2803);
        _SFD_CV_INIT_EML_IF(3,1,8,2094,2128,2159,2803);
        _SFD_CV_INIT_EML_IF(3,1,9,2159,2194,2226,2803);
        _SFD_CV_INIT_EML_IF(3,1,10,2226,2261,2293,2803);
        _SFD_CV_INIT_EML_IF(3,1,11,2293,2328,2359,2803);
        _SFD_CV_INIT_EML_IF(3,1,12,2359,2394,2425,2803);
        _SFD_CV_INIT_EML_IF(3,1,13,2425,2460,2491,2803);
        _SFD_CV_INIT_EML_IF(3,1,14,2491,2526,2557,2803);
        _SFD_CV_INIT_EML_IF(3,1,15,2557,2592,2623,2803);
        _SFD_CV_INIT_EML_IF(3,1,16,2623,2658,2689,2803);
        _SFD_CV_INIT_EML_IF(3,1,17,2689,2724,2755,2803);
        _SFD_CV_INIT_EML(2,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"boredPose",0,-1,1275);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",1275,-1,1457);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",1457,-1,1640);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1640,-1,1824);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1824,-1,2010);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",2010,-1,2196);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",2196,-1,2387);
        _SFD_CV_INIT_EML_IF(2,1,0,709,739,770,1273);
        _SFD_CV_INIT_EML_IF(2,1,1,770,804,835,1273);
        _SFD_CV_INIT_EML_IF(2,1,2,835,869,900,1273);
        _SFD_CV_INIT_EML_IF(2,1,3,900,934,965,1273);
        _SFD_CV_INIT_EML_IF(2,1,4,965,999,1030,1273);
        _SFD_CV_INIT_EML_IF(2,1,5,1030,1064,1095,1273);
        _SFD_CV_INIT_EML_IF(2,1,6,1095,1129,1160,1273);
        _SFD_CV_INIT_EML_IF(2,1,7,1160,1194,1225,1273);
        _SFD_CV_INIT_EML(5,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"idlePose",0,-1,1353);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",1353,-1,1569);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",1569,-1,1800);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",1800,-1,1935);
        _SFD_CV_INIT_EML_FCN(5,4,"aFcnTruthTableAction_4",1935,-1,2226);
        _SFD_CV_INIT_EML_FCN(5,5,"aFcnTruthTableAction_5",2226,-1,2518);
        _SFD_CV_INIT_EML_FCN(5,6,"aFcnTruthTableAction_6",2518,-1,2812);
        _SFD_CV_INIT_EML_FCN(5,7,"aFcnTruthTableAction_7",2812,-1,3107);
        _SFD_CV_INIT_EML_FCN(5,8,"aFcnTruthTableAction_8",3107,-1,3271);
        _SFD_CV_INIT_EML_IF(5,1,0,787,817,848,1351);
        _SFD_CV_INIT_EML_IF(5,1,1,848,882,913,1351);
        _SFD_CV_INIT_EML_IF(5,1,2,913,947,978,1351);
        _SFD_CV_INIT_EML_IF(5,1,3,978,1012,1043,1351);
        _SFD_CV_INIT_EML_IF(5,1,4,1043,1077,1108,1351);
        _SFD_CV_INIT_EML_IF(5,1,5,1108,1142,1173,1351);
        _SFD_CV_INIT_EML_IF(5,1,6,1173,1207,1238,1351);
        _SFD_CV_INIT_EML_IF(5,1,7,1238,1272,1303,1351);
        _SFD_CV_INIT_EML(6,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"paperPose",0,-1,400);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",400,-1,556);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",556,-1,710);
        _SFD_CV_INIT_EML_IF(6,1,0,224,254,285,398);
        _SFD_CV_INIT_EML_IF(6,1,1,285,319,350,398);
        _SFD_CV_INIT_EML(0,1,10,9,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"EAU",0,-1,1473);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1473,-1,1539);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1539,-1,1590);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1590,-1,1649);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1649,-1,1700);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1700,-1,1752);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",1752,-1,1805);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",1805,-1,1857);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",1857,-1,1911);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",1911,-1,1972);
        _SFD_CV_INIT_EML_IF(0,1,0,842,872,903,1471);
        _SFD_CV_INIT_EML_IF(0,1,1,903,937,968,1471);
        _SFD_CV_INIT_EML_IF(0,1,2,968,1002,1033,1471);
        _SFD_CV_INIT_EML_IF(0,1,3,1033,1067,1098,1471);
        _SFD_CV_INIT_EML_IF(0,1,4,1098,1132,1163,1471);
        _SFD_CV_INIT_EML_IF(0,1,5,1163,1197,1228,1471);
        _SFD_CV_INIT_EML_IF(0,1,6,1228,1262,1293,1471);
        _SFD_CV_INIT_EML_IF(0,1,7,1293,1327,1358,1471);
        _SFD_CV_INIT_EML_IF(0,1,8,1358,1392,1423,1471);
        _SFD_CV_INIT_EML(8,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"scissorsPose",0,-1,409);
        _SFD_CV_INIT_EML_FCN(8,1,"aFcnTruthTableAction_1",409,-1,566);
        _SFD_CV_INIT_EML_FCN(8,2,"aFcnTruthTableAction_2",566,-1,725);
        _SFD_CV_INIT_EML_IF(8,1,0,233,263,294,407);
        _SFD_CV_INIT_EML_IF(8,1,1,294,328,359,407);
        _SFD_CV_INIT_EML(4,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"handPoseSB",0,-1,1083);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",1083,-1,1319);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",1319,-1,1553);
        _SFD_CV_INIT_EML_FCN(4,3,"aFcnTruthTableAction_3",1553,-1,1725);
        _SFD_CV_INIT_EML_FCN(4,4,"aFcnTruthTableAction_4",1725,-1,1894);
        _SFD_CV_INIT_EML_FCN(4,5,"aFcnTruthTableAction_5",1894,-1,2050);
        _SFD_CV_INIT_EML_FCN(4,6,"aFcnTruthTableAction_6",2050,-1,2203);
        _SFD_CV_INIT_EML_IF(4,1,0,647,677,708,1081);
        _SFD_CV_INIT_EML_IF(4,1,1,708,742,773,1081);
        _SFD_CV_INIT_EML_IF(4,1,2,773,807,838,1081);
        _SFD_CV_INIT_EML_IF(4,1,3,838,872,903,1081);
        _SFD_CV_INIT_EML_IF(4,1,4,903,937,968,1081);
        _SFD_CV_INIT_EML_IF(4,1,5,968,1002,1033,1081);
        _SFD_CV_INIT_EML(7,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"rockPose",0,-1,396);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",396,-1,557);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",557,-1,718);
        _SFD_CV_INIT_EML_IF(7,1,0,220,250,281,394);
        _SFD_CV_INIT_EML_IF(7,1,1,281,315,346,394);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(44,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(46,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(36,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(37,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(38,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(39,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(40,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(41,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(42,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(43,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(44,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(45,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(46,(void *)(NULL));

        {
          real_T *c1_gameState;
          real_T *c1_inputUser;
          real_T *c1_bradHand;
          real_T *c1_userHand;
          real_T *c1_win;
          real_T *c1_bWinT;
          real_T *c1_uWinT;
          real_T *c1_round;
          real_T (*c1_t)[256];
          c1_t = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
          c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_win);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_temp);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_diff);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_uHand);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_bHand);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c1_smileN);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c1_smileYN);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c1_bored);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c1_BOREDOMT);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c1_randomG);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c1_randomP);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c1_pose);
          _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c1_b);
          _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c1_r);
          _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c1_p);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c1_s);
          _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c1_randomD);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c1_wristRotate);
          _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c1_randomH);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_round);
          _SFD_SET_DATA_VALUE_PTR(26U, *c1_t);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _untitled1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "iQWTVideKQRkzmwrLVYsPC";
}

static void sf_opaque_initialize_c1_untitled1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_untitled1InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_untitled1((SFc1_untitled1InstanceStruct*)
    chartInstanceVar);
  initialize_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_untitled1(void *chartInstanceVar)
{
  enable_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_untitled1(void *chartInstanceVar)
{
  disable_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_untitled1(void *chartInstanceVar)
{
  sf_gateway_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_untitled1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_untitled1((SFc1_untitled1InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_untitled1();/* state var info */
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

extern void sf_internal_set_sim_state_c1_untitled1(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_untitled1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_untitled1((SFc1_untitled1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_untitled1(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_untitled1(S);
}

static void sf_opaque_set_sim_state_c1_untitled1(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_untitled1(S, st);
}

static void sf_opaque_terminate_c1_untitled1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_untitled1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled1_optimization_info();
    }

    finalize_c1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_untitled1((SFc1_untitled1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_untitled1(SimStruct *S)
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
    initialize_params_c1_untitled1((SFc1_untitled1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_untitled1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,1,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,10);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=10; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(621412695U));
  ssSetChecksum1(S,(1084025457U));
  ssSetChecksum2(S,(3183680734U));
  ssSetChecksum3(S,(3297599335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_untitled1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_untitled1(SimStruct *S)
{
  SFc1_untitled1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_untitled1InstanceStruct *)utMalloc(sizeof
    (SFc1_untitled1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_untitled1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_untitled1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_untitled1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_untitled1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_untitled1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_untitled1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_untitled1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_untitled1;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_untitled1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_untitled1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_untitled1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_untitled1;
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

void c1_untitled1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_untitled1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_untitled1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_untitled1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_untitled1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
