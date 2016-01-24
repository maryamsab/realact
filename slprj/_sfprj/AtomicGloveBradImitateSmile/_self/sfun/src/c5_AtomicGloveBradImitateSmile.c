/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AtomicGloveBradImitateSmile_sfun.h"
#include "c5_AtomicGloveBradImitateSmile.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AtomicGloveBradImitateSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c5_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c5_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c5_IN_stateBoredPose           ((uint8_T)1U)
#define c5_IN_stateRandomPose          ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c5_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c5_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void initialize_params_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void enable_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void disable_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void set_sim_state_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_st);
static void c5_set_sim_state_side_effects_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void finalize_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void sf_gateway_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_enter_atomic_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_enter_internal_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_exit_internal_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_initc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void initSimStructsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_enter_atomic_stateRandomPose
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_b_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_c_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_d_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_e_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_f_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_g_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_h_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_i_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_j_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static void c5_k_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256]);
static real_T c5_rand(SFc5_AtomicGloveBradImitateSmileInstanceStruct
                      *chartInstance);
static real_T c5_eml_rand(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance);
static void c5_eml_rand_mt19937ar(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_d_state[625]);
static void c5_twister_state_vector
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_mt[625], real_T c5_seed, uint32_T c5_b_mt[625]);
static void c5_b_eml_rand_mt19937ar
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_d_state[625], uint32_T c5_e_state[625], real_T *c5_r);
static void c5_eml_error(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_b_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static boolean_T c5_c_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_n_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_o_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_p_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_q_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_r_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_s_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_t_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static void c5_activate_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_deactivate_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_increment_counters_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_reset_counters_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance);
static void c5_sendBMLc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, real_T c5_arg
   [256]);
static void c5_boredPoseSc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, real_T
   c5_bmlID, real_T c5_poseBML[256]);
static void c5_sendBML(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance);
static void c5_b_sendBML(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance);
static const mxArray *c5_u_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int8_T c5_e_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_v_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_f_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_w_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static uint8_T c5_g_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_b_tp_stateRandomPose, const char_T *c5_identifier);
static uint8_T c5_h_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint32_T c5_i_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_b_method, const char_T *c5_identifier);
static uint32_T c5_j_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static uint32_T c5_k_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_d_state, const char_T *c5_identifier);
static uint32_T c5_l_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_m_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_d_state, const char_T *c5_identifier,
  uint32_T c5_y[625]);
static void c5_n_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  uint32_T c5_y[625]);
static void c5_o_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_d_state, const char_T *c5_identifier,
  uint32_T c5_y[2]);
static void c5_p_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  uint32_T c5_y[2]);
static const mxArray *c5_q_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_b_setSimStateSideEffectsInfo, const char_T *c5_identifier);
static const mxArray *c5_r_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_updateDataWrittenToVector
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_vectorIndex);
static void c5_errorIfDataNotWrittenToFcn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_vectorIndex, uint32_T c5_dataNumber);
static void c5_b_twister_state_vector
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_mt[625], real_T c5_seed);
static real_T c5_c_eml_rand_mt19937ar
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_d_state[625]);
static real_T c5_get_BOREDOMT(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_BOREDOMT(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_BOREDOMT(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_b(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_b(SFc5_AtomicGloveBradImitateSmileInstanceStruct
                     *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_b(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_bored(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_bored(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_bored(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_pose(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_pose(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_pose(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_randomP(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_randomP(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_randomP(SFc5_AtomicGloveBradImitateSmileInstanceStruct *
  chartInstance, uint32_T c5_b);
static void init_dsm_address_info(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_debugger_state_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  uint32_T c5_prevAniVal;
  c5_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c5_is_active_c5_AtomicGloveBradImitateSmile == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_AtomicGloveBradImitateSmile ==
      c5_IN_stateRandomPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_c5_AtomicGloveBradImitateSmile ==
      c5_IN_stateBoredPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
  }

  _SFD_SET_ANIMATION(c5_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  uint32_T c5_hoistedGlobal;
  uint32_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint32_T c5_b_hoistedGlobal;
  uint32_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_i0;
  uint32_T c5_c_u[625];
  const mxArray *c5_d_y = NULL;
  int32_T c5_i1;
  uint32_T c5_d_u[2];
  const mxArray *c5_e_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  uint8_T c5_d_hoistedGlobal;
  uint8_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  uint8_T c5_e_hoistedGlobal;
  uint8_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(7, 1), false);
  c5_hoistedGlobal = chartInstance->c5_method;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  if (!chartInstance->c5_method_not_empty) {
    sf_mex_assign(&c5_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_state;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  if (!chartInstance->c5_state_not_empty) {
    sf_mex_assign(&c5_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 1, c5_c_y);
  for (c5_i0 = 0; c5_i0 < 625; c5_i0++) {
    c5_c_u[c5_i0] = chartInstance->c5_c_state[c5_i0];
  }

  c5_d_y = NULL;
  if (!chartInstance->c5_c_state_not_empty) {
    sf_mex_assign(&c5_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_c_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c5_y, 2, c5_d_y);
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_d_u[c5_i1] = chartInstance->c5_b_state[c5_i1];
  }

  c5_e_y = NULL;
  if (!chartInstance->c5_b_state_not_empty) {
    sf_mex_assign(&c5_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_d_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_c_hoistedGlobal =
    chartInstance->c5_is_active_c5_AtomicGloveBradImitateSmile;
  c5_e_u = c5_c_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_d_hoistedGlobal = chartInstance->c5_is_c5_AtomicGloveBradImitateSmile;
  c5_f_u = c5_d_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 5, c5_g_y);
  c5_e_hoistedGlobal = chartInstance->c5_temporalCounter_i1;
  c5_g_u = c5_e_hoistedGlobal;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 6, c5_h_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_st)
{
  const mxArray *c5_u;
  uint32_T c5_uv0[625];
  int32_T c5_i2;
  uint32_T c5_uv1[2];
  int32_T c5_i3;
  c5_u = sf_mex_dup(c5_st);
  chartInstance->c5_method = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 0)), "method");
  chartInstance->c5_state = c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 1)), "state");
  c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
                        "state", c5_uv0);
  for (c5_i2 = 0; c5_i2 < 625; c5_i2++) {
    chartInstance->c5_c_state[c5_i2] = c5_uv0[c5_i2];
  }

  c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 3)),
                        "state", c5_uv1);
  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    chartInstance->c5_b_state[c5_i3] = c5_uv1[c5_i3];
  }

  chartInstance->c5_is_active_c5_AtomicGloveBradImitateSmile =
    c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 4)),
    "is_active_c5_AtomicGloveBradImitateSmile");
  chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 5)),
     "is_c5_AtomicGloveBradImitateSmile");
  chartInstance->c5_temporalCounter_i1 = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c5_setSimStateSideEffectsInfo,
                c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c5_u);
  chartInstance->c5_doSetSimStateSideEffects = 1U;
  c5_update_debugger_state_c5_AtomicGloveBradImitateSmile(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void c5_set_sim_state_side_effects_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  if (chartInstance->c5_doSetSimStateSideEffects != 0) {
    if (chartInstance->c5_is_c5_AtomicGloveBradImitateSmile ==
        c5_IN_stateBoredPose) {
      chartInstance->c5_tp_stateBoredPose = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_stateBoredPose = 0U;
    }

    if (chartInstance->c5_is_c5_AtomicGloveBradImitateSmile ==
        c5_IN_stateRandomPose) {
      chartInstance->c5_tp_stateRandomPose = 1U;
    } else {
      chartInstance->c5_tp_stateRandomPose = 0U;
    }

    chartInstance->c5_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c5_setSimStateSideEffectsInfo);
}

static void sf_gateway_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  c5_set_sim_state_side_effects_c5_AtomicGloveBradImitateSmile(chartInstance);
}

static void c5_enter_atomic_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  chartInstance->c5_is_active_c5_AtomicGloveBradImitateSmile = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void c5_enter_internal_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_stateRandomPose;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateRandomPose = 1U;
  c5_enter_atomic_stateRandomPose(chartInstance);
}

