/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DemoIdle_PEC_sfun.h"
#include "c20_DemoIdle_PEC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DemoIdle_PEC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c20_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c20_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c20_IN_gazeCamera              ((uint8_T)1U)
#define c20_IN_gazeCamera1             ((uint8_T)2U)
#define c20_IN_gazeCamera2             ((uint8_T)3U)
#define c20_IN_init                    ((uint8_T)4U)
#define c20_IN_wave                    ((uint8_T)5U)
#define c20_IN_waveBothHands           ((uint8_T)6U)
#define c20_IN_waveLeftHand            ((uint8_T)7U)
#define c20_IN_waveRightHand           ((uint8_T)8U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c20_debug_family_names[11] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "bmlID", "pr", "poseBML" };

static const char * c20_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_g_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "mBML", "newBmls" };

static const char * c20_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c20_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c20_dataWrittenToVector[10];

/* Function Declarations */
static void initialize_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void initialize_params_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct *
  chartInstance);
static void enable_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void disable_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_update_debugger_state_c20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void set_sim_state_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_st);
static void c20_set_sim_state_side_effects_c20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void finalize_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void sf_gateway_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_enter_atomic_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_enter_internal_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void c20_exit_internal_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct *
  chartInstance);
static void c20_initc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void initSimStructsc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_enter_atomic_gazeCamera(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_gazeCamera(SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void c20_wave(SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void c20_enter_atomic_gazeCamera1(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_gazeCamera1(SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void c20_enter_atomic_waveLeftHand(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_enter_atomic_waveBothHands(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_enter_atomic_gazeCamera2(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256]);
static void c20_b_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256]);
static void c20_c_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256]);
static void c20_d_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256]);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  const mxArray *c20_poseBML, const char_T *c20_identifier, real_T c20_y[256]);
static void c20_b_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_c_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_pr, const char_T *c20_identifier);
static real_T c20_d_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static boolean_T c20_e_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_f_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_myarr256, const char_T *c20_identifier,
  real_T c20_y[256]);
static void c20_g_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256]);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_h_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_i_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_j_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_k_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_l_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_m_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_n_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_o_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_h_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_newBmls, const char_T *c20_identifier,
  real_T c20_y[1280]);
static void c20_i_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[1280]);
static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_p_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(const char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u);
static void c20_activate_secsc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_deactivate_secsc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);
static void c20_increment_counters_secsc20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void c20_reset_counters_secsc20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance);
static void c20_wavePoseBradTablec20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance, real_T c20_bmlID, real_T
   *c20_pr, real_T c20_poseBML[256]);
static void c20_insertQueuec20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, real_T c20_bmls[1280], real_T c20_mBML[256], real_T
  c20_newBmls[1280]);
static const mxArray *c20_q_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int8_T c20_j_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_r_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_k_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_s_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint8_T c20_l_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_b_tp_init, const char_T *c20_identifier);
static uint8_T c20_m_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_n_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_b_setSimStateSideEffectsInfo, const char_T *
  c20_identifier);
static const mxArray *c20_o_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_updateDataWrittenToVector(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_vectorIndex);
static void c20_errorIfDataNotWrittenToFcn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_vectorIndex, uint32_T c20_dataNumber);
static real_T c20_get_BML(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_BML(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_BML(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static real_T c20_get_BML2(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_BML2(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_BML2(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static real_T c20_get_P(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_P(SFc20_DemoIdle_PECInstanceStruct *chartInstance, uint32_T
                      c20_b, real_T c20_c);
static real_T *c20_access_P(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static real_T c20_get_STATE_BEFORE(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_STATE_BEFORE(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_STATE_BEFORE(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_STATE_OVER(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_STATE_OVER(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_STATE_OVER(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_b);
static real_T c20_get_avert(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_avert(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_avert(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static real_T c20_get_bmlsM(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_bmlsM(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_bmlsM(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static real_T c20_get_fileID(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void c20_set_fileID(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c);
static real_T *c20_access_fileID(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b);
static void init_dsm_address_info(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c20_update_debugger_state_c20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  uint32_T c20_prevAniVal;
  c20_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c20_is_active_c20_DemoIdle_PEC == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_waveRightHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_wave) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_gazeCamera1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_waveLeftHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_waveBothHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_gazeCamera2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  }

  _SFD_SET_ANIMATION(c20_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  int32_T c20_i0;
  real_T c20_b_u[256];
  const mxArray *c20_c_y = NULL;
  real_T c20_b_hoistedGlobal;
  real_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  real_T c20_c_hoistedGlobal;
  real_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  int32_T c20_i1;
  real_T c20_e_u[256];
  const mxArray *c20_f_y = NULL;
  int32_T c20_i2;
  real_T c20_f_u[1280];
  const mxArray *c20_g_y = NULL;
  real_T c20_d_hoistedGlobal;
  real_T c20_g_u;
  const mxArray *c20_h_y = NULL;
  uint8_T c20_e_hoistedGlobal;
  uint8_T c20_h_u;
  const mxArray *c20_i_y = NULL;
  uint8_T c20_f_hoistedGlobal;
  uint8_T c20_i_u;
  const mxArray *c20_j_y = NULL;
  uint8_T c20_g_hoistedGlobal;
  uint8_T c20_j_u;
  const mxArray *c20_k_y = NULL;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(10, 1), false);
  c20_hoistedGlobal = *c20_gameState;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  for (c20_i0 = 0; c20_i0 < 256; c20_i0++) {
    c20_b_u[c20_i0] = chartInstance->c20_BMLM[c20_i0];
  }

  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", c20_b_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_b_hoistedGlobal = chartInstance->c20_bFlag;
  c20_c_u = c20_b_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_c_hoistedGlobal = chartInstance->c20_lFlag;
  c20_d_u = c20_c_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  for (c20_i1 = 0; c20_i1 < 256; c20_i1++) {
    c20_e_u[c20_i1] = chartInstance->c20_n[c20_i1];
  }

  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", c20_e_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c20_y, 4, c20_f_y);
  for (c20_i2 = 0; c20_i2 < 1280; c20_i2++) {
    c20_f_u[c20_i2] = chartInstance->c20_newBmlsM[c20_i2];
  }

  c20_g_y = NULL;
  sf_mex_assign(&c20_g_y, sf_mex_create("y", c20_f_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c20_y, 5, c20_g_y);
  c20_d_hoistedGlobal = chartInstance->c20_rFlag;
  c20_g_u = c20_d_hoistedGlobal;
  c20_h_y = NULL;
  sf_mex_assign(&c20_h_y, sf_mex_create("y", &c20_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 6, c20_h_y);
  c20_e_hoistedGlobal = chartInstance->c20_is_active_c20_DemoIdle_PEC;
  c20_h_u = c20_e_hoistedGlobal;
  c20_i_y = NULL;
  sf_mex_assign(&c20_i_y, sf_mex_create("y", &c20_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 7, c20_i_y);
  c20_f_hoistedGlobal = chartInstance->c20_is_c20_DemoIdle_PEC;
  c20_i_u = c20_f_hoistedGlobal;
  c20_j_y = NULL;
  sf_mex_assign(&c20_j_y, sf_mex_create("y", &c20_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 8, c20_j_y);
  c20_g_hoistedGlobal = chartInstance->c20_temporalCounter_i1;
  c20_j_u = c20_g_hoistedGlobal;
  c20_k_y = NULL;
  sf_mex_assign(&c20_k_y, sf_mex_create("y", &c20_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 9, c20_k_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv0[256];
  int32_T c20_i3;
  real_T c20_dv1[256];
  int32_T c20_i4;
  real_T c20_dv2[1280];
  int32_T c20_i5;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_u = sf_mex_dup(c20_st);
  *c20_gameState = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 0)), "gameState");
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
                       "BMLM", c20_dv0);
  for (c20_i3 = 0; c20_i3 < 256; c20_i3++) {
    chartInstance->c20_BMLM[c20_i3] = c20_dv0[c20_i3];
  }

  chartInstance->c20_bFlag = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 2)), "bFlag");
  chartInstance->c20_lFlag = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 3)), "lFlag");
  c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 4)),
    "n", c20_dv1);
  for (c20_i4 = 0; c20_i4 < 256; c20_i4++) {
    chartInstance->c20_n[c20_i4] = c20_dv1[c20_i4];
  }

  c20_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 5)),
    "newBmlsM", c20_dv2);
  for (c20_i5 = 0; c20_i5 < 1280; c20_i5++) {
    chartInstance->c20_newBmlsM[c20_i5] = c20_dv2[c20_i5];
  }

  chartInstance->c20_rFlag = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 6)), "rFlag");
  chartInstance->c20_is_active_c20_DemoIdle_PEC = c20_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 7)),
     "is_active_c20_DemoIdle_PEC");
  chartInstance->c20_is_c20_DemoIdle_PEC = c20_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 8)), "is_c20_DemoIdle_PEC");
  chartInstance->c20_temporalCounter_i1 = c20_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 9)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c20_setSimStateSideEffectsInfo,
                c20_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 10)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c20_u);
  chartInstance->c20_doSetSimStateSideEffects = 1U;
  c20_update_debugger_state_c20_DemoIdle_PEC(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void c20_set_sim_state_side_effects_c20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  if (chartInstance->c20_doSetSimStateSideEffects != 0) {
    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_gazeCamera) {
      chartInstance->c20_tp_gazeCamera = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_gazeCamera = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_gazeCamera1) {
      chartInstance->c20_tp_gazeCamera1 = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_gazeCamera1 = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_gazeCamera2) {
      chartInstance->c20_tp_gazeCamera2 = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_gazeCamera2 = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_init) {
      chartInstance->c20_tp_init = 1U;
    } else {
      chartInstance->c20_tp_init = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_wave) {
      chartInstance->c20_tp_wave = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_wave = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_waveBothHands) {
      chartInstance->c20_tp_waveBothHands = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_waveBothHands = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_waveLeftHand) {
      chartInstance->c20_tp_waveLeftHand = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_waveLeftHand = 0U;
    }

    if (chartInstance->c20_is_c20_DemoIdle_PEC == c20_IN_waveRightHand) {
      chartInstance->c20_tp_waveRightHand = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_waveRightHand = 0U;
    }

    chartInstance->c20_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c20_setSimStateSideEffectsInfo);
}

static void sf_gateway_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  c20_set_sim_state_side_effects_c20_DemoIdle_PEC(chartInstance);
}

static void c20_enter_atomic_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 11U, chartInstance->c20_sfEvent);
  chartInstance->c20_is_active_c20_DemoIdle_PEC = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c20_sfEvent);
}

