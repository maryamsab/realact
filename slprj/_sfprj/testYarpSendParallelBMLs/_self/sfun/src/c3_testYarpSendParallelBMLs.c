/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testYarpSendParallelBMLs_sfun.h"
#include "c3_testYarpSendParallelBMLs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testYarpSendParallelBMLs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_face                     ((uint8_T)1U)
#define c3_IN_gaze                     ((uint8_T)2U)
#define c3_IN_stateInitial             ((uint8_T)3U)
#define c3_IN_tt                       ((uint8_T)4U)
#define c3_IN_b                        ((uint8_T)1U)
#define c3_IN_bml3                     ((uint8_T)2U)
#define c3_IN_init                     ((uint8_T)3U)
#define c3_IN_checkHighPriority        ((uint8_T)1U)
#define c3_b_IN_init                   ((uint8_T)2U)
#define c3_IN_low                      ((uint8_T)3U)
#define c3_IN_sendH                    ((uint8_T)4U)
#define c3_IN_sendL                    ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_g_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c3_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[7] = { "full", "t", "nargin",
  "nargout", "bmls", "mBML", "newBmls" };

static const char * c3_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_s_debug_family_names[7] = { "full", "t", "nargin",
  "nargout", "bmls", "mBML", "newBmls" };

static const char * c3_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_u_debug_family_names[4] = { "nargin", "nargout", "bmls",
  "newBmls" };

static const char * c3_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_w_debug_family_names[5] = { "t", "nargin", "nargout",
  "bmls", "empty" };

static const char * c3_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[25];

/* Function Declarations */
static void initialize_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void initialize_params_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void enable_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void disable_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void set_sim_state_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void c3_set_sim_state_side_effects_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void finalize_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void sf_gateway_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void initSimStructsc3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void c3_Low(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void c3_tt(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void c3_b(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void c3_send(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance);
static void c3_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256]);
static void c3_b_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256]);
static void c3_c_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256]);
static void c3_d_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256]);
static void c3_e_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256]);
static boolean_T c3_isequal(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_varargin_1[256], real_T c3_varargin_2[256]);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_poseBML, const char_T *c3_identifier, real_T
  c3_y[256]);
static void c3_b_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct *
  chartInstance, const mxArray *c3_bmlID, const char_T *c3_identifier);
static real_T c3_d_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_e_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_f_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_newBmls, const char_T *c3_identifier, real_T
  c3_y[1280]);
static void c3_h_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[1280]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static void c3_sendBML(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_arg[256]);
static void c3_insertQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280], real_T c3_mBML[256], real_T c3_newBmls
  [1280]);
static void c3_b_insertQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280], real_T c3_mBML[256], real_T c3_newBmls
  [1280]);
static void c3_removeQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280], real_T c3_newBmls[1280]);
static real_T c3_isEmptyQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280]);
static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_i_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_j_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_k_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Low, const char_T *c3_identifier);
static uint8_T c3_l_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_m_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_b_qSizeH, const char_T *c3_identifier,
  real_T c3_y[2]);
static void c3_n_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint32_T c3_o_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_b_previousTicks, const char_T *c3_identifier);
static uint32_T c3_p_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_q_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_r_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber);
static void init_dsm_address_info(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_High = 0U;
  chartInstance->c3_is_High = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_High = 0U;
  chartInstance->c3_tp_b = 0U;
  chartInstance->c3_temporalCounter_i2 = 0U;
  chartInstance->c3_tp_bml3 = 0U;
  chartInstance->c3_tp_init = 0U;
  chartInstance->c3_is_active_Low = 0U;
  chartInstance->c3_is_Low = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_Low = 0U;
  chartInstance->c3_tp_face = 0U;
  chartInstance->c3_tp_gaze = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateInitial = 0U;
  chartInstance->c3_tp_tt = 0U;
  chartInstance->c3_is_active_send = 0U;
  chartInstance->c3_is_send = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_send = 0U;
  chartInstance->c3_tp_checkHighPriority = 0U;
  chartInstance->c3_b_tp_init = 0U;
  chartInstance->c3_tp_low = 0U;
  chartInstance->c3_tp_sendH = 0U;
  chartInstance->c3_tp_sendL = 0U;
  chartInstance->c3_is_active_c3_testYarpSendParallelBMLs = 0U;
  chartInstance->c3_presentTicks = 0U;
  chartInstance->c3_elapsedTicks = 0U;
  chartInstance->c3_previousTicks = 0U;
}

static void initialize_params_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_is_active_send == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
  }

  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.01
    + 0.5);
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
}

static void disable_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.01
    + 0.5);
  chartInstance->c3_elapsedTicks = chartInstance->c3_presentTicks -
    chartInstance->c3_previousTicks;
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if ((uint32_T)chartInstance->c3_temporalCounter_i1 +
      chartInstance->c3_elapsedTicks <= 7U) {
    chartInstance->c3_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i1 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i1 = 7U;
  }

  if ((uint32_T)chartInstance->c3_temporalCounter_i2 +
      chartInstance->c3_elapsedTicks <= 15U) {
    chartInstance->c3_temporalCounter_i2 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i2 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i2 = 15U;
  }

  if (chartInstance->c3_is_active_send == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
  }
}

