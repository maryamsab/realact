/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSs_Bdr_GK_BIS5_sfun.h"
#include "c11_ARP_02_RPSs_Bdr_GK_BIS5.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSs_Bdr_GK_BIS5_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c11_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_checkP                  ((uint8_T)1U)
#define c11_IN_gazeCamera              ((uint8_T)2U)
#define c11_IN_stateCheckSmile         ((uint8_T)3U)
#define c11_IN_stateHeadNeutral        ((uint8_T)4U)
#define c11_IN_stateImitateSmile       ((uint8_T)5U)
#define c11_IN_stateInitial            ((uint8_T)6U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c11_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[5];

/* Function Declarations */
static void initialize_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void initialize_params_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void enable_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void disable_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_st);
static void c11_set_sim_state_side_effects_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void finalize_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void sf_gateway_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_enter_atomic_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_enter_internal_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_exit_internal_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_initc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void initSimStructsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_stateHeadNeutral(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c11_encStr2Arr(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static real_T c11_fopen(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static real_T c11_fileManager(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c11_isequal(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);
static void c11_fprintf(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c11_b_fileID);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static real_T c11_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_feval, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_d_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_e_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_activate_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_deactivate_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_increment_counters_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_reset_counters_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance);
static void c11_smileTablec11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, real_T c11_bmlID,
   real_T *c11_p, real_T c11_poseBML[256]);
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int8_T c11_f_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_g_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_h_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_b_tp_stateInitial, const char_T *c11_identifier);
static uint8_T c11_i_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_j_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier);
static const mxArray *c11_k_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c11_vectorIndex);
static void c11_errorIfDataNotWrittenToFcn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c11_vectorIndex, uint32_T c11_dataNumber);
static real_T c11_get_BML(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_BML(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_BML(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_GAZE_WIN(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_GAZE_WIN(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_GAZE_WIN(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_P(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_P(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                      uint32_T c11_b, real_T c11_c);
static real_T *c11_access_P(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_BEFORE(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_BEFORE(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_BEFORE
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_GO(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_GO(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_GO(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_READY(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_READY(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_READY
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_avert(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_avert(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_changeFlag(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_changeFlag(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_changeFlag(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_gazing(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_gazing(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_gazing(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 == c11_IN_stateInitial)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 ==
      c11_IN_stateCheckSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 ==
      c11_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 == c11_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 ==
      c11_IN_stateImitateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 == c11_IN_checkP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  uint8_T c11_e_hoistedGlobal;
  uint8_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  uint8_T c11_f_hoistedGlobal;
  uint8_T c11_f_u;
  const mxArray *c11_g_y = NULL;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(6, 1), false);
  c11_hoistedGlobal = *c11_gameState;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_fileID;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_c_hoistedGlobal = chartInstance->c11_smileN;
  c11_c_u = c11_c_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_d_hoistedGlobal = chartInstance->c11_is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  c11_d_u = c11_d_hoistedGlobal;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_e_hoistedGlobal = chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  c11_e_u = c11_e_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  c11_f_hoistedGlobal = chartInstance->c11_temporalCounter_i1;
  c11_f_u = c11_f_hoistedGlobal;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 5, c11_g_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_u = sf_mex_dup(c11_st);
  *c11_gameState = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 0)), "gameState");
  chartInstance->c11_fileID = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 1)), "fileID");
  chartInstance->c11_smileN = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 2)), "smileN");
  chartInstance->c11_is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5 =
    c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 3)),
    "is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5");
  chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 4)),
     "is_c11_ARP_02_RPSs_Bdr_GK_BIS5");
  chartInstance->c11_temporalCounter_i1 = c11_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 5)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 == c11_IN_checkP) {
      chartInstance->c11_tp_checkP = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_checkP = 0U;
    }

    if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 == c11_IN_gazeCamera)
    {
      chartInstance->c11_tp_gazeCamera = 1U;
    } else {
      chartInstance->c11_tp_gazeCamera = 0U;
    }

    if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 ==
        c11_IN_stateCheckSmile) {
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      chartInstance->c11_tp_stateCheckSmile = 0U;
    }

    if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 ==
        c11_IN_stateHeadNeutral) {
      chartInstance->c11_tp_stateHeadNeutral = 1U;
    } else {
      chartInstance->c11_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 ==
        c11_IN_stateImitateSmile) {
      chartInstance->c11_tp_stateImitateSmile = 1U;
    } else {
      chartInstance->c11_tp_stateImitateSmile = 0U;
    }

    if (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 == c11_IN_stateInitial)
    {
      chartInstance->c11_tp_stateInitial = 1U;
    } else {
      chartInstance->c11_tp_stateInitial = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  c11_set_sim_state_side_effects_c11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

static void c11_enter_atomic_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_d_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  c11_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  chartInstance->c11_fileID = c11_fopen(chartInstance);
  c11_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c11_fileID, 7U);
  *c11_gameState = c11_get_STATE_BEFORE(chartInstance, 0);
  c11_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_gameState, 8U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
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
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 1.0;
  boolean_T c11_d_out;
  real_T c11_f_nargin = 0.0;
  real_T c11_f_nargout = 0.0;
  real_T c11_g_nargin = 0.0;
  real_T c11_g_nargout = 1.0;
  boolean_T c11_e_out;
  real_T c11_h_nargin = 0.0;
  real_T c11_h_nargout = 0.0;
  real_T c11_i_nargin = 0.0;
  real_T c11_i_nargout = 1.0;
  boolean_T c11_f_out;
  real_T c11_j_nargin = 0.0;
  real_T c11_j_nargout = 0.0;
  real_T c11_BML[256];
  real_T c11_P;
  int32_T c11_i0;
  real_T *c11_isSmiling;
  real_T *c11_gameState;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  switch (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5) {
   case c11_IN_checkP:
    CV_CHART_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_i_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    c11_out = CV_EML_IF(8, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs) &&
                        (chartInstance->c11_temporalCounter_i1 >= 10));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_checkP = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_CHART_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_o_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    c11_b_out = CV_EML_IF(4, 0, 0, *c11_isSmiling == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_gazeCamera = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 =
        c11_IN_stateImitateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateImitateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_g_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 1U, 7U);
      c11_fprintf(chartInstance, chartInstance->c11_fileID);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_CHART_EVAL(8, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_k_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    guard3 = false;
    guard4 = false;
    if (CV_EML_COND(7, 0, 0, *c11_isSmiling == 1.0)) {
      if (CV_EML_COND(7, 0, 1, *c11_gameState != c11_get_STATE_GO(chartInstance,
            0))) {
        if (CV_EML_COND(7, 0, 2, *c11_gameState != c11_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(7, 0, 0, true);
          CV_EML_IF(7, 0, 0, true);
          c11_c_out = true;
        } else {
          guard3 = true;
        }
      } else {
        c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
        guard4 = true;
      }
    } else {
      c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
      guard4 = true;
    }

    if (guard4 == true) {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c11_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    guard2 = false;
    if (c11_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_l_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_c_sf_marshallOut,
        c11_c_sf_marshallIn);
      c11_d_out = CV_EML_IF(2, 0, 0, c11_get_avert(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateCheckSmile = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 =
          c11_IN_stateHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateHeadNeutral = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_e_debug_family_names,
          c11_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargin, 0U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargout, 1U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 1U, 7U);
        c11_fprintf(chartInstance, chartInstance->c11_fileID);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c11_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_m_debug_family_names,
          c11_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_g_nargin, 0U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_g_nargout, 1U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_out, 2U,
          c11_c_sf_marshallOut, c11_c_sf_marshallIn);
        c11_e_out = CV_EML_IF(6, 0, 0, c11_get_avert(chartInstance, 0) == 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c11_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
          chartInstance->c11_tp_stateCheckSmile = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
          chartInstance->c11_isStable = false;
          chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 =
            c11_IN_stateImitateSmile;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
          chartInstance->c11_tp_stateImitateSmile = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_g_debug_family_names,
            c11_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h_nargin, 0U,
            c11_b_sf_marshallOut, c11_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h_nargout, 1U,
            c11_b_sf_marshallOut, c11_b_sf_marshallIn);
          c11_errorIfDataNotWrittenToFcn(chartInstance, 1U, 7U);
          c11_fprintf(chartInstance, chartInstance->c11_fileID);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard2 = true;
        }
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateHeadNeutral:
    CV_CHART_EVAL(8, 0, 4);
    c11_stateHeadNeutral(chartInstance);
    break;

   case c11_IN_stateImitateSmile:
    CV_CHART_EVAL(8, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_p_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(9, 0, 0, c11_get_P(chartInstance, 0) == 0.0)) {
      if (CV_EML_COND(9, 0, 1, c11_get_changeFlag(chartInstance, 0) != 1.0)) {
        CV_EML_MCDC(9, 0, 0, true);
        CV_EML_IF(9, 0, 0, true);
        c11_f_out = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(9, 0, 0, false);
      CV_EML_IF(9, 0, 0, false);
      c11_f_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateImitateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_checkP;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
      chartInstance->c11_temporalCounter_i1 = 0U;
      chartInstance->c11_tp_checkP = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_h_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_j_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_j_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      c11_smileTablec11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 1.0, &c11_P,
        c11_BML);
      c11_set_P(chartInstance, 0, c11_P);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      for (c11_i0 = 0; c11_i0 < 256; c11_i0++) {
        c11_set_BML(chartInstance, c11_i0, c11_BML[c11_i0]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_CHART_EVAL(8, 0, 6);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_stateCheckSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateCheckSmile = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(8, 0, 0);
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5) {
   case c11_IN_checkP:
    CV_CHART_EVAL(8, 0, 1);
    chartInstance->c11_tp_checkP = 0U;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_CHART_EVAL(8, 0, 2);
    chartInstance->c11_tp_gazeCamera = 0U;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_CHART_EVAL(8, 0, 3);
    chartInstance->c11_tp_stateCheckSmile = 0U;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateHeadNeutral:
    CV_CHART_EVAL(8, 0, 4);
    chartInstance->c11_tp_stateHeadNeutral = 0U;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateImitateSmile:
    CV_CHART_EVAL(8, 0, 5);
    chartInstance->c11_tp_stateImitateSmile = 0U;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_CHART_EVAL(8, 0, 6);
    chartInstance->c11_tp_stateInitial = 0U;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(8, 0, 0);
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }
}

static void c11_initc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_checkP = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_tp_gazeCamera = 0U;
  chartInstance->c11_tp_stateCheckSmile = 0U;
  chartInstance->c11_tp_stateHeadNeutral = 0U;
  chartInstance->c11_tp_stateImitateSmile = 0U;
  chartInstance->c11_tp_stateInitial = 0U;
  chartInstance->c11_is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5 = 0U;
  chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_stateHeadNeutral(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
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
  real_T c11_BML[256];
  real_T c11_P;
  int32_T c11_i1;
  real_T *c11_isSmiling;
  c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_j_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_out = CV_EML_IF(5, 0, 0, *c11_isSmiling == 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c11_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateHeadNeutral = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_stateCheckSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateCheckSmile = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_n_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    c11_b_out = CV_EML_IF(10, 0, 0, c11_get_P(chartInstance, 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_ARP_02_RPSs_Bdr_GK_BIS5 = c11_IN_gazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_gazeCamera = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_f_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      c11_smileTablec11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, 2.0, &c11_P,
        c11_BML);
      c11_set_P(chartInstance, 0, c11_P);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      for (c11_i1 = 0; c11_i1 < 256; c11_i1++) {
        c11_set_BML(chartInstance, c11_i1, c11_BML[c11_i1]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      c11_set_avert(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c11_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c11_sfEvent);
}

static void c11_encStr2Arr(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[224];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[224];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i2;
  static char_T c11_cv0[224] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
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

  int32_T c11_i3;
  static real_T c11_dv0[224] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_b_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i2 = 0; c11_i2 < 224; c11_i2++) {
    c11_mystr[c11_i2] = c11_cv0[c11_i2];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i3 = 0; c11_i3 < 224; c11_i3++) {
    c11_arr[c11_i3] = c11_dv0[c11_i3];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 224.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i4 = 0; c11_i4 < 256; c11_i4++) {
    c11_tt[c11_i4] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i5 = 0; c11_i5 < 224; c11_i5++) {
    c11_tt[c11_i5] = c11_arr[c11_i5];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i6 = 0; c11_i6 < 256; c11_i6++) {
    c11_myarr256[c11_i6] = c11_tt[c11_i6];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c11_fopen(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  return c11_fileManager(chartInstance);
}

static real_T c11_fileManager(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  int32_T c11_i7;
  static char_T c11_cv1[5] = { 'f', 'o', 'p', 'e', 'n' };

  char_T c11_u[5];
  const mxArray *c11_y = NULL;
  int32_T c11_i8;
  static char_T c11_filename[14] = { 'm', 'a', 'r', 'y', 'a', 'm', 'S', 'e', 'n',
    't', '.', 't', 'x', 't' };

  char_T c11_b_u[14];
  const mxArray *c11_b_y = NULL;
  char_T c11_c_u;
  const mxArray *c11_c_y = NULL;
  c11_isequal(chartInstance);
  for (c11_i7 = 0; c11_i7 < 5; c11_i7++) {
    c11_u[c11_i7] = c11_cv1[c11_i7];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  for (c11_i8 = 0; c11_i8 < 14; c11_i8++) {
    c11_b_u[c11_i8] = c11_filename[c11_i8];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  c11_c_u = 'a';
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_c_u, 10, 0U, 0U, 0U, 0), false);
  return c11_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 3U, 14, c11_y, 14, c11_b_y, 14,
     c11_c_y), "feval");
}

static void c11_isequal(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_fprintf(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, real_T c11_b_fileID)
{
  boolean_T c11_cond;
  int32_T c11_i9;
  static char_T c11_cv2[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 't',
    'i', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd', '_', 'm', 'x' };

  char_T c11_u[24];
  const mxArray *c11_y = NULL;
  boolean_T c11_b_cond;
  int32_T c11_i10;
  static char_T c11_cv3[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'F', 'i', 'l',
    'e', 'I', 'O', ':', 'I', 'n', 'v', 'a', 'l', 'i', 'd', 'F', 'i', 'd' };

  char_T c11_b_u[24];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i11;
  static char_T c11_cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c11_c_u[7];
  const mxArray *c11_c_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_d_y = NULL;
  int32_T c11_i12;
  static char_T c11_formatSpec[6] = { '%', 's', '\\', 'r', '\\', 'n' };

  char_T c11_e_u[6];
  const mxArray *c11_e_y = NULL;
  int32_T c11_i13;
  static char_T c11_arg[6] = { 'S', 'm', 'i', 'l', 'e', ':' };

  char_T c11_f_u[6];
  const mxArray *c11_f_y = NULL;
  const mxArray *c11_cfmt = NULL;
  const mxArray *c11_convs = NULL;
  c11_isequal(chartInstance);
  c11_cond = (c11_b_fileID != 0.0);
  if (c11_cond) {
  } else {
    for (c11_i9 = 0; c11_i9 < 24; c11_i9++) {
      c11_u[c11_i9] = c11_cv2[c11_i9];
    }

    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c11_y));
  }

  c11_b_cond = (c11_b_fileID > -1.0);
  if (c11_b_cond) {
  } else {
    for (c11_i10 = 0; c11_i10 < 24; c11_i10++) {
      c11_b_u[c11_i10] = c11_cv3[c11_i10];
    }

    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c11_b_y));
  }

  for (c11_i11 = 0; c11_i11 < 7; c11_i11++) {
    c11_c_u[c11_i11] = c11_cv4[c11_i11];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c11_d_u = c11_b_fileID;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0), false);
  for (c11_i12 = 0; c11_i12 < 6; c11_i12++) {
    c11_e_u[c11_i12] = c11_formatSpec[c11_i12];
  }

  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_e_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  for (c11_i13 = 0; c11_i13 < 6; c11_i13++) {
    c11_f_u[c11_i13] = c11_arg[c11_i13];
  }

  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_f_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  c11_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                       (sfGlobalDebugInstanceStruct, "feval", 1U, 4U, 14,
                        c11_c_y, 14, c11_d_y, 14, c11_e_y, 14, c11_f_y), "feval");
  sf_mex_destroy(&c11_cfmt);
  sf_mex_destroy(&c11_convs);
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\12-9-2015-Matlab-prior-M+M\\encStr2Arr.m"));
}

static real_T c11_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_feval, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_feval),
    &c11_thisId);
  sf_mex_destroy(&c11_feval);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
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

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i14;
  real_T c11_b_inData[256];
  int32_T c11_i15;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i14 = 0; c11_i14 < 256; c11_i14++) {
    c11_b_inData[c11_i14] = (*(real_T (*)[256])c11_inData)[c11_i14];
  }

  for (c11_i15 = 0; c11_i15 < 256; c11_i15++) {
    c11_u[c11_i15] = c11_b_inData[c11_i15];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv1[256];
  int32_T c11_i16;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c11_i16 = 0; c11_i16 < 256; c11_i16++) {
    c11_y[c11_i16] = c11_dv1[c11_i16];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_poseBML;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i17;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_poseBML = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_poseBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_poseBML);
  for (c11_i17 = 0; c11_i17 < 256; c11_i17++) {
    (*(real_T (*)[256])c11_outData)[c11_i17] = c11_y[c11_i17];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_feval;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_feval = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_feval),
    &c11_thisId);
  sf_mex_destroy(&c11_feval);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_d_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b0, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_aVarTruthTableCondition_2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_aVarTruthTableCondition_2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_aVarTruthTableCondition_2), &c11_thisId);
  sf_mex_destroy(&c11_aVarTruthTableCondition_2);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i18;
  real_T c11_b_inData[256];
  int32_T c11_i19;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i18 = 0; c11_i18 < 256; c11_i18++) {
    c11_b_inData[c11_i18] = (*(real_T (*)[256])c11_inData)[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 256; c11_i19++) {
    c11_u[c11_i19] = c11_b_inData[c11_i19];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_e_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv2[256];
  int32_T c11_i20;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv2, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c11_i20 = 0; c11_i20 < 256; c11_i20++) {
    c11_y[c11_i20] = c11_dv2[c11_i20];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myarr256;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i21;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_myarr256 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
  for (c11_i21 = 0; c11_i21 < 256; c11_i21++) {
    (*(real_T (*)[256])c11_outData)[c11_i21] = c11_y[c11_i21];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i22;
  char_T c11_b_inData[224];
  int32_T c11_i23;
  char_T c11_u[224];
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i22 = 0; c11_i22 < 224; c11_i22++) {
    c11_b_inData[c11_i22] = (*(char_T (*)[224])c11_inData)[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 224; c11_i23++) {
    c11_u[c11_i23] = c11_b_inData[c11_i23];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 224),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i24;
  real_T c11_b_inData[224];
  int32_T c11_i25;
  real_T c11_u[224];
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i24 = 0; c11_i24 < 224; c11_i24++) {
    c11_b_inData[c11_i24] = (*(real_T (*)[224])c11_inData)[c11_i24];
  }

  for (c11_i25 = 0; c11_i25 < 224; c11_i25++) {
    c11_u[c11_i25] = c11_b_inData[c11_i25];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 224), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i26;
  char_T c11_b_inData[105];
  int32_T c11_i27;
  char_T c11_u[105];
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i26 = 0; c11_i26 < 105; c11_i26++) {
    c11_b_inData[c11_i26] = (*(char_T (*)[105])c11_inData)[c11_i26];
  }

  for (c11_i27 = 0; c11_i27 < 105; c11_i27++) {
    c11_u[c11_i27] = c11_b_inData[c11_i27];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i28;
  real_T c11_b_inData[105];
  int32_T c11_i29;
  real_T c11_u[105];
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i28 = 0; c11_i28 < 105; c11_i28++) {
    c11_b_inData[c11_i28] = (*(real_T (*)[105])c11_inData)[c11_i28];
  }

  for (c11_i29 = 0; c11_i29 < 105; c11_i29++) {
    c11_u[c11_i29] = c11_b_inData[c11_i29];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

const mxArray *sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 50, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  const mxArray *c11_rhs5 = NULL;
  const mxArray *c11_lhs5 = NULL;
  const mxArray *c11_rhs6 = NULL;
  const mxArray *c11_lhs6 = NULL;
  const mxArray *c11_rhs7 = NULL;
  const mxArray *c11_lhs7 = NULL;
  const mxArray *c11_rhs8 = NULL;
  const mxArray *c11_lhs8 = NULL;
  const mxArray *c11_rhs9 = NULL;
  const mxArray *c11_lhs9 = NULL;
  const mxArray *c11_rhs10 = NULL;
  const mxArray *c11_lhs10 = NULL;
  const mxArray *c11_rhs11 = NULL;
  const mxArray *c11_lhs11 = NULL;
  const mxArray *c11_rhs12 = NULL;
  const mxArray *c11_lhs12 = NULL;
  const mxArray *c11_rhs13 = NULL;
  const mxArray *c11_lhs13 = NULL;
  const mxArray *c11_rhs14 = NULL;
  const mxArray *c11_lhs14 = NULL;
  const mxArray *c11_rhs15 = NULL;
  const mxArray *c11_lhs15 = NULL;
  const mxArray *c11_rhs16 = NULL;
  const mxArray *c11_lhs16 = NULL;
  const mxArray *c11_rhs17 = NULL;
  const mxArray *c11_lhs17 = NULL;
  const mxArray *c11_rhs18 = NULL;
  const mxArray *c11_lhs18 = NULL;
  const mxArray *c11_rhs19 = NULL;
  const mxArray *c11_lhs19 = NULL;
  const mxArray *c11_rhs20 = NULL;
  const mxArray *c11_lhs20 = NULL;
  const mxArray *c11_rhs21 = NULL;
  const mxArray *c11_lhs21 = NULL;
  const mxArray *c11_rhs22 = NULL;
  const mxArray *c11_lhs22 = NULL;
  const mxArray *c11_rhs23 = NULL;
  const mxArray *c11_lhs23 = NULL;
  const mxArray *c11_rhs24 = NULL;
  const mxArray *c11_lhs24 = NULL;
  const mxArray *c11_rhs25 = NULL;
  const mxArray *c11_lhs25 = NULL;
  const mxArray *c11_rhs26 = NULL;
  const mxArray *c11_lhs26 = NULL;
  const mxArray *c11_rhs27 = NULL;
  const mxArray *c11_lhs27 = NULL;
  const mxArray *c11_rhs28 = NULL;
  const mxArray *c11_lhs28 = NULL;
  const mxArray *c11_rhs29 = NULL;
  const mxArray *c11_lhs29 = NULL;
  const mxArray *c11_rhs30 = NULL;
  const mxArray *c11_lhs30 = NULL;
  const mxArray *c11_rhs31 = NULL;
  const mxArray *c11_lhs31 = NULL;
  const mxArray *c11_rhs32 = NULL;
  const mxArray *c11_lhs32 = NULL;
  const mxArray *c11_rhs33 = NULL;
  const mxArray *c11_lhs33 = NULL;
  const mxArray *c11_rhs34 = NULL;
  const mxArray *c11_lhs34 = NULL;
  const mxArray *c11_rhs35 = NULL;
  const mxArray *c11_lhs35 = NULL;
  const mxArray *c11_rhs36 = NULL;
  const mxArray *c11_lhs36 = NULL;
  const mxArray *c11_rhs37 = NULL;
  const mxArray *c11_lhs37 = NULL;
  const mxArray *c11_rhs38 = NULL;
  const mxArray *c11_lhs38 = NULL;
  const mxArray *c11_rhs39 = NULL;
  const mxArray *c11_lhs39 = NULL;
  const mxArray *c11_rhs40 = NULL;
  const mxArray *c11_lhs40 = NULL;
  const mxArray *c11_rhs41 = NULL;
  const mxArray *c11_lhs41 = NULL;
  const mxArray *c11_rhs42 = NULL;
  const mxArray *c11_lhs42 = NULL;
  const mxArray *c11_rhs43 = NULL;
  const mxArray *c11_lhs43 = NULL;
  const mxArray *c11_rhs44 = NULL;
  const mxArray *c11_lhs44 = NULL;
  const mxArray *c11_rhs45 = NULL;
  const mxArray *c11_lhs45 = NULL;
  const mxArray *c11_rhs46 = NULL;
  const mxArray *c11_lhs46 = NULL;
  const mxArray *c11_rhs47 = NULL;
  const mxArray *c11_lhs47 = NULL;
  const mxArray *c11_rhs48 = NULL;
  const mxArray *c11_lhs48 = NULL;
  const mxArray *c11_rhs49 = NULL;
  const mxArray *c11_lhs49 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/12-9-2015-Matlab-prior-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fopen"), "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fileManager"), "name",
                  "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.errorIf"),
                  "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/errorIf.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1334104338U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m!STANDALONE"),
                  "context", "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c11_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c11_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnan"), "name", "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c11_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c11_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fprintf"), "name", "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c11_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c11_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c11_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("upper"), "name", "name", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c11_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c11_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c11_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c11_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c11_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c11_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c11_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("colon"), "name", "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c11_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("colon"), "name", "name", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c11_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c11_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c11_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("floor"), "name", "name", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c11_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c11_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c11_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c11_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c11_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c11_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c11_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c11_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c11_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c11_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c11_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c11_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c11_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c11_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c11_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c11_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c11_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c11_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c11_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c11_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "name", "name", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c11_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("fidCheck"), "name", "name",
                  44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c11_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("upper"), "name", "name", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c11_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c11_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c11_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c11_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c11_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs49), "lhs", "lhs",
                  49);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
  sf_mex_destroy(&c11_rhs5);
  sf_mex_destroy(&c11_lhs5);
  sf_mex_destroy(&c11_rhs6);
  sf_mex_destroy(&c11_lhs6);
  sf_mex_destroy(&c11_rhs7);
  sf_mex_destroy(&c11_lhs7);
  sf_mex_destroy(&c11_rhs8);
  sf_mex_destroy(&c11_lhs8);
  sf_mex_destroy(&c11_rhs9);
  sf_mex_destroy(&c11_lhs9);
  sf_mex_destroy(&c11_rhs10);
  sf_mex_destroy(&c11_lhs10);
  sf_mex_destroy(&c11_rhs11);
  sf_mex_destroy(&c11_lhs11);
  sf_mex_destroy(&c11_rhs12);
  sf_mex_destroy(&c11_lhs12);
  sf_mex_destroy(&c11_rhs13);
  sf_mex_destroy(&c11_lhs13);
  sf_mex_destroy(&c11_rhs14);
  sf_mex_destroy(&c11_lhs14);
  sf_mex_destroy(&c11_rhs15);
  sf_mex_destroy(&c11_lhs15);
  sf_mex_destroy(&c11_rhs16);
  sf_mex_destroy(&c11_lhs16);
  sf_mex_destroy(&c11_rhs17);
  sf_mex_destroy(&c11_lhs17);
  sf_mex_destroy(&c11_rhs18);
  sf_mex_destroy(&c11_lhs18);
  sf_mex_destroy(&c11_rhs19);
  sf_mex_destroy(&c11_lhs19);
  sf_mex_destroy(&c11_rhs20);
  sf_mex_destroy(&c11_lhs20);
  sf_mex_destroy(&c11_rhs21);
  sf_mex_destroy(&c11_lhs21);
  sf_mex_destroy(&c11_rhs22);
  sf_mex_destroy(&c11_lhs22);
  sf_mex_destroy(&c11_rhs23);
  sf_mex_destroy(&c11_lhs23);
  sf_mex_destroy(&c11_rhs24);
  sf_mex_destroy(&c11_lhs24);
  sf_mex_destroy(&c11_rhs25);
  sf_mex_destroy(&c11_lhs25);
  sf_mex_destroy(&c11_rhs26);
  sf_mex_destroy(&c11_lhs26);
  sf_mex_destroy(&c11_rhs27);
  sf_mex_destroy(&c11_lhs27);
  sf_mex_destroy(&c11_rhs28);
  sf_mex_destroy(&c11_lhs28);
  sf_mex_destroy(&c11_rhs29);
  sf_mex_destroy(&c11_lhs29);
  sf_mex_destroy(&c11_rhs30);
  sf_mex_destroy(&c11_lhs30);
  sf_mex_destroy(&c11_rhs31);
  sf_mex_destroy(&c11_lhs31);
  sf_mex_destroy(&c11_rhs32);
  sf_mex_destroy(&c11_lhs32);
  sf_mex_destroy(&c11_rhs33);
  sf_mex_destroy(&c11_lhs33);
  sf_mex_destroy(&c11_rhs34);
  sf_mex_destroy(&c11_lhs34);
  sf_mex_destroy(&c11_rhs35);
  sf_mex_destroy(&c11_lhs35);
  sf_mex_destroy(&c11_rhs36);
  sf_mex_destroy(&c11_lhs36);
  sf_mex_destroy(&c11_rhs37);
  sf_mex_destroy(&c11_lhs37);
  sf_mex_destroy(&c11_rhs38);
  sf_mex_destroy(&c11_lhs38);
  sf_mex_destroy(&c11_rhs39);
  sf_mex_destroy(&c11_lhs39);
  sf_mex_destroy(&c11_rhs40);
  sf_mex_destroy(&c11_lhs40);
  sf_mex_destroy(&c11_rhs41);
  sf_mex_destroy(&c11_lhs41);
  sf_mex_destroy(&c11_rhs42);
  sf_mex_destroy(&c11_lhs42);
  sf_mex_destroy(&c11_rhs43);
  sf_mex_destroy(&c11_lhs43);
  sf_mex_destroy(&c11_rhs44);
  sf_mex_destroy(&c11_lhs44);
  sf_mex_destroy(&c11_rhs45);
  sf_mex_destroy(&c11_lhs45);
  sf_mex_destroy(&c11_rhs46);
  sf_mex_destroy(&c11_lhs46);
  sf_mex_destroy(&c11_rhs47);
  sf_mex_destroy(&c11_lhs47);
  sf_mex_destroy(&c11_rhs48);
  sf_mex_destroy(&c11_lhs48);
  sf_mex_destroy(&c11_rhs49);
  sf_mex_destroy(&c11_lhs49);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static void c11_activate_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = c11_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_deactivate_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_increment_counters_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  if (chartInstance->c11_temporalCounter_i1 < 15U) {
    chartInstance->c11_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c11_temporalCounter_i1 + 1);
  }
}

