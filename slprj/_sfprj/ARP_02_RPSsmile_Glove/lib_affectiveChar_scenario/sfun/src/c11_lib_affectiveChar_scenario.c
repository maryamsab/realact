/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_scenario_sfun.h"
#include "c11_lib_affectiveChar_scenario.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_scenario_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c11_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_stateBoredPose          ((uint8_T)1U)
#define c11_IN_stateRandomPose         ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c11_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_o_debug_family_names[2] = { "nargin", "nargout" };

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

static boolean_T c11_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initialize_params_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void enable_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void disable_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void set_sim_state_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_st);
static void c11_set_sim_state_side_effects_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void finalize_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void sf_gateway_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_enter_atomic_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_enter_internal_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_exit_internal_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_initc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initSimStructsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_enter_atomic_stateRandomPose
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_b_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_c_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_d_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_e_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_f_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_g_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_h_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_i_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_j_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static void c11_k_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256]);
static real_T c11_rand(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static real_T c11_eml_rand(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c11_eml_rand_mt19937ar
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_d_state[625]);
static void c11_twister_state_vector
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_mt[625], real_T c11_seed, uint32_T c11_b_mt[625]);
static void c11_b_eml_rand_mt19937ar
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_d_state[625], uint32_T c11_e_state[625], real_T *c11_r);
static void c11_eml_error(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_b_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_c_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_d_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[256]);
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
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_r_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_s_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_t_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_activate_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_deactivate_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_increment_counters_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_reset_counters_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c11_sendBMLc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c11_arg[256]);
static void c11_boredPoseSc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c11_bmlID, real_T c11_poseBML[256]);
static void c11_sendBML(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c11_b_sendBML(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static boolean_T c11_all(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, boolean_T c11_x);
static const mxArray *c11_u_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int8_T c11_e_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_v_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_f_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_w_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_g_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_b_tp_stateRandomPose, const char_T *c11_identifier);
static uint8_T c11_h_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint32_T c11_i_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_b_method, const char_T *c11_identifier);
static uint32_T c11_j_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static uint32_T c11_k_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_d_state, const char_T *c11_identifier);
static uint32_T c11_l_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_m_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_d_state, const char_T *c11_identifier, uint32_T c11_y[625]);
static void c11_n_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId, uint32_T c11_y[625]);
static void c11_o_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_d_state, const char_T *c11_identifier, uint32_T c11_y[2]);
static void c11_p_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId, uint32_T c11_y[2]);
static const mxArray *c11_q_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier);
static const mxArray *c11_r_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex);
static void c11_errorIfDataNotWrittenToFcn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex, uint32_T c11_dataNumber);
static void c11_b_twister_state_vector
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_mt[625], real_T c11_seed);
static real_T c11_c_eml_rand_mt19937ar
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_d_state[625]);
static real_T c11_get_BOREDOMT(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_BOREDOMT(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_BOREDOMT
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c11_b);
static real_T c11_get_b(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_b(SFc11_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_b(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_bored(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_bored(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_bored(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_pose(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_pose(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_pose(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_randomP(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_randomP(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_randomP(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_lib_affectiveChar_scenario == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_lib_affectiveChar_scenario ==
      c11_IN_stateRandomPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_lib_affectiveChar_scenario ==
      c11_IN_stateBoredPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  uint32_T c11_hoistedGlobal;
  uint32_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint32_T c11_b_hoistedGlobal;
  uint32_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  int32_T c11_i0;
  uint32_T c11_c_u[625];
  const mxArray *c11_d_y = NULL;
  int32_T c11_i1;
  uint32_T c11_d_u[2];
  const mxArray *c11_e_y = NULL;
  uint8_T c11_c_hoistedGlobal;
  uint8_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_f_u;
  const mxArray *c11_g_y = NULL;
  uint8_T c11_e_hoistedGlobal;
  uint8_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(7, 1), false);
  c11_hoistedGlobal = chartInstance->c11_method;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  if (!chartInstance->c11_method_not_empty) {
    sf_mex_assign(&c11_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_state;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  if (!chartInstance->c11_state_not_empty) {
    sf_mex_assign(&c11_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c11_y, 1, c11_c_y);
  for (c11_i0 = 0; c11_i0 < 625; c11_i0++) {
    c11_c_u[c11_i0] = chartInstance->c11_c_state[c11_i0];
  }

  c11_d_y = NULL;
  if (!chartInstance->c11_c_state_not_empty) {
    sf_mex_assign(&c11_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_c_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c11_y, 2, c11_d_y);
  for (c11_i1 = 0; c11_i1 < 2; c11_i1++) {
    c11_d_u[c11_i1] = chartInstance->c11_b_state[c11_i1];
  }

  c11_e_y = NULL;
  if (!chartInstance->c11_b_state_not_empty) {
    sf_mex_assign(&c11_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_d_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_c_hoistedGlobal =
    chartInstance->c11_is_active_c11_lib_affectiveChar_scenario;
  c11_e_u = c11_c_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  c11_d_hoistedGlobal = chartInstance->c11_is_c11_lib_affectiveChar_scenario;
  c11_f_u = c11_d_hoistedGlobal;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 5, c11_g_y);
  c11_e_hoistedGlobal = chartInstance->c11_temporalCounter_i1;
  c11_g_u = c11_e_hoistedGlobal;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 6, c11_h_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_st)
{
  const mxArray *c11_u;
  uint32_T c11_uv0[625];
  int32_T c11_i2;
  uint32_T c11_uv1[2];
  int32_T c11_i3;
  c11_u = sf_mex_dup(c11_st);
  chartInstance->c11_method = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 0)), "method");
  chartInstance->c11_state = c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 1)), "state");
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "state", c11_uv0);
  for (c11_i2 = 0; c11_i2 < 625; c11_i2++) {
    chartInstance->c11_c_state[c11_i2] = c11_uv0[c11_i2];
  }

  c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 3)),
    "state", c11_uv1);
  for (c11_i3 = 0; c11_i3 < 2; c11_i3++) {
    chartInstance->c11_b_state[c11_i3] = c11_uv1[c11_i3];
  }

  chartInstance->c11_is_active_c11_lib_affectiveChar_scenario =
    c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 4)),
    "is_active_c11_lib_affectiveChar_scenario");
  chartInstance->c11_is_c11_lib_affectiveChar_scenario = c11_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 5)),
     "is_c11_lib_affectiveChar_scenario");
  chartInstance->c11_temporalCounter_i1 = c11_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_lib_affectiveChar_scenario(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_lib_affectiveChar_scenario ==
        c11_IN_stateBoredPose) {
      chartInstance->c11_tp_stateBoredPose = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_stateBoredPose = 0U;
    }

    if (chartInstance->c11_is_c11_lib_affectiveChar_scenario ==
        c11_IN_stateRandomPose) {
      chartInstance->c11_tp_stateRandomPose = 1U;
    } else {
      chartInstance->c11_tp_stateRandomPose = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  c11_set_sim_state_side_effects_c11_lib_affectiveChar_scenario(chartInstance);
}

static void c11_enter_atomic_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_lib_affectiveChar_scenario = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_c11_lib_affectiveChar_scenario = c11_IN_stateRandomPose;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_stateRandomPose = 1U;
  c11_enter_atomic_stateRandomPose(chartInstance);
}

