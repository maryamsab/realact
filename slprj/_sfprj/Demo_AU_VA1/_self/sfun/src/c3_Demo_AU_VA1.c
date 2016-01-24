/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_AU_VA1_sfun.h"
#include "c3_Demo_AU_VA1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_AU_VA1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Mid                      ((uint8_T)1U)
#define c3_IN_checkHighPriority        ((uint8_T)2U)
#define c3_IN_init                     ((uint8_T)3U)
#define c3_IN_low                      ((uint8_T)4U)
#define c3_IN_sendH                    ((uint8_T)5U)
#define c3_IN_sendL                    ((uint8_T)6U)
#define c3_IN_sendM                    ((uint8_T)7U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c3_subchartSimStateInfo;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_c_debug_family_names[4] = { "nargin", "nargout", "bmls",
  "newBmls" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[6] = { "tempp", "i", "nargin",
  "nargout", "bmls", "empty" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

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

static boolean_T c3_dataWrittenToVector[13];

/* Function Declarations */
static void initialize_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void initialize_params_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void enable_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void disable_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Demo_AU_VA1
  (SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Demo_AU_VA1
  (SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void set_sim_state_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_Demo_AU_VA1
  (SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void finalize_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void sf_gateway_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void initSimStructsc3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c3_sendBMLbyPriority(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void c3_enter_atomic_sendH(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void c3_enter_atomic_sendM(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void c3_low(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);
static void c3_encStr2Arr(SFc3_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c3_myarr256[1000]);
static boolean_T c3_isequal(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c3_varargin_1[1000], real_T c3_varargin_2[1000]);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[1000]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_newBmls, const char_T *c3_identifier, real_T c3_y[5000]);
static void c3_e_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[5000]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_f_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static void c3_removeQueue(SFc3_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c3_bmls[5000], real_T c3_newBmls[5000]);
static real_T c3_isEmptyQueue(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c3_bmls[5000]);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_g_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_h_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_i_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_b_tp_facialExpression_Controller, const
  char_T *c3_identifier);
static uint8_T c3_j_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_k_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_emotion_amount_factor, const char_T *c3_identifier, real_T
  c3_y[11]);
static void c3_l_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[11]);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_m_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_b_BML, const char_T *c3_identifier, real_T c3_y[1000]);
static void c3_n_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[1000]);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_o_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_b_subchartSimStateInfo, const char_T
  *c3_identifier);
static const mxArray *c3_p_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber);
static real_T c3_get_bmlsL(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c3_b);
static void c3_set_bmlsL(SFc3_Demo_AU_VA1InstanceStruct *chartInstance, uint32_T
  c3_b, real_T c3_c);
static real_T *c3_access_bmlsL(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c3_b);
static void init_dsm_address_info(SFc3_Demo_AU_VA1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  real_T (*c3_emotion_amount_factor)[11];
  c3_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  sf_exported_auto_initc50_Demo_AU_VA1(chartInstance->c3_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c3_subchartSimStateInfo = NULL;
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_facialExpression_Controller = 0U;
  chartInstance->c3_tp_facialExpression_Controller = 0U;
  chartInstance->c3_is_active_sendBMLbyPriority = 0U;
  chartInstance->c3_is_sendBMLbyPriority = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_sendBMLbyPriority = 0U;
  chartInstance->c3_tp_Mid = 0U;
  chartInstance->c3_tp_checkHighPriority = 0U;
  chartInstance->c3_tp_init = 0U;
  chartInstance->c3_tp_low = 0U;
  chartInstance->c3_tp_sendH = 0U;
  chartInstance->c3_tp_sendL = 0U;
  chartInstance->c3_tp_sendM = 0U;
  chartInstance->c3_is_active_c3_Demo_AU_VA1 = 0U;
  for (c3_i0 = 0; c3_i0 < 5000; c3_i0++) {
    c3_set_bmlsL(chartInstance, c3_i0, 0.0);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    for (c3_i1 = 0; c3_i1 < 11; c3_i1++) {
      (*c3_emotion_amount_factor)[c3_i1] = 0.0;
    }
  }
}

static void initialize_params_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_is_active_sendBMLbyPriority == 1U) {
    sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
  }

  if (chartInstance->c3_is_active_facialExpression_Controller == 1U) {
    sf_exported_auto_enablec50_Demo_AU_VA1(chartInstance->c3_subchartSimstruct);
  }
}

static void disable_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c3_is_active_sendBMLbyPriority == 1U) {
    sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
  }

  if (chartInstance->c3_is_active_facialExpression_Controller == 1U) {
    sf_exported_auto_disablec50_Demo_AU_VA1(chartInstance->c3_subchartSimstruct);
  }
}