static void c3_update_debugger_state_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_testYarpSendParallelBMLs == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_Low == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Low == c3_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Low == c3_IN_tt) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Low == c3_IN_gaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_Low == c3_IN_face) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_High == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_High == c3_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_High == c3_IN_b) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_High == c3_IN_bml3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_send == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_send == c3_IN_sendH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_send == c3_IN_checkHighPriority) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_send == c3_b_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_send == c3_IN_sendL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_send == c3_IN_low) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_i0;
  real_T c3_c_u[256];
  const mxArray *c3_d_y = NULL;
  int32_T c3_i1;
  real_T c3_d_u[256];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i2;
  real_T c3_e_u[256];
  const mxArray *c3_f_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_i3;
  real_T c3_g_u[1280];
  const mxArray *c3_h_y = NULL;
  int32_T c3_i4;
  real_T c3_h_u[1280];
  const mxArray *c3_i_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  int32_T c3_i5;
  real_T c3_m_u[256];
  const mxArray *c3_n_y = NULL;
  int32_T c3_i6;
  real_T c3_n_u[1280];
  const mxArray *c3_o_y = NULL;
  int32_T c3_i7;
  real_T c3_o_u[1280];
  const mxArray *c3_p_y = NULL;
  int32_T c3_i8;
  real_T c3_p_u[2];
  const mxArray *c3_q_y = NULL;
  int32_T c3_i9;
  real_T c3_q_u[2];
  const mxArray *c3_r_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_r_u;
  const mxArray *c3_s_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  uint8_T c3_s_u;
  const mxArray *c3_t_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  uint8_T c3_t_u;
  const mxArray *c3_u_y = NULL;
  uint8_T c3_k_hoistedGlobal;
  uint8_T c3_u_u;
  const mxArray *c3_v_y = NULL;
  uint8_T c3_l_hoistedGlobal;
  uint8_T c3_v_u;
  const mxArray *c3_w_y = NULL;
  uint8_T c3_m_hoistedGlobal;
  uint8_T c3_w_u;
  const mxArray *c3_x_y = NULL;
  uint8_T c3_n_hoistedGlobal;
  uint8_T c3_x_u;
  const mxArray *c3_y_y = NULL;
  uint8_T c3_o_hoistedGlobal;
  uint8_T c3_y_u;
  const mxArray *c3_ab_y = NULL;
  uint8_T c3_p_hoistedGlobal;
  uint8_T c3_ab_u;
  const mxArray *c3_bb_y = NULL;
  uint32_T c3_q_hoistedGlobal;
  uint32_T c3_bb_u;
  const mxArray *c3_cb_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(27, 1), false);
  c3_hoistedGlobal = chartInstance->c3_A;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_B;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  for (c3_i0 = 0; c3_i0 < 256; c3_i0++) {
    c3_c_u[c3_i0] = chartInstance->c3_BML[c3_i0];
  }

  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  for (c3_i1 = 0; c3_i1 < 256; c3_i1++) {
    c3_d_u[c3_i1] = chartInstance->c3_BMLh[c3_i1];
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i2 = 0; c3_i2 < 256; c3_i2++) {
    c3_e_u[c3_i2] = chartInstance->c3_BMLl[c3_i2];
  }

  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_c_hoistedGlobal = chartInstance->c3_bHand;
  c3_f_u = c3_c_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  for (c3_i3 = 0; c3_i3 < 1280; c3_i3++) {
    c3_g_u[c3_i3] = chartInstance->c3_bmlsH[c3_i3];
  }

  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  for (c3_i4 = 0; c3_i4 < 1280; c3_i4++) {
    c3_h_u[c3_i4] = chartInstance->c3_bmlsL[c3_i4];
  }

  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_h_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_d_hoistedGlobal = chartInstance->c3_cHand;
  c3_i_u = c3_d_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_e_hoistedGlobal = chartInstance->c3_hEmpty;
  c3_j_u = c3_e_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_f_hoistedGlobal = chartInstance->c3_i;
  c3_k_u = c3_f_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_g_hoistedGlobal = chartInstance->c3_lEmpty;
  c3_l_u = c3_g_hoistedGlobal;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  for (c3_i5 = 0; c3_i5 < 256; c3_i5++) {
    c3_m_u[c3_i5] = chartInstance->c3_n[c3_i5];
  }

  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_m_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  for (c3_i6 = 0; c3_i6 < 1280; c3_i6++) {
    c3_n_u[c3_i6] = chartInstance->c3_newBmlsH[c3_i6];
  }

  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", c3_n_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  for (c3_i7 = 0; c3_i7 < 1280; c3_i7++) {
    c3_o_u[c3_i7] = chartInstance->c3_newBmlsL[c3_i7];
  }

  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", c3_o_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    c3_p_u[c3_i8] = chartInstance->c3_qSizeH[c3_i8];
  }

  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", c3_p_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    c3_q_u[c3_i9] = chartInstance->c3_qSizeL[c3_i9];
  }

  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", c3_q_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_active_c3_testYarpSendParallelBMLs;
  c3_r_u = c3_h_hoistedGlobal;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_i_hoistedGlobal = chartInstance->c3_is_active_send;
  c3_s_u = c3_i_hoistedGlobal;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_j_hoistedGlobal = chartInstance->c3_is_active_Low;
  c3_t_u = c3_j_hoistedGlobal;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_k_hoistedGlobal = chartInstance->c3_is_active_High;
  c3_u_u = c3_k_hoistedGlobal;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 20, c3_v_y);
  c3_l_hoistedGlobal = chartInstance->c3_is_send;
  c3_v_u = c3_l_hoistedGlobal;
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 21, c3_w_y);
  c3_m_hoistedGlobal = chartInstance->c3_is_Low;
  c3_w_u = c3_m_hoistedGlobal;
  c3_x_y = NULL;
  sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 22, c3_x_y);
  c3_n_hoistedGlobal = chartInstance->c3_is_High;
  c3_x_u = c3_n_hoistedGlobal;
  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_x_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 23, c3_y_y);
  c3_o_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_y_u = c3_o_hoistedGlobal;
  c3_ab_y = NULL;
  sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_y_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 24, c3_ab_y);
  c3_p_hoistedGlobal = chartInstance->c3_temporalCounter_i2;
  c3_ab_u = c3_p_hoistedGlobal;
  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_ab_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 25, c3_bb_y);
  c3_q_hoistedGlobal = chartInstance->c3_previousTicks;
  c3_bb_u = c3_q_hoistedGlobal;
  c3_cb_y = NULL;
  sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_bb_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 26, c3_cb_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[256];
  int32_T c3_i10;
  real_T c3_dv1[256];
  int32_T c3_i11;
  real_T c3_dv2[256];
  int32_T c3_i12;
  real_T c3_dv3[1280];
  int32_T c3_i13;
  real_T c3_dv4[1280];
  int32_T c3_i14;
  real_T c3_dv5[256];
  int32_T c3_i15;
  real_T c3_dv6[1280];
  int32_T c3_i16;
  real_T c3_dv7[1280];
  int32_T c3_i17;
  real_T c3_dv8[2];
  int32_T c3_i18;
  real_T c3_dv9[2];
  int32_T c3_i19;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_A = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "A");
  chartInstance->c3_B = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "B");
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)), "BML",
                      c3_dv0);
  for (c3_i10 = 0; c3_i10 < 256; c3_i10++) {
    chartInstance->c3_BML[c3_i10] = c3_dv0[c3_i10];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)), "BMLh",
                      c3_dv1);
  for (c3_i11 = 0; c3_i11 < 256; c3_i11++) {
    chartInstance->c3_BMLh[c3_i11] = c3_dv1[c3_i11];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)), "BMLl",
                      c3_dv2);
  for (c3_i12 = 0; c3_i12 < 256; c3_i12++) {
    chartInstance->c3_BMLl[c3_i12] = c3_dv2[c3_i12];
  }

  chartInstance->c3_bHand = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "bHand");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
                        "bmlsH", c3_dv3);
  for (c3_i13 = 0; c3_i13 < 1280; c3_i13++) {
    chartInstance->c3_bmlsH[c3_i13] = c3_dv3[c3_i13];
  }

  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 7)),
                        "bmlsL", c3_dv4);
  for (c3_i14 = 0; c3_i14 < 1280; c3_i14++) {
    chartInstance->c3_bmlsL[c3_i14] = c3_dv4[c3_i14];
  }

  chartInstance->c3_cHand = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "cHand");
  chartInstance->c3_hEmpty = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "hEmpty");
  chartInstance->c3_i = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "i");
  chartInstance->c3_lEmpty = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "lEmpty");
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 12)), "n",
                      c3_dv5);
  for (c3_i15 = 0; c3_i15 < 256; c3_i15++) {
    chartInstance->c3_n[c3_i15] = c3_dv5[c3_i15];
  }

  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 13)),
                        "newBmlsH", c3_dv6);
  for (c3_i16 = 0; c3_i16 < 1280; c3_i16++) {
    chartInstance->c3_newBmlsH[c3_i16] = c3_dv6[c3_i16];
  }

  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 14)),
                        "newBmlsL", c3_dv7);
  for (c3_i17 = 0; c3_i17 < 1280; c3_i17++) {
    chartInstance->c3_newBmlsL[c3_i17] = c3_dv7[c3_i17];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 15)),
                        "qSizeH", c3_dv8);
  for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
    chartInstance->c3_qSizeH[c3_i18] = c3_dv8[c3_i18];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 16)),
                        "qSizeL", c3_dv9);
  for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
    chartInstance->c3_qSizeL[c3_i19] = c3_dv9[c3_i19];
  }

  chartInstance->c3_is_active_c3_testYarpSendParallelBMLs =
    c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 17)),
    "is_active_c3_testYarpSendParallelBMLs");
  chartInstance->c3_is_active_send = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 18)), "is_active_send");
  chartInstance->c3_is_active_Low = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 19)), "is_active_Low");
  chartInstance->c3_is_active_High = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 20)), "is_active_High");
  chartInstance->c3_is_send = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 21)), "is_send");
  chartInstance->c3_is_Low = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 22)), "is_Low");
  chartInstance->c3_is_High = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 23)), "is_High");
  chartInstance->c3_temporalCounter_i1 = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 24)), "temporalCounter_i1");
  chartInstance->c3_temporalCounter_i2 = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 25)), "temporalCounter_i2");
  chartInstance->c3_previousTicks = c3_o_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 26)), "previousTicks");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 27)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_testYarpSendParallelBMLs(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_active_Low == 1U) {
      chartInstance->c3_tp_Low = 1U;
    } else {
      chartInstance->c3_tp_Low = 0U;
    }

    if (chartInstance->c3_is_Low == c3_IN_face) {
      chartInstance->c3_tp_face = 1U;
    } else {
      chartInstance->c3_tp_face = 0U;
    }

    if (chartInstance->c3_is_Low == c3_IN_gaze) {
      chartInstance->c3_tp_gaze = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_gaze = 0U;
    }

    if (chartInstance->c3_is_Low == c3_IN_stateInitial) {
      chartInstance->c3_tp_stateInitial = 1U;
    } else {
      chartInstance->c3_tp_stateInitial = 0U;
    }

    if (chartInstance->c3_is_Low == c3_IN_tt) {
      chartInstance->c3_tp_tt = 1U;
    } else {
      chartInstance->c3_tp_tt = 0U;
    }

    if (chartInstance->c3_is_active_send == 1U) {
      chartInstance->c3_tp_send = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
      }
    } else {
      chartInstance->c3_tp_send = 0U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
      }
    }

    if (chartInstance->c3_is_send == c3_IN_checkHighPriority) {
      chartInstance->c3_tp_checkHighPriority = 1U;
    } else {
      chartInstance->c3_tp_checkHighPriority = 0U;
    }

    if (chartInstance->c3_is_send == c3_b_IN_init) {
      chartInstance->c3_b_tp_init = 1U;
    } else {
      chartInstance->c3_b_tp_init = 0U;
    }

    if (chartInstance->c3_is_send == c3_IN_low) {
      chartInstance->c3_tp_low = 1U;
    } else {
      chartInstance->c3_tp_low = 0U;
    }

    if (chartInstance->c3_is_send == c3_IN_sendH) {
      chartInstance->c3_tp_sendH = 1U;
    } else {
      chartInstance->c3_tp_sendH = 0U;
    }

    if (chartInstance->c3_is_send == c3_IN_sendL) {
      chartInstance->c3_tp_sendL = 1U;
    } else {
      chartInstance->c3_tp_sendL = 0U;
    }

    if (chartInstance->c3_is_active_High == 1U) {
      chartInstance->c3_tp_High = 1U;
    } else {
      chartInstance->c3_tp_High = 0U;
    }

    if (chartInstance->c3_is_High == c3_IN_b) {
      chartInstance->c3_tp_b = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c3_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c3_tp_b = 0U;
    }

    if (chartInstance->c3_is_High == c3_IN_bml3) {
      chartInstance->c3_tp_bml3 = 1U;
    } else {
      chartInstance->c3_tp_bml3 = 0U;
    }

    if (chartInstance->c3_is_High == c3_IN_init) {
      chartInstance->c3_tp_init = 1U;
    } else {
      chartInstance->c3_tp_init = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_dv10[256];
  int32_T c3_i31;
  int32_T c3_i32;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  int32_T c3_i39;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  real_T (*c3_y)[2];
  c3_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_testYarpSendParallelBMLs(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.01
    + 0.5);
  chartInstance->c3_elapsedTicks = chartInstance->c3_presentTicks -
    chartInstance->c3_previousTicks;
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if ((uint32_T)chartInstance->c3_temporalCounter_i1 +
      chartInstance->c3_elapsedTicks <= 7U) {
    chartInstance->c3_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i1 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i1 = 7U;
  }

  if ((uint32_T)chartInstance->c3_temporalCounter_i2 +
      chartInstance->c3_elapsedTicks <= 15U) {
    chartInstance->c3_temporalCounter_i2 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i2 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i2 = 15U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i20 = 0; c3_i20 < 256; c3_i20++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BMLl[c3_i20], 0U);
  }

  for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_qSizeH[c3_i21], 1U);
  }

  for (c3_i22 = 0; c3_i22 < 1280; c3_i22++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i22], 2U);
  }

  for (c3_i23 = 0; c3_i23 < 256; c3_i23++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BML[c3_i23], 3U);
  }

  for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_qSizeL[c3_i24], 4U);
  }

  for (c3_i25 = 0; c3_i25 < 1280; c3_i25++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsL[c3_i25], 5U);
  }

  for (c3_i26 = 0; c3_i26 < 256; c3_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BMLh[c3_i26], 6U);
  }

  for (c3_i27 = 0; c3_i27 < 256; c3_i27++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_n[c3_i27], 7U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_lEmpty, 9U);
  for (c3_i28 = 0; c3_i28 < 1280; c3_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsH[c3_i28], 10U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_i, 11U);
  for (c3_i29 = 0; c3_i29 < 1280; c3_i29++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsL[c3_i29], 12U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_bHand, 13U);
  for (c3_i30 = 0; c3_i30 < 2; c3_i30++) {
    _SFD_DATA_RANGE_CHECK((*c3_y)[c3_i30], 14U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_cHand, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_A, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_B, 17U);
  chartInstance->c3_sfEvent = c3_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_testYarpSendParallelBMLs == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_testYarpSendParallelBMLs = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_Low = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_Low = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_Low = c3_IN_stateInitial;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateInitial = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_e_encStr2Arr(chartInstance, c3_dv10);
    for (c3_i31 = 0; c3_i31 < 256; c3_i31++) {
      chartInstance->c3_n[c3_i31] = c3_dv10[c3_i31];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    for (c3_i32 = 0; c3_i32 < 256; c3_i32++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_n[c3_i32], 7U);
    }

    _SFD_SYMBOL_SCOPE_POP();
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    for (c3_i33 = 0; c3_i33 < 256; c3_i33++) {
      chartInstance->c3_bmlsL[c3_i33] = chartInstance->c3_n[c3_i33];
    }

    for (c3_i34 = 0; c3_i34 < 256; c3_i34++) {
      chartInstance->c3_bmlsL[c3_i34 + 256] = chartInstance->c3_n[c3_i34];
    }

    for (c3_i35 = 0; c3_i35 < 256; c3_i35++) {
      chartInstance->c3_bmlsL[c3_i35 + 512] = chartInstance->c3_n[c3_i35];
    }

    for (c3_i36 = 0; c3_i36 < 256; c3_i36++) {
      chartInstance->c3_bmlsL[c3_i36 + 768] = chartInstance->c3_n[c3_i36];
    }

    for (c3_i37 = 0; c3_i37 < 256; c3_i37++) {
      chartInstance->c3_bmlsL[c3_i37 + 1024] = chartInstance->c3_n[c3_i37];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 5U);
    for (c3_i38 = 0; c3_i38 < 1280; c3_i38++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsL[c3_i38], 5U);
    }

    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_is_active_send = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_send = 1U;
    sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_send = c3_b_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
    chartInstance->c3_b_tp_init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_x_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    chartInstance->c3_A = 5.0;
    c3_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_A, 16U);
    chartInstance->c3_B = 10.0;
    c3_updateDataWrittenToVector(chartInstance, 16U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_B, 17U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    for (c3_i39 = 0; c3_i39 < 256; c3_i39++) {
      chartInstance->c3_bmlsH[c3_i39] = chartInstance->c3_n[c3_i39];
    }

    for (c3_i40 = 0; c3_i40 < 256; c3_i40++) {
      chartInstance->c3_bmlsH[c3_i40 + 256] = chartInstance->c3_n[c3_i40];
    }

    for (c3_i41 = 0; c3_i41 < 256; c3_i41++) {
      chartInstance->c3_bmlsH[c3_i41 + 512] = chartInstance->c3_n[c3_i41];
    }

    for (c3_i42 = 0; c3_i42 < 256; c3_i42++) {
      chartInstance->c3_bmlsH[c3_i42 + 768] = chartInstance->c3_n[c3_i42];
    }

    for (c3_i43 = 0; c3_i43 < 256; c3_i43++) {
      chartInstance->c3_bmlsH[c3_i43 + 1024] = chartInstance->c3_n[c3_i43];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 2U);
    for (c3_i44 = 0; c3_i44 < 1280; c3_i44++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i44], 2U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    for (c3_i45 = 0; c3_i45 < 256; c3_i45++) {
      chartInstance->c3_bmlsL[c3_i45] = chartInstance->c3_n[c3_i45];
    }

    for (c3_i46 = 0; c3_i46 < 256; c3_i46++) {
      chartInstance->c3_bmlsL[c3_i46 + 256] = chartInstance->c3_n[c3_i46];
    }

    for (c3_i47 = 0; c3_i47 < 256; c3_i47++) {
      chartInstance->c3_bmlsL[c3_i47 + 512] = chartInstance->c3_n[c3_i47];
    }

    for (c3_i48 = 0; c3_i48 < 256; c3_i48++) {
      chartInstance->c3_bmlsL[c3_i48 + 768] = chartInstance->c3_n[c3_i48];
    }

    for (c3_i49 = 0; c3_i49 < 256; c3_i49++) {
      chartInstance->c3_bmlsL[c3_i49 + 1024] = chartInstance->c3_n[c3_i49];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 5U);
    for (c3_i50 = 0; c3_i50 < 1280; c3_i50++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsL[c3_i50], 5U);
    }

    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_is_active_High = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_High = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_High = c3_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_q_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_e_encStr2Arr(chartInstance, c3_dv10);
    for (c3_i51 = 0; c3_i51 < 256; c3_i51++) {
      chartInstance->c3_n[c3_i51] = c3_dv10[c3_i51];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    for (c3_i52 = 0; c3_i52 < 256; c3_i52++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_n[c3_i52], 7U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    for (c3_i53 = 0; c3_i53 < 256; c3_i53++) {
      chartInstance->c3_bmlsH[c3_i53] = chartInstance->c3_n[c3_i53];
    }

    for (c3_i54 = 0; c3_i54 < 256; c3_i54++) {
      chartInstance->c3_bmlsH[c3_i54 + 256] = chartInstance->c3_n[c3_i54];
    }

    for (c3_i55 = 0; c3_i55 < 256; c3_i55++) {
      chartInstance->c3_bmlsH[c3_i55 + 512] = chartInstance->c3_n[c3_i55];
    }

    for (c3_i56 = 0; c3_i56 < 256; c3_i56++) {
      chartInstance->c3_bmlsH[c3_i56 + 768] = chartInstance->c3_n[c3_i56];
    }

    for (c3_i57 = 0; c3_i57 < 256; c3_i57++) {
      chartInstance->c3_bmlsH[c3_i57 + 1024] = chartInstance->c3_n[c3_i57];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 2U);
    for (c3_i58 = 0; c3_i58 < 1280; c3_i58++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i58], 2U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 7U);
    for (c3_i59 = 0; c3_i59 < 256; c3_i59++) {
      chartInstance->c3_newBmlsH[c3_i59] = chartInstance->c3_n[c3_i59];
    }

    for (c3_i60 = 0; c3_i60 < 256; c3_i60++) {
      chartInstance->c3_newBmlsH[c3_i60 + 256] = chartInstance->c3_n[c3_i60];
    }

    for (c3_i61 = 0; c3_i61 < 256; c3_i61++) {
      chartInstance->c3_newBmlsH[c3_i61 + 512] = chartInstance->c3_n[c3_i61];
    }

    for (c3_i62 = 0; c3_i62 < 256; c3_i62++) {
      chartInstance->c3_newBmlsH[c3_i62 + 768] = chartInstance->c3_n[c3_i62];
    }

    for (c3_i63 = 0; c3_i63 < 256; c3_i63++) {
      chartInstance->c3_newBmlsH[c3_i63 + 1024] = chartInstance->c3_n[c3_i63];
    }

    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 7U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    for (c3_i64 = 0; c3_i64 < 1280; c3_i64++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsH[c3_i64], 10U);
    }

    _SFD_SYMBOL_SCOPE_POP();
  } else {
    c3_Low(chartInstance);
    c3_send(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_High) {
     case c3_IN_b:
      CV_STATE_EVAL(0, 0, 1);
      c3_b(chartInstance);
      break;

     case c3_IN_bml3:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_bml3 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_High = c3_IN_b;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i2 = 0U;
      chartInstance->c3_tp_b = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_init:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_High = c3_IN_b;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i2 = 0U;
      chartInstance->c3_tp_b = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c3_is_High = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testYarpSendParallelBMLsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_testYarpSendParallelBMLs
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_Low(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_bmlID;
  uint32_T c3_c_debug_family_var_map[6];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_poseBML[256];
  real_T c3_dv11[256];
  int32_T c3_i65;
  uint32_T c3_d_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[105];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[105];
  real_T c3_d_nargin = 1.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i66;
  static char_T c3_cv0[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c3_i67;
  static real_T c3_dv12[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  real_T c3_dv13[1280];
  int32_T c3_i76;
  real_T c3_dv14[256];
  real_T c3_dv15[1280];
  int32_T c3_i77;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i80;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_Low) {
   case c3_IN_face:
    CV_STATE_EVAL(6, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_face = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_Low = c3_IN_tt;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_tt = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_gaze:
    CV_STATE_EVAL(6, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_c_sf_marshallIn);
    c3_out = CV_EML_IF(8, 0, 0, chartInstance->c3_temporalCounter_i1 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_gaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_Low = c3_IN_face;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_face = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_p_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      c3_bmlID = 1.0;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
        c3_c_sf_marshallOut, c3_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
        c3_c_sf_marshallOut, c3_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 3U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_bmlID, 4U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poseBML, 5U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      CV_EML_FCN(11, 0);
      _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 3);
      c3_aVarTruthTableCondition_1 = false;
      _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 4);
      c3_aVarTruthTableCondition_2 = false;
      _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 9);
      c3_aVarTruthTableCondition_1 = (c3_bmlID == 1.0);
      _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 13);
      c3_aVarTruthTableCondition_2 = (c3_bmlID == 2.0);
      _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 15);
      if (CV_EML_IF(11, 1, 0, c3_aVarTruthTableCondition_1)) {
        _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 16);
        CV_EML_FCN(11, 1);
        _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 27);
        c3_encStr2Arr(chartInstance, c3_dv11);
        for (c3_i65 = 0; c3_i65 < 256; c3_i65++) {
          c3_poseBML[c3_i65] = c3_dv11[c3_i65];
        }

        c3_updateDataWrittenToVector(chartInstance, 18U);
        _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, -27);
      } else {
        _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 17);
        if (CV_EML_IF(11, 1, 1, c3_aVarTruthTableCondition_2)) {
          _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 18);
          CV_EML_FCN(11, 2);
          _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 33);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_c_debug_family_names,
            c3_d_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_h_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
            c3_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_g_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 6U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 7U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U,
            c3_d_sf_marshallOut, c3_d_sf_marshallIn);
          for (c3_i66 = 0; c3_i66 < 105; c3_i66++) {
            c3_mystr[c3_i66] = c3_cv0[c3_i66];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
          c3_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
          for (c3_i67 = 0; c3_i67 < 105; c3_i67++) {
            c3_arr[c3_i67] = c3_dv12[c3_i67];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
          c3_ss = 105.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
          c3_padsize = c3_maxarrsize - c3_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
          for (c3_i68 = 0; c3_i68 < 256; c3_i68++) {
            c3_b_tt[c3_i68] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
          for (c3_i69 = 0; c3_i69 < 105; c3_i69++) {
            c3_b_tt[c3_i69] = c3_arr[c3_i69];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
          for (c3_i70 = 0; c3_i70 < 256; c3_i70++) {
            c3_myarr256[c3_i70] = c3_b_tt[c3_i70];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c3_i71 = 0; c3_i71 < 256; c3_i71++) {
            c3_poseBML[c3_i71] = c3_myarr256[c3_i71];
          }

          c3_updateDataWrittenToVector(chartInstance, 18U);
          _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, -33);
        } else {
          _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 20);
          CV_EML_FCN(11, 1);
          _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, 27);
          c3_encStr2Arr(chartInstance, c3_dv11);
          for (c3_i72 = 0; c3_i72 < 256; c3_i72++) {
            c3_poseBML[c3_i72] = c3_dv11[c3_i72];
          }

          c3_updateDataWrittenToVector(chartInstance, 18U);
          _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, -27);
        }
      }

      _SFD_EML_CALL(11U, chartInstance->c3_sfEvent, -20);
      _SFD_SYMBOL_SCOPE_POP();
      for (c3_i73 = 0; c3_i73 < 256; c3_i73++) {
        chartInstance->c3_BMLl[c3_i73] = c3_poseBML[c3_i73];
      }

      c3_updateDataWrittenToVector(chartInstance, 0U);
      for (c3_i74 = 0; c3_i74 < 256; c3_i74++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_BMLl[c3_i74], 0U);
      }

      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
      for (c3_i75 = 0; c3_i75 < 1280; c3_i75++) {
        c3_dv13[c3_i75] = chartInstance->c3_bmlsL[c3_i75];
      }

      for (c3_i76 = 0; c3_i76 < 256; c3_i76++) {
        c3_dv14[c3_i76] = chartInstance->c3_BMLl[c3_i76];
      }

      c3_insertQueue(chartInstance, c3_dv13, c3_dv14, c3_dv15);
      for (c3_i77 = 0; c3_i77 < 1280; c3_i77++) {
        chartInstance->c3_newBmlsL[c3_i77] = c3_dv15[c3_i77];
      }

      c3_updateDataWrittenToVector(chartInstance, 12U);
      for (c3_i78 = 0; c3_i78 < 1280; c3_i78++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsL[c3_i78], 12U);
      }

      c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 12U);
      for (c3_i79 = 0; c3_i79 < 1280; c3_i79++) {
        chartInstance->c3_bmlsL[c3_i79] = chartInstance->c3_newBmlsL[c3_i79];
      }

      c3_updateDataWrittenToVector(chartInstance, 5U);
      for (c3_i80 = 0; c3_i80 < 1280; c3_i80++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsL[c3_i80], 5U);
      }

      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_stateInitial:
    CV_STATE_EVAL(6, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_Low = c3_IN_tt;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_tt = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_tt:
    CV_STATE_EVAL(6, 0, 4);
    c3_tt(chartInstance);
    break;

   default:
    CV_STATE_EVAL(6, 0, 0);
    chartInstance->c3_is_Low = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
}