static void c11_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
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
  real_T c11_r;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_dv0[256];
  int32_T c11_i4;
  real_T c11_arg[256];
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 1.0;
  boolean_T c11_d_out;
  real_T (*c11_b_arg)[256];
  boolean_T guard1 = false;
  c11_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  switch (chartInstance->c11_is_c11_lib_affectiveChar_scenario) {
   case c11_IN_stateBoredPose:
    CV_CHART_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_q_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    c11_out = CV_EML_IF(2, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs) &&
                        (chartInstance->c11_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateBoredPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_lib_affectiveChar_scenario =
        c11_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateRandomPose = 1U;
      c11_enter_atomic_stateRandomPose(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateRandomPose:
    CV_CHART_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_s_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, c11_get_randomP(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(5, 0, 1, c11_get_pose(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c11_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c11_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateRandomPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_lib_affectiveChar_scenario =
        c11_IN_stateBoredPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_temporalCounter_i1 = 0U;
      chartInstance->c11_tp_stateBoredPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_o_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      c11_r = c11_rand(chartInstance);
      c11_x = c11_r * 16.0;
      c11_b_x = c11_x;
      c11_b_x = muDoubleScalarFloor(c11_b_x);
      c11_r = 3.0 + c11_b_x;
      c11_boredPoseSc11_lib_affectiveChar_scenario(chartInstance, c11_r, c11_dv0);
      for (c11_i4 = 0; c11_i4 < 256; c11_i4++) {
        c11_arg[c11_i4] = c11_dv0[c11_i4];
      }

      for (c11_i5 = 0; c11_i5 < 256; c11_i5++) {
        _SFD_DATA_RANGE_CHECK(c11_arg[c11_i5], 5U);
      }

      _SFD_SET_DATA_VALUE_PTR(5U, c11_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c11_arg, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c11_sfEvent);
      for (c11_i6 = 0; c11_i6 < 256; c11_i6++) {
        (*c11_b_arg)[c11_i6] = c11_arg[c11_i6];
      }

      for (c11_i7 = 0; c11_i7 < 256; c11_i7++) {
        _SFD_DATA_RANGE_CHECK((*c11_b_arg)[c11_i7], 5U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(5U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_r_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_c_sf_marshallOut,
        c11_c_sf_marshallIn);
      c11_c_out = CV_EML_IF(3, 0, 0, c11_get_randomP(chartInstance, 0) != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateRandomPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_c11_lib_affectiveChar_scenario =
          c11_IN_stateRandomPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateRandomPose = 1U;
        c11_enter_atomic_stateRandomPose(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c11_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_p_debug_family_names,
          c11_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U,
          c11_c_sf_marshallOut, c11_c_sf_marshallIn);
        c11_d_out = CV_EML_IF(1, 0, 0, c11_get_pose(chartInstance, 0) != 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c11_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
          chartInstance->c11_tp_stateRandomPose = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
          chartInstance->c11_isStable = false;
          chartInstance->c11_is_c11_lib_affectiveChar_scenario =
            c11_IN_stateRandomPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
          chartInstance->c11_tp_stateRandomPose = 1U;
          c11_enter_atomic_stateRandomPose(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c11_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c11_is_c11_lib_affectiveChar_scenario =
      c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_c11_lib_affectiveChar_scenario) {
   case c11_IN_stateBoredPose:
    CV_CHART_EVAL(1, 0, 1);
    chartInstance->c11_tp_stateBoredPose = 0U;
    chartInstance->c11_is_c11_lib_affectiveChar_scenario =
      c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateRandomPose:
    CV_CHART_EVAL(1, 0, 2);
    chartInstance->c11_tp_stateRandomPose = 0U;
    chartInstance->c11_is_c11_lib_affectiveChar_scenario =
      c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c11_is_c11_lib_affectiveChar_scenario =
      c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    break;
  }
}

static void c11_initc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_method_not_empty = false;
  chartInstance->c11_state_not_empty = false;
  chartInstance->c11_b_state_not_empty = false;
  chartInstance->c11_c_state_not_empty = false;
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_stateBoredPose = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_tp_stateRandomPose = 0U;
  chartInstance->c11_is_active_c11_lib_affectiveChar_scenario = 0U;
  chartInstance->c11_is_c11_lib_affectiveChar_scenario = c11_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_enter_atomic_stateRandomPose
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 0.0;
  real_T c11_hoistedGlobal;
  real_T c11_lowhigh[2];
  real_T c11_low;
  real_T c11_high;
  int32_T c11_i8;
  static char_T c11_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c11_u[26];
  const mxArray *c11_y = NULL;
  real_T c11_s;
  real_T c11_r;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_b_hoistedGlobal;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_m_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  c11_set_b(chartInstance, 0, c11_get_BOREDOMT(chartInstance, 0) - c11_get_bored
            (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_n_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  c11_hoistedGlobal = c11_get_b(chartInstance, 0);
  c11_lowhigh[0] = 1.0;
  c11_lowhigh[1] = c11_hoistedGlobal;
  c11_low = c11_lowhigh[0];
  c11_high = c11_lowhigh[1];
  if (c11_low <= c11_high) {
  } else {
    for (c11_i8 = 0; c11_i8 < 26; c11_i8++) {
      c11_u[c11_i8] = c11_cv0[c11_i8];
    }

    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c11_y));
  }

  c11_s = (c11_high - c11_low) + 1.0;
  c11_r = c11_rand(chartInstance);
  c11_x = c11_r * c11_s;
  c11_b_x = c11_x;
  c11_b_x = muDoubleScalarFloor(c11_b_x);
  c11_r = c11_low + c11_b_x;
  c11_set_randomP(chartInstance, 0, c11_r);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  sf_mex_printf("%s =\\n", "randomP");
  c11_b_hoistedGlobal = c11_get_randomP(chartInstance, 0);
  c11_b_u = c11_b_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c11_b_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[91];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[91];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i9;
  static char_T c11_cv1[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i10;
  static real_T c11_dv1[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
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
  for (c11_i9 = 0; c11_i9 < 91; c11_i9++) {
    c11_mystr[c11_i9] = c11_cv1[c11_i9];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i10 = 0; c11_i10 < 91; c11_i10++) {
    c11_arr[c11_i10] = c11_dv1[c11_i10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i11 = 0; c11_i11 < 256; c11_i11++) {
    c11_tt[c11_i11] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i12 = 0; c11_i12 < 91; c11_i12++) {
    c11_tt[c11_i12] = c11_arr[c11_i12];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i13 = 0; c11_i13 < 256; c11_i13++) {
    c11_myarr256[c11_i13] = c11_tt[c11_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_b_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[87];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[87];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i14;
  static char_T c11_cv2[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c11_i15;
  static real_T c11_dv2[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_c_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i14 = 0; c11_i14 < 87; c11_i14++) {
    c11_mystr[c11_i14] = c11_cv2[c11_i14];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i15 = 0; c11_i15 < 87; c11_i15++) {
    c11_arr[c11_i15] = c11_dv2[c11_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i16 = 0; c11_i16 < 256; c11_i16++) {
    c11_tt[c11_i16] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i17 = 0; c11_i17 < 87; c11_i17++) {
    c11_tt[c11_i17] = c11_arr[c11_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i18 = 0; c11_i18 < 256; c11_i18++) {
    c11_myarr256[c11_i18] = c11_tt[c11_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[93];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[93];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i19;
  static char_T c11_cv3[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i20;
  static real_T c11_dv3[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_d_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i19 = 0; c11_i19 < 93; c11_i19++) {
    c11_mystr[c11_i19] = c11_cv3[c11_i19];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i20 = 0; c11_i20 < 93; c11_i20++) {
    c11_arr[c11_i20] = c11_dv3[c11_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i21 = 0; c11_i21 < 256; c11_i21++) {
    c11_tt[c11_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i22 = 0; c11_i22 < 93; c11_i22++) {
    c11_tt[c11_i22] = c11_arr[c11_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i23 = 0; c11_i23 < 256; c11_i23++) {
    c11_myarr256[c11_i23] = c11_tt[c11_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_d_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[94];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[94];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i24;
  static char_T c11_cv4[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i25;
  static real_T c11_dv4[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i26;
  int32_T c11_i27;
  int32_T c11_i28;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_e_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i24 = 0; c11_i24 < 94; c11_i24++) {
    c11_mystr[c11_i24] = c11_cv4[c11_i24];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i25 = 0; c11_i25 < 94; c11_i25++) {
    c11_arr[c11_i25] = c11_dv4[c11_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i26 = 0; c11_i26 < 256; c11_i26++) {
    c11_tt[c11_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i27 = 0; c11_i27 < 94; c11_i27++) {
    c11_tt[c11_i27] = c11_arr[c11_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i28 = 0; c11_i28 < 256; c11_i28++) {
    c11_myarr256[c11_i28] = c11_tt[c11_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_e_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[95];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[95];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i29;
  static char_T c11_cv5[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i30;
  static real_T c11_dv5[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i31;
  int32_T c11_i32;
  int32_T c11_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_f_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i29 = 0; c11_i29 < 95; c11_i29++) {
    c11_mystr[c11_i29] = c11_cv5[c11_i29];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i30 = 0; c11_i30 < 95; c11_i30++) {
    c11_arr[c11_i30] = c11_dv5[c11_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i31 = 0; c11_i31 < 256; c11_i31++) {
    c11_tt[c11_i31] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i32 = 0; c11_i32 < 95; c11_i32++) {
    c11_tt[c11_i32] = c11_arr[c11_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i33 = 0; c11_i33 < 256; c11_i33++) {
    c11_myarr256[c11_i33] = c11_tt[c11_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_f_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[88];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[88];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i34;
  static char_T c11_cv6[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c11_i35;
  static real_T c11_dv6[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i36;
  int32_T c11_i37;
  int32_T c11_i38;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_g_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i34 = 0; c11_i34 < 88; c11_i34++) {
    c11_mystr[c11_i34] = c11_cv6[c11_i34];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i35 = 0; c11_i35 < 88; c11_i35++) {
    c11_arr[c11_i35] = c11_dv6[c11_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i36 = 0; c11_i36 < 256; c11_i36++) {
    c11_tt[c11_i36] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i37 = 0; c11_i37 < 88; c11_i37++) {
    c11_tt[c11_i37] = c11_arr[c11_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i38 = 0; c11_i38 < 256; c11_i38++) {
    c11_myarr256[c11_i38] = c11_tt[c11_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_g_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[93];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[93];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i39;
  static char_T c11_cv7[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i40;
  static real_T c11_dv7[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i41;
  int32_T c11_i42;
  int32_T c11_i43;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_h_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i39 = 0; c11_i39 < 93; c11_i39++) {
    c11_mystr[c11_i39] = c11_cv7[c11_i39];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i40 = 0; c11_i40 < 93; c11_i40++) {
    c11_arr[c11_i40] = c11_dv7[c11_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i41 = 0; c11_i41 < 256; c11_i41++) {
    c11_tt[c11_i41] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i42 = 0; c11_i42 < 93; c11_i42++) {
    c11_tt[c11_i42] = c11_arr[c11_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i43 = 0; c11_i43 < 256; c11_i43++) {
    c11_myarr256[c11_i43] = c11_tt[c11_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_h_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[93];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[93];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i44;
  static char_T c11_cv8[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i45;
  static real_T c11_dv8[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i46;
  int32_T c11_i47;
  int32_T c11_i48;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_i_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i44 = 0; c11_i44 < 93; c11_i44++) {
    c11_mystr[c11_i44] = c11_cv8[c11_i44];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i45 = 0; c11_i45 < 93; c11_i45++) {
    c11_arr[c11_i45] = c11_dv8[c11_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i46 = 0; c11_i46 < 256; c11_i46++) {
    c11_tt[c11_i46] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i47 = 0; c11_i47 < 93; c11_i47++) {
    c11_tt[c11_i47] = c11_arr[c11_i47];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i48 = 0; c11_i48 < 256; c11_i48++) {
    c11_myarr256[c11_i48] = c11_tt[c11_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_i_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[97];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[97];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i49;
  static char_T c11_cv9[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i50;
  static real_T c11_dv9[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_j_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i49 = 0; c11_i49 < 97; c11_i49++) {
    c11_mystr[c11_i49] = c11_cv9[c11_i49];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i50 = 0; c11_i50 < 97; c11_i50++) {
    c11_arr[c11_i50] = c11_dv9[c11_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i51 = 0; c11_i51 < 256; c11_i51++) {
    c11_tt[c11_i51] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i52 = 0; c11_i52 < 97; c11_i52++) {
    c11_tt[c11_i52] = c11_arr[c11_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i53 = 0; c11_i53 < 256; c11_i53++) {
    c11_myarr256[c11_i53] = c11_tt[c11_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_j_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[97];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[97];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i54;
  static char_T c11_cv10[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i55;
  static real_T c11_dv10[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i56;
  int32_T c11_i57;
  int32_T c11_i58;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_k_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i54 = 0; c11_i54 < 97; c11_i54++) {
    c11_mystr[c11_i54] = c11_cv10[c11_i54];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i55 = 0; c11_i55 < 97; c11_i55++) {
    c11_arr[c11_i55] = c11_dv10[c11_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i56 = 0; c11_i56 < 256; c11_i56++) {
    c11_tt[c11_i56] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i57 = 0; c11_i57 < 97; c11_i57++) {
    c11_tt[c11_i57] = c11_arr[c11_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i58 = 0; c11_i58 < 256; c11_i58++) {
    c11_myarr256[c11_i58] = c11_tt[c11_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_k_encStr2Arr(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[92];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[92];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i59;
  static char_T c11_cv11[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h',
    'H', 'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i60;
  static real_T c11_dv11[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c11_i61;
  int32_T c11_i62;
  int32_T c11_i63;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_l_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i59 = 0; c11_i59 < 92; c11_i59++) {
    c11_mystr[c11_i59] = c11_cv11[c11_i59];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i60 = 0; c11_i60 < 92; c11_i60++) {
    c11_arr[c11_i60] = c11_dv11[c11_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i61 = 0; c11_i61 < 256; c11_i61++) {
    c11_tt[c11_i61] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i62 = 0; c11_i62 < 92; c11_i62++) {
    c11_tt[c11_i62] = c11_arr[c11_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i63 = 0; c11_i63 < 256; c11_i63++) {
    c11_myarr256[c11_i63] = c11_tt[c11_i63];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c11_rand(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  return c11_eml_rand(chartInstance);
}

static real_T c11_eml_rand(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  real_T c11_r;
  uint32_T c11_hoistedGlobal;
  uint32_T c11_d_state;
  uint32_T c11_e_state;
  uint32_T c11_s;
  uint32_T c11_u0;
  uint32_T c11_hi;
  uint32_T c11_lo;
  uint32_T c11_test1;
  uint32_T c11_test2;
  uint32_T c11_f_state;
  real_T c11_b_r;
  real_T c11_d0;
  int32_T c11_i64;
  uint32_T c11_icng;
  uint32_T c11_jsr;
  uint32_T c11_u1;
  uint32_T c11_u2;
  uint32_T c11_ui;
  uint32_T c11_b_ui;
  real_T c11_c_r;
  real_T c11_d1;
  uint32_T c11_uv2[625];
  int32_T c11_i65;
  real_T c11_d2;
  if (!chartInstance->c11_method_not_empty) {
    chartInstance->c11_method = 7U;
    chartInstance->c11_method_not_empty = true;
  }

  if (chartInstance->c11_method == 4U) {
    if (!chartInstance->c11_state_not_empty) {
      chartInstance->c11_state = 1144108930U;
      chartInstance->c11_state_not_empty = true;
    }

    c11_hoistedGlobal = chartInstance->c11_state;
    c11_d_state = c11_hoistedGlobal;
    c11_e_state = c11_d_state;
    c11_s = c11_e_state;
    c11_u0 = 127773U;
    if (c11_u0 == 0U) {
      c11_hi = MAX_uint32_T;
    } else {
      c11_hi = c11_s / c11_u0;
    }

    c11_lo = c11_s - c11_hi * 127773U;
    c11_test1 = 16807U * c11_lo;
    c11_test2 = 2836U * c11_hi;
    if (c11_test1 < c11_test2) {
      c11_f_state = (c11_test1 - c11_test2) + 2147483647U;
    } else {
      c11_f_state = c11_test1 - c11_test2;
    }

    c11_b_r = (real_T)c11_f_state * 4.6566128752457969E-10;
    c11_e_state = c11_f_state;
    c11_d0 = c11_b_r;
    chartInstance->c11_state = c11_e_state;
    c11_r = c11_d0;
  } else if (chartInstance->c11_method == 5U) {
    if (!chartInstance->c11_b_state_not_empty) {
      for (c11_i64 = 0; c11_i64 < 2; c11_i64++) {
        chartInstance->c11_b_state[c11_i64] = 362436069U + 158852560U *
          (uint32_T)c11_i64;
      }

      chartInstance->c11_b_state_not_empty = true;
    }

    c11_icng = chartInstance->c11_b_state[0];
    c11_jsr = chartInstance->c11_b_state[1];
    c11_u1 = c11_jsr;
    c11_u2 = c11_icng;
    c11_u2 = 69069U * c11_u2 + 1234567U;
    c11_u1 ^= c11_u1 << 13;
    c11_u1 ^= c11_u1 >> 17;
    c11_u1 ^= c11_u1 << 5;
    c11_ui = c11_u2 + c11_u1;
    chartInstance->c11_b_state[0] = c11_u2;
    chartInstance->c11_b_state[1] = c11_u1;
    c11_b_ui = c11_ui;
    c11_c_r = (real_T)c11_b_ui * 2.328306436538696E-10;
    c11_d1 = c11_c_r;
    c11_r = c11_d1;
  } else {
    if (!chartInstance->c11_c_state_not_empty) {
      c11_eml_rand_mt19937ar(chartInstance, c11_uv2);
      for (c11_i65 = 0; c11_i65 < 625; c11_i65++) {
        chartInstance->c11_c_state[c11_i65] = c11_uv2[c11_i65];
      }

      chartInstance->c11_c_state_not_empty = true;
    }

    c11_d2 = c11_c_eml_rand_mt19937ar(chartInstance, chartInstance->c11_c_state);
    c11_r = c11_d2;
  }

  return c11_r;
}

static void c11_eml_rand_mt19937ar
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_d_state[625])
{
  real_T c11_d3;
  int32_T c11_i66;
  c11_d3 = 5489.0;
  for (c11_i66 = 0; c11_i66 < 625; c11_i66++) {
    c11_d_state[c11_i66] = 0U;
  }

  c11_b_twister_state_vector(chartInstance, c11_d_state, c11_d3);
}

static void c11_twister_state_vector
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_mt[625], real_T c11_seed, uint32_T c11_b_mt[625])
{
  int32_T c11_i67;
  for (c11_i67 = 0; c11_i67 < 625; c11_i67++) {
    c11_b_mt[c11_i67] = c11_mt[c11_i67];
  }

  c11_b_twister_state_vector(chartInstance, c11_b_mt, c11_seed);
}

static void c11_b_eml_rand_mt19937ar
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_d_state[625], uint32_T c11_e_state[625], real_T *c11_r)
{
  int32_T c11_i68;
  for (c11_i68 = 0; c11_i68 < 625; c11_i68++) {
    c11_e_state[c11_i68] = c11_d_state[c11_i68];
  }

  *c11_r = c11_c_eml_rand_mt19937ar(chartInstance, c11_e_state);
}

static void c11_eml_error(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  int32_T c11_i69;
  static char_T c11_cv12[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i',
    'd', 'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c11_u[37];
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  for (c11_i69 = 0; c11_i69 < 37; c11_i69++) {
    c11_u[c11_i69] = c11_cv12[c11_i69];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 37),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c11_y));
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i70;
  real_T c11_b_inData[256];
  int32_T c11_i71;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i70 = 0; c11_i70 < 256; c11_i70++) {
    c11_b_inData[c11_i70] = (*(real_T (*)[256])c11_inData)[c11_i70];
  }

  for (c11_i71 = 0; c11_i71 < 256; c11_i71++) {
    c11_u[c11_i71] = c11_b_inData[c11_i71];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv12[256];
  int32_T c11_i72;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv12, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c11_i72 = 0; c11_i72 < 256; c11_i72++) {
    c11_y[c11_i72] = c11_dv12[c11_i72];
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
  int32_T c11_i73;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_poseBML = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_poseBML), &c11_thisId,
                       c11_y);
  sf_mex_destroy(&c11_poseBML);
  for (c11_i73 = 0; c11_i73 < 256; c11_i73++) {
    (*(real_T (*)[256])c11_outData)[c11_i73] = c11_y[c11_i73];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_b_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d4;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d4, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d4;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_bmlID;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_bmlID = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_bmlID),
    &c11_thisId);
  sf_mex_destroy(&c11_bmlID);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_c_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
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
  const mxArray *c11_aVarTruthTableCondition_18;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_aVarTruthTableCondition_18 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_aVarTruthTableCondition_18), &c11_thisId);
  sf_mex_destroy(&c11_aVarTruthTableCondition_18);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i74;
  real_T c11_b_inData[256];
  int32_T c11_i75;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i74 = 0; c11_i74 < 256; c11_i74++) {
    c11_b_inData[c11_i74] = (*(real_T (*)[256])c11_inData)[c11_i74];
  }

  for (c11_i75 = 0; c11_i75 < 256; c11_i75++) {
    c11_u[c11_i75] = c11_b_inData[c11_i75];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_d_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId, real_T c11_y[256])
{
  real_T c11_dv13[256];
  int32_T c11_i76;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv13, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c11_i76 = 0; c11_i76 < 256; c11_i76++) {
    c11_y[c11_i76] = c11_dv13[c11_i76];
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
  int32_T c11_i77;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_myarr256 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
  for (c11_i77 = 0; c11_i77 < 256; c11_i77++) {
    (*(real_T (*)[256])c11_outData)[c11_i77] = c11_y[c11_i77];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i78;
  char_T c11_b_inData[91];
  int32_T c11_i79;
  char_T c11_u[91];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i78 = 0; c11_i78 < 91; c11_i78++) {
    c11_b_inData[c11_i78] = (*(char_T (*)[91])c11_inData)[c11_i78];
  }

  for (c11_i79 = 0; c11_i79 < 91; c11_i79++) {
    c11_u[c11_i79] = c11_b_inData[c11_i79];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 91),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i80;
  real_T c11_b_inData[91];
  int32_T c11_i81;
  real_T c11_u[91];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i80 = 0; c11_i80 < 91; c11_i80++) {
    c11_b_inData[c11_i80] = (*(real_T (*)[91])c11_inData)[c11_i80];
  }

  for (c11_i81 = 0; c11_i81 < 91; c11_i81++) {
    c11_u[c11_i81] = c11_b_inData[c11_i81];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i82;
  char_T c11_b_inData[87];
  int32_T c11_i83;
  char_T c11_u[87];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i82 = 0; c11_i82 < 87; c11_i82++) {
    c11_b_inData[c11_i82] = (*(char_T (*)[87])c11_inData)[c11_i82];
  }

  for (c11_i83 = 0; c11_i83 < 87; c11_i83++) {
    c11_u[c11_i83] = c11_b_inData[c11_i83];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 87),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i84;
  real_T c11_b_inData[87];
  int32_T c11_i85;
  real_T c11_u[87];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i84 = 0; c11_i84 < 87; c11_i84++) {
    c11_b_inData[c11_i84] = (*(real_T (*)[87])c11_inData)[c11_i84];
  }

  for (c11_i85 = 0; c11_i85 < 87; c11_i85++) {
    c11_u[c11_i85] = c11_b_inData[c11_i85];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i86;
  char_T c11_b_inData[93];
  int32_T c11_i87;
  char_T c11_u[93];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i86 = 0; c11_i86 < 93; c11_i86++) {
    c11_b_inData[c11_i86] = (*(char_T (*)[93])c11_inData)[c11_i86];
  }

  for (c11_i87 = 0; c11_i87 < 93; c11_i87++) {
    c11_u[c11_i87] = c11_b_inData[c11_i87];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 93),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i88;
  real_T c11_b_inData[93];
  int32_T c11_i89;
  real_T c11_u[93];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i88 = 0; c11_i88 < 93; c11_i88++) {
    c11_b_inData[c11_i88] = (*(real_T (*)[93])c11_inData)[c11_i88];
  }

  for (c11_i89 = 0; c11_i89 < 93; c11_i89++) {
    c11_u[c11_i89] = c11_b_inData[c11_i89];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i90;
  char_T c11_b_inData[94];
  int32_T c11_i91;
  char_T c11_u[94];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i90 = 0; c11_i90 < 94; c11_i90++) {
    c11_b_inData[c11_i90] = (*(char_T (*)[94])c11_inData)[c11_i90];
  }

  for (c11_i91 = 0; c11_i91 < 94; c11_i91++) {
    c11_u[c11_i91] = c11_b_inData[c11_i91];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 94),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i92;
  real_T c11_b_inData[94];
  int32_T c11_i93;
  real_T c11_u[94];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i92 = 0; c11_i92 < 94; c11_i92++) {
    c11_b_inData[c11_i92] = (*(real_T (*)[94])c11_inData)[c11_i92];
  }

  for (c11_i93 = 0; c11_i93 < 94; c11_i93++) {
    c11_u[c11_i93] = c11_b_inData[c11_i93];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i94;
  char_T c11_b_inData[95];
  int32_T c11_i95;
  char_T c11_u[95];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i94 = 0; c11_i94 < 95; c11_i94++) {
    c11_b_inData[c11_i94] = (*(char_T (*)[95])c11_inData)[c11_i94];
  }

  for (c11_i95 = 0; c11_i95 < 95; c11_i95++) {
    c11_u[c11_i95] = c11_b_inData[c11_i95];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 95),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i96;
  real_T c11_b_inData[95];
  int32_T c11_i97;
  real_T c11_u[95];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i96 = 0; c11_i96 < 95; c11_i96++) {
    c11_b_inData[c11_i96] = (*(real_T (*)[95])c11_inData)[c11_i96];
  }

  for (c11_i97 = 0; c11_i97 < 95; c11_i97++) {
    c11_u[c11_i97] = c11_b_inData[c11_i97];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i98;
  char_T c11_b_inData[88];
  int32_T c11_i99;
  char_T c11_u[88];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i98 = 0; c11_i98 < 88; c11_i98++) {
    c11_b_inData[c11_i98] = (*(char_T (*)[88])c11_inData)[c11_i98];
  }

  for (c11_i99 = 0; c11_i99 < 88; c11_i99++) {
    c11_u[c11_i99] = c11_b_inData[c11_i99];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 88),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i100;
  real_T c11_b_inData[88];
  int32_T c11_i101;
  real_T c11_u[88];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i100 = 0; c11_i100 < 88; c11_i100++) {
    c11_b_inData[c11_i100] = (*(real_T (*)[88])c11_inData)[c11_i100];
  }

  for (c11_i101 = 0; c11_i101 < 88; c11_i101++) {
    c11_u[c11_i101] = c11_b_inData[c11_i101];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i102;
  char_T c11_b_inData[97];
  int32_T c11_i103;
  char_T c11_u[97];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i102 = 0; c11_i102 < 97; c11_i102++) {
    c11_b_inData[c11_i102] = (*(char_T (*)[97])c11_inData)[c11_i102];
  }

  for (c11_i103 = 0; c11_i103 < 97; c11_i103++) {
    c11_u[c11_i103] = c11_b_inData[c11_i103];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 97),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_r_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i104;
  real_T c11_b_inData[97];
  int32_T c11_i105;
  real_T c11_u[97];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i104 = 0; c11_i104 < 97; c11_i104++) {
    c11_b_inData[c11_i104] = (*(real_T (*)[97])c11_inData)[c11_i104];
  }

  for (c11_i105 = 0; c11_i105 < 97; c11_i105++) {
    c11_u[c11_i105] = c11_b_inData[c11_i105];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_s_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i106;
  char_T c11_b_inData[92];
  int32_T c11_i107;
  char_T c11_u[92];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i106 = 0; c11_i106 < 92; c11_i106++) {
    c11_b_inData[c11_i106] = (*(char_T (*)[92])c11_inData)[c11_i106];
  }

  for (c11_i107 = 0; c11_i107 < 92; c11_i107++) {
    c11_u[c11_i107] = c11_b_inData[c11_i107];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 92),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_t_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i108;
  real_T c11_b_inData[92];
  int32_T c11_i109;
  real_T c11_u[92];
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i108 = 0; c11_i108 < 92; c11_i108++) {
    c11_b_inData[c11_i108] = (*(real_T (*)[92])c11_inData)[c11_i108];
  }

  for (c11_i109 = 0; c11_i109 < 92; c11_i109++) {
    c11_u[c11_i109] = c11_b_inData[c11_i109];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

const mxArray *sf_c11_lib_affectiveChar_scenario_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 38, 1),
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("all"), "name", "name", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372614814U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372615558U), "fileTimeLo",
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
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
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
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("randi"), "name", "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("rand"), "name", "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand"), "name", "name",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eps"), "name", "name", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_eps"), "name", "name",
                  26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name",
                  28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnan"), "name", "name", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_error"), "name", "name",
                  34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("floor"), "name", "name", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
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

static void c11_activate_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = c11_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_deactivate_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_increment_counters_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c11_temporalCounter_i1 < 3U) {
    chartInstance->c11_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c11_temporalCounter_i1 + 1);
  }
}

static void c11_reset_counters_secsc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c11_lib_affectiveChar_scenario_secs(SimStruct
  *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_activate_secsc11_lib_affectiveChar_scenario(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_increment_counters_secsc11_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c11_lib_affectiveChar_scenario_secs
  (SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_reset_counters_secsc11_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_deactivate_c11_lib_affectiveChar_scenario_secs(SimStruct
  *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_deactivate_secsc11_lib_affectiveChar_scenario(chartInstance);
}

boolean_T sf_exported_auto_isStablec11_lib_affectiveChar_scenario(SimStruct
  *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_c11_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_enterc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_sendBML(chartInstance);
  c11_enter_atomic_c11_lib_affectiveChar_scenario(chartInstance);
  c11_enter_internal_c11_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_exitc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_lib_affectiveChar_scenario(chartInstance);
  c11_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_sendBML(chartInstance);
}

void sf_exported_auto_disablec11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc11_lib_affectiveChar_scenario(SimStruct
  *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc11_lib_affectiveChar_scenario
  (SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc11_lib_affectiveChar_scenario(SimStruct
  *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc11_lib_affectiveChar_scenario(SimStruct
  *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc11_lib_affectiveChar_scenario(SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_initc11_lib_affectiveChar_scenario(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_lib_affectiveChar_scenario
  (SimStruct *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out,
                sf_internal_get_sim_state_c11_lib_affectiveChar_scenario(c11_S),
                false);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_lib_affectiveChar_scenario(SimStruct *c11_S,
  const mxArray *c11_in)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c11_lib_affectiveChar_scenario(c11_S, sf_mex_dup
    (c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_lib_affectiveChar_scenario
  (SimStruct *c11_S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_scenarioMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_sendBMLc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c11_arg[256])
{
  int32_T c11_i110;
  int32_T c11_i111;
  int32_T c11_i112;
  real_T (*c11_b_arg)[256];
  c11_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c11_i110 = 0; c11_i110 < 256; c11_i110++) {
    _SFD_DATA_RANGE_CHECK(c11_arg[c11_i110], 5U);
  }

  _SFD_SET_DATA_VALUE_PTR(5U, c11_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c11_arg, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
  for (c11_i111 = 0; c11_i111 < 256; c11_i111++) {
    (*c11_b_arg)[c11_i111] = c11_arg[c11_i111];
  }

  for (c11_i112 = 0; c11_i112 < 256; c11_i112++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_arg)[c11_i112], 5U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(5U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
}

static void c11_boredPoseSc11_lib_affectiveChar_scenario
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c11_bmlID, real_T c11_poseBML[256])
{
  uint32_T c11_debug_family_var_map[22];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  boolean_T c11_aVarTruthTableCondition_3;
  boolean_T c11_aVarTruthTableCondition_4;
  boolean_T c11_aVarTruthTableCondition_5;
  boolean_T c11_aVarTruthTableCondition_6;
  boolean_T c11_aVarTruthTableCondition_7;
  boolean_T c11_aVarTruthTableCondition_8;
  boolean_T c11_aVarTruthTableCondition_9;
  boolean_T c11_aVarTruthTableCondition_10;
  boolean_T c11_aVarTruthTableCondition_11;
  boolean_T c11_aVarTruthTableCondition_12;
  boolean_T c11_aVarTruthTableCondition_13;
  boolean_T c11_aVarTruthTableCondition_14;
  boolean_T c11_aVarTruthTableCondition_15;
  boolean_T c11_aVarTruthTableCondition_16;
  boolean_T c11_aVarTruthTableCondition_17;
  boolean_T c11_aVarTruthTableCondition_18;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_dv14[256];
  int32_T c11_i113;
  int32_T c11_i114;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  int32_T c11_i115;
  int32_T c11_i116;
  real_T c11_b_u[256];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i117;
  int32_T c11_i118;
  real_T c11_c_u[256];
  const mxArray *c11_c_y = NULL;
  int32_T c11_i119;
  int32_T c11_i120;
  real_T c11_d_u[256];
  const mxArray *c11_d_y = NULL;
  int32_T c11_i121;
  int32_T c11_i122;
  real_T c11_e_u[256];
  const mxArray *c11_e_y = NULL;
  int32_T c11_i123;
  int32_T c11_i124;
  real_T c11_f_u[256];
  const mxArray *c11_f_y = NULL;
  int32_T c11_i125;
  int32_T c11_i126;
  real_T c11_g_u[256];
  const mxArray *c11_g_y = NULL;
  int32_T c11_i127;
  int32_T c11_i128;
  real_T c11_h_u[256];
  const mxArray *c11_h_y = NULL;
  int32_T c11_i129;
  int32_T c11_i130;
  real_T c11_i_u[256];
  const mxArray *c11_i_y = NULL;
  int32_T c11_i131;
  int32_T c11_i132;
  real_T c11_j_u[256];
  const mxArray *c11_j_y = NULL;
  int32_T c11_i133;
  int32_T c11_i134;
  real_T c11_k_u[256];
  const mxArray *c11_k_y = NULL;
  int32_T c11_i135;
  int32_T c11_i136;
  real_T c11_l_u[256];
  const mxArray *c11_l_y = NULL;
  int32_T c11_i137;
  int32_T c11_i138;
  real_T c11_m_u[256];
  const mxArray *c11_m_y = NULL;
  int32_T c11_i139;
  int32_T c11_i140;
  real_T c11_n_u[256];
  const mxArray *c11_n_y = NULL;
  int32_T c11_i141;
  int32_T c11_i142;
  real_T c11_o_u[256];
  const mxArray *c11_o_y = NULL;
  int32_T c11_i143;
  int32_T c11_i144;
  real_T c11_p_u[256];
  const mxArray *c11_p_y = NULL;
  int32_T c11_i145;
  int32_T c11_i146;
  real_T c11_q_u[256];
  const mxArray *c11_q_y = NULL;
  int32_T c11_i147;
  int32_T c11_i148;
  real_T c11_r_u[256];
  const mxArray *c11_r_y = NULL;
  int32_T c11_i149;
  int32_T c11_i150;
  real_T c11_s_u[256];
  const mxArray *c11_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_1, 0U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_2, 1U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_3, 2U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_4, 3U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_5, 4U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_6, 5U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_7, 6U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_8, 7U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_9, 8U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_10, 9U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_11, 10U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_12, 11U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_13, 12U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_14, 13U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_15, 14U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_16, 15U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_17, 16U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_18, 17U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 18U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 19U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_bmlID, 20U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_poseBML, 21U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  c11_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
  c11_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 12);
  c11_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 14);
  c11_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 15);
  c11_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
  c11_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 17);
  c11_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
  c11_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 19);
  c11_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
  c11_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 24);
  c11_aVarTruthTableCondition_1 = c11_all(chartInstance, c11_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_aVarTruthTableCondition_2 = c11_all(chartInstance, c11_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 30);
  c11_aVarTruthTableCondition_3 = c11_all(chartInstance, c11_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
  c11_aVarTruthTableCondition_4 = c11_all(chartInstance, c11_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 36);
  c11_aVarTruthTableCondition_5 = c11_all(chartInstance, c11_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 39);
  c11_aVarTruthTableCondition_6 = c11_all(chartInstance, c11_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 42);
  c11_aVarTruthTableCondition_7 = c11_all(chartInstance, c11_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 45);
  c11_aVarTruthTableCondition_8 = c11_all(chartInstance, c11_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 48);
  c11_aVarTruthTableCondition_9 = c11_all(chartInstance, c11_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 51);
  c11_aVarTruthTableCondition_10 = c11_all(chartInstance, c11_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 54);
  c11_aVarTruthTableCondition_11 = c11_all(chartInstance, c11_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 57);
  c11_aVarTruthTableCondition_12 = c11_all(chartInstance, c11_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 60);
  c11_aVarTruthTableCondition_13 = c11_all(chartInstance, c11_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 63);
  c11_aVarTruthTableCondition_14 = c11_all(chartInstance, c11_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 66);
  c11_aVarTruthTableCondition_15 = c11_all(chartInstance, c11_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 69);
  c11_aVarTruthTableCondition_16 = c11_all(chartInstance, c11_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 72);
  c11_aVarTruthTableCondition_17 = c11_all(chartInstance, c11_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 75);
  c11_aVarTruthTableCondition_18 = c11_all(chartInstance, c11_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 77);
  if (CV_EML_IF(0, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 78);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 121);
    c11_encStr2Arr(chartInstance, c11_dv14);
    for (c11_i113 = 0; c11_i113 < 256; c11_i113++) {
      c11_poseBML[c11_i113] = c11_dv14[c11_i113];
    }

    c11_updateDataWrittenToVector(chartInstance, 0U);
    c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c11_i114 = 0; c11_i114 < 256; c11_i114++) {
      c11_u[c11_i114] = c11_poseBML[c11_i114];
    }

    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 256),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c11_y);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -121);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 79);
    if (CV_EML_IF(0, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 80);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, MAX_int8_T);
      c11_b_encStr2Arr(chartInstance, c11_dv14);
      for (c11_i115 = 0; c11_i115 < 256; c11_i115++) {
        c11_poseBML[c11_i115] = c11_dv14[c11_i115];
      }

      c11_updateDataWrittenToVector(chartInstance, 0U);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c11_i116 = 0; c11_i116 < 256; c11_i116++) {
        c11_b_u[c11_i116] = c11_poseBML[c11_i116];
      }

      c11_b_y = NULL;
      sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c11_b_y);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -127);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 81);
      if (CV_EML_IF(0, 1, 2, c11_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 82);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 133U);
        c11_c_encStr2Arr(chartInstance, c11_dv14);
        for (c11_i117 = 0; c11_i117 < 256; c11_i117++) {
          c11_poseBML[c11_i117] = c11_dv14[c11_i117];
        }

        c11_updateDataWrittenToVector(chartInstance, 0U);
        c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c11_i118 = 0; c11_i118 < 256; c11_i118++) {
          c11_c_u[c11_i118] = c11_poseBML[c11_i118];
        }

        c11_c_y = NULL;
        sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 1,
          256), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c11_c_y);
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -133);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 83);
        if (CV_EML_IF(0, 1, 3, c11_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 84);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 139U);
          c11_d_encStr2Arr(chartInstance, c11_dv14);
          for (c11_i119 = 0; c11_i119 < 256; c11_i119++) {
            c11_poseBML[c11_i119] = c11_dv14[c11_i119];
          }

          c11_updateDataWrittenToVector(chartInstance, 0U);
          c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c11_i120 = 0; c11_i120 < 256; c11_i120++) {
            c11_d_u[c11_i120] = c11_poseBML[c11_i120];
          }

          c11_d_y = NULL;
          sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c11_d_y);
          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -139);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 85);
          if (CV_EML_IF(0, 1, 4, c11_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 86);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 145U);
            c11_e_encStr2Arr(chartInstance, c11_dv14);
            for (c11_i121 = 0; c11_i121 < 256; c11_i121++) {
              c11_poseBML[c11_i121] = c11_dv14[c11_i121];
            }

            c11_updateDataWrittenToVector(chartInstance, 0U);
            c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c11_i122 = 0; c11_i122 < 256; c11_i122++) {
              c11_e_u[c11_i122] = c11_poseBML[c11_i122];
            }

            c11_e_y = NULL;
            sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c11_e_y);
            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -145);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 87);
            if (CV_EML_IF(0, 1, 5, c11_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 88);
              CV_EML_FCN(0, 11);
              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 181U);
              c11_f_encStr2Arr(chartInstance, c11_dv14);
              for (c11_i123 = 0; c11_i123 < 256; c11_i123++) {
                c11_poseBML[c11_i123] = c11_dv14[c11_i123];
              }

              c11_updateDataWrittenToVector(chartInstance, 0U);
              c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c11_i124 = 0; c11_i124 < 256; c11_i124++) {
                c11_f_u[c11_i124] = c11_poseBML[c11_i124];
              }

              c11_f_y = NULL;
              sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_f_u, 0, 0U, 1U, 0U,
                1, 256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c11_f_y);
              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -181);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 89);
              if (CV_EML_IF(0, 1, 6, c11_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 90);
                CV_EML_FCN(0, 3);
                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 133U);
                c11_c_encStr2Arr(chartInstance, c11_dv14);
                for (c11_i125 = 0; c11_i125 < 256; c11_i125++) {
                  c11_poseBML[c11_i125] = c11_dv14[c11_i125];
                }

                c11_updateDataWrittenToVector(chartInstance, 0U);
                c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c11_i126 = 0; c11_i126 < 256; c11_i126++) {
                  c11_g_u[c11_i126] = c11_poseBML[c11_i126];
                }

                c11_g_y = NULL;
                sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_g_u, 0, 0U, 1U,
                  0U, 1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c11_g_y);
                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -133);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 91);
                if (CV_EML_IF(0, 1, 7, c11_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 92);
                  CV_EML_FCN(0, 5);
                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 145U);
                  c11_e_encStr2Arr(chartInstance, c11_dv14);
                  for (c11_i127 = 0; c11_i127 < 256; c11_i127++) {
                    c11_poseBML[c11_i127] = c11_dv14[c11_i127];
                  }

                  c11_updateDataWrittenToVector(chartInstance, 0U);
                  c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c11_i128 = 0; c11_i128 < 256; c11_i128++) {
                    c11_h_u[c11_i128] = c11_poseBML[c11_i128];
                  }

                  c11_h_y = NULL;
                  sf_mex_assign(&c11_h_y, sf_mex_create("y", c11_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c11_h_y);
                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 93);
                  if (CV_EML_IF(0, 1, 8, c11_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 94);
                    CV_EML_FCN(0, 3);
                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 133U);
                    c11_c_encStr2Arr(chartInstance, c11_dv14);
                    for (c11_i129 = 0; c11_i129 < 256; c11_i129++) {
                      c11_poseBML[c11_i129] = c11_dv14[c11_i129];
                    }

                    c11_updateDataWrittenToVector(chartInstance, 0U);
                    c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                    sf_mex_printf("%s =\\n", "poseBML");
                    for (c11_i130 = 0; c11_i130 < 256; c11_i130++) {
                      c11_i_u[c11_i130] = c11_poseBML[c11_i130];
                    }

                    c11_i_y = NULL;
                    sf_mex_assign(&c11_i_y, sf_mex_create("y", c11_i_u, 0, 0U,
                      1U, 0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c11_i_y);
                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 95);
                    if (CV_EML_IF(0, 1, 9, c11_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 96);
                      CV_EML_FCN(0, 10);
                      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 175U);
                      c11_g_encStr2Arr(chartInstance, c11_dv14);
                      for (c11_i131 = 0; c11_i131 < 256; c11_i131++) {
                        c11_poseBML[c11_i131] = c11_dv14[c11_i131];
                      }

                      c11_updateDataWrittenToVector(chartInstance, 0U);
                      c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                      sf_mex_printf("%s =\\n", "poseBML");
                      for (c11_i132 = 0; c11_i132 < 256; c11_i132++) {
                        c11_j_u[c11_i132] = c11_poseBML[c11_i132];
                      }

                      c11_j_y = NULL;
                      sf_mex_assign(&c11_j_y, sf_mex_create("y", c11_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c11_j_y);
                      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 97);
                      if (CV_EML_IF(0, 1, 10, c11_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 98);
                        CV_EML_FCN(0, 11);
                        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 181U);
                        c11_f_encStr2Arr(chartInstance, c11_dv14);
                        for (c11_i133 = 0; c11_i133 < 256; c11_i133++) {
                          c11_poseBML[c11_i133] = c11_dv14[c11_i133];
                        }

                        c11_updateDataWrittenToVector(chartInstance, 0U);
                        c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                        sf_mex_printf("%s =\\n", "poseBML");
                        for (c11_i134 = 0; c11_i134 < 256; c11_i134++) {
                          c11_k_u[c11_i134] = c11_poseBML[c11_i134];
                        }

                        c11_k_y = NULL;
                        sf_mex_assign(&c11_k_y, sf_mex_create("y", c11_k_u, 0,
                          0U, 1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c11_k_y);
                        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 99);
                        if (CV_EML_IF(0, 1, 11, c11_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 100);
                          CV_EML_FCN(0, 8);
                          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 163U);
                          c11_h_encStr2Arr(chartInstance, c11_dv14);
                          for (c11_i135 = 0; c11_i135 < 256; c11_i135++) {
                            c11_poseBML[c11_i135] = c11_dv14[c11_i135];
                          }

                          c11_updateDataWrittenToVector(chartInstance, 0U);
                          c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                          sf_mex_printf("%s =\\n", "poseBML");
                          for (c11_i136 = 0; c11_i136 < 256; c11_i136++) {
                            c11_l_u[c11_i136] = c11_poseBML[c11_i136];
                          }

                          c11_l_y = NULL;
                          sf_mex_assign(&c11_l_y, sf_mex_create("y", c11_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c11_l_y);
                          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 101);
                          if (CV_EML_IF(0, 1, 12, c11_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 102);
                            CV_EML_FCN(0, 8);
                            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 163U);
                            c11_h_encStr2Arr(chartInstance, c11_dv14);
                            for (c11_i137 = 0; c11_i137 < 256; c11_i137++) {
                              c11_poseBML[c11_i137] = c11_dv14[c11_i137];
                            }

                            c11_updateDataWrittenToVector(chartInstance, 0U);
                            c11_errorIfDataNotWrittenToFcn(chartInstance, 0U, 7U);
                            sf_mex_printf("%s =\\n", "poseBML");
                            for (c11_i138 = 0; c11_i138 < 256; c11_i138++) {
                              c11_m_u[c11_i138] = c11_poseBML[c11_i138];
                            }

                            c11_m_y = NULL;
                            sf_mex_assign(&c11_m_y, sf_mex_create("y", c11_m_u,
                              0, 0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c11_m_y);
                            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 103);
                            if (CV_EML_IF(0, 1, 13,
                                          c11_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 104);
                              CV_EML_FCN(0, 7);
                              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 157U);
                              c11_i_encStr2Arr(chartInstance, c11_dv14);
                              for (c11_i139 = 0; c11_i139 < 256; c11_i139++) {
                                c11_poseBML[c11_i139] = c11_dv14[c11_i139];
                              }

                              c11_updateDataWrittenToVector(chartInstance, 0U);
                              c11_errorIfDataNotWrittenToFcn(chartInstance, 0U,
                                7U);
                              sf_mex_printf("%s =\\n", "poseBML");
                              for (c11_i140 = 0; c11_i140 < 256; c11_i140++) {
                                c11_n_u[c11_i140] = c11_poseBML[c11_i140];
                              }

                              c11_n_y = NULL;
                              sf_mex_assign(&c11_n_y, sf_mex_create("y", c11_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c11_n_y);
                              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 105);
                              if (CV_EML_IF(0, 1, 14,
                                            c11_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                              106);
                                CV_EML_FCN(0, 6);
                                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                              151U);
                                c11_j_encStr2Arr(chartInstance, c11_dv14);
                                for (c11_i141 = 0; c11_i141 < 256; c11_i141++) {
                                  c11_poseBML[c11_i141] = c11_dv14[c11_i141];
                                }

                                c11_updateDataWrittenToVector(chartInstance, 0U);
                                c11_errorIfDataNotWrittenToFcn(chartInstance, 0U,
                                  7U);
                                sf_mex_printf("%s =\\n", "poseBML");
                                for (c11_i142 = 0; c11_i142 < 256; c11_i142++) {
                                  c11_o_u[c11_i142] = c11_poseBML[c11_i142];
                                }

                                c11_o_y = NULL;
                                sf_mex_assign(&c11_o_y, sf_mex_create("y",
                                  c11_o_u, 0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c11_o_y);
                                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                              107);
                                if (CV_EML_IF(0, 1, 15,
                                              c11_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                108);
                                  CV_EML_FCN(0, 5);
                                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                145U);
                                  c11_e_encStr2Arr(chartInstance, c11_dv14);
                                  for (c11_i143 = 0; c11_i143 < 256; c11_i143++)
                                  {
                                    c11_poseBML[c11_i143] = c11_dv14[c11_i143];
                                  }

                                  c11_updateDataWrittenToVector(chartInstance,
                                    0U);
                                  c11_errorIfDataNotWrittenToFcn(chartInstance,
                                    0U, 7U);
                                  sf_mex_printf("%s =\\n", "poseBML");
                                  for (c11_i144 = 0; c11_i144 < 256; c11_i144++)
                                  {
                                    c11_p_u[c11_i144] = c11_poseBML[c11_i144];
                                  }

                                  c11_p_y = NULL;
                                  sf_mex_assign(&c11_p_y, sf_mex_create("y",
                                    c11_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c11_p_y);
                                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                109);
                                  if (CV_EML_IF(0, 1, 16,
                                                c11_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                  110);
                                    CV_EML_FCN(0, 8);
                                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                  163U);
                                    c11_h_encStr2Arr(chartInstance, c11_dv14);
                                    for (c11_i145 = 0; c11_i145 < 256; c11_i145
                                         ++) {
                                      c11_poseBML[c11_i145] = c11_dv14[c11_i145];
                                    }

                                    c11_updateDataWrittenToVector(chartInstance,
                                      0U);
                                    c11_errorIfDataNotWrittenToFcn(chartInstance,
                                      0U, 7U);
                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c11_i146 = 0; c11_i146 < 256; c11_i146
                                         ++) {
                                      c11_q_u[c11_i146] = c11_poseBML[c11_i146];
                                    }

                                    c11_q_y = NULL;
                                    sf_mex_assign(&c11_q_y, sf_mex_create("y",
                                      c11_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c11_q_y);
                                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent,
                                                  111);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c11_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c11_sfEvent,
                                                    112);
                                      CV_EML_FCN(0, 9);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c11_sfEvent,
                                                    169U);
                                      c11_k_encStr2Arr(chartInstance, c11_dv14);
                                      for (c11_i147 = 0; c11_i147 < 256;
                                           c11_i147++) {
                                        c11_poseBML[c11_i147] =
                                          c11_dv14[c11_i147];
                                      }

                                      c11_updateDataWrittenToVector
                                        (chartInstance, 0U);
                                      c11_errorIfDataNotWrittenToFcn
                                        (chartInstance, 0U, 7U);
                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c11_i148 = 0; c11_i148 < 256;
                                           c11_i148++) {
                                        c11_r_u[c11_i148] = c11_poseBML[c11_i148];
                                      }

                                      c11_r_y = NULL;
                                      sf_mex_assign(&c11_r_y, sf_mex_create("y",
                                        c11_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c11_r_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c11_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c11_sfEvent,
                                                    114);
                                      CV_EML_FCN(0, 3);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c11_sfEvent,
                                                    133U);
                                      c11_c_encStr2Arr(chartInstance, c11_dv14);
                                      for (c11_i149 = 0; c11_i149 < 256;
                                           c11_i149++) {
                                        c11_poseBML[c11_i149] =
                                          c11_dv14[c11_i149];
                                      }

                                      c11_updateDataWrittenToVector
                                        (chartInstance, 0U);
                                      c11_errorIfDataNotWrittenToFcn
                                        (chartInstance, 0U, 7U);
                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c11_i150 = 0; c11_i150 < 256;
                                           c11_i150++) {
                                        c11_s_u[c11_i150] = c11_poseBML[c11_i150];
                                      }

                                      c11_s_y = NULL;
                                      sf_mex_assign(&c11_s_y, sf_mex_create("y",
                                        c11_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c11_s_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c11_sfEvent,
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

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_sendBML(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c11_b_sendBML(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static boolean_T c11_all(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, boolean_T c11_x)
{
  boolean_T c11_b_x;
  (void)chartInstance;
  c11_b_x = c11_x;
  return (real_T)c11_b_x != 0.0;
}

void sf_exported_user_c11_lib_affectiveChar_scenario_boredPoseS(SimStruct *c11_S,
  real_T c11_bmlID, real_T c11_poseBML[256])
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  c11_boredPoseSc11_lib_affectiveChar_scenario(chartInstance, c11_bmlID,
    c11_poseBML);
}

void sf_exported_user_c11_lib_affectiveChar_scenario_sendBML(SimStruct *c11_S,
  real_T c11_arg[256])
{
  int32_T c11_i151;
  real_T c11_b_arg[256];
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)
    ->chartInstance;
  for (c11_i151 = 0; c11_i151 < 256; c11_i151++) {
    c11_b_arg[c11_i151] = c11_arg[c11_i151];
  }

  c11_sendBMLc11_lib_affectiveChar_scenario(chartInstance, c11_b_arg);
}

static const mxArray *c11_u_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int8_T c11_e_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int8_T c11_y;
  int8_T c11_i152;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i152, 1, 2, 0U, 0, 0U, 0);
  c11_y = c11_i152;
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
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_secs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_secs),
    &c11_thisId);
  sf_mex_destroy(&c11_secs);
  *(int8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_v_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_f_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i153;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i153, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i153;
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
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_w_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_g_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_b_tp_stateRandomPose, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_tp_stateRandomPose), &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateRandomPose);
  return c11_y;
}

static uint8_T c11_h_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u3;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u3, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u3;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_stateRandomPose;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c11_b_tp_stateRandomPose = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_tp_stateRandomPose), &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateRandomPose);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint32_T c11_i_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_b_method, const char_T *c11_identifier)
{
  uint32_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_method),
    &c11_thisId);
  sf_mex_destroy(&c11_b_method);
  return c11_y;
}

static uint32_T c11_j_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint32_T c11_y;
  uint32_T c11_u4;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_method_not_empty = false;
  } else {
    chartInstance->c11_method_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u4, 1, 7, 0U, 0, 0U, 0);
    c11_y = c11_u4;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static uint32_T c11_k_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_d_state, const char_T *c11_identifier)
{
  uint32_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_d_state),
    &c11_thisId);
  sf_mex_destroy(&c11_d_state);
  return c11_y;
}

static uint32_T c11_l_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint32_T c11_y;
  uint32_T c11_u5;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_state_not_empty = false;
  } else {
    chartInstance->c11_state_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u5, 1, 7, 0U, 0, 0U, 0);
    c11_y = c11_u5;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_m_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_d_state, const char_T *c11_identifier, uint32_T c11_y[625])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_d_state), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_d_state);
}

