/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testRPSsmile_Glove_sfun.h"
#include "c1_testRPSsmile_Glove.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testRPSsmile_Glove_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_BradLeanForward          ((uint8_T)1U)
#define c1_IN_smile                    ((uint8_T)2U)
#define c1_IN_start                    ((uint8_T)3U)
#define c1_IN_stateBradWin             ((uint8_T)4U)
#define c1_IN_stateCompare             ((uint8_T)5U)
#define c1_IN_stateNoWin               ((uint8_T)6U)
#define c1_IN_statePlayHand            ((uint8_T)7U)
#define c1_IN_stateReadUserHand        ((uint8_T)8U)
#define c1_IN_stateShowGo              ((uint8_T)9U)
#define c1_IN_stateShowHands           ((uint8_T)10U)
#define c1_IN_stateShowReady           ((uint8_T)11U)
#define c1_IN_stateShowResult          ((uint8_T)12U)
#define c1_IN_stateUserWin             ((uint8_T)13U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c1_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_e_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[12];

/* Function Declarations */
static void initialize_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void initialize_params_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void enable_c1_testRPSsmile_Glove(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance);
static void disable_c1_testRPSsmile_Glove(SFc1_testRPSsmile_GloveInstanceStruct *
  chartInstance);
static void c1_update_debugger_state_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void set_sim_state_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void finalize_c1_testRPSsmile_Glove(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance);
static void sf_gateway_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_chartstep_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void initSimStructsc1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_start(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_BradLeanForward(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance);
static void c1_smile(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_stateShowGo(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_stateReadUserHand(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance);
static void c1_stateCompare(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_stateBradWin(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_stateNoWin(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256]);
static void c1_b_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256]);
static void c1_c_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256]);
static void c1_d_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256]);
static void c1_e_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256]);
static real_T c1_rand(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static real_T c1_eml_rand(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void c1_eml_rand_mt19937ar(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_d_state[625]);
static void c1_twister_state_vector(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625]);
static void c1_b_eml_rand_mt19937ar(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T
  *c1_r);
static void c1_eml_error(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_b_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_bmlID, const char_T *c1_identifier);
static real_T c1_c_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_d_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256]);
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
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_idlePose(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_bmlID, real_T c1_poseBML[256]);
static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_start, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint32_T c1_i_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_b_method, const char_T *c1_identifier);
static uint32_T c1_j_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_k_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier);
static uint32_T c1_l_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_m_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  uint32_T c1_y[625]);
static void c1_n_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[625]);
static void c1_o_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  uint32_T c1_y[2]);
static void c1_p_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[2]);
static const mxArray *c1_q_emlrt_marshallIn
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_r_emlrt_marshallIn
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn(SFc1_testRPSsmile_GloveInstanceStruct *
  chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber);