static void c20_enter_internal_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  uint32_T c20_b_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr;
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr;
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_myarr256[256];
  int32_T c20_i6;
  int32_T c20_i7;
  int32_T c20_i8;
  int32_T c20_i9;
  int32_T c20_i10;
  int32_T c20_i11;
  int32_T c20_i12;
  int32_T c20_i13;
  int32_T c20_i14;
  int32_T c20_i15;
  int32_T c20_i16;
  int32_T c20_i17;
  int32_T c20_i18;
  int32_T c20_i19;
  int32_T c20_i20;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c20_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  chartInstance->c20_isStable = false;
  chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_init;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  chartInstance->c20_tp_init = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_i_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c20_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  *c20_gameState = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c20_gameState, 2U);
  chartInstance->c20_rFlag = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
  chartInstance->c20_lFlag = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
  chartInstance->c20_bFlag = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_h_debug_family_names,
    c20_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_arr, 1U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_mystr, 5U, c20_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  c20_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  c20_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i6 = 0; c20_i6 < 256; c20_i6++) {
    c20_tt[c20_i6] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  c20_tt[0] = c20_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i7 = 0; c20_i7 < 256; c20_i7++) {
    c20_myarr256[c20_i7] = c20_tt[c20_i7];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i8 = 0; c20_i8 < 256; c20_i8++) {
    chartInstance->c20_n[c20_i8] = c20_myarr256[c20_i8];
  }

  c20_updateDataWrittenToVector(chartInstance, 6U);
  for (c20_i9 = 0; c20_i9 < 256; c20_i9++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_n[c20_i9], 15U);
  }

  c20_errorIfDataNotWrittenToFcn(chartInstance, 6U, 15U);
  for (c20_i10 = 0; c20_i10 < 256; c20_i10++) {
    c20_set_bmlsM(chartInstance, c20_i10, chartInstance->c20_n[c20_i10]);
  }

  for (c20_i11 = 0; c20_i11 < 256; c20_i11++) {
    c20_set_bmlsM(chartInstance, c20_i11 + 256, chartInstance->c20_n[c20_i11]);
  }

  for (c20_i12 = 0; c20_i12 < 256; c20_i12++) {
    c20_set_bmlsM(chartInstance, c20_i12 + 512, chartInstance->c20_n[c20_i12]);
  }

  for (c20_i13 = 0; c20_i13 < 256; c20_i13++) {
    c20_set_bmlsM(chartInstance, c20_i13 + 768, chartInstance->c20_n[c20_i13]);
  }

  for (c20_i14 = 0; c20_i14 < 256; c20_i14++) {
    c20_set_bmlsM(chartInstance, c20_i14 + 1024, chartInstance->c20_n[c20_i14]);
  }

  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 6U);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c20_errorIfDataNotWrittenToFcn(chartInstance, 6U, 15U);
  for (c20_i15 = 0; c20_i15 < 256; c20_i15++) {
    chartInstance->c20_newBmlsM[c20_i15] = chartInstance->c20_n[c20_i15];
  }

  for (c20_i16 = 0; c20_i16 < 256; c20_i16++) {
    chartInstance->c20_newBmlsM[c20_i16 + 256] = chartInstance->c20_n[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 256; c20_i17++) {
    chartInstance->c20_newBmlsM[c20_i17 + 512] = chartInstance->c20_n[c20_i17];
  }

  for (c20_i18 = 0; c20_i18 < 256; c20_i18++) {
    chartInstance->c20_newBmlsM[c20_i18 + 768] = chartInstance->c20_n[c20_i18];
  }

  for (c20_i19 = 0; c20_i19 < 256; c20_i19++) {
    chartInstance->c20_newBmlsM[c20_i19 + 1024] = chartInstance->c20_n[c20_i19];
  }

  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 6U);
  c20_updateDataWrittenToVector(chartInstance, 5U);
  for (c20_i20 = 0; c20_i20 < 1280; c20_i20++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i20], 13U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i21;
  int32_T c20_i22;
  int32_T c20_i23;
  real_T c20_dv3[1280];
  int32_T c20_i24;
  real_T c20_dv4[256];
  real_T c20_dv5[1280];
  int32_T c20_i25;
  int32_T c20_i26;
  int32_T c20_i27;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 1.0;
  boolean_T c20_c_out;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 1.0;
  boolean_T c20_d_out;
  real_T c20_f_nargin = 0.0;
  real_T c20_f_nargout = 1.0;
  boolean_T c20_e_out;
  real_T *c20_gameState;
  c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c20_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_isStable = true;
  switch (chartInstance->c20_is_c20_DemoIdle_PEC) {
   case c20_IN_gazeCamera:
    CV_CHART_EVAL(11, 0, 1);
    c20_gazeCamera(chartInstance);
    break;

   case c20_IN_gazeCamera1:
    CV_CHART_EVAL(11, 0, 2);
    c20_gazeCamera1(chartInstance);
    break;

   case c20_IN_gazeCamera2:
    CV_CHART_EVAL(11, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_hb_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_out = CV_EML_IF(9, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs) &&
                        (chartInstance->c20_temporalCounter_i1 >= 4));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_gazeCamera2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_waveBothHands;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_waveBothHands = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_n_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 3.0, &c20_P,
        c20_b_BMLM);
      c20_set_P(chartInstance, 0, c20_P);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      for (c20_i21 = 0; c20_i21 < 256; c20_i21++) {
        chartInstance->c20_BMLM[c20_i21] = c20_b_BMLM[c20_i21];
      }

      c20_updateDataWrittenToVector(chartInstance, 4U);
      for (c20_i22 = 0; c20_i22 < 256; c20_i22++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i22], 12U);
      }

      chartInstance->c20_bFlag = 1.0;
      c20_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
      c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
      for (c20_i23 = 0; c20_i23 < 1280; c20_i23++) {
        c20_dv3[c20_i23] = c20_get_bmlsM(chartInstance, c20_i23);
      }

      for (c20_i24 = 0; c20_i24 < 256; c20_i24++) {
        c20_dv4[c20_i24] = chartInstance->c20_BMLM[c20_i24];
      }

      c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv3, c20_dv4, c20_dv5);
      for (c20_i25 = 0; c20_i25 < 1280; c20_i25++) {
        chartInstance->c20_newBmlsM[c20_i25] = c20_dv5[c20_i25];
      }

      c20_updateDataWrittenToVector(chartInstance, 5U);
      for (c20_i26 = 0; c20_i26 < 1280; c20_i26++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i26], 13U);
      }

      c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
      for (c20_i27 = 0; c20_i27 < 1280; c20_i27++) {
        c20_set_bmlsM(chartInstance, c20_i27, chartInstance->
                      c20_newBmlsM[c20_i27]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_init:
    CV_CHART_EVAL(11, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_s_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_errorIfDataNotWrittenToFcn(chartInstance, 0U, 2U);
    c20_b_out = CV_EML_IF(7, 0, 0, *c20_gameState == 10.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_wave:
    CV_CHART_EVAL(11, 0, 5);
    c20_wave(chartInstance);
    break;

   case c20_IN_waveBothHands:
    CV_CHART_EVAL(11, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_r_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_c_out = CV_EML_IF(6, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs)
                          && (chartInstance->c20_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_waveBothHands = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveLeftHand:
    CV_CHART_EVAL(11, 0, 7);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_q_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_d_out = CV_EML_IF(5, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs)
                          && (chartInstance->c20_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_waveLeftHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveRightHand:
    CV_CHART_EVAL(11, 0, 8);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_p_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_e_out = CV_EML_IF(4, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs)
                          && (chartInstance->c20_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_waveRightHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_wave;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_wave = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c20_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_CHART_EVAL(11, 0, 0);
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_c20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct *
  chartInstance)
{
  switch (chartInstance->c20_is_c20_DemoIdle_PEC) {
   case c20_IN_gazeCamera:
    CV_CHART_EVAL(11, 0, 1);
    chartInstance->c20_tp_gazeCamera = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_gazeCamera1:
    CV_CHART_EVAL(11, 0, 2);
    chartInstance->c20_tp_gazeCamera1 = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_gazeCamera2:
    CV_CHART_EVAL(11, 0, 3);
    chartInstance->c20_tp_gazeCamera2 = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_init:
    CV_CHART_EVAL(11, 0, 4);
    chartInstance->c20_tp_init = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_wave:
    CV_CHART_EVAL(11, 0, 5);
    chartInstance->c20_tp_wave = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveBothHands:
    CV_CHART_EVAL(11, 0, 6);
    chartInstance->c20_tp_waveBothHands = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveLeftHand:
    CV_CHART_EVAL(11, 0, 7);
    chartInstance->c20_tp_waveLeftHand = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_waveRightHand:
    CV_CHART_EVAL(11, 0, 8);
    chartInstance->c20_tp_waveRightHand = 0U;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_CHART_EVAL(11, 0, 0);
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_initc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_doSetSimStateSideEffects = 0U;
  chartInstance->c20_setSimStateSideEffectsInfo = NULL;
  chartInstance->c20_tp_gazeCamera = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_gazeCamera1 = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_gazeCamera2 = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_init = 0U;
  chartInstance->c20_tp_wave = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_waveBothHands = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_waveLeftHand = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_waveRightHand = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_is_active_c20_DemoIdle_PEC = 0U;
  chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c20_enter_atomic_gazeCamera(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i28;
  int32_T c20_i29;
  int32_T c20_i30;
  real_T c20_dv6[1280];
  int32_T c20_i31;
  real_T c20_dv7[256];
  real_T c20_dv8[1280];
  int32_T c20_i32;
  int32_T c20_i33;
  int32_T c20_i34;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_k_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 6.0, &c20_P, c20_b_BMLM);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i28 = 0; c20_i28 < 256; c20_i28++) {
    chartInstance->c20_BMLM[c20_i28] = c20_b_BMLM[c20_i28];
  }

  c20_updateDataWrittenToVector(chartInstance, 4U);
  for (c20_i29 = 0; c20_i29 < 256; c20_i29++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i29], 12U);
  }

  c20_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
  for (c20_i30 = 0; c20_i30 < 1280; c20_i30++) {
    c20_dv6[c20_i30] = c20_get_bmlsM(chartInstance, c20_i30);
  }

  for (c20_i31 = 0; c20_i31 < 256; c20_i31++) {
    c20_dv7[c20_i31] = chartInstance->c20_BMLM[c20_i31];
  }

  c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv6, c20_dv7, c20_dv8);
  for (c20_i32 = 0; c20_i32 < 1280; c20_i32++) {
    chartInstance->c20_newBmlsM[c20_i32] = c20_dv8[c20_i32];
  }

  c20_updateDataWrittenToVector(chartInstance, 5U);
  for (c20_i33 = 0; c20_i33 < 1280; c20_i33++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i33], 13U);
  }

  c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
  for (c20_i34 = 0; c20_i34 < 1280; c20_i34++) {
    c20_set_bmlsM(chartInstance, c20_i34, chartInstance->c20_newBmlsM[c20_i34]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_gazeCamera(SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i35;
  int32_T c20_i36;
  int32_T c20_i37;
  real_T c20_dv9[1280];
  int32_T c20_i38;
  real_T c20_dv10[256];
  real_T c20_dv11[1280];
  int32_T c20_i39;
  int32_T c20_i40;
  int32_T c20_i41;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_t_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  c20_out = CV_EML_IF(11, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs) &&
                      (chartInstance->c20_temporalCounter_i1 >= 4));
  _SFD_SYMBOL_SCOPE_POP();
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_gazeCamera = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    chartInstance->c20_isStable = false;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_waveRightHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
    chartInstance->c20_temporalCounter_i1 = 0U;
    chartInstance->c20_tp_waveRightHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_j_debug_family_names,
      c20_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 1.0, &c20_P, c20_b_BMLM);
    c20_set_P(chartInstance, 0, c20_P);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    for (c20_i35 = 0; c20_i35 < 256; c20_i35++) {
      chartInstance->c20_BMLM[c20_i35] = c20_b_BMLM[c20_i35];
    }

    c20_updateDataWrittenToVector(chartInstance, 4U);
    for (c20_i36 = 0; c20_i36 < 256; c20_i36++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i36], 12U);
    }

    chartInstance->c20_rFlag = 1.0;
    c20_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
    c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
    for (c20_i37 = 0; c20_i37 < 1280; c20_i37++) {
      c20_dv9[c20_i37] = c20_get_bmlsM(chartInstance, c20_i37);
    }

    for (c20_i38 = 0; c20_i38 < 256; c20_i38++) {
      c20_dv10[c20_i38] = chartInstance->c20_BMLM[c20_i38];
    }

    c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv9, c20_dv10, c20_dv11);
    for (c20_i39 = 0; c20_i39 < 1280; c20_i39++) {
      chartInstance->c20_newBmlsM[c20_i39] = c20_dv11[c20_i39];
    }

    c20_updateDataWrittenToVector(chartInstance, 5U);
    for (c20_i40 = 0; c20_i40 < 1280; c20_i40++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i40], 13U);
    }

    c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
    for (c20_i41 = 0; c20_i41 < 1280; c20_i41++) {
      c20_set_bmlsM(chartInstance, c20_i41, chartInstance->c20_newBmlsM[c20_i41]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c20_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c20_sfEvent);
}