static void c3_update_debugger_state_c3_Demo_AU_VA1
  (SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_Demo_AU_VA1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_facialExpression_Controller == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_sendBMLbyPriority == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_sendH) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_checkHighPriority) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_sendM) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_Mid) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_sendL) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_low) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_Demo_AU_VA1
  (SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i2;
  real_T c3_u[11];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i3;
  real_T c3_b_u[1000];
  const mxArray *c3_c_y = NULL;
  int32_T c3_i4;
  static real_T c3_c_u[5000];
  const mxArray *c3_d_y = NULL;
  int32_T c3_i5;
  static real_T c3_d_u[5000];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i6;
  real_T c3_e_u[5000];
  const mxArray *c3_f_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  int32_T c3_i7;
  real_T c3_i_u[1000];
  const mxArray *c3_j_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  int32_T c3_i8;
  real_T c3_k_u[5000];
  const mxArray *c3_l_y = NULL;
  int32_T c3_i9;
  real_T c3_l_u[5000];
  const mxArray *c3_m_y = NULL;
  int32_T c3_i10;
  real_T c3_m_u[5000];
  const mxArray *c3_n_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_p_u;
  const mxArray *c3_q_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_q_u;
  const mxArray *c3_r_y = NULL;
  const mxArray *c3_r_u;
  const mxArray *c3_s_y = NULL;
  real_T (*c3_emotion_amount_factor)[11];
  c3_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_subchartSimStateInfo,
                sf_exported_auto_getSimstatec50_Demo_AU_VA1
                (chartInstance->c3_subchartSimstruct), true);
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(18, 1), false);
  for (c3_i2 = 0; c3_i2 < 11; c3_i2++) {
    c3_u[c3_i2] = (*c3_emotion_amount_factor)[c3_i2];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i3 = 0; c3_i3 < 1000; c3_i3++) {
    c3_b_u[c3_i3] = chartInstance->c3_BML[c3_i3];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  for (c3_i4 = 0; c3_i4 < 5000; c3_i4++) {
    c3_c_u[c3_i4] = chartInstance->c3_bmlsH[c3_i4];
  }

  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  for (c3_i5 = 0; c3_i5 < 5000; c3_i5++) {
    c3_d_u[c3_i5] = c3_get_bmlsL(chartInstance, c3_i5);
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  for (c3_i6 = 0; c3_i6 < 5000; c3_i6++) {
    c3_e_u[c3_i6] = chartInstance->c3_bmlsM[c3_i6];
  }

  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_hoistedGlobal = chartInstance->c3_hEmpty;
  c3_f_u = c3_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_b_hoistedGlobal = chartInstance->c3_lEmpty;
  c3_g_u = c3_b_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_c_hoistedGlobal = chartInstance->c3_mEmpty;
  c3_h_u = c3_c_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  for (c3_i7 = 0; c3_i7 < 1000; c3_i7++) {
    c3_i_u[c3_i7] = chartInstance->c3_n[c3_i7];
  }

  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_i_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_d_hoistedGlobal = chartInstance->c3_newBmlA;
  c3_j_u = c3_d_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  for (c3_i8 = 0; c3_i8 < 5000; c3_i8++) {
    c3_k_u[c3_i8] = chartInstance->c3_newBmlsH[c3_i8];
  }

  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", c3_k_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  for (c3_i9 = 0; c3_i9 < 5000; c3_i9++) {
    c3_l_u[c3_i9] = chartInstance->c3_newBmlsL[c3_i9];
  }

  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", c3_l_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  for (c3_i10 = 0; c3_i10 < 5000; c3_i10++) {
    c3_m_u[c3_i10] = chartInstance->c3_newBmlsM[c3_i10];
  }

  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_m_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_Demo_AU_VA1;
  c3_n_u = c3_e_hoistedGlobal;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_active_facialExpression_Controller;
  c3_o_u = c3_f_hoistedGlobal;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_active_sendBMLbyPriority;
  c3_p_u = c3_g_hoistedGlobal;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_sendBMLbyPriority;
  c3_q_u = c3_h_hoistedGlobal;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_r_u = sf_mex_dup(c3_subchartSimStateInfo);
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_duplicatearraysafe(&c3_r_u), false);
  sf_mex_destroy(&c3_r_u);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[11];
  int32_T c3_i11;
  real_T c3_dv1[1000];
  int32_T c3_i12;
  static real_T c3_dv2[5000];
  int32_T c3_i13;
  static real_T c3_dv3[5000];
  int32_T c3_i14;
  static real_T c3_dv4[5000];
  int32_T c3_i15;
  real_T c3_dv5[1000];
  int32_T c3_i16;
  real_T c3_dv6[5000];
  int32_T c3_i17;
  real_T c3_dv7[5000];
  int32_T c3_i18;
  real_T c3_dv8[5000];
  int32_T c3_i19;
  real_T (*c3_emotion_amount_factor)[11];
  c3_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "emotion_amount_factor", c3_dv0);
  for (c3_i11 = 0; c3_i11 < 11; c3_i11++) {
    (*c3_emotion_amount_factor)[c3_i11] = c3_dv0[c3_i11];
  }

  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "BML", c3_dv1);
  for (c3_i12 = 0; c3_i12 < 1000; c3_i12++) {
    chartInstance->c3_BML[c3_i12] = c3_dv1[c3_i12];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
                        "bmlsH", c3_dv2);
  for (c3_i13 = 0; c3_i13 < 5000; c3_i13++) {
    chartInstance->c3_bmlsH[c3_i13] = c3_dv2[c3_i13];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
                        "bmlsL", c3_dv3);
  for (c3_i14 = 0; c3_i14 < 5000; c3_i14++) {
    c3_set_bmlsL(chartInstance, c3_i14, c3_dv3[c3_i14]);
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                        "bmlsM", c3_dv4);
  for (c3_i15 = 0; c3_i15 < 5000; c3_i15++) {
    chartInstance->c3_bmlsM[c3_i15] = c3_dv4[c3_i15];
  }

  chartInstance->c3_hEmpty = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "hEmpty");
  chartInstance->c3_lEmpty = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "lEmpty");
  chartInstance->c3_mEmpty = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "mEmpty");
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)), "n",
                        c3_dv5);
  for (c3_i16 = 0; c3_i16 < 1000; c3_i16++) {
    chartInstance->c3_n[c3_i16] = c3_dv5[c3_i16];
  }

  chartInstance->c3_newBmlA = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "newBmlA");
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 10)),
                        "newBmlsH", c3_dv6);
  for (c3_i17 = 0; c3_i17 < 5000; c3_i17++) {
    chartInstance->c3_newBmlsH[c3_i17] = c3_dv6[c3_i17];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 11)),
                        "newBmlsL", c3_dv7);
  for (c3_i18 = 0; c3_i18 < 5000; c3_i18++) {
    chartInstance->c3_newBmlsL[c3_i18] = c3_dv7[c3_i18];
  }

  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 12)),
                        "newBmlsM", c3_dv8);
  for (c3_i19 = 0; c3_i19 < 5000; c3_i19++) {
    chartInstance->c3_newBmlsM[c3_i19] = c3_dv8[c3_i19];
  }

  chartInstance->c3_is_active_c3_Demo_AU_VA1 = c3_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 13)),
     "is_active_c3_Demo_AU_VA1");
  chartInstance->c3_is_active_facialExpression_Controller =
    c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 14)),
    "is_active_facialExpression_Controller");
  chartInstance->c3_is_active_sendBMLbyPriority = c3_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 15)),
     "is_active_sendBMLbyPriority");
  chartInstance->c3_is_sendBMLbyPriority = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 16)), "is_sendBMLbyPriority");
  sf_mex_assign(&c3_subchartSimStateInfo, c3_o_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 17)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 18)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_Demo_AU_VA1(chartInstance);
  sf_exported_auto_setSimstatec50_Demo_AU_VA1
    (chartInstance->c3_subchartSimstruct, sf_mex_dup(c3_subchartSimStateInfo));
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_Demo_AU_VA1
  (SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_active_facialExpression_Controller == 1U) {
      chartInstance->c3_tp_facialExpression_Controller = 1U;
    } else {
      chartInstance->c3_tp_facialExpression_Controller = 0U;
    }

    if (chartInstance->c3_is_active_sendBMLbyPriority == 1U) {
      chartInstance->c3_tp_sendBMLbyPriority = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
      }
    } else {
      chartInstance->c3_tp_sendBMLbyPriority = 0U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) > 0.0) {
        sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
      }
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_Mid) {
      chartInstance->c3_tp_Mid = 1U;
    } else {
      chartInstance->c3_tp_Mid = 0U;
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_checkHighPriority) {
      chartInstance->c3_tp_checkHighPriority = 1U;
    } else {
      chartInstance->c3_tp_checkHighPriority = 0U;
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_init) {
      chartInstance->c3_tp_init = 1U;
    } else {
      chartInstance->c3_tp_init = 0U;
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_low) {
      chartInstance->c3_tp_low = 1U;
    } else {
      chartInstance->c3_tp_low = 0U;
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_sendH) {
      chartInstance->c3_tp_sendH = 1U;
    } else {
      chartInstance->c3_tp_sendH = 0U;
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_sendL) {
      chartInstance->c3_tp_sendL = 1U;
    } else {
      chartInstance->c3_tp_sendL = 0U;
    }

    if (chartInstance->c3_is_sendBMLbyPriority == c3_IN_sendM) {
      chartInstance->c3_tp_sendM = 1U;
    } else {
      chartInstance->c3_tp_sendM = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c3_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance)
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
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_dv9[1000];
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
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
  real_T *c3_inV;
  real_T *c3_inA;
  real_T (*c3_emotion_amount_factor)[11];
  c3_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c3_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_Demo_AU_VA1(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc50_Demo_AU_VA1(chartInstance->c3_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_inV, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_inA, 1U);
  for (c3_i20 = 0; c3_i20 < 5000; c3_i20++) {
    _SFD_DATA_RANGE_CHECK(c3_get_bmlsL(chartInstance, c3_i20), 2U);
  }

  for (c3_i21 = 0; c3_i21 < 5000; c3_i21++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsL[c3_i21], 3U);
  }

  for (c3_i22 = 0; c3_i22 < 11; c3_i22++) {
    _SFD_DATA_RANGE_CHECK((*c3_emotion_amount_factor)[c3_i22], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 5U);
  for (c3_i23 = 0; c3_i23 < 5000; c3_i23++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsM[c3_i23], 6U);
  }

  for (c3_i24 = 0; c3_i24 < 5000; c3_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsM[c3_i24], 7U);
  }

  for (c3_i25 = 0; c3_i25 < 5000; c3_i25++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsH[c3_i25], 8U);
  }

  for (c3_i26 = 0; c3_i26 < 5000; c3_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i26], 9U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlA, 10U);
  for (c3_i27 = 0; c3_i27 < 1000; c3_i27++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BML[c3_i27], 11U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_lEmpty, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_mEmpty, 13U);
  for (c3_i28 = 0; c3_i28 < 1000; c3_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_n[c3_i28], 14U);
  }

  sf_exported_auto_activate_c50_Demo_AU_VA1_secs
    (chartInstance->c3_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c50_Demo_AU_VA1_secs
    (chartInstance->c3_subchartSimstruct);
  chartInstance->c3_sfEvent = c3_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  sf_exported_auto_stepBuffersc50_Demo_AU_VA1
    (chartInstance->c3_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_Demo_AU_VA1 == 0U) {
    sf_exported_auto_initBuffersc50_Demo_AU_VA1
      (chartInstance->c3_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_Demo_AU_VA1 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_facialExpression_Controller = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_facialExpression_Controller = 1U;
    sf_exported_auto_enterc50_Demo_AU_VA1(chartInstance->c3_subchartSimstruct);
    chartInstance->c3_is_active_sendBMLbyPriority = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_sendBMLbyPriority = 1U;
    sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_sendBMLbyPriority = c3_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_encStr2Arr(chartInstance, c3_dv9);
    for (c3_i29 = 0; c3_i29 < 1000; c3_i29++) {
      chartInstance->c3_n[c3_i29] = c3_dv9[c3_i29];
    }

    c3_updateDataWrittenToVector(chartInstance, 10U);
    for (c3_i30 = 0; c3_i30 < 1000; c3_i30++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_n[c3_i30], 14U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 14U);
    for (c3_i31 = 0; c3_i31 < 1000; c3_i31++) {
      chartInstance->c3_bmlsH[c3_i31] = chartInstance->c3_n[c3_i31];
    }

    for (c3_i32 = 0; c3_i32 < 1000; c3_i32++) {
      chartInstance->c3_bmlsH[c3_i32 + 1000] = chartInstance->c3_n[c3_i32];
    }

    for (c3_i33 = 0; c3_i33 < 1000; c3_i33++) {
      chartInstance->c3_bmlsH[c3_i33 + 2000] = chartInstance->c3_n[c3_i33];
    }

    for (c3_i34 = 0; c3_i34 < 1000; c3_i34++) {
      chartInstance->c3_bmlsH[c3_i34 + 3000] = chartInstance->c3_n[c3_i34];
    }

    for (c3_i35 = 0; c3_i35 < 1000; c3_i35++) {
      chartInstance->c3_bmlsH[c3_i35 + 4000] = chartInstance->c3_n[c3_i35];
    }

    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 5U);
    for (c3_i36 = 0; c3_i36 < 5000; c3_i36++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i36], 9U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 14U);
    for (c3_i37 = 0; c3_i37 < 1000; c3_i37++) {
      chartInstance->c3_bmlsM[c3_i37] = chartInstance->c3_n[c3_i37];
    }

    for (c3_i38 = 0; c3_i38 < 1000; c3_i38++) {
      chartInstance->c3_bmlsM[c3_i38 + 1000] = chartInstance->c3_n[c3_i38];
    }

    for (c3_i39 = 0; c3_i39 < 1000; c3_i39++) {
      chartInstance->c3_bmlsM[c3_i39 + 2000] = chartInstance->c3_n[c3_i39];
    }

    for (c3_i40 = 0; c3_i40 < 1000; c3_i40++) {
      chartInstance->c3_bmlsM[c3_i40 + 3000] = chartInstance->c3_n[c3_i40];
    }

    for (c3_i41 = 0; c3_i41 < 1000; c3_i41++) {
      chartInstance->c3_bmlsM[c3_i41 + 4000] = chartInstance->c3_n[c3_i41];
    }

    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 3U);
    for (c3_i42 = 0; c3_i42 < 5000; c3_i42++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsM[c3_i42], 7U);
    }

    c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 14U);
    for (c3_i43 = 0; c3_i43 < 1000; c3_i43++) {
      c3_set_bmlsL(chartInstance, c3_i43, chartInstance->c3_n[c3_i43]);
    }

    for (c3_i44 = 0; c3_i44 < 1000; c3_i44++) {
      c3_set_bmlsL(chartInstance, c3_i44 + 1000, chartInstance->c3_n[c3_i44]);
    }

    for (c3_i45 = 0; c3_i45 < 1000; c3_i45++) {
      c3_set_bmlsL(chartInstance, c3_i45 + 2000, chartInstance->c3_n[c3_i45]);
    }

    for (c3_i46 = 0; c3_i46 < 1000; c3_i46++) {
      c3_set_bmlsL(chartInstance, c3_i46 + 3000, chartInstance->c3_n[c3_i46]);
    }

    for (c3_i47 = 0; c3_i47 < 1000; c3_i47++) {
      c3_set_bmlsL(chartInstance, c3_i47 + 4000, chartInstance->c3_n[c3_i47]);
    }

    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    c3_updateDataWrittenToVector(chartInstance, 10U);
    for (c3_i48 = 0; c3_i48 < 5000; c3_i48++) {
      _SFD_DATA_RANGE_CHECK(c3_get_bmlsL(chartInstance, c3_i48), 2U);
    }

    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    sf_exported_auto_duringc50_Demo_AU_VA1(chartInstance->c3_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    c3_sendBMLbyPriority(chartInstance);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  sf_exported_auto_resetTemporalCounter_c50_Demo_AU_VA1_secs
    (chartInstance->c3_subchartSimstruct);
  sf_exported_auto_deactivate_c50_Demo_AU_VA1_secs
    (chartInstance->c3_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_AU_VA1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c3_is_active_facialExpression_Controller == 1U) {
    sf_exported_auto_check_state_inconsistency_c50_Demo_AU_VA1
      (chartInstance->c3_subchartSimstruct);
  }
}