static void c11_reset_counters_secsc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_activate_secsc11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_increment_counters_secsc11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs
  (SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_reset_counters_secsc11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_deactivate_c11_ARP_02_RPSs_Bdr_GK_BIS5_secs(SimStruct
  *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_deactivate_secsc11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

boolean_T sf_exported_auto_isStablec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_c11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_enterc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_enter_atomic_c11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
  c11_enter_internal_c11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_exitc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

void sf_exported_auto_gatewayc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_initc11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct
  *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out, sf_internal_get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
                (c11_S), false);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *c11_S,
  const mxArray *c11_in)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5(c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct *c11_S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_smileTablec11_ARP_02_RPSs_Bdr_GK_BIS5
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, real_T c11_bmlID,
   real_T *c11_p, real_T c11_poseBML[256])
{
  uint32_T c11_debug_family_var_map[7];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  real_T c11_dv3[256];
  int32_T c11_i30;
  uint32_T c11_b_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[105];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[105];
  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  real_T c11_myarr256[256];
  int32_T c11_i31;
  static char_T c11_cv5[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"',
    '5', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i32;
  static real_T c11_dv4[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c11_i33;
  int32_T c11_i34;
  int32_T c11_i35;
  int32_T c11_i36;
  int32_T c11_i37;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_1, 0U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_2, 1U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_bmlID, 4U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p, 5U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_poseBML, 6U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_1 = (c11_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_2 = (c11_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(2, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 16);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 27);
    c11_encStr2Arr(chartInstance, c11_dv3);
    for (c11_i30 = 0; c11_i30 < 256; c11_i30++) {
      c11_poseBML[c11_i30] = c11_dv3[c11_i30];
    }

    c11_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 27);
    *c11_p = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(2, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_c_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_h_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
        c11_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_g_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 6U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 7U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U,
        c11_d_sf_marshallOut, c11_d_sf_marshallIn);
      for (c11_i31 = 0; c11_i31 < 105; c11_i31++) {
        c11_mystr[c11_i31] = c11_cv5[c11_i31];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
      c11_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
      for (c11_i32 = 0; c11_i32 < 105; c11_i32++) {
        c11_arr[c11_i32] = c11_dv4[c11_i32];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
      c11_ss = 105.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
      c11_padsize = c11_maxarrsize - c11_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
      for (c11_i33 = 0; c11_i33 < 256; c11_i33++) {
        c11_tt[c11_i33] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
      for (c11_i34 = 0; c11_i34 < 105; c11_i34++) {
        c11_tt[c11_i34] = c11_arr[c11_i34];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
      for (c11_i35 = 0; c11_i35 < 256; c11_i35++) {
        c11_myarr256[c11_i35] = c11_tt[c11_i35];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c11_i36 = 0; c11_i36 < 256; c11_i36++) {
        c11_poseBML[c11_i36] = c11_myarr256[c11_i36];
      }

      c11_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 33);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(2, 1);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 27);
      c11_encStr2Arr(chartInstance, c11_dv3);
      for (c11_i37 = 0; c11_i37 < 256; c11_i37++) {
        c11_poseBML[c11_i37] = c11_dv3[c11_i37];
      }

      c11_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 27);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c11_ARP_02_RPSs_Bdr_GK_BIS5_smileTable(SimStruct *c11_S,
  real_T c11_bmlID, real_T *c11_p, real_T c11_poseBML[256])
{
  real_T c11_b_p;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_smileTablec11_ARP_02_RPSs_Bdr_GK_BIS5(chartInstance, c11_bmlID, &c11_b_p,
    c11_poseBML);
  *c11_p = c11_b_p;
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int8_T c11_f_emlrt_marshallIn(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int8_T c11_y;
  int8_T c11_i38;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i38, 1, 2, 0U, 0, 0U, 0);
  c11_y = c11_i38;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_secs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int8_T c11_y;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_secs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_secs),
    &c11_thisId);
  sf_mex_destroy(&c11_secs);
  *(int8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_g_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i39;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i39, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i39;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_h_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_b_tp_stateInitial, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_stateInitial),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateInitial);
  return c11_y;
}

static uint8_T c11_i_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_stateInitial;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
    chartInstanceVoid;
  c11_b_tp_stateInitial = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_stateInitial),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateInitial);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_j_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_k_emlrt_marshallIn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_updateDataWrittenToVector
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 4, 1, 0)] = true;
}