static void c20_wave(SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 1.0;
  boolean_T c20_c_out;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 0.0;
  real_T c20_f_nargin = 0.0;
  real_T c20_f_nargout = 1.0;
  boolean_T c20_d_out;
  real_T c20_g_nargin = 0.0;
  real_T c20_g_nargout = 1.0;
  boolean_T c20_e_out;
  real_T c20_h_nargin = 0.0;
  real_T c20_h_nargout = 0.0;
  real_T c20_i_nargin = 0.0;
  real_T c20_i_nargout = 1.0;
  boolean_T c20_f_out;
  real_T c20_j_nargin = 0.0;
  real_T c20_j_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i42;
  int32_T c20_i43;
  int32_T c20_i44;
  real_T c20_dv12[1280];
  int32_T c20_i45;
  real_T c20_dv13[256];
  real_T c20_dv14[1280];
  int32_T c20_i46;
  int32_T c20_i47;
  int32_T c20_i48;
  real_T c20_k_nargin = 0.0;
  real_T c20_k_nargout = 1.0;
  boolean_T c20_g_out;
  real_T c20_l_nargin = 0.0;
  real_T c20_l_nargout = 0.0;
  real_T *c20_handUp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c20_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_x_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  guard3 = false;
  if (CV_EML_COND(2, 0, 0, *c20_handUp == 2.0)) {
    if (CV_EML_COND(2, 0, 1, chartInstance->c20_lFlag == 0.0)) {
      CV_EML_MCDC(2, 0, 0, true);
      CV_EML_IF(2, 0, 0, true);
      c20_out = true;
    } else {
      guard3 = true;
    }
  } else {
    c20_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
    guard3 = true;
  }

  if (guard3 == true) {
    CV_EML_MCDC(2, 0, 0, false);
    CV_EML_IF(2, 0, 0, false);
    c20_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_y_debug_family_names,
      c20_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    chartInstance->c20_rFlag = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
    chartInstance->c20_bFlag = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_ab_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    c20_b_out = CV_EML_IF(14, 0, 0, c20_get_avert(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_wave = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_gazeCamera1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_gazeCamera1 = 1U;
      c20_enter_atomic_gazeCamera1(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_wave = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
      chartInstance->c20_isStable = false;
      chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_waveLeftHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_temporalCounter_i1 = 0U;
      chartInstance->c20_tp_waveLeftHand = 1U;
      c20_enter_atomic_waveLeftHand(chartInstance);
    }
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_eb_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U, c20_c_sf_marshallOut,
      c20_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(3, 0, 0, *c20_handUp == 3.0)) {
      if (CV_EML_COND(3, 0, 1, chartInstance->c20_bFlag == 0.0)) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c20_c_out = true;
      } else {
        guard2 = true;
      }
    } else {
      c20_errorIfDataNotWrittenToFcn(chartInstance, 3U, 9U);
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c20_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c20_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_fb_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      chartInstance->c20_rFlag = 0.0;
      c20_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
      chartInstance->c20_lFlag = 0.0;
      c20_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_gb_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U, c20_c_sf_marshallOut,
        c20_c_sf_marshallIn);
      c20_d_out = CV_EML_IF(15, 0, 0, c20_get_avert(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_wave = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
        chartInstance->c20_isStable = false;
        chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_gazeCamera2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
        chartInstance->c20_temporalCounter_i1 = 0U;
        chartInstance->c20_tp_gazeCamera2 = 1U;
        c20_enter_atomic_gazeCamera2(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_wave = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
        chartInstance->c20_isStable = false;
        chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_waveBothHands;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
        chartInstance->c20_temporalCounter_i1 = 0U;
        chartInstance->c20_tp_waveBothHands = 1U;
        c20_enter_atomic_waveBothHands(chartInstance);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_u_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_nargin, 0U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_nargout, 1U,
        c20_b_sf_marshallOut, c20_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_out, 2U, c20_c_sf_marshallOut,
        c20_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(1, 0, 0, *c20_handUp == 1.0)) {
        if (CV_EML_COND(1, 0, 1, chartInstance->c20_rFlag == 0.0)) {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c20_e_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c20_errorIfDataNotWrittenToFcn(chartInstance, 1U, 7U);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c20_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c20_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_v_debug_family_names,
          c20_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h_nargin, 0U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h_nargout, 1U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        chartInstance->c20_lFlag = 0.0;
        c20_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
        chartInstance->c20_bFlag = 0.0;
        c20_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_w_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i_nargin, 0U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i_nargout, 1U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_out, 2U,
          c20_c_sf_marshallOut, c20_c_sf_marshallIn);
        c20_f_out = CV_EML_IF(12, 0, 0, c20_get_avert(chartInstance, 0) == 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_wave = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
          chartInstance->c20_isStable = false;
          chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_gazeCamera;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
          chartInstance->c20_temporalCounter_i1 = 0U;
          chartInstance->c20_tp_gazeCamera = 1U;
          c20_enter_atomic_gazeCamera(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_wave = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
          chartInstance->c20_isStable = false;
          chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_waveRightHand;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
          chartInstance->c20_temporalCounter_i1 = 0U;
          chartInstance->c20_tp_waveRightHand = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_j_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j_nargin, 0U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j_nargout, 1U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 1.0, &c20_P,
            c20_b_BMLM);
          c20_set_P(chartInstance, 0, c20_P);
          ssUpdateDataStoreLog(chartInstance->S, 2);
          for (c20_i42 = 0; c20_i42 < 256; c20_i42++) {
            chartInstance->c20_BMLM[c20_i42] = c20_b_BMLM[c20_i42];
          }

          c20_updateDataWrittenToVector(chartInstance, 4U);
          for (c20_i43 = 0; c20_i43 < 256; c20_i43++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i43], 12U);
          }

          chartInstance->c20_rFlag = 1.0;
          c20_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
          c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
          for (c20_i44 = 0; c20_i44 < 1280; c20_i44++) {
            c20_dv12[c20_i44] = c20_get_bmlsM(chartInstance, c20_i44);
          }

          for (c20_i45 = 0; c20_i45 < 256; c20_i45++) {
            c20_dv13[c20_i45] = chartInstance->c20_BMLM[c20_i45];
          }

          c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv12, c20_dv13,
            c20_dv14);
          for (c20_i46 = 0; c20_i46 < 1280; c20_i46++) {
            chartInstance->c20_newBmlsM[c20_i46] = c20_dv14[c20_i46];
          }

          c20_updateDataWrittenToVector(chartInstance, 5U);
          for (c20_i47 = 0; c20_i47 < 1280; c20_i47++) {
            _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i47], 13U);
          }

          c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
          for (c20_i48 = 0; c20_i48 < 1280; c20_i48++) {
            c20_set_bmlsM(chartInstance, c20_i48, chartInstance->
                          c20_newBmlsM[c20_i48]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 6);
          _SFD_SYMBOL_SCOPE_POP();
        }
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_cb_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_k_nargin, 0U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_k_nargout, 1U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_out, 2U,
          c20_c_sf_marshallOut, c20_c_sf_marshallIn);
        c20_g_out = CV_EML_IF(8, 0, 0, (chartInstance->c20_sfEvent ==
          c20_event_secs) && (chartInstance->c20_temporalCounter_i1 >= 70));
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_db_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_l_nargin, 0U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_l_nargout, 1U,
            c20_b_sf_marshallOut, c20_b_sf_marshallIn);
          chartInstance->c20_rFlag = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_rFlag, 7U);
          chartInstance->c20_lFlag = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
          chartInstance->c20_bFlag = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c20_tp_wave = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
          chartInstance->c20_isStable = false;
          chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_wave;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
          chartInstance->c20_temporalCounter_i1 = 0U;
          chartInstance->c20_tp_wave = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       chartInstance->c20_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c20_sfEvent);
}