static void initSimStructsc3_Demo_AU_VA1(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  chartInstance->c3_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "facialExpression_Controller");
}

static void c3_sendBMLbyPriority(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  int32_T c3_i49;
  static real_T c3_dv10[5000];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  int32_T c3_i50;
  static real_T c3_dv11[5000];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i51;
  static real_T c3_dv12[5000];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  int32_T c3_i52;
  static real_T c3_dv13[5000];
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  int32_T c3_i53;
  static real_T c3_dv14[5000];
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 0.0;
  int32_T c3_i54;
  static real_T c3_dv15[5000];
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 1.0;
  boolean_T c3_g_out;
  int32_T c3_i55;
  static real_T c3_dv16[5000];
  real_T c3_m_nargin = 0.0;
  real_T c3_m_nargout = 1.0;
  boolean_T c3_h_out;
  int32_T c3_i56;
  static real_T c3_dv17[5000];
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 0.0;
  int32_T c3_i57;
  static real_T c3_dv18[5000];
  real_T c3_o_nargin = 0.0;
  real_T c3_o_nargout = 1.0;
  boolean_T c3_i_out;
  int32_T c3_i58;
  static real_T c3_dv19[5000];
  real_T c3_p_nargin = 0.0;
  real_T c3_p_nargout = 0.0;
  int32_T c3_i59;
  static real_T c3_dv20[5000];
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_sendBMLbyPriority) {
   case c3_IN_Mid:
    CV_STATE_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_e_sf_marshallOut,
      c3_d_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
    for (c3_i49 = 0; c3_i49 < 5000; c3_i49++) {
      c3_dv10[c3_i49] = chartInstance->c3_bmlsH[c3_i49];
    }

    c3_out = CV_EML_IF(9, 0, 0, c3_isEmptyQueue(chartInstance, c3_dv10) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Mid = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendH;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendH = 1U;
      c3_enter_atomic_sendH(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_r_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_e_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 13U);
      c3_b_out = CV_EML_IF(12, 0, 0, chartInstance->c3_mEmpty != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Mid = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendM;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_sendM = 1U;
        c3_enter_atomic_sendM(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_s_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_e_sf_marshallOut,
          c3_d_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 13U);
        c3_c_out = CV_EML_IF(13, 0, 0, chartInstance->c3_mEmpty == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Mid = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_sendBMLbyPriority = c3_IN_low;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_low = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          for (c3_i50 = 0; c3_i50 < 5000; c3_i50++) {
            c3_dv11[c3_i50] = c3_get_bmlsL(chartInstance, c3_i50);
          }

          chartInstance->c3_lEmpty = c3_isEmptyQueue(chartInstance, c3_dv11);
          c3_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_lEmpty, 12U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                       chartInstance->c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U,
            c3_e_sf_marshallOut, c3_d_sf_marshallIn);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 13U);
          c3_d_out = CV_EML_IF(5, 0, 0, chartInstance->c3_mEmpty == 1.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_Mid = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_sendBMLbyPriority = c3_IN_checkHighPriority;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_checkHighPriority = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
              c3_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
              c3_sf_marshallOut, c3_sf_marshallIn);
            c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
            for (c3_i51 = 0; c3_i51 < 5000; c3_i51++) {
              c3_dv12[c3_i51] = chartInstance->c3_bmlsH[c3_i51];
            }

            chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv12);
            c3_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 5U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                         chartInstance->c3_sfEvent);
          }
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_checkHighPriority:
    CV_STATE_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_e_sf_marshallOut,
      c3_d_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 5U);
    c3_e_out = CV_EML_IF(4, 0, 0, chartInstance->c3_hEmpty == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_checkHighPriority = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_sendBMLbyPriority = c3_IN_Mid;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Mid = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
      for (c3_i52 = 0; c3_i52 < 5000; c3_i52++) {
        c3_dv13[c3_i52] = chartInstance->c3_bmlsM[c3_i52];
      }

      chartInstance->c3_mEmpty = c3_isEmptyQueue(chartInstance, c3_dv13);
      c3_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_mEmpty, 13U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_e_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 5U);
      c3_f_out = CV_EML_IF(1, 0, 0, chartInstance->c3_hEmpty != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_checkHighPriority = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendH;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_sendH = 1U;
        c3_enter_atomic_sendH(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_init:
    CV_STATE_EVAL(1, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_sendBMLbyPriority = c3_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
    for (c3_i53 = 0; c3_i53 < 5000; c3_i53++) {
      c3_dv14[c3_i53] = chartInstance->c3_bmlsH[c3_i53];
    }

    chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv14);
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 5U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_low:
    CV_STATE_EVAL(1, 0, 4);
    c3_low(chartInstance);
    break;

   case c3_IN_sendH:
    CV_STATE_EVAL(1, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_sendH = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_sendBMLbyPriority = c3_IN_checkHighPriority;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkHighPriority = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
    for (c3_i54 = 0; c3_i54 < 5000; c3_i54++) {
      c3_dv15[c3_i54] = chartInstance->c3_bmlsH[c3_i54];
    }

    chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv15);
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 5U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_sendL:
    CV_STATE_EVAL(1, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_v_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U, c3_e_sf_marshallOut,
      c3_d_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
    for (c3_i55 = 0; c3_i55 < 5000; c3_i55++) {
      c3_dv16[c3_i55] = chartInstance->c3_bmlsM[c3_i55];
    }

    c3_g_out = CV_EML_IF(16, 0, 0, c3_isEmptyQueue(chartInstance, c3_dv16) !=
                         1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendL = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendM;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendM = 1U;
      c3_enter_atomic_sendM(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_q_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U, c3_e_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
      for (c3_i56 = 0; c3_i56 < 5000; c3_i56++) {
        c3_dv17[c3_i56] = chartInstance->c3_bmlsH[c3_i56];
      }

      c3_h_out = CV_EML_IF(11, 0, 0, c3_isEmptyQueue(chartInstance, c3_dv17) !=
                           1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_sendL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendH;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_sendH = 1U;
        c3_enter_atomic_sendH(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_sendL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_sendBMLbyPriority = c3_IN_checkHighPriority;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_checkHighPriority = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
        for (c3_i57 = 0; c3_i57 < 5000; c3_i57++) {
          c3_dv18[c3_i57] = chartInstance->c3_bmlsH[c3_i57];
        }

        chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv18);
        c3_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 5U);
        _SFD_SYMBOL_SCOPE_POP();
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_sendM:
    CV_STATE_EVAL(1, 0, 7);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_out, 2U, c3_e_sf_marshallOut,
      c3_d_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
    for (c3_i58 = 0; c3_i58 < 5000; c3_i58++) {
      c3_dv19[c3_i58] = chartInstance->c3_bmlsH[c3_i58];
    }

    c3_i_out = CV_EML_IF(10, 0, 0, c3_isEmptyQueue(chartInstance, c3_dv19) !=
                         1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_i_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendM = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendH;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendH = 1U;
      c3_enter_atomic_sendH(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendM = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_sendBMLbyPriority = c3_IN_checkHighPriority;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_checkHighPriority = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_p_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
      for (c3_i59 = 0; c3_i59 < 5000; c3_i59++) {
        c3_dv20[c3_i59] = chartInstance->c3_bmlsH[c3_i59];
      }

      chartInstance->c3_hEmpty = c3_isEmptyQueue(chartInstance, c3_dv20);
      c3_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_hEmpty, 5U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 0, 0);
    chartInstance->c3_is_sendBMLbyPriority = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_sendH(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  real_T c3_In1[1000];
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  real_T c3_dv21[5000];
  real_T c3_dv22[5000];
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i70;
  real_T (*c3_b_In1)[1000];
  c3_b_In1 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
  for (c3_i60 = 0; c3_i60 < 1000; c3_i60++) {
    chartInstance->c3_BML[c3_i60] = chartInstance->c3_bmlsH[c3_i60];
  }

  c3_updateDataWrittenToVector(chartInstance, 7U);
  for (c3_i61 = 0; c3_i61 < 1000; c3_i61++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BML[c3_i61], 11U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 11U);
  for (c3_i62 = 0; c3_i62 < 1000; c3_i62++) {
    c3_In1[c3_i62] = chartInstance->c3_BML[c3_i62];
  }

  for (c3_i63 = 0; c3_i63 < 1000; c3_i63++) {
    _SFD_DATA_RANGE_CHECK(c3_In1[c3_i63], 15U);
  }

  _SFD_SET_DATA_VALUE_PTR(15U, c3_In1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In1", c3_In1, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
  for (c3_i64 = 0; c3_i64 < 1000; c3_i64++) {
    (*c3_b_In1)[c3_i64] = c3_In1[c3_i64];
  }

  for (c3_i65 = 0; c3_i65 < 1000; c3_i65++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_In1)[c3_i65], 15U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(15U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
  for (c3_i66 = 0; c3_i66 < 5000; c3_i66++) {
    c3_dv21[c3_i66] = chartInstance->c3_bmlsH[c3_i66];
  }

  c3_removeQueue(chartInstance, c3_dv21, c3_dv22);
  for (c3_i67 = 0; c3_i67 < 5000; c3_i67++) {
    chartInstance->c3_newBmlsH[c3_i67] = c3_dv22[c3_i67];
  }

  c3_updateDataWrittenToVector(chartInstance, 4U);
  for (c3_i68 = 0; c3_i68 < 5000; c3_i68++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsH[c3_i68], 8U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 4U, 8U);
  for (c3_i69 = 0; c3_i69 < 5000; c3_i69++) {
    chartInstance->c3_bmlsH[c3_i69] = chartInstance->c3_newBmlsH[c3_i69];
  }

  c3_updateDataWrittenToVector(chartInstance, 5U);
  for (c3_i70 = 0; c3_i70 < 5000; c3_i70++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsH[c3_i70], 9U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_sendM(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  real_T c3_In1[1000];
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  real_T c3_dv23[5000];
  real_T c3_dv24[5000];
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  real_T (*c3_b_In1)[1000];
  c3_b_In1 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
  for (c3_i71 = 0; c3_i71 < 1000; c3_i71++) {
    chartInstance->c3_BML[c3_i71] = chartInstance->c3_bmlsM[c3_i71];
  }

  c3_updateDataWrittenToVector(chartInstance, 7U);
  for (c3_i72 = 0; c3_i72 < 1000; c3_i72++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_BML[c3_i72], 11U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 11U);
  for (c3_i73 = 0; c3_i73 < 1000; c3_i73++) {
    c3_In1[c3_i73] = chartInstance->c3_BML[c3_i73];
  }

  for (c3_i74 = 0; c3_i74 < 1000; c3_i74++) {
    _SFD_DATA_RANGE_CHECK(c3_In1[c3_i74], 15U);
  }

  _SFD_SET_DATA_VALUE_PTR(15U, c3_In1);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In1", c3_In1, c3_j_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
  for (c3_i75 = 0; c3_i75 < 1000; c3_i75++) {
    (*c3_b_In1)[c3_i75] = c3_In1[c3_i75];
  }

  for (c3_i76 = 0; c3_i76 < 1000; c3_i76++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_In1)[c3_i76], 15U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(15U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
  for (c3_i77 = 0; c3_i77 < 5000; c3_i77++) {
    c3_dv23[c3_i77] = chartInstance->c3_bmlsM[c3_i77];
  }

  c3_removeQueue(chartInstance, c3_dv23, c3_dv24);
  for (c3_i78 = 0; c3_i78 < 5000; c3_i78++) {
    chartInstance->c3_newBmlsM[c3_i78] = c3_dv24[c3_i78];
  }

  c3_updateDataWrittenToVector(chartInstance, 2U);
  for (c3_i79 = 0; c3_i79 < 5000; c3_i79++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsM[c3_i79], 6U);
  }

  c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 6U);
  for (c3_i80 = 0; c3_i80 < 5000; c3_i80++) {
    chartInstance->c3_bmlsM[c3_i80] = chartInstance->c3_newBmlsM[c3_i80];
  }

  c3_updateDataWrittenToVector(chartInstance, 3U);
  for (c3_i81 = 0; c3_i81 < 5000; c3_i81++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bmlsM[c3_i81], 7U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_low(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  int32_T c3_i82;
  static real_T c3_dv25[5000];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  int32_T c3_i83;
  static real_T c3_dv26[5000];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  real_T c3_In1[1000];
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i90;
  static real_T c3_dv27[5000];
  static real_T c3_dv28[5000];
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  int32_T c3_i95;
  real_T c3_dv29[5000];
  real_T (*c3_b_In1)[1000];
  c3_b_In1 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
  for (c3_i82 = 0; c3_i82 < 5000; c3_i82++) {
    c3_dv25[c3_i82] = chartInstance->c3_bmlsH[c3_i82];
  }

  c3_out = CV_EML_IF(8, 0, 0, c3_isEmptyQueue(chartInstance, c3_dv25) != 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_low = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendH;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_sendH = 1U;
    c3_enter_atomic_sendH(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_u_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_e_sf_marshallOut,
      c3_d_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
    for (c3_i83 = 0; c3_i83 < 5000; c3_i83++) {
      c3_dv26[c3_i83] = chartInstance->c3_bmlsM[c3_i83];
    }

    c3_b_out = CV_EML_IF(15, 0, 0, c3_isEmptyQueue(chartInstance, c3_dv26) !=
                         1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_low = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendM;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_sendM = 1U;
      c3_enter_atomic_sendM(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_w_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_e_sf_marshallOut,
        c3_d_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 12U);
      c3_c_out = CV_EML_IF(17, 0, 0, chartInstance->c3_lEmpty != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_low = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_sendBMLbyPriority = c3_IN_sendL;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_sendL = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        for (c3_i84 = 0; c3_i84 < 1000; c3_i84++) {
          chartInstance->c3_BML[c3_i84] = c3_get_bmlsL(chartInstance, c3_i84);
        }

        c3_updateDataWrittenToVector(chartInstance, 7U);
        for (c3_i85 = 0; c3_i85 < 1000; c3_i85++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_BML[c3_i85], 11U);
        }

        c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 11U);
        for (c3_i86 = 0; c3_i86 < 1000; c3_i86++) {
          c3_In1[c3_i86] = chartInstance->c3_BML[c3_i86];
        }

        for (c3_i87 = 0; c3_i87 < 1000; c3_i87++) {
          _SFD_DATA_RANGE_CHECK(c3_In1[c3_i87], 15U);
        }

        _SFD_SET_DATA_VALUE_PTR(15U, c3_In1);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("In1", c3_In1, c3_j_sf_marshallOut,
          c3_i_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c3_sfEvent);
        for (c3_i88 = 0; c3_i88 < 1000; c3_i88++) {
          (*c3_b_In1)[c3_i88] = c3_In1[c3_i88];
        }

        for (c3_i89 = 0; c3_i89 < 1000; c3_i89++) {
          _SFD_DATA_RANGE_CHECK((*c3_b_In1)[c3_i89], 15U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(15U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
        for (c3_i90 = 0; c3_i90 < 5000; c3_i90++) {
          c3_dv27[c3_i90] = c3_get_bmlsL(chartInstance, c3_i90);
        }

        c3_removeQueue(chartInstance, c3_dv27, c3_dv28);
        for (c3_i91 = 0; c3_i91 < 5000; c3_i91++) {
          chartInstance->c3_newBmlsL[c3_i91] = c3_dv28[c3_i91];
        }

        c3_updateDataWrittenToVector(chartInstance, 0U);
        for (c3_i92 = 0; c3_i92 < 5000; c3_i92++) {
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_newBmlsL[c3_i92], 3U);
        }

        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 3U);
        for (c3_i93 = 0; c3_i93 < 5000; c3_i93++) {
          c3_set_bmlsL(chartInstance, c3_i93, chartInstance->c3_newBmlsL[c3_i93]);
        }

        for (c3_i94 = 0; c3_i94 < 5000; c3_i94++) {
          _SFD_DATA_RANGE_CHECK(c3_get_bmlsL(chartInstance, c3_i94), 2U);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_t_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_e_sf_marshallOut,
          c3_d_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 12U);
        c3_d_out = CV_EML_IF(14, 0, 0, chartInstance->c3_lEmpty == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_low = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_sendBMLbyPriority = c3_IN_Mid;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Mid = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
          for (c3_i95 = 0; c3_i95 < 5000; c3_i95++) {
            c3_dv29[c3_i95] = chartInstance->c3_bmlsM[c3_i95];
          }

          chartInstance->c3_mEmpty = c3_isEmptyQueue(chartInstance, c3_dv29);
          c3_updateDataWrittenToVector(chartInstance, 9U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c3_mEmpty, 13U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       chartInstance->c3_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
}

static void c3_encStr2Arr(SFc3_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c3_myarr256[1000])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr;
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[1000];
  char_T c3_mystr;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i96;
  int32_T c3_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_arr, 1U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_mystr, 5U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = c3_maxarrsize - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i96 = 0; c3_i96 < 1000; c3_i96++) {
    c3_tt[c3_i96] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_tt[0] = c3_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i97 = 0; c3_i97 < 1000; c3_i97++) {
    c3_myarr256[c3_i97] = c3_tt[c3_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c3_isequal(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c3_varargin_1[1000], real_T c3_varargin_2[1000])
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
  while ((exitg1 == false) && (c3_k < 1000)) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_x1 = c3_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 1000, 1, 0) - 1];
    c3_x2 = c3_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 1000, 1, 0) - 1];
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
    "C:\\Users\\root180\\Documents\\affective-project\\14-12-2015-Matlab\\encStr2Arr.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i98;
  real_T c3_b_inData[1000];
  int32_T c3_i99;
  real_T c3_u[1000];
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i98 = 0; c3_i98 < 1000; c3_i98++) {
    c3_b_inData[c3_i98] = (*(real_T (*)[1000])c3_inData)[c3_i98];
  }

  for (c3_i99 = 0; c3_i99 < 1000; c3_i99++) {
    c3_u[c3_i99] = c3_b_inData[c3_i99];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[1000])
{
  real_T c3_dv30[1000];
  int32_T c3_i100;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv30, 1, 0, 0U, 1, 0U, 1, 1000);
  for (c3_i100 = 0; c3_i100 < 1000; c3_i100++) {
    c3_y[c3_i100] = c3_dv30[c3_i100];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[1000];
  int32_T c3_i101;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i101 = 0; c3_i101 < 1000; c3_i101++) {
    (*(real_T (*)[1000])c3_outData)[c3_i101] = c3_y[c3_i101];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  char_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(char_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  real_T c3_b_inData[5000];
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  real_T c3_u[5000];
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i102 = 0;
  for (c3_i103 = 0; c3_i103 < 5; c3_i103++) {
    for (c3_i104 = 0; c3_i104 < 1000; c3_i104++) {
      c3_b_inData[c3_i104 + c3_i102] = (*(real_T (*)[5000])c3_inData)[c3_i104 +
        c3_i102];
    }

    c3_i102 += 1000;
  }

  c3_i105 = 0;
  for (c3_i106 = 0; c3_i106 < 5; c3_i106++) {
    for (c3_i107 = 0; c3_i107 < 1000; c3_i107++) {
      c3_u[c3_i107 + c3_i105] = c3_b_inData[c3_i107 + c3_i105];
    }

    c3_i105 += 1000;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_newBmls, const char_T *c3_identifier, real_T c3_y[5000])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_newBmls), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_newBmls);
}

static void c3_e_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[5000])
{
  real_T c3_dv31[5000];
  int32_T c3_i108;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv31, 1, 0, 0U, 1, 0U, 2, 1000,
                5);
  for (c3_i108 = 0; c3_i108 < 5000; c3_i108++) {
    c3_y[c3_i108] = c3_dv31[c3_i108];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_newBmls;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[5000];
  int32_T c3_i109;
  int32_T c3_i110;
  int32_T c3_i111;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_newBmls = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_newBmls), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_newBmls);
  c3_i109 = 0;
  for (c3_i110 = 0; c3_i110 < 5; c3_i110++) {
    for (c3_i111 = 0; c3_i111 < 1000; c3_i111++) {
      (*(real_T (*)[5000])c3_outData)[c3_i111 + c3_i109] = c3_y[c3_i111 +
        c3_i109];
    }

    c3_i109 += 1000;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_f_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Demo_AU_VA1_get_eml_resolved_functions_info(void)
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
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
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

static void c3_removeQueue(SFc3_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c3_bmls[5000], real_T c3_newBmls[5000])
{
  uint32_T c3_debug_family_var_map[4];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  real_T c3_dv32[1000];
  int32_T c3_i112;
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i116;
  int32_T c3_i117;
  int32_T c3_i118;
  int32_T c3_i119;
  int32_T c3_i120;
  int32_T c3_i121;
  real_T c3_dv33[1000];
  int32_T c3_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bmls, 2U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_newBmls, 3U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 2);
  c3_encStr2Arr(chartInstance, c3_dv32);
  for (c3_i112 = 0; c3_i112 < 1000; c3_i112++) {
    chartInstance->c3_n[c3_i112] = c3_dv32[c3_i112];
  }

  c3_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 3);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 10U, 14U);
  for (c3_i113 = 0; c3_i113 < 1000; c3_i113++) {
    c3_newBmls[c3_i113] = chartInstance->c3_n[c3_i113];
  }

  for (c3_i114 = 0; c3_i114 < 1000; c3_i114++) {
    c3_newBmls[c3_i114 + 1000] = chartInstance->c3_n[c3_i114];
  }

  for (c3_i115 = 0; c3_i115 < 1000; c3_i115++) {
    c3_newBmls[c3_i115 + 2000] = chartInstance->c3_n[c3_i115];
  }

  for (c3_i116 = 0; c3_i116 < 1000; c3_i116++) {
    c3_newBmls[c3_i116 + 3000] = chartInstance->c3_n[c3_i116];
  }

  for (c3_i117 = 0; c3_i117 < 1000; c3_i117++) {
    c3_newBmls[c3_i117 + 4000] = chartInstance->c3_n[c3_i117];
  }

  c3_updateDataWrittenToVector(chartInstance, 10U);
  c3_updateDataWrittenToVector(chartInstance, 10U);
  c3_updateDataWrittenToVector(chartInstance, 10U);
  c3_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 4);
  for (c3_i118 = 0; c3_i118 < 1000; c3_i118++) {
    c3_newBmls[c3_i118] = c3_bmls[c3_i118 + 1000];
  }

  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 5);
  for (c3_i119 = 0; c3_i119 < 1000; c3_i119++) {
    c3_newBmls[c3_i119 + 1000] = c3_bmls[c3_i119 + 2000];
  }

  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 6);
  for (c3_i120 = 0; c3_i120 < 1000; c3_i120++) {
    c3_newBmls[c3_i120 + 2000] = c3_bmls[c3_i120 + 3000];
  }

  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 7);
  for (c3_i121 = 0; c3_i121 < 1000; c3_i121++) {
    c3_newBmls[c3_i121 + 3000] = c3_bmls[c3_i121 + 4000];
  }

  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, 8);
  c3_encStr2Arr(chartInstance, c3_dv33);
  for (c3_i122 = 0; c3_i122 < 1000; c3_i122++) {
    c3_newBmls[c3_i122 + 4000] = c3_dv33[c3_i122];
  }

  _SFD_EML_CALL(7U, chartInstance->c3_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c3_isEmptyQueue(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c3_bmls[5000])
{
  real_T c3_empty;
  uint32_T c3_debug_family_var_map[6];
  real_T c3_tempp[1000];
  real_T c3_i;
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i123;
  static real_T c3_dv34[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  int32_T c3_b_i;
  int32_T c3_c_i;
  int32_T c3_i124;
  real_T c3_b_bmls[1000];
  int32_T c3_i125;
  real_T c3_dv35[1000];
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_tempp, 0U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_bmls, 4U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_empty, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 2);
  c3_empty = 1.0;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 3);
  for (c3_i123 = 0; c3_i123 < 1000; c3_i123++) {
    c3_tempp[c3_i123] = c3_dv34[c3_i123];
  }

  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 4);
  c3_i = 1.0;
  c3_b_i = 0;
  do {
    exitg1 = 0;
    if (c3_b_i < 5) {
      c3_i = 1.0 + (real_T)c3_b_i;
      CV_EML_FOR(5, 1, 0, 1);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 5);
      c3_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c3_i), 1, 5, 2, 0) - 1;
      for (c3_i124 = 0; c3_i124 < 1000; c3_i124++) {
        c3_b_bmls[c3_i124] = c3_bmls[c3_i124 + 1000 * c3_c_i];
      }

      for (c3_i125 = 0; c3_i125 < 1000; c3_i125++) {
        c3_dv35[c3_i125] = c3_dv34[c3_i125];
      }

      if (CV_EML_IF(5, 1, 0, (real_T)c3_isequal(chartInstance, c3_b_bmls,
            c3_dv35) == 0.0)) {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 6);
        c3_empty = 0.0;
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 7);
        exitg1 = 1;
      } else {
        c3_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(5, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_empty;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_g_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i126;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i126, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i126;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_secs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_secs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_secs), &c3_thisId);
  sf_mex_destroy(&c3_secs);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_h_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i127;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i127, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i127;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_i_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_b_tp_facialExpression_Controller, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_tp_facialExpression_Controller), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_facialExpression_Controller);
  return c3_y;
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
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

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_facialExpression_Controller;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_b_tp_facialExpression_Controller = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_tp_facialExpression_Controller), &c3_thisId);
  sf_mex_destroy(&c3_b_tp_facialExpression_Controller);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i128;
  real_T c3_b_inData[11];
  int32_T c3_i129;
  real_T c3_u[11];
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i128 = 0; c3_i128 < 11; c3_i128++) {
    c3_b_inData[c3_i128] = (*(real_T (*)[11])c3_inData)[c3_i128];
  }

  for (c3_i129 = 0; c3_i129 < 11; c3_i129++) {
    c3_u[c3_i129] = c3_b_inData[c3_i129];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 11), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_k_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_emotion_amount_factor, const char_T *c3_identifier, real_T
  c3_y[11])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_emotion_amount_factor),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_emotion_amount_factor);
}