static void c3_tt(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_bmlID;
  uint32_T c3_b_debug_family_var_map[6];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_poseBML[256];
  real_T c3_dv16[256];
  int32_T c3_i81;
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[138];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[138];
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i82;
  static char_T c3_cv1[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i83;
  static real_T c3_dv17[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i90;
  int32_T c3_i91;
  real_T c3_dv18[1280];
  int32_T c3_i92;
  real_T c3_dv19[256];
  real_T c3_dv20[1280];
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_tt = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_Low = c3_IN_gaze;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_gaze = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_bmlID = 2.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_d_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_bmlID, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poseBML, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(9, 0);
  _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 3);
  c3_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 4);
  c3_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 8);
  c3_aVarTruthTableCondition_1 = (c3_bmlID == 1.0);
  _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 11);
  c3_aVarTruthTableCondition_2 = (c3_bmlID == 2.0);
  _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 13);
  if (CV_EML_IF(9, 1, 0, c3_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 14);
    CV_EML_FCN(9, 1);
    _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 25);
    c3_b_encStr2Arr(chartInstance, c3_dv16);
    for (c3_i81 = 0; c3_i81 < 256; c3_i81++) {
      c3_poseBML[c3_i81] = c3_dv16[c3_i81];
    }

    c3_updateDataWrittenToVector(chartInstance, 19U);
    _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, -25);
  } else {
    _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 15);
    if (CV_EML_IF(9, 1, 1, c3_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 16);
      CV_EML_FCN(9, 2);
      _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 31);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_f_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_l_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_k_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 6U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 7U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_d_sf_marshallOut,
        c3_d_sf_marshallIn);
      for (c3_i82 = 0; c3_i82 < 138; c3_i82++) {
        c3_mystr[c3_i82] = c3_cv1[c3_i82];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
      c3_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
      for (c3_i83 = 0; c3_i83 < 138; c3_i83++) {
        c3_arr[c3_i83] = c3_dv17[c3_i83];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
      c3_ss = 138.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
      c3_padsize = c3_maxarrsize - c3_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
      for (c3_i84 = 0; c3_i84 < 256; c3_i84++) {
        c3_b_tt[c3_i84] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
      for (c3_i85 = 0; c3_i85 < 138; c3_i85++) {
        c3_b_tt[c3_i85] = c3_arr[c3_i85];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
      for (c3_i86 = 0; c3_i86 < 256; c3_i86++) {
        c3_myarr256[c3_i86] = c3_b_tt[c3_i86];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c3_i87 = 0; c3_i87 < 256; c3_i87++) {
        c3_poseBML[c3_i87] = c3_myarr256[c3_i87];
      }

      c3_updateDataWrittenToVector(chartInstance, 19U);
      _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, -31);
    } else {
      _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 18);
      CV_EML_FCN(9, 1);
      _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, 25);
      c3_b_encStr2Arr(chartInstance, c3_dv16);
      for (c3_i88 = 0; c3_i88 < 256; c3_i88++) {
        c3_poseBML[c3_i88] = c3_dv16[c3_i88];
      }

      c3_updateDataWrittenToVector(chartInstance, 19U);
      _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, -25);
    }
  }

  _SFD_EML_CALL(9U, chartInstance->c3_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i89 = 0; c3_i89 < 256; c3_i89++) {
    chartInstance->c3_BMLl[c3_i89] = c3_poseBML[c3_i89];
  }

  c3_updateDataWrittenToVector(chartInstance, 0U);
  for (c3_i90 = 0; c3_i90 < 256; c3_i90++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BMLl[c3_i90], 0U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
  for (c3_i91 = 0; c3_i91 < 1280; c3_i91++) {
    c3_dv18[c3_i91] = chartInstance->c3_bmlsL[c3_i91];
  }

  for (c3_i92 = 0; c3_i92 < 256; c3_i92++) {
    c3_dv19[c3_i92] = chartInstance->c3_BMLl[c3_i92];
  }

  c3_insertQueue(chartInstance, c3_dv18, c3_dv19, c3_dv20);
  for (c3_i93 = 0; c3_i93 < 1280; c3_i93++) {
    chartInstance->c3_newBmlsL[c3_i93] = c3_dv20[c3_i93];
  }

  c3_updateDataWrittenToVector(chartInstance, 12U);
  for (c3_i94 = 0; c3_i94 < 1280; c3_i94++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsL[c3_i94], 12U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 12U);
  for (c3_i95 = 0; c3_i95 < 1280; c3_i95++) {
    chartInstance->c3_bmlsL[c3_i95] = chartInstance->c3_newBmlsL[c3_i95];
  }

  c3_updateDataWrittenToVector(chartInstance, 5U);
  for (c3_i96 = 0; c3_i96 < 1280; c3_i96++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsL[c3_i96], 5U);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c3_sfEvent);
}