static void c20_enter_atomic_gazeCamera1(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i49;
  int32_T c20_i50;
  int32_T c20_i51;
  real_T c20_dv15[1280];
  int32_T c20_i52;
  real_T c20_dv16[256];
  real_T c20_dv17[1280];
  int32_T c20_i53;
  int32_T c20_i54;
  int32_T c20_i55;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_l_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 6.0, &c20_P, c20_b_BMLM);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i49 = 0; c20_i49 < 256; c20_i49++) {
    chartInstance->c20_BMLM[c20_i49] = c20_b_BMLM[c20_i49];
  }

  c20_updateDataWrittenToVector(chartInstance, 4U);
  for (c20_i50 = 0; c20_i50 < 256; c20_i50++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i50], 12U);
  }

  c20_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
  for (c20_i51 = 0; c20_i51 < 1280; c20_i51++) {
    c20_dv15[c20_i51] = c20_get_bmlsM(chartInstance, c20_i51);
  }

  for (c20_i52 = 0; c20_i52 < 256; c20_i52++) {
    c20_dv16[c20_i52] = chartInstance->c20_BMLM[c20_i52];
  }

  c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv15, c20_dv16, c20_dv17);
  for (c20_i53 = 0; c20_i53 < 1280; c20_i53++) {
    chartInstance->c20_newBmlsM[c20_i53] = c20_dv17[c20_i53];
  }

  c20_updateDataWrittenToVector(chartInstance, 5U);
  for (c20_i54 = 0; c20_i54 < 1280; c20_i54++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i54], 13U);
  }

  c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
  for (c20_i55 = 0; c20_i55 < 1280; c20_i55++) {
    c20_set_bmlsM(chartInstance, c20_i55, chartInstance->c20_newBmlsM[c20_i55]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_gazeCamera1(SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i56;
  int32_T c20_i57;
  int32_T c20_i58;
  real_T c20_dv18[1280];
  int32_T c20_i59;
  real_T c20_dv19[256];
  real_T c20_dv20[1280];
  int32_T c20_i60;
  int32_T c20_i61;
  int32_T c20_i62;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_bb_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  c20_out = CV_EML_IF(10, 0, 0, (chartInstance->c20_sfEvent == c20_event_secs) &&
                      (chartInstance->c20_temporalCounter_i1 >= 4));
  _SFD_SYMBOL_SCOPE_POP();
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_gazeCamera1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    chartInstance->c20_isStable = false;
    chartInstance->c20_is_c20_DemoIdle_PEC = c20_IN_waveLeftHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
    chartInstance->c20_temporalCounter_i1 = 0U;
    chartInstance->c20_tp_waveLeftHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_m_debug_family_names,
      c20_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_b_sf_marshallOut,
      c20_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
      c20_b_sf_marshallOut, c20_b_sf_marshallIn);
    c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 2.0, &c20_P, c20_b_BMLM);
    c20_set_P(chartInstance, 0, c20_P);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    for (c20_i56 = 0; c20_i56 < 256; c20_i56++) {
      chartInstance->c20_BMLM[c20_i56] = c20_b_BMLM[c20_i56];
    }

    c20_updateDataWrittenToVector(chartInstance, 4U);
    for (c20_i57 = 0; c20_i57 < 256; c20_i57++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i57], 12U);
    }

    chartInstance->c20_lFlag = 1.0;
    c20_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
    c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
    for (c20_i58 = 0; c20_i58 < 1280; c20_i58++) {
      c20_dv18[c20_i58] = c20_get_bmlsM(chartInstance, c20_i58);
    }

    for (c20_i59 = 0; c20_i59 < 256; c20_i59++) {
      c20_dv19[c20_i59] = chartInstance->c20_BMLM[c20_i59];
    }

    c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv18, c20_dv19, c20_dv20);
    for (c20_i60 = 0; c20_i60 < 1280; c20_i60++) {
      chartInstance->c20_newBmlsM[c20_i60] = c20_dv20[c20_i60];
    }

    c20_updateDataWrittenToVector(chartInstance, 5U);
    for (c20_i61 = 0; c20_i61 < 1280; c20_i61++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i61], 13U);
    }

    c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
    for (c20_i62 = 0; c20_i62 < 1280; c20_i62++) {
      c20_set_bmlsM(chartInstance, c20_i62, chartInstance->c20_newBmlsM[c20_i62]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c20_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c20_sfEvent);
}