static void c3_l_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[11])
{
  real_T c3_dv36[11];
  int32_T c3_i130;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv36, 1, 0, 0U, 1, 0U, 2, 1,
                11);
  for (c3_i130 = 0; c3_i130 < 11; c3_i130++) {
    c3_y[c3_i130] = c3_dv36[c3_i130];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_emotion_amount_factor;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[11];
  int32_T c3_i131;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_emotion_amount_factor = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_emotion_amount_factor),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_emotion_amount_factor);
  for (c3_i131 = 0; c3_i131 < 11; c3_i131++) {
    (*(real_T (*)[11])c3_outData)[c3_i131] = c3_y[c3_i131];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i132;
  real_T c3_b_inData[1000];
  int32_T c3_i133;
  real_T c3_u[1000];
  const mxArray *c3_y = NULL;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i132 = 0; c3_i132 < 1000; c3_i132++) {
    c3_b_inData[c3_i132] = (*(real_T (*)[1000])c3_inData)[c3_i132];
  }

  for (c3_i133 = 0; c3_i133 < 1000; c3_i133++) {
    c3_u[c3_i133] = c3_b_inData[c3_i133];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_m_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_b_BML, const char_T *c3_identifier, real_T c3_y[1000])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_BML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_BML);
}

static void c3_n_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[1000])
{
  real_T c3_dv37[1000];
  int32_T c3_i134;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv37, 1, 0, 0U, 1, 0U, 2, 1000,
                1);
  for (c3_i134 = 0; c3_i134 < 1000; c3_i134++) {
    c3_y[c3_i134] = c3_dv37[c3_i134];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_BML;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[1000];
  int32_T c3_i135;
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c3_b_BML = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_BML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_BML);
  for (c3_i135 = 0; c3_i135 < 1000; c3_i135++) {
    (*(real_T (*)[1000])c3_outData)[c3_i135] = c3_y[c3_i135];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_o_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_b_subchartSimStateInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_subchartSimStateInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_subchartSimStateInfo);
  return c3_y;
}

