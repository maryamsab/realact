/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_scenario_sfun.h"
#include "c10_lib_affectiveChar_scenario.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_scenario_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c10_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c10_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c10_IN_stateAvertGaze          ((uint8_T)1U)
#define c10_IN_stateAvertHead          ((uint8_T)2U)
#define c10_IN_stateHeadNeutral        ((uint8_T)3U)
#define c10_IN_stateInitial            ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c10_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

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

static const char * c10_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_j_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c10_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c10_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c10_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c10_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c10_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initialize_params_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void enable_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void disable_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void set_sim_state_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_st);
static void c10_set_sim_state_side_effects_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void finalize_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void sf_gateway_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_enter_atomic_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_enter_internal_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_exit_internal_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_initc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initSimStructsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_enter_atomic_stateInitial
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_stateInitial(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c10_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_b_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_c_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_d_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_e_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_f_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_g_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_h_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_i_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_j_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_k_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_l_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_m_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_n_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_o_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_p_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_q_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_r_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_s_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_t_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_u_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_v_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_w_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_x_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static void c10_y_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256]);
static real_T c10_rand(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static real_T c10_eml_rand(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c10_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_d_state[625]);
static void c10_twister_state_vector
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed, uint32_T c10_b_mt[625]);
static void c10_b_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_d_state[625], uint32_T c10_e_state[625], real_T *c10_r);
static void c10_eml_error(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_b_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static boolean_T c10_c_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_d_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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
static const mxArray *c10_o_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_p_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_q_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_e_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, creal_T c10_y[256]);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_r_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_s_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_t_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_u_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_v_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_w_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_x_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_y_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_db_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_info_helper(const mxArray **c10_info);
static const mxArray *c10_emlrt_marshallOut(const char * c10_u);
static const mxArray *c10_b_emlrt_marshallOut(const uint32_T c10_u);
static void c10_activate_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_deactivate_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_increment_counters_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_reset_counters_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c10_sendBMLc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c10_arg[256]);
static void c10_idlePosec10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c10_bmlID, real_T c10_poseBML[256]);
static void c10_boredGazec10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c10_bmlID, creal_T c10_gazeBML[256]);
static void c10_sendBML(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c10_b_sendBML(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static boolean_T c10_all(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, boolean_T c10_x);
static const mxArray *c10_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int8_T c10_f_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_g_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static uint8_T c10_h_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_tp_stateInitial, const char_T *c10_identifier);
static uint8_T c10_i_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint32_T c10_j_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_method, const char_T *c10_identifier);
static uint32_T c10_k_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static uint32_T c10_l_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier);
static uint32_T c10_m_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_n_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[625]);
static void c10_o_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[625]);
static void c10_p_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[2]);
static void c10_q_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[2]);
static uint32_T c10_r_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_temporalCounter_i1, const char_T *c10_identifier);
static uint32_T c10_s_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static const mxArray *c10_t_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier);
static const mxArray *c10_u_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_updateDataWrittenToVector
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex);
static void c10_errorIfDataNotWrittenToFcn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex, uint32_T c10_dataNumber);
static void c10_b_twister_state_vector
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed);
static real_T c10_c_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_d_state[625]);
static real_T c10_get_BOREDOMT(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_BOREDOMT(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_BOREDOMT
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c10_b);
static real_T c10_get_b(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_b(SFc10_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_b(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_bored(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_bored(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_bored(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_pose(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_pose(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_pose(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_randomD(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_randomD(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_randomD(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_randomG(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_randomG(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_randomG(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static real_T c10_get_randomP(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void c10_set_randomP(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c);
static real_T *c10_access_randomP(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b);
static void init_dsm_address_info(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_update_debugger_state_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c10_prevAniVal;
  c10_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c10_is_active_c10_lib_affectiveChar_scenario == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
      c10_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
      c10_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
      c10_IN_stateAvertGaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  }

  if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
      c10_IN_stateAvertHead) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
  }

  _SFD_SET_ANIMATION(c10_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
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
  uint32_T c10_e_hoistedGlobal;
  uint32_T c10_g_u;
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
    chartInstance->c10_is_active_c10_lib_affectiveChar_scenario;
  c10_e_u = c10_c_hoistedGlobal;
  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", &c10_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 4, c10_f_y);
  c10_d_hoistedGlobal = chartInstance->c10_is_c10_lib_affectiveChar_scenario;
  c10_f_u = c10_d_hoistedGlobal;
  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_create("y", &c10_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 5, c10_g_y);
  c10_e_hoistedGlobal = chartInstance->c10_temporalCounter_i1;
  c10_g_u = c10_e_hoistedGlobal;
  c10_h_y = NULL;
  sf_mex_assign(&c10_h_y, sf_mex_create("y", &c10_g_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 6, c10_h_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_st)
{
  const mxArray *c10_u;
  uint32_T c10_uv0[625];
  int32_T c10_i2;
  uint32_T c10_uv1[2];
  int32_T c10_i3;
  c10_u = sf_mex_dup(c10_st);
  chartInstance->c10_method = c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 0)), "method");
  chartInstance->c10_state = c10_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 1)), "state");
  c10_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
    "state", c10_uv0);
  for (c10_i2 = 0; c10_i2 < 625; c10_i2++) {
    chartInstance->c10_c_state[c10_i2] = c10_uv0[c10_i2];
  }

  c10_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 3)),
    "state", c10_uv1);
  for (c10_i3 = 0; c10_i3 < 2; c10_i3++) {
    chartInstance->c10_b_state[c10_i3] = c10_uv1[c10_i3];
  }

  chartInstance->c10_is_active_c10_lib_affectiveChar_scenario =
    c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 4)),
    "is_active_c10_lib_affectiveChar_scenario");
  chartInstance->c10_is_c10_lib_affectiveChar_scenario = c10_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 5)),
     "is_c10_lib_affectiveChar_scenario");
  chartInstance->c10_temporalCounter_i1 = c10_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c10_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c10_setSimStateSideEffectsInfo,
                c10_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c10_u);
  chartInstance->c10_doSetSimStateSideEffects = 1U;
  c10_update_debugger_state_c10_lib_affectiveChar_scenario(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void c10_set_sim_state_side_effects_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c10_doSetSimStateSideEffects != 0) {
    if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
        c10_IN_stateAvertGaze) {
      chartInstance->c10_tp_stateAvertGaze = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_stateAvertGaze = 0U;
    }

    if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
        c10_IN_stateAvertHead) {
      chartInstance->c10_tp_stateAvertHead = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_stateAvertHead = 0U;
    }

    if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
        c10_IN_stateHeadNeutral) {
      chartInstance->c10_tp_stateHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c10_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c10_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c10_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c10_is_c10_lib_affectiveChar_scenario ==
        c10_IN_stateInitial) {
      chartInstance->c10_tp_stateInitial = 1U;
    } else {
      chartInstance->c10_tp_stateInitial = 0U;
    }

    chartInstance->c10_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c10_setSimStateSideEffectsInfo);
}

static void sf_gateway_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  c10_set_sim_state_side_effects_c10_lib_affectiveChar_scenario(chartInstance);
}

static void c10_enter_atomic_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
  chartInstance->c10_is_active_c10_lib_affectiveChar_scenario = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
}

static void c10_enter_internal_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c10_sfEvent);
  chartInstance->c10_isStable = false;
  chartInstance->c10_is_c10_lib_affectiveChar_scenario = c10_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
  chartInstance->c10_tp_stateInitial = 1U;
  c10_enter_atomic_stateInitial(chartInstance);
}