static void c11_n_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId, uint32_T c11_y[625])
{
  uint32_T c11_uv3[625];
  int32_T c11_i154;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_c_state_not_empty = false;
  } else {
    chartInstance->c11_c_state_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv3, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c11_i154 = 0; c11_i154 < 625; c11_i154++) {
      c11_y[c11_i154] = c11_uv3[c11_i154];
    }
  }

  sf_mex_destroy(&c11_u);
}

static void c11_o_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_d_state, const char_T *c11_identifier, uint32_T c11_y[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_d_state), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_d_state);
}

static void c11_p_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId, uint32_T c11_y[2])
{
  uint32_T c11_uv4[2];
  int32_T c11_i155;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_b_state_not_empty = false;
  } else {
    chartInstance->c11_b_state_not_empty = true;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv4, 1, 7, 0U, 1, 0U, 1,
                  2);
    for (c11_i155 = 0; c11_i155 < 2; c11_i155++) {
      c11_y[c11_i155] = c11_uv4[c11_i155];
    }
  }

  sf_mex_destroy(&c11_u);
}

static const mxArray *c11_q_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_b_setSimStateSideEffectsInfo, const char_T *c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_r_emlrt_marshallIn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c11_u, const emlrtMsgIdentifier *c11_parentId)
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
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c11_errorIfDataNotWrittenToFcn
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_vectorIndex, uint32_T c11_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c11_dataNumber, c11_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c11_vectorIndex, 0, 0, 1,
    0)]);
}