static void c3_b(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_bmlID;
  uint32_T c3_c_debug_family_var_map[7];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  boolean_T c3_aVarTruthTableCondition_3;
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_poseBML[256];
  real_T c3_dv21[256];
  int32_T c3_i97;
  int32_T c3_i98;
  uint32_T c3_d_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[99];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[99];
  real_T c3_d_nargin = 1.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i99;
  static char_T c3_cv2[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't',
    'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_',
    'S', 'h', 'a', 'k', 'e', '_', 'F', 'i', 's', 't', '.', 's', 'k', 'm', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i100;
  static real_T c3_dv22[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 83.0, 104.0, 97.0, 107.0, 101.0, 95.0, 70.0,
    105.0, 115.0, 116.0, 46.0, 115.0, 107.0, 109.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  real_T c3_dv23[1280];
  int32_T c3_i109;
  real_T c3_dv24[256];
  real_T c3_dv25[1280];
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  int32_T c3_i113;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_cb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  c3_out = CV_EML_IF(12, 0, 0, chartInstance->c3_temporalCounter_i2 >= 10);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_b = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_High = c3_IN_bml3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_bml3 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_r_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_bmlID = 2.0;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_g_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
      c3_c_sf_marshallOut, c3_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
      c3_c_sf_marshallOut, c3_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_3, 2U,
      c3_c_sf_marshallOut, c3_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 3U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 4U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_bmlID, 5U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poseBML, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    CV_EML_FCN(5, 0);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 3);
    c3_aVarTruthTableCondition_1 = false;
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 4);
    c3_aVarTruthTableCondition_2 = false;
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 5);
    c3_aVarTruthTableCondition_3 = false;
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 10);
    c3_aVarTruthTableCondition_1 = (c3_bmlID == 1.0);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 14);
    c3_aVarTruthTableCondition_2 = (c3_bmlID == 2.0);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 18);
    c3_aVarTruthTableCondition_3 = (c3_bmlID == 3.0);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 20);
    if (CV_EML_IF(5, 1, 0, c3_aVarTruthTableCondition_1)) {
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 21);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 34);
      c3_c_encStr2Arr(chartInstance, c3_dv21);
      for (c3_i97 = 0; c3_i97 < 256; c3_i97++) {
        c3_poseBML[c3_i97] = c3_dv21[c3_i97];
      }

      c3_updateDataWrittenToVector(chartInstance, 20U);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -34);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 22);
      if (CV_EML_IF(5, 1, 1, c3_aVarTruthTableCondition_2)) {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 23);
        CV_EML_FCN(5, 2);
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 40);
        c3_d_encStr2Arr(chartInstance, c3_dv21);
        for (c3_i98 = 0; c3_i98 < 256; c3_i98++) {
          c3_poseBML[c3_i98] = c3_dv21[c3_i98];
        }

        c3_updateDataWrittenToVector(chartInstance, 20U);
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -40);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 24);
        if (CV_EML_IF(5, 1, 2, c3_aVarTruthTableCondition_3)) {
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 25);
          CV_EML_FCN(5, 3);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 46);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_j_debug_family_names,
            c3_d_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_p_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
            c3_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_o_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 6U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 7U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U,
            c3_d_sf_marshallOut, c3_d_sf_marshallIn);
          for (c3_i99 = 0; c3_i99 < 99; c3_i99++) {
            c3_mystr[c3_i99] = c3_cv2[c3_i99];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
          c3_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
          for (c3_i100 = 0; c3_i100 < 99; c3_i100++) {
            c3_arr[c3_i100] = c3_dv22[c3_i100];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
          c3_ss = 99.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
          c3_padsize = c3_maxarrsize - c3_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
          for (c3_i101 = 0; c3_i101 < 256; c3_i101++) {
            c3_b_tt[c3_i101] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
          for (c3_i102 = 0; c3_i102 < 99; c3_i102++) {
            c3_b_tt[c3_i102] = c3_arr[c3_i102];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
          for (c3_i103 = 0; c3_i103 < 256; c3_i103++) {
            c3_myarr256[c3_i103] = c3_b_tt[c3_i103];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c3_i104 = 0; c3_i104 < 256; c3_i104++) {
            c3_poseBML[c3_i104] = c3_myarr256[c3_i104];
          }

          c3_updateDataWrittenToVector(chartInstance, 20U);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -46);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 27);
          CV_EML_FCN(5, 1);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 34);
          c3_c_encStr2Arr(chartInstance, c3_dv21);
          for (c3_i105 = 0; c3_i105 < 256; c3_i105++) {
            c3_poseBML[c3_i105] = c3_dv21[c3_i105];
          }

          c3_updateDataWrittenToVector(chartInstance, 20U);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -34);
        }
      }
    }

    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -27);
    _SFD_SYMBOL_SCOPE_POP();
    for (c3_i106 = 0; c3_i106 < 256; c3_i106++) {
      chartInstance->c3_BMLh[c3_i106] = c3_poseBML[c3_i106];
    }

    c3_updateDataWrittenToVector(chartInstance, 6U);
    for (c3_i107 = 0; c3_i107 < 256; c3_i107++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_BMLh[c3_i107], 6U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 6U);
    for (c3_i108 = 0; c3_i108 < 1280; c3_i108++) {
      c3_dv23[c3_i108] = chartInstance->c3_bmlsH[c3_i108];
    }

    for (c3_i109 = 0; c3_i109 < 256; c3_i109++) {
      c3_dv24[c3_i109] = chartInstance->c3_BMLh[c3_i109];
    }

    c3_b_insertQueue(chartInstance, c3_dv23, c3_dv24, c3_dv25);
    for (c3_i110 = 0; c3_i110 < 1280; c3_i110++) {
      chartInstance->c3_newBmlsH[c3_i110] = c3_dv25[c3_i110];
    }

    c3_updateDataWrittenToVector(chartInstance, 10U);
    for (c3_i111 = 0; c3_i111 < 1280; c3_i111++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsH[c3_i111], 10U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 10U);
    for (c3_i112 = 0; c3_i112 < 1280; c3_i112++) {
      chartInstance->c3_bmlsH[c3_i112] = chartInstance->c3_newBmlsH[c3_i112];
    }

    c3_updateDataWrittenToVector(chartInstance, 2U);
    for (c3_i113 = 0; c3_i113 < 1280; c3_i113++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i113], 2U);
    }

    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void c3_send(SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  int32_T c3_i114;
  real_T c3_dv26[1280];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  int32_T c3_i115;
  real_T c3_dv27[1280];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i116;
  int32_T c3_i117;
  int32_T c3_i118;
  real_T c3_dv28[256];
  int32_T c3_i119;
  real_T c3_dv29[1280];
  real_T c3_dv30[1280];
  int32_T c3_i120;
  int32_T c3_i121;
  int32_T c3_i122;
  int32_T c3_i123;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  int32_T c3_i124;
  real_T c3_dv31[1280];
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  int32_T c3_i125;
  real_T c3_dv32[1280];
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  int32_T c3_i126;
  real_T c3_dv33[1280];
  real_T (*c3_c_y)[2];
  c3_c_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_send) {
   case c3_IN_checkHighPriority:
    CV_STATE_EVAL(17, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_eb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    chartInstance->c3_bHand = (*c3_c_y)[1];
    c3_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bHand, 13U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 13U, 13U);
    sf_mex_printf("%s =\\n", "bHand");
    c3_hoistedGlobal = chartInstance->c3_bHand;
    c3_u = c3_hoistedGlobal;
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_db_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    chartInstance->c3_cHand = (*c3_c_y)[0];
    c3_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_cHand, 15U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 14U, 15U);
    sf_mex_printf("%s =\\n", "cHand");
    c3_b_hoistedGlobal = chartInstance->c3_cHand;
    c3_b_u = c3_b_hoistedGlobal;
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_b_y);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_tp_checkHighPriority = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_send = c3_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
    for (c3_i114 = 0; c3_i114 < 1280; c3_i114++) {
      c3_dv26[c3_i114] = chartInstance->c3_bmlsH[c3_i114];
    }

    chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv26);
    c3_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 8U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c3_sfEvent);
    break;

   case c3_b_IN_init:
    CV_STATE_EVAL(17, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
    chartInstance->c3_b_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_send = c3_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
    for (c3_i115 = 0; c3_i115 < 1280; c3_i115++) {
      c3_dv27[c3_i115] = chartInstance->c3_bmlsH[c3_i115];
    }

    chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv27);
    c3_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 8U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_low:
    CV_STATE_EVAL(17, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ib_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_c_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 9U);
    c3_out = CV_EML_IF(2, 0, 0, chartInstance->c3_lEmpty != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_low = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_send = c3_IN_sendL;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendL = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_y_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
      for (c3_i116 = 0; c3_i116 < 256; c3_i116++) {
        chartInstance->c3_BML[c3_i116] = chartInstance->c3_bmlsL[c3_i116];
      }

      c3_updateDataWrittenToVector(chartInstance, 3U);
      for (c3_i117 = 0; c3_i117 < 256; c3_i117++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_BML[c3_i117], 3U);
      }

      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 3U);
      for (c3_i118 = 0; c3_i118 < 256; c3_i118++) {
        c3_dv28[c3_i118] = chartInstance->c3_BML[c3_i118];
      }

      c3_sendBML(chartInstance, c3_dv28);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 5U);
      for (c3_i119 = 0; c3_i119 < 1280; c3_i119++) {
        c3_dv29[c3_i119] = chartInstance->c3_bmlsL[c3_i119];
      }

      c3_removeQueue(chartInstance, c3_dv29, c3_dv30);
      for (c3_i120 = 0; c3_i120 < 1280; c3_i120++) {
        chartInstance->c3_newBmlsL[c3_i120] = c3_dv30[c3_i120];
      }

      c3_updateDataWrittenToVector(chartInstance, 12U);
      for (c3_i121 = 0; c3_i121 < 1280; c3_i121++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsL[c3_i121], 12U);
      }

      c3_errorIfDataNotWrittenToFcn(chartInstance, 12U, 12U);
      for (c3_i122 = 0; c3_i122 < 1280; c3_i122++) {
        chartInstance->c3_bmlsL[c3_i122] = chartInstance->c3_newBmlsL[c3_i122];
      }

      c3_updateDataWrittenToVector(chartInstance, 5U);
      for (c3_i123 = 0; c3_i123 < 1280; c3_i123++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsL[c3_i123], 5U);
      }

      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_hb_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
        c3_b_sf_marshallOut, c3_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 9U);
      c3_b_out = CV_EML_IF(14, 0, 0, chartInstance->c3_lEmpty == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_low = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_send = c3_IN_checkHighPriority;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_checkHighPriority = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U,
          c3_b_sf_marshallOut, c3_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_b_sf_marshallOut, c3_b_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
        for (c3_i124 = 0; c3_i124 < 1280; c3_i124++) {
          c3_dv31[c3_i124] = chartInstance->c3_bmlsH[c3_i124];
        }

        chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv31);
        c3_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 8U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_sendH:
    CV_STATE_EVAL(17, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_sendH = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_send = c3_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
    for (c3_i125 = 0; c3_i125 < 1280; c3_i125++) {
      c3_dv32[c3_i125] = chartInstance->c3_bmlsH[c3_i125];
    }

    chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv32);
    c3_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 8U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_sendL:
    CV_STATE_EVAL(17, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_sendL = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_send = c3_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
    for (c3_i126 = 0; c3_i126 < 1280; c3_i126++) {
      c3_dv33[c3_i126] = chartInstance->c3_bmlsH[c3_i126];
    }

    chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv33);
    c3_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 8U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(17, 0, 0);
    chartInstance->c3_is_send = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c3_sfEvent);
}

