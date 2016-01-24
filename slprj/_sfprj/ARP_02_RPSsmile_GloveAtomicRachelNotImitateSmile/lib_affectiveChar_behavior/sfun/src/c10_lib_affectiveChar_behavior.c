/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c10_lib_affectiveChar_behavior.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c10_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c10_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c10_IN_stateBoredPose          ((uint8_T)1U)
#define c10_IN_stateRandomPose         ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c10_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c10_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c10_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_st);
static void c10_set_sim_state_side_effects_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_enter_atomic_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_enter_internal_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_exit_internal_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_initc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_enter_atomic_stateRandomPose
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_b_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_c_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_d_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_e_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_f_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_g_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static real_T c10_rand(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static real_T c10_eml_rand(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c10_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_d_state[625]);
static void c10_twister_state_vector
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed, uint32_T c10_b_mt[625]);
static void c10_b_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_d_state[625], uint32_T c10_e_state[625], real_T *c10_r);
static void c10_eml_error(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_b_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static boolean_T c10_c_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[256]);
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
static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_m_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_n_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_activate_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_deactivate_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_increment_counters_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_reset_counters_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c10_sendBMLc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T
   c10_arg[256]);
static void c10_idlePoseRachelTablec10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T
   c10_bmlID, real_T c10_poseBML[256]);
static void c10_sendBML(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c10_b_sendBML(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static const mxArray *c10_o_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int8_T c10_e_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_p_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_f_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_q_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static uint8_T c10_g_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_b_tp_stateRandomPose, const char_T *c10_identifier);
static uint8_T c10_h_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint32_T c10_i_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_b_method, const char_T *c10_identifier);
static uint32_T c10_j_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static uint32_T c10_k_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier);
static uint32_T c10_l_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_m_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[625]);
static void c10_n_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[625]);
static void c10_o_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[2]);
static void c10_p_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[2]);
static const mxArray *c10_q_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier);
static const mxArray *c10_r_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_updateDataWrittenToVector
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex);
static void c10_b_twister_state_vector
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed);
static real_T c10_c_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_d_state[625]);
static real_T c10_get_BOREDOM_THRESHOLD
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b);
static void c10_set_BOREDOM_THRESHOLD
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b,
   real_T c10_c);
static real_T *c10_access_BOREDOM_THRESHOLD
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b);
static real_T c10_get_boredom(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_boredom(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_boredom(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_interest(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_interest(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_interest
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b);
static real_T c10_get_isPosing(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_isPosing(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_isPosing
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b);
static real_T c10_get_randPoseChance
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b);
static void c10_set_randPoseChance
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b,
   real_T c10_c);
static real_T *c10_access_randPoseChance
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b);
static void init_dsm_address_info(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_update_debugger_state_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c10_prevAniVal;
  c10_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c10_is_active_c10_lib_affectiveChar_behavior == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_lib_affectiveChar_behavior ==
      c10_IN_stateRandomPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_lib_affectiveChar_behavior ==
      c10_IN_stateBoredPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  }

  _SFD_SET_ANIMATION(c10_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  uint32_T c10_hoistedGlobal;
  uint32_T c10_u;
  const mxArray *c10_b_y = NULL;
  uint32_T c10_b_hoistedGlobal;
  uint32_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  int32_T c10_i0;
  uint32_T c10_c_u[625];
  const mxArray *c10_d_y = NULL;
  int32_T c10_i1;
  uint32_T c10_d_u[2];
  const mxArray *c10_e_y = NULL;
  uint8_T c10_c_hoistedGlobal;
  uint8_T c10_e_u;
  const mxArray *c10_f_y = NULL;
  uint8_T c10_d_hoistedGlobal;
  uint8_T c10_f_u;
  const mxArray *c10_g_y = NULL;
  uint8_T c10_e_hoistedGlobal;
  uint8_T c10_g_u;
  const mxArray *c10_h_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(7, 1), false);
  c10_hoistedGlobal = chartInstance->c10_method;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  if (!chartInstance->c10_method_not_empty) {
    sf_mex_assign(&c10_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = chartInstance->c10_state;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  if (!chartInstance->c10_state_not_empty) {
    sf_mex_assign(&c10_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c10_y, 1, c10_c_y);
  for (c10_i0 = 0; c10_i0 < 625; c10_i0++) {
    c10_c_u[c10_i0] = chartInstance->c10_c_state[c10_i0];
  }

  c10_d_y = NULL;
  if (!chartInstance->c10_c_state_not_empty) {
    sf_mex_assign(&c10_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_c_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c10_y, 2, c10_d_y);
  for (c10_i1 = 0; c10_i1 < 2; c10_i1++) {
    c10_d_u[c10_i1] = chartInstance->c10_b_state[c10_i1];
  }

  c10_e_y = NULL;
  if (!chartInstance->c10_b_state_not_empty) {
    sf_mex_assign(&c10_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c10_e_y, sf_mex_create("y", c10_d_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c10_y, 3, c10_e_y);
  c10_c_hoistedGlobal =
    chartInstance->c10_is_active_c10_lib_affectiveChar_behavior;
  c10_e_u = c10_c_hoistedGlobal;
  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", &c10_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 4, c10_f_y);
  c10_d_hoistedGlobal = chartInstance->c10_is_c10_lib_affectiveChar_behavior;
  c10_f_u = c10_d_hoistedGlobal;
  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_create("y", &c10_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 5, c10_g_y);
  c10_e_hoistedGlobal = chartInstance->c10_temporalCounter_i1;
  c10_g_u = c10_e_hoistedGlobal;
  c10_h_y = NULL;
  sf_mex_assign(&c10_h_y, sf_mex_create("y", &c10_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 6, c10_h_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_st)
{
  const mxArray *c10_u;
  uint32_T c10_uv0[625];
  int32_T c10_i2;
  uint32_T c10_uv1[2];
  int32_T c10_i3;
  c10_u = sf_mex_dup(c10_st);
  chartInstance->c10_method = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "method");
  chartInstance->c10_state = c10_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 1)), "state");
  c10_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
    "state", c10_uv0);
  for (c10_i2 = 0; c10_i2 < 625; c10_i2++) {
    chartInstance->c10_c_state[c10_i2] = c10_uv0[c10_i2];
  }

  c10_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 3)),
    "state", c10_uv1);
  for (c10_i3 = 0; c10_i3 < 2; c10_i3++) {
    chartInstance->c10_b_state[c10_i3] = c10_uv1[c10_i3];
  }

  chartInstance->c10_is_active_c10_lib_affectiveChar_behavior =
    c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 4)),
    "is_active_c10_lib_affectiveChar_behavior");
  chartInstance->c10_is_c10_lib_affectiveChar_behavior = c10_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 5)),
     "is_c10_lib_affectiveChar_behavior");
  chartInstance->c10_temporalCounter_i1 = c10_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c10_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c10_setSimStateSideEffectsInfo,
                c10_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c10_u);
  chartInstance->c10_doSetSimStateSideEffects = 1U;
  c10_update_debugger_state_c10_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void c10_set_sim_state_side_effects_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c10_doSetSimStateSideEffects != 0) {
    if (chartInstance->c10_is_c10_lib_affectiveChar_behavior ==
        c10_IN_stateBoredPose) {
      chartInstance->c10_tp_stateBoredPose = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_stateBoredPose = 0U;
    }

    if (chartInstance->c10_is_c10_lib_affectiveChar_behavior ==
        c10_IN_stateRandomPose) {
      chartInstance->c10_tp_stateRandomPose = 1U;
    } else {
      chartInstance->c10_tp_stateRandomPose = 0U;
    }

    chartInstance->c10_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c10_setSimStateSideEffectsInfo);
}

static void sf_gateway_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c10_set_sim_state_side_effects_c10_lib_affectiveChar_behavior(chartInstance);
}

static void c10_enter_atomic_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
  chartInstance->c10_is_active_c10_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
}

static void c10_enter_internal_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  chartInstance->c10_isStable = false;
  chartInstance->c10_is_c10_lib_affectiveChar_behavior = c10_IN_stateRandomPose;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  chartInstance->c10_tp_stateRandomPose = 1U;
  c10_enter_atomic_stateRandomPose(chartInstance);
}