static void c11_b_twister_state_vector
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_mt[625], real_T c11_seed)
{
  real_T c11_d5;
  uint32_T c11_u6;
  uint32_T c11_r;
  int32_T c11_mti;
  real_T c11_b_mti;
  real_T c11_d6;
  uint32_T c11_u7;
  (void)chartInstance;
  c11_d5 = c11_seed;
  if (c11_d5 < 4.294967296E+9) {
    if (c11_d5 >= 0.0) {
      c11_u6 = (uint32_T)c11_d5;
    } else {
      c11_u6 = 0U;
    }
  } else if (c11_d5 >= 4.294967296E+9) {
    c11_u6 = MAX_uint32_T;
  } else {
    c11_u6 = 0U;
  }

  c11_r = c11_u6;
  c11_mt[0] = c11_r;
  for (c11_mti = 0; c11_mti < 623; c11_mti++) {
    c11_b_mti = 2.0 + (real_T)c11_mti;
    c11_d6 = muDoubleScalarRound(c11_b_mti - 1.0);
    if (c11_d6 < 4.294967296E+9) {
      if (c11_d6 >= 0.0) {
        c11_u7 = (uint32_T)c11_d6;
      } else {
        c11_u7 = 0U;
      }
    } else if (c11_d6 >= 4.294967296E+9) {
      c11_u7 = MAX_uint32_T;
    } else {
      c11_u7 = 0U;
    }

    c11_r = (c11_r ^ c11_r >> 30U) * 1812433253U + c11_u7;
    c11_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c11_b_mti), 1, 625, 1, 0) - 1] = c11_r;
  }

  c11_mt[624] = 624U;
}