static void c11_errorIfDataNotWrittenToFcn
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T
   c11_vectorIndex, uint32_T c11_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c11_dataNumber, c11_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c11_vectorIndex, 0, 4, 1,
    0)]);
}

static real_T c11_get_BML(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#557) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_BML_address)[c11_b];
}

static void c11_set_BML(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#557) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_BML_address)[c11_b] = c11_c;
}

static real_T *c11_access_BML(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#557) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_BML_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_GAZE_WIN(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#556) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_GAZE_WIN_address;
}

static void c11_set_GAZE_WIN(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#556) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_GAZE_WIN_address = c11_c;
}

static real_T *c11_access_GAZE_WIN(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#556) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_GAZE_WIN_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_P(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#558) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_P_address;
}

static void c11_set_P(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance,
                      uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#558) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_P_address = c11_c;
}

static real_T *c11_access_P(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#558) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_P_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_BEFORE(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#563) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_BEFORE_address;
}

static void c11_set_STATE_BEFORE(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#563) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_BEFORE_address = c11_c;
}

static real_T *c11_access_STATE_BEFORE
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#563) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_BEFORE_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_GO(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#561) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_GO_address;
}

static void c11_set_STATE_GO(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#561) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_GO_address = c11_c;
}

static real_T *c11_access_STATE_GO(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#561) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_GO_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_READY(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#562) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_READY_address;
}