static void c20_enter_atomic_waveLeftHand(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i63;
  int32_T c20_i64;
  int32_T c20_i65;
  real_T c20_dv21[1280];
  int32_T c20_i66;
  real_T c20_dv22[256];
  real_T c20_dv23[1280];
  int32_T c20_i67;
  int32_T c20_i68;
  int32_T c20_i69;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_m_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 2.0, &c20_P, c20_b_BMLM);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i63 = 0; c20_i63 < 256; c20_i63++) {
    chartInstance->c20_BMLM[c20_i63] = c20_b_BMLM[c20_i63];
  }

  c20_updateDataWrittenToVector(chartInstance, 4U);
  for (c20_i64 = 0; c20_i64 < 256; c20_i64++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i64], 12U);
  }

  chartInstance->c20_lFlag = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_lFlag, 8U);
  c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
  for (c20_i65 = 0; c20_i65 < 1280; c20_i65++) {
    c20_dv21[c20_i65] = c20_get_bmlsM(chartInstance, c20_i65);
  }

  for (c20_i66 = 0; c20_i66 < 256; c20_i66++) {
    c20_dv22[c20_i66] = chartInstance->c20_BMLM[c20_i66];
  }

  c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv21, c20_dv22, c20_dv23);
  for (c20_i67 = 0; c20_i67 < 1280; c20_i67++) {
    chartInstance->c20_newBmlsM[c20_i67] = c20_dv23[c20_i67];
  }

  c20_updateDataWrittenToVector(chartInstance, 5U);
  for (c20_i68 = 0; c20_i68 < 1280; c20_i68++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i68], 13U);
  }

  c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
  for (c20_i69 = 0; c20_i69 < 1280; c20_i69++) {
    c20_set_bmlsM(chartInstance, c20_i69, chartInstance->c20_newBmlsM[c20_i69]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_enter_atomic_waveBothHands(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i70;
  int32_T c20_i71;
  int32_T c20_i72;
  real_T c20_dv24[1280];
  int32_T c20_i73;
  real_T c20_dv25[256];
  real_T c20_dv26[1280];
  int32_T c20_i74;
  int32_T c20_i75;
  int32_T c20_i76;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_n_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 3.0, &c20_P, c20_b_BMLM);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i70 = 0; c20_i70 < 256; c20_i70++) {
    chartInstance->c20_BMLM[c20_i70] = c20_b_BMLM[c20_i70];
  }

  c20_updateDataWrittenToVector(chartInstance, 4U);
  for (c20_i71 = 0; c20_i71 < 256; c20_i71++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i71], 12U);
  }

  chartInstance->c20_bFlag = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_bFlag, 9U);
  c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
  for (c20_i72 = 0; c20_i72 < 1280; c20_i72++) {
    c20_dv24[c20_i72] = c20_get_bmlsM(chartInstance, c20_i72);
  }

  for (c20_i73 = 0; c20_i73 < 256; c20_i73++) {
    c20_dv25[c20_i73] = chartInstance->c20_BMLM[c20_i73];
  }

  c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv24, c20_dv25, c20_dv26);
  for (c20_i74 = 0; c20_i74 < 1280; c20_i74++) {
    chartInstance->c20_newBmlsM[c20_i74] = c20_dv26[c20_i74];
  }

  c20_updateDataWrittenToVector(chartInstance, 5U);
  for (c20_i75 = 0; c20_i75 < 1280; c20_i75++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i75], 13U);
  }

  c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
  for (c20_i76 = 0; c20_i76 < 1280; c20_i76++) {
    c20_set_bmlsM(chartInstance, c20_i76, chartInstance->c20_newBmlsM[c20_i76]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_enter_atomic_gazeCamera2(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  real_T c20_b_BMLM[256];
  real_T c20_P;
  int32_T c20_i77;
  int32_T c20_i78;
  int32_T c20_i79;
  real_T c20_dv27[1280];
  int32_T c20_i80;
  real_T c20_dv28[256];
  real_T c20_dv29[1280];
  int32_T c20_i81;
  int32_T c20_i82;
  int32_T c20_i83;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_o_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, 6.0, &c20_P, c20_b_BMLM);
  c20_set_P(chartInstance, 0, c20_P);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  for (c20_i77 = 0; c20_i77 < 256; c20_i77++) {
    chartInstance->c20_BMLM[c20_i77] = c20_b_BMLM[c20_i77];
  }

  c20_updateDataWrittenToVector(chartInstance, 4U);
  for (c20_i78 = 0; c20_i78 < 256; c20_i78++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_BMLM[c20_i78], 12U);
  }

  c20_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c20_errorIfDataNotWrittenToFcn(chartInstance, 4U, 12U);
  for (c20_i79 = 0; c20_i79 < 1280; c20_i79++) {
    c20_dv27[c20_i79] = c20_get_bmlsM(chartInstance, c20_i79);
  }

  for (c20_i80 = 0; c20_i80 < 256; c20_i80++) {
    c20_dv28[c20_i80] = chartInstance->c20_BMLM[c20_i80];
  }

  c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_dv27, c20_dv28, c20_dv29);
  for (c20_i81 = 0; c20_i81 < 1280; c20_i81++) {
    chartInstance->c20_newBmlsM[c20_i81] = c20_dv29[c20_i81];
  }

  c20_updateDataWrittenToVector(chartInstance, 5U);
  for (c20_i82 = 0; c20_i82 < 1280; c20_i82++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_newBmlsM[c20_i82], 13U);
  }

  c20_errorIfDataNotWrittenToFcn(chartInstance, 5U, 13U);
  for (c20_i83 = 0; c20_i83 < 1280; c20_i83++) {
    c20_set_bmlsM(chartInstance, c20_i83, chartInstance->c20_newBmlsM[c20_i83]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[110];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[110];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i84;
  static char_T c20_cv0[110] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a',
    't', 'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't',
    '_', 'w', 'a', 'v', 'e', '_', 'l', 'e', 'f', 't', '.', 's', 'k', 'm', '\"',
    ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '0', '.', '5', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c20_i85;
  static real_T c20_dv30[110] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 119.0, 97.0, 118.0, 101.0, 95.0, 108.0, 101.0,
    102.0, 116.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0, 101.0,
    101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c20_i86;
  int32_T c20_i87;
  int32_T c20_i88;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_b_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i84 = 0; c20_i84 < 110; c20_i84++) {
    c20_mystr[c20_i84] = c20_cv0[c20_i84];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i85 = 0; c20_i85 < 110; c20_i85++) {
    c20_arr[c20_i85] = c20_dv30[c20_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 110.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i86 = 0; c20_i86 < 256; c20_i86++) {
    c20_tt[c20_i86] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i87 = 0; c20_i87 < 110; c20_i87++) {
    c20_tt[c20_i87] = c20_arr[c20_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i88 = 0; c20_i88 < 256; c20_i88++) {
    c20_myarr256[c20_i88] = c20_tt[c20_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_b_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[111];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[111];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i89;
  static char_T c20_cv1[111] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a',
    't', 'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't',
    '_', 'w', 'a', 'v', 'e', '_', 'r', 'i', 'g', 'h', 't', '.', 's', 'k', 'm',
    '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '0', '.', '5', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c20_i90;
  static real_T c20_dv31[111] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 119.0, 97.0, 118.0, 101.0, 95.0, 114.0, 105.0,
    103.0, 104.0, 116.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c20_i91;
  int32_T c20_i92;
  int32_T c20_i93;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_c_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i89 = 0; c20_i89 < 111; c20_i89++) {
    c20_mystr[c20_i89] = c20_cv1[c20_i89];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i90 = 0; c20_i90 < 111; c20_i90++) {
    c20_arr[c20_i90] = c20_dv31[c20_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i91 = 0; c20_i91 < 256; c20_i91++) {
    c20_tt[c20_i91] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i92 = 0; c20_i92 < 111; c20_i92++) {
    c20_tt[c20_i92] = c20_arr[c20_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i93 = 0; c20_i93 < 256; c20_i93++) {
    c20_myarr256[c20_i93] = c20_tt[c20_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_c_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[103];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[103];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i94;
  static char_T c20_cv2[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'H',
    'i', 'g', 'h', 'B', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '0', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c20_i95;
  static real_T c20_dv32[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 72.0, 105.0, 103.0, 104.0, 66.0, 116.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c20_i96;
  int32_T c20_i97;
  int32_T c20_i98;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_d_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i94 = 0; c20_i94 < 103; c20_i94++) {
    c20_mystr[c20_i94] = c20_cv2[c20_i94];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i95 = 0; c20_i95 < 103; c20_i95++) {
    c20_arr[c20_i95] = c20_dv32[c20_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i96 = 0; c20_i96 < 256; c20_i96++) {
    c20_tt[c20_i96] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i97 = 0; c20_i97 < 103; c20_i97++) {
    c20_tt[c20_i97] = c20_arr[c20_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i98 = 0; c20_i98 < 256; c20_i98++) {
    c20_myarr256[c20_i98] = c20_tt[c20_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_d_encStr2Arr(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  real_T c20_myarr256[256])
{
  uint32_T c20_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[91];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[91];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i99;
  static char_T c20_cv3[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'H', 'i',
    'g', 'h', 'R', 't', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c20_i100;
  static real_T c20_dv33[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 72.0, 105.0, 103.0, 104.0, 82.0, 116.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c20_i101;
  int32_T c20_i102;
  int32_T c20_i103;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_e_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  for (c20_i99 = 0; c20_i99 < 91; c20_i99++) {
    c20_mystr[c20_i99] = c20_cv3[c20_i99];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
  for (c20_i100 = 0; c20_i100 < 91; c20_i100++) {
    c20_arr[c20_i100] = c20_dv33[c20_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_padsize = c20_maxarrsize - c20_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
  for (c20_i101 = 0; c20_i101 < 256; c20_i101++) {
    c20_tt[c20_i101] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
  for (c20_i102 = 0; c20_i102 < 91; c20_i102++) {
    c20_tt[c20_i102] = c20_arr[c20_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i103 = 0; c20_i103 < 256; c20_i103++) {
    c20_myarr256[c20_i103] = c20_tt[c20_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, c20_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\5-10-2015-Matlab-Demo-v2\\encStr2Arr.m"));
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i104;
  real_T c20_b_inData[256];
  int32_T c20_i105;
  real_T c20_u[256];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i104 = 0; c20_i104 < 256; c20_i104++) {
    c20_b_inData[c20_i104] = (*(real_T (*)[256])c20_inData)[c20_i104];
  }

  for (c20_i105 = 0; c20_i105 < 256; c20_i105++) {
    c20_u[c20_i105] = c20_b_inData[c20_i105];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  const mxArray *c20_poseBML, const char_T *c20_identifier, real_T c20_y[256])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_poseBML), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_poseBML);
}

static void c20_b_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256])
{
  real_T c20_dv34[256];
  int32_T c20_i106;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv34, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c20_i106 = 0; c20_i106 < 256; c20_i106++) {
    c20_y[c20_i106] = c20_dv34[c20_i106];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_poseBML;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[256];
  int32_T c20_i107;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_poseBML = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_poseBML), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_poseBML);
  for (c20_i107 = 0; c20_i107 < 256; c20_i107++) {
    (*(real_T (*)[256])c20_outData)[c20_i107] = c20_y[c20_i107];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_c_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_pr, const char_T *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_pr), &c20_thisId);
  sf_mex_destroy(&c20_pr);
  return c20_y;
}

static real_T c20_d_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_pr;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_pr = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_pr), &c20_thisId);
  sf_mex_destroy(&c20_pr);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  boolean_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(boolean_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static boolean_T c20_e_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  boolean_T c20_y;
  boolean_T c20_b0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_b0, 1, 11, 0U, 0, 0U, 0);
  c20_y = c20_b0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_aVarTruthTableCondition_6;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  boolean_T c20_y;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_aVarTruthTableCondition_6 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_aVarTruthTableCondition_6), &c20_thisId);
  sf_mex_destroy(&c20_aVarTruthTableCondition_6);
  *(boolean_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i108;
  real_T c20_b_inData[256];
  int32_T c20_i109;
  real_T c20_u[256];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i108 = 0; c20_i108 < 256; c20_i108++) {
    c20_b_inData[c20_i108] = (*(real_T (*)[256])c20_inData)[c20_i108];
  }

  for (c20_i109 = 0; c20_i109 < 256; c20_i109++) {
    c20_u[c20_i109] = c20_b_inData[c20_i109];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_f_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_myarr256, const char_T *c20_identifier,
  real_T c20_y[256])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_myarr256), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_myarr256);
}

static void c20_g_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[256])
{
  real_T c20_dv35[256];
  int32_T c20_i110;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv35, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c20_i110 = 0; c20_i110 < 256; c20_i110++) {
    c20_y[c20_i110] = c20_dv35[c20_i110];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_myarr256;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[256];
  int32_T c20_i111;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_myarr256 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_myarr256), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_myarr256);
  for (c20_i111 = 0; c20_i111 < 256; c20_i111++) {
    (*(real_T (*)[256])c20_outData)[c20_i111] = c20_y[c20_i111];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i112;
  char_T c20_b_inData[110];
  int32_T c20_i113;
  char_T c20_u[110];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i112 = 0; c20_i112 < 110; c20_i112++) {
    c20_b_inData[c20_i112] = (*(char_T (*)[110])c20_inData)[c20_i112];
  }

  for (c20_i113 = 0; c20_i113 < 110; c20_i113++) {
    c20_u[c20_i113] = c20_b_inData[c20_i113];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 110),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i114;
  real_T c20_b_inData[110];
  int32_T c20_i115;
  real_T c20_u[110];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i114 = 0; c20_i114 < 110; c20_i114++) {
    c20_b_inData[c20_i114] = (*(real_T (*)[110])c20_inData)[c20_i114];
  }

  for (c20_i115 = 0; c20_i115 < 110; c20_i115++) {
    c20_u[c20_i115] = c20_b_inData[c20_i115];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 110), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i116;
  char_T c20_b_inData[111];
  int32_T c20_i117;
  char_T c20_u[111];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i116 = 0; c20_i116 < 111; c20_i116++) {
    c20_b_inData[c20_i116] = (*(char_T (*)[111])c20_inData)[c20_i116];
  }

  for (c20_i117 = 0; c20_i117 < 111; c20_i117++) {
    c20_u[c20_i117] = c20_b_inData[c20_i117];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 111),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_h_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i118;
  real_T c20_b_inData[111];
  int32_T c20_i119;
  real_T c20_u[111];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i118 = 0; c20_i118 < 111; c20_i118++) {
    c20_b_inData[c20_i118] = (*(real_T (*)[111])c20_inData)[c20_i118];
  }

  for (c20_i119 = 0; c20_i119 < 111; c20_i119++) {
    c20_u[c20_i119] = c20_b_inData[c20_i119];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 111), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_i_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i120;
  char_T c20_b_inData[103];
  int32_T c20_i121;
  char_T c20_u[103];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i120 = 0; c20_i120 < 103; c20_i120++) {
    c20_b_inData[c20_i120] = (*(char_T (*)[103])c20_inData)[c20_i120];
  }

  for (c20_i121 = 0; c20_i121 < 103; c20_i121++) {
    c20_u[c20_i121] = c20_b_inData[c20_i121];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_j_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i122;
  real_T c20_b_inData[103];
  int32_T c20_i123;
  real_T c20_u[103];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i122 = 0; c20_i122 < 103; c20_i122++) {
    c20_b_inData[c20_i122] = (*(real_T (*)[103])c20_inData)[c20_i122];
  }

  for (c20_i123 = 0; c20_i123 < 103; c20_i123++) {
    c20_u[c20_i123] = c20_b_inData[c20_i123];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 103), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_k_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i124;
  char_T c20_b_inData[91];
  int32_T c20_i125;
  char_T c20_u[91];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i124 = 0; c20_i124 < 91; c20_i124++) {
    c20_b_inData[c20_i124] = (*(char_T (*)[91])c20_inData)[c20_i124];
  }

  for (c20_i125 = 0; c20_i125 < 91; c20_i125++) {
    c20_u[c20_i125] = c20_b_inData[c20_i125];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 91),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_l_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i126;
  real_T c20_b_inData[91];
  int32_T c20_i127;
  real_T c20_u[91];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i126 = 0; c20_i126 < 91; c20_i126++) {
    c20_b_inData[c20_i126] = (*(real_T (*)[91])c20_inData)[c20_i126];
  }

  for (c20_i127 = 0; c20_i127 < 91; c20_i127++) {
    c20_u[c20_i127] = c20_b_inData[c20_i127];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_m_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i128;
  char_T c20_b_inData[115];
  int32_T c20_i129;
  char_T c20_u[115];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i128 = 0; c20_i128 < 115; c20_i128++) {
    c20_b_inData[c20_i128] = (*(char_T (*)[115])c20_inData)[c20_i128];
  }

  for (c20_i129 = 0; c20_i129 < 115; c20_i129++) {
    c20_u[c20_i129] = c20_b_inData[c20_i129];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_n_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i130;
  real_T c20_b_inData[115];
  int32_T c20_i131;
  real_T c20_u[115];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i130 = 0; c20_i130 < 115; c20_i130++) {
    c20_b_inData[c20_i130] = (*(real_T (*)[115])c20_inData)[c20_i130];
  }

  for (c20_i131 = 0; c20_i131 < 115; c20_i131++) {
    c20_u[c20_i131] = c20_b_inData[c20_i131];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_o_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i132;
  int32_T c20_i133;
  int32_T c20_i134;
  real_T c20_b_inData[1280];
  int32_T c20_i135;
  int32_T c20_i136;
  int32_T c20_i137;
  real_T c20_u[1280];
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i132 = 0;
  for (c20_i133 = 0; c20_i133 < 5; c20_i133++) {
    for (c20_i134 = 0; c20_i134 < 256; c20_i134++) {
      c20_b_inData[c20_i134 + c20_i132] = (*(real_T (*)[1280])c20_inData)
        [c20_i134 + c20_i132];
    }

    c20_i132 += 256;
  }

  c20_i135 = 0;
  for (c20_i136 = 0; c20_i136 < 5; c20_i136++) {
    for (c20_i137 = 0; c20_i137 < 256; c20_i137++) {
      c20_u[c20_i137 + c20_i135] = c20_b_inData[c20_i137 + c20_i135];
    }

    c20_i135 += 256;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_h_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_newBmls, const char_T *c20_identifier,
  real_T c20_y[1280])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_newBmls), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_newBmls);
}