static void c10_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
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
  real_T c10_r;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_dv0[256];
  int32_T c10_i4;
  real_T c10_arg[256];
  int32_T c10_i5;
  int32_T c10_i6;
  int32_T c10_i7;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_c_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 1.0;
  boolean_T c10_d_out;
  real_T (*c10_b_arg)[256];
  boolean_T guard1 = false;
  c10_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_isStable = true;
  switch (chartInstance->c10_is_c10_lib_affectiveChar_behavior) {
   case c10_IN_stateBoredPose:
    CV_CHART_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_l_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_out = CV_EML_IF(2, 0, 0, (chartInstance->c10_sfEvent == c10_event_secs) &&
                        (chartInstance->c10_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateBoredPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_lib_affectiveChar_behavior =
        c10_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateRandomPose = 1U;
      c10_enter_atomic_stateRandomPose(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateRandomPose:
    CV_CHART_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_o_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, c10_get_randPoseChance(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(5, 0, 1, c10_get_isPosing(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c10_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c10_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateRandomPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_lib_affectiveChar_behavior =
        c10_IN_stateBoredPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_stateBoredPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_k_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_r = c10_rand(chartInstance);
      c10_x = c10_r * 18.0;
      c10_b_x = c10_x;
      c10_b_x = muDoubleScalarFloor(c10_b_x);
      c10_r = 1.0 + c10_b_x;
      c10_idlePoseRachelTablec10_lib_affectiveChar_behavior(chartInstance, c10_r,
        c10_dv0);
      for (c10_i4 = 0; c10_i4 < 256; c10_i4++) {
        c10_arg[c10_i4] = c10_dv0[c10_i4];
      }

      for (c10_i5 = 0; c10_i5 < 256; c10_i5++) {
        _SFD_DATA_RANGE_CHECK(c10_arg[c10_i5], 5U);
      }

      _SFD_SET_DATA_VALUE_PTR(5U, c10_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c10_arg, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c10_sfEvent);
      for (c10_i6 = 0; c10_i6 < 256; c10_i6++) {
        (*c10_b_arg)[c10_i6] = c10_arg[c10_i6];
      }

      for (c10_i7 = 0; c10_i7 < 256; c10_i7++) {
        _SFD_DATA_RANGE_CHECK((*c10_b_arg)[c10_i7], 5U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(5U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_m_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      c10_c_out = CV_EML_IF(3, 0, 0, c10_get_randPoseChance(chartInstance, 0) !=
                            1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c10_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_stateRandomPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_lib_affectiveChar_behavior =
          c10_IN_stateRandomPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_stateRandomPose = 1U;
        c10_enter_atomic_stateRandomPose(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_n_debug_family_names,
          c10_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_out, 2U,
          c10_c_sf_marshallOut, c10_c_sf_marshallIn);
        c10_d_out = CV_EML_IF(1, 0, 0, c10_get_isPosing(chartInstance, 0) != 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c10_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
          chartInstance->c10_tp_stateRandomPose = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
          chartInstance->c10_isStable = false;
          chartInstance->c10_is_c10_lib_affectiveChar_behavior =
            c10_IN_stateRandomPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
          chartInstance->c10_tp_stateRandomPose = 1U;
          c10_enter_atomic_stateRandomPose(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c10_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c10_is_c10_lib_affectiveChar_behavior =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
}

static void c10_exit_internal_c10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  switch (chartInstance->c10_is_c10_lib_affectiveChar_behavior) {
   case c10_IN_stateBoredPose:
    CV_CHART_EVAL(1, 0, 1);
    chartInstance->c10_tp_stateBoredPose = 0U;
    chartInstance->c10_is_c10_lib_affectiveChar_behavior =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateRandomPose:
    CV_CHART_EVAL(1, 0, 2);
    chartInstance->c10_tp_stateRandomPose = 0U;
    chartInstance->c10_is_c10_lib_affectiveChar_behavior =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c10_is_c10_lib_affectiveChar_behavior =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
    break;
  }
}

static void c10_initc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_method_not_empty = false;
  chartInstance->c10_state_not_empty = false;
  chartInstance->c10_b_state_not_empty = false;
  chartInstance->c10_c_state_not_empty = false;
  chartInstance->c10_doSetSimStateSideEffects = 0U;
  chartInstance->c10_setSimStateSideEffectsInfo = NULL;
  chartInstance->c10_tp_stateBoredPose = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateRandomPose = 0U;
  chartInstance->c10_is_active_c10_lib_affectiveChar_behavior = 0U;
  chartInstance->c10_is_c10_lib_affectiveChar_behavior = c10_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_enter_atomic_stateRandomPose
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[2];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 0.0;
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_hoistedGlobal;
  real_T c10_lowhigh[2];
  real_T c10_low;
  real_T c10_high;
  int32_T c10_i8;
  static char_T c10_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c10_u[26];
  const mxArray *c10_y = NULL;
  real_T c10_s;
  real_T c10_r;
  real_T c10_x;
  real_T c10_b_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_i_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  c10_set_interest(chartInstance, 0, c10_get_BOREDOM_THRESHOLD(chartInstance, 0)
                   - c10_get_boredom(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 2);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_j_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  c10_hoistedGlobal = c10_get_interest(chartInstance, 0);
  c10_lowhigh[0] = 1.0;
  c10_lowhigh[1] = c10_hoistedGlobal;
  c10_low = c10_lowhigh[0];
  c10_high = c10_lowhigh[1];
  if (c10_low <= c10_high) {
  } else {
    for (c10_i8 = 0; c10_i8 < 26; c10_i8++) {
      c10_u[c10_i8] = c10_cv0[c10_i8];
    }

    c10_y = NULL;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c10_y));
  }

  c10_s = (c10_high - c10_low) + 1.0;
  c10_r = c10_rand(chartInstance);
  c10_x = c10_r * c10_s;
  c10_b_x = c10_x;
  c10_b_x = muDoubleScalarFloor(c10_b_x);
  c10_r = c10_low + c10_b_x;
  c10_set_randPoseChance(chartInstance, 0, c10_r);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[93];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[93];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i9;
  static char_T c10_cv1[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i10;
  static real_T c10_dv1[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i11;
  int32_T c10_i12;
  int32_T c10_i13;
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
  for (c10_i9 = 0; c10_i9 < 93; c10_i9++) {
    c10_mystr[c10_i9] = c10_cv1[c10_i9];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i10 = 0; c10_i10 < 93; c10_i10++) {
    c10_arr[c10_i10] = c10_dv1[c10_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i11 = 0; c10_i11 < 256; c10_i11++) {
    c10_tt[c10_i11] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i12 = 0; c10_i12 < 93; c10_i12++) {
    c10_tt[c10_i12] = c10_arr[c10_i12];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i13 = 0; c10_i13 < 256; c10_i13++) {
    c10_myarr256[c10_i13] = c10_tt[c10_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_b_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[104];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[104];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i14;
  static char_T c10_cv2[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'R', 'a',
    'c', 'h', 'e', 'l', '_', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '@', 'I', 'd',
    'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c', 'h', 'C', 'h', 'e',
    's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c10_i15;
  static real_T c10_dv2[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 82.0, 97.0,
    99.0, 104.0, 101.0, 108.0, 95.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0,
    100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0, 114.0,
    97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0, 49.0, 34.0,
    32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c10_i16;
  int32_T c10_i17;
  int32_T c10_i18;
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
  for (c10_i14 = 0; c10_i14 < 104; c10_i14++) {
    c10_mystr[c10_i14] = c10_cv2[c10_i14];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i15 = 0; c10_i15 < 104; c10_i15++) {
    c10_arr[c10_i15] = c10_dv2[c10_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i16 = 0; c10_i16 < 256; c10_i16++) {
    c10_tt[c10_i16] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i17 = 0; c10_i17 < 104; c10_i17++) {
    c10_tt[c10_i17] = c10_arr[c10_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i18 = 0; c10_i18 < 256; c10_i18++) {
    c10_myarr256[c10_i18] = c10_tt[c10_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_c_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[93];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[93];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i19;
  static char_T c10_cv3[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i20;
  static real_T c10_dv3[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i21;
  int32_T c10_i22;
  int32_T c10_i23;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_d_debug_family_names,
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
  for (c10_i19 = 0; c10_i19 < 93; c10_i19++) {
    c10_mystr[c10_i19] = c10_cv3[c10_i19];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i20 = 0; c10_i20 < 93; c10_i20++) {
    c10_arr[c10_i20] = c10_dv3[c10_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i21 = 0; c10_i21 < 256; c10_i21++) {
    c10_tt[c10_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i22 = 0; c10_i22 < 93; c10_i22++) {
    c10_tt[c10_i22] = c10_arr[c10_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i23 = 0; c10_i23 < 256; c10_i23++) {
    c10_myarr256[c10_i23] = c10_tt[c10_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_d_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[95];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[95];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i24;
  static char_T c10_cv4[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i25;
  static real_T c10_dv4[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i26;
  int32_T c10_i27;
  int32_T c10_i28;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_e_debug_family_names,
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
  for (c10_i24 = 0; c10_i24 < 95; c10_i24++) {
    c10_mystr[c10_i24] = c10_cv4[c10_i24];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i25 = 0; c10_i25 < 95; c10_i25++) {
    c10_arr[c10_i25] = c10_dv4[c10_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i26 = 0; c10_i26 < 256; c10_i26++) {
    c10_tt[c10_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i27 = 0; c10_i27 < 95; c10_i27++) {
    c10_tt[c10_i27] = c10_arr[c10_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i28 = 0; c10_i28 < 256; c10_i28++) {
    c10_myarr256[c10_i28] = c10_tt[c10_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_e_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[88];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[88];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i29;
  static char_T c10_cv5[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c10_i30;
  static real_T c10_dv5[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i31;
  int32_T c10_i32;
  int32_T c10_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_f_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i29 = 0; c10_i29 < 88; c10_i29++) {
    c10_mystr[c10_i29] = c10_cv5[c10_i29];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i30 = 0; c10_i30 < 88; c10_i30++) {
    c10_arr[c10_i30] = c10_dv5[c10_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i31 = 0; c10_i31 < 256; c10_i31++) {
    c10_tt[c10_i31] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i32 = 0; c10_i32 < 88; c10_i32++) {
    c10_tt[c10_i32] = c10_arr[c10_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i33 = 0; c10_i33 < 256; c10_i33++) {
    c10_myarr256[c10_i33] = c10_tt[c10_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_f_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[93];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[93];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i34;
  static char_T c10_cv6[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i35;
  static real_T c10_dv6[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i36;
  int32_T c10_i37;
  int32_T c10_i38;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_g_debug_family_names,
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
  for (c10_i34 = 0; c10_i34 < 93; c10_i34++) {
    c10_mystr[c10_i34] = c10_cv6[c10_i34];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i35 = 0; c10_i35 < 93; c10_i35++) {
    c10_arr[c10_i35] = c10_dv6[c10_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i36 = 0; c10_i36 < 256; c10_i36++) {
    c10_tt[c10_i36] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i37 = 0; c10_i37 < 93; c10_i37++) {
    c10_tt[c10_i37] = c10_arr[c10_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i38 = 0; c10_i38 < 256; c10_i38++) {
    c10_myarr256[c10_i38] = c10_tt[c10_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_g_encStr2Arr(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[97];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[97];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i39;
  static char_T c10_cv7[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i40;
  static real_T c10_dv7[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i41;
  int32_T c10_i42;
  int32_T c10_i43;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_h_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i39 = 0; c10_i39 < 97; c10_i39++) {
    c10_mystr[c10_i39] = c10_cv7[c10_i39];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i40 = 0; c10_i40 < 97; c10_i40++) {
    c10_arr[c10_i40] = c10_dv7[c10_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i41 = 0; c10_i41 < 256; c10_i41++) {
    c10_tt[c10_i41] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i42 = 0; c10_i42 < 97; c10_i42++) {
    c10_tt[c10_i42] = c10_arr[c10_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i43 = 0; c10_i43 < 256; c10_i43++) {
    c10_myarr256[c10_i43] = c10_tt[c10_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c10_rand(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  return c10_eml_rand(chartInstance);
}

static real_T c10_eml_rand(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  real_T c10_r;
  uint32_T c10_hoistedGlobal;
  uint32_T c10_d_state;
  uint32_T c10_e_state;
  uint32_T c10_s;
  uint32_T c10_u0;
  uint32_T c10_hi;
  uint32_T c10_lo;
  uint32_T c10_test1;
  uint32_T c10_test2;
  uint32_T c10_f_state;
  real_T c10_b_r;
  real_T c10_d0;
  int32_T c10_i44;
  uint32_T c10_icng;
  uint32_T c10_jsr;
  uint32_T c10_u1;
  uint32_T c10_u2;
  uint32_T c10_ui;
  uint32_T c10_b_ui;
  real_T c10_c_r;
  real_T c10_d1;
  uint32_T c10_uv2[625];
  int32_T c10_i45;
  real_T c10_d2;
  if (!chartInstance->c10_method_not_empty) {
    chartInstance->c10_method = 7U;
    chartInstance->c10_method_not_empty = true;
  }

  if (chartInstance->c10_method == 4U) {
    if (!chartInstance->c10_state_not_empty) {
      chartInstance->c10_state = 1144108930U;
      chartInstance->c10_state_not_empty = true;
    }

    c10_hoistedGlobal = chartInstance->c10_state;
    c10_d_state = c10_hoistedGlobal;
    c10_e_state = c10_d_state;
    c10_s = c10_e_state;
    c10_u0 = 127773U;
    if (c10_u0 == 0U) {
      c10_hi = MAX_uint32_T;
    } else {
      c10_hi = c10_s / c10_u0;
    }

    c10_lo = c10_s - c10_hi * 127773U;
    c10_test1 = 16807U * c10_lo;
    c10_test2 = 2836U * c10_hi;
    if (c10_test1 < c10_test2) {
      c10_f_state = (c10_test1 - c10_test2) + 2147483647U;
    } else {
      c10_f_state = c10_test1 - c10_test2;
    }

    c10_b_r = (real_T)c10_f_state * 4.6566128752457969E-10;
    c10_e_state = c10_f_state;
    c10_d0 = c10_b_r;
    chartInstance->c10_state = c10_e_state;
    c10_r = c10_d0;
  } else if (chartInstance->c10_method == 5U) {
    if (!chartInstance->c10_b_state_not_empty) {
      for (c10_i44 = 0; c10_i44 < 2; c10_i44++) {
        chartInstance->c10_b_state[c10_i44] = 362436069U + 158852560U *
          (uint32_T)c10_i44;
      }

      chartInstance->c10_b_state_not_empty = true;
    }

    c10_icng = chartInstance->c10_b_state[0];
    c10_jsr = chartInstance->c10_b_state[1];
    c10_u1 = c10_jsr;
    c10_u2 = c10_icng;
    c10_u2 = 69069U * c10_u2 + 1234567U;
    c10_u1 ^= c10_u1 << 13;
    c10_u1 ^= c10_u1 >> 17;
    c10_u1 ^= c10_u1 << 5;
    c10_ui = c10_u2 + c10_u1;
    chartInstance->c10_b_state[0] = c10_u2;
    chartInstance->c10_b_state[1] = c10_u1;
    c10_b_ui = c10_ui;
    c10_c_r = (real_T)c10_b_ui * 2.328306436538696E-10;
    c10_d1 = c10_c_r;
    c10_r = c10_d1;
  } else {
    if (!chartInstance->c10_c_state_not_empty) {
      c10_eml_rand_mt19937ar(chartInstance, c10_uv2);
      for (c10_i45 = 0; c10_i45 < 625; c10_i45++) {
        chartInstance->c10_c_state[c10_i45] = c10_uv2[c10_i45];
      }

      chartInstance->c10_c_state_not_empty = true;
    }

    c10_d2 = c10_c_eml_rand_mt19937ar(chartInstance, chartInstance->c10_c_state);
    c10_r = c10_d2;
  }

  return c10_r;
}

static void c10_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_d_state[625])
{
  real_T c10_d3;
  int32_T c10_i46;
  c10_d3 = 5489.0;
  for (c10_i46 = 0; c10_i46 < 625; c10_i46++) {
    c10_d_state[c10_i46] = 0U;
  }

  c10_b_twister_state_vector(chartInstance, c10_d_state, c10_d3);
}

static void c10_twister_state_vector
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed, uint32_T c10_b_mt[625])
{
  int32_T c10_i47;
  for (c10_i47 = 0; c10_i47 < 625; c10_i47++) {
    c10_b_mt[c10_i47] = c10_mt[c10_i47];
  }

  c10_b_twister_state_vector(chartInstance, c10_b_mt, c10_seed);
}

static void c10_b_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_d_state[625], uint32_T c10_e_state[625], real_T *c10_r)
{
  int32_T c10_i48;
  for (c10_i48 = 0; c10_i48 < 625; c10_i48++) {
    c10_e_state[c10_i48] = c10_d_state[c10_i48];
  }

  *c10_r = c10_c_eml_rand_mt19937ar(chartInstance, c10_e_state);
}

static void c10_eml_error(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  int32_T c10_i49;
  static char_T c10_cv8[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c10_u[37];
  const mxArray *c10_y = NULL;
  (void)chartInstance;
  for (c10_i49 = 0; c10_i49 < 37; c10_i49++) {
    c10_u[c10_i49] = c10_cv8[c10_i49];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c10_y));
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, c10_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\4-6-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i50;
  real_T c10_b_inData[256];
  int32_T c10_i51;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i50 = 0; c10_i50 < 256; c10_i50++) {
    c10_b_inData[c10_i50] = (*(real_T (*)[256])c10_inData)[c10_i50];
  }

  for (c10_i51 = 0; c10_i51 < 256; c10_i51++) {
    c10_u[c10_i51] = c10_b_inData[c10_i51];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256])
{
  real_T c10_dv8[256];
  int32_T c10_i52;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv8, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c10_i52 = 0; c10_i52 < 256; c10_i52++) {
    c10_y[c10_i52] = c10_dv8[c10_i52];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_poseBML;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[256];
  int32_T c10_i53;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_poseBML = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_poseBML), &c10_thisId,
                       c10_y);
  sf_mex_destroy(&c10_poseBML);
  for (c10_i53 = 0; c10_i53 < 256; c10_i53++) {
    (*(real_T (*)[256])c10_outData)[c10_i53] = c10_y[c10_i53];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_b_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d4;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d4, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d4;
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
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_bmlID = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_bmlID),
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
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(boolean_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static boolean_T c10_c_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
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
  const mxArray *c10_aVarTruthTableCondition_18;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  boolean_T c10_y;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_aVarTruthTableCondition_18 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_aVarTruthTableCondition_18), &c10_thisId);
  sf_mex_destroy(&c10_aVarTruthTableCondition_18);
  *(boolean_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i54;
  real_T c10_b_inData[256];
  int32_T c10_i55;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i54 = 0; c10_i54 < 256; c10_i54++) {
    c10_b_inData[c10_i54] = (*(real_T (*)[256])c10_inData)[c10_i54];
  }

  for (c10_i55 = 0; c10_i55 < 256; c10_i55++) {
    c10_u[c10_i55] = c10_b_inData[c10_i55];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[256])
{
  real_T c10_dv9[256];
  int32_T c10_i56;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv9, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c10_i56 = 0; c10_i56 < 256; c10_i56++) {
    c10_y[c10_i56] = c10_dv9[c10_i56];
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
  int32_T c10_i57;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_myarr256 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_myarr256), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_myarr256);
  for (c10_i57 = 0; c10_i57 < 256; c10_i57++) {
    (*(real_T (*)[256])c10_outData)[c10_i57] = c10_y[c10_i57];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i58;
  char_T c10_b_inData[93];
  int32_T c10_i59;
  char_T c10_u[93];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i58 = 0; c10_i58 < 93; c10_i58++) {
    c10_b_inData[c10_i58] = (*(char_T (*)[93])c10_inData)[c10_i58];
  }

  for (c10_i59 = 0; c10_i59 < 93; c10_i59++) {
    c10_u[c10_i59] = c10_b_inData[c10_i59];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 93),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i60;
  real_T c10_b_inData[93];
  int32_T c10_i61;
  real_T c10_u[93];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i60 = 0; c10_i60 < 93; c10_i60++) {
    c10_b_inData[c10_i60] = (*(real_T (*)[93])c10_inData)[c10_i60];
  }

  for (c10_i61 = 0; c10_i61 < 93; c10_i61++) {
    c10_u[c10_i61] = c10_b_inData[c10_i61];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i62;
  char_T c10_b_inData[104];
  int32_T c10_i63;
  char_T c10_u[104];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i62 = 0; c10_i62 < 104; c10_i62++) {
    c10_b_inData[c10_i62] = (*(char_T (*)[104])c10_inData)[c10_i62];
  }

  for (c10_i63 = 0; c10_i63 < 104; c10_i63++) {
    c10_u[c10_i63] = c10_b_inData[c10_i63];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 104),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i64;
  real_T c10_b_inData[104];
  int32_T c10_i65;
  real_T c10_u[104];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i64 = 0; c10_i64 < 104; c10_i64++) {
    c10_b_inData[c10_i64] = (*(real_T (*)[104])c10_inData)[c10_i64];
  }

  for (c10_i65 = 0; c10_i65 < 104; c10_i65++) {
    c10_u[c10_i65] = c10_b_inData[c10_i65];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 104), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i66;
  char_T c10_b_inData[95];
  int32_T c10_i67;
  char_T c10_u[95];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i66 = 0; c10_i66 < 95; c10_i66++) {
    c10_b_inData[c10_i66] = (*(char_T (*)[95])c10_inData)[c10_i66];
  }

  for (c10_i67 = 0; c10_i67 < 95; c10_i67++) {
    c10_u[c10_i67] = c10_b_inData[c10_i67];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 95),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i68;
  real_T c10_b_inData[95];
  int32_T c10_i69;
  real_T c10_u[95];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i68 = 0; c10_i68 < 95; c10_i68++) {
    c10_b_inData[c10_i68] = (*(real_T (*)[95])c10_inData)[c10_i68];
  }

  for (c10_i69 = 0; c10_i69 < 95; c10_i69++) {
    c10_u[c10_i69] = c10_b_inData[c10_i69];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i70;
  char_T c10_b_inData[88];
  int32_T c10_i71;
  char_T c10_u[88];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i70 = 0; c10_i70 < 88; c10_i70++) {
    c10_b_inData[c10_i70] = (*(char_T (*)[88])c10_inData)[c10_i70];
  }

  for (c10_i71 = 0; c10_i71 < 88; c10_i71++) {
    c10_u[c10_i71] = c10_b_inData[c10_i71];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 88),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i72;
  real_T c10_b_inData[88];
  int32_T c10_i73;
  real_T c10_u[88];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i72 = 0; c10_i72 < 88; c10_i72++) {
    c10_b_inData[c10_i72] = (*(real_T (*)[88])c10_inData)[c10_i72];
  }

  for (c10_i73 = 0; c10_i73 < 88; c10_i73++) {
    c10_u[c10_i73] = c10_b_inData[c10_i73];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_m_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i74;
  char_T c10_b_inData[97];
  int32_T c10_i75;
  char_T c10_u[97];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i74 = 0; c10_i74 < 97; c10_i74++) {
    c10_b_inData[c10_i74] = (*(char_T (*)[97])c10_inData)[c10_i74];
  }

  for (c10_i75 = 0; c10_i75 < 97; c10_i75++) {
    c10_u[c10_i75] = c10_b_inData[c10_i75];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 97),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_n_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i76;
  real_T c10_b_inData[97];
  int32_T c10_i77;
  real_T c10_u[97];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i76 = 0; c10_i76 < 97; c10_i76++) {
    c10_b_inData[c10_i76] = (*(real_T (*)[97])c10_inData)[c10_i76];
  }

  for (c10_i77 = 0; c10_i77 < 97; c10_i77++) {
    c10_u[c10_i77] = c10_b_inData[c10_i77];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

const mxArray *sf_c10_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c10_info_helper(&c10_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(const mxArray **c10_info)
{
  const mxArray *c10_rhs0 = NULL;
  const mxArray *c10_lhs0 = NULL;
  const mxArray *c10_rhs1 = NULL;
  const mxArray *c10_lhs1 = NULL;
  const mxArray *c10_rhs2 = NULL;
  const mxArray *c10_lhs2 = NULL;
  const mxArray *c10_rhs3 = NULL;
  const mxArray *c10_lhs3 = NULL;
  const mxArray *c10_rhs4 = NULL;
  const mxArray *c10_lhs4 = NULL;
  const mxArray *c10_rhs5 = NULL;
  const mxArray *c10_lhs5 = NULL;
  const mxArray *c10_rhs6 = NULL;
  const mxArray *c10_lhs6 = NULL;
  const mxArray *c10_rhs7 = NULL;
  const mxArray *c10_lhs7 = NULL;
  const mxArray *c10_rhs8 = NULL;
  const mxArray *c10_lhs8 = NULL;
  const mxArray *c10_rhs9 = NULL;
  const mxArray *c10_lhs9 = NULL;
  const mxArray *c10_rhs10 = NULL;
  const mxArray *c10_lhs10 = NULL;
  const mxArray *c10_rhs11 = NULL;
  const mxArray *c10_lhs11 = NULL;
  const mxArray *c10_rhs12 = NULL;
  const mxArray *c10_lhs12 = NULL;
  const mxArray *c10_rhs13 = NULL;
  const mxArray *c10_lhs13 = NULL;
  const mxArray *c10_rhs14 = NULL;
  const mxArray *c10_lhs14 = NULL;
  const mxArray *c10_rhs15 = NULL;
  const mxArray *c10_lhs15 = NULL;
  const mxArray *c10_rhs16 = NULL;
  const mxArray *c10_lhs16 = NULL;
  const mxArray *c10_rhs17 = NULL;
  const mxArray *c10_lhs17 = NULL;
  const mxArray *c10_rhs18 = NULL;
  const mxArray *c10_lhs18 = NULL;
  const mxArray *c10_rhs19 = NULL;
  const mxArray *c10_lhs19 = NULL;
  const mxArray *c10_rhs20 = NULL;
  const mxArray *c10_lhs20 = NULL;
  const mxArray *c10_rhs21 = NULL;
  const mxArray *c10_lhs21 = NULL;
  const mxArray *c10_rhs22 = NULL;
  const mxArray *c10_lhs22 = NULL;
  const mxArray *c10_rhs23 = NULL;
  const mxArray *c10_lhs23 = NULL;
  const mxArray *c10_rhs24 = NULL;
  const mxArray *c10_lhs24 = NULL;
  const mxArray *c10_rhs25 = NULL;
  const mxArray *c10_lhs25 = NULL;
  const mxArray *c10_rhs26 = NULL;
  const mxArray *c10_lhs26 = NULL;
  const mxArray *c10_rhs27 = NULL;
  const mxArray *c10_lhs27 = NULL;
  const mxArray *c10_rhs28 = NULL;
  const mxArray *c10_lhs28 = NULL;
  const mxArray *c10_rhs29 = NULL;
  const mxArray *c10_lhs29 = NULL;
  const mxArray *c10_rhs30 = NULL;
  const mxArray *c10_lhs30 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c10_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c10_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c10_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c10_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand"), "name", "name",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c10_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c10_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c10_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c10_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c10_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c10_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c10_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c10_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c10_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c10_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c10_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c10_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c10_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_eps"), "name", "name",
                  18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c10_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c10_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isequal"), "name", "name",
                  20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c10_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c10_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c10_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c10_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c10_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c10_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c10_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c10_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c10_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c10_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c10_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c10_rhs0);
  sf_mex_destroy(&c10_lhs0);
  sf_mex_destroy(&c10_rhs1);
  sf_mex_destroy(&c10_lhs1);
  sf_mex_destroy(&c10_rhs2);
  sf_mex_destroy(&c10_lhs2);
  sf_mex_destroy(&c10_rhs3);
  sf_mex_destroy(&c10_lhs3);
  sf_mex_destroy(&c10_rhs4);
  sf_mex_destroy(&c10_lhs4);
  sf_mex_destroy(&c10_rhs5);
  sf_mex_destroy(&c10_lhs5);
  sf_mex_destroy(&c10_rhs6);
  sf_mex_destroy(&c10_lhs6);
  sf_mex_destroy(&c10_rhs7);
  sf_mex_destroy(&c10_lhs7);
  sf_mex_destroy(&c10_rhs8);
  sf_mex_destroy(&c10_lhs8);
  sf_mex_destroy(&c10_rhs9);
  sf_mex_destroy(&c10_lhs9);
  sf_mex_destroy(&c10_rhs10);
  sf_mex_destroy(&c10_lhs10);
  sf_mex_destroy(&c10_rhs11);
  sf_mex_destroy(&c10_lhs11);
  sf_mex_destroy(&c10_rhs12);
  sf_mex_destroy(&c10_lhs12);
  sf_mex_destroy(&c10_rhs13);
  sf_mex_destroy(&c10_lhs13);
  sf_mex_destroy(&c10_rhs14);
  sf_mex_destroy(&c10_lhs14);
  sf_mex_destroy(&c10_rhs15);
  sf_mex_destroy(&c10_lhs15);
  sf_mex_destroy(&c10_rhs16);
  sf_mex_destroy(&c10_lhs16);
  sf_mex_destroy(&c10_rhs17);
  sf_mex_destroy(&c10_lhs17);
  sf_mex_destroy(&c10_rhs18);
  sf_mex_destroy(&c10_lhs18);
  sf_mex_destroy(&c10_rhs19);
  sf_mex_destroy(&c10_lhs19);
  sf_mex_destroy(&c10_rhs20);
  sf_mex_destroy(&c10_lhs20);
  sf_mex_destroy(&c10_rhs21);
  sf_mex_destroy(&c10_lhs21);
  sf_mex_destroy(&c10_rhs22);
  sf_mex_destroy(&c10_lhs22);
  sf_mex_destroy(&c10_rhs23);
  sf_mex_destroy(&c10_lhs23);
  sf_mex_destroy(&c10_rhs24);
  sf_mex_destroy(&c10_lhs24);
  sf_mex_destroy(&c10_rhs25);
  sf_mex_destroy(&c10_lhs25);
  sf_mex_destroy(&c10_rhs26);
  sf_mex_destroy(&c10_lhs26);
  sf_mex_destroy(&c10_rhs27);
  sf_mex_destroy(&c10_lhs27);
  sf_mex_destroy(&c10_rhs28);
  sf_mex_destroy(&c10_lhs28);
  sf_mex_destroy(&c10_rhs29);
  sf_mex_destroy(&c10_lhs29);
  sf_mex_destroy(&c10_rhs30);
  sf_mex_destroy(&c10_lhs30);
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

static void c10_activate_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = c10_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_deactivate_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_increment_counters_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c10_temporalCounter_i1 < 3U) {
    chartInstance->c10_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c10_temporalCounter_i1 + 1);
  }
}

static void c10_reset_counters_secsc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c10_lib_affectiveChar_behavior_secs(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_activate_secsc10_lib_affectiveChar_behavior(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c10_lib_affectiveChar_behavior_secs
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_increment_counters_secsc10_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c10_lib_affectiveChar_behavior_secs
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_reset_counters_secsc10_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_deactivate_c10_lib_affectiveChar_behavior_secs(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_deactivate_secsc10_lib_affectiveChar_behavior(chartInstance);
}

boolean_T sf_exported_auto_isStablec10_lib_affectiveChar_behavior(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c10_isStable;
}

void sf_exported_auto_duringc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_c10_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_sendBML(chartInstance);
  c10_enter_atomic_c10_lib_affectiveChar_behavior(chartInstance);
  c10_enter_internal_c10_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_exit_internal_c10_lib_affectiveChar_behavior(chartInstance);
  c10_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_sendBML(chartInstance);
}

void sf_exported_auto_disablec10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc10_lib_affectiveChar_behavior(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c10_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc10_lib_affectiveChar_behavior
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc10_lib_affectiveChar_behavior(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc10_lib_affectiveChar_behavior(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc10_lib_affectiveChar_behavior(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_initc10_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec10_lib_affectiveChar_behavior
  (SimStruct *c10_S)
{
  const mxArray *c10_out = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_out = NULL;
  sf_mex_assign(&c10_out,
                sf_internal_get_sim_state_c10_lib_affectiveChar_behavior(c10_S),
                false);
  return c10_out;
}

void sf_exported_auto_setSimstatec10_lib_affectiveChar_behavior(SimStruct *c10_S,
  const mxArray *c10_in)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c10_lib_affectiveChar_behavior(c10_S, sf_mex_dup
    (c10_in));
  sf_mex_destroy(&c10_in);
}

void sf_exported_auto_check_state_inconsistency_c10_lib_affectiveChar_behavior
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_sendBMLc10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T
   c10_arg[256])
{
  int32_T c10_i78;
  int32_T c10_i79;
  int32_T c10_i80;
  real_T (*c10_b_arg)[256];
  c10_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c10_i78 = 0; c10_i78 < 256; c10_i78++) {
    _SFD_DATA_RANGE_CHECK(c10_arg[c10_i78], 5U);
  }

  _SFD_SET_DATA_VALUE_PTR(5U, c10_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c10_arg, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
  for (c10_i79 = 0; c10_i79 < 256; c10_i79++) {
    (*c10_b_arg)[c10_i79] = c10_arg[c10_i79];
  }

  for (c10_i80 = 0; c10_i80 < 256; c10_i80++) {
    _SFD_DATA_RANGE_CHECK((*c10_b_arg)[c10_i80], 5U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(5U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c10_sfEvent);
}

static void c10_idlePoseRachelTablec10_lib_affectiveChar_behavior
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T
   c10_bmlID, real_T c10_poseBML[256])
{
  uint32_T c10_debug_family_var_map[22];
  boolean_T c10_aVarTruthTableCondition_1;
  boolean_T c10_aVarTruthTableCondition_2;
  boolean_T c10_aVarTruthTableCondition_3;
  boolean_T c10_aVarTruthTableCondition_4;
  boolean_T c10_aVarTruthTableCondition_5;
  boolean_T c10_aVarTruthTableCondition_6;
  boolean_T c10_aVarTruthTableCondition_7;
  boolean_T c10_aVarTruthTableCondition_8;
  boolean_T c10_aVarTruthTableCondition_9;
  boolean_T c10_aVarTruthTableCondition_10;
  boolean_T c10_aVarTruthTableCondition_11;
  boolean_T c10_aVarTruthTableCondition_12;
  boolean_T c10_aVarTruthTableCondition_13;
  boolean_T c10_aVarTruthTableCondition_14;
  boolean_T c10_aVarTruthTableCondition_15;
  boolean_T c10_aVarTruthTableCondition_16;
  boolean_T c10_aVarTruthTableCondition_17;
  boolean_T c10_aVarTruthTableCondition_18;
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  real_T c10_dv10[256];
  int32_T c10_i81;
  int32_T c10_i82;
  int32_T c10_i83;
  int32_T c10_i84;
  int32_T c10_i85;
  int32_T c10_i86;
  int32_T c10_i87;
  int32_T c10_i88;
  int32_T c10_i89;
  int32_T c10_i90;
  int32_T c10_i91;
  int32_T c10_i92;
  int32_T c10_i93;
  int32_T c10_i94;
  int32_T c10_i95;
  int32_T c10_i96;
  int32_T c10_i97;
  int32_T c10_i98;
  int32_T c10_i99;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_1, 0U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_2, 1U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_3, 2U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_4, 3U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_5, 4U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_6, 5U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_7, 6U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_8, 7U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_9, 8U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_10, 9U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_11, 10U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_12, 11U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_13, 12U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_14, 13U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_15, 14U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_16, 15U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_17, 16U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_aVarTruthTableCondition_18, 17U,
    c10_c_sf_marshallOut, c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 18U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 19U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_bmlID, 20U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_poseBML, 21U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  c10_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 6);
  c10_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 9);
  c10_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  c10_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 11);
  c10_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  c10_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 13);
  c10_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 14);
  c10_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 15);
  c10_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 16);
  c10_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 17);
  c10_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 18);
  c10_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 19);
  c10_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 20);
  c10_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 24);
  c10_aVarTruthTableCondition_1 = (c10_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 27);
  c10_aVarTruthTableCondition_2 = (c10_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 30);
  c10_aVarTruthTableCondition_3 = (c10_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 33);
  c10_aVarTruthTableCondition_4 = (c10_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 36);
  c10_aVarTruthTableCondition_5 = (c10_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 39);
  c10_aVarTruthTableCondition_6 = (c10_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 42);
  c10_aVarTruthTableCondition_7 = (c10_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 45);
  c10_aVarTruthTableCondition_8 = (c10_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 48);
  c10_aVarTruthTableCondition_9 = (c10_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 51);
  c10_aVarTruthTableCondition_10 = (c10_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 54);
  c10_aVarTruthTableCondition_11 = (c10_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 57);
  c10_aVarTruthTableCondition_12 = (c10_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 60);
  c10_aVarTruthTableCondition_13 = (c10_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 63);
  c10_aVarTruthTableCondition_14 = (c10_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 66);
  c10_aVarTruthTableCondition_15 = (c10_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 69);
  c10_aVarTruthTableCondition_16 = (c10_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 72);
  c10_aVarTruthTableCondition_17 = (c10_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 75);
  c10_aVarTruthTableCondition_18 = (c10_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 77);
  if (CV_EML_IF(0, 1, 0, c10_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 78);
    CV_EML_FCN(0, 6);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 151U);
    c10_encStr2Arr(chartInstance, c10_dv10);
    for (c10_i81 = 0; c10_i81 < 256; c10_i81++) {
      c10_poseBML[c10_i81] = c10_dv10[c10_i81];
    }

    c10_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -151);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 79);
    if (CV_EML_IF(0, 1, 1, c10_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 80);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, MAX_int8_T);
      c10_b_encStr2Arr(chartInstance, c10_dv10);
      for (c10_i82 = 0; c10_i82 < 256; c10_i82++) {
        c10_poseBML[c10_i82] = c10_dv10[c10_i82];
      }

      c10_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -127);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 81);
      if (CV_EML_IF(0, 1, 2, c10_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 82);
        CV_EML_FCN(0, 1);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 121);
        c10_c_encStr2Arr(chartInstance, c10_dv10);
        for (c10_i83 = 0; c10_i83 < 256; c10_i83++) {
          c10_poseBML[c10_i83] = c10_dv10[c10_i83];
        }

        c10_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -121);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 83);
        if (CV_EML_IF(0, 1, 3, c10_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 84);
          CV_EML_FCN(0, 2);
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, MAX_int8_T);
          c10_b_encStr2Arr(chartInstance, c10_dv10);
          for (c10_i84 = 0; c10_i84 < 256; c10_i84++) {
            c10_poseBML[c10_i84] = c10_dv10[c10_i84];
          }

          c10_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -127);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 85);
          if (CV_EML_IF(0, 1, 4, c10_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 86);
            CV_EML_FCN(0, 3);
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 133U);
            c10_d_encStr2Arr(chartInstance, c10_dv10);
            for (c10_i85 = 0; c10_i85 < 256; c10_i85++) {
              c10_poseBML[c10_i85] = c10_dv10[c10_i85];
            }

            c10_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -133);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 87);
            if (CV_EML_IF(0, 1, 5, c10_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 88);
              CV_EML_FCN(0, 7);
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 157U);
              c10_e_encStr2Arr(chartInstance, c10_dv10);
              for (c10_i86 = 0; c10_i86 < 256; c10_i86++) {
                c10_poseBML[c10_i86] = c10_dv10[c10_i86];
              }

              c10_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -157);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 89);
              if (CV_EML_IF(0, 1, 6, c10_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 90);
                CV_EML_FCN(0, 1);
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 121);
                c10_c_encStr2Arr(chartInstance, c10_dv10);
                for (c10_i87 = 0; c10_i87 < 256; c10_i87++) {
                  c10_poseBML[c10_i87] = c10_dv10[c10_i87];
                }

                c10_updateDataWrittenToVector(chartInstance, 0U);
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -121);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 91);
                if (CV_EML_IF(0, 1, 7, c10_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 92);
                  CV_EML_FCN(0, 3);
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 133U);
                  c10_d_encStr2Arr(chartInstance, c10_dv10);
                  for (c10_i88 = 0; c10_i88 < 256; c10_i88++) {
                    c10_poseBML[c10_i88] = c10_dv10[c10_i88];
                  }

                  c10_updateDataWrittenToVector(chartInstance, 0U);
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -133);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 93);
                  if (CV_EML_IF(0, 1, 8, c10_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 94);
                    CV_EML_FCN(0, 1);
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 121);
                    c10_c_encStr2Arr(chartInstance, c10_dv10);
                    for (c10_i89 = 0; c10_i89 < 256; c10_i89++) {
                      c10_poseBML[c10_i89] = c10_dv10[c10_i89];
                    }

                    c10_updateDataWrittenToVector(chartInstance, 0U);
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -121);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 95);
                    if (CV_EML_IF(0, 1, 9, c10_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 96);
                      CV_EML_FCN(0, 6);
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 151U);
                      c10_encStr2Arr(chartInstance, c10_dv10);
                      for (c10_i90 = 0; c10_i90 < 256; c10_i90++) {
                        c10_poseBML[c10_i90] = c10_dv10[c10_i90];
                      }

                      c10_updateDataWrittenToVector(chartInstance, 0U);
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -151);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 97);
                      if (CV_EML_IF(0, 1, 10, c10_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 98);
                        CV_EML_FCN(0, 7);
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 157U);
                        c10_e_encStr2Arr(chartInstance, c10_dv10);
                        for (c10_i91 = 0; c10_i91 < 256; c10_i91++) {
                          c10_poseBML[c10_i91] = c10_dv10[c10_i91];
                        }

                        c10_updateDataWrittenToVector(chartInstance, 0U);
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -157);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 99);
                        if (CV_EML_IF(0, 1, 11, c10_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 100);
                          CV_EML_FCN(0, 5);
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 145U);
                          c10_f_encStr2Arr(chartInstance, c10_dv10);
                          for (c10_i92 = 0; c10_i92 < 256; c10_i92++) {
                            c10_poseBML[c10_i92] = c10_dv10[c10_i92];
                          }

                          c10_updateDataWrittenToVector(chartInstance, 0U);
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -145);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 101);
                          if (CV_EML_IF(0, 1, 12, c10_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 102);
                            CV_EML_FCN(0, 5);
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 145U);
                            c10_f_encStr2Arr(chartInstance, c10_dv10);
                            for (c10_i93 = 0; c10_i93 < 256; c10_i93++) {
                              c10_poseBML[c10_i93] = c10_dv10[c10_i93];
                            }

                            c10_updateDataWrittenToVector(chartInstance, 0U);
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -145);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 103);
                            if (CV_EML_IF(0, 1, 13,
                                          c10_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 104);
                              CV_EML_FCN(0, 3);
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 133U);
                              c10_d_encStr2Arr(chartInstance, c10_dv10);
                              for (c10_i94 = 0; c10_i94 < 256; c10_i94++) {
                                c10_poseBML[c10_i94] = c10_dv10[c10_i94];
                              }

                              c10_updateDataWrittenToVector(chartInstance, 0U);
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -133);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 105);
                              if (CV_EML_IF(0, 1, 14,
                                            c10_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              106);
                                CV_EML_FCN(0, 4);
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              139U);
                                c10_g_encStr2Arr(chartInstance, c10_dv10);
                                for (c10_i95 = 0; c10_i95 < 256; c10_i95++) {
                                  c10_poseBML[c10_i95] = c10_dv10[c10_i95];
                                }

                                c10_updateDataWrittenToVector(chartInstance, 0U);
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              -139);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              107);
                                if (CV_EML_IF(0, 1, 15,
                                              c10_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                108);
                                  CV_EML_FCN(0, 3);
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                133U);
                                  c10_d_encStr2Arr(chartInstance, c10_dv10);
                                  for (c10_i96 = 0; c10_i96 < 256; c10_i96++) {
                                    c10_poseBML[c10_i96] = c10_dv10[c10_i96];
                                  }

                                  c10_updateDataWrittenToVector(chartInstance,
                                    0U);
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                -133);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                109);
                                  if (CV_EML_IF(0, 1, 16,
                                                c10_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  110);
                                    CV_EML_FCN(0, 5);
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  145U);
                                    c10_f_encStr2Arr(chartInstance, c10_dv10);
                                    for (c10_i97 = 0; c10_i97 < 256; c10_i97++)
                                    {
                                      c10_poseBML[c10_i97] = c10_dv10[c10_i97];
                                    }

                                    c10_updateDataWrittenToVector(chartInstance,
                                      0U);
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  -145);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  111);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c10_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    112);
                                      CV_EML_FCN(0, 5);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    145U);
                                      c10_f_encStr2Arr(chartInstance, c10_dv10);
                                      for (c10_i98 = 0; c10_i98 < 256; c10_i98++)
                                      {
                                        c10_poseBML[c10_i98] = c10_dv10[c10_i98];
                                      }

                                      c10_updateDataWrittenToVector
                                        (chartInstance, 0U);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    -145);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    114);
                                      CV_EML_FCN(0, 1);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    121);
                                      c10_c_encStr2Arr(chartInstance, c10_dv10);
                                      for (c10_i99 = 0; c10_i99 < 256; c10_i99++)
                                      {
                                        c10_poseBML[c10_i99] = c10_dv10[c10_i99];
                                      }

                                      c10_updateDataWrittenToVector
                                        (chartInstance, 0U);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    -121);
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

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_sendBML(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c10_b_sendBML(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void sf_exported_user_c10_lib_affectiveChar_behavior_idlePoseRachelTable
  (SimStruct *c10_S, real_T c10_bmlID, real_T c10_poseBML[256])
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_idlePoseRachelTablec10_lib_affectiveChar_behavior(chartInstance, c10_bmlID,
    c10_poseBML);
}

void sf_exported_user_c10_lib_affectiveChar_behavior_sendBML(SimStruct *c10_S,
  real_T c10_arg[256])
{
  int32_T c10_i100;
  real_T c10_b_arg[256];
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  for (c10_i100 = 0; c10_i100 < 256; c10_i100++) {
    c10_b_arg[c10_i100] = c10_arg[c10_i100];
  }

  c10_sendBMLc10_lib_affectiveChar_behavior(chartInstance, c10_b_arg);
}

static const mxArray *c10_o_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int8_T c10_e_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int8_T c10_y;
  int8_T c10_i101;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i101, 1, 2, 0U, 0, 0U, 0);
  c10_y = c10_i101;
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
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_secs = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_secs),
    &c10_thisId);
  sf_mex_destroy(&c10_secs);
  *(int8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_p_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_f_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i102;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i102, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i102;
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
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_q_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  uint8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(uint8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static uint8_T c10_g_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_b_tp_stateRandomPose, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_tp_stateRandomPose), &c10_thisId);
  sf_mex_destroy(&c10_b_tp_stateRandomPose);
  return c10_y;
}