static void c3_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[224];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[224];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i127;
  static char_T c3_cv3[224] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c', 't',
    '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '5', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '8', '\"',
    ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=',
    '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '5', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"',
    '8', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i128;
  static real_T c3_dv34[224] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 53.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 56.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0,
    51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0,
    100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0,
    97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 56.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 48.0,
    34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c3_i129;
  int32_T c3_i130;
  int32_T c3_i131;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  for (c3_i127 = 0; c3_i127 < 224; c3_i127++) {
    c3_mystr[c3_i127] = c3_cv3[c3_i127];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i128 = 0; c3_i128 < 224; c3_i128++) {
    c3_arr[c3_i128] = c3_dv34[c3_i128];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 224.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i129 = 0; c3_i129 < 256; c3_i129++) {
    c3_b_tt[c3_i129] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i130 = 0; c3_i130 < 224; c3_i130++) {
    c3_b_tt[c3_i130] = c3_arr[c3_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i131 = 0; c3_i131 < 256; c3_i131++) {
    c3_myarr256[c3_i131] = c3_b_tt[c3_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_b_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[238];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[238];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i132;
  static char_T c3_cv4[238] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '3', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1',
    '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '3', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c3_i133;
  static real_T c3_dv35[238] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0,
    97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 100.0,
    105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i134;
  int32_T c3_i135;
  int32_T c3_i136;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  for (c3_i132 = 0; c3_i132 < 238; c3_i132++) {
    c3_mystr[c3_i132] = c3_cv4[c3_i132];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i133 = 0; c3_i133 < 238; c3_i133++) {
    c3_arr[c3_i133] = c3_dv35[c3_i133];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 238.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i134 = 0; c3_i134 < 256; c3_i134++) {
    c3_b_tt[c3_i134] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i135 = 0; c3_i135 < 238; c3_i135++) {
    c3_b_tt[c3_i135] = c3_arr[c3_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i136 = 0; c3_i136 < 256; c3_i136++) {
    c3_myarr256[c3_i136] = c3_b_tt[c3_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_c_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[144];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[144];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i137;
  static char_T c3_cv5[144] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\"', '1',
    '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '2', '\"', ' ', 'r', 'e',
    'l', 'a', 'x', '=', '\"', '3', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4',
    '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c3_i138;
  static real_T c3_dv36[144] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0,
    34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 52.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i139;
  int32_T c3_i140;
  int32_T c3_i141;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_h_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  for (c3_i137 = 0; c3_i137 < 144; c3_i137++) {
    c3_mystr[c3_i137] = c3_cv5[c3_i137];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i138 = 0; c3_i138 < 144; c3_i138++) {
    c3_arr[c3_i138] = c3_dv36[c3_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 144.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i139 = 0; c3_i139 < 256; c3_i139++) {
    c3_b_tt[c3_i139] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i140 = 0; c3_i140 < 144; c3_i140++) {
    c3_b_tt[c3_i140] = c3_arr[c3_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i141 = 0; c3_i141 < 256; c3_i141++) {
    c3_myarr256[c3_i141] = c3_b_tt[c3_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_d_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[144];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr[144];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i142;
  static char_T c3_cv6[144] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\"', '1',
    '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '2', '\"', ' ', 'r', 'e',
    'l', 'a', 'x', '=', '\"', '3', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4',
    '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c3_i143;
  static real_T c3_dv37[144] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0,
    34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 52.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i144;
  int32_T c3_i145;
  int32_T c3_i146;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_i_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  for (c3_i142 = 0; c3_i142 < 144; c3_i142++) {
    c3_mystr[c3_i142] = c3_cv6[c3_i142];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i143 = 0; c3_i143 < 144; c3_i143++) {
    c3_arr[c3_i143] = c3_dv37[c3_i143];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 144.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i144 = 0; c3_i144 < 256; c3_i144++) {
    c3_b_tt[c3_i144] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i145 = 0; c3_i145 < 144; c3_i145++) {
    c3_b_tt[c3_i145] = c3_arr[c3_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i146 = 0; c3_i146 < 256; c3_i146++) {
    c3_myarr256[c3_i146] = c3_b_tt[c3_i146];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_e_encStr2Arr(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr;
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_b_tt[256];
  char_T c3_mystr;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i147;
  int32_T c3_i148;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_l_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_arr, 1U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tt, 4U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_mystr, 5U, c3_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  c3_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i147 = 0; c3_i147 < 256; c3_i147++) {
    c3_b_tt[c3_i147] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_b_tt[0] = c3_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i148 = 0; c3_i148 < 256; c3_i148++) {
    c3_myarr256[c3_i148] = c3_b_tt[c3_i148];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c3_isequal(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_varargin_1[256], real_T c3_varargin_2[256])
{
  boolean_T c3_p;
  boolean_T c3_b_p;
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_x1;
  real_T c3_x2;
  boolean_T c3_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c3_p = false;
  c3_b_p = true;
  c3_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c3_k < 256)) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_x1 = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 256, 1, 0) - 1];
    c3_x2 = c3_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 256, 1, 0) - 1];
    c3_c_p = (c3_x1 == c3_x2);
    if (!c3_c_p) {
      c3_b_p = false;
      exitg1 = true;
    } else {
      c3_k++;
    }
  }

  if (!c3_b_p) {
  } else {
    c3_p = true;
  }

  return c3_p;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\25-9-2015-Matlab-Demo-v2\\encStr2Arr.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i149;
  real_T c3_b_inData[256];
  int32_T c3_i150;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i149 = 0; c3_i149 < 256; c3_i149++) {
    c3_b_inData[c3_i149] = (*(real_T (*)[256])c3_inData)[c3_i149];
  }

  for (c3_i150 = 0; c3_i150 < 256; c3_i150++) {
    c3_u[c3_i150] = c3_b_inData[c3_i150];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_poseBML, const char_T *c3_identifier, real_T
  c3_y[256])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_poseBML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_poseBML);
}

static void c3_b_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv38[256];
  int32_T c3_i151;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv38, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c3_i151 = 0; c3_i151 < 256; c3_i151++) {
    c3_y[c3_i151] = c3_dv38[c3_i151];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_poseBML;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i152;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_poseBML = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_poseBML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_poseBML);
  for (c3_i152 = 0; c3_i152 < 256; c3_i152++) {
    (*(real_T (*)[256])c3_outData)[c3_i152] = c3_y[c3_i152];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct *
  chartInstance, const mxArray *c3_bmlID, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_bmlID), &c3_thisId);
  sf_mex_destroy(&c3_bmlID);
  return c3_y;
}

static real_T c3_d_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_bmlID;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_bmlID = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_bmlID), &c3_thisId);
  sf_mex_destroy(&c3_bmlID);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_e_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_aVarTruthTableCondition_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_aVarTruthTableCondition_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_aVarTruthTableCondition_2), &c3_thisId);
  sf_mex_destroy(&c3_aVarTruthTableCondition_2);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i153;
  real_T c3_b_inData[256];
  int32_T c3_i154;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i153 = 0; c3_i153 < 256; c3_i153++) {
    c3_b_inData[c3_i153] = (*(real_T (*)[256])c3_inData)[c3_i153];
  }

  for (c3_i154 = 0; c3_i154 < 256; c3_i154++) {
    c3_u[c3_i154] = c3_b_inData[c3_i154];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_f_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv39[256];
  int32_T c3_i155;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv39, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i155 = 0; c3_i155 < 256; c3_i155++) {
    c3_y[c3_i155] = c3_dv39[c3_i155];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i156;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i156 = 0; c3_i156 < 256; c3_i156++) {
    (*(real_T (*)[256])c3_outData)[c3_i156] = c3_y[c3_i156];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i157;
  char_T c3_b_inData[224];
  int32_T c3_i158;
  char_T c3_u[224];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i157 = 0; c3_i157 < 224; c3_i157++) {
    c3_b_inData[c3_i157] = (*(char_T (*)[224])c3_inData)[c3_i157];
  }

  for (c3_i158 = 0; c3_i158 < 224; c3_i158++) {
    c3_u[c3_i158] = c3_b_inData[c3_i158];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 224),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i159;
  real_T c3_b_inData[224];
  int32_T c3_i160;
  real_T c3_u[224];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i159 = 0; c3_i159 < 224; c3_i159++) {
    c3_b_inData[c3_i159] = (*(real_T (*)[224])c3_inData)[c3_i159];
  }

  for (c3_i160 = 0; c3_i160 < 224; c3_i160++) {
    c3_u[c3_i160] = c3_b_inData[c3_i160];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 224), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i161;
  char_T c3_b_inData[105];
  int32_T c3_i162;
  char_T c3_u[105];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i161 = 0; c3_i161 < 105; c3_i161++) {
    c3_b_inData[c3_i161] = (*(char_T (*)[105])c3_inData)[c3_i161];
  }

  for (c3_i162 = 0; c3_i162 < 105; c3_i162++) {
    c3_u[c3_i162] = c3_b_inData[c3_i162];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i163;
  real_T c3_b_inData[105];
  int32_T c3_i164;
  real_T c3_u[105];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i163 = 0; c3_i163 < 105; c3_i163++) {
    c3_b_inData[c3_i163] = (*(real_T (*)[105])c3_inData)[c3_i163];
  }

  for (c3_i164 = 0; c3_i164 < 105; c3_i164++) {
    c3_u[c3_i164] = c3_b_inData[c3_i164];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i165;
  char_T c3_b_inData[238];
  int32_T c3_i166;
  char_T c3_u[238];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i165 = 0; c3_i165 < 238; c3_i165++) {
    c3_b_inData[c3_i165] = (*(char_T (*)[238])c3_inData)[c3_i165];
  }

  for (c3_i166 = 0; c3_i166 < 238; c3_i166++) {
    c3_u[c3_i166] = c3_b_inData[c3_i166];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 238),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i167;
  real_T c3_b_inData[238];
  int32_T c3_i168;
  real_T c3_u[238];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i167 = 0; c3_i167 < 238; c3_i167++) {
    c3_b_inData[c3_i167] = (*(real_T (*)[238])c3_inData)[c3_i167];
  }

  for (c3_i168 = 0; c3_i168 < 238; c3_i168++) {
    c3_u[c3_i168] = c3_b_inData[c3_i168];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 238), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i169;
  char_T c3_b_inData[138];
  int32_T c3_i170;
  char_T c3_u[138];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i169 = 0; c3_i169 < 138; c3_i169++) {
    c3_b_inData[c3_i169] = (*(char_T (*)[138])c3_inData)[c3_i169];
  }

  for (c3_i170 = 0; c3_i170 < 138; c3_i170++) {
    c3_u[c3_i170] = c3_b_inData[c3_i170];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i171;
  real_T c3_b_inData[138];
  int32_T c3_i172;
  real_T c3_u[138];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i171 = 0; c3_i171 < 138; c3_i171++) {
    c3_b_inData[c3_i171] = (*(real_T (*)[138])c3_inData)[c3_i171];
  }

  for (c3_i172 = 0; c3_i172 < 138; c3_i172++) {
    c3_u[c3_i172] = c3_b_inData[c3_i172];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i173;
  char_T c3_b_inData[144];
  int32_T c3_i174;
  char_T c3_u[144];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i173 = 0; c3_i173 < 144; c3_i173++) {
    c3_b_inData[c3_i173] = (*(char_T (*)[144])c3_inData)[c3_i173];
  }

  for (c3_i174 = 0; c3_i174 < 144; c3_i174++) {
    c3_u[c3_i174] = c3_b_inData[c3_i174];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 144),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i175;
  real_T c3_b_inData[144];
  int32_T c3_i176;
  real_T c3_u[144];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i175 = 0; c3_i175 < 144; c3_i175++) {
    c3_b_inData[c3_i175] = (*(real_T (*)[144])c3_inData)[c3_i175];
  }

  for (c3_i176 = 0; c3_i176 < 144; c3_i176++) {
    c3_u[c3_i176] = c3_b_inData[c3_i176];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 144), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i177;
  char_T c3_b_inData[99];
  int32_T c3_i178;
  char_T c3_u[99];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i177 = 0; c3_i177 < 99; c3_i177++) {
    c3_b_inData[c3_i177] = (*(char_T (*)[99])c3_inData)[c3_i177];
  }

  for (c3_i178 = 0; c3_i178 < 99; c3_i178++) {
    c3_u[c3_i178] = c3_b_inData[c3_i178];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 99), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i179;
  real_T c3_b_inData[99];
  int32_T c3_i180;
  real_T c3_u[99];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i179 = 0; c3_i179 < 99; c3_i179++) {
    c3_b_inData[c3_i179] = (*(real_T (*)[99])c3_inData)[c3_i179];
  }

  for (c3_i180 = 0; c3_i180 < 99; c3_i180++) {
    c3_u[c3_i180] = c3_b_inData[c3_i180];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  char_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(char_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i181;
  int32_T c3_i182;
  int32_T c3_i183;
  real_T c3_b_inData[1280];
  int32_T c3_i184;
  int32_T c3_i185;
  int32_T c3_i186;
  real_T c3_u[1280];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i181 = 0;
  for (c3_i182 = 0; c3_i182 < 5; c3_i182++) {
    for (c3_i183 = 0; c3_i183 < 256; c3_i183++) {
      c3_b_inData[c3_i183 + c3_i181] = (*(real_T (*)[1280])c3_inData)[c3_i183 +
        c3_i181];
    }

    c3_i181 += 256;
  }

  c3_i184 = 0;
  for (c3_i185 = 0; c3_i185 < 5; c3_i185++) {
    for (c3_i186 = 0; c3_i186 < 256; c3_i186++) {
      c3_u[c3_i186 + c3_i184] = c3_b_inData[c3_i186 + c3_i184];
    }

    c3_i184 += 256;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 5), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_newBmls, const char_T *c3_identifier, real_T
  c3_y[1280])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_newBmls), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_newBmls);
}