static void c10_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[3];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 1.0;
  boolean_T c10_out;
  boolean_T c10_temp;
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 1.0;
  boolean_T c10_b_out;
  uint32_T c10_b_debug_family_var_map[2];
  real_T c10_c_nargin = 0.0;
  real_T c10_c_nargout = 0.0;
  real_T c10_dv0[256];
  int32_T c10_i4;
  real_T c10_arg[256];
  int32_T c10_i5;
  int32_T c10_i6;
  int32_T c10_i7;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_c_out;
  real_T (*c10_b_arg)[256];
  c10_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_isStable = true;
  switch (chartInstance->c10_is_c10_lib_affectiveChar_scenario) {
   case c10_IN_stateAvertGaze:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_jb_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_temp = (chartInstance->c10_sfEvent == c10_event_secs);
    if (c10_temp) {
      c10_temp = (chartInstance->c10_temporalCounter_i1 >=
                  _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c10_get_randomD
        (chartInstance, 0), 32U, 2U));
    }

    c10_out = CV_EML_IF(2, 0, 0, c10_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateAvertGaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_lib_affectiveChar_scenario = c10_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateInitial = 1U;
      c10_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateAvertHead:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_ob_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_b_out = CV_EML_IF(8, 0, 0, (chartInstance->c10_sfEvent == c10_event_secs)
                          && (chartInstance->c10_temporalCounter_i1 >= 3U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateAvertHead = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_lib_affectiveChar_scenario =
        c10_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_fb_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_idlePosec10_lib_affectiveChar_scenario(chartInstance, 8.0, c10_dv0);
      for (c10_i4 = 0; c10_i4 < 256; c10_i4++) {
        c10_arg[c10_i4] = c10_dv0[c10_i4];
      }

      for (c10_i5 = 0; c10_i5 < 256; c10_i5++) {
        _SFD_DATA_RANGE_CHECK(c10_arg[c10_i5], 7U);
      }

      _SFD_SET_DATA_VALUE_PTR(7U, c10_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c10_arg, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c10_sfEvent);
      for (c10_i6 = 0; c10_i6 < 256; c10_i6++) {
        (*c10_b_arg)[c10_i6] = c10_arg[c10_i6];
      }

      for (c10_i7 = 0; c10_i7 < 256; c10_i7++) {
        _SFD_DATA_RANGE_CHECK((*c10_b_arg)[c10_i7], 7U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateHeadNeutral:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_ib_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    c10_c_out = CV_EML_IF(1, 0, 0, (chartInstance->c10_sfEvent == c10_event_secs)
                          && (chartInstance->c10_temporalCounter_i1 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c10_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_lib_affectiveChar_scenario = c10_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateInitial = 1U;
      c10_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c10_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateInitial:
    CV_CHART_EVAL(0, 0, 4);
    c10_stateInitial(chartInstance);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c10_is_c10_lib_affectiveChar_scenario =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c10_sfEvent);
}

static void c10_exit_internal_c10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  switch (chartInstance->c10_is_c10_lib_affectiveChar_scenario) {
   case c10_IN_stateAvertGaze:
    CV_CHART_EVAL(0, 0, 1);
    chartInstance->c10_tp_stateAvertGaze = 0U;
    chartInstance->c10_is_c10_lib_affectiveChar_scenario =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateAvertHead:
    CV_CHART_EVAL(0, 0, 2);
    chartInstance->c10_tp_stateAvertHead = 0U;
    chartInstance->c10_is_c10_lib_affectiveChar_scenario =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateHeadNeutral:
    CV_CHART_EVAL(0, 0, 3);
    chartInstance->c10_tp_stateHeadNeutral = 0U;
    chartInstance->c10_is_c10_lib_affectiveChar_scenario =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
    break;

   case c10_IN_stateInitial:
    CV_CHART_EVAL(0, 0, 4);
    chartInstance->c10_tp_stateInitial = 0U;
    chartInstance->c10_is_c10_lib_affectiveChar_scenario =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c10_is_c10_lib_affectiveChar_scenario =
      c10_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
    break;
  }
}

static void c10_initc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_method_not_empty = false;
  chartInstance->c10_state_not_empty = false;
  chartInstance->c10_b_state_not_empty = false;
  chartInstance->c10_c_state_not_empty = false;
  chartInstance->c10_doSetSimStateSideEffects = 0U;
  chartInstance->c10_setSimStateSideEffectsInfo = NULL;
  chartInstance->c10_tp_stateAvertGaze = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateAvertHead = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateHeadNeutral = 0U;
  chartInstance->c10_temporalCounter_i1 = 0U;
  chartInstance->c10_tp_stateInitial = 0U;
  chartInstance->c10_is_active_c10_lib_affectiveChar_scenario = 0U;
  chartInstance->c10_is_c10_lib_affectiveChar_scenario = c10_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c10_enter_atomic_stateInitial
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c10_debug_family_var_map[2];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 0.0;
  real_T c10_r;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  real_T c10_b_r;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_b_hoistedGlobal;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_b_nargin = 0.0;
  real_T c10_b_nargout = 0.0;
  real_T c10_c_hoistedGlobal;
  real_T c10_lowhigh[2];
  real_T c10_low;
  real_T c10_high;
  int32_T c10_i8;
  static char_T c10_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c10_c_u[26];
  const mxArray *c10_c_y = NULL;
  real_T c10_s;
  real_T c10_c_r;
  real_T c10_e_x;
  real_T c10_f_x;
  real_T c10_d_hoistedGlobal;
  real_T c10_d_u;
  const mxArray *c10_d_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_db_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  c10_r = c10_rand(chartInstance);
  c10_x = c10_r * 10.0;
  c10_b_x = c10_x;
  c10_b_x = muDoubleScalarFloor(c10_b_x);
  c10_r = 1.0 + c10_b_x;
  c10_set_randomG(chartInstance, 0, c10_r);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  sf_mex_printf("%s =\\n", "randomG");
  c10_hoistedGlobal = c10_get_randomG(chartInstance, 0);
  c10_u = c10_hoistedGlobal;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_y);
  c10_b_r = c10_rand(chartInstance);
  c10_c_x = c10_b_r * 4.0;
  c10_d_x = c10_c_x;
  c10_d_x = muDoubleScalarFloor(c10_d_x);
  c10_b_r = 1.0 + c10_d_x;
  c10_set_randomD(chartInstance, 0, c10_b_r);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  sf_mex_printf("%s =\\n", "randomD");
  c10_b_hoistedGlobal = c10_get_randomD(chartInstance, 0);
  c10_b_u = c10_b_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_b_y);
  c10_set_b(chartInstance, 0, c10_get_BOREDOMT(chartInstance, 0) - c10_get_bored
            (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_eb_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  c10_c_hoistedGlobal = c10_get_b(chartInstance, 0);
  c10_lowhigh[0] = 1.0;
  c10_lowhigh[1] = c10_c_hoistedGlobal;
  c10_low = c10_lowhigh[0];
  c10_high = c10_lowhigh[1];
  if (c10_low <= c10_high) {
  } else {
    for (c10_i8 = 0; c10_i8 < 26; c10_i8++) {
      c10_c_u[c10_i8] = c10_cv0[c10_i8];
    }

    c10_c_y = NULL;
    sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_c_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c10_c_y));
  }

  c10_s = (c10_high - c10_low) + 1.0;
  c10_c_r = c10_rand(chartInstance);
  c10_e_x = c10_c_r * c10_s;
  c10_f_x = c10_e_x;
  c10_f_x = muDoubleScalarFloor(c10_f_x);
  c10_c_r = c10_low + c10_f_x;
  c10_set_randomP(chartInstance, 0, c10_c_r);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  sf_mex_printf("%s =\\n", "randomP");
  c10_d_hoistedGlobal = c10_get_randomP(chartInstance, 0);
  c10_d_u = c10_d_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_d_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_stateInitial(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
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
  creal_T c10_dcv0[256];
  int32_T c10_i9;
  real_T c10_arg[256];
  int32_T c10_i10;
  int32_T c10_i11;
  int32_T c10_i12;
  real_T c10_d_nargin = 0.0;
  real_T c10_d_nargout = 1.0;
  boolean_T c10_c_out;
  real_T c10_e_nargin = 0.0;
  real_T c10_e_nargout = 0.0;
  real_T c10_b_r;
  real_T c10_c_x;
  real_T c10_d_x;
  int32_T c10_i13;
  real_T c10_b_arg[256];
  int32_T c10_i14;
  int32_T c10_i15;
  int32_T c10_i16;
  real_T c10_f_nargin = 0.0;
  real_T c10_f_nargout = 1.0;
  boolean_T c10_d_out;
  real_T (*c10_c_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c10_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_kb_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_out, 2U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  c10_out = CV_EML_IF(4, 0, 0, c10_get_pose(chartInstance, 0) != 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c10_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
    chartInstance->c10_isStable = false;
    chartInstance->c10_is_c10_lib_affectiveChar_scenario = c10_IN_stateInitial;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
    chartInstance->c10_tp_stateInitial = 1U;
    c10_enter_atomic_stateInitial(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 chartInstance->c10_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_nb_debug_family_names,
      c10_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 0U, c10_b_sf_marshallOut,
      c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 1U,
      c10_b_sf_marshallOut, c10_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_out, 2U, c10_c_sf_marshallOut,
      c10_c_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(7, 0, 0, c10_get_randomG(chartInstance, 0) > 3.0)) {
      if (CV_EML_COND(7, 0, 1, c10_get_pose(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(7, 0, 0, true);
        CV_EML_IF(7, 0, 0, true);
        c10_b_out = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c10_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c10_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c10_sfEvent);
      chartInstance->c10_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
      chartInstance->c10_isStable = false;
      chartInstance->c10_is_c10_lib_affectiveChar_scenario =
        c10_IN_stateAvertGaze;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c10_sfEvent);
      chartInstance->c10_temporalCounter_i1 = 0U;
      chartInstance->c10_tp_stateAvertGaze = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_gb_debug_family_names,
        c10_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      c10_r = c10_rand(chartInstance);
      c10_x = c10_r * 8.0;
      c10_b_x = c10_x;
      c10_b_x = muDoubleScalarFloor(c10_b_x);
      c10_r = 1.0 + c10_b_x;
      c10_boredGazec10_lib_affectiveChar_scenario(chartInstance, c10_r, c10_dcv0);
      for (c10_i9 = 0; c10_i9 < 256; c10_i9++) {
        c10_arg[c10_i9] = c10_dcv0[c10_i9].re;
      }

      for (c10_i10 = 0; c10_i10 < 256; c10_i10++) {
        _SFD_DATA_RANGE_CHECK(c10_arg[c10_i10], 7U);
      }

      _SFD_SET_DATA_VALUE_PTR(7U, c10_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c10_arg, c10_sf_marshallOut,
        c10_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c10_sfEvent);
      for (c10_i11 = 0; c10_i11 < 256; c10_i11++) {
        (*c10_c_arg)[c10_i11] = c10_arg[c10_i11];
      }

      for (c10_i12 = 0; c10_i12 < 256; c10_i12++) {
        _SFD_DATA_RANGE_CHECK((*c10_c_arg)[c10_i12], 7U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c10_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_mb_debug_family_names,
        c10_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargin, 0U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_nargout, 1U,
        c10_b_sf_marshallOut, c10_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c_out, 2U, c10_c_sf_marshallOut,
        c10_c_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(6, 0, 0, c10_get_randomP(chartInstance, 0) == 1.0)) {
        if (CV_EML_COND(6, 0, 1, c10_get_pose(chartInstance, 0) == 0.0)) {
          CV_EML_MCDC(6, 0, 0, true);
          CV_EML_IF(6, 0, 0, true);
          c10_c_out = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(6, 0, 0, false);
        CV_EML_IF(6, 0, 0, false);
        c10_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c10_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
        chartInstance->c10_tp_stateInitial = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
        chartInstance->c10_isStable = false;
        chartInstance->c10_is_c10_lib_affectiveChar_scenario =
          c10_IN_stateAvertHead;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c10_sfEvent);
        chartInstance->c10_temporalCounter_i1 = 0U;
        chartInstance->c10_tp_stateAvertHead = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_hb_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_e_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        c10_b_r = c10_rand(chartInstance);
        c10_c_x = c10_b_r * 8.0;
        c10_d_x = c10_c_x;
        c10_d_x = muDoubleScalarFloor(c10_d_x);
        c10_b_r = 9.0 + c10_d_x;
        c10_boredGazec10_lib_affectiveChar_scenario(chartInstance, c10_b_r,
          c10_dcv0);
        for (c10_i13 = 0; c10_i13 < 256; c10_i13++) {
          c10_b_arg[c10_i13] = c10_dcv0[c10_i13].re;
        }

        for (c10_i14 = 0; c10_i14 < 256; c10_i14++) {
          _SFD_DATA_RANGE_CHECK(c10_b_arg[c10_i14], 7U);
        }

        _SFD_SET_DATA_VALUE_PTR(7U, c10_b_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c10_b_arg, c10_sf_marshallOut,
          c10_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c10_sfEvent);
        for (c10_i15 = 0; c10_i15 < 256; c10_i15++) {
          (*c10_c_arg)[c10_i15] = c10_b_arg[c10_i15];
        }

        for (c10_i16 = 0; c10_i16 < 256; c10_i16++) {
          _SFD_DATA_RANGE_CHECK((*c10_c_arg)[c10_i16], 7U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(7U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c10_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c10_lb_debug_family_names,
          c10_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargin, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_f_nargout, 1U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_d_out, 2U,
          c10_c_sf_marshallOut, c10_c_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(5, 0, 0, 0.0 < c10_get_randomG(chartInstance, 0))) {
          if (CV_EML_COND(5, 0, 1, c10_get_randomG(chartInstance, 0) < 4.0)) {
            CV_EML_MCDC(5, 0, 0, true);
            CV_EML_IF(5, 0, 0, true);
            c10_d_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(5, 0, 0, false);
          CV_EML_IF(5, 0, 0, false);
          c10_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c10_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c10_sfEvent);
          chartInstance->c10_tp_stateInitial = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
          chartInstance->c10_isStable = false;
          chartInstance->c10_is_c10_lib_affectiveChar_scenario =
            c10_IN_stateInitial;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c10_sfEvent);
          chartInstance->c10_tp_stateInitial = 1U;
          c10_enter_atomic_stateInitial(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       chartInstance->c10_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c10_sfEvent);
}

static void c10_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[147];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[147];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i17;
  static char_T c10_cv1[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<',
    'g', 'a', 'z', 'e', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'C', 'H', 'E', 'S', 'T', ' ', 'B', 'A',
    'C', 'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c10_i18;
  static real_T c10_dv1[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c10_i19;
  int32_T c10_i20;
  int32_T c10_i21;
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
  for (c10_i17 = 0; c10_i17 < 147; c10_i17++) {
    c10_mystr[c10_i17] = c10_cv1[c10_i17];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i18 = 0; c10_i18 < 147; c10_i18++) {
    c10_arr[c10_i18] = c10_dv1[c10_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i19 = 0; c10_i19 < 256; c10_i19++) {
    c10_tt[c10_i19] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i20 = 0; c10_i20 < 147; c10_i20++) {
    c10_tt[c10_i20] = c10_arr[c10_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i21 = 0; c10_i21 < 256; c10_i21++) {
    c10_myarr256[c10_i21] = c10_tt[c10_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_b_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[164];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[164];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i22;
  static char_T c10_cv2[164] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<',
    'g', 'a', 'z', 'e', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=',
    '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n',
    't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'C', 'H', 'E', 'S', 'T', ' ',
    'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c10_i23;
  static real_T c10_dv2[164] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c10_i24;
  int32_T c10_i25;
  int32_T c10_i26;
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
  for (c10_i22 = 0; c10_i22 < 164; c10_i22++) {
    c10_mystr[c10_i22] = c10_cv2[c10_i22];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i23 = 0; c10_i23 < 164; c10_i23++) {
    c10_arr[c10_i23] = c10_dv2[c10_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i24 = 0; c10_i24 < 256; c10_i24++) {
    c10_tt[c10_i24] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i25 = 0; c10_i25 < 164; c10_i25++) {
    c10_tt[c10_i25] = c10_arr[c10_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i26 = 0; c10_i26 < 256; c10_i26++) {
    c10_myarr256[c10_i26] = c10_tt[c10_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_c_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[223];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[223];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i27;
  static char_T c10_cv3[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1',
    '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '8', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"',
    '6', '\"', ' ', 'e', 'n', 'd', '=', '\"', '8', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c10_i28;
  static real_T c10_dv3[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 56.0, 34.0, 32.0, 114.0, 101.0,
    108.0, 97.0, 120.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0,
    61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0,
    32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 101.0, 110.0, 100.0,
    61.0, 34.0, 56.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0,
    54.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0, 34.0, 32.0,
    116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c10_i29;
  int32_T c10_i30;
  int32_T c10_i31;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_e_debug_family_names,
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
  for (c10_i27 = 0; c10_i27 < 223; c10_i27++) {
    c10_mystr[c10_i27] = c10_cv3[c10_i27];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i28 = 0; c10_i28 < 223; c10_i28++) {
    c10_arr[c10_i28] = c10_dv3[c10_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i29 = 0; c10_i29 < 256; c10_i29++) {
    c10_tt[c10_i29] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i30 = 0; c10_i30 < 223; c10_i30++) {
    c10_tt[c10_i30] = c10_arr[c10_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i31 = 0; c10_i31 < 256; c10_i31++) {
    c10_myarr256[c10_i31] = c10_tt[c10_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_d_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[223];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[223];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i32;
  static char_T c10_cv4[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1',
    '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '9', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '7', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"',
    '6', '\"', ' ', 'e', 'n', 'd', '=', '\"', '9', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '7', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c10_i33;
  static real_T c10_dv4[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 57.0, 34.0, 32.0, 114.0, 101.0,
    108.0, 97.0, 120.0, 61.0, 34.0, 55.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0,
    61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0,
    32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 101.0, 110.0, 100.0,
    61.0, 34.0, 57.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0,
    55.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0, 34.0, 32.0,
    116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c10_i34;
  int32_T c10_i35;
  int32_T c10_i36;
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
  for (c10_i32 = 0; c10_i32 < 223; c10_i32++) {
    c10_mystr[c10_i32] = c10_cv4[c10_i32];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i33 = 0; c10_i33 < 223; c10_i33++) {
    c10_arr[c10_i33] = c10_dv4[c10_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i34 = 0; c10_i34 < 256; c10_i34++) {
    c10_tt[c10_i34] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i35 = 0; c10_i35 < 223; c10_i35++) {
    c10_tt[c10_i35] = c10_arr[c10_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i36 = 0; c10_i36 < 256; c10_i36++) {
    c10_myarr256[c10_i36] = c10_tt[c10_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_e_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[225];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[225];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i37;
  static char_T c10_cv5[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1',
    '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l',
    'a', 'x', '=', '\"', '8', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's',
    't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=',
    '\"', '6', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', 'r',
    'e', 'l', 'a', 'x', '=', '\"', '8', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"',
    'B', 'O', 'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"',
    ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i38;
  static real_T c10_dv5[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 114.0,
    101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 56.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0,
    53.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 56.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0,
    79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0,
    48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c10_i39;
  int32_T c10_i40;
  int32_T c10_i41;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_g_debug_family_names,
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
  for (c10_i37 = 0; c10_i37 < 225; c10_i37++) {
    c10_mystr[c10_i37] = c10_cv5[c10_i37];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i38 = 0; c10_i38 < 225; c10_i38++) {
    c10_arr[c10_i38] = c10_dv5[c10_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i39 = 0; c10_i39 < 256; c10_i39++) {
    c10_tt[c10_i39] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i40 = 0; c10_i40 < 225; c10_i40++) {
    c10_tt[c10_i40] = c10_arr[c10_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i41 = 0; c10_i41 < 256; c10_i41++) {
    c10_myarr256[c10_i41] = c10_tt[c10_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_f_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[225];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[225];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i42;
  static char_T c10_cv6[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1',
    '2', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '1', '\"', ' ', 'r', 'e', 'l',
    'a', 'x', '=', '\"', '9', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's',
    't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=',
    '\"', '6', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '1', '\"', ' ', 'r',
    'e', 'l', 'a', 'x', '=', '\"', '9', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"',
    'B', 'O', 'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"',
    ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i43;
  static real_T c10_dv6[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 49.0, 34.0, 32.0, 114.0,
    101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 57.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0,
    53.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 49.0, 49.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 57.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0,
    79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0,
    48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c10_i44;
  int32_T c10_i45;
  int32_T c10_i46;
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
  for (c10_i42 = 0; c10_i42 < 225; c10_i42++) {
    c10_mystr[c10_i42] = c10_cv6[c10_i42];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i43 = 0; c10_i43 < 225; c10_i43++) {
    c10_arr[c10_i43] = c10_dv6[c10_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i44 = 0; c10_i44 < 256; c10_i44++) {
    c10_tt[c10_i44] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i45 = 0; c10_i45 < 225; c10_i45++) {
    c10_tt[c10_i45] = c10_arr[c10_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i46 = 0; c10_i46 < 256; c10_i46++) {
    c10_myarr256[c10_i46] = c10_tt[c10_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_g_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[87];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[87];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i47;
  static char_T c10_cv7[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c10_i48;
  static real_T c10_dv7[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i49;
  int32_T c10_i50;
  int32_T c10_i51;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_i_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i47 = 0; c10_i47 < 87; c10_i47++) {
    c10_mystr[c10_i47] = c10_cv7[c10_i47];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i48 = 0; c10_i48 < 87; c10_i48++) {
    c10_arr[c10_i48] = c10_dv7[c10_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i49 = 0; c10_i49 < 256; c10_i49++) {
    c10_tt[c10_i49] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i50 = 0; c10_i50 < 87; c10_i50++) {
    c10_tt[c10_i50] = c10_arr[c10_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i51 = 0; c10_i51 < 256; c10_i51++) {
    c10_myarr256[c10_i51] = c10_tt[c10_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_h_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[118];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[118];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i52;
  static char_T c10_cv8[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c10_i53;
  static real_T c10_dv8[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i54;
  int32_T c10_i55;
  int32_T c10_i56;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_k_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i52 = 0; c10_i52 < 118; c10_i52++) {
    c10_mystr[c10_i52] = c10_cv8[c10_i52];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i53 = 0; c10_i53 < 118; c10_i53++) {
    c10_arr[c10_i53] = c10_dv8[c10_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i54 = 0; c10_i54 < 256; c10_i54++) {
    c10_tt[c10_i54] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i55 = 0; c10_i55 < 118; c10_i55++) {
    c10_tt[c10_i55] = c10_arr[c10_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i56 = 0; c10_i56 < 256; c10_i56++) {
    c10_myarr256[c10_i56] = c10_tt[c10_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_i_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[119];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[119];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i57;
  static char_T c10_cv9[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c10_i58;
  static real_T c10_dv9[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i59;
  int32_T c10_i60;
  int32_T c10_i61;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_l_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i57 = 0; c10_i57 < 119; c10_i57++) {
    c10_mystr[c10_i57] = c10_cv9[c10_i57];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i58 = 0; c10_i58 < 119; c10_i58++) {
    c10_arr[c10_i58] = c10_dv9[c10_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i59 = 0; c10_i59 < 256; c10_i59++) {
    c10_tt[c10_i59] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i60 = 0; c10_i60 < 119; c10_i60++) {
    c10_tt[c10_i60] = c10_arr[c10_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i61 = 0; c10_i61 < 256; c10_i61++) {
    c10_myarr256[c10_i61] = c10_tt[c10_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_j_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[116];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[116];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i62;
  static char_T c10_cv10[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c10_i63;
  static real_T c10_dv10[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0,
    97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i64;
  int32_T c10_i65;
  int32_T c10_i66;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_m_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i62 = 0; c10_i62 < 116; c10_i62++) {
    c10_mystr[c10_i62] = c10_cv10[c10_i62];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i63 = 0; c10_i63 < 116; c10_i63++) {
    c10_arr[c10_i63] = c10_dv10[c10_i63];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i64 = 0; c10_i64 < 256; c10_i64++) {
    c10_tt[c10_i64] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i65 = 0; c10_i65 < 116; c10_i65++) {
    c10_tt[c10_i65] = c10_arr[c10_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i66 = 0; c10_i66 < 256; c10_i66++) {
    c10_myarr256[c10_i66] = c10_tt[c10_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_k_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[118];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[118];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i67;
  static char_T c10_cv11[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c10_i68;
  static real_T c10_dv11[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i69;
  int32_T c10_i70;
  int32_T c10_i71;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_n_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i67 = 0; c10_i67 < 118; c10_i67++) {
    c10_mystr[c10_i67] = c10_cv11[c10_i67];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i68 = 0; c10_i68 < 118; c10_i68++) {
    c10_arr[c10_i68] = c10_dv11[c10_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i69 = 0; c10_i69 < 256; c10_i69++) {
    c10_tt[c10_i69] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i70 = 0; c10_i70 < 118; c10_i70++) {
    c10_tt[c10_i70] = c10_arr[c10_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i71 = 0; c10_i71 < 256; c10_i71++) {
    c10_myarr256[c10_i71] = c10_tt[c10_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_l_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[120];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[120];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i72;
  static char_T c10_cv12[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i73;
  static real_T c10_dv12[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i74;
  int32_T c10_i75;
  int32_T c10_i76;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_o_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i72 = 0; c10_i72 < 120; c10_i72++) {
    c10_mystr[c10_i72] = c10_cv12[c10_i72];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i73 = 0; c10_i73 < 120; c10_i73++) {
    c10_arr[c10_i73] = c10_dv12[c10_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i74 = 0; c10_i74 < 256; c10_i74++) {
    c10_tt[c10_i74] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i75 = 0; c10_i75 < 120; c10_i75++) {
    c10_tt[c10_i75] = c10_arr[c10_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i76 = 0; c10_i76 < 256; c10_i76++) {
    c10_myarr256[c10_i76] = c10_tt[c10_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_m_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[121];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[121];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i77;
  static char_T c10_cv13[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i78;
  static real_T c10_dv13[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0, 72.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i79;
  int32_T c10_i80;
  int32_T c10_i81;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_p_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i77 = 0; c10_i77 < 121; c10_i77++) {
    c10_mystr[c10_i77] = c10_cv13[c10_i77];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i78 = 0; c10_i78 < 121; c10_i78++) {
    c10_arr[c10_i78] = c10_dv13[c10_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i79 = 0; c10_i79 < 256; c10_i79++) {
    c10_tt[c10_i79] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i80 = 0; c10_i80 < 121; c10_i80++) {
    c10_tt[c10_i80] = c10_arr[c10_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i81 = 0; c10_i81 < 256; c10_i81++) {
    c10_myarr256[c10_i81] = c10_tt[c10_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_n_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[122];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[122];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i82;
  static char_T c10_cv14[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i83;
  static real_T c10_dv14[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0,
    70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i84;
  int32_T c10_i85;
  int32_T c10_i86;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_q_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i82 = 0; c10_i82 < 122; c10_i82++) {
    c10_mystr[c10_i82] = c10_cv14[c10_i82];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i83 = 0; c10_i83 < 122; c10_i83++) {
    c10_arr[c10_i83] = c10_dv14[c10_i83];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i84 = 0; c10_i84 < 256; c10_i84++) {
    c10_tt[c10_i84] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i85 = 0; c10_i85 < 122; c10_i85++) {
    c10_tt[c10_i85] = c10_arr[c10_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i86 = 0; c10_i86 < 256; c10_i86++) {
    c10_myarr256[c10_i86] = c10_tt[c10_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_o_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[123];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[123];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i87;
  static char_T c10_cv15[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i88;
  static real_T c10_dv15[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i89;
  int32_T c10_i90;
  int32_T c10_i91;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_r_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i87 = 0; c10_i87 < 123; c10_i87++) {
    c10_mystr[c10_i87] = c10_cv15[c10_i87];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i88 = 0; c10_i88 < 123; c10_i88++) {
    c10_arr[c10_i88] = c10_dv15[c10_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i89 = 0; c10_i89 < 256; c10_i89++) {
    c10_tt[c10_i89] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i90 = 0; c10_i90 < 123; c10_i90++) {
    c10_tt[c10_i90] = c10_arr[c10_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i91 = 0; c10_i91 < 256; c10_i91++) {
    c10_myarr256[c10_i91] = c10_tt[c10_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_p_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[133];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[133];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i92;
  static char_T c10_cv16[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c10_i93;
  static real_T c10_dv16[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 49.0,
    53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i94;
  int32_T c10_i95;
  int32_T c10_i96;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_s_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i92 = 0; c10_i92 < 133; c10_i92++) {
    c10_mystr[c10_i92] = c10_cv16[c10_i92];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i93 = 0; c10_i93 < 133; c10_i93++) {
    c10_arr[c10_i93] = c10_dv16[c10_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i94 = 0; c10_i94 < 256; c10_i94++) {
    c10_tt[c10_i94] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i95 = 0; c10_i95 < 133; c10_i95++) {
    c10_tt[c10_i95] = c10_arr[c10_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i96 = 0; c10_i96 < 256; c10_i96++) {
    c10_myarr256[c10_i96] = c10_tt[c10_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_q_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[137];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[137];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i97;
  static char_T c10_cv17[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i98;
  static real_T c10_dv17[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0,
    69.0, 70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 48.0, 46.0, 49.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i99;
  int32_T c10_i100;
  int32_T c10_i101;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_t_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i97 = 0; c10_i97 < 137; c10_i97++) {
    c10_mystr[c10_i97] = c10_cv17[c10_i97];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i98 = 0; c10_i98 < 137; c10_i98++) {
    c10_arr[c10_i98] = c10_dv17[c10_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i99 = 0; c10_i99 < 256; c10_i99++) {
    c10_tt[c10_i99] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i100 = 0; c10_i100 < 137; c10_i100++) {
    c10_tt[c10_i100] = c10_arr[c10_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i101 = 0; c10_i101 < 256; c10_i101++) {
    c10_myarr256[c10_i101] = c10_tt[c10_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_r_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[138];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[138];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i102;
  static char_T c10_cv18[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i103;
  static real_T c10_dv18[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 49.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c10_i104;
  int32_T c10_i105;
  int32_T c10_i106;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_u_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i102 = 0; c10_i102 < 138; c10_i102++) {
    c10_mystr[c10_i102] = c10_cv18[c10_i102];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i103 = 0; c10_i103 < 138; c10_i103++) {
    c10_arr[c10_i103] = c10_dv18[c10_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i104 = 0; c10_i104 < 256; c10_i104++) {
    c10_tt[c10_i104] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i105 = 0; c10_i105 < 138; c10_i105++) {
    c10_tt[c10_i105] = c10_arr[c10_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i106 = 0; c10_i106 < 256; c10_i106++) {
    c10_myarr256[c10_i106] = c10_tt[c10_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_s_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[136];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[136];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i107;
  static char_T c10_cv19[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i108;
  static real_T c10_dv19[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 49.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i109;
  int32_T c10_i110;
  int32_T c10_i111;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_v_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i107 = 0; c10_i107 < 136; c10_i107++) {
    c10_mystr[c10_i107] = c10_cv19[c10_i107];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i108 = 0; c10_i108 < 136; c10_i108++) {
    c10_arr[c10_i108] = c10_dv19[c10_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i109 = 0; c10_i109 < 256; c10_i109++) {
    c10_tt[c10_i109] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i110 = 0; c10_i110 < 136; c10_i110++) {
    c10_tt[c10_i110] = c10_arr[c10_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i111 = 0; c10_i111 < 256; c10_i111++) {
    c10_myarr256[c10_i111] = c10_tt[c10_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_t_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[135];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[135];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i112;
  static char_T c10_cv20[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i113;
  static real_T c10_dv20[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 49.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i114;
  int32_T c10_i115;
  int32_T c10_i116;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_w_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i112 = 0; c10_i112 < 135; c10_i112++) {
    c10_mystr[c10_i112] = c10_cv20[c10_i112];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i113 = 0; c10_i113 < 135; c10_i113++) {
    c10_arr[c10_i113] = c10_dv20[c10_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i114 = 0; c10_i114 < 256; c10_i114++) {
    c10_tt[c10_i114] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i115 = 0; c10_i115 < 135; c10_i115++) {
    c10_tt[c10_i115] = c10_arr[c10_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i116 = 0; c10_i116 < 256; c10_i116++) {
    c10_myarr256[c10_i116] = c10_tt[c10_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_u_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[131];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[131];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i117;
  static char_T c10_cv21[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '1',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c10_i118;
  static real_T c10_dv21[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0,
    67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 49.0, 53.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i119;
  int32_T c10_i120;
  int32_T c10_i121;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_x_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i117 = 0; c10_i117 < 131; c10_i117++) {
    c10_mystr[c10_i117] = c10_cv21[c10_i117];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i118 = 0; c10_i118 < 131; c10_i118++) {
    c10_arr[c10_i118] = c10_dv21[c10_i118];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 131.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i119 = 0; c10_i119 < 256; c10_i119++) {
    c10_tt[c10_i119] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i120 = 0; c10_i120 < 131; c10_i120++) {
    c10_tt[c10_i120] = c10_arr[c10_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i121 = 0; c10_i121 < 256; c10_i121++) {
    c10_myarr256[c10_i121] = c10_tt[c10_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_v_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[134];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[134];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i122;
  static char_T c10_cv22[134] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c10_i123;
  static real_T c10_dv22[134] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 49.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i124;
  int32_T c10_i125;
  int32_T c10_i126;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_y_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i122 = 0; c10_i122 < 134; c10_i122++) {
    c10_mystr[c10_i122] = c10_cv22[c10_i122];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i123 = 0; c10_i123 < 134; c10_i123++) {
    c10_arr[c10_i123] = c10_dv22[c10_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i124 = 0; c10_i124 < 256; c10_i124++) {
    c10_tt[c10_i124] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i125 = 0; c10_i125 < 134; c10_i125++) {
    c10_tt[c10_i125] = c10_arr[c10_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i126 = 0; c10_i126 < 256; c10_i126++) {
    c10_myarr256[c10_i126] = c10_tt[c10_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_w_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[133];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[133];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i127;
  static char_T c10_cv23[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c10_i128;
  static real_T c10_dv23[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 49.0,
    53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i129;
  int32_T c10_i130;
  int32_T c10_i131;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_ab_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i127 = 0; c10_i127 < 133; c10_i127++) {
    c10_mystr[c10_i127] = c10_cv23[c10_i127];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i128 = 0; c10_i128 < 133; c10_i128++) {
    c10_arr[c10_i128] = c10_dv23[c10_i128];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i129 = 0; c10_i129 < 256; c10_i129++) {
    c10_tt[c10_i129] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i130 = 0; c10_i130 < 133; c10_i130++) {
    c10_tt[c10_i130] = c10_arr[c10_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i131 = 0; c10_i131 < 256; c10_i131++) {
    c10_myarr256[c10_i131] = c10_tt[c10_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_x_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[142];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[142];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i132;
  static char_T c10_cv24[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i133;
  static real_T c10_dv24[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 67.0, 72.0, 69.0,
    83.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c10_i134;
  int32_T c10_i135;
  int32_T c10_i136;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_bb_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 7U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  for (c10_i132 = 0; c10_i132 < 142; c10_i132++) {
    c10_mystr[c10_i132] = c10_cv24[c10_i132];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i133 = 0; c10_i133 < 142; c10_i133++) {
    c10_arr[c10_i133] = c10_dv24[c10_i133];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i134 = 0; c10_i134 < 256; c10_i134++) {
    c10_tt[c10_i134] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i135 = 0; c10_i135 < 142; c10_i135++) {
    c10_tt[c10_i135] = c10_arr[c10_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i136 = 0; c10_i136 < 256; c10_i136++) {
    c10_myarr256[c10_i136] = c10_tt[c10_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_y_encStr2Arr(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c10_myarr256[256])
{
  uint32_T c10_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[225];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[225];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  int32_T c10_i137;
  static char_T c10_cv25[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=',
    '\"', '1', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"',
    ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '4', '\"', ' ', 'e', 'n', 'd', '=',
    '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '8', '\"', ' ', ' ',
    's', 't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '4', '\"', ' ', 'a', 'u', '=', '\"', '2', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i138;
  static real_T c10_dv25[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 52.0, 34.0, 32.0,
    101.0, 110.0, 100.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0,
    56.0, 34.0, 32.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0,
    51.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 52.0, 34.0,
    32.0, 97.0, 117.0, 61.0, 34.0, 50.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0,
    34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0,
    84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0,
    34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c10_i139;
  int32_T c10_i140;
  int32_T c10_i141;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_cb_debug_family_names,
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
  for (c10_i137 = 0; c10_i137 < 225; c10_i137++) {
    c10_mystr[c10_i137] = c10_cv25[c10_i137];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
  c10_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
  for (c10_i138 = 0; c10_i138 < 225; c10_i138++) {
    c10_arr[c10_i138] = c10_dv25[c10_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_padsize = c10_maxarrsize - c10_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
  for (c10_i139 = 0; c10_i139 < 256; c10_i139++) {
    c10_tt[c10_i139] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
  for (c10_i140 = 0; c10_i140 < 225; c10_i140++) {
    c10_tt[c10_i140] = c10_arr[c10_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
  for (c10_i141 = 0; c10_i141 < 256; c10_i141++) {
    c10_myarr256[c10_i141] = c10_tt[c10_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c10_rand(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  return c10_eml_rand(chartInstance);
}

static real_T c10_eml_rand(SFc10_lib_affectiveChar_scenarioInstanceStruct
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
  int32_T c10_i142;
  uint32_T c10_icng;
  uint32_T c10_jsr;
  uint32_T c10_u1;
  uint32_T c10_u2;
  uint32_T c10_ui;
  uint32_T c10_b_ui;
  real_T c10_c_r;
  real_T c10_d1;
  uint32_T c10_uv2[625];
  int32_T c10_i143;
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
      for (c10_i142 = 0; c10_i142 < 2; c10_i142++) {
        chartInstance->c10_b_state[c10_i142] = 362436069U + 158852560U *
          (uint32_T)c10_i142;
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
      for (c10_i143 = 0; c10_i143 < 625; c10_i143++) {
        chartInstance->c10_c_state[c10_i143] = c10_uv2[c10_i143];
      }

      chartInstance->c10_c_state_not_empty = true;
    }

    c10_d2 = c10_c_eml_rand_mt19937ar(chartInstance, chartInstance->c10_c_state);
    c10_r = c10_d2;
  }

  return c10_r;
}

static void c10_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_d_state[625])
{
  real_T c10_d3;
  int32_T c10_i144;
  c10_d3 = 5489.0;
  for (c10_i144 = 0; c10_i144 < 625; c10_i144++) {
    c10_d_state[c10_i144] = 0U;
  }

  c10_b_twister_state_vector(chartInstance, c10_d_state, c10_d3);
}

static void c10_twister_state_vector
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed, uint32_T c10_b_mt[625])
{
  int32_T c10_i145;
  for (c10_i145 = 0; c10_i145 < 625; c10_i145++) {
    c10_b_mt[c10_i145] = c10_mt[c10_i145];
  }

  c10_b_twister_state_vector(chartInstance, c10_b_mt, c10_seed);
}

static void c10_b_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_d_state[625], uint32_T c10_e_state[625], real_T *c10_r)
{
  int32_T c10_i146;
  for (c10_i146 = 0; c10_i146 < 625; c10_i146++) {
    c10_e_state[c10_i146] = c10_d_state[c10_i146];
  }

  *c10_r = c10_c_eml_rand_mt19937ar(chartInstance, c10_e_state);
}

static void c10_eml_error(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  int32_T c10_i147;
  static char_T c10_cv26[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i',
    'd', 'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c10_u[37];
  const mxArray *c10_y = NULL;
  (void)chartInstance;
  for (c10_i147 = 0; c10_i147 < 37; c10_i147++) {
    c10_u[c10_i147] = c10_cv26[c10_i147];
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
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i148;
  real_T c10_b_inData[256];
  int32_T c10_i149;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i148 = 0; c10_i148 < 256; c10_i148++) {
    c10_b_inData[c10_i148] = (*(real_T (*)[256])c10_inData)[c10_i148];
  }

  for (c10_i149 = 0; c10_i149 < 256; c10_i149++) {
    c10_u[c10_i149] = c10_b_inData[c10_i149];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[256])
{
  real_T c10_dv26[256];
  int32_T c10_i150;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv26, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c10_i150 = 0; c10_i150 < 256; c10_i150++) {
    c10_y[c10_i150] = c10_dv26[c10_i150];
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
  int32_T c10_i151;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_poseBML = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_poseBML), &c10_thisId,
                       c10_y);
  sf_mex_destroy(&c10_poseBML);
  for (c10_i151 = 0; c10_i151 < 256; c10_i151++) {
    (*(real_T (*)[256])c10_outData)[c10_i151] = c10_y[c10_i151];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_b_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
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
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(boolean_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static boolean_T c10_c_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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
  const mxArray *c10_aVarTruthTableCondition_8;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  boolean_T c10_y;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_aVarTruthTableCondition_8 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_aVarTruthTableCondition_8), &c10_thisId);
  sf_mex_destroy(&c10_aVarTruthTableCondition_8);
  *(boolean_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i152;
  real_T c10_b_inData[256];
  int32_T c10_i153;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i152 = 0; c10_i152 < 256; c10_i152++) {
    c10_b_inData[c10_i152] = (*(real_T (*)[256])c10_inData)[c10_i152];
  }

  for (c10_i153 = 0; c10_i153 < 256; c10_i153++) {
    c10_u[c10_i153] = c10_b_inData[c10_i153];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_d_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y[256])
{
  real_T c10_dv27[256];
  int32_T c10_i154;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv27, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c10_i154 = 0; c10_i154 < 256; c10_i154++) {
    c10_y[c10_i154] = c10_dv27[c10_i154];
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
  int32_T c10_i155;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_myarr256 = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_myarr256), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_myarr256);
  for (c10_i155 = 0; c10_i155 < 256; c10_i155++) {
    (*(real_T (*)[256])c10_outData)[c10_i155] = c10_y[c10_i155];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i156;
  char_T c10_b_inData[147];
  int32_T c10_i157;
  char_T c10_u[147];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i156 = 0; c10_i156 < 147; c10_i156++) {
    c10_b_inData[c10_i156] = (*(char_T (*)[147])c10_inData)[c10_i156];
  }

  for (c10_i157 = 0; c10_i157 < 147; c10_i157++) {
    c10_u[c10_i157] = c10_b_inData[c10_i157];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i158;
  real_T c10_b_inData[147];
  int32_T c10_i159;
  real_T c10_u[147];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i158 = 0; c10_i158 < 147; c10_i158++) {
    c10_b_inData[c10_i158] = (*(real_T (*)[147])c10_inData)[c10_i158];
  }

  for (c10_i159 = 0; c10_i159 < 147; c10_i159++) {
    c10_u[c10_i159] = c10_b_inData[c10_i159];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i160;
  char_T c10_b_inData[164];
  int32_T c10_i161;
  char_T c10_u[164];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i160 = 0; c10_i160 < 164; c10_i160++) {
    c10_b_inData[c10_i160] = (*(char_T (*)[164])c10_inData)[c10_i160];
  }

  for (c10_i161 = 0; c10_i161 < 164; c10_i161++) {
    c10_u[c10_i161] = c10_b_inData[c10_i161];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i162;
  real_T c10_b_inData[164];
  int32_T c10_i163;
  real_T c10_u[164];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i162 = 0; c10_i162 < 164; c10_i162++) {
    c10_b_inData[c10_i162] = (*(real_T (*)[164])c10_inData)[c10_i162];
  }

  for (c10_i163 = 0; c10_i163 < 164; c10_i163++) {
    c10_u[c10_i163] = c10_b_inData[c10_i163];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i164;
  char_T c10_b_inData[68];
  int32_T c10_i165;
  char_T c10_u[68];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i164 = 0; c10_i164 < 68; c10_i164++) {
    c10_b_inData[c10_i164] = (*(char_T (*)[68])c10_inData)[c10_i164];
  }

  for (c10_i165 = 0; c10_i165 < 68; c10_i165++) {
    c10_u[c10_i165] = c10_b_inData[c10_i165];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 68),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i166;
  real_T c10_b_inData[68];
  int32_T c10_i167;
  real_T c10_u[68];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i166 = 0; c10_i166 < 68; c10_i166++) {
    c10_b_inData[c10_i166] = (*(real_T (*)[68])c10_inData)[c10_i166];
  }

  for (c10_i167 = 0; c10_i167 < 68; c10_i167++) {
    c10_u[c10_i167] = c10_b_inData[c10_i167];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i168;
  char_T c10_b_inData[223];
  int32_T c10_i169;
  char_T c10_u[223];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i168 = 0; c10_i168 < 223; c10_i168++) {
    c10_b_inData[c10_i168] = (*(char_T (*)[223])c10_inData)[c10_i168];
  }

  for (c10_i169 = 0; c10_i169 < 223; c10_i169++) {
    c10_u[c10_i169] = c10_b_inData[c10_i169];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i170;
  real_T c10_b_inData[223];
  int32_T c10_i171;
  real_T c10_u[223];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i170 = 0; c10_i170 < 223; c10_i170++) {
    c10_b_inData[c10_i170] = (*(real_T (*)[223])c10_inData)[c10_i170];
  }

  for (c10_i171 = 0; c10_i171 < 223; c10_i171++) {
    c10_u[c10_i171] = c10_b_inData[c10_i171];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_m_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i172;
  char_T c10_b_inData[225];
  int32_T c10_i173;
  char_T c10_u[225];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i172 = 0; c10_i172 < 225; c10_i172++) {
    c10_b_inData[c10_i172] = (*(char_T (*)[225])c10_inData)[c10_i172];
  }

  for (c10_i173 = 0; c10_i173 < 225; c10_i173++) {
    c10_u[c10_i173] = c10_b_inData[c10_i173];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_n_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i174;
  real_T c10_b_inData[225];
  int32_T c10_i175;
  real_T c10_u[225];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i174 = 0; c10_i174 < 225; c10_i174++) {
    c10_b_inData[c10_i174] = (*(real_T (*)[225])c10_inData)[c10_i174];
  }

  for (c10_i175 = 0; c10_i175 < 225; c10_i175++) {
    c10_u[c10_i175] = c10_b_inData[c10_i175];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_o_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i176;
  char_T c10_b_inData[87];
  int32_T c10_i177;
  char_T c10_u[87];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i176 = 0; c10_i176 < 87; c10_i176++) {
    c10_b_inData[c10_i176] = (*(char_T (*)[87])c10_inData)[c10_i176];
  }

  for (c10_i177 = 0; c10_i177 < 87; c10_i177++) {
    c10_u[c10_i177] = c10_b_inData[c10_i177];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 87),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_p_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i178;
  real_T c10_b_inData[87];
  int32_T c10_i179;
  real_T c10_u[87];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i178 = 0; c10_i178 < 87; c10_i178++) {
    c10_b_inData[c10_i178] = (*(real_T (*)[87])c10_inData)[c10_i178];
  }

  for (c10_i179 = 0; c10_i179 < 87; c10_i179++) {
    c10_u[c10_i179] = c10_b_inData[c10_i179];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_q_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i180;
  creal_T c10_b_inData[256];
  int32_T c10_i181;
  creal_T c10_u[256];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i180 = 0; c10_i180 < 256; c10_i180++) {
    c10_b_inData[c10_i180] = (*(creal_T (*)[256])c10_inData)[c10_i180];
  }

  for (c10_i181 = 0; c10_i181 < 256; c10_i181++) {
    c10_u[c10_i181] = c10_b_inData[c10_i181];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 1U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_e_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, creal_T c10_y[256])
{
  creal_T c10_dcv1[256];
  int32_T c10_i182;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dcv1, 1, 0, 1U, 1, 0U, 2,
                256, 1);
  for (c10_i182 = 0; c10_i182 < 256; c10_i182++) {
    c10_y[c10_i182] = c10_dcv1[c10_i182];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_gazeBML;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  creal_T c10_y[256];
  int32_T c10_i183;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_gazeBML = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_gazeBML), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_gazeBML);
  for (c10_i183 = 0; c10_i183 < 256; c10_i183++) {
    (*(creal_T (*)[256])c10_outData)[c10_i183] = c10_y[c10_i183];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_r_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i184;
  char_T c10_b_inData[118];
  int32_T c10_i185;
  char_T c10_u[118];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i184 = 0; c10_i184 < 118; c10_i184++) {
    c10_b_inData[c10_i184] = (*(char_T (*)[118])c10_inData)[c10_i184];
  }

  for (c10_i185 = 0; c10_i185 < 118; c10_i185++) {
    c10_u[c10_i185] = c10_b_inData[c10_i185];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_s_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i186;
  real_T c10_b_inData[118];
  int32_T c10_i187;
  real_T c10_u[118];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i186 = 0; c10_i186 < 118; c10_i186++) {
    c10_b_inData[c10_i186] = (*(real_T (*)[118])c10_inData)[c10_i186];
  }

  for (c10_i187 = 0; c10_i187 < 118; c10_i187++) {
    c10_u[c10_i187] = c10_b_inData[c10_i187];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_t_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i188;
  char_T c10_b_inData[119];
  int32_T c10_i189;
  char_T c10_u[119];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i188 = 0; c10_i188 < 119; c10_i188++) {
    c10_b_inData[c10_i188] = (*(char_T (*)[119])c10_inData)[c10_i188];
  }

  for (c10_i189 = 0; c10_i189 < 119; c10_i189++) {
    c10_u[c10_i189] = c10_b_inData[c10_i189];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_u_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i190;
  real_T c10_b_inData[119];
  int32_T c10_i191;
  real_T c10_u[119];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i190 = 0; c10_i190 < 119; c10_i190++) {
    c10_b_inData[c10_i190] = (*(real_T (*)[119])c10_inData)[c10_i190];
  }

  for (c10_i191 = 0; c10_i191 < 119; c10_i191++) {
    c10_u[c10_i191] = c10_b_inData[c10_i191];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_v_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i192;
  char_T c10_b_inData[116];
  int32_T c10_i193;
  char_T c10_u[116];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i192 = 0; c10_i192 < 116; c10_i192++) {
    c10_b_inData[c10_i192] = (*(char_T (*)[116])c10_inData)[c10_i192];
  }

  for (c10_i193 = 0; c10_i193 < 116; c10_i193++) {
    c10_u[c10_i193] = c10_b_inData[c10_i193];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_w_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i194;
  real_T c10_b_inData[116];
  int32_T c10_i195;
  real_T c10_u[116];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i194 = 0; c10_i194 < 116; c10_i194++) {
    c10_b_inData[c10_i194] = (*(real_T (*)[116])c10_inData)[c10_i194];
  }

  for (c10_i195 = 0; c10_i195 < 116; c10_i195++) {
    c10_u[c10_i195] = c10_b_inData[c10_i195];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_x_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i196;
  char_T c10_b_inData[120];
  int32_T c10_i197;
  char_T c10_u[120];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i196 = 0; c10_i196 < 120; c10_i196++) {
    c10_b_inData[c10_i196] = (*(char_T (*)[120])c10_inData)[c10_i196];
  }

  for (c10_i197 = 0; c10_i197 < 120; c10_i197++) {
    c10_u[c10_i197] = c10_b_inData[c10_i197];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_y_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i198;
  real_T c10_b_inData[120];
  int32_T c10_i199;
  real_T c10_u[120];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i198 = 0; c10_i198 < 120; c10_i198++) {
    c10_b_inData[c10_i198] = (*(real_T (*)[120])c10_inData)[c10_i198];
  }

  for (c10_i199 = 0; c10_i199 < 120; c10_i199++) {
    c10_u[c10_i199] = c10_b_inData[c10_i199];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i200;
  char_T c10_b_inData[121];
  int32_T c10_i201;
  char_T c10_u[121];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i200 = 0; c10_i200 < 121; c10_i200++) {
    c10_b_inData[c10_i200] = (*(char_T (*)[121])c10_inData)[c10_i200];
  }

  for (c10_i201 = 0; c10_i201 < 121; c10_i201++) {
    c10_u[c10_i201] = c10_b_inData[c10_i201];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i202;
  real_T c10_b_inData[121];
  int32_T c10_i203;
  real_T c10_u[121];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i202 = 0; c10_i202 < 121; c10_i202++) {
    c10_b_inData[c10_i202] = (*(real_T (*)[121])c10_inData)[c10_i202];
  }

  for (c10_i203 = 0; c10_i203 < 121; c10_i203++) {
    c10_u[c10_i203] = c10_b_inData[c10_i203];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i204;
  char_T c10_b_inData[122];
  int32_T c10_i205;
  char_T c10_u[122];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i204 = 0; c10_i204 < 122; c10_i204++) {
    c10_b_inData[c10_i204] = (*(char_T (*)[122])c10_inData)[c10_i204];
  }

  for (c10_i205 = 0; c10_i205 < 122; c10_i205++) {
    c10_u[c10_i205] = c10_b_inData[c10_i205];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_db_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i206;
  real_T c10_b_inData[122];
  int32_T c10_i207;
  real_T c10_u[122];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i206 = 0; c10_i206 < 122; c10_i206++) {
    c10_b_inData[c10_i206] = (*(real_T (*)[122])c10_inData)[c10_i206];
  }

  for (c10_i207 = 0; c10_i207 < 122; c10_i207++) {
    c10_u[c10_i207] = c10_b_inData[c10_i207];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i208;
  char_T c10_b_inData[123];
  int32_T c10_i209;
  char_T c10_u[123];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i208 = 0; c10_i208 < 123; c10_i208++) {
    c10_b_inData[c10_i208] = (*(char_T (*)[123])c10_inData)[c10_i208];
  }

  for (c10_i209 = 0; c10_i209 < 123; c10_i209++) {
    c10_u[c10_i209] = c10_b_inData[c10_i209];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i210;
  real_T c10_b_inData[123];
  int32_T c10_i211;
  real_T c10_u[123];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i210 = 0; c10_i210 < 123; c10_i210++) {
    c10_b_inData[c10_i210] = (*(real_T (*)[123])c10_inData)[c10_i210];
  }

  for (c10_i211 = 0; c10_i211 < 123; c10_i211++) {
    c10_u[c10_i211] = c10_b_inData[c10_i211];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i212;
  char_T c10_b_inData[133];
  int32_T c10_i213;
  char_T c10_u[133];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i212 = 0; c10_i212 < 133; c10_i212++) {
    c10_b_inData[c10_i212] = (*(char_T (*)[133])c10_inData)[c10_i212];
  }

  for (c10_i213 = 0; c10_i213 < 133; c10_i213++) {
    c10_u[c10_i213] = c10_b_inData[c10_i213];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i214;
  real_T c10_b_inData[133];
  int32_T c10_i215;
  real_T c10_u[133];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i214 = 0; c10_i214 < 133; c10_i214++) {
    c10_b_inData[c10_i214] = (*(real_T (*)[133])c10_inData)[c10_i214];
  }

  for (c10_i215 = 0; c10_i215 < 133; c10_i215++) {
    c10_u[c10_i215] = c10_b_inData[c10_i215];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i216;
  char_T c10_b_inData[137];
  int32_T c10_i217;
  char_T c10_u[137];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i216 = 0; c10_i216 < 137; c10_i216++) {
    c10_b_inData[c10_i216] = (*(char_T (*)[137])c10_inData)[c10_i216];
  }

  for (c10_i217 = 0; c10_i217 < 137; c10_i217++) {
    c10_u[c10_i217] = c10_b_inData[c10_i217];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i218;
  real_T c10_b_inData[137];
  int32_T c10_i219;
  real_T c10_u[137];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i218 = 0; c10_i218 < 137; c10_i218++) {
    c10_b_inData[c10_i218] = (*(real_T (*)[137])c10_inData)[c10_i218];
  }

  for (c10_i219 = 0; c10_i219 < 137; c10_i219++) {
    c10_u[c10_i219] = c10_b_inData[c10_i219];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i220;
  char_T c10_b_inData[138];
  int32_T c10_i221;
  char_T c10_u[138];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i220 = 0; c10_i220 < 138; c10_i220++) {
    c10_b_inData[c10_i220] = (*(char_T (*)[138])c10_inData)[c10_i220];
  }

  for (c10_i221 = 0; c10_i221 < 138; c10_i221++) {
    c10_u[c10_i221] = c10_b_inData[c10_i221];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i222;
  real_T c10_b_inData[138];
  int32_T c10_i223;
  real_T c10_u[138];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i222 = 0; c10_i222 < 138; c10_i222++) {
    c10_b_inData[c10_i222] = (*(real_T (*)[138])c10_inData)[c10_i222];
  }

  for (c10_i223 = 0; c10_i223 < 138; c10_i223++) {
    c10_u[c10_i223] = c10_b_inData[c10_i223];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i224;
  char_T c10_b_inData[136];
  int32_T c10_i225;
  char_T c10_u[136];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i224 = 0; c10_i224 < 136; c10_i224++) {
    c10_b_inData[c10_i224] = (*(char_T (*)[136])c10_inData)[c10_i224];
  }

  for (c10_i225 = 0; c10_i225 < 136; c10_i225++) {
    c10_u[c10_i225] = c10_b_inData[c10_i225];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i226;
  real_T c10_b_inData[136];
  int32_T c10_i227;
  real_T c10_u[136];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i226 = 0; c10_i226 < 136; c10_i226++) {
    c10_b_inData[c10_i226] = (*(real_T (*)[136])c10_inData)[c10_i226];
  }

  for (c10_i227 = 0; c10_i227 < 136; c10_i227++) {
    c10_u[c10_i227] = c10_b_inData[c10_i227];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i228;
  char_T c10_b_inData[135];
  int32_T c10_i229;
  char_T c10_u[135];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i228 = 0; c10_i228 < 135; c10_i228++) {
    c10_b_inData[c10_i228] = (*(char_T (*)[135])c10_inData)[c10_i228];
  }

  for (c10_i229 = 0; c10_i229 < 135; c10_i229++) {
    c10_u[c10_i229] = c10_b_inData[c10_i229];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i230;
  real_T c10_b_inData[135];
  int32_T c10_i231;
  real_T c10_u[135];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i230 = 0; c10_i230 < 135; c10_i230++) {
    c10_b_inData[c10_i230] = (*(real_T (*)[135])c10_inData)[c10_i230];
  }

  for (c10_i231 = 0; c10_i231 < 135; c10_i231++) {
    c10_u[c10_i231] = c10_b_inData[c10_i231];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i232;
  char_T c10_b_inData[131];
  int32_T c10_i233;
  char_T c10_u[131];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i232 = 0; c10_i232 < 131; c10_i232++) {
    c10_b_inData[c10_i232] = (*(char_T (*)[131])c10_inData)[c10_i232];
  }

  for (c10_i233 = 0; c10_i233 < 131; c10_i233++) {
    c10_u[c10_i233] = c10_b_inData[c10_i233];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i234;
  real_T c10_b_inData[131];
  int32_T c10_i235;
  real_T c10_u[131];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i234 = 0; c10_i234 < 131; c10_i234++) {
    c10_b_inData[c10_i234] = (*(real_T (*)[131])c10_inData)[c10_i234];
  }

  for (c10_i235 = 0; c10_i235 < 131; c10_i235++) {
    c10_u[c10_i235] = c10_b_inData[c10_i235];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i236;
  char_T c10_b_inData[134];
  int32_T c10_i237;
  char_T c10_u[134];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i236 = 0; c10_i236 < 134; c10_i236++) {
    c10_b_inData[c10_i236] = (*(char_T (*)[134])c10_inData)[c10_i236];
  }

  for (c10_i237 = 0; c10_i237 < 134; c10_i237++) {
    c10_u[c10_i237] = c10_b_inData[c10_i237];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i238;
  real_T c10_b_inData[134];
  int32_T c10_i239;
  real_T c10_u[134];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i238 = 0; c10_i238 < 134; c10_i238++) {
    c10_b_inData[c10_i238] = (*(real_T (*)[134])c10_inData)[c10_i238];
  }

  for (c10_i239 = 0; c10_i239 < 134; c10_i239++) {
    c10_u[c10_i239] = c10_b_inData[c10_i239];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i240;
  char_T c10_b_inData[142];
  int32_T c10_i241;
  char_T c10_u[142];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i240 = 0; c10_i240 < 142; c10_i240++) {
    c10_b_inData[c10_i240] = (*(char_T (*)[142])c10_inData)[c10_i240];
  }

  for (c10_i241 = 0; c10_i241 < 142; c10_i241++) {
    c10_u[c10_i241] = c10_b_inData[c10_i241];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i242;
  real_T c10_b_inData[142];
  int32_T c10_i243;
  real_T c10_u[142];
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i242 = 0; c10_i242 < 142; c10_i242++) {
    c10_b_inData[c10_i242] = (*(real_T (*)[142])c10_inData)[c10_i242];
  }

  for (c10_i243 = 0; c10_i243 < 142; c10_i243++) {
    c10_u[c10_i243] = c10_b_inData[c10_i243];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

const mxArray *sf_c10_lib_affectiveChar_scenario_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_createstruct("structure", 2, 38, 1),
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
  const mxArray *c10_rhs31 = NULL;
  const mxArray *c10_lhs31 = NULL;
  const mxArray *c10_rhs32 = NULL;
  const mxArray *c10_lhs32 = NULL;
  const mxArray *c10_rhs33 = NULL;
  const mxArray *c10_lhs33 = NULL;
  const mxArray *c10_rhs34 = NULL;
  const mxArray *c10_lhs34 = NULL;
  const mxArray *c10_rhs35 = NULL;
  const mxArray *c10_lhs35 = NULL;
  const mxArray *c10_rhs36 = NULL;
  const mxArray *c10_lhs36 = NULL;
  const mxArray *c10_rhs37 = NULL;
  const mxArray *c10_lhs37 = NULL;
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("all"), "name", "name", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372614814U), "fileTimeLo",
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
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372615558U), "fileTimeLo",
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
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("randi"), "name", "name", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("rand"), "name", "name", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand"), "name", "name",
                  13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 13);
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
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eps"), "name", "name", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_eps"), "name", "name",
                  26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isequal"), "name", "name",
                  28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("isnan"), "name", "name", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c10_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c10_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c10_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_error"), "name", "name",
                  34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c10_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("floor"), "name", "name", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c10_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c10_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c10_info, c10_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c10_info, c10_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c10_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c10_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c10_info, sf_mex_duplicatearraysafe(&c10_lhs37), "lhs", "lhs",
                  37);
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
  sf_mex_destroy(&c10_rhs31);
  sf_mex_destroy(&c10_lhs31);
  sf_mex_destroy(&c10_rhs32);
  sf_mex_destroy(&c10_lhs32);
  sf_mex_destroy(&c10_rhs33);
  sf_mex_destroy(&c10_lhs33);
  sf_mex_destroy(&c10_rhs34);
  sf_mex_destroy(&c10_lhs34);
  sf_mex_destroy(&c10_rhs35);
  sf_mex_destroy(&c10_lhs35);
  sf_mex_destroy(&c10_rhs36);
  sf_mex_destroy(&c10_lhs36);
  sf_mex_destroy(&c10_rhs37);
  sf_mex_destroy(&c10_lhs37);
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

static void c10_activate_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = c10_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_deactivate_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c10_event_secs,
               chartInstance->c10_sfEvent);
}

static void c10_increment_counters_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c10_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c10_temporalCounter_i1++;
  }
}

static void c10_reset_counters_secsc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c10_lib_affectiveChar_scenario_secs(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_activate_secsc10_lib_affectiveChar_scenario(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c10_lib_affectiveChar_scenario_secs
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_increment_counters_secsc10_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c10_lib_affectiveChar_scenario_secs
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_reset_counters_secsc10_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_deactivate_c10_lib_affectiveChar_scenario_secs(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_deactivate_secsc10_lib_affectiveChar_scenario(chartInstance);
}

boolean_T sf_exported_auto_isStablec10_lib_affectiveChar_scenario(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  return chartInstance->c10_isStable;
}

void sf_exported_auto_duringc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_c10_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_enterc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_sendBML(chartInstance);
  c10_enter_atomic_c10_lib_affectiveChar_scenario(chartInstance);
  c10_enter_internal_c10_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_exitc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_exit_internal_c10_lib_affectiveChar_scenario(chartInstance);
  c10_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_sendBML(chartInstance);
}

void sf_exported_auto_disablec10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c10_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initBuffersc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_activate_callc10_lib_affectiveChar_scenario(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  chartInstance->c10_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc10_lib_affectiveChar_scenario
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_reset_call_counterc10_lib_affectiveChar_scenario(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_deactivate_callc10_lib_affectiveChar_scenario(SimStruct
  *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
}

void sf_exported_auto_initc10_lib_affectiveChar_scenario(SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_initc10_lib_affectiveChar_scenario(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec10_lib_affectiveChar_scenario
  (SimStruct *c10_S)
{
  const mxArray *c10_out = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_out = NULL;
  sf_mex_assign(&c10_out,
                sf_internal_get_sim_state_c10_lib_affectiveChar_scenario(c10_S),
                false);
  return c10_out;
}

void sf_exported_auto_setSimstatec10_lib_affectiveChar_scenario(SimStruct *c10_S,
  const mxArray *c10_in)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  sf_internal_set_sim_state_c10_lib_affectiveChar_scenario(c10_S, sf_mex_dup
    (c10_in));
  sf_mex_destroy(&c10_in);
}

void sf_exported_auto_check_state_inconsistency_c10_lib_affectiveChar_scenario
  (SimStruct *c10_S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_scenarioMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c10_sendBMLc10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c10_arg[256])
{
  int32_T c10_i244;
  int32_T c10_i245;
  int32_T c10_i246;
  real_T (*c10_b_arg)[256];
  c10_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c10_i244 = 0; c10_i244 < 256; c10_i244++) {
    _SFD_DATA_RANGE_CHECK(c10_arg[c10_i244], 7U);
  }

  _SFD_SET_DATA_VALUE_PTR(7U, c10_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c10_arg, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
  for (c10_i245 = 0; c10_i245 < 256; c10_i245++) {
    (*c10_b_arg)[c10_i245] = c10_arg[c10_i245];
  }

  for (c10_i246 = 0; c10_i246 < 256; c10_i246++) {
    _SFD_DATA_RANGE_CHECK((*c10_b_arg)[c10_i246], 7U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c10_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(7U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c10_sfEvent);
}

static void c10_idlePosec10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c10_bmlID, real_T c10_poseBML[256])
{
  uint32_T c10_debug_family_var_map[12];
  boolean_T c10_aVarTruthTableCondition_1;
  boolean_T c10_aVarTruthTableCondition_2;
  boolean_T c10_aVarTruthTableCondition_3;
  boolean_T c10_aVarTruthTableCondition_4;
  boolean_T c10_aVarTruthTableCondition_5;
  boolean_T c10_aVarTruthTableCondition_6;
  boolean_T c10_aVarTruthTableCondition_7;
  boolean_T c10_aVarTruthTableCondition_8;
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  real_T c10_dv28[256];
  int32_T c10_i247;
  int32_T c10_i248;
  real_T c10_u[256];
  const mxArray *c10_y = NULL;
  int32_T c10_i249;
  int32_T c10_i250;
  real_T c10_b_u[256];
  const mxArray *c10_b_y = NULL;
  uint32_T c10_b_debug_family_var_map[9];
  real_T c10_maxarrsize;
  real_T c10_arr[68];
  real_T c10_ss;
  real_T c10_padsize;
  real_T c10_tt[256];
  char_T c10_mystr[68];
  real_T c10_b_nargin = 1.0;
  real_T c10_b_nargout = 1.0;
  real_T c10_myarr256[256];
  int32_T c10_i251;
  static char_T c10_cv27[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd',
    'e', ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c10_i252;
  static real_T c10_dv29[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c10_i253;
  int32_T c10_i254;
  int32_T c10_i255;
  int32_T c10_i256;
  int32_T c10_i257;
  real_T c10_c_u[256];
  const mxArray *c10_c_y = NULL;
  int32_T c10_i258;
  int32_T c10_i259;
  real_T c10_d_u[256];
  const mxArray *c10_d_y = NULL;
  int32_T c10_i260;
  int32_T c10_i261;
  real_T c10_e_u[256];
  const mxArray *c10_e_y = NULL;
  int32_T c10_i262;
  int32_T c10_i263;
  real_T c10_f_u[256];
  const mxArray *c10_f_y = NULL;
  int32_T c10_i264;
  int32_T c10_i265;
  real_T c10_g_u[256];
  const mxArray *c10_g_y = NULL;
  int32_T c10_i266;
  int32_T c10_i267;
  real_T c10_h_u[256];
  const mxArray *c10_h_y = NULL;
  int32_T c10_i268;
  int32_T c10_i269;
  real_T c10_i_u[256];
  const mxArray *c10_i_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c10_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 8U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 9U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_bmlID, 10U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_poseBML, 11U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 3);
  c10_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 4);
  c10_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 5);
  c10_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 6);
  c10_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 7);
  c10_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 8);
  c10_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 9);
  c10_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 10);
  c10_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 15);
  c10_aVarTruthTableCondition_1 = c10_all(chartInstance, c10_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 19);
  c10_aVarTruthTableCondition_2 = c10_all(chartInstance, c10_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 23);
  c10_aVarTruthTableCondition_3 = c10_all(chartInstance, c10_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 27);
  c10_aVarTruthTableCondition_4 = c10_all(chartInstance, c10_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 31);
  c10_aVarTruthTableCondition_5 = c10_all(chartInstance, c10_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 35);
  c10_aVarTruthTableCondition_6 = c10_all(chartInstance, c10_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 39);
  c10_aVarTruthTableCondition_7 = c10_all(chartInstance, c10_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 43);
  c10_aVarTruthTableCondition_8 = c10_all(chartInstance, c10_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 45);
  if (CV_EML_IF(1, 1, 0, c10_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 46);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 69);
    c10_encStr2Arr(chartInstance, c10_dv28);
    for (c10_i247 = 0; c10_i247 < 256; c10_i247++) {
      c10_poseBML[c10_i247] = c10_dv28[c10_i247];
    }

    c10_updateDataWrittenToVector(chartInstance, 0U);
    c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c10_i248 = 0; c10_i248 < 256; c10_i248++) {
      c10_u[c10_i248] = c10_poseBML[c10_i248];
    }

    c10_y = NULL;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 256),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_y);
    _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -69);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 47);
    if (CV_EML_IF(1, 1, 1, c10_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 48);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 75);
      c10_b_encStr2Arr(chartInstance, c10_dv28);
      for (c10_i249 = 0; c10_i249 < 256; c10_i249++) {
        c10_poseBML[c10_i249] = c10_dv28[c10_i249];
      }

      c10_updateDataWrittenToVector(chartInstance, 0U);
      c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c10_i250 = 0; c10_i250 < 256; c10_i250++) {
        c10_b_u[c10_i250] = c10_poseBML[c10_i250];
      }

      c10_b_y = NULL;
      sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_b_y);
      _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -75);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 49);
      if (CV_EML_IF(1, 1, 2, c10_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 50);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 81);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c10_d_debug_family_names,
          c10_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_maxarrsize, 0U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c10_arr, 1U, c10_j_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c10_ss, 2U, c10_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_padsize, 3U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_tt, 4U, c10_d_sf_marshallOut,
          c10_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c10_mystr, 5U, c10_i_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargin, 6U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_b_nargout, 7U,
          c10_b_sf_marshallOut, c10_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_myarr256, 8U,
          c10_d_sf_marshallOut, c10_d_sf_marshallIn);
        for (c10_i251 = 0; c10_i251 < 68; c10_i251++) {
          c10_mystr[c10_i251] = c10_cv27[c10_i251];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 4);
        c10_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 6);
        for (c10_i252 = 0; c10_i252 < 68; c10_i252++) {
          c10_arr[c10_i252] = c10_dv29[c10_i252];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 7);
        c10_ss = 68.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 8);
        c10_padsize = c10_maxarrsize - c10_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 9);
        for (c10_i253 = 0; c10_i253 < 256; c10_i253++) {
          c10_tt[c10_i253] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 10);
        for (c10_i254 = 0; c10_i254 < 68; c10_i254++) {
          c10_tt[c10_i254] = c10_arr[c10_i254];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, 11);
        for (c10_i255 = 0; c10_i255 < 256; c10_i255++) {
          c10_myarr256[c10_i255] = c10_tt[c10_i255];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c10_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c10_i256 = 0; c10_i256 < 256; c10_i256++) {
          c10_poseBML[c10_i256] = c10_myarr256[c10_i256];
        }

        c10_updateDataWrittenToVector(chartInstance, 0U);
        c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c10_i257 = 0; c10_i257 < 256; c10_i257++) {
          c10_c_u[c10_i257] = c10_poseBML[c10_i257];
        }

        c10_c_y = NULL;
        sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 1,
          256), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c10_c_y);
        _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -81);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 51);
        if (CV_EML_IF(1, 1, 3, c10_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 52);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 87);
          c10_c_encStr2Arr(chartInstance, c10_dv28);
          for (c10_i258 = 0; c10_i258 < 256; c10_i258++) {
            c10_poseBML[c10_i258] = c10_dv28[c10_i258];
          }

          c10_updateDataWrittenToVector(chartInstance, 0U);
          c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c10_i259 = 0; c10_i259 < 256; c10_i259++) {
            c10_d_u[c10_i259] = c10_poseBML[c10_i259];
          }

          c10_d_y = NULL;
          sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c10_d_y);
          _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -87);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 53);
          if (CV_EML_IF(1, 1, 4, c10_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 54);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 93);
            c10_d_encStr2Arr(chartInstance, c10_dv28);
            for (c10_i260 = 0; c10_i260 < 256; c10_i260++) {
              c10_poseBML[c10_i260] = c10_dv28[c10_i260];
            }

            c10_updateDataWrittenToVector(chartInstance, 0U);
            c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c10_i261 = 0; c10_i261 < 256; c10_i261++) {
              c10_e_u[c10_i261] = c10_poseBML[c10_i261];
            }

            c10_e_y = NULL;
            sf_mex_assign(&c10_e_y, sf_mex_create("y", c10_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c10_e_y);
            _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -93);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 55);
            if (CV_EML_IF(1, 1, 5, c10_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 56);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 99);
              c10_e_encStr2Arr(chartInstance, c10_dv28);
              for (c10_i262 = 0; c10_i262 < 256; c10_i262++) {
                c10_poseBML[c10_i262] = c10_dv28[c10_i262];
              }

              c10_updateDataWrittenToVector(chartInstance, 0U);
              c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c10_i263 = 0; c10_i263 < 256; c10_i263++) {
                c10_f_u[c10_i263] = c10_poseBML[c10_i263];
              }

              c10_f_y = NULL;
              sf_mex_assign(&c10_f_y, sf_mex_create("y", c10_f_u, 0, 0U, 1U, 0U,
                1, 256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c10_f_y);
              _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -99);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 57);
              if (CV_EML_IF(1, 1, 6, c10_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 58);
                CV_EML_FCN(1, 7);
                _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 105);
                c10_f_encStr2Arr(chartInstance, c10_dv28);
                for (c10_i264 = 0; c10_i264 < 256; c10_i264++) {
                  c10_poseBML[c10_i264] = c10_dv28[c10_i264];
                }

                c10_updateDataWrittenToVector(chartInstance, 0U);
                c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c10_i265 = 0; c10_i265 < 256; c10_i265++) {
                  c10_g_u[c10_i265] = c10_poseBML[c10_i265];
                }

                c10_g_y = NULL;
                sf_mex_assign(&c10_g_y, sf_mex_create("y", c10_g_u, 0, 0U, 1U,
                  0U, 1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c10_g_y);
                _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -105);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 59);
                if (CV_EML_IF(1, 1, 7, c10_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 60);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 111);
                  c10_g_encStr2Arr(chartInstance, c10_dv28);
                  for (c10_i266 = 0; c10_i266 < 256; c10_i266++) {
                    c10_poseBML[c10_i266] = c10_dv28[c10_i266];
                  }

                  c10_updateDataWrittenToVector(chartInstance, 0U);
                  c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c10_i267 = 0; c10_i267 < 256; c10_i267++) {
                    c10_h_u[c10_i267] = c10_poseBML[c10_i267];
                  }

                  c10_h_y = NULL;
                  sf_mex_assign(&c10_h_y, sf_mex_create("y", c10_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c10_h_y);
                  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 62);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, 111);
                  c10_g_encStr2Arr(chartInstance, c10_dv28);
                  for (c10_i268 = 0; c10_i268 < 256; c10_i268++) {
                    c10_poseBML[c10_i268] = c10_dv28[c10_i268];
                  }

                  c10_updateDataWrittenToVector(chartInstance, 0U);
                  c10_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c10_i269 = 0; c10_i269 < 256; c10_i269++) {
                    c10_i_u[c10_i269] = c10_poseBML[c10_i269];
                  }

                  c10_i_y = NULL;
                  sf_mex_assign(&c10_i_y, sf_mex_create("y", c10_i_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c10_i_y);
                  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -111);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c10_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c10_boredGazec10_lib_affectiveChar_scenario
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T
   c10_bmlID, creal_T c10_gazeBML[256])
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
  real_T c10_dv30[256];
  int32_T c10_i270;
  int32_T c10_i271;
  creal_T c10_u[256];
  const mxArray *c10_y = NULL;
  int32_T c10_i272;
  int32_T c10_i273;
  creal_T c10_b_u[256];
  const mxArray *c10_b_y = NULL;
  int32_T c10_i274;
  int32_T c10_i275;
  creal_T c10_c_u[256];
  const mxArray *c10_c_y = NULL;
  int32_T c10_i276;
  int32_T c10_i277;
  creal_T c10_d_u[256];
  const mxArray *c10_d_y = NULL;
  int32_T c10_i278;
  int32_T c10_i279;
  creal_T c10_e_u[256];
  const mxArray *c10_e_y = NULL;
  int32_T c10_i280;
  int32_T c10_i281;
  creal_T c10_f_u[256];
  const mxArray *c10_f_y = NULL;
  int32_T c10_i282;
  int32_T c10_i283;
  creal_T c10_g_u[256];
  const mxArray *c10_g_y = NULL;
  int32_T c10_i284;
  int32_T c10_i285;
  creal_T c10_h_u[256];
  const mxArray *c10_h_y = NULL;
  int32_T c10_i286;
  int32_T c10_i287;
  creal_T c10_i_u[256];
  const mxArray *c10_i_y = NULL;
  int32_T c10_i288;
  int32_T c10_i289;
  creal_T c10_j_u[256];
  const mxArray *c10_j_y = NULL;
  int32_T c10_i290;
  int32_T c10_i291;
  creal_T c10_k_u[256];
  const mxArray *c10_k_y = NULL;
  int32_T c10_i292;
  int32_T c10_i293;
  creal_T c10_l_u[256];
  const mxArray *c10_l_y = NULL;
  int32_T c10_i294;
  int32_T c10_i295;
  creal_T c10_m_u[256];
  const mxArray *c10_m_y = NULL;
  int32_T c10_i296;
  int32_T c10_i297;
  creal_T c10_n_u[256];
  const mxArray *c10_n_y = NULL;
  int32_T c10_i298;
  int32_T c10_i299;
  creal_T c10_o_u[256];
  const mxArray *c10_o_y = NULL;
  int32_T c10_i300;
  int32_T c10_i301;
  creal_T c10_p_u[256];
  const mxArray *c10_p_y = NULL;
  int32_T c10_i302;
  int32_T c10_i303;
  creal_T c10_q_u[256];
  const mxArray *c10_q_y = NULL;
  int32_T c10_i304;
  int32_T c10_i305;
  creal_T c10_r_u[256];
  const mxArray *c10_r_y = NULL;
  int32_T c10_i306;
  int32_T c10_i307;
  creal_T c10_s_u[256];
  const mxArray *c10_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c10_j_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_gazeBML, 21U, c10_q_sf_marshallOut,
    c10_e_sf_marshallIn);
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
  c10_aVarTruthTableCondition_1 = c10_all(chartInstance, c10_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 27);
  c10_aVarTruthTableCondition_2 = c10_all(chartInstance, c10_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 30);
  c10_aVarTruthTableCondition_3 = c10_all(chartInstance, c10_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 33);
  c10_aVarTruthTableCondition_4 = c10_all(chartInstance, c10_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 36);
  c10_aVarTruthTableCondition_5 = c10_all(chartInstance, c10_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 39);
  c10_aVarTruthTableCondition_6 = c10_all(chartInstance, c10_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 42);
  c10_aVarTruthTableCondition_7 = c10_all(chartInstance, c10_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 45);
  c10_aVarTruthTableCondition_8 = c10_all(chartInstance, c10_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 48);
  c10_aVarTruthTableCondition_9 = c10_all(chartInstance, c10_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 51);
  c10_aVarTruthTableCondition_10 = c10_all(chartInstance, c10_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 54);
  c10_aVarTruthTableCondition_11 = c10_all(chartInstance, c10_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 57);
  c10_aVarTruthTableCondition_12 = c10_all(chartInstance, c10_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 60);
  c10_aVarTruthTableCondition_13 = c10_all(chartInstance, c10_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 63);
  c10_aVarTruthTableCondition_14 = c10_all(chartInstance, c10_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 66);
  c10_aVarTruthTableCondition_15 = c10_all(chartInstance, c10_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 69);
  c10_aVarTruthTableCondition_16 = c10_all(chartInstance, c10_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 72);
  c10_aVarTruthTableCondition_17 = c10_all(chartInstance, c10_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 75);
  c10_aVarTruthTableCondition_18 = c10_all(chartInstance, c10_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 77);
  if (CV_EML_IF(0, 1, 0, c10_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 78);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 121);
    c10_h_encStr2Arr(chartInstance, c10_dv30);
    for (c10_i270 = 0; c10_i270 < 256; c10_i270++) {
      c10_gazeBML[c10_i270].re = c10_dv30[c10_i270];
      c10_gazeBML[c10_i270].im = 0.0;
    }

    c10_updateDataWrittenToVector(chartInstance, 1U);
    c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
    sf_mex_printf("%s =\\n", "gazeBML");
    for (c10_i271 = 0; c10_i271 < 256; c10_i271++) {
      c10_u[c10_i271] = c10_gazeBML[c10_i271];
    }

    c10_y = NULL;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 1U, 1U, 0U, 1, 256),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_y);
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -121);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 79);
    if (CV_EML_IF(0, 1, 1, c10_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 80);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, MAX_int8_T);
      c10_i_encStr2Arr(chartInstance, c10_dv30);
      for (c10_i272 = 0; c10_i272 < 256; c10_i272++) {
        c10_gazeBML[c10_i272].re = c10_dv30[c10_i272];
        c10_gazeBML[c10_i272].im = 0.0;
      }

      c10_updateDataWrittenToVector(chartInstance, 1U);
      c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
      sf_mex_printf("%s =\\n", "gazeBML");
      for (c10_i273 = 0; c10_i273 < 256; c10_i273++) {
        c10_b_u[c10_i273] = c10_gazeBML[c10_i273];
      }

      c10_b_y = NULL;
      sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 0, 1U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c10_b_y);
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -127);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 81);
      if (CV_EML_IF(0, 1, 2, c10_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 82);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 133U);
        c10_j_encStr2Arr(chartInstance, c10_dv30);
        for (c10_i274 = 0; c10_i274 < 256; c10_i274++) {
          c10_gazeBML[c10_i274].re = c10_dv30[c10_i274];
          c10_gazeBML[c10_i274].im = 0.0;
        }

        c10_updateDataWrittenToVector(chartInstance, 1U);
        c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
        sf_mex_printf("%s =\\n", "gazeBML");
        for (c10_i275 = 0; c10_i275 < 256; c10_i275++) {
          c10_c_u[c10_i275] = c10_gazeBML[c10_i275];
        }

        c10_c_y = NULL;
        sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_c_u, 0, 1U, 1U, 0U, 1,
          256), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c10_c_y);
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -133);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 83);
        if (CV_EML_IF(0, 1, 3, c10_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 84);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 139U);
          c10_k_encStr2Arr(chartInstance, c10_dv30);
          for (c10_i276 = 0; c10_i276 < 256; c10_i276++) {
            c10_gazeBML[c10_i276].re = c10_dv30[c10_i276];
            c10_gazeBML[c10_i276].im = 0.0;
          }

          c10_updateDataWrittenToVector(chartInstance, 1U);
          c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
          sf_mex_printf("%s =\\n", "gazeBML");
          for (c10_i277 = 0; c10_i277 < 256; c10_i277++) {
            c10_d_u[c10_i277] = c10_gazeBML[c10_i277];
          }

          c10_d_y = NULL;
          sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_d_u, 0, 1U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c10_d_y);
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -139);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 85);
          if (CV_EML_IF(0, 1, 4, c10_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 86);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 145U);
            c10_l_encStr2Arr(chartInstance, c10_dv30);
            for (c10_i278 = 0; c10_i278 < 256; c10_i278++) {
              c10_gazeBML[c10_i278].re = c10_dv30[c10_i278];
              c10_gazeBML[c10_i278].im = 0.0;
            }

            c10_updateDataWrittenToVector(chartInstance, 1U);
            c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
            sf_mex_printf("%s =\\n", "gazeBML");
            for (c10_i279 = 0; c10_i279 < 256; c10_i279++) {
              c10_e_u[c10_i279] = c10_gazeBML[c10_i279];
            }

            c10_e_y = NULL;
            sf_mex_assign(&c10_e_y, sf_mex_create("y", c10_e_u, 0, 1U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c10_e_y);
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -145);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 87);
            if (CV_EML_IF(0, 1, 5, c10_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 88);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 151U);
              c10_m_encStr2Arr(chartInstance, c10_dv30);
              for (c10_i280 = 0; c10_i280 < 256; c10_i280++) {
                c10_gazeBML[c10_i280].re = c10_dv30[c10_i280];
                c10_gazeBML[c10_i280].im = 0.0;
              }

              c10_updateDataWrittenToVector(chartInstance, 1U);
              c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
              sf_mex_printf("%s =\\n", "gazeBML");
              for (c10_i281 = 0; c10_i281 < 256; c10_i281++) {
                c10_f_u[c10_i281] = c10_gazeBML[c10_i281];
              }

              c10_f_y = NULL;
              sf_mex_assign(&c10_f_y, sf_mex_create("y", c10_f_u, 0, 1U, 1U, 0U,
                1, 256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c10_f_y);
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -151);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 89);
              if (CV_EML_IF(0, 1, 6, c10_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 90);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 157U);
                c10_n_encStr2Arr(chartInstance, c10_dv30);
                for (c10_i282 = 0; c10_i282 < 256; c10_i282++) {
                  c10_gazeBML[c10_i282].re = c10_dv30[c10_i282];
                  c10_gazeBML[c10_i282].im = 0.0;
                }

                c10_updateDataWrittenToVector(chartInstance, 1U);
                c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                sf_mex_printf("%s =\\n", "gazeBML");
                for (c10_i283 = 0; c10_i283 < 256; c10_i283++) {
                  c10_g_u[c10_i283] = c10_gazeBML[c10_i283];
                }

                c10_g_y = NULL;
                sf_mex_assign(&c10_g_y, sf_mex_create("y", c10_g_u, 0, 1U, 1U,
                  0U, 1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c10_g_y);
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -157);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 91);
                if (CV_EML_IF(0, 1, 7, c10_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 92);
                  CV_EML_FCN(0, 8);
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 163U);
                  c10_o_encStr2Arr(chartInstance, c10_dv30);
                  for (c10_i284 = 0; c10_i284 < 256; c10_i284++) {
                    c10_gazeBML[c10_i284].re = c10_dv30[c10_i284];
                    c10_gazeBML[c10_i284].im = 0.0;
                  }

                  c10_updateDataWrittenToVector(chartInstance, 1U);
                  c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c10_i285 = 0; c10_i285 < 256; c10_i285++) {
                    c10_h_u[c10_i285] = c10_gazeBML[c10_i285];
                  }

                  c10_h_y = NULL;
                  sf_mex_assign(&c10_h_y, sf_mex_create("y", c10_h_u, 0, 1U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c10_h_y);
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -163);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 93);
                  if (CV_EML_IF(0, 1, 8, c10_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 94);
                    CV_EML_FCN(0, 9);
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 169U);
                    c10_p_encStr2Arr(chartInstance, c10_dv30);
                    for (c10_i286 = 0; c10_i286 < 256; c10_i286++) {
                      c10_gazeBML[c10_i286].re = c10_dv30[c10_i286];
                      c10_gazeBML[c10_i286].im = 0.0;
                    }

                    c10_updateDataWrittenToVector(chartInstance, 1U);
                    c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c10_i287 = 0; c10_i287 < 256; c10_i287++) {
                      c10_i_u[c10_i287] = c10_gazeBML[c10_i287];
                    }

                    c10_i_y = NULL;
                    sf_mex_assign(&c10_i_y, sf_mex_create("y", c10_i_u, 0, 1U,
                      1U, 0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c10_i_y);
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -169);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 95);
                    if (CV_EML_IF(0, 1, 9, c10_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 96);
                      CV_EML_FCN(0, 10);
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 175U);
                      c10_q_encStr2Arr(chartInstance, c10_dv30);
                      for (c10_i288 = 0; c10_i288 < 256; c10_i288++) {
                        c10_gazeBML[c10_i288].re = c10_dv30[c10_i288];
                        c10_gazeBML[c10_i288].im = 0.0;
                      }

                      c10_updateDataWrittenToVector(chartInstance, 1U);
                      c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c10_i289 = 0; c10_i289 < 256; c10_i289++) {
                        c10_j_u[c10_i289] = c10_gazeBML[c10_i289];
                      }

                      c10_j_y = NULL;
                      sf_mex_assign(&c10_j_y, sf_mex_create("y", c10_j_u, 0, 1U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c10_j_y);
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 97);
                      if (CV_EML_IF(0, 1, 10, c10_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 98);
                        CV_EML_FCN(0, 11);
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 181U);
                        c10_r_encStr2Arr(chartInstance, c10_dv30);
                        for (c10_i290 = 0; c10_i290 < 256; c10_i290++) {
                          c10_gazeBML[c10_i290].re = c10_dv30[c10_i290];
                          c10_gazeBML[c10_i290].im = 0.0;
                        }

                        c10_updateDataWrittenToVector(chartInstance, 1U);
                        c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c10_i291 = 0; c10_i291 < 256; c10_i291++) {
                          c10_k_u[c10_i291] = c10_gazeBML[c10_i291];
                        }

                        c10_k_y = NULL;
                        sf_mex_assign(&c10_k_y, sf_mex_create("y", c10_k_u, 0,
                          1U, 1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c10_k_y);
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 99);
                        if (CV_EML_IF(0, 1, 11, c10_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 100);
                          CV_EML_FCN(0, 12);
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 187U);
                          c10_s_encStr2Arr(chartInstance, c10_dv30);
                          for (c10_i292 = 0; c10_i292 < 256; c10_i292++) {
                            c10_gazeBML[c10_i292].re = c10_dv30[c10_i292];
                            c10_gazeBML[c10_i292].im = 0.0;
                          }

                          c10_updateDataWrittenToVector(chartInstance, 1U);
                          c10_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c10_i293 = 0; c10_i293 < 256; c10_i293++) {
                            c10_l_u[c10_i293] = c10_gazeBML[c10_i293];
                          }

                          c10_l_y = NULL;
                          sf_mex_assign(&c10_l_y, sf_mex_create("y", c10_l_u, 0,
                            1U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c10_l_y);
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -187);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 101);
                          if (CV_EML_IF(0, 1, 12, c10_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 102);
                            CV_EML_FCN(0, 13);
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 193U);
                            c10_t_encStr2Arr(chartInstance, c10_dv30);
                            for (c10_i294 = 0; c10_i294 < 256; c10_i294++) {
                              c10_gazeBML[c10_i294].re = c10_dv30[c10_i294];
                              c10_gazeBML[c10_i294].im = 0.0;
                            }

                            c10_updateDataWrittenToVector(chartInstance, 1U);
                            c10_errorIfDataNotWrittenToFcn(chartInstance, 1U,
                              11U);
                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c10_i295 = 0; c10_i295 < 256; c10_i295++) {
                              c10_m_u[c10_i295] = c10_gazeBML[c10_i295];
                            }

                            c10_m_y = NULL;
                            sf_mex_assign(&c10_m_y, sf_mex_create("y", c10_m_u,
                              0, 1U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c10_m_y);
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -193);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 103);
                            if (CV_EML_IF(0, 1, 13,
                                          c10_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 104);
                              CV_EML_FCN(0, 14);
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 199U);
                              c10_u_encStr2Arr(chartInstance, c10_dv30);
                              for (c10_i296 = 0; c10_i296 < 256; c10_i296++) {
                                c10_gazeBML[c10_i296].re = c10_dv30[c10_i296];
                                c10_gazeBML[c10_i296].im = 0.0;
                              }

                              c10_updateDataWrittenToVector(chartInstance, 1U);
                              c10_errorIfDataNotWrittenToFcn(chartInstance, 1U,
                                11U);
                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c10_i297 = 0; c10_i297 < 256; c10_i297++) {
                                c10_n_u[c10_i297] = c10_gazeBML[c10_i297];
                              }

                              c10_n_y = NULL;
                              sf_mex_assign(&c10_n_y, sf_mex_create("y", c10_n_u,
                                0, 1U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c10_n_y);
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -199);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 105);
                              if (CV_EML_IF(0, 1, 14,
                                            c10_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              106);
                                CV_EML_FCN(0, 15);
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              205U);
                                c10_v_encStr2Arr(chartInstance, c10_dv30);
                                for (c10_i298 = 0; c10_i298 < 256; c10_i298++) {
                                  c10_gazeBML[c10_i298].re = c10_dv30[c10_i298];
                                  c10_gazeBML[c10_i298].im = 0.0;
                                }

                                c10_updateDataWrittenToVector(chartInstance, 1U);
                                c10_errorIfDataNotWrittenToFcn(chartInstance, 1U,
                                  11U);
                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c10_i299 = 0; c10_i299 < 256; c10_i299++) {
                                  c10_o_u[c10_i299] = c10_gazeBML[c10_i299];
                                }

                                c10_o_y = NULL;
                                sf_mex_assign(&c10_o_y, sf_mex_create("y",
                                  c10_o_u, 0, 1U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c10_o_y);
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              -205);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                              107);
                                if (CV_EML_IF(0, 1, 15,
                                              c10_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                108);
                                  CV_EML_FCN(0, 16);
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                211U);
                                  c10_w_encStr2Arr(chartInstance, c10_dv30);
                                  for (c10_i300 = 0; c10_i300 < 256; c10_i300++)
                                  {
                                    c10_gazeBML[c10_i300].re = c10_dv30[c10_i300];
                                    c10_gazeBML[c10_i300].im = 0.0;
                                  }

                                  c10_updateDataWrittenToVector(chartInstance,
                                    1U);
                                  c10_errorIfDataNotWrittenToFcn(chartInstance,
                                    1U, 11U);
                                  sf_mex_printf("%s =\\n", "gazeBML");
                                  for (c10_i301 = 0; c10_i301 < 256; c10_i301++)
                                  {
                                    c10_p_u[c10_i301] = c10_gazeBML[c10_i301];
                                  }

                                  c10_p_y = NULL;
                                  sf_mex_assign(&c10_p_y, sf_mex_create("y",
                                    c10_p_u, 0, 1U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c10_p_y);
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                -211);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                109);
                                  if (CV_EML_IF(0, 1, 16,
                                                c10_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  110);
                                    CV_EML_FCN(0, 19);
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  229U);
                                    c10_x_encStr2Arr(chartInstance, c10_dv30);
                                    for (c10_i302 = 0; c10_i302 < 256; c10_i302
                                         ++) {
                                      c10_gazeBML[c10_i302].re =
                                        c10_dv30[c10_i302];
                                      c10_gazeBML[c10_i302].im = 0.0;
                                    }

                                    c10_updateDataWrittenToVector(chartInstance,
                                      1U);
                                    c10_errorIfDataNotWrittenToFcn(chartInstance,
                                      1U, 11U);
                                    sf_mex_printf("%s =\\n", "gazeBML");
                                    for (c10_i303 = 0; c10_i303 < 256; c10_i303
                                         ++) {
                                      c10_q_u[c10_i303] = c10_gazeBML[c10_i303];
                                    }

                                    c10_q_y = NULL;
                                    sf_mex_assign(&c10_q_y, sf_mex_create("y",
                                      c10_q_u, 0, 1U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c10_q_y);
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  -229);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c10_sfEvent,
                                                  111);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c10_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    112);
                                      CV_EML_FCN(0, 26);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    271);
                                      c10_y_encStr2Arr(chartInstance, c10_dv30);
                                      for (c10_i304 = 0; c10_i304 < 256;
                                           c10_i304++) {
                                        c10_gazeBML[c10_i304].re =
                                          c10_dv30[c10_i304];
                                        c10_gazeBML[c10_i304].im = 0.0;
                                      }

                                      c10_updateDataWrittenToVector
                                        (chartInstance, 1U);
                                      c10_errorIfDataNotWrittenToFcn
                                        (chartInstance, 1U, 11U);
                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c10_i305 = 0; c10_i305 < 256;
                                           c10_i305++) {
                                        c10_r_u[c10_i305] = c10_gazeBML[c10_i305];
                                      }

                                      c10_r_y = NULL;
                                      sf_mex_assign(&c10_r_y, sf_mex_create("y",
                                        c10_r_u, 0, 1U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c10_r_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    -271);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    114);
                                      CV_EML_FCN(0, 1);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c10_sfEvent,
                                                    121);
                                      c10_h_encStr2Arr(chartInstance, c10_dv30);
                                      for (c10_i306 = 0; c10_i306 < 256;
                                           c10_i306++) {
                                        c10_gazeBML[c10_i306].re =
                                          c10_dv30[c10_i306];
                                        c10_gazeBML[c10_i306].im = 0.0;
                                      }

                                      c10_updateDataWrittenToVector
                                        (chartInstance, 1U);
                                      c10_errorIfDataNotWrittenToFcn
                                        (chartInstance, 1U, 11U);
                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c10_i307 = 0; c10_i307 < 256;
                                           c10_i307++) {
                                        c10_s_u[c10_i307] = c10_gazeBML[c10_i307];
                                      }

                                      c10_s_y = NULL;
                                      sf_mex_assign(&c10_s_y, sf_mex_create("y",
                                        c10_s_u, 0, 1U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c10_s_y);
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

static void c10_sendBML(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c10_b_sendBML(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static boolean_T c10_all(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, boolean_T c10_x)
{
  boolean_T c10_b_x;
  (void)chartInstance;
  c10_b_x = c10_x;
  return (real_T)c10_b_x != 0.0;
}

void sf_exported_user_c10_lib_affectiveChar_scenario_boredGaze(SimStruct *c10_S,
  real_T c10_bmlID, creal_T c10_gazeBML[256])
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_boredGazec10_lib_affectiveChar_scenario(chartInstance, c10_bmlID,
    c10_gazeBML);
}

void sf_exported_user_c10_lib_affectiveChar_scenario_idlePose(SimStruct *c10_S,
  real_T c10_bmlID, real_T c10_poseBML[256])
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  c10_idlePosec10_lib_affectiveChar_scenario(chartInstance, c10_bmlID,
    c10_poseBML);
}

void sf_exported_user_c10_lib_affectiveChar_scenario_sendBML(SimStruct *c10_S,
  real_T c10_arg[256])
{
  int32_T c10_i308;
  real_T c10_b_arg[256];
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c10_S))->instanceInfo)
    ->chartInstance;
  for (c10_i308 = 0; c10_i308 < 256; c10_i308++) {
    c10_b_arg[c10_i308] = c10_arg[c10_i308];
  }

  c10_sendBMLc10_lib_affectiveChar_scenario(chartInstance, c10_b_arg);
}

static const mxArray *c10_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int8_T c10_f_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int8_T c10_y;
  int8_T c10_i309;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i309, 1, 2, 0U, 0, 0U, 0);
  c10_y = c10_i309;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_secs;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int8_T c10_y;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_secs = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_secs),
    &c10_thisId);
  sf_mex_destroy(&c10_secs);
  *(int8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_g_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i310;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i310, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i310;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  uint8_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(uint8_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static uint8_T c10_h_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_tp_stateInitial, const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_stateInitial),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_stateInitial);
  return c10_y;
}

static uint8_T c10_i_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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

static void c10_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_tp_stateInitial;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  uint8_T c10_y;
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c10_b_tp_stateInitial = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_tp_stateInitial),
    &c10_thisId);
  sf_mex_destroy(&c10_b_tp_stateInitial);
  *(uint8_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint32_T c10_j_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_method, const char_T *c10_identifier)
{
  uint32_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_method),
    &c10_thisId);
  sf_mex_destroy(&c10_b_method);
  return c10_y;
}

static uint32_T c10_k_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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

static uint32_T c10_l_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier)
{
  uint32_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_d_state),
    &c10_thisId);
  sf_mex_destroy(&c10_d_state);
  return c10_y;
}

static uint32_T c10_m_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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

static void c10_n_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[625])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_d_state), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_d_state);
}

static void c10_o_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[625])
{
  uint32_T c10_uv3[625];
  int32_T c10_i311;
  if (mxIsEmpty(c10_u)) {
    chartInstance->c10_c_state_not_empty = false;
  } else {
    chartInstance->c10_c_state_not_empty = true;
    sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_uv3, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c10_i311 = 0; c10_i311 < 625; c10_i311++) {
      c10_y[c10_i311] = c10_uv3[c10_i311];
    }
  }

  sf_mex_destroy(&c10_u);
}

static void c10_p_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_d_state, const char_T *c10_identifier, uint32_T c10_y[2])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_d_state), &c10_thisId,
    c10_y);
  sf_mex_destroy(&c10_d_state);
}

static void c10_q_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId, uint32_T c10_y[2])
{
  uint32_T c10_uv4[2];
  int32_T c10_i312;
  if (mxIsEmpty(c10_u)) {
    chartInstance->c10_b_state_not_empty = false;
  } else {
    chartInstance->c10_b_state_not_empty = true;
    sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_uv4, 1, 7, 0U, 1, 0U, 1,
                  2);
    for (c10_i312 = 0; c10_i312 < 2; c10_i312++) {
      c10_y[c10_i312] = c10_uv4[c10_i312];
    }
  }

  sf_mex_destroy(&c10_u);
}

static uint32_T c10_r_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_temporalCounter_i1, const char_T *c10_identifier)
{
  uint32_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_temporalCounter_i1), &c10_thisId);
  sf_mex_destroy(&c10_b_temporalCounter_i1);
  return c10_y;
}

static uint32_T c10_s_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint32_T c10_y;
  uint32_T c10_u6;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u6, 1, 7, 0U, 0, 0U, 0);
  c10_y = c10_u6;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static const mxArray *c10_t_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
   c10_b_setSimStateSideEffectsInfo, const char_T *c10_identifier)
{
  const mxArray *c10_y = NULL;
  emlrtMsgIdentifier c10_thisId;
  c10_y = NULL;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  sf_mex_assign(&c10_y, c10_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_setSimStateSideEffectsInfo), &c10_thisId), false);
  sf_mex_destroy(&c10_b_setSimStateSideEffectsInfo);
  return c10_y;
}

static const mxArray *c10_u_emlrt_marshallIn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray *
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
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex)
{
  (void)chartInstance;
  c10_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c10_vectorIndex, 0, 1, 1, 0)] = true;
}

static void c10_errorIfDataNotWrittenToFcn
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_vectorIndex, uint32_T c10_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c10_dataNumber, c10_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c10_vectorIndex, 0, 1, 1,
    0)]);
}

static void c10_b_twister_state_vector
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_mt[625], real_T c10_seed)
{
  real_T c10_d5;
  uint32_T c10_u7;
  uint32_T c10_r;
  int32_T c10_mti;
  real_T c10_b_mti;
  real_T c10_d6;
  uint32_T c10_u8;
  (void)chartInstance;
  c10_d5 = c10_seed;
  if (c10_d5 < 4.294967296E+9) {
    if (c10_d5 >= 0.0) {
      c10_u7 = (uint32_T)c10_d5;
    } else {
      c10_u7 = 0U;
    }
  } else if (c10_d5 >= 4.294967296E+9) {
    c10_u7 = MAX_uint32_T;
  } else {
    c10_u7 = 0U;
  }

  c10_r = c10_u7;
  c10_mt[0] = c10_r;
  for (c10_mti = 0; c10_mti < 623; c10_mti++) {
    c10_b_mti = 2.0 + (real_T)c10_mti;
    c10_d6 = muDoubleScalarRound(c10_b_mti - 1.0);
    if (c10_d6 < 4.294967296E+9) {
      if (c10_d6 >= 0.0) {
        c10_u8 = (uint32_T)c10_d6;
      } else {
        c10_u8 = 0U;
      }
    } else if (c10_d6 >= 4.294967296E+9) {
      c10_u8 = MAX_uint32_T;
    } else {
      c10_u8 = 0U;
    }

    c10_r = (c10_r ^ c10_r >> 30U) * 1812433253U + c10_u8;
    c10_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c10_b_mti), 1, 625, 1, 0) - 1] = c10_r;
  }

  c10_mt[624] = 624U;
}

static real_T c10_c_eml_rand_mt19937ar
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c10_d_state[625])
{
  int32_T c10_i313;
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
    for (c10_i313 = 0; c10_i313 < 2; c10_i313++) {
      c10_u[c10_i313] = 0U;
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

static real_T c10_get_BOREDOMT(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#853) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_BOREDOMT_address;
}

static void c10_set_BOREDOMT(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#853) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_BOREDOMT_address = c10_c;
}

static real_T *c10_access_BOREDOMT
  (SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c10_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#853) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_BOREDOMT_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c10_c;
}

static real_T c10_get_b(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c10_b);
  if (chartInstance->c10_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#857) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_b_address;
}

static void c10_set_b(SFc10_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c10_b);
  if (chartInstance->c10_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#857) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_b_address = c10_c;
}

static real_T *c10_access_b(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c10_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#857) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_b_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c10_c;
}

static real_T c10_get_bored(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c10_b);
  if (chartInstance->c10_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#852) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_bored_address;
}

static void c10_set_bored(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c10_b);
  if (chartInstance->c10_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#852) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_bored_address = c10_c;
}

static real_T *c10_access_bored(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c10_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#852) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_bored_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c10_c;
}

static real_T c10_get_pose(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c10_b);
  if (chartInstance->c10_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#856) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_pose_address;
}

static void c10_set_pose(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c10_b);
  if (chartInstance->c10_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#856) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_pose_address = c10_c;
}

static real_T *c10_access_pose(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c10_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#856) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_pose_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c10_c;
}

static real_T c10_get_randomD(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c10_b);
  if (chartInstance->c10_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#858) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_randomD_address;
}

static void c10_set_randomD(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c10_b);
  if (chartInstance->c10_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#858) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_randomD_address = c10_c;
}

static real_T *c10_access_randomD(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c10_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#858) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_randomD_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c10_c;
}

static real_T c10_get_randomG(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c10_b);
  if (chartInstance->c10_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#854) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_randomG_address;
}

static void c10_set_randomG(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c10_b);
  if (chartInstance->c10_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#854) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_randomG_address = c10_c;
}

static real_T *c10_access_randomG(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c10_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#854) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_randomG_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c10_c;
}

static real_T c10_get_randomP(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c10_b);
  if (chartInstance->c10_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#855) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_randomP_address;
}

static void c10_set_randomP(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b, real_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c10_b);
  if (chartInstance->c10_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#855) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_randomP_address = c10_c;
}

static real_T *c10_access_randomP(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  real_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c10_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#855) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_randomP_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c10_c;
}

static void init_dsm_address_info(SFc10_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c10_BOREDOMT_address, &chartInstance->c10_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "b", (void **)
    &chartInstance->c10_b_address, &chartInstance->c10_b_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c10_bored_address, &chartInstance->c10_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c10_pose_address, &chartInstance->c10_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomD", (void **)
    &chartInstance->c10_randomD_address, &chartInstance->c10_randomD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomG", (void **)
    &chartInstance->c10_randomG_address, &chartInstance->c10_randomG_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c10_randomP_address, &chartInstance->c10_randomP_index);
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

void sf_c10_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3414929206U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1086961356U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2497200467U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2669623520U);
}

mxArray *sf_c10_lib_affectiveChar_scenario_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Bx12PIEuChnz6poBVrH7HB");
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

mxArray *sf_c10_lib_affectiveChar_scenario_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_lib_affectiveChar_scenario_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_lib_affectiveChar_scenario(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c10_lib_affectiveChar_scenario\",},{M[9],M[0],T\"is_c10_lib_affectiveChar_scenario\",},{M[11],M[23],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x3[13 14 15],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_lib_affectiveChar_scenario_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_scenarioMachineNumber_,
           10,
           7,
           9,
           0,
           12,
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
          _SFD_SET_DATA_PROPS(2,11,0,0,"randomG");
          _SFD_SET_DATA_PROPS(3,11,0,0,"randomP");
          _SFD_SET_DATA_PROPS(4,11,0,0,"pose");
          _SFD_SET_DATA_PROPS(5,11,0,0,"b");
          _SFD_SET_DATA_PROPS(6,11,0,0,"randomD");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,9,0,0,"");
          _SFD_SET_DATA_PROPS(10,8,0,0,"");
          _SFD_SET_DATA_PROPS(11,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,3);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_CH_SUBSTATE_INDEX(3,6);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

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
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
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

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"idlePosec10_lib_affectiveChar_scenario",0,-1,
                             1393);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",1393,-1,1609);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1609,-1,1840);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1840,-1,1975);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1975,-1,2266);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",2266,-1,2558);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",2558,-1,2852);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",2852,-1,3147);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",3147,-1,3311);
        _SFD_CV_INIT_EML_IF(1,1,0,827,857,888,1391);
        _SFD_CV_INIT_EML_IF(1,1,1,888,922,953,1391);
        _SFD_CV_INIT_EML_IF(1,1,2,953,987,1018,1391);
        _SFD_CV_INIT_EML_IF(1,1,3,1018,1052,1083,1391);
        _SFD_CV_INIT_EML_IF(1,1,4,1083,1117,1148,1391);
        _SFD_CV_INIT_EML_IF(1,1,5,1148,1182,1213,1391);
        _SFD_CV_INIT_EML_IF(1,1,6,1213,1247,1278,1391);
        _SFD_CV_INIT_EML_IF(1,1,7,1278,1312,1343,1391);
        _SFD_CV_INIT_EML(0,1,27,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredGazec10_lib_affectiveChar_scenario",0,-1,
                             2900);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",2900,-1,3086);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",3086,-1,3274);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3274,-1,3456);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",3456,-1,3642);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",3642,-1,3832);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",3832,-1,4024);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",4024,-1,4218);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",4218,-1,4414);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",4414,-1,4614);
        _SFD_CV_INIT_EML_FCN(0,10,"aFcnTruthTableAction_10",4614,-1,4823);
        _SFD_CV_INIT_EML_FCN(0,11,"aFcnTruthTableAction_11",4823,-1,5034);
        _SFD_CV_INIT_EML_FCN(0,12,"aFcnTruthTableAction_12",5034,-1,5241);
        _SFD_CV_INIT_EML_FCN(0,13,"aFcnTruthTableAction_13",5241,-1,5446);
        _SFD_CV_INIT_EML_FCN(0,14,"aFcnTruthTableAction_14",5446,-1,5643);
        _SFD_CV_INIT_EML_FCN(0,15,"aFcnTruthTableAction_15",5643,-1,5846);
        _SFD_CV_INIT_EML_FCN(0,16,"aFcnTruthTableAction_16",5846,-1,6047);
        _SFD_CV_INIT_EML_FCN(0,17,"aFcnTruthTableAction_17",6047,-1,6260);
        _SFD_CV_INIT_EML_FCN(0,18,"aFcnTruthTableAction_18",6260,-1,6475);
        _SFD_CV_INIT_EML_FCN(0,19,"aFcnTruthTableAction_19",6475,-1,6689);
        _SFD_CV_INIT_EML_FCN(0,20,"aFcnTruthTableAction_20",6689,-1,6902);
        _SFD_CV_INIT_EML_FCN(0,21,"aFcnTruthTableAction_21",6902,-1,7119);
        _SFD_CV_INIT_EML_FCN(0,22,"aFcnTruthTableAction_22",7119,-1,7338);
        _SFD_CV_INIT_EML_FCN(0,23,"aFcnTruthTableAction_23",7338,-1,7559);
        _SFD_CV_INIT_EML_FCN(0,24,"aFcnTruthTableAction_24",7559,-1,7782);
        _SFD_CV_INIT_EML_FCN(0,25,"aFcnTruthTableAction_25",7782,-1,7948);
        _SFD_CV_INIT_EML_FCN(0,26,"aFcnTruthTableAction_26",7948,-1,8245);
        _SFD_CV_INIT_EML_IF(0,1,0,1666,1696,1727,2898);
        _SFD_CV_INIT_EML_IF(0,1,1,1727,1761,1792,2898);
        _SFD_CV_INIT_EML_IF(0,1,2,1792,1826,1857,2898);
        _SFD_CV_INIT_EML_IF(0,1,3,1857,1891,1922,2898);
        _SFD_CV_INIT_EML_IF(0,1,4,1922,1956,1987,2898);
        _SFD_CV_INIT_EML_IF(0,1,5,1987,2021,2052,2898);
        _SFD_CV_INIT_EML_IF(0,1,6,2052,2086,2117,2898);
        _SFD_CV_INIT_EML_IF(0,1,7,2117,2151,2182,2898);
        _SFD_CV_INIT_EML_IF(0,1,8,2182,2216,2247,2898);
        _SFD_CV_INIT_EML_IF(0,1,9,2247,2282,2314,2898);
        _SFD_CV_INIT_EML_IF(0,1,10,2314,2349,2381,2898);
        _SFD_CV_INIT_EML_IF(0,1,11,2381,2416,2448,2898);
        _SFD_CV_INIT_EML_IF(0,1,12,2448,2483,2515,2898);
        _SFD_CV_INIT_EML_IF(0,1,13,2515,2550,2582,2898);
        _SFD_CV_INIT_EML_IF(0,1,14,2582,2617,2649,2898);
        _SFD_CV_INIT_EML_IF(0,1,15,2649,2684,2716,2898);
        _SFD_CV_INIT_EML_IF(0,1,16,2716,2751,2783,2898);
        _SFD_CV_INIT_EML_IF(0,1,17,2783,2818,2850,2898);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,19,0,19);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,28,1,28);

        {
          static int condStart[] = { 2, 16 };

          static int condEnd[] = { 13, 27 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,28,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,27,1,27);

        {
          static int condStart[] = { 2, 17 };

          static int condEnd[] = { 14, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,27,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,26,1,26);

        {
          static int condStart[] = { 2, 16 };

          static int condEnd[] = { 13, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,13,0,13);
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
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
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

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,1,(MexFcnForType)c10_q_sf_marshallOut,(MexInFcnForType)
            c10_e_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_bored_address);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c10_BOREDOMT_address);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_randomG_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c10_randomP_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c10_pose_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c10_b_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c10_randomD_address);
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
  return "UyUB6lIfekhfRrLBmMg5wE";
}