static void c5_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 1.0;
  boolean_T c5_b_out;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 0.0;
  real_T c5_r;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_dv0[256];
  int32_T c5_i4;
  real_T c5_dv1[256];
  real_T c5_d_nargin = 0.0;
  real_T c5_d_nargout = 1.0;
  boolean_T c5_c_out;
  real_T c5_e_nargin = 0.0;
  real_T c5_e_nargout = 1.0;
  boolean_T c5_d_out;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_isStable = true;
  switch (chartInstance->c5_is_c5_AtomicGloveBradImitateSmile) {
   case c5_IN_stateBoredPose:
    CV_CHART_EVAL(4, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_r_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    c5_out = CV_EML_IF(2, 0, 0, (chartInstance->c5_sfEvent == c5_event_secs) &&
                       (chartInstance->c5_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateBoredPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_c5_AtomicGloveBradImitateSmile =
        c5_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateRandomPose = 1U;
      c5_enter_atomic_stateRandomPose(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateRandomPose:
    CV_CHART_EVAL(4, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_s_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_b_sf_marshallOut,
      c5_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_out, 2U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, c5_get_randomP(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(5, 0, 1, c5_get_pose(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c5_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c5_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c5_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateRandomPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_stateBoredPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
      chartInstance->c5_temporalCounter_i1 = 0U;
      chartInstance->c5_tp_stateBoredPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_o_debug_family_names,
        c5_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_b_sf_marshallOut,
        c5_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U,
        c5_b_sf_marshallOut, c5_b_sf_marshallIn);
      c5_r = c5_rand(chartInstance);
      c5_x = c5_r * 16.0;
      c5_b_x = c5_x;
      c5_b_x = muDoubleScalarFloor(c5_b_x);
      c5_r = 3.0 + c5_b_x;
      c5_boredPoseSc5_AtomicGloveBradImitateSmile(chartInstance, c5_r, c5_dv0);
      for (c5_i4 = 0; c5_i4 < 256; c5_i4++) {
        c5_dv1[c5_i4] = c5_dv0[c5_i4];
      }

      c5_sendBMLc5_AtomicGloveBradImitateSmile(chartInstance, c5_dv1);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c5_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_q_debug_family_names,
        c5_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargin, 0U, c5_b_sf_marshallOut,
        c5_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargout, 1U,
        c5_b_sf_marshallOut, c5_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_out, 2U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      c5_c_out = CV_EML_IF(3, 0, 0, c5_get_randomP(chartInstance, 0) != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c5_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_stateRandomPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
        chartInstance->c5_isStable = false;
        chartInstance->c5_is_c5_AtomicGloveBradImitateSmile =
          c5_IN_stateRandomPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_stateRandomPose = 1U;
        c5_enter_atomic_stateRandomPose(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c5_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_p_debug_family_names,
          c5_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargin, 0U,
          c5_b_sf_marshallOut, c5_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargout, 1U,
          c5_b_sf_marshallOut, c5_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_out, 2U, c5_c_sf_marshallOut,
          c5_c_sf_marshallIn);
        c5_d_out = CV_EML_IF(1, 0, 0, c5_get_pose(chartInstance, 0) != 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c5_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_stateRandomPose = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
          chartInstance->c5_isStable = false;
          chartInstance->c5_is_c5_AtomicGloveBradImitateSmile =
            c5_IN_stateRandomPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_stateRandomPose = 1U;
          c5_enter_atomic_stateRandomPose(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c5_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void c5_exit_internal_c5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  switch (chartInstance->c5_is_c5_AtomicGloveBradImitateSmile) {
   case c5_IN_stateBoredPose:
    CV_CHART_EVAL(4, 0, 1);
    chartInstance->c5_tp_stateBoredPose = 0U;
    chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateRandomPose:
    CV_CHART_EVAL(4, 0, 2);
    chartInstance->c5_tp_stateRandomPose = 0U;
    chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    break;
  }
}

static void c5_initc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_method_not_empty = false;
  chartInstance->c5_state_not_empty = false;
  chartInstance->c5_b_state_not_empty = false;
  chartInstance->c5_c_state_not_empty = false;
  chartInstance->c5_doSetSimStateSideEffects = 0U;
  chartInstance->c5_setSimStateSideEffectsInfo = NULL;
  chartInstance->c5_tp_stateBoredPose = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateRandomPose = 0U;
  chartInstance->c5_is_active_c5_AtomicGloveBradImitateSmile = 0U;
  chartInstance->c5_is_c5_AtomicGloveBradImitateSmile = c5_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_enter_atomic_stateRandomPose
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T c5_hoistedGlobal;
  real_T c5_lowhigh[2];
  real_T c5_low;
  real_T c5_high;
  int32_T c5_i5;
  static char_T c5_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c5_u[26];
  const mxArray *c5_y = NULL;
  real_T c5_s;
  real_T c5_r;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_m_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  c5_set_b(chartInstance, 0, c5_get_BOREDOMT(chartInstance, 0) - c5_get_bored
           (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_n_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  c5_hoistedGlobal = c5_get_b(chartInstance, 0);
  c5_lowhigh[0] = 1.0;
  c5_lowhigh[1] = c5_hoistedGlobal;
  c5_low = c5_lowhigh[0];
  c5_high = c5_lowhigh[1];
  if (c5_low <= c5_high) {
  } else {
    for (c5_i5 = 0; c5_i5 < 26; c5_i5++) {
      c5_u[c5_i5] = c5_cv0[c5_i5];
    }

    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c5_y));
  }

  c5_s = (c5_high - c5_low) + 1.0;
  c5_r = c5_rand(chartInstance);
  c5_x = c5_r * c5_s;
  c5_b_x = c5_x;
  c5_b_x = muDoubleScalarFloor(c5_b_x);
  c5_r = c5_low + c5_b_x;
  c5_set_randomP(chartInstance, 0, c5_r);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  sf_mex_printf("%s =\\n", "randomP");
  c5_b_hoistedGlobal = c5_get_randomP(chartInstance, 0);
  c5_b_u = c5_b_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_b_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[91];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[91];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i6;
  static char_T c5_cv1[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i7;
  static real_T c5_dv2[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i6 = 0; c5_i6 < 91; c5_i6++) {
    c5_mystr[c5_i6] = c5_cv1[c5_i6];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i7 = 0; c5_i7 < 91; c5_i7++) {
    c5_arr[c5_i7] = c5_dv2[c5_i7];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i8 = 0; c5_i8 < 256; c5_i8++) {
    c5_tt[c5_i8] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i9 = 0; c5_i9 < 91; c5_i9++) {
    c5_tt[c5_i9] = c5_arr[c5_i9];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i10 = 0; c5_i10 < 256; c5_i10++) {
    c5_myarr256[c5_i10] = c5_tt[c5_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_b_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[87];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[87];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i11;
  static char_T c5_cv2[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c5_i12;
  static real_T c5_dv3[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_c_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i11 = 0; c5_i11 < 87; c5_i11++) {
    c5_mystr[c5_i11] = c5_cv2[c5_i11];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i12 = 0; c5_i12 < 87; c5_i12++) {
    c5_arr[c5_i12] = c5_dv3[c5_i12];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i13 = 0; c5_i13 < 256; c5_i13++) {
    c5_tt[c5_i13] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i14 = 0; c5_i14 < 87; c5_i14++) {
    c5_tt[c5_i14] = c5_arr[c5_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i15 = 0; c5_i15 < 256; c5_i15++) {
    c5_myarr256[c5_i15] = c5_tt[c5_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_c_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[93];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[93];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i16;
  static char_T c5_cv3[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i17;
  static real_T c5_dv4[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_d_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i16 = 0; c5_i16 < 93; c5_i16++) {
    c5_mystr[c5_i16] = c5_cv3[c5_i16];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i17 = 0; c5_i17 < 93; c5_i17++) {
    c5_arr[c5_i17] = c5_dv4[c5_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i18 = 0; c5_i18 < 256; c5_i18++) {
    c5_tt[c5_i18] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i19 = 0; c5_i19 < 93; c5_i19++) {
    c5_tt[c5_i19] = c5_arr[c5_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i20 = 0; c5_i20 < 256; c5_i20++) {
    c5_myarr256[c5_i20] = c5_tt[c5_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_d_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[94];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[94];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i21;
  static char_T c5_cv4[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i22;
  static real_T c5_dv5[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_e_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i21 = 0; c5_i21 < 94; c5_i21++) {
    c5_mystr[c5_i21] = c5_cv4[c5_i21];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i22 = 0; c5_i22 < 94; c5_i22++) {
    c5_arr[c5_i22] = c5_dv5[c5_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i23 = 0; c5_i23 < 256; c5_i23++) {
    c5_tt[c5_i23] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i24 = 0; c5_i24 < 94; c5_i24++) {
    c5_tt[c5_i24] = c5_arr[c5_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i25 = 0; c5_i25 < 256; c5_i25++) {
    c5_myarr256[c5_i25] = c5_tt[c5_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_e_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[95];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[95];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i26;
  static char_T c5_cv5[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i27;
  static real_T c5_dv6[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i30;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_f_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i26 = 0; c5_i26 < 95; c5_i26++) {
    c5_mystr[c5_i26] = c5_cv5[c5_i26];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i27 = 0; c5_i27 < 95; c5_i27++) {
    c5_arr[c5_i27] = c5_dv6[c5_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i28 = 0; c5_i28 < 256; c5_i28++) {
    c5_tt[c5_i28] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i29 = 0; c5_i29 < 95; c5_i29++) {
    c5_tt[c5_i29] = c5_arr[c5_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i30 = 0; c5_i30 < 256; c5_i30++) {
    c5_myarr256[c5_i30] = c5_tt[c5_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_f_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[88];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[88];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i31;
  static char_T c5_cv6[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c5_i32;
  static real_T c5_dv7[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_g_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i31 = 0; c5_i31 < 88; c5_i31++) {
    c5_mystr[c5_i31] = c5_cv6[c5_i31];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i32 = 0; c5_i32 < 88; c5_i32++) {
    c5_arr[c5_i32] = c5_dv7[c5_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i33 = 0; c5_i33 < 256; c5_i33++) {
    c5_tt[c5_i33] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i34 = 0; c5_i34 < 88; c5_i34++) {
    c5_tt[c5_i34] = c5_arr[c5_i34];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i35 = 0; c5_i35 < 256; c5_i35++) {
    c5_myarr256[c5_i35] = c5_tt[c5_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_g_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[93];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[93];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i36;
  static char_T c5_cv7[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i37;
  static real_T c5_dv8[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_h_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i36 = 0; c5_i36 < 93; c5_i36++) {
    c5_mystr[c5_i36] = c5_cv7[c5_i36];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i37 = 0; c5_i37 < 93; c5_i37++) {
    c5_arr[c5_i37] = c5_dv8[c5_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i38 = 0; c5_i38 < 256; c5_i38++) {
    c5_tt[c5_i38] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i39 = 0; c5_i39 < 93; c5_i39++) {
    c5_tt[c5_i39] = c5_arr[c5_i39];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i40 = 0; c5_i40 < 256; c5_i40++) {
    c5_myarr256[c5_i40] = c5_tt[c5_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_h_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[93];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[93];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i41;
  static char_T c5_cv8[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i42;
  static real_T c5_dv9[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_i_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i41 = 0; c5_i41 < 93; c5_i41++) {
    c5_mystr[c5_i41] = c5_cv8[c5_i41];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i42 = 0; c5_i42 < 93; c5_i42++) {
    c5_arr[c5_i42] = c5_dv9[c5_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i43 = 0; c5_i43 < 256; c5_i43++) {
    c5_tt[c5_i43] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i44 = 0; c5_i44 < 93; c5_i44++) {
    c5_tt[c5_i44] = c5_arr[c5_i44];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i45 = 0; c5_i45 < 256; c5_i45++) {
    c5_myarr256[c5_i45] = c5_tt[c5_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_i_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[97];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[97];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i46;
  static char_T c5_cv9[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i47;
  static real_T c5_dv10[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_j_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i46 = 0; c5_i46 < 97; c5_i46++) {
    c5_mystr[c5_i46] = c5_cv9[c5_i46];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i47 = 0; c5_i47 < 97; c5_i47++) {
    c5_arr[c5_i47] = c5_dv10[c5_i47];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i48 = 0; c5_i48 < 256; c5_i48++) {
    c5_tt[c5_i48] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i49 = 0; c5_i49 < 97; c5_i49++) {
    c5_tt[c5_i49] = c5_arr[c5_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i50 = 0; c5_i50 < 256; c5_i50++) {
    c5_myarr256[c5_i50] = c5_tt[c5_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_j_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[97];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[97];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i51;
  static char_T c5_cv10[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i52;
  static real_T c5_dv11[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_k_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i51 = 0; c5_i51 < 97; c5_i51++) {
    c5_mystr[c5_i51] = c5_cv10[c5_i51];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i52 = 0; c5_i52 < 97; c5_i52++) {
    c5_arr[c5_i52] = c5_dv11[c5_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i53 = 0; c5_i53 < 256; c5_i53++) {
    c5_tt[c5_i53] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i54 = 0; c5_i54 < 97; c5_i54++) {
    c5_tt[c5_i54] = c5_arr[c5_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i55 = 0; c5_i55 < 256; c5_i55++) {
    c5_myarr256[c5_i55] = c5_tt[c5_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_k_encStr2Arr(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, real_T c5_myarr256[256])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[92];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[256];
  char_T c5_mystr[92];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i56;
  static char_T c5_cv11[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i57;
  static real_T c5_dv12[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_l_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i56 = 0; c5_i56 < 92; c5_i56++) {
    c5_mystr[c5_i56] = c5_cv11[c5_i56];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i57 = 0; c5_i57 < 92; c5_i57++) {
    c5_arr[c5_i57] = c5_dv12[c5_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i58 = 0; c5_i58 < 256; c5_i58++) {
    c5_tt[c5_i58] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i59 = 0; c5_i59 < 92; c5_i59++) {
    c5_tt[c5_i59] = c5_arr[c5_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i60 = 0; c5_i60 < 256; c5_i60++) {
    c5_myarr256[c5_i60] = c5_tt[c5_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c5_rand(SFc5_AtomicGloveBradImitateSmileInstanceStruct
                      *chartInstance)
{
  return c5_eml_rand(chartInstance);
}

static real_T c5_eml_rand(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance)
{
  real_T c5_r;
  uint32_T c5_hoistedGlobal;
  uint32_T c5_d_state;
  uint32_T c5_e_state;
  uint32_T c5_s;
  uint32_T c5_u0;
  uint32_T c5_hi;
  uint32_T c5_lo;
  uint32_T c5_test1;
  uint32_T c5_test2;
  uint32_T c5_f_state;
  real_T c5_b_r;
  real_T c5_d0;
  int32_T c5_i61;
  uint32_T c5_icng;
  uint32_T c5_jsr;
  uint32_T c5_u1;
  uint32_T c5_u2;
  uint32_T c5_ui;
  uint32_T c5_b_ui;
  real_T c5_c_r;
  real_T c5_d1;
  uint32_T c5_uv2[625];
  int32_T c5_i62;
  real_T c5_d2;
  if (!chartInstance->c5_method_not_empty) {
    chartInstance->c5_method = 7U;
    chartInstance->c5_method_not_empty = true;
  }

  if (chartInstance->c5_method == 4U) {
    if (!chartInstance->c5_state_not_empty) {
      chartInstance->c5_state = 1144108930U;
      chartInstance->c5_state_not_empty = true;
    }

    c5_hoistedGlobal = chartInstance->c5_state;
    c5_d_state = c5_hoistedGlobal;
    c5_e_state = c5_d_state;
    c5_s = c5_e_state;
    c5_u0 = 127773U;
    if (c5_u0 == 0U) {
      c5_hi = MAX_uint32_T;
    } else {
      c5_hi = c5_s / c5_u0;
    }

    c5_lo = c5_s - c5_hi * 127773U;
    c5_test1 = 16807U * c5_lo;
    c5_test2 = 2836U * c5_hi;
    if (c5_test1 < c5_test2) {
      c5_f_state = (c5_test1 - c5_test2) + 2147483647U;
    } else {
      c5_f_state = c5_test1 - c5_test2;
    }

    c5_b_r = (real_T)c5_f_state * 4.6566128752457969E-10;
    c5_e_state = c5_f_state;
    c5_d0 = c5_b_r;
    chartInstance->c5_state = c5_e_state;
    c5_r = c5_d0;
  } else if (chartInstance->c5_method == 5U) {
    if (!chartInstance->c5_b_state_not_empty) {
      for (c5_i61 = 0; c5_i61 < 2; c5_i61++) {
        chartInstance->c5_b_state[c5_i61] = 362436069U + 158852560U * (uint32_T)
          c5_i61;
      }

      chartInstance->c5_b_state_not_empty = true;
    }

    c5_icng = chartInstance->c5_b_state[0];
    c5_jsr = chartInstance->c5_b_state[1];
    c5_u1 = c5_jsr;
    c5_u2 = c5_icng;
    c5_u2 = 69069U * c5_u2 + 1234567U;
    c5_u1 ^= c5_u1 << 13;
    c5_u1 ^= c5_u1 >> 17;
    c5_u1 ^= c5_u1 << 5;
    c5_ui = c5_u2 + c5_u1;
    chartInstance->c5_b_state[0] = c5_u2;
    chartInstance->c5_b_state[1] = c5_u1;
    c5_b_ui = c5_ui;
    c5_c_r = (real_T)c5_b_ui * 2.328306436538696E-10;
    c5_d1 = c5_c_r;
    c5_r = c5_d1;
  } else {
    if (!chartInstance->c5_c_state_not_empty) {
      c5_eml_rand_mt19937ar(chartInstance, c5_uv2);
      for (c5_i62 = 0; c5_i62 < 625; c5_i62++) {
        chartInstance->c5_c_state[c5_i62] = c5_uv2[c5_i62];
      }

      chartInstance->c5_c_state_not_empty = true;
    }

    c5_d2 = c5_c_eml_rand_mt19937ar(chartInstance, chartInstance->c5_c_state);
    c5_r = c5_d2;
  }

  return c5_r;
}

static void c5_eml_rand_mt19937ar(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_d_state[625])
{
  real_T c5_d3;
  int32_T c5_i63;
  c5_d3 = 5489.0;
  for (c5_i63 = 0; c5_i63 < 625; c5_i63++) {
    c5_d_state[c5_i63] = 0U;
  }

  c5_b_twister_state_vector(chartInstance, c5_d_state, c5_d3);
}

static void c5_twister_state_vector
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_mt[625], real_T c5_seed, uint32_T c5_b_mt[625])
{
  int32_T c5_i64;
  for (c5_i64 = 0; c5_i64 < 625; c5_i64++) {
    c5_b_mt[c5_i64] = c5_mt[c5_i64];
  }

  c5_b_twister_state_vector(chartInstance, c5_b_mt, c5_seed);
}

static void c5_b_eml_rand_mt19937ar
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_d_state[625], uint32_T c5_e_state[625], real_T *c5_r)
{
  int32_T c5_i65;
  for (c5_i65 = 0; c5_i65 < 625; c5_i65++) {
    c5_e_state[c5_i65] = c5_d_state[c5_i65];
  }

  *c5_r = c5_c_eml_rand_mt19937ar(chartInstance, c5_e_state);
}

static void c5_eml_error(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance)
{
  int32_T c5_i66;
  static char_T c5_cv12[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c5_u[37];
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  for (c5_i66 = 0; c5_i66 < 37; c5_i66++) {
    c5_u[c5_i66] = c5_cv12[c5_i66];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c5_y));
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i67;
  real_T c5_b_inData[256];
  int32_T c5_i68;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i67 = 0; c5_i67 < 256; c5_i67++) {
    c5_b_inData[c5_i67] = (*(real_T (*)[256])c5_inData)[c5_i67];
  }

  for (c5_i68 = 0; c5_i68 < 256; c5_i68++) {
    c5_u[c5_i68] = c5_b_inData[c5_i68];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256])
{
  real_T c5_dv13[256];
  int32_T c5_i69;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv13, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c5_i69 = 0; c5_i69 < 256; c5_i69++) {
    c5_y[c5_i69] = c5_dv13[c5_i69];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_poseBML;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[256];
  int32_T c5_i70;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_poseBML = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_poseBML), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_poseBML);
  for (c5_i70 = 0; c5_i70 < 256; c5_i70++) {
    (*(real_T (*)[256])c5_outData)[c5_i70] = c5_y[c5_i70];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_b_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d4;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d4, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d4;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_bmlID;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_bmlID = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_bmlID), &c5_thisId);
  sf_mex_destroy(&c5_bmlID);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(boolean_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static boolean_T c5_c_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_y;
  boolean_T c5_b0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b0, 1, 11, 0U, 0, 0U, 0);
  c5_y = c5_b0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_aVarTruthTableCondition_18;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_y;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_aVarTruthTableCondition_18 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_aVarTruthTableCondition_18), &c5_thisId);
  sf_mex_destroy(&c5_aVarTruthTableCondition_18);
  *(boolean_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i71;
  real_T c5_b_inData[256];
  int32_T c5_i72;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i71 = 0; c5_i71 < 256; c5_i71++) {
    c5_b_inData[c5_i71] = (*(real_T (*)[256])c5_inData)[c5_i71];
  }

  for (c5_i72 = 0; c5_i72 < 256; c5_i72++) {
    c5_u[c5_i72] = c5_b_inData[c5_i72];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256])
{
  real_T c5_dv14[256];
  int32_T c5_i73;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv14, 1, 0, 0U, 1, 0U, 1, 256);
  for (c5_i73 = 0; c5_i73 < 256; c5_i73++) {
    c5_y[c5_i73] = c5_dv14[c5_i73];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_myarr256;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[256];
  int32_T c5_i74;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_myarr256 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_myarr256), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_myarr256);
  for (c5_i74 = 0; c5_i74 < 256; c5_i74++) {
    (*(real_T (*)[256])c5_outData)[c5_i74] = c5_y[c5_i74];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i75;
  char_T c5_b_inData[91];
  int32_T c5_i76;
  char_T c5_u[91];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i75 = 0; c5_i75 < 91; c5_i75++) {
    c5_b_inData[c5_i75] = (*(char_T (*)[91])c5_inData)[c5_i75];
  }

  for (c5_i76 = 0; c5_i76 < 91; c5_i76++) {
    c5_u[c5_i76] = c5_b_inData[c5_i76];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i77;
  real_T c5_b_inData[91];
  int32_T c5_i78;
  real_T c5_u[91];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i77 = 0; c5_i77 < 91; c5_i77++) {
    c5_b_inData[c5_i77] = (*(real_T (*)[91])c5_inData)[c5_i77];
  }

  for (c5_i78 = 0; c5_i78 < 91; c5_i78++) {
    c5_u[c5_i78] = c5_b_inData[c5_i78];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i79;
  char_T c5_b_inData[87];
  int32_T c5_i80;
  char_T c5_u[87];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i79 = 0; c5_i79 < 87; c5_i79++) {
    c5_b_inData[c5_i79] = (*(char_T (*)[87])c5_inData)[c5_i79];
  }

  for (c5_i80 = 0; c5_i80 < 87; c5_i80++) {
    c5_u[c5_i80] = c5_b_inData[c5_i80];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i81;
  real_T c5_b_inData[87];
  int32_T c5_i82;
  real_T c5_u[87];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i81 = 0; c5_i81 < 87; c5_i81++) {
    c5_b_inData[c5_i81] = (*(real_T (*)[87])c5_inData)[c5_i81];
  }

  for (c5_i82 = 0; c5_i82 < 87; c5_i82++) {
    c5_u[c5_i82] = c5_b_inData[c5_i82];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i83;
  char_T c5_b_inData[93];
  int32_T c5_i84;
  char_T c5_u[93];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i83 = 0; c5_i83 < 93; c5_i83++) {
    c5_b_inData[c5_i83] = (*(char_T (*)[93])c5_inData)[c5_i83];
  }

  for (c5_i84 = 0; c5_i84 < 93; c5_i84++) {
    c5_u[c5_i84] = c5_b_inData[c5_i84];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i85;
  real_T c5_b_inData[93];
  int32_T c5_i86;
  real_T c5_u[93];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i85 = 0; c5_i85 < 93; c5_i85++) {
    c5_b_inData[c5_i85] = (*(real_T (*)[93])c5_inData)[c5_i85];
  }

  for (c5_i86 = 0; c5_i86 < 93; c5_i86++) {
    c5_u[c5_i86] = c5_b_inData[c5_i86];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i87;
  char_T c5_b_inData[94];
  int32_T c5_i88;
  char_T c5_u[94];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i87 = 0; c5_i87 < 94; c5_i87++) {
    c5_b_inData[c5_i87] = (*(char_T (*)[94])c5_inData)[c5_i87];
  }

  for (c5_i88 = 0; c5_i88 < 94; c5_i88++) {
    c5_u[c5_i88] = c5_b_inData[c5_i88];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i89;
  real_T c5_b_inData[94];
  int32_T c5_i90;
  real_T c5_u[94];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i89 = 0; c5_i89 < 94; c5_i89++) {
    c5_b_inData[c5_i89] = (*(real_T (*)[94])c5_inData)[c5_i89];
  }

  for (c5_i90 = 0; c5_i90 < 94; c5_i90++) {
    c5_u[c5_i90] = c5_b_inData[c5_i90];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i91;
  char_T c5_b_inData[95];
  int32_T c5_i92;
  char_T c5_u[95];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i91 = 0; c5_i91 < 95; c5_i91++) {
    c5_b_inData[c5_i91] = (*(char_T (*)[95])c5_inData)[c5_i91];
  }

  for (c5_i92 = 0; c5_i92 < 95; c5_i92++) {
    c5_u[c5_i92] = c5_b_inData[c5_i92];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_n_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i93;
  real_T c5_b_inData[95];
  int32_T c5_i94;
  real_T c5_u[95];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i93 = 0; c5_i93 < 95; c5_i93++) {
    c5_b_inData[c5_i93] = (*(real_T (*)[95])c5_inData)[c5_i93];
  }

  for (c5_i94 = 0; c5_i94 < 95; c5_i94++) {
    c5_u[c5_i94] = c5_b_inData[c5_i94];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_o_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i95;
  char_T c5_b_inData[88];
  int32_T c5_i96;
  char_T c5_u[88];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i95 = 0; c5_i95 < 88; c5_i95++) {
    c5_b_inData[c5_i95] = (*(char_T (*)[88])c5_inData)[c5_i95];
  }

  for (c5_i96 = 0; c5_i96 < 88; c5_i96++) {
    c5_u[c5_i96] = c5_b_inData[c5_i96];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_p_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i97;
  real_T c5_b_inData[88];
  int32_T c5_i98;
  real_T c5_u[88];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i97 = 0; c5_i97 < 88; c5_i97++) {
    c5_b_inData[c5_i97] = (*(real_T (*)[88])c5_inData)[c5_i97];
  }

  for (c5_i98 = 0; c5_i98 < 88; c5_i98++) {
    c5_u[c5_i98] = c5_b_inData[c5_i98];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_q_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i99;
  char_T c5_b_inData[97];
  int32_T c5_i100;
  char_T c5_u[97];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i99 = 0; c5_i99 < 97; c5_i99++) {
    c5_b_inData[c5_i99] = (*(char_T (*)[97])c5_inData)[c5_i99];
  }

  for (c5_i100 = 0; c5_i100 < 97; c5_i100++) {
    c5_u[c5_i100] = c5_b_inData[c5_i100];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_r_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i101;
  real_T c5_b_inData[97];
  int32_T c5_i102;
  real_T c5_u[97];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i101 = 0; c5_i101 < 97; c5_i101++) {
    c5_b_inData[c5_i101] = (*(real_T (*)[97])c5_inData)[c5_i101];
  }

  for (c5_i102 = 0; c5_i102 < 97; c5_i102++) {
    c5_u[c5_i102] = c5_b_inData[c5_i102];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_s_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i103;
  char_T c5_b_inData[92];
  int32_T c5_i104;
  char_T c5_u[92];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i103 = 0; c5_i103 < 92; c5_i103++) {
    c5_b_inData[c5_i103] = (*(char_T (*)[92])c5_inData)[c5_i103];
  }

  for (c5_i104 = 0; c5_i104 < 92; c5_i104++) {
    c5_u[c5_i104] = c5_b_inData[c5_i104];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_t_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i105;
  real_T c5_b_inData[92];
  int32_T c5_i106;
  real_T c5_u[92];
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i105 = 0; c5_i105 < 92; c5_i105++) {
    c5_b_inData[c5_i105] = (*(real_T (*)[92])c5_inData)[c5_i105];
  }

  for (c5_i106 = 0; c5_i106 < 92; c5_i106++) {
    c5_u[c5_i106] = c5_b_inData[c5_i106];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_AtomicGloveBradImitateSmile_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  const mxArray *c5_rhs11 = NULL;
  const mxArray *c5_lhs11 = NULL;
  const mxArray *c5_rhs12 = NULL;
  const mxArray *c5_lhs12 = NULL;
  const mxArray *c5_rhs13 = NULL;
  const mxArray *c5_lhs13 = NULL;
  const mxArray *c5_rhs14 = NULL;
  const mxArray *c5_lhs14 = NULL;
  const mxArray *c5_rhs15 = NULL;
  const mxArray *c5_lhs15 = NULL;
  const mxArray *c5_rhs16 = NULL;
  const mxArray *c5_lhs16 = NULL;
  const mxArray *c5_rhs17 = NULL;
  const mxArray *c5_lhs17 = NULL;
  const mxArray *c5_rhs18 = NULL;
  const mxArray *c5_lhs18 = NULL;
  const mxArray *c5_rhs19 = NULL;
  const mxArray *c5_lhs19 = NULL;
  const mxArray *c5_rhs20 = NULL;
  const mxArray *c5_lhs20 = NULL;
  const mxArray *c5_rhs21 = NULL;
  const mxArray *c5_lhs21 = NULL;
  const mxArray *c5_rhs22 = NULL;
  const mxArray *c5_lhs22 = NULL;
  const mxArray *c5_rhs23 = NULL;
  const mxArray *c5_lhs23 = NULL;
  const mxArray *c5_rhs24 = NULL;
  const mxArray *c5_lhs24 = NULL;
  const mxArray *c5_rhs25 = NULL;
  const mxArray *c5_lhs25 = NULL;
  const mxArray *c5_rhs26 = NULL;
  const mxArray *c5_lhs26 = NULL;
  const mxArray *c5_rhs27 = NULL;
  const mxArray *c5_lhs27 = NULL;
  const mxArray *c5_rhs28 = NULL;
  const mxArray *c5_lhs28 = NULL;
  const mxArray *c5_rhs29 = NULL;
  const mxArray *c5_lhs29 = NULL;
  const mxArray *c5_rhs30 = NULL;
  const mxArray *c5_lhs30 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c5_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c5_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c5_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c5_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c5_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c5_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c5_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c5_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c5_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c5_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c5_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c5_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c5_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c5_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c5_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c5_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c5_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c5_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c5_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c5_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
  sf_mex_destroy(&c5_rhs11);
  sf_mex_destroy(&c5_lhs11);
  sf_mex_destroy(&c5_rhs12);
  sf_mex_destroy(&c5_lhs12);
  sf_mex_destroy(&c5_rhs13);
  sf_mex_destroy(&c5_lhs13);
  sf_mex_destroy(&c5_rhs14);
  sf_mex_destroy(&c5_lhs14);
  sf_mex_destroy(&c5_rhs15);
  sf_mex_destroy(&c5_lhs15);
  sf_mex_destroy(&c5_rhs16);
  sf_mex_destroy(&c5_lhs16);
  sf_mex_destroy(&c5_rhs17);
  sf_mex_destroy(&c5_lhs17);
  sf_mex_destroy(&c5_rhs18);
  sf_mex_destroy(&c5_lhs18);
  sf_mex_destroy(&c5_rhs19);
  sf_mex_destroy(&c5_lhs19);
  sf_mex_destroy(&c5_rhs20);
  sf_mex_destroy(&c5_lhs20);
  sf_mex_destroy(&c5_rhs21);
  sf_mex_destroy(&c5_lhs21);
  sf_mex_destroy(&c5_rhs22);
  sf_mex_destroy(&c5_lhs22);
  sf_mex_destroy(&c5_rhs23);
  sf_mex_destroy(&c5_lhs23);
  sf_mex_destroy(&c5_rhs24);
  sf_mex_destroy(&c5_lhs24);
  sf_mex_destroy(&c5_rhs25);
  sf_mex_destroy(&c5_lhs25);
  sf_mex_destroy(&c5_rhs26);
  sf_mex_destroy(&c5_lhs26);
  sf_mex_destroy(&c5_rhs27);
  sf_mex_destroy(&c5_lhs27);
  sf_mex_destroy(&c5_rhs28);
  sf_mex_destroy(&c5_lhs28);
  sf_mex_destroy(&c5_rhs29);
  sf_mex_destroy(&c5_lhs29);
  sf_mex_destroy(&c5_rhs30);
  sf_mex_destroy(&c5_lhs30);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static void c5_activate_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = c5_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c5_event_secs,
               chartInstance->c5_sfEvent);
}

static void c5_deactivate_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c5_event_secs,
               chartInstance->c5_sfEvent);
}

static void c5_increment_counters_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  if (chartInstance->c5_temporalCounter_i1 < 3U) {
    chartInstance->c5_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c5_temporalCounter_i1 + 1);
  }
}

static void c5_reset_counters_secsc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c5_AtomicGloveBradImitateSmile_secs(SimStruct
  *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_activate_secsc5_AtomicGloveBradImitateSmile(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c5_AtomicGloveBradImitateSmile_secs
  (SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_increment_counters_secsc5_AtomicGloveBradImitateSmile(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c5_AtomicGloveBradImitateSmile_secs
  (SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_reset_counters_secsc5_AtomicGloveBradImitateSmile(chartInstance);
}

void sf_exported_auto_deactivate_c5_AtomicGloveBradImitateSmile_secs(SimStruct
  *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_deactivate_secsc5_AtomicGloveBradImitateSmile(chartInstance);
}

boolean_T sf_exported_auto_isStablec5_AtomicGloveBradImitateSmile(SimStruct
  *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c5_isStable;
}

void sf_exported_auto_duringc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_c5_AtomicGloveBradImitateSmile(chartInstance);
}

void sf_exported_auto_enterc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_sendBML(chartInstance);
  c5_enter_atomic_c5_AtomicGloveBradImitateSmile(chartInstance);
  c5_enter_internal_c5_AtomicGloveBradImitateSmile(chartInstance);
}

void sf_exported_auto_exitc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_exit_internal_c5_AtomicGloveBradImitateSmile(chartInstance);
  c5_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_sendBML(chartInstance);
}

void sf_exported_auto_disablec5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc5_AtomicGloveBradImitateSmile(SimStruct
  *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  chartInstance->c5_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc5_AtomicGloveBradImitateSmile
  (SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc5_AtomicGloveBradImitateSmile(SimStruct
  *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc5_AtomicGloveBradImitateSmile(SimStruct
  *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc5_AtomicGloveBradImitateSmile(SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_initc5_AtomicGloveBradImitateSmile(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec5_AtomicGloveBradImitateSmile
  (SimStruct *c5_S)
{
  const mxArray *c5_out = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_out = NULL;
  sf_mex_assign(&c5_out,
                sf_internal_get_sim_state_c5_AtomicGloveBradImitateSmile(c5_S),
                false);
  return c5_out;
}

void sf_exported_auto_setSimstatec5_AtomicGloveBradImitateSmile(SimStruct *c5_S,
  const mxArray *c5_in)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c5_AtomicGloveBradImitateSmile(c5_S, sf_mex_dup
    (c5_in));
  sf_mex_destroy(&c5_in);
}

void sf_exported_auto_check_state_inconsistency_c5_AtomicGloveBradImitateSmile
  (SimStruct *c5_S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AtomicGloveBradImitateSmileMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_sendBMLc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, real_T c5_arg
   [256])
{
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  real_T (*c5_b_arg)[256];
  c5_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c5_i107 = 0; c5_i107 < 256; c5_i107++) {
    _SFD_DATA_RANGE_CHECK(c5_arg[c5_i107], 5U);
  }

  _SFD_SET_DATA_VALUE_PTR(5U, c5_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c5_arg, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  for (c5_i108 = 0; c5_i108 < 256; c5_i108++) {
    (*c5_b_arg)[c5_i108] = c5_arg[c5_i108];
  }

  for (c5_i109 = 0; c5_i109 < 256; c5_i109++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_arg)[c5_i109], 5U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(5U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
}

static void c5_boredPoseSc5_AtomicGloveBradImitateSmile
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, real_T
   c5_bmlID, real_T c5_poseBML[256])
{
  uint32_T c5_debug_family_var_map[22];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  boolean_T c5_aVarTruthTableCondition_4;
  boolean_T c5_aVarTruthTableCondition_5;
  boolean_T c5_aVarTruthTableCondition_6;
  boolean_T c5_aVarTruthTableCondition_7;
  boolean_T c5_aVarTruthTableCondition_8;
  boolean_T c5_aVarTruthTableCondition_9;
  boolean_T c5_aVarTruthTableCondition_10;
  boolean_T c5_aVarTruthTableCondition_11;
  boolean_T c5_aVarTruthTableCondition_12;
  boolean_T c5_aVarTruthTableCondition_13;
  boolean_T c5_aVarTruthTableCondition_14;
  boolean_T c5_aVarTruthTableCondition_15;
  boolean_T c5_aVarTruthTableCondition_16;
  boolean_T c5_aVarTruthTableCondition_17;
  boolean_T c5_aVarTruthTableCondition_18;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  real_T c5_dv15[256];
  int32_T c5_i110;
  int32_T c5_i111;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  int32_T c5_i112;
  int32_T c5_i113;
  real_T c5_b_u[256];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i114;
  int32_T c5_i115;
  real_T c5_c_u[256];
  const mxArray *c5_c_y = NULL;
  int32_T c5_i116;
  int32_T c5_i117;
  real_T c5_d_u[256];
  const mxArray *c5_d_y = NULL;
  int32_T c5_i118;
  int32_T c5_i119;
  real_T c5_e_u[256];
  const mxArray *c5_e_y = NULL;
  int32_T c5_i120;
  int32_T c5_i121;
  real_T c5_f_u[256];
  const mxArray *c5_f_y = NULL;
  int32_T c5_i122;
  int32_T c5_i123;
  real_T c5_g_u[256];
  const mxArray *c5_g_y = NULL;
  int32_T c5_i124;
  int32_T c5_i125;
  real_T c5_h_u[256];
  const mxArray *c5_h_y = NULL;
  int32_T c5_i126;
  int32_T c5_i127;
  real_T c5_i_u[256];
  const mxArray *c5_i_y = NULL;
  int32_T c5_i128;
  int32_T c5_i129;
  real_T c5_j_u[256];
  const mxArray *c5_j_y = NULL;
  int32_T c5_i130;
  int32_T c5_i131;
  real_T c5_k_u[256];
  const mxArray *c5_k_y = NULL;
  int32_T c5_i132;
  int32_T c5_i133;
  real_T c5_l_u[256];
  const mxArray *c5_l_y = NULL;
  int32_T c5_i134;
  int32_T c5_i135;
  real_T c5_m_u[256];
  const mxArray *c5_m_y = NULL;
  int32_T c5_i136;
  int32_T c5_i137;
  real_T c5_n_u[256];
  const mxArray *c5_n_y = NULL;
  int32_T c5_i138;
  int32_T c5_i139;
  real_T c5_o_u[256];
  const mxArray *c5_o_y = NULL;
  int32_T c5_i140;
  int32_T c5_i141;
  real_T c5_p_u[256];
  const mxArray *c5_p_y = NULL;
  int32_T c5_i142;
  int32_T c5_i143;
  real_T c5_q_u[256];
  const mxArray *c5_q_y = NULL;
  int32_T c5_i144;
  int32_T c5_i145;
  real_T c5_r_u[256];
  const mxArray *c5_r_y = NULL;
  int32_T c5_i146;
  int32_T c5_i147;
  real_T c5_s_u[256];
  const mxArray *c5_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_4, 3U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_5, 4U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_6, 5U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_7, 6U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_8, 7U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_9, 8U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_10, 9U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_11, 10U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_12, 11U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_13, 12U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_14, 13U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_15, 14U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_16, 15U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_17, 16U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_18, 17U,
    c5_c_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 18U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 19U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_bmlID, 20U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseBML, 21U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_aVarTruthTableCondition_1 = (c5_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_aVarTruthTableCondition_2 = (c5_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
  c5_aVarTruthTableCondition_3 = (c5_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 33);
  c5_aVarTruthTableCondition_4 = (c5_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 36);
  c5_aVarTruthTableCondition_5 = (c5_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
  c5_aVarTruthTableCondition_6 = (c5_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 42);
  c5_aVarTruthTableCondition_7 = (c5_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 45);
  c5_aVarTruthTableCondition_8 = (c5_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 48);
  c5_aVarTruthTableCondition_9 = (c5_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 51);
  c5_aVarTruthTableCondition_10 = (c5_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 54);
  c5_aVarTruthTableCondition_11 = (c5_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 57);
  c5_aVarTruthTableCondition_12 = (c5_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 60);
  c5_aVarTruthTableCondition_13 = (c5_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 63);
  c5_aVarTruthTableCondition_14 = (c5_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 66);
  c5_aVarTruthTableCondition_15 = (c5_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 69);
  c5_aVarTruthTableCondition_16 = (c5_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 72);
  c5_aVarTruthTableCondition_17 = (c5_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 75);
  c5_aVarTruthTableCondition_18 = (c5_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 77);
  if (CV_EML_IF(0, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 78);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 121);
    c5_encStr2Arr(chartInstance, c5_dv15);
    for (c5_i110 = 0; c5_i110 < 256; c5_i110++) {
      c5_poseBML[c5_i110] = c5_dv15[c5_i110];
    }

    c5_updateDataWrittenToVector(chartInstance, 0U);
    c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c5_i111 = 0; c5_i111 < 256; c5_i111++) {
      c5_u[c5_i111] = c5_poseBML[c5_i111];
    }

    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_y);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -121);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 79);
    if (CV_EML_IF(0, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 80);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, MAX_int8_T);
      c5_b_encStr2Arr(chartInstance, c5_dv15);
      for (c5_i112 = 0; c5_i112 < 256; c5_i112++) {
        c5_poseBML[c5_i112] = c5_dv15[c5_i112];
      }

      c5_updateDataWrittenToVector(chartInstance, 0U);
      c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c5_i113 = 0; c5_i113 < 256; c5_i113++) {
        c5_b_u[c5_i113] = c5_poseBML[c5_i113];
      }

      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_b_y);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -127);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 81);
      if (CV_EML_IF(0, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 82);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 133U);
        c5_c_encStr2Arr(chartInstance, c5_dv15);
        for (c5_i114 = 0; c5_i114 < 256; c5_i114++) {
          c5_poseBML[c5_i114] = c5_dv15[c5_i114];
        }

        c5_updateDataWrittenToVector(chartInstance, 0U);
        c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c5_i115 = 0; c5_i115 < 256; c5_i115++) {
          c5_c_u[c5_i115] = c5_poseBML[c5_i115];
        }

        c5_c_y = NULL;
        sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c5_c_y);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -133);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 83);
        if (CV_EML_IF(0, 1, 3, c5_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 84);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 139U);
          c5_d_encStr2Arr(chartInstance, c5_dv15);
          for (c5_i116 = 0; c5_i116 < 256; c5_i116++) {
            c5_poseBML[c5_i116] = c5_dv15[c5_i116];
          }

          c5_updateDataWrittenToVector(chartInstance, 0U);
          c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c5_i117 = 0; c5_i117 < 256; c5_i117++) {
            c5_d_u[c5_i117] = c5_poseBML[c5_i117];
          }

          c5_d_y = NULL;
          sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c5_d_y);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -139);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 85);
          if (CV_EML_IF(0, 1, 4, c5_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 86);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 145U);
            c5_e_encStr2Arr(chartInstance, c5_dv15);
            for (c5_i118 = 0; c5_i118 < 256; c5_i118++) {
              c5_poseBML[c5_i118] = c5_dv15[c5_i118];
            }

            c5_updateDataWrittenToVector(chartInstance, 0U);
            c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c5_i119 = 0; c5_i119 < 256; c5_i119++) {
              c5_e_u[c5_i119] = c5_poseBML[c5_i119];
            }

            c5_e_y = NULL;
            sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c5_e_y);
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -145);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 87);
            if (CV_EML_IF(0, 1, 5, c5_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 88);
              CV_EML_FCN(0, 11);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 181U);
              c5_f_encStr2Arr(chartInstance, c5_dv15);
              for (c5_i120 = 0; c5_i120 < 256; c5_i120++) {
                c5_poseBML[c5_i120] = c5_dv15[c5_i120];
              }

              c5_updateDataWrittenToVector(chartInstance, 0U);
              c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c5_i121 = 0; c5_i121 < 256; c5_i121++) {
                c5_f_u[c5_i121] = c5_poseBML[c5_i121];
              }

              c5_f_y = NULL;
              sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c5_f_y);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -181);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 89);
              if (CV_EML_IF(0, 1, 6, c5_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 90);
                CV_EML_FCN(0, 3);
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 133U);
                c5_c_encStr2Arr(chartInstance, c5_dv15);
                for (c5_i122 = 0; c5_i122 < 256; c5_i122++) {
                  c5_poseBML[c5_i122] = c5_dv15[c5_i122];
                }

                c5_updateDataWrittenToVector(chartInstance, 0U);
                c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c5_i123 = 0; c5_i123 < 256; c5_i123++) {
                  c5_g_u[c5_i123] = c5_poseBML[c5_i123];
                }

                c5_g_y = NULL;
                sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c5_g_y);
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -133);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 91);
                if (CV_EML_IF(0, 1, 7, c5_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 92);
                  CV_EML_FCN(0, 5);
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 145U);
                  c5_e_encStr2Arr(chartInstance, c5_dv15);
                  for (c5_i124 = 0; c5_i124 < 256; c5_i124++) {
                    c5_poseBML[c5_i124] = c5_dv15[c5_i124];
                  }

                  c5_updateDataWrittenToVector(chartInstance, 0U);
                  c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c5_i125 = 0; c5_i125 < 256; c5_i125++) {
                    c5_h_u[c5_i125] = c5_poseBML[c5_i125];
                  }

                  c5_h_y = NULL;
                  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c5_h_y);
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 93);
                  if (CV_EML_IF(0, 1, 8, c5_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 94);
                    CV_EML_FCN(0, 3);
                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 133U);
                    c5_c_encStr2Arr(chartInstance, c5_dv15);
                    for (c5_i126 = 0; c5_i126 < 256; c5_i126++) {
                      c5_poseBML[c5_i126] = c5_dv15[c5_i126];
                    }

                    c5_updateDataWrittenToVector(chartInstance, 0U);
                    c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                    sf_mex_printf("%s =\\n", "poseBML");
                    for (c5_i127 = 0; c5_i127 < 256; c5_i127++) {
                      c5_i_u[c5_i127] = c5_poseBML[c5_i127];
                    }

                    c5_i_y = NULL;
                    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c5_i_y);
                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 95);
                    if (CV_EML_IF(0, 1, 9, c5_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 96);
                      CV_EML_FCN(0, 10);
                      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 175U);
                      c5_g_encStr2Arr(chartInstance, c5_dv15);
                      for (c5_i128 = 0; c5_i128 < 256; c5_i128++) {
                        c5_poseBML[c5_i128] = c5_dv15[c5_i128];
                      }

                      c5_updateDataWrittenToVector(chartInstance, 0U);
                      c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                      sf_mex_printf("%s =\\n", "poseBML");
                      for (c5_i129 = 0; c5_i129 < 256; c5_i129++) {
                        c5_j_u[c5_i129] = c5_poseBML[c5_i129];
                      }

                      c5_j_y = NULL;
                      sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c5_j_y);
                      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 97);
                      if (CV_EML_IF(0, 1, 10, c5_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 98);
                        CV_EML_FCN(0, 11);
                        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 181U);
                        c5_f_encStr2Arr(chartInstance, c5_dv15);
                        for (c5_i130 = 0; c5_i130 < 256; c5_i130++) {
                          c5_poseBML[c5_i130] = c5_dv15[c5_i130];
                        }

                        c5_updateDataWrittenToVector(chartInstance, 0U);
                        c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                        sf_mex_printf("%s =\\n", "poseBML");
                        for (c5_i131 = 0; c5_i131 < 256; c5_i131++) {
                          c5_k_u[c5_i131] = c5_poseBML[c5_i131];
                        }

                        c5_k_y = NULL;
                        sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c5_k_y);
                        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 99);
                        if (CV_EML_IF(0, 1, 11, c5_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 100);
                          CV_EML_FCN(0, 8);
                          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 163U);
                          c5_h_encStr2Arr(chartInstance, c5_dv15);
                          for (c5_i132 = 0; c5_i132 < 256; c5_i132++) {
                            c5_poseBML[c5_i132] = c5_dv15[c5_i132];
                          }

                          c5_updateDataWrittenToVector(chartInstance, 0U);
                          c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                          sf_mex_printf("%s =\\n", "poseBML");
                          for (c5_i133 = 0; c5_i133 < 256; c5_i133++) {
                            c5_l_u[c5_i133] = c5_poseBML[c5_i133];
                          }

                          c5_l_y = NULL;
                          sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c5_l_y);
                          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 101);
                          if (CV_EML_IF(0, 1, 12, c5_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 102);
                            CV_EML_FCN(0, 8);
                            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 163U);
                            c5_h_encStr2Arr(chartInstance, c5_dv15);
                            for (c5_i134 = 0; c5_i134 < 256; c5_i134++) {
                              c5_poseBML[c5_i134] = c5_dv15[c5_i134];
                            }

                            c5_updateDataWrittenToVector(chartInstance, 0U);
                            c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                            sf_mex_printf("%s =\\n", "poseBML");
                            for (c5_i135 = 0; c5_i135 < 256; c5_i135++) {
                              c5_m_u[c5_i135] = c5_poseBML[c5_i135];
                            }

                            c5_m_y = NULL;
                            sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c5_m_y);
                            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 103);
                            if (CV_EML_IF(0, 1, 13,
                                          c5_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 104);
                              CV_EML_FCN(0, 7);
                              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 157U);
                              c5_i_encStr2Arr(chartInstance, c5_dv15);
                              for (c5_i136 = 0; c5_i136 < 256; c5_i136++) {
                                c5_poseBML[c5_i136] = c5_dv15[c5_i136];
                              }

                              c5_updateDataWrittenToVector(chartInstance, 0U);
                              c5_errorIfDataNotWrittenToFcn(chartInstance, 0U,
                                7U);
                              sf_mex_printf("%s =\\n", "poseBML");
                              for (c5_i137 = 0; c5_i137 < 256; c5_i137++) {
                                c5_n_u[c5_i137] = c5_poseBML[c5_i137];
                              }

                              c5_n_y = NULL;
                              sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c5_n_y);
                              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 105);
                              if (CV_EML_IF(0, 1, 14,
                                            c5_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 106);
                                CV_EML_FCN(0, 6);
                                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                              151U);
                                c5_j_encStr2Arr(chartInstance, c5_dv15);
                                for (c5_i138 = 0; c5_i138 < 256; c5_i138++) {
                                  c5_poseBML[c5_i138] = c5_dv15[c5_i138];
                                }

                                c5_updateDataWrittenToVector(chartInstance, 0U);
                                c5_errorIfDataNotWrittenToFcn(chartInstance, 0U,
                                  7U);
                                sf_mex_printf("%s =\\n", "poseBML");
                                for (c5_i139 = 0; c5_i139 < 256; c5_i139++) {
                                  c5_o_u[c5_i139] = c5_poseBML[c5_i139];
                                }

                                c5_o_y = NULL;
                                sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c5_o_y);
                                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 107);
                                if (CV_EML_IF(0, 1, 15,
                                              c5_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                108);
                                  CV_EML_FCN(0, 5);
                                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                145U);
                                  c5_e_encStr2Arr(chartInstance, c5_dv15);
                                  for (c5_i140 = 0; c5_i140 < 256; c5_i140++) {
                                    c5_poseBML[c5_i140] = c5_dv15[c5_i140];
                                  }

                                  c5_updateDataWrittenToVector(chartInstance, 0U);
                                  c5_errorIfDataNotWrittenToFcn(chartInstance,
                                    0U, 7U);
                                  sf_mex_printf("%s =\\n", "poseBML");
                                  for (c5_i141 = 0; c5_i141 < 256; c5_i141++) {
                                    c5_p_u[c5_i141] = c5_poseBML[c5_i141];
                                  }

                                  c5_p_y = NULL;
                                  sf_mex_assign(&c5_p_y, sf_mex_create("y",
                                    c5_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c5_p_y);
                                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                109);
                                  if (CV_EML_IF(0, 1, 16,
                                                c5_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                  110);
                                    CV_EML_FCN(0, 8);
                                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                  163U);
                                    c5_h_encStr2Arr(chartInstance, c5_dv15);
                                    for (c5_i142 = 0; c5_i142 < 256; c5_i142++)
                                    {
                                      c5_poseBML[c5_i142] = c5_dv15[c5_i142];
                                    }

                                    c5_updateDataWrittenToVector(chartInstance,
                                      0U);
                                    c5_errorIfDataNotWrittenToFcn(chartInstance,
                                      0U, 7U);
                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c5_i143 = 0; c5_i143 < 256; c5_i143++)
                                    {
                                      c5_q_u[c5_i143] = c5_poseBML[c5_i143];
                                    }

                                    c5_q_y = NULL;
                                    sf_mex_assign(&c5_q_y, sf_mex_create("y",
                                      c5_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c5_q_y);
                                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent,
                                                  111);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c5_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c5_sfEvent,
                                                    112);
                                      CV_EML_FCN(0, 9);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c5_sfEvent,
                                                    169U);
                                      c5_k_encStr2Arr(chartInstance, c5_dv15);
                                      for (c5_i144 = 0; c5_i144 < 256; c5_i144++)
                                      {
                                        c5_poseBML[c5_i144] = c5_dv15[c5_i144];
                                      }

                                      c5_updateDataWrittenToVector(chartInstance,
                                        0U);
                                      c5_errorIfDataNotWrittenToFcn
                                        (chartInstance, 0U, 7U);
                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c5_i145 = 0; c5_i145 < 256; c5_i145++)
                                      {
                                        c5_r_u[c5_i145] = c5_poseBML[c5_i145];
                                      }

                                      c5_r_y = NULL;
                                      sf_mex_assign(&c5_r_y, sf_mex_create("y",
                                        c5_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c5_r_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c5_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c5_sfEvent,
                                                    114);
                                      CV_EML_FCN(0, 3);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c5_sfEvent,
                                                    133U);
                                      c5_c_encStr2Arr(chartInstance, c5_dv15);
                                      for (c5_i146 = 0; c5_i146 < 256; c5_i146++)
                                      {
                                        c5_poseBML[c5_i146] = c5_dv15[c5_i146];
                                      }

                                      c5_updateDataWrittenToVector(chartInstance,
                                        0U);
                                      c5_errorIfDataNotWrittenToFcn
                                        (chartInstance, 0U, 7U);
                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c5_i147 = 0; c5_i147 < 256; c5_i147++)
                                      {
                                        c5_s_u[c5_i147] = c5_poseBML[c5_i147];
                                      }

                                      c5_s_y = NULL;
                                      sf_mex_assign(&c5_s_y, sf_mex_create("y",
                                        c5_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c5_s_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c5_sfEvent,
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

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_sendBML(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c5_b_sendBML(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void sf_exported_user_c5_AtomicGloveBradImitateSmile_boredPoseS(SimStruct *c5_S,
  real_T c5_bmlID, real_T c5_poseBML[256])
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  c5_boredPoseSc5_AtomicGloveBradImitateSmile(chartInstance, c5_bmlID,
    c5_poseBML);
}

void sf_exported_user_c5_AtomicGloveBradImitateSmile_sendBML(SimStruct *c5_S,
  real_T c5_arg[256])
{
  int32_T c5_i148;
  real_T c5_b_arg[256];
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo
    )->chartInstance;
  for (c5_i148 = 0; c5_i148 < 256; c5_i148++) {
    c5_b_arg[c5_i148] = c5_arg[c5_i148];
  }

  c5_sendBMLc5_AtomicGloveBradImitateSmile(chartInstance, c5_b_arg);
}

static const mxArray *c5_u_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int8_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int8_T c5_e_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int8_T c5_y;
  int8_T c5_i149;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i149, 1, 2, 0U, 0, 0U, 0);
  c5_y = c5_i149;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_secs;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int8_T c5_y;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_secs = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_secs), &c5_thisId);
  sf_mex_destroy(&c5_secs);
  *(int8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_v_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_f_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i150;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i150, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i150;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_w_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  uint8_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(uint8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static uint8_T c5_g_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_b_tp_stateRandomPose, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_stateRandomPose),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_stateRandomPose);
  return c5_y;
}

static uint8_T c5_h_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u3;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u3, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u3;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_tp_stateRandomPose;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c5_b_tp_stateRandomPose = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_stateRandomPose),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_stateRandomPose);
  *(uint8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint32_T c5_i_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_b_method, const char_T *c5_identifier)
{
  uint32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_method),
    &c5_thisId);
  sf_mex_destroy(&c5_b_method);
  return c5_y;
}