static void c3_h_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[1280])
{
  real_T c3_dv40[1280];
  int32_T c3_i187;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv40, 1, 0, 0U, 1, 0U, 2, 256,
                5);
  for (c3_i187 = 0; c3_i187 < 1280; c3_i187++) {
    c3_y[c3_i187] = c3_dv40[c3_i187];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_newBmls;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[1280];
  int32_T c3_i188;
  int32_T c3_i189;
  int32_T c3_i190;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_newBmls = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_newBmls), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_newBmls);
  c3_i188 = 0;
  for (c3_i189 = 0; c3_i189 < 5; c3_i189++) {
    for (c3_i190 = 0; c3_i190 < 256; c3_i190++) {
      (*(real_T (*)[1280])c3_outData)[c3_i190 + c3_i188] = c3_y[c3_i190 +
        c3_i188];
    }

    c3_i188 += 256;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_testYarpSendParallelBMLs_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 5, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/25-9-2015-Matlab-Demo-v2/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static void c3_sendBML(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_arg[256])
{
  int32_T c3_i191;
  int32_T c3_i192;
  int32_T c3_i193;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c3_i191 = 0; c3_i191 < 256; c3_i191++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i191], 31U);
  }

  _SFD_SET_DATA_VALUE_PTR(31U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c3_sfEvent);
  for (c3_i192 = 0; c3_i192 < 256; c3_i192++) {
    (*c3_b_arg)[c3_i192] = c3_arg[c3_i192];
  }

  for (c3_i193 = 0; c3_i193 < 256; c3_i193++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i193], 31U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(31U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c3_sfEvent);
}