static uint8_T c10_h_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u3;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u3, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u3;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_tp_stateRandomPose;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c10_b_tp_stateRandomPose = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_tp_stateRandomPose), &c10_thisId);
  sf_mex_destroy(&c10_b_tp_stateRandomPose);
  *(uint8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint32_T c10_i_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_b_method, const char_T *c10_identifier)
{
  uint32_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_method),
    &c10_thisId);
  sf_mex_destroy(&c10_b_method);
  return c10_y;
}

static uint32_T c10_j_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint32_T c10_y;
  uint32_T c10_u4;
  if (mxIsEmpty(c10_u)) {
    chartInstance->c10_method_not_empty = false;
  } else {
    chartInstance->c10_method_not_empty = true;
    sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u4, 1, 7, 0U, 0, 0U, 0);
    c10_y = c10_u4;
  }

  sf_mex_destroy(&c10_u);
  return c10_y;
}

static uint32_T c10_k_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier)
{
  uint32_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_d_state),
    &c10_thisId);
  sf_mex_destroy(&c10_d_state);
  return c10_y;
}

static uint32_T c10_l_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint32_T c10_y;
  uint32_T c10_u5;
  if (mxIsEmpty(c10_u)) {
    chartInstance->c10_state_not_empty = false;
  } else {
    chartInstance->c10_state_not_empty = true;
    sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u5, 1, 7, 0U, 0, 0U, 0);
    c10_y = c10_u5;
  }

  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_m_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[625])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_d_state), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_d_state);
}