static uint32_T c5_j_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u4;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_method_not_empty = false;
  } else {
    chartInstance->c5_method_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u4, 1, 7, 0U, 0, 0U, 0);
    c5_y = c5_u4;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static uint32_T c5_k_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_d_state, const char_T *c5_identifier)
{
  uint32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_d_state), &c5_thisId);
  sf_mex_destroy(&c5_d_state);
  return c5_y;
}

static uint32_T c5_l_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u5;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_state_not_empty = false;
  } else {
    chartInstance->c5_state_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u5, 1, 7, 0U, 0, 0U, 0);
    c5_y = c5_u5;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_m_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_d_state, const char_T *c5_identifier,
  uint32_T c5_y[625])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_d_state), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_d_state);
}

static void c5_n_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  uint32_T c5_y[625])
{
  uint32_T c5_uv3[625];
  int32_T c5_i151;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_c_state_not_empty = false;
  } else {
    chartInstance->c5_c_state_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c5_i151 = 0; c5_i151 < 625; c5_i151++) {
      c5_y[c5_i151] = c5_uv3[c5_i151];
    }
  }

  sf_mex_destroy(&c5_u);
}

static void c5_o_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_d_state, const char_T *c5_identifier,
  uint32_T c5_y[2])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_d_state), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_d_state);
}