static void c1_b_twister_state_vector(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed);
static real_T c1_c_eml_rand_mt19937ar(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_d_state[625]);
static void init_dsm_address_info(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_method_not_empty = false;
  chartInstance->c1_state_not_empty = false;
  chartInstance->c1_b_state_not_empty = false;
  chartInstance->c1_c_state_not_empty = false;
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_BradLeanForward = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_smile = 0U;
  chartInstance->c1_tp_start = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateBradWin = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateCompare = 0U;
  chartInstance->c1_tp_stateNoWin = 0U;
  chartInstance->c1_tp_statePlayHand = 0U;
  chartInstance->c1_tp_stateReadUserHand = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateShowGo = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateShowHands = 0U;
  chartInstance->c1_tp_stateShowReady = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateShowResult = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateUserWin = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_is_active_c1_testRPSsmile_Glove = 0U;
  chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_testRPSsmile_Glove(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void disable_c1_testRPSsmile_Glove(SFc1_testRPSsmile_GloveInstanceStruct *
  chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static void c1_update_debugger_state_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_testRPSsmile_Glove == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_BradLeanForward) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_smile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_statePlayHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
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
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  uint32_T c1_k_hoistedGlobal;
  uint32_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  uint32_T c1_l_hoistedGlobal;
  uint32_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  int32_T c1_i0;
  uint32_T c1_m_u[625];
  const mxArray *c1_n_y = NULL;
  int32_T c1_i1;
  uint32_T c1_n_u[2];
  const mxArray *c1_o_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  uint8_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  uint8_T c1_n_hoistedGlobal;
  uint8_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  uint8_T c1_o_hoistedGlobal;
  uint8_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(17, 1), false);
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
  c1_d_hoistedGlobal = *c1_uWinT;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_userHand;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_win;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_bHand;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_diff;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = chartInstance->c1_temp;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_uHand;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = chartInstance->c1_method;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = chartInstance->c1_state;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  if (!chartInstance->c1_state_not_empty) {
    sf_mex_assign(&c1_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c1_y, 11, c1_m_y);
  for (c1_i0 = 0; c1_i0 < 625; c1_i0++) {
    c1_m_u[c1_i0] = chartInstance->c1_c_state[c1_i0];
  }

  c1_n_y = NULL;
  if (!chartInstance->c1_c_state_not_empty) {
    sf_mex_assign(&c1_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_m_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c1_y, 12, c1_n_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_n_u[c1_i1] = chartInstance->c1_b_state[c1_i1];
  }

  c1_o_y = NULL;
  if (!chartInstance->c1_b_state_not_empty) {
    sf_mex_assign(&c1_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_n_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_m_hoistedGlobal = chartInstance->c1_is_active_c1_testRPSsmile_Glove;
  c1_o_u = c1_m_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_n_hoistedGlobal = chartInstance->c1_is_c1_testRPSsmile_Glove;
  c1_p_u = c1_n_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_o_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_q_u = c1_o_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  uint32_T c1_uv0[625];
  int32_T c1_i2;
  uint32_T c1_uv1[2];
  int32_T c1_i3;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
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
  *c1_uWinT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "uWinT");
  *c1_userHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "userHand");
  *c1_win = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    5)), "win");
  chartInstance->c1_bHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "bHand");
  chartInstance->c1_diff = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 7)), "diff");
  chartInstance->c1_temp = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "temp");
  chartInstance->c1_uHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "uHand");
  chartInstance->c1_method = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 10)), "method");
  chartInstance->c1_state = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "state");
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 12)),
                        "state", c1_uv0);
  for (c1_i2 = 0; c1_i2 < 625; c1_i2++) {
    chartInstance->c1_c_state[c1_i2] = c1_uv0[c1_i2];
  }

  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 13)),
                        "state", c1_uv1);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    chartInstance->c1_b_state[c1_i3] = c1_uv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_testRPSsmile_Glove = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 14)),
     "is_active_c1_testRPSsmile_Glove");
  chartInstance->c1_is_c1_testRPSsmile_Glove = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 15)),
     "is_c1_testRPSsmile_Glove");
  chartInstance->c1_temporalCounter_i1 = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 16)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 17)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_testRPSsmile_Glove(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_BradLeanForward) {
      chartInstance->c1_tp_BradLeanForward = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_BradLeanForward = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_smile) {
      chartInstance->c1_tp_smile = 1U;
    } else {
      chartInstance->c1_tp_smile = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_start) {
      chartInstance->c1_tp_start = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_start = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateBradWin) {
      chartInstance->c1_tp_stateBradWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateBradWin = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateCompare) {
      chartInstance->c1_tp_stateCompare = 1U;
    } else {
      chartInstance->c1_tp_stateCompare = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateNoWin) {
      chartInstance->c1_tp_stateNoWin = 1U;
    } else {
      chartInstance->c1_tp_stateNoWin = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_statePlayHand) {
      chartInstance->c1_tp_statePlayHand = 1U;
    } else {
      chartInstance->c1_tp_statePlayHand = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateReadUserHand) {
      chartInstance->c1_tp_stateReadUserHand = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowGo) {
      chartInstance->c1_tp_stateShowGo = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateShowGo = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowHands) {
      chartInstance->c1_tp_stateShowHands = 1U;
    } else {
      chartInstance->c1_tp_stateShowHands = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowReady) {
      chartInstance->c1_tp_stateShowReady = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateShowReady = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateShowResult) {
      chartInstance->c1_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateShowResult = 0U;
    }

    if (chartInstance->c1_is_c1_testRPSsmile_Glove == c1_IN_stateUserWin) {
      chartInstance->c1_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateUserWin = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_testRPSsmile_Glove(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  real_T *c1_gameState;
  real_T *c1_inputUser;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_testRPSsmile_Glove(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_temporalCounter_i1 < 63U) {
    chartInstance->c1_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c1_temporalCounter_i1 + 1);
  }

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
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_testRPSsmile_Glove(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testRPSsmile_GloveMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv0[256];
  int32_T c1_i4;
  real_T c1_arg[256];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_dv1[256];
  int32_T c1_i8;
  real_T c1_b_arg[256];
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_d_x;
  real_T c1_e_x;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_dv2[256];
  int32_T c1_i12;
  real_T c1_c_arg[256];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 0.0;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_d_out;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  real_T *c1_gameState;
  real_T *c1_win;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_inputUser;
  real_T (*c1_d_arg)[256];
  boolean_T guard1 = false;
  c1_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_testRPSsmile_Glove == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_testRPSsmile_Glove = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_start = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_j_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_uHand = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    *c1_userHand = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
    *c1_bradHand = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
    *c1_win = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
    *c1_gameState = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    *c1_uWinT = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
    *c1_bWinT = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
    c1_idlePose(chartInstance, 1.0, c1_dv0);
    for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
      c1_arg[c1_i4] = c1_dv0[c1_i4];
    }

    for (c1_i5 = 0; c1_i5 < 256; c1_i5++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i5], 13U);
    }

    _SFD_SET_DATA_VALUE_PTR(13U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    for (c1_i6 = 0; c1_i6 < 256; c1_i6++) {
      (*c1_d_arg)[c1_i6] = c1_arg[c1_i6];
    }

    for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
      _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i7], 13U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(13U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    c1_idlePose(chartInstance, 3.0, c1_dv1);
    for (c1_i8 = 0; c1_i8 < 256; c1_i8++) {
      c1_b_arg[c1_i8] = c1_dv1[c1_i8];
    }

    for (c1_i9 = 0; c1_i9 < 256; c1_i9++) {
      _SFD_DATA_RANGE_CHECK(c1_b_arg[c1_i9], 13U);
    }

    _SFD_SET_DATA_VALUE_PTR(13U, c1_b_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_b_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    for (c1_i10 = 0; c1_i10 < 256; c1_i10++) {
      (*c1_d_arg)[c1_i10] = c1_b_arg[c1_i10];
    }

    for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
      _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i11], 13U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(13U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c1_is_c1_testRPSsmile_Glove) {
     case c1_IN_BradLeanForward:
      CV_CHART_EVAL(0, 0, 1);
      c1_BradLeanForward(chartInstance);
      break;

     case c1_IN_smile:
      CV_CHART_EVAL(0, 0, 2);
      c1_smile(chartInstance);
      break;

     case c1_IN_start:
      CV_CHART_EVAL(0, 0, 3);
      c1_start(chartInstance);
      break;

     case c1_IN_stateBradWin:
      CV_CHART_EVAL(0, 0, 4);
      c1_stateBradWin(chartInstance);
      break;

     case c1_IN_stateCompare:
      CV_CHART_EVAL(0, 0, 5);
      c1_stateCompare(chartInstance);
      break;

     case c1_IN_stateNoWin:
      CV_CHART_EVAL(0, 0, 6);
      c1_stateNoWin(chartInstance);
      break;

     case c1_IN_statePlayHand:
      CV_CHART_EVAL(0, 0, 7);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_statePlayHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateReadUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateReadUserHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_o_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_uHand = *c1_inputUser;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_stateReadUserHand:
      CV_CHART_EVAL(0, 0, 8);
      c1_stateReadUserHand(chartInstance);
      break;

     case c1_IN_stateShowGo:
      CV_CHART_EVAL(0, 0, 9);
      c1_stateShowGo(chartInstance);
      break;

     case c1_IN_stateShowHands:
      CV_CHART_EVAL(0, 0, 10);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateShowHands = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateCompare;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateCompare = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_r_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
      chartInstance->c1_temp = chartInstance->c1_uHand - chartInstance->c1_bHand;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_temp, 5U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
      c1_hoistedGlobal = chartInstance->c1_temp;
      c1_b_hoistedGlobal = chartInstance->c1_temp;
      c1_A = c1_b_hoistedGlobal;
      c1_x = c1_A;
      c1_b_x = c1_x;
      c1_c_x = c1_b_x;
      c1_y = c1_c_x / 3.0;
      c1_d_x = c1_y;
      c1_e_x = c1_d_x;
      c1_e_x = muDoubleScalarFloor(c1_e_x);
      chartInstance->c1_diff = c1_hoistedGlobal - 3.0 * c1_e_x;
      c1_updateDataWrittenToVector(chartInstance, 4U);
      c1_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff, 6U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_stateShowReady:
      CV_CHART_EVAL(0, 0, 11);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_y_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(6, 0, 0, chartInstance->c1_temporalCounter_i1 >= 30)) {
        if (CV_EML_COND(6, 0, 1, chartInstance->c1_uHand != 3.0)) {
          CV_EML_MCDC(6, 0, 0, true);
          CV_EML_IF(6, 0, 0, true);
          c1_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(6, 0, 0, false);
        CV_EML_IF(6, 0, 0, false);
        c1_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateShowReady = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_BradLeanForward;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_BradLeanForward = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_l_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_idlePose(chartInstance, 2.0, c1_dv2);
        for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
          c1_c_arg[c1_i12] = c1_dv2[c1_i12];
        }

        for (c1_i13 = 0; c1_i13 < 256; c1_i13++) {
          _SFD_DATA_RANGE_CHECK(c1_c_arg[c1_i13], 13U);
        }

        _SFD_SET_DATA_VALUE_PTR(13U, c1_c_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_c_arg, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c1_sfEvent);
        for (c1_i14 = 0; c1_i14 < 256; c1_i14++) {
          (*c1_d_arg)[c1_i14] = c1_c_arg[c1_i14];
        }

        for (c1_i15 = 0; c1_i15 < 256; c1_i15++) {
          _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i15], 13U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(13U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_w_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
        c1_b_out = CV_EML_IF(8, 0, 0, chartInstance->c1_uHand == 3.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateShowReady = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowReady;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i1 = 0U;
          chartInstance->c1_tp_stateShowReady = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          *c1_bradHand = 3.0;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
          *c1_userHand = 3.0;
          c1_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
          *c1_gameState = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
          *c1_win = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                       chartInstance->c1_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_stateShowResult:
      CV_CHART_EVAL(0, 0, 12);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_x_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_c_out = CV_EML_IF(15, 0, 0, chartInstance->c1_temporalCounter_i1 >= 20);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_stateShowReady = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        *c1_bradHand = 3.0;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
        *c1_userHand = 3.0;
        c1_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
        *c1_gameState = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
        *c1_win = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_stateUserWin:
      CV_CHART_EVAL(0, 0, 13);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ib_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_d_out = CV_EML_IF(12, 0, 0, chartInstance->c1_temporalCounter_i1 >= 50);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateUserWin = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowResult;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_stateShowResult = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_testRPSsmile_Glove
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_start(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_gameState;
  real_T *c1_win;
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_v_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(3, 0, 0, chartInstance->c1_temporalCounter_i1 >= 20);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_start = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateShowReady = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_k_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    *c1_bradHand = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
    *c1_userHand = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
    *c1_gameState = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    *c1_win = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
}

static void c1_BradLeanForward(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv3[256];
  int32_T c1_i16;
  real_T c1_arg[256];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ab_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(16, 0, 0, chartInstance->c1_temporalCounter_i1 >= 10);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_BradLeanForward = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_smile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_smile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_m_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_idlePose(chartInstance, 4.0, c1_dv3);
    for (c1_i16 = 0; c1_i16 < 256; c1_i16++) {
      c1_arg[c1_i16] = c1_dv3[c1_i16];
    }

    for (c1_i17 = 0; c1_i17 < 256; c1_i17++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i17], 13U);
    }

    _SFD_SET_DATA_VALUE_PTR(13U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    for (c1_i18 = 0; c1_i18 < 256; c1_i18++) {
      (*c1_b_arg)[c1_i18] = c1_arg[c1_i18];
    }

    for (c1_i19 = 0; c1_i19 < 256; c1_i19++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i19], 13U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(13U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void c1_smile(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T *c1_gameState;
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_smile = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowGo;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateShowGo = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_n_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  *c1_gameState = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
}

static void c1_stateShowGo(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_hoistedGlobal;
  real_T c1_bmlID;
  uint32_T c1_c_debug_family_var_map[7];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  real_T c1_c_nargin = 1.0;
  real_T c1_c_nargout = 1.0;
  real_T c1_poseBML[256];
  real_T c1_dv4[256];
  int32_T c1_i20;
  int32_T c1_i21;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  uint32_T c1_d_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[94];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[94];
  real_T c1_d_nargin = 1.0;
  real_T c1_d_nargout = 1.0;
  real_T c1_myarr256[256];
  int32_T c1_i24;
  static char_T c1_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i25;
  static real_T c1_dv5[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i33;
  real_T c1_arg[256];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_bb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(5, 0, 0, chartInstance->c1_temporalCounter_i1 >= 10);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_statePlayHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePlayHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_p_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_r = c1_rand(chartInstance);
    c1_x = c1_r * 3.0;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarFloor(c1_b_x);
    c1_r = c1_b_x;
    chartInstance->c1_bHand = c1_r;
    c1_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_bHand, 8U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    c1_hoistedGlobal = chartInstance->c1_bHand;
    c1_bmlID = c1_hoistedGlobal;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_debug_family_names,
      c1_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
      c1_c_sf_marshallOut, c1_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
      c1_c_sf_marshallOut, c1_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
      c1_c_sf_marshallOut, c1_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 3U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 4U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 5U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 6U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    CV_EML_FCN(1, 0);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 3);
    c1_aVarTruthTableCondition_1 = false;
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 4);
    c1_aVarTruthTableCondition_2 = false;
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 5);
    c1_aVarTruthTableCondition_3 = false;
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 10);
    c1_aVarTruthTableCondition_1 = (c1_bmlID == 0.0);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 14);
    c1_aVarTruthTableCondition_2 = (c1_bmlID == 1.0);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 18);
    c1_aVarTruthTableCondition_3 = (c1_bmlID == 2.0);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 20);
    if (CV_EML_IF(1, 1, 0, c1_aVarTruthTableCondition_1)) {
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 21);
      CV_EML_FCN(1, 1);
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 34);
      c1_encStr2Arr(chartInstance, c1_dv4);
      for (c1_i20 = 0; c1_i20 < 256; c1_i20++) {
        c1_poseBML[c1_i20] = c1_dv4[c1_i20];
      }

      c1_updateDataWrittenToVector(chartInstance, 10U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i21 = 0; c1_i21 < 256; c1_i21++) {
        c1_u[c1_i21] = c1_poseBML[c1_i21];
      }

      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -34);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 22);
      if (CV_EML_IF(1, 1, 1, c1_aVarTruthTableCondition_2)) {
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 23);
        CV_EML_FCN(1, 2);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 40);
        c1_b_encStr2Arr(chartInstance, c1_dv4);
        for (c1_i22 = 0; c1_i22 < 256; c1_i22++) {
          c1_poseBML[c1_i22] = c1_dv4[c1_i22];
        }

        c1_updateDataWrittenToVector(chartInstance, 10U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i23 = 0; c1_i23 < 256; c1_i23++) {
          c1_b_u[c1_i23] = c1_poseBML[c1_i23];
        }

        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_b_y);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -40);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 24);
        if (CV_EML_IF(1, 1, 2, c1_aVarTruthTableCondition_3)) {
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 25);
          CV_EML_FCN(1, 3);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 46);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_d_debug_family_names,
            c1_d_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_j_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
            c1_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_i_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 6U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 7U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
            c1_d_sf_marshallOut, c1_d_sf_marshallIn);
          for (c1_i24 = 0; c1_i24 < 94; c1_i24++) {
            c1_mystr[c1_i24] = c1_cv0[c1_i24];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
          c1_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
          for (c1_i25 = 0; c1_i25 < 94; c1_i25++) {
            c1_arr[c1_i25] = c1_dv5[c1_i25];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
          c1_ss = 94.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
          c1_padsize = c1_maxarrsize - c1_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
          for (c1_i26 = 0; c1_i26 < 256; c1_i26++) {
            c1_tt[c1_i26] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
          for (c1_i27 = 0; c1_i27 < 94; c1_i27++) {
            c1_tt[c1_i27] = c1_arr[c1_i27];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
          for (c1_i28 = 0; c1_i28 < 256; c1_i28++) {
            c1_myarr256[c1_i28] = c1_tt[c1_i28];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c1_i29 = 0; c1_i29 < 256; c1_i29++) {
            c1_poseBML[c1_i29] = c1_myarr256[c1_i29];
          }

          c1_updateDataWrittenToVector(chartInstance, 10U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i30 = 0; c1_i30 < 256; c1_i30++) {
            c1_c_u[c1_i30] = c1_poseBML[c1_i30];
          }

          c1_c_y = NULL;
          sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_c_y);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -46);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 27);
          CV_EML_FCN(1, 1);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 34);
          c1_encStr2Arr(chartInstance, c1_dv4);
          for (c1_i31 = 0; c1_i31 < 256; c1_i31++) {
            c1_poseBML[c1_i31] = c1_dv4[c1_i31];
          }

          c1_updateDataWrittenToVector(chartInstance, 10U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i32 = 0; c1_i32 < 256; c1_i32++) {
            c1_d_u[c1_i32] = c1_poseBML[c1_i32];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -34);
        }
      }
    }

    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -27);
    _SFD_SYMBOL_SCOPE_POP();
    for (c1_i33 = 0; c1_i33 < 256; c1_i33++) {
      c1_arg[c1_i33] = c1_poseBML[c1_i33];
    }

    for (c1_i34 = 0; c1_i34 < 256; c1_i34++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i34], 13U);
    }

    _SFD_SET_DATA_VALUE_PTR(13U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    for (c1_i35 = 0; c1_i35 < 256; c1_i35++) {
      (*c1_b_arg)[c1_i35] = c1_arg[c1_i35];
    }

    for (c1_i36 = 0; c1_i36 < 256; c1_i36++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i36], 13U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(13U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
}

static void c1_stateReadUserHand(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T *c1_inputUser;
  real_T *c1_gameState;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  boolean_T guard1 = false;
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_db_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(4, 0, 0, chartInstance->c1_temporalCounter_i1 >= 10)) {
    if (CV_EML_COND(4, 0, 1, chartInstance->c1_uHand != 3.0)) {
      CV_EML_MCDC(4, 0, 0, true);
      CV_EML_IF(4, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(4, 0, 0, false);
    CV_EML_IF(4, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowHands = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_q_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    *c1_gameState = 2.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    *c1_bradHand = chartInstance->c1_bHand;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    *c1_userHand = chartInstance->c1_uHand;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_cb_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    c1_b_out = CV_EML_IF(0, 0, 0, chartInstance->c1_uHand == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateReadUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateReadUserHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_o_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_uHand = *c1_inputUser;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
}

static void c1_stateCompare(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T *c1_win;
  real_T *c1_uWinT;
  real_T *c1_bWinT;
  boolean_T guard1 = false;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
  c1_out = CV_EML_IF(14, 0, 0, chartInstance->c1_diff == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateCompare = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateBradWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateBradWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_t_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    *c1_win = 2.0;
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 8U, 9U);
    (*c1_bWinT)++;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_eb_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
    c1_b_out = CV_EML_IF(2, 0, 0, chartInstance->c1_diff == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateUserWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateUserWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_s_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      *c1_win = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 10U);
      (*c1_uWinT)++;
      c1_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_gb_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
      guard1 = false;
      if (CV_EML_COND(10, 0, 0, chartInstance->c1_diff != 1.0)) {
        if (CV_EML_COND(10, 0, 1, chartInstance->c1_diff != 2.0)) {
          CV_EML_MCDC(10, 0, 0, true);
          CV_EML_IF(10, 0, 0, true);
          c1_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(10, 0, 0, false);
        CV_EML_IF(10, 0, 0, false);
        c1_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateNoWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateNoWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_u_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        *c1_win = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c1_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
}

static void c1_stateBradWin(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_hb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(13, 0, 0, chartInstance->c1_temporalCounter_i1 >= 50);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateBradWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateShowResult = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
}

static void c1_stateNoWin(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateNoWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_c1_testRPSsmile_Glove = c1_IN_stateShowResult;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateShowResult = 1U;
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
}

static void c1_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[86];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[86];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i37;
  static char_T c1_cv1[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c1_i38;
  static real_T c1_dv6[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i37 = 0; c1_i37 < 86; c1_i37++) {
    c1_mystr[c1_i37] = c1_cv1[c1_i37];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i38 = 0; c1_i38 < 86; c1_i38++) {
    c1_arr[c1_i38] = c1_dv6[c1_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i39 = 0; c1_i39 < 256; c1_i39++) {
    c1_tt[c1_i39] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i40 = 0; c1_i40 < 86; c1_i40++) {
    c1_tt[c1_i40] = c1_arr[c1_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i41 = 0; c1_i41 < 256; c1_i41++) {
    c1_myarr256[c1_i41] = c1_tt[c1_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_b_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[90];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[90];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i42;
  static char_T c1_cv2[90] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'M', 'i',
    'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c1_i43;
  static real_T c1_dv7[90] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i42 = 0; c1_i42 < 90; c1_i42++) {
    c1_mystr[c1_i42] = c1_cv2[c1_i42];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i43 = 0; c1_i43 < 90; c1_i43++) {
    c1_arr[c1_i43] = c1_dv7[c1_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 90.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i44 = 0; c1_i44 < 256; c1_i44++) {
    c1_tt[c1_i44] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i45 = 0; c1_i45 < 90; c1_i45++) {
    c1_tt[c1_i45] = c1_arr[c1_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i46 = 0; c1_i46 < 256; c1_i46++) {
    c1_myarr256[c1_i46] = c1_tt[c1_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_c_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[147];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[147];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i47;
  static char_T c1_cv3[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', 'g',
    'a', 'z', 'e', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'C', 'H', 'E', 'S', 'T', ' ', 'B', 'A', 'C',
    'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i48;
  static real_T c1_dv8[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 67.0, 72.0, 69.0, 83.0, 84.0, 32.0,
    66.0, 65.0, 67.0, 75.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_f_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i47 = 0; c1_i47 < 147; c1_i47++) {
    c1_mystr[c1_i47] = c1_cv3[c1_i47];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i48 = 0; c1_i48 < 147; c1_i48++) {
    c1_arr[c1_i48] = c1_dv8[c1_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i49 = 0; c1_i49 < 256; c1_i49++) {
    c1_tt[c1_i49] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i50 = 0; c1_i50 < 147; c1_i50++) {
    c1_tt[c1_i50] = c1_arr[c1_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i51 = 0; c1_i51 < 256; c1_i51++) {
    c1_myarr256[c1_i51] = c1_tt[c1_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_d_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[164];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[164];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i52;
  static char_T c1_cv4[164] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', 'g',
    'a', 'z', 'e', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"',
    'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'C', 'H', 'E', 'S', 'T', ' ', 'B',
    'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i53;
  static real_T c1_dv9[164] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0,
    100.0, 105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0,
    68.0, 79.0, 87.0, 78.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    67.0, 72.0, 69.0, 83.0, 84.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_g_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i52 = 0; c1_i52 < 164; c1_i52++) {
    c1_mystr[c1_i52] = c1_cv4[c1_i52];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i53 = 0; c1_i53 < 164; c1_i53++) {
    c1_arr[c1_i53] = c1_dv9[c1_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i54 = 0; c1_i54 < 256; c1_i54++) {
    c1_tt[c1_i54] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i55 = 0; c1_i55 < 164; c1_i55++) {
    c1_tt[c1_i55] = c1_arr[c1_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i56 = 0; c1_i56 < 256; c1_i56++) {
    c1_myarr256[c1_i56] = c1_tt[c1_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_e_encStr2Arr(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[181];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[181];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i57;
  static char_T c1_cv5[181] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '6', '\"', ' ',
    ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=',
    '\"', '2', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"',
    '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F',
    'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 'a', 'u', '=', '\"', '1', '2', '\"', ' ', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '\"', ' ',
    'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i58;
  static real_T c1_dv10[181] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0,
    34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 34.0, 32.0, 97.0, 109.0, 111.0,
    117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0,
    99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0,
    83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 50.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0,
    61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_i_debug_family_names,
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
  for (c1_i57 = 0; c1_i57 < 181; c1_i57++) {
    c1_mystr[c1_i57] = c1_cv5[c1_i57];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i58 = 0; c1_i58 < 181; c1_i58++) {
    c1_arr[c1_i58] = c1_dv10[c1_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 181.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i59 = 0; c1_i59 < 256; c1_i59++) {
    c1_tt[c1_i59] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i60 = 0; c1_i60 < 181; c1_i60++) {
    c1_tt[c1_i60] = c1_arr[c1_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i61 = 0; c1_i61 < 256; c1_i61++) {
    c1_myarr256[c1_i61] = c1_tt[c1_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_rand(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  return c1_eml_rand(chartInstance);
}

static real_T c1_eml_rand(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  real_T c1_r;
  uint32_T c1_hoistedGlobal;
  uint32_T c1_d_state;
  uint32_T c1_e_state;
  uint32_T c1_s;
  uint32_T c1_u0;
  uint32_T c1_hi;
  uint32_T c1_lo;
  uint32_T c1_test1;
  uint32_T c1_test2;
  uint32_T c1_f_state;
  real_T c1_b_r;
  real_T c1_d0;
  int32_T c1_i62;
  uint32_T c1_icng;
  uint32_T c1_jsr;
  uint32_T c1_u1;
  uint32_T c1_u2;
  uint32_T c1_ui;
  uint32_T c1_b_ui;
  real_T c1_c_r;
  real_T c1_d1;
  uint32_T c1_uv2[625];
  int32_T c1_i63;
  real_T c1_d2;
  if (!chartInstance->c1_method_not_empty) {
    chartInstance->c1_method = 7U;
    chartInstance->c1_method_not_empty = true;
  }

  if (chartInstance->c1_method == 4U) {
    if (!chartInstance->c1_state_not_empty) {
      chartInstance->c1_state = 1144108930U;
      chartInstance->c1_state_not_empty = true;
    }

    c1_hoistedGlobal = chartInstance->c1_state;
    c1_d_state = c1_hoistedGlobal;
    c1_e_state = c1_d_state;
    c1_s = c1_e_state;
    c1_u0 = 127773U;
    if (c1_u0 == 0U) {
      c1_hi = MAX_uint32_T;
    } else {
      c1_hi = c1_s / c1_u0;
    }

    c1_lo = c1_s - c1_hi * 127773U;
    c1_test1 = 16807U * c1_lo;
    c1_test2 = 2836U * c1_hi;
    if (c1_test1 < c1_test2) {
      c1_f_state = (c1_test1 - c1_test2) + 2147483647U;
    } else {
      c1_f_state = c1_test1 - c1_test2;
    }

    c1_b_r = (real_T)c1_f_state * 4.6566128752457969E-10;
    c1_e_state = c1_f_state;
    c1_d0 = c1_b_r;
    chartInstance->c1_state = c1_e_state;
    c1_r = c1_d0;
  } else if (chartInstance->c1_method == 5U) {
    if (!chartInstance->c1_b_state_not_empty) {
      for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
        chartInstance->c1_b_state[c1_i62] = 362436069U + 158852560U * (uint32_T)
          c1_i62;
      }

      chartInstance->c1_b_state_not_empty = true;
    }

    c1_icng = chartInstance->c1_b_state[0];
    c1_jsr = chartInstance->c1_b_state[1];
    c1_u1 = c1_jsr;
    c1_u2 = c1_icng;
    c1_u2 = 69069U * c1_u2 + 1234567U;
    c1_u1 ^= c1_u1 << 13;
    c1_u1 ^= c1_u1 >> 17;
    c1_u1 ^= c1_u1 << 5;
    c1_ui = c1_u2 + c1_u1;
    chartInstance->c1_b_state[0] = c1_u2;
    chartInstance->c1_b_state[1] = c1_u1;
    c1_b_ui = c1_ui;
    c1_c_r = (real_T)c1_b_ui * 2.328306436538696E-10;
    c1_d1 = c1_c_r;
    c1_r = c1_d1;
  } else {
    if (!chartInstance->c1_c_state_not_empty) {
      c1_eml_rand_mt19937ar(chartInstance, c1_uv2);
      for (c1_i63 = 0; c1_i63 < 625; c1_i63++) {
        chartInstance->c1_c_state[c1_i63] = c1_uv2[c1_i63];
      }

      chartInstance->c1_c_state_not_empty = true;
    }

    c1_d2 = c1_c_eml_rand_mt19937ar(chartInstance, chartInstance->c1_c_state);
    c1_r = c1_d2;
  }

  return c1_r;
}

static void c1_eml_rand_mt19937ar(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_d_state[625])
{
  real_T c1_d3;
  int32_T c1_i64;
  c1_d3 = 5489.0;
  for (c1_i64 = 0; c1_i64 < 625; c1_i64++) {
    c1_d_state[c1_i64] = 0U;
  }

  c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d3);
}

static void c1_twister_state_vector(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625])
{
  int32_T c1_i65;
  for (c1_i65 = 0; c1_i65 < 625; c1_i65++) {
    c1_b_mt[c1_i65] = c1_mt[c1_i65];
  }

  c1_b_twister_state_vector(chartInstance, c1_b_mt, c1_seed);
}

static void c1_b_eml_rand_mt19937ar(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T
  *c1_r)
{
  int32_T c1_i66;
  for (c1_i66 = 0; c1_i66 < 625; c1_i66++) {
    c1_e_state[c1_i66] = c1_d_state[c1_i66];
  }

  *c1_r = c1_c_eml_rand_mt19937ar(chartInstance, c1_e_state);
}

static void c1_eml_error(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance)
{
  int32_T c1_i67;
  static char_T c1_cv6[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c1_u[37];
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  for (c1_i67 = 0; c1_i67 < 37; c1_i67++) {
    c1_u[c1_i67] = c1_cv6[c1_i67];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
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
  int32_T c1_i68;
  real_T c1_b_inData[256];
  int32_T c1_i69;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i68 = 0; c1_i68 < 256; c1_i68++) {
    c1_b_inData[c1_i68] = (*(real_T (*)[256])c1_inData)[c1_i68];
  }

  for (c1_i69 = 0; c1_i69 < 256; c1_i69++) {
    c1_u[c1_i69] = c1_b_inData[c1_i69];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256])
{
  real_T c1_dv11[256];
  int32_T c1_i70;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv11, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c1_i70 = 0; c1_i70 < 256; c1_i70++) {
    c1_y[c1_i70] = c1_dv11[c1_i70];
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
  int32_T c1_i71;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_poseBML = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_poseBML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_poseBML);
  for (c1_i71 = 0; c1_i71 < 256; c1_i71++) {
    (*(real_T (*)[256])c1_outData)[c1_i71] = c1_y[c1_i71];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_b_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_bmlID, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bmlID), &c1_thisId);
  sf_mex_destroy(&c1_bmlID);
  return c1_y;
}

static real_T c1_c_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d4;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d4, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d4;
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
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
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
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
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
  const mxArray *c1_aVarTruthTableCondition_3;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_aVarTruthTableCondition_3 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_3), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_3);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i72;
  real_T c1_b_inData[256];
  int32_T c1_i73;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i72 = 0; c1_i72 < 256; c1_i72++) {
    c1_b_inData[c1_i72] = (*(real_T (*)[256])c1_inData)[c1_i72];
  }

  for (c1_i73 = 0; c1_i73 < 256; c1_i73++) {
    c1_u[c1_i73] = c1_b_inData[c1_i73];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[256])
{
  real_T c1_dv12[256];
  int32_T c1_i74;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv12, 1, 0, 0U, 1, 0U, 1, 256);
  for (c1_i74 = 0; c1_i74 < 256; c1_i74++) {
    c1_y[c1_i74] = c1_dv12[c1_i74];
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
  int32_T c1_i75;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_myarr256 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_myarr256), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_myarr256);
  for (c1_i75 = 0; c1_i75 < 256; c1_i75++) {
    (*(real_T (*)[256])c1_outData)[c1_i75] = c1_y[c1_i75];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i76;
  char_T c1_b_inData[86];
  int32_T c1_i77;
  char_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i76 = 0; c1_i76 < 86; c1_i76++) {
    c1_b_inData[c1_i76] = (*(char_T (*)[86])c1_inData)[c1_i76];
  }

  for (c1_i77 = 0; c1_i77 < 86; c1_i77++) {
    c1_u[c1_i77] = c1_b_inData[c1_i77];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i78;
  real_T c1_b_inData[86];
  int32_T c1_i79;
  real_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i78 = 0; c1_i78 < 86; c1_i78++) {
    c1_b_inData[c1_i78] = (*(real_T (*)[86])c1_inData)[c1_i78];
  }

  for (c1_i79 = 0; c1_i79 < 86; c1_i79++) {
    c1_u[c1_i79] = c1_b_inData[c1_i79];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i80;
  char_T c1_b_inData[90];
  int32_T c1_i81;
  char_T c1_u[90];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i80 = 0; c1_i80 < 90; c1_i80++) {
    c1_b_inData[c1_i80] = (*(char_T (*)[90])c1_inData)[c1_i80];
  }

  for (c1_i81 = 0; c1_i81 < 90; c1_i81++) {
    c1_u[c1_i81] = c1_b_inData[c1_i81];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 90), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i82;
  real_T c1_b_inData[90];
  int32_T c1_i83;
  real_T c1_u[90];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i82 = 0; c1_i82 < 90; c1_i82++) {
    c1_b_inData[c1_i82] = (*(real_T (*)[90])c1_inData)[c1_i82];
  }

  for (c1_i83 = 0; c1_i83 < 90; c1_i83++) {
    c1_u[c1_i83] = c1_b_inData[c1_i83];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 90), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i84;
  char_T c1_b_inData[94];
  int32_T c1_i85;
  char_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i84 = 0; c1_i84 < 94; c1_i84++) {
    c1_b_inData[c1_i84] = (*(char_T (*)[94])c1_inData)[c1_i84];
  }

  for (c1_i85 = 0; c1_i85 < 94; c1_i85++) {
    c1_u[c1_i85] = c1_b_inData[c1_i85];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i86;
  real_T c1_b_inData[94];
  int32_T c1_i87;
  real_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i86 = 0; c1_i86 < 94; c1_i86++) {
    c1_b_inData[c1_i86] = (*(real_T (*)[94])c1_inData)[c1_i86];
  }

  for (c1_i87 = 0; c1_i87 < 94; c1_i87++) {
    c1_u[c1_i87] = c1_b_inData[c1_i87];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i88;
  char_T c1_b_inData[147];
  int32_T c1_i89;
  char_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i88 = 0; c1_i88 < 147; c1_i88++) {
    c1_b_inData[c1_i88] = (*(char_T (*)[147])c1_inData)[c1_i88];
  }

  for (c1_i89 = 0; c1_i89 < 147; c1_i89++) {
    c1_u[c1_i89] = c1_b_inData[c1_i89];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i90;
  real_T c1_b_inData[147];
  int32_T c1_i91;
  real_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i90 = 0; c1_i90 < 147; c1_i90++) {
    c1_b_inData[c1_i90] = (*(real_T (*)[147])c1_inData)[c1_i90];
  }

  for (c1_i91 = 0; c1_i91 < 147; c1_i91++) {
    c1_u[c1_i91] = c1_b_inData[c1_i91];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i92;
  char_T c1_b_inData[164];
  int32_T c1_i93;
  char_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i92 = 0; c1_i92 < 164; c1_i92++) {
    c1_b_inData[c1_i92] = (*(char_T (*)[164])c1_inData)[c1_i92];
  }

  for (c1_i93 = 0; c1_i93 < 164; c1_i93++) {
    c1_u[c1_i93] = c1_b_inData[c1_i93];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i94;
  real_T c1_b_inData[164];
  int32_T c1_i95;
  real_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i94 = 0; c1_i94 < 164; c1_i94++) {
    c1_b_inData[c1_i94] = (*(real_T (*)[164])c1_inData)[c1_i94];
  }

  for (c1_i95 = 0; c1_i95 < 164; c1_i95++) {
    c1_u[c1_i95] = c1_b_inData[c1_i95];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i96;
  char_T c1_b_inData[68];
  int32_T c1_i97;
  char_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i96 = 0; c1_i96 < 68; c1_i96++) {
    c1_b_inData[c1_i96] = (*(char_T (*)[68])c1_inData)[c1_i96];
  }

  for (c1_i97 = 0; c1_i97 < 68; c1_i97++) {
    c1_u[c1_i97] = c1_b_inData[c1_i97];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i98;
  real_T c1_b_inData[68];
  int32_T c1_i99;
  real_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i98 = 0; c1_i98 < 68; c1_i98++) {
    c1_b_inData[c1_i98] = (*(real_T (*)[68])c1_inData)[c1_i98];
  }

  for (c1_i99 = 0; c1_i99 < 68; c1_i99++) {
    c1_u[c1_i99] = c1_b_inData[c1_i99];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i100;
  char_T c1_b_inData[181];
  int32_T c1_i101;
  char_T c1_u[181];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i100 = 0; c1_i100 < 181; c1_i100++) {
    c1_b_inData[c1_i100] = (*(char_T (*)[181])c1_inData)[c1_i100];
  }

  for (c1_i101 = 0; c1_i101 < 181; c1_i101++) {
    c1_u[c1_i101] = c1_b_inData[c1_i101];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 181),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_r_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i102;
  real_T c1_b_inData[181];
  int32_T c1_i103;
  real_T c1_u[181];
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i102 = 0; c1_i102 < 181; c1_i102++) {
    c1_b_inData[c1_i102] = (*(real_T (*)[181])c1_inData)[c1_i102];
  }

  for (c1_i103 = 0; c1_i103 < 181; c1_i103++) {
    c1_u[c1_i103] = c1_b_inData[c1_i103];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 181), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_testRPSsmile_Glove_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  const mxArray *c1_rhs36 = NULL;
  const mxArray *c1_lhs36 = NULL;
  const mxArray *c1_rhs37 = NULL;
  const mxArray *c1_lhs37 = NULL;
  const mxArray *c1_rhs38 = NULL;
  const mxArray *c1_lhs38 = NULL;
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
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c1_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c1_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c1_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
  sf_mex_destroy(&c1_rhs36);
  sf_mex_destroy(&c1_lhs36);
  sf_mex_destroy(&c1_rhs37);
  sf_mex_destroy(&c1_lhs37);
  sf_mex_destroy(&c1_rhs38);
  sf_mex_destroy(&c1_lhs38);
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

static void c1_idlePose(SFc1_testRPSsmile_GloveInstanceStruct *chartInstance,
  real_T c1_bmlID, real_T c1_poseBML[256])
{
  uint32_T c1_debug_family_var_map[8];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv13[256];
  int32_T c1_i104;
  int32_T c1_i105;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i106;
  int32_T c1_i107;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  uint32_T c1_b_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[68];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[68];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_myarr256[256];
  int32_T c1_i108;
  static char_T c1_cv7[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i109;
  static real_T c1_dv14[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i115;
  int32_T c1_i116;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c1_e_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 11);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 15);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 19);
  c1_aVarTruthTableCondition_3 = (c1_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 23);
  c1_aVarTruthTableCondition_4 = (c1_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 25);
  if (CV_EML_IF(2, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 26);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 41);
    c1_c_encStr2Arr(chartInstance, c1_dv13);
    for (c1_i104 = 0; c1_i104 < 256; c1_i104++) {
      c1_poseBML[c1_i104] = c1_dv13[c1_i104];
    }

    c1_updateDataWrittenToVector(chartInstance, 11U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 15U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i105 = 0; c1_i105 < 256; c1_i105++) {
      c1_u[c1_i105] = c1_poseBML[c1_i105];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, -41);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 27);
    if (CV_EML_IF(2, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 28);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 47);
      c1_d_encStr2Arr(chartInstance, c1_dv13);
      for (c1_i106 = 0; c1_i106 < 256; c1_i106++) {
        c1_poseBML[c1_i106] = c1_dv13[c1_i106];
      }

      c1_updateDataWrittenToVector(chartInstance, 11U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 15U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i107 = 0; c1_i107 < 256; c1_i107++) {
        c1_b_u[c1_i107] = c1_poseBML[c1_i107];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, -47);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 29);
      if (CV_EML_IF(2, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 30);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 53);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_h_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_p_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
          c1_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_o_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 6U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 7U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
          c1_d_sf_marshallOut, c1_d_sf_marshallIn);
        for (c1_i108 = 0; c1_i108 < 68; c1_i108++) {
          c1_mystr[c1_i108] = c1_cv7[c1_i108];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
        c1_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
        for (c1_i109 = 0; c1_i109 < 68; c1_i109++) {
          c1_arr[c1_i109] = c1_dv14[c1_i109];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
        c1_ss = 68.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
        c1_padsize = c1_maxarrsize - c1_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
        for (c1_i110 = 0; c1_i110 < 256; c1_i110++) {
          c1_tt[c1_i110] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
        for (c1_i111 = 0; c1_i111 < 68; c1_i111++) {
          c1_tt[c1_i111] = c1_arr[c1_i111];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
        for (c1_i112 = 0; c1_i112 < 256; c1_i112++) {
          c1_myarr256[c1_i112] = c1_tt[c1_i112];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c1_i113 = 0; c1_i113 < 256; c1_i113++) {
          c1_poseBML[c1_i113] = c1_myarr256[c1_i113];
        }

        c1_updateDataWrittenToVector(chartInstance, 11U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 15U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i114 = 0; c1_i114 < 256; c1_i114++) {
          c1_c_u[c1_i114] = c1_poseBML[c1_i114];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, -53);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 31);
        if (CV_EML_IF(2, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 32);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 59);
          c1_e_encStr2Arr(chartInstance, c1_dv13);
          for (c1_i115 = 0; c1_i115 < 256; c1_i115++) {
            c1_poseBML[c1_i115] = c1_dv13[c1_i115];
          }

          c1_updateDataWrittenToVector(chartInstance, 11U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 15U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i116 = 0; c1_i116 < 256; c1_i116++) {
            c1_d_u[c1_i116] = c1_poseBML[c1_i116];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, -59);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 34);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, 59);
          c1_e_encStr2Arr(chartInstance, c1_dv13);
          for (c1_i117 = 0; c1_i117 < 256; c1_i117++) {
            c1_poseBML[c1_i117] = c1_dv13[c1_i117];
          }

          c1_updateDataWrittenToVector(chartInstance, 11U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 15U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i118 = 0; c1_i118 < 256; c1_i118++) {
            c1_e_u[c1_i118] = c1_poseBML[c1_i118];
          }

          c1_e_y = NULL;
          sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_e_y);
          _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, -59);
        }
      }
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c1_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i119;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i119, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i119;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_start, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_start),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_start);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u3, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_start;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)chartInstanceVoid;
  c1_b_tp_start = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_start),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_start);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_i_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_b_method, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_method),
    &c1_thisId);
  sf_mex_destroy(&c1_b_method);
  return c1_y;
}

static uint32_T c1_j_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u4;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_method_not_empty = false;
  } else {
    chartInstance->c1_method_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u4, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u4;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint32_T c1_k_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId);
  sf_mex_destroy(&c1_d_state);
  return c1_y;
}

static uint32_T c1_l_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u5;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_state_not_empty = false;
  } else {
    chartInstance->c1_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u5, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u5;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_m_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  uint32_T c1_y[625])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_n_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[625])
{
  uint32_T c1_uv3[625];
  int32_T c1_i120;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_c_state_not_empty = false;
  } else {
    chartInstance->c1_c_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c1_i120 = 0; c1_i120 < 625; c1_i120++) {
      c1_y[c1_i120] = c1_uv3[c1_i120];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_o_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_d_state, const char_T *c1_identifier,
  uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_p_emlrt_marshallIn(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[2])
{
  uint32_T c1_uv4[2];
  int32_T c1_i121;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_b_state_not_empty = false;
  } else {
    chartInstance->c1_b_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c1_i121 = 0; c1_i121 < 2; c1_i121++) {
      c1_y[c1_i121] = c1_uv4[c1_i121];
    }
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_q_emlrt_marshallIn
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_r_emlrt_marshallIn
  (SFc1_testRPSsmile_GloveInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 11, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn(SFc1_testRPSsmile_GloveInstanceStruct *
  chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 11, 1,
    0)]);
}