static void c10_n_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[625])
{
  uint32_T c10_uv3[625];
  int32_T c10_i103;
  if (mxIsEmpty(c10_u)) {
    chartInstance->c10_c_state_not_empty = false;
  } else {
    chartInstance->c10_c_state_not_empty = true;
    sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_uv3, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c10_i103 = 0; c10_i103 < 625; c10_i103++) {
      c10_y[c10_i103] = c10_uv3[c10_i103];
    }
  }

  sf_mex_destroy(&c10_u);
}

static void c10_o_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[2])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_d_state), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_d_state);
}

static void c10_p_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[2])
{
  uint32_T c10_uv4[2];
  int32_T c10_i104;
  if (mxIsEmpty(c10_u)) {
    chartInstance->c10_b_state_not_empty = false;
  } else {
    chartInstance->c10_b_state_not_empty = true;
    sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_uv4, 1, 7, 0U, 1, 0U, 1,
                  2);
    for (c10_i104 = 0; c10_i104 < 2; c10_i104++) {
      c10_y[c10_i104] = c10_uv4[c10_i104];
    }
  }

  sf_mex_destroy(&c10_u);
}

static const mxArray *c10_q_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier)
{
  const mxArray *c10_y = NULL;
  emlrtMsgIdentifier c10_thisId;
  c10_y = NULL;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  sf_mex_assign(&c10_y, c10_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_setSimStateSideEffectsInfo), &c10_thisId), false);
  sf_mex_destroy(&c10_b_setSimStateSideEffectsInfo);
  return c10_y;
}