static void c5_p_emlrt_marshallIn(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  uint32_T c5_y[2])
{
  uint32_T c5_uv4[2];
  int32_T c5_i152;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_b_state_not_empty = false;
  } else {
    chartInstance->c5_b_state_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c5_i152 = 0; c5_i152 < 2; c5_i152++) {
      c5_y[c5_i152] = c5_uv4[c5_i152];
    }
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_q_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_b_setSimStateSideEffectsInfo, const char_T *c5_identifier)
{
  const mxArray *c5_y = NULL;
  emlrtMsgIdentifier c5_thisId;
  c5_y = NULL;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  sf_mex_assign(&c5_y, c5_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_setSimStateSideEffectsInfo), &c5_thisId), false);
  sf_mex_destroy(&c5_b_setSimStateSideEffectsInfo);
  return c5_y;
}

static const mxArray *c5_r_emlrt_marshallIn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, const mxArray *
   c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  (void)c5_parentId;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u), false);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_updateDataWrittenToVector
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_vectorIndex)
{
  (void)chartInstance;
  c5_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c5_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c5_errorIfDataNotWrittenToFcn
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_vectorIndex, uint32_T c5_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c5_dataNumber, c5_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c5_vectorIndex, 0, 0, 1,
    0)]);
}

static void c5_b_twister_state_vector
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_mt[625], real_T c5_seed)
{
  real_T c5_d5;
  uint32_T c5_u6;
  uint32_T c5_r;
  int32_T c5_mti;
  real_T c5_b_mti;
  real_T c5_d6;
  uint32_T c5_u7;
  (void)chartInstance;
  c5_d5 = c5_seed;
  if (c5_d5 < 4.294967296E+9) {
    if (c5_d5 >= 0.0) {
      c5_u6 = (uint32_T)c5_d5;
    } else {
      c5_u6 = 0U;
    }
  } else if (c5_d5 >= 4.294967296E+9) {
    c5_u6 = MAX_uint32_T;
  } else {
    c5_u6 = 0U;
  }

  c5_r = c5_u6;
  c5_mt[0] = c5_r;
  for (c5_mti = 0; c5_mti < 623; c5_mti++) {
    c5_b_mti = 2.0 + (real_T)c5_mti;
    c5_d6 = muDoubleScalarRound(c5_b_mti - 1.0);
    if (c5_d6 < 4.294967296E+9) {
      if (c5_d6 >= 0.0) {
        c5_u7 = (uint32_T)c5_d6;
      } else {
        c5_u7 = 0U;
      }
    } else if (c5_d6 >= 4.294967296E+9) {
      c5_u7 = MAX_uint32_T;
    } else {
      c5_u7 = 0U;
    }

    c5_r = (c5_r ^ c5_r >> 30U) * 1812433253U + c5_u7;
    c5_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c5_b_mti), 1, 625, 1, 0) - 1] = c5_r;
  }

  c5_mt[624] = 624U;
}