static real_T c11_c_eml_rand_mt19937ar
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c11_d_state[625])
{
  int32_T c11_i156;
  uint32_T c11_u[2];
  int32_T c11_j;
  real_T c11_b_j;
  uint32_T c11_mti;
  int32_T c11_kk;
  real_T c11_b_kk;
  uint32_T c11_y;
  uint32_T c11_b_y;
  uint32_T c11_c_y;
  int32_T c11_c_kk;
  uint32_T c11_d_y;
  uint32_T c11_e_y;
  uint32_T c11_f_y;
  uint32_T c11_g_y;
  real_T c11_b_r;
  boolean_T c11_b1;
  boolean_T c11_isvalid;
  int32_T c11_k;
  int32_T c11_a;
  int32_T c11_b_a;
  real_T c11_d7;
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
    for (c11_i156 = 0; c11_i156 < 2; c11_i156++) {
      c11_u[c11_i156] = 0U;
    }

    for (c11_j = 0; c11_j < 2; c11_j++) {
      c11_b_j = 1.0 + (real_T)c11_j;
      c11_mti = c11_d_state[624] + 1U;
      if ((real_T)c11_mti >= 625.0) {
        for (c11_kk = 0; c11_kk < 227; c11_kk++) {
          c11_b_kk = 1.0 + (real_T)c11_kk;
          c11_y = (c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", c11_b_kk), 1, 625, 1, 0) - 1] &
                   2147483648U) | (c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c11_b_kk + 1.0), 1, 625, 1, 0) - 1]
            & 2147483647U);
          c11_b_y = c11_y;
          c11_c_y = c11_b_y;
          if ((real_T)(c11_c_y & 1U) == 0.0) {
            c11_c_y >>= 1U;
          } else {
            c11_c_y = c11_c_y >> 1U ^ 2567483615U;
          }

          c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c11_b_kk), 1, 625, 1, 0) - 1] =
            c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c11_b_kk + 397.0), 1, 625, 1, 0) - 1] ^
            c11_c_y;
        }

        for (c11_c_kk = 0; c11_c_kk < 396; c11_c_kk++) {
          c11_b_kk = 228.0 + (real_T)c11_c_kk;
          c11_y = (c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", c11_b_kk), 1, 625, 1, 0) - 1] &
                   2147483648U) | (c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c11_b_kk + 1.0), 1, 625, 1, 0) - 1]
            & 2147483647U);
          c11_d_y = c11_y;
          c11_e_y = c11_d_y;
          if ((real_T)(c11_e_y & 1U) == 0.0) {
            c11_e_y >>= 1U;
          } else {
            c11_e_y = c11_e_y >> 1U ^ 2567483615U;
          }

          c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c11_b_kk), 1, 625, 1, 0) - 1] =
            c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c11_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1]
            ^ c11_e_y;
        }

        c11_y = (c11_d_state[623] & 2147483648U) | (c11_d_state[0] & 2147483647U);
        c11_f_y = c11_y;
        c11_g_y = c11_f_y;
        if ((real_T)(c11_g_y & 1U) == 0.0) {
          c11_g_y >>= 1U;
        } else {
          c11_g_y = c11_g_y >> 1U ^ 2567483615U;
        }

        c11_d_state[623] = c11_d_state[396] ^ c11_g_y;
        c11_mti = 1U;
      }

      c11_y = c11_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c11_mti), 1, 625, 1, 0)
        - 1];
      c11_d_state[624] = c11_mti;
      c11_y ^= c11_y >> 11U;
      c11_y ^= c11_y << 7U & 2636928640U;
      c11_y ^= c11_y << 15U & 4022730752U;
      c11_y ^= c11_y >> 18U;
      c11_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c11_b_j), 1, 2, 1, 0) - 1] = c11_y;
    }

    c11_u[0] >>= 5U;
    c11_u[1] >>= 6U;
    c11_b_r = 1.1102230246251565E-16 * ((real_T)c11_u[0] * 6.7108864E+7 +
      (real_T)c11_u[1]);
    if (c11_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c11_d_state[624] >= 1.0) {
        if ((real_T)c11_d_state[624] < 625.0) {
          c11_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c11_b1 = false;
      }

      c11_isvalid = c11_b1;
      if (c11_isvalid) {
        c11_isvalid = false;
        c11_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c11_k < 625)) {
          if ((real_T)c11_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c11_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c11_a = c11_k;
            c11_b_a = c11_a + 1;
            c11_k = c11_b_a;
          } else {
            c11_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c11_isvalid) {
        c11_eml_error(chartInstance);
        c11_d7 = 5489.0;
        c11_b_twister_state_vector(chartInstance, c11_d_state, c11_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c11_b_r;
}

static real_T c11_get_BOREDOMT(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#879) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_BOREDOMT_address;
}

static void c11_set_BOREDOMT(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#879) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_BOREDOMT_address = c11_c;
}

static real_T *c11_access_BOREDOMT
  (SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#879) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_BOREDOMT_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_b(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#882) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_b_address;
}

static void c11_set_b(SFc11_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#882) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_b_address = c11_c;
}

static real_T *c11_access_b(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#882) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_b_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_bored(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#878) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_bored_address;
}

static void c11_set_bored(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#878) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_bored_address = c11_c;
}

static real_T *c11_access_bored(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#878) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_bored_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_pose(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#881) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_pose_address;
}

static void c11_set_pose(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#881) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_pose_address = c11_c;
}

static real_T *c11_access_pose(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#881) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_pose_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static real_T c11_get_randomP(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#880) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_randomP_address;
}

static void c11_set_randomP(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#880) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_randomP_address = c11_c;
}

static real_T *c11_access_randomP(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c11_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#880) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_randomP_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c11_BOREDOMT_address, &chartInstance->c11_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "b", (void **)
    &chartInstance->c11_b_address, &chartInstance->c11_b_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c11_bored_address, &chartInstance->c11_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c11_pose_address, &chartInstance->c11_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c11_randomP_address, &chartInstance->c11_randomP_index);
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

void sf_c11_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(472054079U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(586515587U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1426741595U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2597956566U);
}

mxArray *sf_c11_lib_affectiveChar_scenario_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Kt2U2lrnseO0IhD9eqsZ7D");
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

mxArray *sf_c11_lib_affectiveChar_scenario_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_lib_affectiveChar_scenario_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_lib_affectiveChar_scenario(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c11_lib_affectiveChar_scenario\",},{M[9],M[0],T\"is_c11_lib_affectiveChar_scenario\",},{M[11],M[16],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[10],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_lib_affectiveChar_scenario_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_scenarioMachineNumber_,
           11,
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
        init_script_number_translation(_lib_affectiveChar_scenarioMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _lib_affectiveChar_scenarioMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lib_affectiveChar_scenarioMachineNumber_,
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredPoseSc11_lib_affectiveChar_scenario",0,-1,
                             2895);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",2895,-1,3066);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",3066,-1,3228);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3228,-1,3395);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",3395,-1,3564);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",3564,-1,3733);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",3733,-1,3914);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",3914,-1,4093);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",4093,-1,4262);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",4262,-1,4429);
        _SFD_CV_INIT_EML_FCN(0,10,"aFcnTruthTableAction_10",4429,-1,4598);
        _SFD_CV_INIT_EML_FCN(0,11,"aFcnTruthTableAction_11",4598,-1,4764);
        _SFD_CV_INIT_EML_IF(0,1,0,1667,1697,1728,2893);
        _SFD_CV_INIT_EML_IF(0,1,1,1728,1762,1793,2893);
        _SFD_CV_INIT_EML_IF(0,1,2,1793,1827,1858,2893);
        _SFD_CV_INIT_EML_IF(0,1,3,1858,1892,1923,2893);
        _SFD_CV_INIT_EML_IF(0,1,4,1923,1957,1988,2893);
        _SFD_CV_INIT_EML_IF(0,1,5,1988,2022,2054,2893);
        _SFD_CV_INIT_EML_IF(0,1,6,2054,2088,2119,2893);
        _SFD_CV_INIT_EML_IF(0,1,7,2119,2153,2184,2893);
        _SFD_CV_INIT_EML_IF(0,1,8,2184,2218,2249,2893);
        _SFD_CV_INIT_EML_IF(0,1,9,2249,2284,2316,2893);
        _SFD_CV_INIT_EML_IF(0,1,10,2316,2351,2383,2893);
        _SFD_CV_INIT_EML_IF(0,1,11,2383,2418,2449,2893);
        _SFD_CV_INIT_EML_IF(0,1,12,2449,2484,2515,2893);
        _SFD_CV_INIT_EML_IF(0,1,13,2515,2550,2581,2893);
        _SFD_CV_INIT_EML_IF(0,1,14,2581,2616,2647,2893);
        _SFD_CV_INIT_EML_IF(0,1,15,2647,2682,2713,2893);
        _SFD_CV_INIT_EML_IF(0,1,16,2713,2748,2779,2893);
        _SFD_CV_INIT_EML_IF(0,1,17,2779,2814,2845,2893);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,11,1,11);
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
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
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

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c11_bored_address);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c11_BOREDOMT_address);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c11_randomP_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_pose_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_b_address);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lib_affectiveChar_scenarioMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "KFCBwQWmQ1sQwKUoCAewFB";
}