static void c1_b_twister_state_vector(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_mt[625], real_T c1_seed)
{
  real_T c1_d5;
  uint32_T c1_u6;
  uint32_T c1_r;
  int32_T c1_mti;
  real_T c1_b_mti;
  real_T c1_d6;
  uint32_T c1_u7;
  (void)chartInstance;
  c1_d5 = c1_seed;
  if (c1_d5 < 4.294967296E+9) {
    if (c1_d5 >= 0.0) {
      c1_u6 = (uint32_T)c1_d5;
    } else {
      c1_u6 = 0U;
    }
  } else if (c1_d5 >= 4.294967296E+9) {
    c1_u6 = MAX_uint32_T;
  } else {
    c1_u6 = 0U;
  }

  c1_r = c1_u6;
  c1_mt[0] = c1_r;
  for (c1_mti = 0; c1_mti < 623; c1_mti++) {
    c1_b_mti = 2.0 + (real_T)c1_mti;
    c1_d6 = muDoubleScalarRound(c1_b_mti - 1.0);
    if (c1_d6 < 4.294967296E+9) {
      if (c1_d6 >= 0.0) {
        c1_u7 = (uint32_T)c1_d6;
      } else {
        c1_u7 = 0U;
      }
    } else if (c1_d6 >= 4.294967296E+9) {
      c1_u7 = MAX_uint32_T;
    } else {
      c1_u7 = 0U;
    }

    c1_r = (c1_r ^ c1_r >> 30U) * 1812433253U + c1_u7;
    c1_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_mti), 1, 625, 1, 0) - 1] = c1_r;
  }

  c1_mt[624] = 624U;
}