static const mxArray *c3_p_emlrt_marshallIn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 12, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn(SFc3_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 12, 1,
    0)]);
}

static real_T c3_get_bmlsL(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c3_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c3_b);
  if (chartInstance->c3_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2135) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c3_bmlsL_address)[c3_b];
}

static void c3_set_bmlsL(SFc3_Demo_AU_VA1InstanceStruct *chartInstance, uint32_T
  c3_b, real_T c3_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c3_b);
  if (chartInstance->c3_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2135) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c3_bmlsL_address)[c3_b] = c3_c;
}

static real_T *c3_access_bmlsL(SFc3_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c3_b)
{
  real_T *c3_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c3_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2135) in the initialization routine of the chart.\n");
  }

  c3_c = *chartInstance->c3_bmlsL_address;
  if (c3_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c3_c;
}

static void init_dsm_address_info(SFc3_Demo_AU_VA1InstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c3_bmlsL_address, &chartInstance->c3_bmlsL_index);
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

void sf_c3_Demo_AU_VA1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1006977840U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3509758971U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3567440653U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1995030326U);
}

mxArray *sf_c3_Demo_AU_VA1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("08WMXCt1Uun4dW8X12ptr");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[1] = (double)(11);
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Demo_AU_VA1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Demo_AU_VA1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_Demo_AU_VA1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[62],T\"emotion_amount_factor\",},{M[3],M[71],T\"BML\",},{M[3],M[67],T\"bmlsH\",},{M[3],M[60],T\"bmlsL\",},{M[3],M[65],T\"bmlsM\",},{M[3],M[63],T\"hEmpty\",},{M[3],M[73],T\"lEmpty\",},{M[3],M[74],T\"mEmpty\",},{M[3],M[75],T\"n\",},{M[3],M[70],T\"newBmlA\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[3],M[66],T\"newBmlsH\",},{M[3],M[61],T\"newBmlsL\",},{M[3],M[64],T\"newBmlsM\",},{M[8],M[0],T\"is_active_c3_Demo_AU_VA1\",},{M[8],M[1],T\"is_active_facialExpression_Controller\",},{M[8],M[9],T\"is_active_sendBMLbyPriority\",},{M[9],M[9],T\"is_sendBMLbyPriority\",},{M[14],M[1],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 18, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Demo_AU_VA1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_AU_VA1MachineNumber_,
           3,
           12,
           18,
           0,
           20,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_AU_VA1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_AU_VA1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_AU_VA1MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(2,0,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(3,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(4,2,0,1,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(5,0,0,0,"hEmpty");
          _SFD_SET_DATA_PROPS(6,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(7,0,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(8,0,0,0,"newBmlsH");
          _SFD_SET_DATA_PROPS(9,0,0,0,"bmlsH");
          _SFD_SET_DATA_PROPS(10,0,0,0,"newBmlA");
          _SFD_SET_DATA_PROPS(11,0,0,0,"BML");
          _SFD_SET_DATA_PROPS(12,0,0,0,"lEmpty");
          _SFD_SET_DATA_PROPS(13,0,0,0,"mEmpty");
          _SFD_SET_DATA_PROPS(14,0,0,0,"n");
          _SFD_SET_DATA_PROPS(15,8,0,0,"");
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,7);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_INDEX(1,3,6);
          _SFD_ST_SUBSTATE_INDEX(1,4,9);
          _SFD_ST_SUBSTATE_INDEX(1,5,10);
          _SFD_ST_SUBSTATE_INDEX(1,6,11);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,7,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
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
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"removeQueue",0,-1,234);
        _SFD_CV_INIT_EML(5,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"isEmptyQueue",0,-1,201);
        _SFD_CV_INIT_EML_IF(5,1,0,82,114,-1,-2);
        _SFD_CV_INIT_EML_FOR(5,1,0,66,78,200);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,10,1,10);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_i_sf_marshallOut,(MexInFcnForType)
            c3_h_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_j_sf_marshallOut,(MexInFcnForType)
            c3_i_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_j_sf_marshallOut,(MexInFcnForType)
            c3_i_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_j_sf_marshallOut,(MexInFcnForType)
            c3_i_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));

        {
          real_T *c3_inV;
          real_T *c3_inA;
          real_T (*c3_emotion_amount_factor)[11];
          c3_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c3_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_inV);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_inA);
          _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c3_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_emotion_amount_factor);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c3_hEmpty);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_bmlsM);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c3_newBmlsH);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_bmlsH);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_newBmlA);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c3_BML);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_lEmpty);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_mEmpty);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c3_n);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_AU_VA1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "MRqvEKsaiNl7demorldYDH";
}