static void c11_set_STATE_READY(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#562) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_READY_address = c11_c;
}

static real_T *c11_access_STATE_READY
  (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#562) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_READY_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#554) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_address;
}

static void c11_set_avert(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#554) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_address = c11_c;
}

static real_T *c11_access_avert(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#554) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c11_c;
}

static real_T c11_get_changeFlag(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#564) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_changeFlag_address;
}

static void c11_set_changeFlag(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#564) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_changeFlag_address = c11_c;
}

static real_T *c11_access_changeFlag(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#564) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_changeFlag_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c11_c;
}

static real_T c11_get_gazing(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#555) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_gazing_address;
}

static void c11_set_gazing(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#555) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_gazing_address = c11_c;
}

static real_T *c11_access_gazing(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#555) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_gazing_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c11_BML_address, &chartInstance->c11_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c11_GAZE_WIN_address, &chartInstance->c11_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c11_P_address, &chartInstance->c11_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c11_STATE_BEFORE_address,
    &chartInstance->c11_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c11_STATE_GO_address, &chartInstance->c11_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c11_STATE_READY_address,
    &chartInstance->c11_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c11_avert_address, &chartInstance->c11_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "changeFlag", (void **)
    &chartInstance->c11_changeFlag_address, &chartInstance->c11_changeFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c11_gazing_address, &chartInstance->c11_gazing_index);
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

void sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2648223889U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3099154985U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1212453056U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(53854962U);
}

mxArray *sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PmwoSHxnMbEPpmiyPaw35F");
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_ARP_02_RPSs_Bdr_GK_BIS5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[61],T\"gameState\",},{M[3],M[55],T\"fileID\",},{M[3],M[10],T\"smileN\",},{M[8],M[0],T\"is_active_c11_ARP_02_RPSs_Bdr_GK_BIS5\",},{M[9],M[0],T\"is_c11_ARP_02_RPSs_Bdr_GK_BIS5\",},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[65],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_ARP_02_RPSs_Bdr_GK_BIS5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
           11,
           7,
           11,
           0,
           16,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(1,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(2,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(3,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(4,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(5,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(6,11,0,0,"P");
          _SFD_SET_DATA_PROPS(7,0,0,0,"fileID");
          _SFD_SET_DATA_PROPS(8,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(9,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(10,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(11,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(12,11,0,0,"changeFlag");
          _SFD_SET_DATA_PROPS(13,8,0,0,"");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(2,0,2);
          _SFD_CH_SUBSTATE_COUNT(6);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,3);
          _SFD_CH_SUBSTATE_INDEX(3,4);
          _SFD_CH_SUBSTATE_INDEX(4,5);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(6,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"smileTablec11_ARP_02_RPSs_Bdr_GK_BIS5",0,-1,
                             404);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",404,-1,701);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",701,-1,889);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",889,-1,1188);
        _SFD_CV_INIT_EML_IF(2,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(2,1,1,289,323,354,402);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,66,1,48);

        {
          static int condStart[] = { 1, 16, 40 };

          static int condEnd[] = { 15, 39, 66 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,66,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,5,1,5);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));

        {
          real_T *c11_isSmiling;
          real_T *c11_gameState;
          c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c11_smileN);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c11_avert_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c11_BML_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c11_P_address);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c11_fileID);
          _SFD_SET_DATA_VALUE_PTR(8U, c11_gameState);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c11_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c11_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c11_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c11_changeFlag_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSs_Bdr_GK_BIS5MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "QOeGLjJkTR3KGHfy3U0BOB";
}

static void sf_opaque_initialize_c11_ARP_02_RPSs_Bdr_GK_BIS5(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
  initialize_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  enable_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  disable_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_ARP_02_RPSs_Bdr_GK_BIS5(void *chartInstanceVar)
{
  sf_gateway_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_ARP_02_RPSs_Bdr_GK_BIS5();/* state var info */
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

extern void sf_internal_set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_ARP_02_RPSs_Bdr_GK_BIS5();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c11_ARP_02_RPSs_Bdr_GK_BIS5(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSs_Bdr_GK_BIS5_optimization_info();
    }

    finalize_c11_ARP_02_RPSs_Bdr_GK_BIS5
      ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_ARP_02_RPSs_Bdr_GK_BIS5
    ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
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
    initialize_params_c11_ARP_02_RPSs_Bdr_GK_BIS5
      ((SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSs_Bdr_GK_BIS5_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1664112382U));
  ssSetChecksum1(S,(3896456358U));
  ssSetChecksum2(S,(2274031233U));
  ssSetChecksum3(S,(2901750472U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_ARP_02_RPSs_Bdr_GK_BIS5(SimStruct *S)
{
  SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct *)utMalloc(sizeof
    (SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_ARP_02_RPSs_Bdr_GK_BIS5InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_ARP_02_RPSs_Bdr_GK_BIS5;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_ARP_02_RPSs_Bdr_GK_BIS5;
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

void c11_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_ARP_02_RPSs_Bdr_GK_BIS5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_ARP_02_RPSs_Bdr_GK_BIS5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