static void c20_i_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[1280])
{
  real_T c20_dv36[1280];
  int32_T c20_i138;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv36, 1, 0, 0U, 1, 0U, 2,
                256, 5);
  for (c20_i138 = 0; c20_i138 < 1280; c20_i138++) {
    c20_y[c20_i138] = c20_dv36[c20_i138];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_newBmls;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[1280];
  int32_T c20_i139;
  int32_T c20_i140;
  int32_T c20_i141;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_newBmls = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_newBmls), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_newBmls);
  c20_i139 = 0;
  for (c20_i140 = 0; c20_i140 < 5; c20_i140++) {
    for (c20_i141 = 0; c20_i141 < 256; c20_i141++) {
      (*(real_T (*)[1280])c20_outData)[c20_i141 + c20_i139] = c20_y[c20_i141 +
        c20_i139];
    }

    c20_i139 += 256;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_p_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  char_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(char_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

const mxArray *sf_c20_DemoIdle_PEC_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  const mxArray *c20_rhs3 = NULL;
  const mxArray *c20_lhs3 = NULL;
  const mxArray *c20_rhs4 = NULL;
  const mxArray *c20_lhs4 = NULL;
  const mxArray *c20_rhs5 = NULL;
  const mxArray *c20_lhs5 = NULL;
  const mxArray *c20_rhs6 = NULL;
  const mxArray *c20_lhs6 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/5-10-2015-Matlab-Demo-v2/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c20_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c20_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("disp"), "name", "name", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 5);
  sf_mex_assign(&c20_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("disp"), "name", "name", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 6);
  sf_mex_assign(&c20_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
  sf_mex_destroy(&c20_rhs3);
  sf_mex_destroy(&c20_lhs3);
  sf_mex_destroy(&c20_rhs4);
  sf_mex_destroy(&c20_lhs4);
  sf_mex_destroy(&c20_rhs5);
  sf_mex_destroy(&c20_lhs5);
  sf_mex_destroy(&c20_rhs6);
  sf_mex_destroy(&c20_lhs6);
}

static const mxArray *c20_emlrt_marshallOut(const char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), false);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), false);
  return c20_y;
}

static void c20_activate_secsc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  chartInstance->c20_sfEvent = c20_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c20_event_secs,
               chartInstance->c20_sfEvent);
}

static void c20_deactivate_secsc20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c20_event_secs,
               chartInstance->c20_sfEvent);
}

static void c20_increment_counters_secsc20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  if (chartInstance->c20_temporalCounter_i1 < 127U) {
    chartInstance->c20_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c20_temporalCounter_i1 + 1);
  }
}

static void c20_reset_counters_secsc20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c20_DemoIdle_PEC_secs(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_activate_secsc20_DemoIdle_PEC(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c20_DemoIdle_PEC_secs(SimStruct
  *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_increment_counters_secsc20_DemoIdle_PEC(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c20_DemoIdle_PEC_secs(SimStruct
  *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_reset_counters_secsc20_DemoIdle_PEC(chartInstance);
}

void sf_exported_auto_deactivate_c20_DemoIdle_PEC_secs(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_deactivate_secsc20_DemoIdle_PEC(chartInstance);
}

boolean_T sf_exported_auto_isStablec20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  return chartInstance->c20_isStable;
}

void sf_exported_auto_duringc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_c20_DemoIdle_PEC(chartInstance);
}

void sf_exported_auto_enterc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c20_enter_atomic_c20_DemoIdle_PEC(chartInstance);
  c20_enter_internal_c20_DemoIdle_PEC(chartInstance);
}

void sf_exported_auto_exitc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c20_exit_internal_c20_DemoIdle_PEC(chartInstance);
}