static const mxArray *c10_r_emlrt_marshallIn
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
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
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex)
{
  (void)chartInstance;
  c10_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c10_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c10_b_twister_state_vector
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed)
{
  real_T c10_d5;
  uint32_T c10_u6;
  uint32_T c10_r;
  int32_T c10_mti;
  real_T c10_b_mti;
  real_T c10_d6;
  uint32_T c10_u7;
  (void)chartInstance;
  c10_d5 = c10_seed;
  if (c10_d5 < 4.294967296E+9) {
    if (c10_d5 >= 0.0) {
      c10_u6 = (uint32_T)c10_d5;
    } else {
      c10_u6 = 0U;
    }
  } else if (c10_d5 >= 4.294967296E+9) {
    c10_u6 = MAX_uint32_T;
  } else {
    c10_u6 = 0U;
  }

  c10_r = c10_u6;
  c10_mt[0] = c10_r;
  for (c10_mti = 0; c10_mti < 623; c10_mti++) {
    c10_b_mti = 2.0 + (real_T)c10_mti;
    c10_d6 = muDoubleScalarRound(c10_b_mti - 1.0);
    if (c10_d6 < 4.294967296E+9) {
      if (c10_d6 >= 0.0) {
        c10_u7 = (uint32_T)c10_d6;
      } else {
        c10_u7 = 0U;
      }
    } else if (c10_d6 >= 4.294967296E+9) {
      c10_u7 = MAX_uint32_T;
    } else {
      c10_u7 = 0U;
    }

    c10_r = (c10_r ^ c10_r >> 30U) * 1812433253U + c10_u7;
    c10_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c10_b_mti), 1, 625, 1, 0) - 1] = c10_r;
  }

  c10_mt[624] = 624U;
}