static real_T c5_c_eml_rand_mt19937ar
  (SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance, uint32_T
   c5_d_state[625])
{
  int32_T c5_i153;
  uint32_T c5_u[2];
  int32_T c5_j;
  real_T c5_b_j;
  uint32_T c5_mti;
  int32_T c5_kk;
  real_T c5_b_kk;
  uint32_T c5_y;
  uint32_T c5_b_y;
  uint32_T c5_c_y;
  int32_T c5_c_kk;
  uint32_T c5_d_y;
  uint32_T c5_e_y;
  uint32_T c5_f_y;
  uint32_T c5_g_y;
  real_T c5_b_r;
  boolean_T c5_b1;
  boolean_T c5_isvalid;
  int32_T c5_k;
  int32_T c5_a;
  int32_T c5_b_a;
  real_T c5_d7;
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
    for (c5_i153 = 0; c5_i153 < 2; c5_i153++) {
      c5_u[c5_i153] = 0U;
    }

    for (c5_j = 0; c5_j < 2; c5_j++) {
      c5_b_j = 1.0 + (real_T)c5_j;
      c5_mti = c5_d_state[624] + 1U;
      if ((real_T)c5_mti >= 625.0) {
        for (c5_kk = 0; c5_kk < 227; c5_kk++) {
          c5_b_kk = 1.0 + (real_T)c5_kk;
          c5_y = (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c5_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c5_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c5_b_y = c5_y;
          c5_c_y = c5_b_y;
          if ((real_T)(c5_c_y & 1U) == 0.0) {
            c5_c_y >>= 1U;
          } else {
            c5_c_y = c5_c_y >> 1U ^ 2567483615U;
          }

          c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c5_b_kk), 1, 625, 1, 0) - 1] =
            c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c5_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c5_c_y;
        }

        for (c5_c_kk = 0; c5_c_kk < 396; c5_c_kk++) {
          c5_b_kk = 228.0 + (real_T)c5_c_kk;
          c5_y = (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c5_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c5_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c5_d_y = c5_y;
          c5_e_y = c5_d_y;
          if ((real_T)(c5_e_y & 1U) == 0.0) {
            c5_e_y >>= 1U;
          } else {
            c5_e_y = c5_e_y >> 1U ^ 2567483615U;
          }

          c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c5_b_kk), 1, 625, 1, 0) - 1] =
            c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c5_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c5_e_y;
        }

        c5_y = (c5_d_state[623] & 2147483648U) | (c5_d_state[0] & 2147483647U);
        c5_f_y = c5_y;
        c5_g_y = c5_f_y;
        if ((real_T)(c5_g_y & 1U) == 0.0) {
          c5_g_y >>= 1U;
        } else {
          c5_g_y = c5_g_y >> 1U ^ 2567483615U;
        }

        c5_d_state[623] = c5_d_state[396] ^ c5_g_y;
        c5_mti = 1U;
      }

      c5_y = c5_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c5_mti), 1, 625, 1, 0)
        - 1];
      c5_d_state[624] = c5_mti;
      c5_y ^= c5_y >> 11U;
      c5_y ^= c5_y << 7U & 2636928640U;
      c5_y ^= c5_y << 15U & 4022730752U;
      c5_y ^= c5_y >> 18U;
      c5_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c5_b_j), 1, 2, 1, 0) - 1] = c5_y;
    }

    c5_u[0] >>= 5U;
    c5_u[1] >>= 6U;
    c5_b_r = 1.1102230246251565E-16 * ((real_T)c5_u[0] * 6.7108864E+7 + (real_T)
      c5_u[1]);
    if (c5_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c5_d_state[624] >= 1.0) {
        if ((real_T)c5_d_state[624] < 625.0) {
          c5_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c5_b1 = false;
      }

      c5_isvalid = c5_b1;
      if (c5_isvalid) {
        c5_isvalid = false;
        c5_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c5_k < 625)) {
          if ((real_T)c5_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c5_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c5_a = c5_k;
            c5_b_a = c5_a + 1;
            c5_k = c5_b_a;
          } else {
            c5_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c5_isvalid) {
        c5_eml_error(chartInstance);
        c5_d7 = 5489.0;
        c5_b_twister_state_vector(chartInstance, c5_d_state, c5_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c5_b_r;
}

static real_T c5_get_BOREDOMT(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c5_b);
  if (chartInstance->c5_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#316) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_BOREDOMT_address;
}

static void c5_set_BOREDOMT(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c5_b);
  if (chartInstance->c5_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#316) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_BOREDOMT_address = c5_c;
}

static real_T *c5_access_BOREDOMT(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c5_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#316) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_BOREDOMT_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c5_c;
}

static real_T c5_get_b(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c5_b);
  if (chartInstance->c5_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#319) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_b_address;
}

static void c5_set_b(SFc5_AtomicGloveBradImitateSmileInstanceStruct
                     *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c5_b);
  if (chartInstance->c5_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#319) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_b_address = c5_c;
}

static real_T *c5_access_b(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c5_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#319) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_b_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c5_c;
}

static real_T c5_get_bored(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c5_b);
  if (chartInstance->c5_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#315) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_bored_address;
}

static void c5_set_bored(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c5_b);
  if (chartInstance->c5_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#315) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_bored_address = c5_c;
}

static real_T *c5_access_bored(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c5_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#315) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_bored_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c5_c;
}

static real_T c5_get_pose(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c5_b);
  if (chartInstance->c5_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#318) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_pose_address;
}

static void c5_set_pose(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c5_b);
  if (chartInstance->c5_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#318) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_pose_address = c5_c;
}

static real_T *c5_access_pose(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c5_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#318) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_pose_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c5_c;
}

static real_T c5_get_randomP(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c5_b);
  if (chartInstance->c5_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#317) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_randomP_address;
}

static void c5_set_randomP(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c5_b);
  if (chartInstance->c5_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#317) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_randomP_address = c5_c;
}

static real_T *c5_access_randomP(SFc5_AtomicGloveBradImitateSmileInstanceStruct *
  chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c5_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#317) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_randomP_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c5_c;
}

static void init_dsm_address_info(SFc5_AtomicGloveBradImitateSmileInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c5_BOREDOMT_address, &chartInstance->c5_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "b", (void **)
    &chartInstance->c5_b_address, &chartInstance->c5_b_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c5_bored_address, &chartInstance->c5_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c5_pose_address, &chartInstance->c5_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c5_randomP_address, &chartInstance->c5_randomP_index);
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

void sf_c5_AtomicGloveBradImitateSmile_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3684889933U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1834257604U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(544280138U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3034030675U);
}

mxArray *sf_c5_AtomicGloveBradImitateSmile_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kd5AcKyffVTGQGXU1b4rVG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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

mxArray *sf_c5_AtomicGloveBradImitateSmile_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_AtomicGloveBradImitateSmile_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_AtomicGloveBradImitateSmile(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c5_AtomicGloveBradImitateSmile\",},{M[9],M[0],T\"is_c5_AtomicGloveBradImitateSmile\",},{M[11],M[16],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[10],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_AtomicGloveBradImitateSmile_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AtomicGloveBradImitateSmileMachineNumber_,
           5,
           4,
           6,
           0,
           8,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation
          (_AtomicGloveBradImitateSmileMachineNumber_,chartInstance->chartNumber,
           chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _AtomicGloveBradImitateSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AtomicGloveBradImitateSmileMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"bored");
          _SFD_SET_DATA_PROPS(1,11,0,0,"BOREDOMT");
          _SFD_SET_DATA_PROPS(2,11,0,0,"randomP");
          _SFD_SET_DATA_PROPS(3,11,0,0,"pose");
          _SFD_SET_DATA_PROPS(4,11,0,0,"b");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredPoseSc5_AtomicGloveBradImitateSmile",0,-1,
                             2805);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",2805,-1,2976);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",2976,-1,3138);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3138,-1,3305);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",3305,-1,3474);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",3474,-1,3643);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",3643,-1,3824);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",3824,-1,4003);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",4003,-1,4172);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",4172,-1,4339);
        _SFD_CV_INIT_EML_FCN(0,10,"aFcnTruthTableAction_10",4339,-1,4508);
        _SFD_CV_INIT_EML_FCN(0,11,"aFcnTruthTableAction_11",4508,-1,4674);
        _SFD_CV_INIT_EML_IF(0,1,0,1577,1607,1638,2803);
        _SFD_CV_INIT_EML_IF(0,1,1,1638,1672,1703,2803);
        _SFD_CV_INIT_EML_IF(0,1,2,1703,1737,1768,2803);
        _SFD_CV_INIT_EML_IF(0,1,3,1768,1802,1833,2803);
        _SFD_CV_INIT_EML_IF(0,1,4,1833,1867,1898,2803);
        _SFD_CV_INIT_EML_IF(0,1,5,1898,1932,1964,2803);
        _SFD_CV_INIT_EML_IF(0,1,6,1964,1998,2029,2803);
        _SFD_CV_INIT_EML_IF(0,1,7,2029,2063,2094,2803);
        _SFD_CV_INIT_EML_IF(0,1,8,2094,2128,2159,2803);
        _SFD_CV_INIT_EML_IF(0,1,9,2159,2194,2226,2803);
        _SFD_CV_INIT_EML_IF(0,1,10,2226,2261,2293,2803);
        _SFD_CV_INIT_EML_IF(0,1,11,2293,2328,2359,2803);
        _SFD_CV_INIT_EML_IF(0,1,12,2359,2394,2425,2803);
        _SFD_CV_INIT_EML_IF(0,1,13,2425,2460,2491,2803);
        _SFD_CV_INIT_EML_IF(0,1,14,2491,2526,2557,2803);
        _SFD_CV_INIT_EML_IF(0,1,15,2557,2592,2623,2803);
        _SFD_CV_INIT_EML_IF(0,1,16,2623,2658,2689,2803);
        _SFD_CV_INIT_EML_IF(0,1,17,2689,2724,2755,2803);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,27,1,27);

        {
          static int condStart[] = { 2, 17 };

          static int condEnd[] = { 14, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,27,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_bored_address);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c5_BOREDOMT_address);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c5_randomP_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_pose_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_b_address);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AtomicGloveBradImitateSmileMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "HxJCdlzRxAZoqVAVdXwxAD";
}