static void c3_insertQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280], real_T c3_mBML[256], real_T c3_newBmls
  [1280])
{
  uint32_T c3_debug_family_var_map[7];
  real_T c3_full;
  real_T c3_t[256];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i194;
  static real_T c3_dv41[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c3_i195;
  int32_T c3_i196;
  int32_T c3_i197;
  int32_T c3_i198;
  int32_T c3_i199;
  int32_T c3_b_i;
  int32_T c3_i200;
  int32_T c3_i201;
  real_T c3_b_bmls[256];
  int32_T c3_i202;
  real_T c3_dv42[256];
  int32_T c3_i203;
  int32_T c3_i204;
  int32_T c3_i205;
  real_T c3_c_bmls[256];
  int32_T c3_i206;
  int32_T c3_i207;
  real_T c3_d_bmls[256];
  int32_T c3_i208;
  int32_T c3_i209;
  real_T c3_e_bmls[256];
  int32_T c3_i210;
  int32_T c3_i211;
  int32_T c3_i212;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_o_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_full, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_t, 1U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bmls, 4U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mBML, 5U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_newBmls, 6U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  CV_EML_FCN(10, 0);
  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 2);
  c3_full = 1.0;
  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 3);
  for (c3_i194 = 0; c3_i194 < 256; c3_i194++) {
    c3_t[c3_i194] = c3_dv41[c3_i194];
  }

  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 4);
  for (c3_i195 = 0; c3_i195 < 256; c3_i195++) {
    c3_newBmls[c3_i195] = c3_t[c3_i195];
  }

  for (c3_i196 = 0; c3_i196 < 256; c3_i196++) {
    c3_newBmls[c3_i196 + 256] = c3_t[c3_i196];
  }

  for (c3_i197 = 0; c3_i197 < 256; c3_i197++) {
    c3_newBmls[c3_i197 + 512] = c3_t[c3_i197];
  }

  for (c3_i198 = 0; c3_i198 < 256; c3_i198++) {
    c3_newBmls[c3_i198 + 768] = c3_t[c3_i198];
  }

  for (c3_i199 = 0; c3_i199 < 256; c3_i199++) {
    c3_newBmls[c3_i199 + 1024] = c3_t[c3_i199];
  }

  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 5);
  chartInstance->c3_i = 1.0;
  c3_updateDataWrittenToVector(chartInstance, 11U);
  c3_b_i = 0;
  do {
    exitg1 = 0;
    if (c3_b_i < 5) {
      chartInstance->c3_i = 1.0 + (real_T)c3_b_i;
      c3_updateDataWrittenToVector(chartInstance, 11U);
      CV_EML_FOR(10, 1, 0, 1);
      _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 6);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 11U);
      c3_i200 = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", chartInstance->c3_i), 1, 5, 2, 0) - 1;
      for (c3_i201 = 0; c3_i201 < 256; c3_i201++) {
        c3_b_bmls[c3_i201] = c3_bmls[c3_i201 + (c3_i200 << 8)];
      }

      for (c3_i202 = 0; c3_i202 < 256; c3_i202++) {
        c3_dv42[c3_i202] = c3_dv41[c3_i202];
      }

      if (CV_EML_IF(10, 1, 0, c3_isequal(chartInstance, c3_b_bmls, c3_dv42))) {
        _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 8);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 11U);
        c3_i203 = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)
          _SFD_INTEGER_CHECK("i", chartInstance->c3_i), 1, 5, 2, 0) - 1;
        for (c3_i204 = 0; c3_i204 < 256; c3_i204++) {
          c3_bmls[c3_i204 + (c3_i203 << 8)] = c3_mBML[c3_i204];
        }

        _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 9);
        c3_full = 0.0;
        _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 10);
        exitg1 = 1;
      } else {
        c3_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(10, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 13);
  if (CV_EML_IF(10, 1, 1, c3_full != 0.0)) {
    _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 15);
    for (c3_i205 = 0; c3_i205 < 256; c3_i205++) {
      c3_c_bmls[c3_i205] = c3_bmls[c3_i205 + 256];
    }

    for (c3_i206 = 0; c3_i206 < 256; c3_i206++) {
      c3_bmls[c3_i206] = c3_c_bmls[c3_i206];
    }

    _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 16);
    for (c3_i207 = 0; c3_i207 < 256; c3_i207++) {
      c3_d_bmls[c3_i207] = c3_bmls[c3_i207 + 512];
    }

    for (c3_i208 = 0; c3_i208 < 256; c3_i208++) {
      c3_bmls[c3_i208 + 256] = c3_d_bmls[c3_i208];
    }

    _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 17);
    for (c3_i209 = 0; c3_i209 < 256; c3_i209++) {
      c3_e_bmls[c3_i209] = c3_bmls[c3_i209 + 768];
    }

    for (c3_i210 = 0; c3_i210 < 256; c3_i210++) {
      c3_bmls[c3_i210 + 512] = c3_e_bmls[c3_i210];
    }

    _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 18);
    for (c3_i211 = 0; c3_i211 < 256; c3_i211++) {
      c3_bmls[c3_i211 + 1024] = c3_mBML[c3_i211];
    }
  }

  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, 20);
  for (c3_i212 = 0; c3_i212 < 1280; c3_i212++) {
    c3_newBmls[c3_i212] = c3_bmls[c3_i212];
  }

  _SFD_EML_CALL(10U, chartInstance->c3_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_b_insertQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280], real_T c3_mBML[256], real_T c3_newBmls
  [1280])
{
  uint32_T c3_debug_family_var_map[7];
  real_T c3_full;
  real_T c3_t[256];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i213;
  static real_T c3_dv43[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c3_i214;
  int32_T c3_i215;
  int32_T c3_i216;
  int32_T c3_i217;
  int32_T c3_i218;
  int32_T c3_b_i;
  int32_T c3_i219;
  int32_T c3_i220;
  real_T c3_b_bmls[256];
  int32_T c3_i221;
  real_T c3_dv44[256];
  int32_T c3_i222;
  int32_T c3_i223;
  int32_T c3_i224;
  real_T c3_c_bmls[256];
  int32_T c3_i225;
  int32_T c3_i226;
  real_T c3_d_bmls[256];
  int32_T c3_i227;
  int32_T c3_i228;
  real_T c3_e_bmls[256];
  int32_T c3_i229;
  int32_T c3_i230;
  int32_T c3_i231;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_s_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_full, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_t, 1U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bmls, 4U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mBML, 5U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_newBmls, 6U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 2);
  c3_full = 1.0;
  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 3);
  for (c3_i213 = 0; c3_i213 < 256; c3_i213++) {
    c3_t[c3_i213] = c3_dv43[c3_i213];
  }

  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 4);
  for (c3_i214 = 0; c3_i214 < 256; c3_i214++) {
    c3_newBmls[c3_i214] = c3_t[c3_i214];
  }

  for (c3_i215 = 0; c3_i215 < 256; c3_i215++) {
    c3_newBmls[c3_i215 + 256] = c3_t[c3_i215];
  }

  for (c3_i216 = 0; c3_i216 < 256; c3_i216++) {
    c3_newBmls[c3_i216 + 512] = c3_t[c3_i216];
  }

  for (c3_i217 = 0; c3_i217 < 256; c3_i217++) {
    c3_newBmls[c3_i217 + 768] = c3_t[c3_i217];
  }

  for (c3_i218 = 0; c3_i218 < 256; c3_i218++) {
    c3_newBmls[c3_i218 + 1024] = c3_t[c3_i218];
  }

  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 5);
  chartInstance->c3_i = 1.0;
  c3_updateDataWrittenToVector(chartInstance, 11U);
  c3_b_i = 0;
  do {
    exitg1 = 0;
    if (c3_b_i < 5) {
      chartInstance->c3_i = 1.0 + (real_T)c3_b_i;
      c3_updateDataWrittenToVector(chartInstance, 11U);
      CV_EML_FOR(4, 1, 0, 1);
      _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 6);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 11U);
      c3_i219 = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", chartInstance->c3_i), 1, 5, 2, 0) - 1;
      for (c3_i220 = 0; c3_i220 < 256; c3_i220++) {
        c3_b_bmls[c3_i220] = c3_bmls[c3_i220 + (c3_i219 << 8)];
      }

      for (c3_i221 = 0; c3_i221 < 256; c3_i221++) {
        c3_dv44[c3_i221] = c3_dv43[c3_i221];
      }

      if (CV_EML_IF(4, 1, 0, c3_isequal(chartInstance, c3_b_bmls, c3_dv44))) {
        _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 8);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 11U);
        c3_i222 = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)
          _SFD_INTEGER_CHECK("i", chartInstance->c3_i), 1, 5, 2, 0) - 1;
        for (c3_i223 = 0; c3_i223 < 256; c3_i223++) {
          c3_bmls[c3_i223 + (c3_i222 << 8)] = c3_mBML[c3_i223];
        }

        _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 9);
        c3_full = 0.0;
        _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 10);
        exitg1 = 1;
      } else {
        c3_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(4, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 13);
  if (CV_EML_IF(4, 1, 1, c3_full != 0.0)) {
    _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 15);
    for (c3_i224 = 0; c3_i224 < 256; c3_i224++) {
      c3_c_bmls[c3_i224] = c3_bmls[c3_i224 + 256];
    }

    for (c3_i225 = 0; c3_i225 < 256; c3_i225++) {
      c3_bmls[c3_i225] = c3_c_bmls[c3_i225];
    }

    _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 16);
    for (c3_i226 = 0; c3_i226 < 256; c3_i226++) {
      c3_d_bmls[c3_i226] = c3_bmls[c3_i226 + 512];
    }

    for (c3_i227 = 0; c3_i227 < 256; c3_i227++) {
      c3_bmls[c3_i227 + 256] = c3_d_bmls[c3_i227];
    }

    _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 17);
    for (c3_i228 = 0; c3_i228 < 256; c3_i228++) {
      c3_e_bmls[c3_i228] = c3_bmls[c3_i228 + 768];
    }

    for (c3_i229 = 0; c3_i229 < 256; c3_i229++) {
      c3_bmls[c3_i229 + 512] = c3_e_bmls[c3_i229];
    }

    _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 18);
    for (c3_i230 = 0; c3_i230 < 256; c3_i230++) {
      c3_bmls[c3_i230 + 1024] = c3_mBML[c3_i230];
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, 20);
  for (c3_i231 = 0; c3_i231 < 1280; c3_i231++) {
    c3_newBmls[c3_i231] = c3_bmls[c3_i231];
  }

  _SFD_EML_CALL(4U, chartInstance->c3_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_removeQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280], real_T c3_newBmls[1280])
{
  uint32_T c3_debug_family_var_map[4];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i232;
  real_T c3_b_bmls[256];
  int32_T c3_i233;
  int32_T c3_i234;
  real_T c3_c_bmls[256];
  int32_T c3_i235;
  int32_T c3_i236;
  real_T c3_d_bmls[256];
  int32_T c3_i237;
  real_T c3_dv45[256];
  int32_T c3_i238;
  int32_T c3_i239;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_u_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bmls, 2U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_newBmls, 3U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  CV_EML_FCN(16, 0);
  _SFD_EML_CALL(16U, chartInstance->c3_sfEvent, 2);
  for (c3_i232 = 0; c3_i232 < 256; c3_i232++) {
    c3_b_bmls[c3_i232] = c3_bmls[c3_i232 + 256];
  }

  for (c3_i233 = 0; c3_i233 < 256; c3_i233++) {
    c3_bmls[c3_i233] = c3_b_bmls[c3_i233];
  }

  _SFD_EML_CALL(16U, chartInstance->c3_sfEvent, 3);
  for (c3_i234 = 0; c3_i234 < 256; c3_i234++) {
    c3_c_bmls[c3_i234] = c3_bmls[c3_i234 + 512];
  }

  for (c3_i235 = 0; c3_i235 < 256; c3_i235++) {
    c3_bmls[c3_i235 + 256] = c3_c_bmls[c3_i235];
  }

  _SFD_EML_CALL(16U, chartInstance->c3_sfEvent, 4);
  for (c3_i236 = 0; c3_i236 < 256; c3_i236++) {
    c3_d_bmls[c3_i236] = c3_bmls[c3_i236 + 768];
  }

  for (c3_i237 = 0; c3_i237 < 256; c3_i237++) {
    c3_bmls[c3_i237 + 512] = c3_d_bmls[c3_i237];
  }

  _SFD_EML_CALL(16U, chartInstance->c3_sfEvent, 5);
  c3_e_encStr2Arr(chartInstance, c3_dv45);
  for (c3_i238 = 0; c3_i238 < 256; c3_i238++) {
    c3_bmls[c3_i238 + 1024] = c3_dv45[c3_i238];
  }

  _SFD_EML_CALL(16U, chartInstance->c3_sfEvent, 6);
  for (c3_i239 = 0; c3_i239 < 1280; c3_i239++) {
    c3_newBmls[c3_i239] = c3_bmls[c3_i239];
  }

  _SFD_EML_CALL(16U, chartInstance->c3_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c3_isEmptyQueue(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, real_T c3_bmls[1280])
{
  real_T c3_empty;
  uint32_T c3_debug_family_var_map[5];
  real_T c3_t[256];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i240;
  static real_T c3_dv46[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c3_b_i;
  int32_T c3_i241;
  int32_T c3_i242;
  real_T c3_b_bmls[256];
  int32_T c3_i243;
  real_T c3_dv47[256];
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_w_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_t, 0U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bmls, 3U, c3_r_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_empty, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(15, 0);
  _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, 2);
  c3_empty = 1.0;
  _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, 2);
  for (c3_i240 = 0; c3_i240 < 256; c3_i240++) {
    c3_t[c3_i240] = c3_dv46[c3_i240];
  }

  _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, 3);
  chartInstance->c3_i = 1.0;
  c3_updateDataWrittenToVector(chartInstance, 11U);
  c3_b_i = 0;
  do {
    exitg1 = 0;
    if (c3_b_i < 5) {
      chartInstance->c3_i = 1.0 + (real_T)c3_b_i;
      c3_updateDataWrittenToVector(chartInstance, 11U);
      CV_EML_FOR(15, 1, 0, 1);
      _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, 4);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 11U, 11U);
      c3_i241 = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", chartInstance->c3_i), 1, 5, 2, 0) - 1;
      for (c3_i242 = 0; c3_i242 < 256; c3_i242++) {
        c3_b_bmls[c3_i242] = c3_bmls[c3_i242 + (c3_i241 << 8)];
      }

      for (c3_i243 = 0; c3_i243 < 256; c3_i243++) {
        c3_dv47[c3_i243] = c3_dv46[c3_i243];
      }

      if (CV_EML_IF(15, 1, 0, (real_T)c3_isequal(chartInstance, c3_b_bmls,
            c3_dv47) == 0.0)) {
        _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, 5);
        c3_empty = 0.0;
        _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, 6);
        exitg1 = 1;
      } else {
        c3_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(15, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(15U, chartInstance->c3_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_empty;
}

static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_i_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i244;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i244, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i244;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_secs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_secs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_secs), &c3_thisId);
  sf_mex_destroy(&c3_secs);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_j_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i245;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i245, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i245;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_k_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Low, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Low),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Low);
  return c3_y;
}