void sf_exported_auto_gatewayc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  chartInstance->c20_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc20_DemoIdle_PEC(SimStruct *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_initc20_DemoIdle_PEC(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec20_DemoIdle_PEC(SimStruct *c20_S)
{
  const mxArray *c20_out = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_out = NULL;
  sf_mex_assign(&c20_out, sf_internal_get_sim_state_c20_DemoIdle_PEC(c20_S),
                false);
  return c20_out;
}

void sf_exported_auto_setSimstatec20_DemoIdle_PEC(SimStruct *c20_S, const
  mxArray *c20_in)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c20_DemoIdle_PEC(c20_S, sf_mex_dup(c20_in));
  sf_mex_destroy(&c20_in);
}

void sf_exported_auto_check_state_inconsistency_c20_DemoIdle_PEC(SimStruct
  *c20_S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DemoIdle_PECMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c20_wavePoseBradTablec20_DemoIdle_PEC
  (SFc20_DemoIdle_PECInstanceStruct *chartInstance, real_T c20_bmlID, real_T
   *c20_pr, real_T c20_poseBML[256])
{
  uint32_T c20_debug_family_var_map[11];
  boolean_T c20_aVarTruthTableCondition_1;
  boolean_T c20_aVarTruthTableCondition_2;
  boolean_T c20_aVarTruthTableCondition_3;
  boolean_T c20_aVarTruthTableCondition_4;
  boolean_T c20_aVarTruthTableCondition_5;
  boolean_T c20_aVarTruthTableCondition_6;
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 2.0;
  real_T c20_dv37[256];
  int32_T c20_i142;
  int32_T c20_i143;
  int32_T c20_i144;
  int32_T c20_i145;
  int32_T c20_i146;
  uint32_T c20_b_debug_family_var_map[9];
  real_T c20_maxarrsize;
  real_T c20_arr[115];
  real_T c20_ss;
  real_T c20_padsize;
  real_T c20_tt[256];
  char_T c20_mystr[115];
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_myarr256[256];
  int32_T c20_i147;
  static char_T c20_cv4[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c20_i148;
  static real_T c20_dv38[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c20_i149;
  int32_T c20_i150;
  int32_T c20_i151;
  int32_T c20_i152;
  int32_T c20_i153;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_1, 0U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_2, 1U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_3, 2U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_4, 3U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_5, 4U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_aVarTruthTableCondition_6, 5U,
    c20_c_sf_marshallOut, c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 6U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 7U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_bmlID, 8U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_pr, 9U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_poseBML, 10U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(8, 0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 3);
  c20_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 4);
  c20_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 5);
  c20_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 6);
  c20_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 7);
  c20_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 8);
  c20_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 12);
  c20_aVarTruthTableCondition_1 = (c20_bmlID == 1.0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 15);
  c20_aVarTruthTableCondition_2 = (c20_bmlID == 2.0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 18);
  c20_aVarTruthTableCondition_3 = (c20_bmlID == 3.0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 21);
  c20_aVarTruthTableCondition_4 = (c20_bmlID == 4.0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 24);
  c20_aVarTruthTableCondition_5 = (c20_bmlID == 5.0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 27);
  c20_aVarTruthTableCondition_6 = (c20_bmlID == 6.0);
  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 29);
  if (CV_EML_IF(8, 1, 0, c20_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 30);
    CV_EML_FCN(8, 1);
    _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 49);
    c20_encStr2Arr(chartInstance, c20_dv37);
    for (c20_i142 = 0; c20_i142 < 256; c20_i142++) {
      c20_poseBML[c20_i142] = c20_dv37[c20_i142];
    }

    c20_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 49);
    *c20_pr = 2.0;
    c20_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -49);
  } else {
    _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 31);
    if (CV_EML_IF(8, 1, 1, c20_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 32);
      CV_EML_FCN(8, 2);
      _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 55);
      c20_b_encStr2Arr(chartInstance, c20_dv37);
      for (c20_i143 = 0; c20_i143 < 256; c20_i143++) {
        c20_poseBML[c20_i143] = c20_dv37[c20_i143];
      }

      c20_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 55);
      *c20_pr = 2.0;
      c20_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -55);
    } else {
      _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 33);
      if (CV_EML_IF(8, 1, 2, c20_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 34);
        CV_EML_FCN(8, 3);
        _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 61);
        c20_c_encStr2Arr(chartInstance, c20_dv37);
        for (c20_i144 = 0; c20_i144 < 256; c20_i144++) {
          c20_poseBML[c20_i144] = c20_dv37[c20_i144];
        }

        c20_updateDataWrittenToVector(chartInstance, 8U);
        _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 61);
        *c20_pr = 2.0;
        c20_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -61);
      } else {
        _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 35);
        if (CV_EML_IF(8, 1, 3, c20_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 36);
          CV_EML_FCN(8, 4);
          _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 67);
          c20_d_encStr2Arr(chartInstance, c20_dv37);
          for (c20_i145 = 0; c20_i145 < 256; c20_i145++) {
            c20_poseBML[c20_i145] = c20_dv37[c20_i145];
          }

          c20_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 67);
          *c20_pr = 2.0;
          c20_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -67);
        } else {
          _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 37);
          if (CV_EML_IF(8, 1, 4, c20_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 38);
            CV_EML_FCN(8, 5);
            _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 73);
            c20_d_encStr2Arr(chartInstance, c20_dv37);
            for (c20_i146 = 0; c20_i146 < 256; c20_i146++) {
              c20_poseBML[c20_i146] = c20_dv37[c20_i146];
            }

            c20_updateDataWrittenToVector(chartInstance, 8U);
            _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 73);
            *c20_pr = 2.0;
            c20_updateDataWrittenToVector(chartInstance, 7U);
            _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -73);
          } else {
            _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 39);
            if (CV_EML_IF(8, 1, 5, c20_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 40);
              CV_EML_FCN(8, 6);
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 79);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_f_debug_family_names,
                c20_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_maxarrsize, 0U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML(c20_arr, 1U, c20_n_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML(&c20_ss, 2U, c20_b_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_padsize, 3U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_tt, 4U,
                c20_d_sf_marshallOut, c20_d_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML(c20_mystr, 5U, c20_m_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 6U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 7U,
                c20_b_sf_marshallOut, c20_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_myarr256, 8U,
                c20_d_sf_marshallOut, c20_d_sf_marshallIn);
              for (c20_i147 = 0; c20_i147 < 115; c20_i147++) {
                c20_mystr[c20_i147] = c20_cv4[c20_i147];
              }

              CV_SCRIPT_FCN(0, 0);
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 3);
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 4);
              c20_maxarrsize = 256.0;
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 6);
              for (c20_i148 = 0; c20_i148 < 115; c20_i148++) {
                c20_arr[c20_i148] = c20_dv38[c20_i148];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 7);
              c20_ss = 115.0;
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 8);
              c20_padsize = c20_maxarrsize - c20_ss;
              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 9);
              for (c20_i149 = 0; c20_i149 < 256; c20_i149++) {
                c20_tt[c20_i149] = 0.0;
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 10);
              for (c20_i150 = 0; c20_i150 < 115; c20_i150++) {
                c20_tt[c20_i150] = c20_arr[c20_i150];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, 11);
              for (c20_i151 = 0; c20_i151 < 256; c20_i151++) {
                c20_myarr256[c20_i151] = c20_tt[c20_i151];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c20_sfEvent, -11);
              _SFD_SYMBOL_SCOPE_POP();
              for (c20_i152 = 0; c20_i152 < 256; c20_i152++) {
                c20_poseBML[c20_i152] = c20_myarr256[c20_i152];
              }

              c20_updateDataWrittenToVector(chartInstance, 8U);
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 79);
              *c20_pr = 2.0;
              c20_updateDataWrittenToVector(chartInstance, 7U);
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -79);
            } else {
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 42);
              CV_EML_FCN(8, 1);
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 49);
              c20_encStr2Arr(chartInstance, c20_dv37);
              for (c20_i153 = 0; c20_i153 < 256; c20_i153++) {
                c20_poseBML[c20_i153] = c20_dv37[c20_i153];
              }

              c20_updateDataWrittenToVector(chartInstance, 8U);
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, 49);
              *c20_pr = 2.0;
              c20_updateDataWrittenToVector(chartInstance, 7U);
              _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -49);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(8U, chartInstance->c20_sfEvent, -42);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_insertQueuec20_DemoIdle_PEC(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, real_T c20_bmls[1280], real_T c20_mBML[256], real_T
  c20_newBmls[1280])
{
  uint32_T c20_debug_family_var_map[8];
  real_T c20_full;
  real_T c20_t[256];
  real_T c20_i;
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i154;
  static real_T c20_varargin_2[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c20_i155;
  int32_T c20_i156;
  int32_T c20_i157;
  int32_T c20_i158;
  int32_T c20_i159;
  int32_T c20_b_i;
  int32_T c20_c_i;
  int32_T c20_i160;
  real_T c20_varargin_1[256];
  boolean_T c20_p;
  boolean_T c20_b_p;
  int32_T c20_k;
  real_T c20_b_k;
  real_T c20_x1;
  real_T c20_x2;
  boolean_T c20_c_p;
  int32_T c20_d_i;
  int32_T c20_i161;
  int32_T c20_i162;
  static char_T c20_cv5[20] = { 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'a', 'd', 'd',
    ' ', 'w', 'h', 'e', 'n', ' ', 'f', 'u', 'l', 'l' };

  char_T c20_u[20];
  const mxArray *c20_y = NULL;
  int32_T c20_i163;
  real_T c20_b_u[1280];
  const mxArray *c20_b_y = NULL;
  int32_T c20_i164;
  real_T c20_b_bmls[256];
  int32_T c20_i165;
  int32_T c20_i166;
  real_T c20_c_bmls[256];
  int32_T c20_i167;
  int32_T c20_i168;
  real_T c20_d_bmls[256];
  int32_T c20_i169;
  int32_T c20_i170;
  int32_T c20_i171;
  int32_T exitg1;
  boolean_T exitg2;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c20_g_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_full, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_t, 1U, c20_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i, 2U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 3U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 4U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_bmls, 5U, c20_o_sf_marshallOut,
    c20_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_mBML, 6U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_newBmls, 7U, c20_o_sf_marshallOut,
    c20_e_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 2);
  c20_full = 1.0;
  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 3);
  for (c20_i154 = 0; c20_i154 < 256; c20_i154++) {
    c20_t[c20_i154] = c20_varargin_2[c20_i154];
  }

  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 4);
  for (c20_i155 = 0; c20_i155 < 256; c20_i155++) {
    c20_newBmls[c20_i155] = c20_t[c20_i155];
  }

  for (c20_i156 = 0; c20_i156 < 256; c20_i156++) {
    c20_newBmls[c20_i156 + 256] = c20_t[c20_i156];
  }

  for (c20_i157 = 0; c20_i157 < 256; c20_i157++) {
    c20_newBmls[c20_i157 + 512] = c20_t[c20_i157];
  }

  for (c20_i158 = 0; c20_i158 < 256; c20_i158++) {
    c20_newBmls[c20_i158 + 768] = c20_t[c20_i158];
  }

  for (c20_i159 = 0; c20_i159 < 256; c20_i159++) {
    c20_newBmls[c20_i159 + 1024] = c20_t[c20_i159];
  }

  c20_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 5);
  c20_i = 1.0;
  c20_b_i = 0;
  do {
    exitg1 = 0;
    if (c20_b_i < 5) {
      c20_i = 1.0 + (real_T)c20_b_i;
      CV_EML_FOR(4, 1, 0, 1);
      _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 6);
      c20_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c20_i), 1, 5, 2, 0) - 1;
      for (c20_i160 = 0; c20_i160 < 256; c20_i160++) {
        c20_varargin_1[c20_i160] = c20_bmls[c20_i160 + (c20_c_i << 8)];
      }

      c20_p = false;
      c20_b_p = true;
      c20_k = 0;
      exitg2 = false;
      while ((exitg2 == false) && (c20_k < 256)) {
        c20_b_k = 1.0 + (real_T)c20_k;
        c20_x1 = c20_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c20_b_k), 1, 256, 1, 0) - 1];
        c20_x2 = c20_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c20_b_k), 1, 256, 1, 0) - 1];
        c20_c_p = (c20_x1 == c20_x2);
        if (!c20_c_p) {
          c20_b_p = false;
          exitg2 = true;
        } else {
          c20_k++;
        }
      }

      if (!c20_b_p) {
      } else {
        c20_p = true;
      }

      if (CV_EML_IF(4, 1, 0, c20_p)) {
        _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 8);
        c20_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)
          _SFD_INTEGER_CHECK("i", c20_i), 1, 5, 2, 0) - 1;
        for (c20_i161 = 0; c20_i161 < 256; c20_i161++) {
          c20_bmls[c20_i161 + (c20_d_i << 8)] = c20_mBML[c20_i161];
        }

        _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 9);
        c20_full = 0.0;
        _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 10);
        exitg1 = 1;
      } else {
        c20_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(4, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 13);
  if (CV_EML_IF(4, 1, 1, c20_full != 0.0)) {
    _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 15);
    for (c20_i162 = 0; c20_i162 < 20; c20_i162++) {
      c20_u[c20_i162] = c20_cv5[c20_i162];
    }

    c20_y = NULL;
    sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 20),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c20_y);
    _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 15);
    for (c20_i163 = 0; c20_i163 < 1280; c20_i163++) {
      c20_b_u[c20_i163] = c20_bmls[c20_i163];
    }

    c20_b_y = NULL;
    sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 0, 0U, 1U, 0U, 2, 256, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c20_b_y);
    _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 16);
    for (c20_i164 = 0; c20_i164 < 256; c20_i164++) {
      c20_b_bmls[c20_i164] = c20_bmls[c20_i164 + 256];
    }

    for (c20_i165 = 0; c20_i165 < 256; c20_i165++) {
      c20_bmls[c20_i165] = c20_b_bmls[c20_i165];
    }

    _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 17);
    for (c20_i166 = 0; c20_i166 < 256; c20_i166++) {
      c20_c_bmls[c20_i166] = c20_bmls[c20_i166 + 512];
    }

    for (c20_i167 = 0; c20_i167 < 256; c20_i167++) {
      c20_bmls[c20_i167 + 256] = c20_c_bmls[c20_i167];
    }

    _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 18);
    for (c20_i168 = 0; c20_i168 < 256; c20_i168++) {
      c20_d_bmls[c20_i168] = c20_bmls[c20_i168 + 768];
    }

    for (c20_i169 = 0; c20_i169 < 256; c20_i169++) {
      c20_bmls[c20_i169 + 512] = c20_d_bmls[c20_i169];
    }

    _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 19);
    for (c20_i170 = 0; c20_i170 < 256; c20_i170++) {
      c20_bmls[c20_i170 + 1024] = c20_mBML[c20_i170];
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, 22);
  for (c20_i171 = 0; c20_i171 < 1280; c20_i171++) {
    c20_newBmls[c20_i171] = c20_bmls[c20_i171];
  }

  c20_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(4U, chartInstance->c20_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c20_DemoIdle_PEC_insertQueue(SimStruct *c20_S, real_T
  c20_bmls[1280], real_T c20_mBML[256], real_T c20_newBmls[1280])
{
  int32_T c20_i172;
  real_T c20_b_bmls[1280];
  int32_T c20_i173;
  real_T c20_b_mBML[256];
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  for (c20_i172 = 0; c20_i172 < 1280; c20_i172++) {
    c20_b_bmls[c20_i172] = c20_bmls[c20_i172];
  }

  for (c20_i173 = 0; c20_i173 < 256; c20_i173++) {
    c20_b_mBML[c20_i173] = c20_mBML[c20_i173];
  }

  c20_insertQueuec20_DemoIdle_PEC(chartInstance, c20_b_bmls, c20_b_mBML,
    c20_newBmls);
}

void sf_exported_user_c20_DemoIdle_PEC_wavePoseBradTable(SimStruct *c20_S,
  real_T c20_bmlID, real_T *c20_pr, real_T c20_poseBML[256])
{
  real_T c20_b_pr;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c20_S))->instanceInfo)->chartInstance;
  c20_wavePoseBradTablec20_DemoIdle_PEC(chartInstance, c20_bmlID, &c20_b_pr,
    c20_poseBML);
  *c20_pr = c20_b_pr;
}

static const mxArray *c20_q_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int8_T c20_j_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int8_T c20_y;
  int8_T c20_i174;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i174, 1, 2, 0U, 0, 0U, 0);
  c20_y = c20_i174;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_secs;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int8_T c20_y;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_secs = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_secs),
    &c20_thisId);
  sf_mex_destroy(&c20_secs);
  *(int8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_r_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_k_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i175;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i175, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i175;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_s_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint8_T c20_l_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_b_tp_init, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_tp_init),
    &c20_thisId);
  sf_mex_destroy(&c20_b_tp_init);
  return c20_y;
}

static uint8_T c20_m_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_tp_init;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y;
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)chartInstanceVoid;
  c20_b_tp_init = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_tp_init),
    &c20_thisId);
  sf_mex_destroy(&c20_b_tp_init);
  *(uint8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_n_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_b_setSimStateSideEffectsInfo, const char_T *
  c20_identifier)
{
  const mxArray *c20_y = NULL;
  emlrtMsgIdentifier c20_thisId;
  c20_y = NULL;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  sf_mex_assign(&c20_y, c20_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_setSimStateSideEffectsInfo), &c20_thisId), false);
  sf_mex_destroy(&c20_b_setSimStateSideEffectsInfo);
  return c20_y;
}

static const mxArray *c20_o_emlrt_marshallIn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  const mxArray *c20_y = NULL;
  (void)chartInstance;
  (void)c20_parentId;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_duplicatearraysafe(&c20_u), false);
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_updateDataWrittenToVector(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_vectorIndex)
{
  (void)chartInstance;
  c20_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c20_vectorIndex, 0, 9, 1, 0)] = true;
}

static void c20_errorIfDataNotWrittenToFcn(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_vectorIndex, uint32_T c20_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c20_dataNumber, c20_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c20_vectorIndex, 0, 9, 1,
    0)]);
}