static void sf_opaque_initialize_c5_AtomicGloveBradImitateSmile(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_AtomicGloveBradImitateSmileInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
  initialize_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_AtomicGloveBradImitateSmile(void
  *chartInstanceVar)
{
  enable_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_AtomicGloveBradImitateSmile(void
  *chartInstanceVar)
{
  disable_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_AtomicGloveBradImitateSmile(void
  *chartInstanceVar)
{
  sf_gateway_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_AtomicGloveBradImitateSmile
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_AtomicGloveBradImitateSmile();/* state var info */
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

extern void sf_internal_set_sim_state_c5_AtomicGloveBradImitateSmile(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_AtomicGloveBradImitateSmile();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_AtomicGloveBradImitateSmile
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c5_AtomicGloveBradImitateSmile(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c5_AtomicGloveBradImitateSmile(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AtomicGloveBradImitateSmile_optimization_info();
    }

    finalize_c5_AtomicGloveBradImitateSmile
      ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_AtomicGloveBradImitateSmile
    ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_AtomicGloveBradImitateSmile(SimStruct *S)
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
    initialize_params_c5_AtomicGloveBradImitateSmile
      ((SFc5_AtomicGloveBradImitateSmileInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_AtomicGloveBradImitateSmile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AtomicGloveBradImitateSmile_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,5,1);
    if (chartIsInlinable) {
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2833670513U));
  ssSetChecksum1(S,(962142131U));
  ssSetChecksum2(S,(3891908542U));
  ssSetChecksum3(S,(2278553484U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_AtomicGloveBradImitateSmile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c5_AtomicGloveBradImitateSmile(SimStruct *S)
{
  SFc5_AtomicGloveBradImitateSmileInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_AtomicGloveBradImitateSmileInstanceStruct *)utMalloc
    (sizeof(SFc5_AtomicGloveBradImitateSmileInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_AtomicGloveBradImitateSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_AtomicGloveBradImitateSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_AtomicGloveBradImitateSmile;
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

void c5_AtomicGloveBradImitateSmile_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_AtomicGloveBradImitateSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_AtomicGloveBradImitateSmile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_AtomicGloveBradImitateSmile(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_AtomicGloveBradImitateSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