static uint8_T c3_l_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_Low;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_b_tp_Low = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Low),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Low);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i246;
  real_T c3_b_inData[2];
  int32_T c3_i247;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i246 = 0; c3_i246 < 2; c3_i246++) {
    c3_b_inData[c3_i246] = (*(real_T (*)[2])c3_inData)[c3_i246];
  }

  for (c3_i247 = 0; c3_i247 < 2; c3_i247++) {
    c3_u[c3_i247] = c3_b_inData[c3_i247];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_m_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_b_qSizeH, const char_T *c3_identifier,
  real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_qSizeH), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_qSizeH);
}

static void c3_n_emlrt_marshallIn(SFc3_testYarpSendParallelBMLsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv48[2];
  int32_T c3_i248;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv48, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c3_i248 = 0; c3_i248 < 2; c3_i248++) {
    c3_y[c3_i248] = c3_dv48[c3_i248];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_qSizeH;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i249;
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
    chartInstanceVoid;
  c3_b_qSizeH = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_qSizeH), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_qSizeH);
  for (c3_i249 = 0; c3_i249 < 2; c3_i249++) {
    (*(real_T (*)[2])c3_outData)[c3_i249] = c3_y[c3_i249];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static uint32_T c3_o_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_b_previousTicks, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_previousTicks),
    &c3_thisId);
  sf_mex_destroy(&c3_b_previousTicks);
  return c3_y;
}

static uint32_T c3_p_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_q_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_r_emlrt_marshallIn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 24, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn
  (SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 24, 1,
    0)]);
}

static void init_dsm_address_info(SFc3_testYarpSendParallelBMLsInstanceStruct
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

void sf_c3_testYarpSendParallelBMLs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1611189104U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3040241814U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3956439276U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1000060863U);
}

mxArray *sf_c3_testYarpSendParallelBMLs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mzMqX9WaYtURB192DDAiDH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,17,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(256);
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
      pr[1] = (double)(2);
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
      pr[0] = (double)(256);
      pr[1] = (double)(5);
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
      pr[0] = (double)(256);
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
      pr[1] = (double)(2);
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
      pr[0] = (double)(256);
      pr[1] = (double)(5);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
      pr[1] = (double)(5);
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
      pr[0] = (double)(256);
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_testYarpSendParallelBMLs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_testYarpSendParallelBMLs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_testYarpSendParallelBMLs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[166],T\"A\",},{M[3],M[167],T\"B\",},{M[3],M[77],T\"BML\",},{M[3],M[80],T\"BMLh\",},{M[3],M[63],T\"BMLl\",},{M[3],M[157],T\"bHand\",},{M[3],M[76],T\"bmlsH\",},{M[3],M[79],T\"bmlsL\",},{M[3],M[165],T\"cHand\",},{M[3],M[139],T\"hEmpty\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[148],T\"i\",},{M[3],M[140],T\"lEmpty\",},{M[3],M[123],T\"n\",},{M[3],M[147],T\"newBmlsH\",},{M[3],M[155],T\"newBmlsL\",},{M[3],M[75],T\"qSizeH\",},{M[3],M[78],T\"qSizeL\",},{M[8],M[0],T\"is_active_c3_testYarpSendParallelBMLs\",},{M[8],M[65],T\"is_active_send\",},{M[8],M[81],T\"is_active_Low\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[8],M[99],T\"is_active_High\",},{M[9],M[65],T\"is_send\",},{M[9],M[81],T\"is_Low\",},{M[9],M[99],T\"is_High\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[91],M[1]}}},{M[11],M[0],T\"temporalCounter_i2\",S'et','os','ct'{{T\"at\",M[124],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 27, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_testYarpSendParallelBMLs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testYarpSendParallelBMLsMachineNumber_,
           3,
           24,
           19,
           0,
           36,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testYarpSendParallelBMLsMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testYarpSendParallelBMLsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testYarpSendParallelBMLsMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(1,0,0,0,"qSizeH");
          _SFD_SET_DATA_PROPS(2,0,0,0,"bmlsH");
          _SFD_SET_DATA_PROPS(3,0,0,0,"BML");
          _SFD_SET_DATA_PROPS(4,0,0,0,"qSizeL");
          _SFD_SET_DATA_PROPS(5,0,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(6,0,0,0,"BMLh");
          _SFD_SET_DATA_PROPS(7,0,0,0,"n");
          _SFD_SET_DATA_PROPS(8,0,0,0,"hEmpty");
          _SFD_SET_DATA_PROPS(9,0,0,0,"lEmpty");
          _SFD_SET_DATA_PROPS(10,0,0,0,"newBmlsH");
          _SFD_SET_DATA_PROPS(11,0,0,0,"i");
          _SFD_SET_DATA_PROPS(12,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(13,0,0,0,"bHand");
          _SFD_SET_DATA_PROPS(14,1,1,0,"y");
          _SFD_SET_DATA_PROPS(15,0,0,0,"cHand");
          _SFD_SET_DATA_PROPS(16,0,0,0,"A");
          _SFD_SET_DATA_PROPS(17,0,0,0,"B");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,9,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,8,0,0,"");
          _SFD_SET_DATA_PROPS(29,9,0,0,"");
          _SFD_SET_DATA_PROPS(30,9,0,0,"");
          _SFD_SET_DATA_PROPS(31,8,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,9,0,0,"");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_SET_DATA_PROPS(35,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(17,0,1);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_STATE_INFO(11,0,2);
          _SFD_STATE_INFO(21,0,2);
          _SFD_STATE_INFO(14,0,2);
          _SFD_STATE_INFO(15,0,2);
          _SFD_STATE_INFO(16,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,6);
          _SFD_CH_SUBSTATE_INDEX(1,17);
          _SFD_CH_SUBSTATE_INDEX(2,0);
          _SFD_ST_SUBSTATE_COUNT(6,4);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_INDEX(6,2,12);
          _SFD_ST_SUBSTATE_INDEX(6,3,13);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(17,5);
          _SFD_ST_SUBSTATE_INDEX(17,0,18);
          _SFD_ST_SUBSTATE_INDEX(17,1,19);
          _SFD_ST_SUBSTATE_INDEX(17,2,20);
          _SFD_ST_SUBSTATE_INDEX(17,3,22);
          _SFD_ST_SUBSTATE_INDEX(17,4,23);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(6,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,5,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(10,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(10,0,"insertQueue",0,-1,562);
        _SFD_CV_INIT_EML_IF(10,1,0,125,150,-1,-2);
        _SFD_CV_INIT_EML_IF(10,1,1,294,305,-1,543);
        _SFD_CV_INIT_EML_FOR(10,1,0,105,117,289);
        _SFD_CV_INIT_EML(11,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(11,0,"smileTable",0,-1,400);
        _SFD_CV_INIT_EML_FCN(11,1,"aFcnTruthTableAction_1",400,-1,693);
        _SFD_CV_INIT_EML_FCN(11,2,"aFcnTruthTableAction_2",693,-1,876);
        _SFD_CV_INIT_EML_IF(11,1,0,224,254,285,398);
        _SFD_CV_INIT_EML_IF(11,1,1,285,319,350,398);
        _SFD_CV_INIT_EML(9,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(9,0,"idleGazeTable",0,-1,385);
        _SFD_CV_INIT_EML_FCN(9,1,"aFcnTruthTableAction_1",385,-1,700);
        _SFD_CV_INIT_EML_FCN(9,2,"aFcnTruthTableAction_2",700,-1,917);
        _SFD_CV_INIT_EML_IF(9,1,0,209,239,270,383);
        _SFD_CV_INIT_EML_IF(9,1,1,270,304,335,383);
        _SFD_CV_INIT_EML(5,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"rockPoseTable",0,-1,558);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",558,-1,770);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",770,-1,983);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",983,-1,1154);
        _SFD_CV_INIT_EML_IF(5,1,0,317,347,378,556);
        _SFD_CV_INIT_EML_IF(5,1,1,378,412,443,556);
        _SFD_CV_INIT_EML_IF(5,1,2,443,477,508,556);
        _SFD_CV_INIT_EML(4,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"insertQueue",0,-1,562);
        _SFD_CV_INIT_EML_IF(4,1,0,125,150,-1,-2);
        _SFD_CV_INIT_EML_IF(4,1,1,294,305,-1,543);
        _SFD_CV_INIT_EML_FOR(4,1,0,105,117,289);
        _SFD_CV_INIT_EML(14,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(14,0,"fcnShuffleRand",0,-1,85);
        _SFD_CV_INIT_EML(16,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(16,0,"removeQueue",0,-1,163);
        _SFD_CV_INIT_EML(15,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(15,0,"isEmptyQueue",0,-1,192);
        _SFD_CV_INIT_EML_IF(15,1,0,77,105,-1,-2);
        _SFD_CV_INIT_EML_FOR(15,1,0,61,73,191);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(18,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,10,1,10);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_v_sf_marshallOut,(MexInFcnForType)
            c3_i_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_r_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_v_sf_marshallOut,(MexInFcnForType)
            c3_i_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_r_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_r_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_r_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_v_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_r_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_r_sf_marshallOut,(MexInFcnForType)
            c3_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));

        {
          real_T (*c3_y)[2];
          c3_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_BMLl);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_qSizeH);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_bmlsH);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_BML);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_qSizeL);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_bmlsL);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_BMLh);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_n);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c3_hEmpty);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_lEmpty);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_newBmlsH);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_i);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c3_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_bHand);
          _SFD_SET_DATA_VALUE_PTR(14U, *c3_y);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c3_cHand);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c3_A);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c3_B);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testYarpSendParallelBMLsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "OuSErtZpbi5X9WVaWewqGE";
}

static void sf_opaque_initialize_c3_testYarpSendParallelBMLs(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_testYarpSendParallelBMLsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
  initialize_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_testYarpSendParallelBMLs(void *chartInstanceVar)
{
  enable_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_testYarpSendParallelBMLs(void *chartInstanceVar)
{
  disable_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_testYarpSendParallelBMLs(void *chartInstanceVar)
{
  sf_gateway_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_testYarpSendParallelBMLs
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_testYarpSendParallelBMLs();/* state var info */
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

extern void sf_internal_set_sim_state_c3_testYarpSendParallelBMLs(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_testYarpSendParallelBMLs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_testYarpSendParallelBMLs
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_testYarpSendParallelBMLs(S);
}

static void sf_opaque_set_sim_state_c3_testYarpSendParallelBMLs(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_testYarpSendParallelBMLs(S, st);
}

static void sf_opaque_terminate_c3_testYarpSendParallelBMLs(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_testYarpSendParallelBMLsInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testYarpSendParallelBMLs_optimization_info();
    }

    finalize_c3_testYarpSendParallelBMLs
      ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_testYarpSendParallelBMLs
    ((SFc3_testYarpSendParallelBMLsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_testYarpSendParallelBMLs(SimStruct *S)
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
    initialize_params_c3_testYarpSendParallelBMLs
      ((SFc3_testYarpSendParallelBMLsInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_testYarpSendParallelBMLs(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testYarpSendParallelBMLs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,3,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(973703710U));
  ssSetChecksum1(S,(92448661U));
  ssSetChecksum2(S,(3832496882U));
  ssSetChecksum3(S,(2171614451U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_testYarpSendParallelBMLs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_testYarpSendParallelBMLs(SimStruct *S)
{
  SFc3_testYarpSendParallelBMLsInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_testYarpSendParallelBMLsInstanceStruct *)utMalloc(sizeof
    (SFc3_testYarpSendParallelBMLsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_testYarpSendParallelBMLsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_testYarpSendParallelBMLs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_testYarpSendParallelBMLs;
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

void c3_testYarpSendParallelBMLs_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_testYarpSendParallelBMLs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_testYarpSendParallelBMLs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_testYarpSendParallelBMLs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_testYarpSendParallelBMLs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