static real_T c20_get_BML(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c20_b);
  if (chartInstance->c20_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#584) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c20_BML_address)[c20_b];
}

static void c20_set_BML(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c20_b);
  if (chartInstance->c20_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#584) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c20_BML_address)[c20_b] = c20_c;
}

static real_T *c20_access_BML(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c20_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#584) in the initialization routine of the chart.\n");
  }

  c20_c = *chartInstance->c20_BML_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c20_c;
}

static real_T c20_get_BML2(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c20_b);
  if (chartInstance->c20_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#591) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c20_BML2_address)[c20_b];
}

static void c20_set_BML2(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c20_b);
  if (chartInstance->c20_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#591) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c20_BML2_address)[c20_b] = c20_c;
}

static real_T *c20_access_BML2(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c20_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#591) in the initialization routine of the chart.\n");
  }

  c20_c = *chartInstance->c20_BML2_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c20_c;
}

static real_T c20_get_P(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c20_b);
  if (chartInstance->c20_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#585) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_P_address;
}

static void c20_set_P(SFc20_DemoIdle_PECInstanceStruct *chartInstance, uint32_T
                      c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c20_b);
  if (chartInstance->c20_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#585) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_P_address = c20_c;
}

static real_T *c20_access_P(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c20_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#585) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_P_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c20_c;
}

static real_T c20_get_STATE_BEFORE(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c20_b);
  if (chartInstance->c20_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#587) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_STATE_BEFORE_address;
}

static void c20_set_STATE_BEFORE(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c20_b);
  if (chartInstance->c20_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#587) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_STATE_BEFORE_address = c20_c;
}

static real_T *c20_access_STATE_BEFORE(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c20_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#587) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_STATE_BEFORE_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c20_c;
}

static real_T c20_get_STATE_OVER(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c20_b);
  if (chartInstance->c20_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#586) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_STATE_OVER_address;
}

static void c20_set_STATE_OVER(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c20_b);
  if (chartInstance->c20_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#586) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_STATE_OVER_address = c20_c;
}

static real_T *c20_access_STATE_OVER(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c20_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#586) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_STATE_OVER_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c20_c;
}

static real_T c20_get_avert(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c20_b);
  if (chartInstance->c20_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#592) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_avert_address;
}

static void c20_set_avert(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c20_b);
  if (chartInstance->c20_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#592) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_avert_address = c20_c;
}

static real_T *c20_access_avert(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c20_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#592) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_avert_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c20_c;
}

static real_T c20_get_bmlsM(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c20_b);
  if (chartInstance->c20_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#595) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c20_bmlsM_address)[c20_b];
}

static void c20_set_bmlsM(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c20_b);
  if (chartInstance->c20_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#595) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c20_bmlsM_address)[c20_b] = c20_c;
}

static real_T *c20_access_bmlsM(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c20_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#595) in the initialization routine of the chart.\n");
  }

  c20_c = *chartInstance->c20_bmlsM_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c20_c;
}

static real_T c20_get_fileID(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c20_b);
  if (chartInstance->c20_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#581) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_fileID_address;
}

static void c20_set_fileID(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c20_b);
  if (chartInstance->c20_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#581) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_fileID_address = c20_c;
}

static real_T *c20_access_fileID(SFc20_DemoIdle_PECInstanceStruct *chartInstance,
  uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c20_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#581) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_fileID_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c20_c;
}

static void init_dsm_address_info(SFc20_DemoIdle_PECInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c20_BML_address, &chartInstance->c20_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML2", (void **)
    &chartInstance->c20_BML2_address, &chartInstance->c20_BML2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c20_P_address, &chartInstance->c20_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c20_STATE_BEFORE_address,
    &chartInstance->c20_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c20_STATE_OVER_address, &chartInstance->c20_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c20_avert_address, &chartInstance->c20_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c20_bmlsM_address, &chartInstance->c20_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c20_fileID_address, &chartInstance->c20_fileID_index);
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

void sf_c20_DemoIdle_PEC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3241875619U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4087945663U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1318961651U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(484414391U);
}

mxArray *sf_c20_DemoIdle_PEC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("iFsGdxEBf37MFtb84KlJOB");
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_DemoIdle_PEC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_DemoIdle_PEC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_DemoIdle_PEC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[25],T\"gameState\",},{M[3],M[69],T\"BMLM\",},{M[3],M[33],T\"bFlag\",},{M[3],M[32],T\"lFlag\",},{M[3],M[72],T\"n\",},{M[3],M[70],T\"newBmlsM\",},{M[3],M[31],T\"rFlag\",},{M[8],M[0],T\"is_active_c20_DemoIdle_PEC\",},{M[9],M[0],T\"is_c20_DemoIdle_PEC\",},{M[11],M[29],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x7[8 10 11 46 49 42 51],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_DemoIdle_PEC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_DemoIdle_PECInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DemoIdle_PECMachineNumber_,
           20,
           10,
           18,
           0,
           22,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_DemoIdle_PECMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DemoIdle_PECMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DemoIdle_PECMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(1,1,1,0,"handUp");
          _SFD_SET_DATA_PROPS(2,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(3,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(4,11,0,0,"P");
          _SFD_SET_DATA_PROPS(5,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(6,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(7,0,0,0,"rFlag");
          _SFD_SET_DATA_PROPS(8,0,0,0,"lFlag");
          _SFD_SET_DATA_PROPS(9,0,0,0,"bFlag");
          _SFD_SET_DATA_PROPS(10,11,0,0,"BML2");
          _SFD_SET_DATA_PROPS(11,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(12,0,0,0,"BMLM");
          _SFD_SET_DATA_PROPS(13,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(14,11,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(15,0,0,0,"n");
          _SFD_SET_DATA_PROPS(16,9,0,0,"");
          _SFD_SET_DATA_PROPS(17,8,0,0,"");
          _SFD_SET_DATA_PROPS(18,9,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_CH_SUBSTATE_COUNT(8);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,5);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_CH_SUBSTATE_INDEX(6,7);
          _SFD_CH_SUBSTATE_INDEX(7,9);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
        }

        _SFD_CV_INIT_CHART(8,1,0,0);

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
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(8,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"wavePoseBradTablec20_DemoIdle_PEC",0,-1,990);
        _SFD_CV_INIT_EML_FCN(8,1,"aFcnTruthTableAction_1",990,-1,1182);
        _SFD_CV_INIT_EML_FCN(8,2,"aFcnTruthTableAction_2",1182,-1,1376);
        _SFD_CV_INIT_EML_FCN(8,3,"aFcnTruthTableAction_3",1376,-1,1557);
        _SFD_CV_INIT_EML_FCN(8,4,"aFcnTruthTableAction_4",1557,-1,1725);
        _SFD_CV_INIT_EML_FCN(8,5,"aFcnTruthTableAction_5",1725,-1,1894);
        _SFD_CV_INIT_EML_FCN(8,6,"aFcnTruthTableAction_6",1894,-1,2087);
        _SFD_CV_INIT_EML_IF(8,1,0,554,584,615,988);
        _SFD_CV_INIT_EML_IF(8,1,1,615,649,680,988);
        _SFD_CV_INIT_EML_IF(8,1,2,680,714,745,988);
        _SFD_CV_INIT_EML_IF(8,1,3,745,779,810,988);
        _SFD_CV_INIT_EML_IF(8,1,4,810,844,875,988);
        _SFD_CV_INIT_EML_IF(8,1,5,875,909,940,988);
        _SFD_CV_INIT_EML(4,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"insertQueuec20_DemoIdle_PEC",0,-1,640);
        _SFD_CV_INIT_EML_IF(4,1,0,125,150,-1,-2);
        _SFD_CV_INIT_EML_IF(4,1,1,294,305,-1,621);
        _SFD_CV_INIT_EML_FOR(4,1,0,105,117,289);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 12, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 12, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 12, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_o_sf_marshallOut,(MexInFcnForType)
            c20_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_o_sf_marshallOut,(MexInFcnForType)
            c20_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
            c20_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_o_sf_marshallOut,(MexInFcnForType)
            c20_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_o_sf_marshallOut,(MexInFcnForType)
            c20_e_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));

        {
          real_T *c20_handUp;
          real_T *c20_gameState;
          c20_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c20_handUp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c20_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(1U, c20_handUp);
          _SFD_SET_DATA_VALUE_PTR(2U, c20_gameState);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c20_BML_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_P_address);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c20_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c20_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c20_rFlag);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c20_lFlag);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c20_bFlag);
          _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c20_BML2_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c20_avert_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c20_BMLM);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c20_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(14U, *chartInstance->c20_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c20_n);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DemoIdle_PECMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "HNBaQgV92kOFMmrijhlljC";
}

static void sf_opaque_initialize_c20_DemoIdle_PEC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_DemoIdle_PECInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
    chartInstanceVar);
  initialize_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_DemoIdle_PEC(void *chartInstanceVar)
{
  enable_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_DemoIdle_PEC(void *chartInstanceVar)
{
  disable_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_DemoIdle_PEC(void *chartInstanceVar)
{
  sf_gateway_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_DemoIdle_PEC(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_DemoIdle_PEC
    ((SFc20_DemoIdle_PECInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_DemoIdle_PEC();/* state var info */
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

extern void sf_internal_set_sim_state_c20_DemoIdle_PEC(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c20_DemoIdle_PEC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_DemoIdle_PEC(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c20_DemoIdle_PEC(SimStruct* S, const mxArray
  *st)
{
}

static void sf_opaque_terminate_c20_DemoIdle_PEC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_DemoIdle_PECInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DemoIdle_PEC_optimization_info();
    }

    finalize_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
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
  initSimStructsc20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_DemoIdle_PEC(SimStruct *S)
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
    initialize_params_c20_DemoIdle_PEC((SFc20_DemoIdle_PECInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_DemoIdle_PEC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DemoIdle_PEC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1558762503U));
  ssSetChecksum1(S,(1396493667U));
  ssSetChecksum2(S,(2017227079U));
  ssSetChecksum3(S,(1972253960U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_DemoIdle_PEC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c20_DemoIdle_PEC(SimStruct *S)
{
  SFc20_DemoIdle_PECInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_DemoIdle_PECInstanceStruct *)utMalloc(sizeof
    (SFc20_DemoIdle_PECInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_DemoIdle_PECInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c20_DemoIdle_PEC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_DemoIdle_PEC;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c20_DemoIdle_PEC;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_DemoIdle_PEC;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_DemoIdle_PEC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_DemoIdle_PEC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_DemoIdle_PEC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_DemoIdle_PEC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_DemoIdle_PEC;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_DemoIdle_PEC;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c20_DemoIdle_PEC;
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

void c20_DemoIdle_PEC_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_DemoIdle_PEC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_DemoIdle_PEC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_DemoIdle_PEC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_DemoIdle_PEC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