static real_T c10_c_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c10_d_state[625])
{
  int32_T c10_i105;
  uint32_T c10_u[2];
  int32_T c10_j;
  real_T c10_b_j;
  uint32_T c10_mti;
  int32_T c10_kk;
  real_T c10_b_kk;
  uint32_T c10_y;
  uint32_T c10_b_y;
  uint32_T c10_c_y;
  int32_T c10_c_kk;
  uint32_T c10_d_y;
  uint32_T c10_e_y;
  uint32_T c10_f_y;
  uint32_T c10_g_y;
  real_T c10_b_r;
  boolean_T c10_b1;
  boolean_T c10_isvalid;
  int32_T c10_k;
  int32_T c10_a;
  int32_T c10_b_a;
  real_T c10_d7;
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
    for (c10_i105 = 0; c10_i105 < 2; c10_i105++) {
      c10_u[c10_i105] = 0U;
    }

    for (c10_j = 0; c10_j < 2; c10_j++) {
      c10_b_j = 1.0 + (real_T)c10_j;
      c10_mti = c10_d_state[624] + 1U;
      if ((real_T)c10_mti >= 625.0) {
        for (c10_kk = 0; c10_kk < 227; c10_kk++) {
          c10_b_kk = 1.0 + (real_T)c10_kk;
          c10_y = (c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", c10_b_kk), 1, 625, 1, 0) - 1] &
                   2147483648U) | (c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c10_b_kk + 1.0), 1, 625, 1, 0) - 1]
            & 2147483647U);
          c10_b_y = c10_y;
          c10_c_y = c10_b_y;
          if ((real_T)(c10_c_y & 1U) == 0.0) {
            c10_c_y >>= 1U;
          } else {
            c10_c_y = c10_c_y >> 1U ^ 2567483615U;
          }

          c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c10_b_kk), 1, 625, 1, 0) - 1] =
            c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c10_b_kk + 397.0), 1, 625, 1, 0) - 1] ^
            c10_c_y;
        }

        for (c10_c_kk = 0; c10_c_kk < 396; c10_c_kk++) {
          c10_b_kk = 228.0 + (real_T)c10_c_kk;
          c10_y = (c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", c10_b_kk), 1, 625, 1, 0) - 1] &
                   2147483648U) | (c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c10_b_kk + 1.0), 1, 625, 1, 0) - 1]
            & 2147483647U);
          c10_d_y = c10_y;
          c10_e_y = c10_d_y;
          if ((real_T)(c10_e_y & 1U) == 0.0) {
            c10_e_y >>= 1U;
          } else {
            c10_e_y = c10_e_y >> 1U ^ 2567483615U;
          }

          c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c10_b_kk), 1, 625, 1, 0) - 1] =
            c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c10_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1]
            ^ c10_e_y;
        }

        c10_y = (c10_d_state[623] & 2147483648U) | (c10_d_state[0] & 2147483647U);
        c10_f_y = c10_y;
        c10_g_y = c10_f_y;
        if ((real_T)(c10_g_y & 1U) == 0.0) {
          c10_g_y >>= 1U;
        } else {
          c10_g_y = c10_g_y >> 1U ^ 2567483615U;
        }

        c10_d_state[623] = c10_d_state[396] ^ c10_g_y;
        c10_mti = 1U;
      }

      c10_y = c10_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c10_mti), 1, 625, 1, 0)
        - 1];
      c10_d_state[624] = c10_mti;
      c10_y ^= c10_y >> 11U;
      c10_y ^= c10_y << 7U & 2636928640U;
      c10_y ^= c10_y << 15U & 4022730752U;
      c10_y ^= c10_y >> 18U;
      c10_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c10_b_j), 1, 2, 1, 0) - 1] = c10_y;
    }

    c10_u[0] >>= 5U;
    c10_u[1] >>= 6U;
    c10_b_r = 1.1102230246251565E-16 * ((real_T)c10_u[0] * 6.7108864E+7 +
      (real_T)c10_u[1]);
    if (c10_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c10_d_state[624] >= 1.0) {
        if ((real_T)c10_d_state[624] < 625.0) {
          c10_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c10_b1 = false;
      }

      c10_isvalid = c10_b1;
      if (c10_isvalid) {
        c10_isvalid = false;
        c10_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c10_k < 625)) {
          if ((real_T)c10_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c10_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c10_a = c10_k;
            c10_b_a = c10_a + 1;
            c10_k = c10_b_a;
          } else {
            c10_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c10_isvalid) {
        c10_eml_error(chartInstance);
        c10_d7 = 5489.0;
        c10_b_twister_state_vector(chartInstance, c10_d_state, c10_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c10_b_r;
}

static real_T c10_get_BOREDOM_THRESHOLD
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#778) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_BOREDOM_THRESHOLD_address;
}

static void c10_set_BOREDOM_THRESHOLD
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b,
   real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#778) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_BOREDOM_THRESHOLD_address = c10_c;
}