static void sf_opaque_initialize_c11_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_lib_affectiveChar_scenarioInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
  initialize_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  enable_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  disable_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  sf_gateway_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_lib_affectiveChar_scenario
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_lib_affectiveChar_scenario();/* state var info */
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

extern void sf_internal_set_sim_state_c11_lib_affectiveChar_scenario(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_lib_affectiveChar_scenario();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_lib_affectiveChar_scenario
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_lib_affectiveChar_scenario(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c11_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_lib_affectiveChar_scenarioInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_scenario_optimization_info();
    }

    finalize_c11_lib_affectiveChar_scenario
      ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_lib_affectiveChar_scenario
    ((SFc11_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_lib_affectiveChar_scenario(SimStruct *S)
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
    initialize_params_c11_lib_affectiveChar_scenario
      ((SFc11_lib_affectiveChar_scenarioInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_scenario_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,11,1);
    if (chartIsInlinable) {
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4226504066U));
  ssSetChecksum1(S,(561082740U));
  ssSetChecksum2(S,(231339564U));
  ssSetChecksum3(S,(2014496576U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_lib_affectiveChar_scenario(SimStruct *S)
{
  SFc11_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_lib_affectiveChar_scenarioInstanceStruct *)utMalloc
    (sizeof(SFc11_lib_affectiveChar_scenarioInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_lib_affectiveChar_scenarioInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_lib_affectiveChar_scenario;
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

void c11_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_lib_affectiveChar_scenario(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_lib_affectiveChar_scenario_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