static void sf_opaque_initialize_c10_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_lib_affectiveChar_scenarioInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
  initialize_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  enable_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  disable_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  sf_gateway_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_lib_affectiveChar_scenario
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_lib_affectiveChar_scenario();/* state var info */
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

extern void sf_internal_set_sim_state_c10_lib_affectiveChar_scenario(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c10_lib_affectiveChar_scenario();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_lib_affectiveChar_scenario
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c10_lib_affectiveChar_scenario(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c10_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_lib_affectiveChar_scenarioInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_scenario_optimization_info();
    }

    finalize_c10_lib_affectiveChar_scenario
      ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_lib_affectiveChar_scenario
    ((SFc10_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_lib_affectiveChar_scenario(SimStruct *S)
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
    initialize_params_c10_lib_affectiveChar_scenario
      ((SFc10_lib_affectiveChar_scenarioInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_scenario_optimization_info();
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
  ssSetChecksum0(S,(1525025175U));
  ssSetChecksum1(S,(1009836814U));
  ssSetChecksum2(S,(2742995200U));
  ssSetChecksum3(S,(3692906626U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c10_lib_affectiveChar_scenario(SimStruct *S)
{
  SFc10_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_lib_affectiveChar_scenarioInstanceStruct *)utMalloc
    (sizeof(SFc10_lib_affectiveChar_scenarioInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_lib_affectiveChar_scenarioInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_lib_affectiveChar_scenario;
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

void c10_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_lib_affectiveChar_scenario(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_lib_affectiveChar_scenario_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