static real_T c1_c_eml_rand_mt19937ar(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance, uint32_T c1_d_state[625])
{
  int32_T c1_i122;
  uint32_T c1_u[2];
  int32_T c1_j;
  real_T c1_b_j;
  uint32_T c1_mti;
  int32_T c1_kk;
  real_T c1_b_kk;
  uint32_T c1_y;
  uint32_T c1_b_y;
  uint32_T c1_c_y;
  int32_T c1_c_kk;
  uint32_T c1_d_y;
  uint32_T c1_e_y;
  uint32_T c1_f_y;
  uint32_T c1_g_y;
  real_T c1_b_r;
  boolean_T c1_b1;
  boolean_T c1_isvalid;
  int32_T c1_k;
  int32_T c1_a;
  int32_T c1_b_a;
  real_T c1_d7;
  boolean_T guard1 = false;
  int32_T exitg1;
  boolean_T exitg2;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (c1_i122 = 0; c1_i122 < 2; c1_i122++) {
      c1_u[c1_i122] = 0U;
    }

    for (c1_j = 0; c1_j < 2; c1_j++) {
      c1_b_j = 1.0 + (real_T)c1_j;
      c1_mti = c1_d_state[624] + 1U;
      if ((real_T)c1_mti >= 625.0) {
        for (c1_kk = 0; c1_kk < 227; c1_kk++) {
          c1_b_kk = 1.0 + (real_T)c1_kk;
          c1_y = (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c1_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c1_b_y = c1_y;
          c1_c_y = c1_b_y;
          if ((real_T)(c1_c_y & 1U) == 0.0) {
            c1_c_y >>= 1U;
          } else {
            c1_c_y = c1_c_y >> 1U ^ 2567483615U;
          }

          c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c1_b_kk), 1, 625, 1, 0) - 1] =
            c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c1_c_y;
        }

        for (c1_c_kk = 0; c1_c_kk < 396; c1_c_kk++) {
          c1_b_kk = 228.0 + (real_T)c1_c_kk;
          c1_y = (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c1_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c1_d_y = c1_y;
          c1_e_y = c1_d_y;
          if ((real_T)(c1_e_y & 1U) == 0.0) {
            c1_e_y >>= 1U;
          } else {
            c1_e_y = c1_e_y >> 1U ^ 2567483615U;
          }

          c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c1_b_kk), 1, 625, 1, 0) - 1] =
            c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c1_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c1_e_y;
        }

        c1_y = (c1_d_state[623] & 2147483648U) | (c1_d_state[0] & 2147483647U);
        c1_f_y = c1_y;
        c1_g_y = c1_f_y;
        if ((real_T)(c1_g_y & 1U) == 0.0) {
          c1_g_y >>= 1U;
        } else {
          c1_g_y = c1_g_y >> 1U ^ 2567483615U;
        }

        c1_d_state[623] = c1_d_state[396] ^ c1_g_y;
        c1_mti = 1U;
      }

      c1_y = c1_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_mti), 1, 625, 1, 0)
        - 1];
      c1_d_state[624] = c1_mti;
      c1_y ^= c1_y >> 11U;
      c1_y ^= c1_y << 7U & 2636928640U;
      c1_y ^= c1_y << 15U & 4022730752U;
      c1_y ^= c1_y >> 18U;
      c1_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c1_b_j), 1, 2, 1, 0) - 1] = c1_y;
    }

    c1_u[0] >>= 5U;
    c1_u[1] >>= 6U;
    c1_b_r = 1.1102230246251565E-16 * ((real_T)c1_u[0] * 6.7108864E+7 + (real_T)
      c1_u[1]);
    if (c1_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c1_d_state[624] >= 1.0) {
        if ((real_T)c1_d_state[624] < 625.0) {
          c1_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c1_b1 = false;
      }

      c1_isvalid = c1_b1;
      if (c1_isvalid) {
        c1_isvalid = false;
        c1_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c1_k < 625)) {
          if ((real_T)c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c1_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c1_a = c1_k;
            c1_b_a = c1_a + 1;
            c1_k = c1_b_a;
          } else {
            c1_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c1_isvalid) {
        c1_eml_error(chartInstance);
        c1_d7 = 5489.0;
        c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c1_b_r;
}

static void init_dsm_address_info(SFc1_testRPSsmile_GloveInstanceStruct
  *chartInstance)
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

void sf_c1_testRPSsmile_Glove_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2280759742U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1215093914U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(333178143U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(187286974U);
}

mxArray *sf_c1_testRPSsmile_Glove_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("exxcZjsKrMPZlwjCH6tBqH");
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

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_testRPSsmile_Glove_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_testRPSsmile_Glove_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_testRPSsmile_Glove(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[468],T\"bHand\",},{M[3],M[462],T\"diff\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c1_testRPSsmile_Glove\",},{M[9],M[0],T\"is_c1_testRPSsmile_Glove\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x8[432 439 436 474 440 444 455 430],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_testRPSsmile_Glove_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testRPSsmile_GloveMachineNumber_,
           1,
           16,
           18,
           0,
           16,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testRPSsmile_GloveMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testRPSsmile_GloveMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testRPSsmile_GloveMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
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
          _SFD_SET_DATA_PROPS(11,8,0,0,"");
          _SFD_SET_DATA_PROPS(12,9,0,0,"");
          _SFD_SET_DATA_PROPS(13,8,0,0,"");
          _SFD_SET_DATA_PROPS(14,8,0,0,"");
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_CH_SUBSTATE_COUNT(13);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_CH_SUBSTATE_INDEX(3,6);
          _SFD_CH_SUBSTATE_INDEX(4,7);
          _SFD_CH_SUBSTATE_INDEX(5,8);
          _SFD_CH_SUBSTATE_INDEX(6,9);
          _SFD_CH_SUBSTATE_INDEX(7,10);
          _SFD_CH_SUBSTATE_INDEX(8,11);
          _SFD_CH_SUBSTATE_INDEX(9,12);
          _SFD_CH_SUBSTATE_INDEX(10,13);
          _SFD_CH_SUBSTATE_INDEX(11,14);
          _SFD_CH_SUBSTATE_INDEX(12,15);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
        }

        _SFD_CV_INIT_CHART(13,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"handPose",0,-1,557);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",557,-1,714);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",714,-1,872);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",872,-1,1032);
        _SFD_CV_INIT_EML_IF(1,1,0,316,346,377,555);
        _SFD_CV_INIT_EML_IF(1,1,1,377,411,442,555);
        _SFD_CV_INIT_EML_IF(1,1,2,442,476,507,555);
        _SFD_CV_INIT_EML(2,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"idlePose",0,-1,711);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",711,-1,927);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",927,-1,1158);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1158,-1,1293);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1293,-1,1541);
        _SFD_CV_INIT_EML_IF(2,1,0,405,435,466,709);
        _SFD_CV_INIT_EML_IF(2,1,1,466,500,531,709);
        _SFD_CV_INIT_EML_IF(2,1,2,531,565,596,709);
        _SFD_CV_INIT_EML_IF(2,1,3,596,630,661,709);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,0,21,0,21);

        {
          static int condStart[] = { 0, 13 };

          static int condEnd[] = { 12, 21 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,0,21,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,0,21,0,21);

        {
          static int condStart[] = { 0, 13 };

          static int condEnd[] = { 12, 21 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,0,21,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(10,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(10,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,12,0,12);
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

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));

        {
          real_T *c1_gameState;
          real_T *c1_inputUser;
          real_T *c1_bradHand;
          real_T *c1_userHand;
          real_T *c1_win;
          real_T *c1_bWinT;
          real_T *c1_uWinT;
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
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testRPSsmile_GloveMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "9gouXUPLpIYCd8YZdJxfrE";
}

static void sf_opaque_initialize_c1_testRPSsmile_Glove(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar);
  initialize_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_testRPSsmile_Glove(void *chartInstanceVar)
{
  enable_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_testRPSsmile_Glove(void *chartInstanceVar)
{
  disable_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_testRPSsmile_Glove(void *chartInstanceVar)
{
  sf_gateway_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_testRPSsmile_Glove(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_testRPSsmile_Glove
    ((SFc1_testRPSsmile_GloveInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_testRPSsmile_Glove();/* state var info */
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

extern void sf_internal_set_sim_state_c1_testRPSsmile_Glove(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_testRPSsmile_Glove();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_testRPSsmile_Glove(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_testRPSsmile_Glove(S);
}

static void sf_opaque_set_sim_state_c1_testRPSsmile_Glove(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_testRPSsmile_Glove(S, st);
}

static void sf_opaque_terminate_c1_testRPSsmile_Glove(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_testRPSsmile_GloveInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testRPSsmile_Glove_optimization_info();
    }

    finalize_c1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
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
  initSimStructsc1_testRPSsmile_Glove((SFc1_testRPSsmile_GloveInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_testRPSsmile_Glove(SimStruct *S)
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
    initialize_params_c1_testRPSsmile_Glove
      ((SFc1_testRPSsmile_GloveInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_testRPSsmile_Glove(SimStruct *S)
{
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testRPSsmile_Glove_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,1,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
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
  ssSetChecksum0(S,(1422773004U));
  ssSetChecksum1(S,(3017969802U));
  ssSetChecksum2(S,(151709154U));
  ssSetChecksum3(S,(3700366571U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_testRPSsmile_Glove(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_testRPSsmile_Glove(SimStruct *S)
{
  SFc1_testRPSsmile_GloveInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_testRPSsmile_GloveInstanceStruct *)utMalloc(sizeof
    (SFc1_testRPSsmile_GloveInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_testRPSsmile_GloveInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_testRPSsmile_Glove;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_testRPSsmile_Glove;
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

void c1_testRPSsmile_Glove_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_testRPSsmile_Glove(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_testRPSsmile_Glove(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_testRPSsmile_Glove(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_testRPSsmile_Glove_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