static real_T *c10_access_BOREDOM_THRESHOLD
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c10_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#778) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_BOREDOM_THRESHOLD_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c10_c;
}

static real_T c10_get_boredom(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c10_b);
  if (chartInstance->c10_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#777) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_boredom_address;
}

static void c10_set_boredom(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c10_b);
  if (chartInstance->c10_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#777) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_boredom_address = c10_c;
}

static real_T *c10_access_boredom(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c10_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#777) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_boredom_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c10_c;
}

static real_T c10_get_interest(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c10_b);
  if (chartInstance->c10_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#781) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_interest_address;
}

static void c10_set_interest(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c10_b);
  if (chartInstance->c10_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#781) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_interest_address = c10_c;
}

static real_T *c10_access_interest
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c10_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#781) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_interest_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c10_c;
}

static real_T c10_get_isPosing(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c10_b);
  if (chartInstance->c10_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#780) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_isPosing_address;
}

static void c10_set_isPosing(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c10_b);
  if (chartInstance->c10_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#780) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_isPosing_address = c10_c;
}

static real_T *c10_access_isPosing
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c10_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#780) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_isPosing_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c10_c;
}

static real_T c10_get_randPoseChance
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c10_b);
  if (chartInstance->c10_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#779) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_randPoseChance_address;
}