static void sf_opaque_initialize_c3_Demo_AU_VA1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*)
    chartInstanceVar);
  initialize_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Demo_AU_VA1(void *chartInstanceVar)
{
  enable_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Demo_AU_VA1(void *chartInstanceVar)
{
  disable_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Demo_AU_VA1(void *chartInstanceVar)
{
  sf_gateway_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Demo_AU_VA1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Demo_AU_VA1
    ((SFc3_Demo_AU_VA1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Demo_AU_VA1();/* state var info */
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

extern void sf_internal_set_sim_state_c3_Demo_AU_VA1(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_Demo_AU_VA1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Demo_AU_VA1(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_Demo_AU_VA1(S);
}

static void sf_opaque_set_sim_state_c3_Demo_AU_VA1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_Demo_AU_VA1(S, st);
}

static void sf_opaque_terminate_c3_Demo_AU_VA1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_AU_VA1_optimization_info();
    }

    finalize_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Demo_AU_VA1(SimStruct *S)
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
    initialize_params_c3_Demo_AU_VA1((SFc3_Demo_AU_VA1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_Demo_AU_VA1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_AU_VA1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,3,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(503084278U));
  ssSetChecksum1(S,(3566046081U));
  ssSetChecksum2(S,(1345451960U));
  ssSetChecksum3(S,(3199665855U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Demo_AU_VA1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_Demo_AU_VA1(SimStruct *S)
{
  SFc3_Demo_AU_VA1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_Demo_AU_VA1InstanceStruct *)utMalloc(sizeof
    (SFc3_Demo_AU_VA1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_Demo_AU_VA1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Demo_AU_VA1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Demo_AU_VA1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Demo_AU_VA1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Demo_AU_VA1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Demo_AU_VA1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Demo_AU_VA1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Demo_AU_VA1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Demo_AU_VA1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Demo_AU_VA1;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Demo_AU_VA1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Demo_AU_VA1;
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

void c3_Demo_AU_VA1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Demo_AU_VA1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Demo_AU_VA1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Demo_AU_VA1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Demo_AU_VA1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}