static void c10_set_randPoseChance
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b,
   real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c10_b);
  if (chartInstance->c10_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#779) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_randPoseChance_address = c10_c;
}

static real_T *c10_access_randPoseChance
  (SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c10_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#779) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_randPoseChance_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c10_c;
}

static void init_dsm_address_info(SFc10_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c10_BOREDOM_THRESHOLD_address,
    &chartInstance->c10_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c10_boredom_address, &chartInstance->c10_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c10_interest_address, &chartInstance->c10_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c10_isPosing_address, &chartInstance->c10_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c10_randPoseChance_address,
    &chartInstance->c10_randPoseChance_index);
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

void sf_c10_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(300656135U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3636816019U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(64226284U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1402228977U);
}

mxArray *sf_c10_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xeAdvcDfVS6AdmGYmsw1dF");
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

mxArray *sf_c10_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c10_lib_affectiveChar_behavior\",},{M[9],M[0],T\"is_c10_lib_affectiveChar_behavior\",},{M[11],M[16],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[10],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           10,
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
        init_script_number_translation(_lib_affectiveChar_behaviorMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _lib_affectiveChar_behaviorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lib_affectiveChar_behaviorMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(1,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(2,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(3,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(4,11,0,0,"interest");
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,8,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,
                             "idlePoseRachelTablec10_lib_affectiveChar_behavior",
                             0,-1,2811);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",2811,-1,2979);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",2979,-1,3159);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3159,-1,3329);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",3329,-1,3511);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",3511,-1,3681);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",3681,-1,3850);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",3850,-1,4016);
        _SFD_CV_INIT_EML_IF(0,1,0,1586,1616,1647,2809);
        _SFD_CV_INIT_EML_IF(0,1,1,1647,1681,1712,2809);
        _SFD_CV_INIT_EML_IF(0,1,2,1712,1746,1777,2809);
        _SFD_CV_INIT_EML_IF(0,1,3,1777,1811,1842,2809);
        _SFD_CV_INIT_EML_IF(0,1,4,1842,1876,1907,2809);
        _SFD_CV_INIT_EML_IF(0,1,5,1907,1941,1972,2809);
        _SFD_CV_INIT_EML_IF(0,1,6,1972,2006,2037,2809);
        _SFD_CV_INIT_EML_IF(0,1,7,2037,2071,2102,2809);
        _SFD_CV_INIT_EML_IF(0,1,8,2102,2136,2167,2809);
        _SFD_CV_INIT_EML_IF(0,1,9,2167,2202,2233,2809);
        _SFD_CV_INIT_EML_IF(0,1,10,2233,2268,2299,2809);
        _SFD_CV_INIT_EML_IF(0,1,11,2299,2334,2365,2809);
        _SFD_CV_INIT_EML_IF(0,1,12,2365,2400,2431,2809);
        _SFD_CV_INIT_EML_IF(0,1,13,2431,2466,2497,2809);
        _SFD_CV_INIT_EML_IF(0,1,14,2497,2532,2563,2809);
        _SFD_CV_INIT_EML_IF(0,1,15,2563,2598,2629,2809);
        _SFD_CV_INIT_EML_IF(0,1,16,2629,2664,2695,2809);
        _SFD_CV_INIT_EML_IF(0,1,17,2695,2730,2761,2809);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,38,1,38);

        {
          static int condStart[] = { 2, 24 };

          static int condEnd[] = { 21, 37 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,38,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

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
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_boredom_address);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c10_BOREDOM_THRESHOLD_address);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_randPoseChance_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c10_isPosing_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c10_interest_address);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lib_affectiveChar_behaviorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "DFaiVSEXBj6jcv7PEwIYkC";
}

static void sf_opaque_initialize_c10_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c10_lib_affectiveChar_behavior(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c10_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c10_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c10_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c10_lib_affectiveChar_behavior
      ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_lib_affectiveChar_behavior
    ((SFc10_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c10_lib_affectiveChar_behavior
      ((SFc10_lib_affectiveChar_behaviorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,10,1);
    if (chartIsInlinable) {
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1653849544U));
  ssSetChecksum1(S,(2421497415U));
  ssSetChecksum2(S,(602413357U));
  ssSetChecksum3(S,(686912404U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c10_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc10_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc10_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_lib_affectiveChar_behavior;
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

void c10_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
