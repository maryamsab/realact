/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_behavior_sfun.h"
#include "c9_lib_affectiveChar_behavior.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_behavior_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c9_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_stateAvertGaze           ((uint8_T)1U)
#define c9_IN_stateAvertHead           ((uint8_T)2U)
#define c9_IN_stateHeadNeutral         ((uint8_T)3U)
#define c9_IN_stateInitial             ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c9_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_t_debug_family_names[11] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7", "nargin", "nargout",
  "bmlID", "gazeBML" };

static const char * c9_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c9_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initialize_params_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void enable_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void disable_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void set_sim_state_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_st);
static void c9_set_sim_state_side_effects_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void finalize_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void sf_gateway_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_enter_atomic_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_enter_internal_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_exit_internal_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_initc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void initSimStructsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_enter_atomic_stateInitial
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_stateInitial(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c9_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_b_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_c_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_d_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_e_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_f_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_g_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_h_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_i_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_j_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_k_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_l_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_m_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_n_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_o_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_p_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_q_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_r_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_s_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_t_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_u_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_v_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_w_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_x_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static real_T c9_rand(SFc9_lib_affectiveChar_behaviorInstanceStruct
                      *chartInstance);
static real_T c9_eml_rand(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c9_eml_rand_mt19937ar(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_d_state[625]);
static void c9_twister_state_vector
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed, uint32_T c9_b_mt[625]);
static void c9_b_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c9_d_state[625], uint32_T c9_e_state[625], real_T *c9_r);
static void c9_eml_error(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_b_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_c_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static void c9_activate_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_deactivate_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_increment_counters_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_reset_counters_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance);
static void c9_sendBMLc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c9_arg
   [256]);
static void c9_idleGazeTablec9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_gazeBML[256]);
static void c9_idleGazeInterestedTablec9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_gazeBML[256]);
static void c9_sendBML(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static void c9_b_sendBML(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance);
static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int8_T c9_e_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_f_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_g_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_tp_stateInitial, const char_T *c9_identifier);
static uint8_T c9_h_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint32_T c9_i_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_method, const char_T *c9_identifier);
static uint32_T c9_j_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static uint32_T c9_k_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_d_state, const char_T *c9_identifier);
static uint32_T c9_l_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_m_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[625]);
static void c9_n_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[625]);
static void c9_o_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[2]);
static void c9_p_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[2]);
static uint32_T c9_q_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_temporalCounter_i1, const char_T *c9_identifier);
static uint32_T c9_r_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static const mxArray *c9_s_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_setSimStateSideEffectsInfo, const char_T *c9_identifier);
static const mxArray *c9_t_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c9_vectorIndex);
static void c9_b_twister_state_vector
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed);
static real_T c9_c_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c9_d_state[625]);
static real_T c9_get_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static void c9_set_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c);
static real_T *c9_access_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static real_T c9_get_boredom(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_boredom(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_boredom(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_interest(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_interest(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_interest(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_b);
static real_T c9_get_isPosing(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_isPosing(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_isPosing(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_b);
static real_T c9_get_randAvertGazeChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static void c9_set_randAvertGazeChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c);
static real_T *c9_access_randAvertGazeChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static real_T c9_get_randGazeDur(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_randGazeDur(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randGazeDur
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static real_T c9_get_randPoseChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static void c9_set_randPoseChance(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randPoseChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b);
static void init_dsm_address_info(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_debugger_state_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_lib_affectiveChar_behavior == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_behavior == c9_IN_stateInitial)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_behavior ==
      c9_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_behavior == c9_IN_stateAvertGaze)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_behavior == c9_IN_stateAvertHead)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  uint32_T c9_hoistedGlobal;
  uint32_T c9_u;
  const mxArray *c9_b_y = NULL;
  uint32_T c9_b_hoistedGlobal;
  uint32_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  int32_T c9_i0;
  uint32_T c9_c_u[625];
  const mxArray *c9_d_y = NULL;
  int32_T c9_i1;
  uint32_T c9_d_u[2];
  const mxArray *c9_e_y = NULL;
  uint8_T c9_c_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  uint8_T c9_d_hoistedGlobal;
  uint8_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  uint32_T c9_e_hoistedGlobal;
  uint32_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(7, 1), false);
  c9_hoistedGlobal = chartInstance->c9_method;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  if (!chartInstance->c9_method_not_empty) {
    sf_mex_assign(&c9_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = chartInstance->c9_state;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  if (!chartInstance->c9_state_not_empty) {
    sf_mex_assign(&c9_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 1, c9_c_y);
  for (c9_i0 = 0; c9_i0 < 625; c9_i0++) {
    c9_c_u[c9_i0] = chartInstance->c9_c_state[c9_i0];
  }

  c9_d_y = NULL;
  if (!chartInstance->c9_c_state_not_empty) {
    sf_mex_assign(&c9_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_c_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c9_y, 2, c9_d_y);
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_d_u[c9_i1] = chartInstance->c9_b_state[c9_i1];
  }

  c9_e_y = NULL;
  if (!chartInstance->c9_b_state_not_empty) {
    sf_mex_assign(&c9_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_d_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_c_hoistedGlobal = chartInstance->c9_is_active_c9_lib_affectiveChar_behavior;
  c9_e_u = c9_c_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_d_hoistedGlobal = chartInstance->c9_is_c9_lib_affectiveChar_behavior;
  c9_f_u = c9_d_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_e_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
  c9_g_u = c9_e_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  uint32_T c9_uv0[625];
  int32_T c9_i2;
  uint32_T c9_uv1[2];
  int32_T c9_i3;
  c9_u = sf_mex_dup(c9_st);
  chartInstance->c9_method = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 0)), "method");
  chartInstance->c9_state = c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 1)), "state");
  c9_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
                        "state", c9_uv0);
  for (c9_i2 = 0; c9_i2 < 625; c9_i2++) {
    chartInstance->c9_c_state[c9_i2] = c9_uv0[c9_i2];
  }

  c9_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
                        "state", c9_uv1);
  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    chartInstance->c9_b_state[c9_i3] = c9_uv1[c9_i3];
  }

  chartInstance->c9_is_active_c9_lib_affectiveChar_behavior =
    c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 4)),
    "is_active_c9_lib_affectiveChar_behavior");
  chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 5)),
     "is_c9_lib_affectiveChar_behavior");
  chartInstance->c9_temporalCounter_i1 = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_lib_affectiveChar_behavior(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_c9_lib_affectiveChar_behavior ==
        c9_IN_stateAvertGaze) {
      chartInstance->c9_tp_stateAvertGaze = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertGaze = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_behavior ==
        c9_IN_stateAvertHead) {
      chartInstance->c9_tp_stateAvertHead = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertHead = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_behavior ==
        c9_IN_stateHeadNeutral) {
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_behavior == c9_IN_stateInitial)
    {
      chartInstance->c9_tp_stateInitial = 1U;
    } else {
      chartInstance->c9_tp_stateInitial = 0U;
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  c9_set_sim_state_side_effects_c9_lib_affectiveChar_behavior(chartInstance);
}

static void c9_enter_atomic_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  chartInstance->c9_is_active_c9_lib_affectiveChar_behavior = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
}

static void c9_enter_internal_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateInitial = 1U;
  c9_enter_atomic_stateInitial(chartInstance);
}

static void c9_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  boolean_T c9_temp;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_dv0[256];
  int32_T c9_i4;
  real_T c9_arg[256];
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_c_out;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_isStable = true;
  switch (chartInstance->c9_is_c9_lib_affectiveChar_behavior) {
   case c9_IN_stateAvertGaze:
    CV_CHART_EVAL(1, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_kb_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_temp) {
      c9_temp = (chartInstance->c9_temporalCounter_i1 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c9_get_randGazeDur
                  (chartInstance, 0), 32U, 2U));
    }

    c9_out = CV_EML_IF(2, 0, 0, c9_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateAvertGaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateInitial = 1U;
      c9_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHead:
    CV_CHART_EVAL(1, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_nb_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(8, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 3U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateAvertHead = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_behavior =
        c9_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_eb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_lib_affectiveChar_behavior(chartInstance, 17.0, c9_dv0);
      for (c9_i4 = 0; c9_i4 < 256; c9_i4++) {
        c9_arg[c9_i4] = c9_dv0[c9_i4];
      }

      for (c9_i5 = 0; c9_i5 < 256; c9_i5++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i5], 7U);
      }

      _SFD_SET_DATA_VALUE_PTR(7U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c9_sfEvent);
      for (c9_i6 = 0; c9_i6 < 256; c9_i6++) {
        (*c9_b_arg)[c9_i6] = c9_arg[c9_i6];
      }

      for (c9_i7 = 0; c9_i7 < 256; c9_i7++) {
        _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i7], 7U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateHeadNeutral:
    CV_CHART_EVAL(1, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_hb_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_c_out = CV_EML_IF(1, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateInitial = 1U;
      c9_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInitial:
    CV_CHART_EVAL(1, 0, 4);
    c9_stateInitial(chartInstance);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
}

static void c9_exit_internal_c9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  switch (chartInstance->c9_is_c9_lib_affectiveChar_behavior) {
   case c9_IN_stateAvertGaze:
    CV_CHART_EVAL(1, 0, 1);
    chartInstance->c9_tp_stateAvertGaze = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHead:
    CV_CHART_EVAL(1, 0, 2);
    chartInstance->c9_tp_stateAvertHead = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateHeadNeutral:
    CV_CHART_EVAL(1, 0, 3);
    chartInstance->c9_tp_stateHeadNeutral = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInitial:
    CV_CHART_EVAL(1, 0, 4);
    chartInstance->c9_tp_stateInitial = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_CHART_EVAL(1, 0, 0);
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    break;
  }
}

static void c9_initc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_method_not_empty = false;
  chartInstance->c9_state_not_empty = false;
  chartInstance->c9_b_state_not_empty = false;
  chartInstance->c9_c_state_not_empty = false;
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  chartInstance->c9_tp_stateAvertGaze = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateAvertHead = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateHeadNeutral = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateInitial = 0U;
  chartInstance->c9_is_active_c9_lib_affectiveChar_behavior = 0U;
  chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_enter_atomic_stateInitial
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_b_r;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_hoistedGlobal;
  real_T c9_lowhigh[2];
  real_T c9_low;
  real_T c9_high;
  int32_T c9_i8;
  static char_T c9_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c9_u[26];
  const mxArray *c9_y = NULL;
  real_T c9_s;
  real_T c9_c_r;
  real_T c9_e_x;
  real_T c9_f_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_cb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_r = c9_rand(chartInstance);
  c9_x = c9_r * 10.0;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarFloor(c9_b_x);
  c9_r = 1.0 + c9_b_x;
  c9_set_randAvertGazeChance(chartInstance, 0, c9_r);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c9_b_r = c9_rand(chartInstance);
  c9_c_x = c9_b_r * 4.0;
  c9_d_x = c9_c_x;
  c9_d_x = muDoubleScalarFloor(c9_d_x);
  c9_b_r = 1.0 + c9_d_x;
  c9_set_randGazeDur(chartInstance, 0, c9_b_r);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c9_set_interest(chartInstance, 0, c9_get_BOREDOM_THRESHOLD(chartInstance, 0) -
                  c9_get_boredom(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 2);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_db_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_hoistedGlobal = c9_get_interest(chartInstance, 0);
  c9_lowhigh[0] = 1.0;
  c9_lowhigh[1] = c9_hoistedGlobal;
  c9_low = c9_lowhigh[0];
  c9_high = c9_lowhigh[1];
  if (c9_low <= c9_high) {
  } else {
    for (c9_i8 = 0; c9_i8 < 26; c9_i8++) {
      c9_u[c9_i8] = c9_cv0[c9_i8];
    }

    c9_y = NULL;
    sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c9_y));
  }

  c9_s = (c9_high - c9_low) + 1.0;
  c9_c_r = c9_rand(chartInstance);
  c9_e_x = c9_c_r * c9_s;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarFloor(c9_f_x);
  c9_c_r = c9_low + c9_f_x;
  c9_set_randPoseChance(chartInstance, 0, c9_c_r);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateInitial(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_dv1[256];
  int32_T c9_i9;
  real_T c9_arg[256];
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  real_T c9_b_r;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_dv2[256];
  int32_T c9_i13;
  real_T c9_b_arg[256];
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_d_out;
  real_T (*c9_c_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c9_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ib_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(4, 0, 0, c9_get_isPosing(chartInstance, 0) != 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_stateInitial;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateInitial = 1U;
    c9_enter_atomic_stateInitial(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_mb_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(7, 0, 0, c9_get_randAvertGazeChance(chartInstance, 0) > 3.0))
    {
      if (CV_EML_COND(7, 0, 1, c9_get_isPosing(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(7, 0, 0, true);
        CV_EML_IF(7, 0, 0, true);
        c9_b_out = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c9_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_behavior = c9_IN_stateAvertGaze;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateAvertGaze = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_fb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_r = c9_rand(chartInstance);
      c9_x = c9_r * 7.0;
      c9_b_x = c9_x;
      c9_b_x = muDoubleScalarFloor(c9_b_x);
      c9_r = 1.0 + c9_b_x;
      c9_idleGazeInterestedTablec9_lib_affectiveChar_behavior(chartInstance,
        c9_r, c9_dv1);
      for (c9_i9 = 0; c9_i9 < 256; c9_i9++) {
        c9_arg[c9_i9] = c9_dv1[c9_i9];
      }

      for (c9_i10 = 0; c9_i10 < 256; c9_i10++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i10], 7U);
      }

      _SFD_SET_DATA_VALUE_PTR(7U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c9_sfEvent);
      for (c9_i11 = 0; c9_i11 < 256; c9_i11++) {
        (*c9_c_arg)[c9_i11] = c9_arg[c9_i11];
      }

      for (c9_i12 = 0; c9_i12 < 256; c9_i12++) {
        _SFD_DATA_RANGE_CHECK((*c9_c_arg)[c9_i12], 7U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_lb_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(6, 0, 0, c9_get_randPoseChance(chartInstance, 0) == 1.0))
      {
        if (CV_EML_COND(6, 0, 1, c9_get_isPosing(chartInstance, 0) == 0.0)) {
          CV_EML_MCDC(6, 0, 0, true);
          CV_EML_IF(6, 0, 0, true);
          c9_c_out = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(6, 0, 0, false);
        CV_EML_IF(6, 0, 0, false);
        c9_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateInitial = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_c9_lib_affectiveChar_behavior =
          c9_IN_stateAvertHead;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_stateAvertHead = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_gb_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        c9_b_r = c9_rand(chartInstance);
        c9_c_x = c9_b_r * 8.0;
        c9_d_x = c9_c_x;
        c9_d_x = muDoubleScalarFloor(c9_d_x);
        c9_b_r = 1.0 + c9_d_x;
        c9_idleGazeTablec9_lib_affectiveChar_behavior(chartInstance, c9_b_r,
          c9_dv2);
        for (c9_i13 = 0; c9_i13 < 256; c9_i13++) {
          c9_b_arg[c9_i13] = c9_dv2[c9_i13];
        }

        for (c9_i14 = 0; c9_i14 < 256; c9_i14++) {
          _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i14], 7U);
        }

        _SFD_SET_DATA_VALUE_PTR(7U, c9_b_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c9_sfEvent);
        for (c9_i15 = 0; c9_i15 < 256; c9_i15++) {
          (*c9_c_arg)[c9_i15] = c9_b_arg[c9_i15];
        }

        for (c9_i16 = 0; c9_i16 < 256; c9_i16++) {
          _SFD_DATA_RANGE_CHECK((*c9_c_arg)[c9_i16], 7U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(7U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_jb_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(5, 0, 0, 0.0 < c9_get_randAvertGazeChance(chartInstance,
              0))) {
          if (CV_EML_COND(5, 0, 1, c9_get_randAvertGazeChance(chartInstance, 0) <
                          4.0)) {
            CV_EML_MCDC(5, 0, 0, true);
            CV_EML_IF(5, 0, 0, true);
            c9_d_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(5, 0, 0, false);
          CV_EML_IF(5, 0, 0, false);
          c9_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c9_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateInitial = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
          chartInstance->c9_isStable = false;
          chartInstance->c9_is_c9_lib_affectiveChar_behavior =
            c9_IN_stateInitial;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateInitial = 1U;
          c9_enter_atomic_stateInitial(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       chartInstance->c9_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
}

static void c9_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[118];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[118];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i17;
  static char_T c9_cv1[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i18;
  static real_T c9_dv3[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i19;
  int32_T c9_i20;
  int32_T c9_i21;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_b_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i17 = 0; c9_i17 < 118; c9_i17++) {
    c9_mystr[c9_i17] = c9_cv1[c9_i17];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i18 = 0; c9_i18 < 118; c9_i18++) {
    c9_arr[c9_i18] = c9_dv3[c9_i18];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i19 = 0; c9_i19 < 256; c9_i19++) {
    c9_tt[c9_i19] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i20 = 0; c9_i20 < 118; c9_i20++) {
    c9_tt[c9_i20] = c9_arr[c9_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i21 = 0; c9_i21 < 256; c9_i21++) {
    c9_myarr256[c9_i21] = c9_tt[c9_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_b_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[119];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[119];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i22;
  static char_T c9_cv2[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i23;
  static real_T c9_dv4[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_c_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i22 = 0; c9_i22 < 119; c9_i22++) {
    c9_mystr[c9_i22] = c9_cv2[c9_i22];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i23 = 0; c9_i23 < 119; c9_i23++) {
    c9_arr[c9_i23] = c9_dv4[c9_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i24 = 0; c9_i24 < 256; c9_i24++) {
    c9_tt[c9_i24] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i25 = 0; c9_i25 < 119; c9_i25++) {
    c9_tt[c9_i25] = c9_arr[c9_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i26 = 0; c9_i26 < 256; c9_i26++) {
    c9_myarr256[c9_i26] = c9_tt[c9_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_c_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[116];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[116];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i27;
  static char_T c9_cv3[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r',
    'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i28;
  static real_T c9_dv5[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_d_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i27 = 0; c9_i27 < 116; c9_i27++) {
    c9_mystr[c9_i27] = c9_cv3[c9_i27];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i28 = 0; c9_i28 < 116; c9_i28++) {
    c9_arr[c9_i28] = c9_dv5[c9_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i29 = 0; c9_i29 < 256; c9_i29++) {
    c9_tt[c9_i29] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i30 = 0; c9_i30 < 116; c9_i30++) {
    c9_tt[c9_i30] = c9_arr[c9_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i31 = 0; c9_i31 < 256; c9_i31++) {
    c9_myarr256[c9_i31] = c9_tt[c9_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_d_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[118];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[118];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i32;
  static char_T c9_cv4[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i33;
  static real_T c9_dv6[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_e_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i32 = 0; c9_i32 < 118; c9_i32++) {
    c9_mystr[c9_i32] = c9_cv4[c9_i32];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i33 = 0; c9_i33 < 118; c9_i33++) {
    c9_arr[c9_i33] = c9_dv6[c9_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i34 = 0; c9_i34 < 256; c9_i34++) {
    c9_tt[c9_i34] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i35 = 0; c9_i35 < 118; c9_i35++) {
    c9_tt[c9_i35] = c9_arr[c9_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i36 = 0; c9_i36 < 256; c9_i36++) {
    c9_myarr256[c9_i36] = c9_tt[c9_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_e_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[120];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[120];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i37;
  static char_T c9_cv5[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i38;
  static real_T c9_dv7[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i39;
  int32_T c9_i40;
  int32_T c9_i41;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_f_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i37 = 0; c9_i37 < 120; c9_i37++) {
    c9_mystr[c9_i37] = c9_cv5[c9_i37];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i38 = 0; c9_i38 < 120; c9_i38++) {
    c9_arr[c9_i38] = c9_dv7[c9_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i39 = 0; c9_i39 < 256; c9_i39++) {
    c9_tt[c9_i39] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i40 = 0; c9_i40 < 120; c9_i40++) {
    c9_tt[c9_i40] = c9_arr[c9_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i41 = 0; c9_i41 < 256; c9_i41++) {
    c9_myarr256[c9_i41] = c9_tt[c9_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_f_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[121];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[121];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i42;
  static char_T c9_cv6[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i43;
  static real_T c9_dv8[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i44;
  int32_T c9_i45;
  int32_T c9_i46;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_g_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i42 = 0; c9_i42 < 121; c9_i42++) {
    c9_mystr[c9_i42] = c9_cv6[c9_i42];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i43 = 0; c9_i43 < 121; c9_i43++) {
    c9_arr[c9_i43] = c9_dv8[c9_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i44 = 0; c9_i44 < 256; c9_i44++) {
    c9_tt[c9_i44] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i45 = 0; c9_i45 < 121; c9_i45++) {
    c9_tt[c9_i45] = c9_arr[c9_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i46 = 0; c9_i46 < 256; c9_i46++) {
    c9_myarr256[c9_i46] = c9_tt[c9_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_g_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[122];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[122];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i47;
  static char_T c9_cv7[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i48;
  static real_T c9_dv9[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i49;
  int32_T c9_i50;
  int32_T c9_i51;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_h_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i47 = 0; c9_i47 < 122; c9_i47++) {
    c9_mystr[c9_i47] = c9_cv7[c9_i47];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i48 = 0; c9_i48 < 122; c9_i48++) {
    c9_arr[c9_i48] = c9_dv9[c9_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i49 = 0; c9_i49 < 256; c9_i49++) {
    c9_tt[c9_i49] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i50 = 0; c9_i50 < 122; c9_i50++) {
    c9_tt[c9_i50] = c9_arr[c9_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i51 = 0; c9_i51 < 256; c9_i51++) {
    c9_myarr256[c9_i51] = c9_tt[c9_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_h_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[123];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[123];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i52;
  static char_T c9_cv8[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i53;
  static real_T c9_dv10[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i54;
  int32_T c9_i55;
  int32_T c9_i56;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_i_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i52 = 0; c9_i52 < 123; c9_i52++) {
    c9_mystr[c9_i52] = c9_cv8[c9_i52];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i53 = 0; c9_i53 < 123; c9_i53++) {
    c9_arr[c9_i53] = c9_dv10[c9_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i54 = 0; c9_i54 < 256; c9_i54++) {
    c9_tt[c9_i54] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i55 = 0; c9_i55 < 123; c9_i55++) {
    c9_tt[c9_i55] = c9_arr[c9_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i56 = 0; c9_i56 < 256; c9_i56++) {
    c9_myarr256[c9_i56] = c9_tt[c9_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_i_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[133];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[133];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i57;
  static char_T c9_cv9[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd', 'i',
    'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.',
    '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i58;
  static real_T c9_dv11[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i59;
  int32_T c9_i60;
  int32_T c9_i61;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_j_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i57 = 0; c9_i57 < 133; c9_i57++) {
    c9_mystr[c9_i57] = c9_cv9[c9_i57];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i58 = 0; c9_i58 < 133; c9_i58++) {
    c9_arr[c9_i58] = c9_dv11[c9_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i59 = 0; c9_i59 < 256; c9_i59++) {
    c9_tt[c9_i59] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i60 = 0; c9_i60 < 133; c9_i60++) {
    c9_tt[c9_i60] = c9_arr[c9_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i61 = 0; c9_i61 < 256; c9_i61++) {
    c9_myarr256[c9_i61] = c9_tt[c9_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_j_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[137];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[137];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i62;
  static char_T c9_cv10[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i63;
  static real_T c9_dv12[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i64;
  int32_T c9_i65;
  int32_T c9_i66;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_k_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i62 = 0; c9_i62 < 137; c9_i62++) {
    c9_mystr[c9_i62] = c9_cv10[c9_i62];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i63 = 0; c9_i63 < 137; c9_i63++) {
    c9_arr[c9_i63] = c9_dv12[c9_i63];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i64 = 0; c9_i64 < 256; c9_i64++) {
    c9_tt[c9_i64] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i65 = 0; c9_i65 < 137; c9_i65++) {
    c9_tt[c9_i65] = c9_arr[c9_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i66 = 0; c9_i66 < 256; c9_i66++) {
    c9_myarr256[c9_i66] = c9_tt[c9_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_k_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[138];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[138];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i67;
  static char_T c9_cv11[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i68;
  static real_T c9_dv13[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i69;
  int32_T c9_i70;
  int32_T c9_i71;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_l_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i67 = 0; c9_i67 < 138; c9_i67++) {
    c9_mystr[c9_i67] = c9_cv11[c9_i67];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i68 = 0; c9_i68 < 138; c9_i68++) {
    c9_arr[c9_i68] = c9_dv13[c9_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i69 = 0; c9_i69 < 256; c9_i69++) {
    c9_tt[c9_i69] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i70 = 0; c9_i70 < 138; c9_i70++) {
    c9_tt[c9_i70] = c9_arr[c9_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i71 = 0; c9_i71 < 256; c9_i71++) {
    c9_myarr256[c9_i71] = c9_tt[c9_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_l_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[136];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[136];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i72;
  static char_T c9_cv12[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i73;
  static real_T c9_dv14[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i74;
  int32_T c9_i75;
  int32_T c9_i76;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_m_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i72 = 0; c9_i72 < 136; c9_i72++) {
    c9_mystr[c9_i72] = c9_cv12[c9_i72];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i73 = 0; c9_i73 < 136; c9_i73++) {
    c9_arr[c9_i73] = c9_dv14[c9_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i74 = 0; c9_i74 < 256; c9_i74++) {
    c9_tt[c9_i74] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i75 = 0; c9_i75 < 136; c9_i75++) {
    c9_tt[c9_i75] = c9_arr[c9_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i76 = 0; c9_i76 < 256; c9_i76++) {
    c9_myarr256[c9_i76] = c9_tt[c9_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_m_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[135];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[135];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i77;
  static char_T c9_cv13[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i78;
  static real_T c9_dv15[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i79;
  int32_T c9_i80;
  int32_T c9_i81;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_n_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i77 = 0; c9_i77 < 135; c9_i77++) {
    c9_mystr[c9_i77] = c9_cv13[c9_i77];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i78 = 0; c9_i78 < 135; c9_i78++) {
    c9_arr[c9_i78] = c9_dv15[c9_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i79 = 0; c9_i79 < 256; c9_i79++) {
    c9_tt[c9_i79] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i80 = 0; c9_i80 < 135; c9_i80++) {
    c9_tt[c9_i80] = c9_arr[c9_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i81 = 0; c9_i81 < 256; c9_i81++) {
    c9_myarr256[c9_i81] = c9_tt[c9_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_n_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[131];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[131];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i82;
  static char_T c9_cv14[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '1',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i83;
  static real_T c9_dv16[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i84;
  int32_T c9_i85;
  int32_T c9_i86;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_o_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i82 = 0; c9_i82 < 131; c9_i82++) {
    c9_mystr[c9_i82] = c9_cv14[c9_i82];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i83 = 0; c9_i83 < 131; c9_i83++) {
    c9_arr[c9_i83] = c9_dv16[c9_i83];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 131.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i84 = 0; c9_i84 < 256; c9_i84++) {
    c9_tt[c9_i84] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i85 = 0; c9_i85 < 131; c9_i85++) {
    c9_tt[c9_i85] = c9_arr[c9_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i86 = 0; c9_i86 < 256; c9_i86++) {
    c9_myarr256[c9_i86] = c9_tt[c9_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_o_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[134];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[134];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i87;
  static char_T c9_cv15[134] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i88;
  static real_T c9_dv17[134] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i89;
  int32_T c9_i90;
  int32_T c9_i91;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_p_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i87 = 0; c9_i87 < 134; c9_i87++) {
    c9_mystr[c9_i87] = c9_cv15[c9_i87];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i88 = 0; c9_i88 < 134; c9_i88++) {
    c9_arr[c9_i88] = c9_dv17[c9_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i89 = 0; c9_i89 < 256; c9_i89++) {
    c9_tt[c9_i89] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i90 = 0; c9_i90 < 134; c9_i90++) {
    c9_tt[c9_i90] = c9_arr[c9_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i91 = 0; c9_i91 < 256; c9_i91++) {
    c9_myarr256[c9_i91] = c9_tt[c9_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_p_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[133];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[133];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i92;
  static char_T c9_cv16[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i93;
  static real_T c9_dv18[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i94;
  int32_T c9_i95;
  int32_T c9_i96;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_q_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i92 = 0; c9_i92 < 133; c9_i92++) {
    c9_mystr[c9_i92] = c9_cv16[c9_i92];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i93 = 0; c9_i93 < 133; c9_i93++) {
    c9_arr[c9_i93] = c9_dv18[c9_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i94 = 0; c9_i94 < 256; c9_i94++) {
    c9_tt[c9_i94] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i95 = 0; c9_i95 < 133; c9_i95++) {
    c9_tt[c9_i95] = c9_arr[c9_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i96 = 0; c9_i96 < 256; c9_i96++) {
    c9_myarr256[c9_i96] = c9_tt[c9_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_q_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[87];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[87];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i97;
  static char_T c9_cv17[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i98;
  static real_T c9_dv19[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i99;
  int32_T c9_i100;
  int32_T c9_i101;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_r_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i97 = 0; c9_i97 < 87; c9_i97++) {
    c9_mystr[c9_i97] = c9_cv17[c9_i97];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i98 = 0; c9_i98 < 87; c9_i98++) {
    c9_arr[c9_i98] = c9_dv19[c9_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i99 = 0; c9_i99 < 256; c9_i99++) {
    c9_tt[c9_i99] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i100 = 0; c9_i100 < 87; c9_i100++) {
    c9_tt[c9_i100] = c9_arr[c9_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i101 = 0; c9_i101 < 256; c9_i101++) {
    c9_myarr256[c9_i101] = c9_tt[c9_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_r_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[115];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[115];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i102;
  static char_T c9_cv18[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '5',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd',
    '=', '\"', '0', '.', '1', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"',
    '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i103;
  static real_T c9_dv20[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    53.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 48.0, 46.0, 49.0, 34.0, 32.0, 97.0,
    109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i104;
  int32_T c9_i105;
  int32_T c9_i106;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_s_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i102 = 0; c9_i102 < 115; c9_i102++) {
    c9_mystr[c9_i102] = c9_cv18[c9_i102];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i103 = 0; c9_i103 < 115; c9_i103++) {
    c9_arr[c9_i103] = c9_dv20[c9_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i104 = 0; c9_i104 < 256; c9_i104++) {
    c9_tt[c9_i104] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i105 = 0; c9_i105 < 115; c9_i105++) {
    c9_tt[c9_i105] = c9_arr[c9_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i106 = 0; c9_i106 < 256; c9_i106++) {
    c9_myarr256[c9_i106] = c9_tt[c9_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_s_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[115];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[115];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i107;
  static char_T c9_cv19[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r',
    'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i108;
  static real_T c9_dv21[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0,
    101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i109;
  int32_T c9_i110;
  int32_T c9_i111;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_u_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i107 = 0; c9_i107 < 115; c9_i107++) {
    c9_mystr[c9_i107] = c9_cv19[c9_i107];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i108 = 0; c9_i108 < 115; c9_i108++) {
    c9_arr[c9_i108] = c9_dv21[c9_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i109 = 0; c9_i109 < 256; c9_i109++) {
    c9_tt[c9_i109] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i110 = 0; c9_i110 < 115; c9_i110++) {
    c9_tt[c9_i110] = c9_arr[c9_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i111 = 0; c9_i111 < 256; c9_i111++) {
    c9_myarr256[c9_i111] = c9_tt[c9_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_t_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[117];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[117];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i112;
  static char_T c9_cv20[117] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i113;
  static real_T c9_dv22[117] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i114;
  int32_T c9_i115;
  int32_T c9_i116;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_v_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i112 = 0; c9_i112 < 117; c9_i112++) {
    c9_mystr[c9_i112] = c9_cv20[c9_i112];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i113 = 0; c9_i113 < 117; c9_i113++) {
    c9_arr[c9_i113] = c9_dv22[c9_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i114 = 0; c9_i114 < 256; c9_i114++) {
    c9_tt[c9_i114] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i115 = 0; c9_i115 < 117; c9_i115++) {
    c9_tt[c9_i115] = c9_arr[c9_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i116 = 0; c9_i116 < 256; c9_i116++) {
    c9_myarr256[c9_i116] = c9_tt[c9_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_u_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[118];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[118];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i117;
  static char_T c9_cv21[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i118;
  static real_T c9_dv23[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i119;
  int32_T c9_i120;
  int32_T c9_i121;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_w_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i117 = 0; c9_i117 < 118; c9_i117++) {
    c9_mystr[c9_i117] = c9_cv21[c9_i117];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i118 = 0; c9_i118 < 118; c9_i118++) {
    c9_arr[c9_i118] = c9_dv23[c9_i118];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i119 = 0; c9_i119 < 256; c9_i119++) {
    c9_tt[c9_i119] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i120 = 0; c9_i120 < 118; c9_i120++) {
    c9_tt[c9_i120] = c9_arr[c9_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i121 = 0; c9_i121 < 256; c9_i121++) {
    c9_myarr256[c9_i121] = c9_tt[c9_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_v_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[119];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[119];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i122;
  static char_T c9_cv22[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i123;
  static real_T c9_dv24[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i124;
  int32_T c9_i125;
  int32_T c9_i126;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_x_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i122 = 0; c9_i122 < 119; c9_i122++) {
    c9_mystr[c9_i122] = c9_cv22[c9_i122];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i123 = 0; c9_i123 < 119; c9_i123++) {
    c9_arr[c9_i123] = c9_dv24[c9_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i124 = 0; c9_i124 < 256; c9_i124++) {
    c9_tt[c9_i124] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i125 = 0; c9_i125 < 119; c9_i125++) {
    c9_tt[c9_i125] = c9_arr[c9_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i126 = 0; c9_i126 < 256; c9_i126++) {
    c9_myarr256[c9_i126] = c9_tt[c9_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_w_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[120];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[120];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i127;
  static char_T c9_cv23[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i128;
  static real_T c9_dv25[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i129;
  int32_T c9_i130;
  int32_T c9_i131;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_y_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i127 = 0; c9_i127 < 120; c9_i127++) {
    c9_mystr[c9_i127] = c9_cv23[c9_i127];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i128 = 0; c9_i128 < 120; c9_i128++) {
    c9_arr[c9_i128] = c9_dv25[c9_i128];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i129 = 0; c9_i129 < 256; c9_i129++) {
    c9_tt[c9_i129] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i130 = 0; c9_i130 < 120; c9_i130++) {
    c9_tt[c9_i130] = c9_arr[c9_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i131 = 0; c9_i131 < 256; c9_i131++) {
    c9_myarr256[c9_i131] = c9_tt[c9_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_x_encStr2Arr(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[121];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[121];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i132;
  static char_T c9_cv24[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i133;
  static real_T c9_dv26[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i134;
  int32_T c9_i135;
  int32_T c9_i136;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ab_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i132 = 0; c9_i132 < 121; c9_i132++) {
    c9_mystr[c9_i132] = c9_cv24[c9_i132];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i133 = 0; c9_i133 < 121; c9_i133++) {
    c9_arr[c9_i133] = c9_dv26[c9_i133];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i134 = 0; c9_i134 < 256; c9_i134++) {
    c9_tt[c9_i134] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i135 = 0; c9_i135 < 121; c9_i135++) {
    c9_tt[c9_i135] = c9_arr[c9_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i136 = 0; c9_i136 < 256; c9_i136++) {
    c9_myarr256[c9_i136] = c9_tt[c9_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c9_rand(SFc9_lib_affectiveChar_behaviorInstanceStruct
                      *chartInstance)
{
  return c9_eml_rand(chartInstance);
}

static real_T c9_eml_rand(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  real_T c9_r;
  uint32_T c9_hoistedGlobal;
  uint32_T c9_d_state;
  uint32_T c9_e_state;
  uint32_T c9_s;
  uint32_T c9_u0;
  uint32_T c9_hi;
  uint32_T c9_lo;
  uint32_T c9_test1;
  uint32_T c9_test2;
  uint32_T c9_f_state;
  real_T c9_b_r;
  real_T c9_d0;
  int32_T c9_i137;
  uint32_T c9_icng;
  uint32_T c9_jsr;
  uint32_T c9_u1;
  uint32_T c9_u2;
  uint32_T c9_ui;
  uint32_T c9_b_ui;
  real_T c9_c_r;
  real_T c9_d1;
  uint32_T c9_uv2[625];
  int32_T c9_i138;
  real_T c9_d2;
  if (!chartInstance->c9_method_not_empty) {
    chartInstance->c9_method = 7U;
    chartInstance->c9_method_not_empty = true;
  }

  if (chartInstance->c9_method == 4U) {
    if (!chartInstance->c9_state_not_empty) {
      chartInstance->c9_state = 1144108930U;
      chartInstance->c9_state_not_empty = true;
    }

    c9_hoistedGlobal = chartInstance->c9_state;
    c9_d_state = c9_hoistedGlobal;
    c9_e_state = c9_d_state;
    c9_s = c9_e_state;
    c9_u0 = 127773U;
    if (c9_u0 == 0U) {
      c9_hi = MAX_uint32_T;
    } else {
      c9_hi = c9_s / c9_u0;
    }

    c9_lo = c9_s - c9_hi * 127773U;
    c9_test1 = 16807U * c9_lo;
    c9_test2 = 2836U * c9_hi;
    if (c9_test1 < c9_test2) {
      c9_f_state = (c9_test1 - c9_test2) + 2147483647U;
    } else {
      c9_f_state = c9_test1 - c9_test2;
    }

    c9_b_r = (real_T)c9_f_state * 4.6566128752457969E-10;
    c9_e_state = c9_f_state;
    c9_d0 = c9_b_r;
    chartInstance->c9_state = c9_e_state;
    c9_r = c9_d0;
  } else if (chartInstance->c9_method == 5U) {
    if (!chartInstance->c9_b_state_not_empty) {
      for (c9_i137 = 0; c9_i137 < 2; c9_i137++) {
        chartInstance->c9_b_state[c9_i137] = 362436069U + 158852560U * (uint32_T)
          c9_i137;
      }

      chartInstance->c9_b_state_not_empty = true;
    }

    c9_icng = chartInstance->c9_b_state[0];
    c9_jsr = chartInstance->c9_b_state[1];
    c9_u1 = c9_jsr;
    c9_u2 = c9_icng;
    c9_u2 = 69069U * c9_u2 + 1234567U;
    c9_u1 ^= c9_u1 << 13;
    c9_u1 ^= c9_u1 >> 17;
    c9_u1 ^= c9_u1 << 5;
    c9_ui = c9_u2 + c9_u1;
    chartInstance->c9_b_state[0] = c9_u2;
    chartInstance->c9_b_state[1] = c9_u1;
    c9_b_ui = c9_ui;
    c9_c_r = (real_T)c9_b_ui * 2.328306436538696E-10;
    c9_d1 = c9_c_r;
    c9_r = c9_d1;
  } else {
    if (!chartInstance->c9_c_state_not_empty) {
      c9_eml_rand_mt19937ar(chartInstance, c9_uv2);
      for (c9_i138 = 0; c9_i138 < 625; c9_i138++) {
        chartInstance->c9_c_state[c9_i138] = c9_uv2[c9_i138];
      }

      chartInstance->c9_c_state_not_empty = true;
    }

    c9_d2 = c9_c_eml_rand_mt19937ar(chartInstance, chartInstance->c9_c_state);
    c9_r = c9_d2;
  }

  return c9_r;
}

static void c9_eml_rand_mt19937ar(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_d_state[625])
{
  real_T c9_d3;
  int32_T c9_i139;
  c9_d3 = 5489.0;
  for (c9_i139 = 0; c9_i139 < 625; c9_i139++) {
    c9_d_state[c9_i139] = 0U;
  }

  c9_b_twister_state_vector(chartInstance, c9_d_state, c9_d3);
}

static void c9_twister_state_vector
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed, uint32_T c9_b_mt[625])
{
  int32_T c9_i140;
  for (c9_i140 = 0; c9_i140 < 625; c9_i140++) {
    c9_b_mt[c9_i140] = c9_mt[c9_i140];
  }

  c9_b_twister_state_vector(chartInstance, c9_b_mt, c9_seed);
}

static void c9_b_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c9_d_state[625], uint32_T c9_e_state[625], real_T *c9_r)
{
  int32_T c9_i141;
  for (c9_i141 = 0; c9_i141 < 625; c9_i141++) {
    c9_e_state[c9_i141] = c9_d_state[c9_i141];
  }

  *c9_r = c9_c_eml_rand_mt19937ar(chartInstance, c9_e_state);
}

static void c9_eml_error(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  int32_T c9_i142;
  static char_T c9_cv25[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c9_u[37];
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  for (c9_i142 = 0; c9_i142 < 37; c9_i142++) {
    c9_u[c9_i142] = c9_cv25[c9_i142];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c9_y));
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\4-6-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i143;
  real_T c9_b_inData[256];
  int32_T c9_i144;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i143 = 0; c9_i143 < 256; c9_i143++) {
    c9_b_inData[c9_i143] = (*(real_T (*)[256])c9_inData)[c9_i143];
  }

  for (c9_i144 = 0; c9_i144 < 256; c9_i144++) {
    c9_u[c9_i144] = c9_b_inData[c9_i144];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256])
{
  real_T c9_dv27[256];
  int32_T c9_i145;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv27, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c9_i145 = 0; c9_i145 < 256; c9_i145++) {
    c9_y[c9_i145] = c9_dv27[c9_i145];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_gazeBML;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[256];
  int32_T c9_i146;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_gazeBML = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_gazeBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_gazeBML);
  for (c9_i146 = 0; c9_i146 < 256; c9_i146++) {
    (*(real_T (*)[256])c9_outData)[c9_i146] = c9_y[c9_i146];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_b_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d4;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d4, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d4;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_bmlID;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_bmlID = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_bmlID), &c9_thisId);
  sf_mex_destroy(&c9_bmlID);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_c_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b0, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_aVarTruthTableCondition_18;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_aVarTruthTableCondition_18 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_aVarTruthTableCondition_18), &c9_thisId);
  sf_mex_destroy(&c9_aVarTruthTableCondition_18);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i147;
  real_T c9_b_inData[256];
  int32_T c9_i148;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i147 = 0; c9_i147 < 256; c9_i147++) {
    c9_b_inData[c9_i147] = (*(real_T (*)[256])c9_inData)[c9_i147];
  }

  for (c9_i148 = 0; c9_i148 < 256; c9_i148++) {
    c9_u[c9_i148] = c9_b_inData[c9_i148];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256])
{
  real_T c9_dv28[256];
  int32_T c9_i149;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv28, 1, 0, 0U, 1, 0U, 1, 256);
  for (c9_i149 = 0; c9_i149 < 256; c9_i149++) {
    c9_y[c9_i149] = c9_dv28[c9_i149];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_myarr256;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[256];
  int32_T c9_i150;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_myarr256 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
  for (c9_i150 = 0; c9_i150 < 256; c9_i150++) {
    (*(real_T (*)[256])c9_outData)[c9_i150] = c9_y[c9_i150];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i151;
  char_T c9_b_inData[118];
  int32_T c9_i152;
  char_T c9_u[118];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i151 = 0; c9_i151 < 118; c9_i151++) {
    c9_b_inData[c9_i151] = (*(char_T (*)[118])c9_inData)[c9_i151];
  }

  for (c9_i152 = 0; c9_i152 < 118; c9_i152++) {
    c9_u[c9_i152] = c9_b_inData[c9_i152];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i153;
  real_T c9_b_inData[118];
  int32_T c9_i154;
  real_T c9_u[118];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i153 = 0; c9_i153 < 118; c9_i153++) {
    c9_b_inData[c9_i153] = (*(real_T (*)[118])c9_inData)[c9_i153];
  }

  for (c9_i154 = 0; c9_i154 < 118; c9_i154++) {
    c9_u[c9_i154] = c9_b_inData[c9_i154];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i155;
  char_T c9_b_inData[119];
  int32_T c9_i156;
  char_T c9_u[119];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i155 = 0; c9_i155 < 119; c9_i155++) {
    c9_b_inData[c9_i155] = (*(char_T (*)[119])c9_inData)[c9_i155];
  }

  for (c9_i156 = 0; c9_i156 < 119; c9_i156++) {
    c9_u[c9_i156] = c9_b_inData[c9_i156];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i157;
  real_T c9_b_inData[119];
  int32_T c9_i158;
  real_T c9_u[119];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i157 = 0; c9_i157 < 119; c9_i157++) {
    c9_b_inData[c9_i157] = (*(real_T (*)[119])c9_inData)[c9_i157];
  }

  for (c9_i158 = 0; c9_i158 < 119; c9_i158++) {
    c9_u[c9_i158] = c9_b_inData[c9_i158];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i159;
  char_T c9_b_inData[116];
  int32_T c9_i160;
  char_T c9_u[116];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i159 = 0; c9_i159 < 116; c9_i159++) {
    c9_b_inData[c9_i159] = (*(char_T (*)[116])c9_inData)[c9_i159];
  }

  for (c9_i160 = 0; c9_i160 < 116; c9_i160++) {
    c9_u[c9_i160] = c9_b_inData[c9_i160];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i161;
  real_T c9_b_inData[116];
  int32_T c9_i162;
  real_T c9_u[116];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i161 = 0; c9_i161 < 116; c9_i161++) {
    c9_b_inData[c9_i161] = (*(real_T (*)[116])c9_inData)[c9_i161];
  }

  for (c9_i162 = 0; c9_i162 < 116; c9_i162++) {
    c9_u[c9_i162] = c9_b_inData[c9_i162];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i163;
  char_T c9_b_inData[120];
  int32_T c9_i164;
  char_T c9_u[120];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i163 = 0; c9_i163 < 120; c9_i163++) {
    c9_b_inData[c9_i163] = (*(char_T (*)[120])c9_inData)[c9_i163];
  }

  for (c9_i164 = 0; c9_i164 < 120; c9_i164++) {
    c9_u[c9_i164] = c9_b_inData[c9_i164];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i165;
  real_T c9_b_inData[120];
  int32_T c9_i166;
  real_T c9_u[120];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i165 = 0; c9_i165 < 120; c9_i165++) {
    c9_b_inData[c9_i165] = (*(real_T (*)[120])c9_inData)[c9_i165];
  }

  for (c9_i166 = 0; c9_i166 < 120; c9_i166++) {
    c9_u[c9_i166] = c9_b_inData[c9_i166];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i167;
  char_T c9_b_inData[121];
  int32_T c9_i168;
  char_T c9_u[121];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i167 = 0; c9_i167 < 121; c9_i167++) {
    c9_b_inData[c9_i167] = (*(char_T (*)[121])c9_inData)[c9_i167];
  }

  for (c9_i168 = 0; c9_i168 < 121; c9_i168++) {
    c9_u[c9_i168] = c9_b_inData[c9_i168];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i169;
  real_T c9_b_inData[121];
  int32_T c9_i170;
  real_T c9_u[121];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i169 = 0; c9_i169 < 121; c9_i169++) {
    c9_b_inData[c9_i169] = (*(real_T (*)[121])c9_inData)[c9_i169];
  }

  for (c9_i170 = 0; c9_i170 < 121; c9_i170++) {
    c9_u[c9_i170] = c9_b_inData[c9_i170];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i171;
  char_T c9_b_inData[122];
  int32_T c9_i172;
  char_T c9_u[122];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i171 = 0; c9_i171 < 122; c9_i171++) {
    c9_b_inData[c9_i171] = (*(char_T (*)[122])c9_inData)[c9_i171];
  }

  for (c9_i172 = 0; c9_i172 < 122; c9_i172++) {
    c9_u[c9_i172] = c9_b_inData[c9_i172];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i173;
  real_T c9_b_inData[122];
  int32_T c9_i174;
  real_T c9_u[122];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i173 = 0; c9_i173 < 122; c9_i173++) {
    c9_b_inData[c9_i173] = (*(real_T (*)[122])c9_inData)[c9_i173];
  }

  for (c9_i174 = 0; c9_i174 < 122; c9_i174++) {
    c9_u[c9_i174] = c9_b_inData[c9_i174];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i175;
  char_T c9_b_inData[123];
  int32_T c9_i176;
  char_T c9_u[123];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i175 = 0; c9_i175 < 123; c9_i175++) {
    c9_b_inData[c9_i175] = (*(char_T (*)[123])c9_inData)[c9_i175];
  }

  for (c9_i176 = 0; c9_i176 < 123; c9_i176++) {
    c9_u[c9_i176] = c9_b_inData[c9_i176];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i177;
  real_T c9_b_inData[123];
  int32_T c9_i178;
  real_T c9_u[123];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i177 = 0; c9_i177 < 123; c9_i177++) {
    c9_b_inData[c9_i177] = (*(real_T (*)[123])c9_inData)[c9_i177];
  }

  for (c9_i178 = 0; c9_i178 < 123; c9_i178++) {
    c9_u[c9_i178] = c9_b_inData[c9_i178];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i179;
  char_T c9_b_inData[133];
  int32_T c9_i180;
  char_T c9_u[133];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i179 = 0; c9_i179 < 133; c9_i179++) {
    c9_b_inData[c9_i179] = (*(char_T (*)[133])c9_inData)[c9_i179];
  }

  for (c9_i180 = 0; c9_i180 < 133; c9_i180++) {
    c9_u[c9_i180] = c9_b_inData[c9_i180];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i181;
  real_T c9_b_inData[133];
  int32_T c9_i182;
  real_T c9_u[133];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i181 = 0; c9_i181 < 133; c9_i181++) {
    c9_b_inData[c9_i181] = (*(real_T (*)[133])c9_inData)[c9_i181];
  }

  for (c9_i182 = 0; c9_i182 < 133; c9_i182++) {
    c9_u[c9_i182] = c9_b_inData[c9_i182];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i183;
  char_T c9_b_inData[137];
  int32_T c9_i184;
  char_T c9_u[137];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i183 = 0; c9_i183 < 137; c9_i183++) {
    c9_b_inData[c9_i183] = (*(char_T (*)[137])c9_inData)[c9_i183];
  }

  for (c9_i184 = 0; c9_i184 < 137; c9_i184++) {
    c9_u[c9_i184] = c9_b_inData[c9_i184];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i185;
  real_T c9_b_inData[137];
  int32_T c9_i186;
  real_T c9_u[137];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i185 = 0; c9_i185 < 137; c9_i185++) {
    c9_b_inData[c9_i185] = (*(real_T (*)[137])c9_inData)[c9_i185];
  }

  for (c9_i186 = 0; c9_i186 < 137; c9_i186++) {
    c9_u[c9_i186] = c9_b_inData[c9_i186];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i187;
  char_T c9_b_inData[138];
  int32_T c9_i188;
  char_T c9_u[138];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i187 = 0; c9_i187 < 138; c9_i187++) {
    c9_b_inData[c9_i187] = (*(char_T (*)[138])c9_inData)[c9_i187];
  }

  for (c9_i188 = 0; c9_i188 < 138; c9_i188++) {
    c9_u[c9_i188] = c9_b_inData[c9_i188];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i189;
  real_T c9_b_inData[138];
  int32_T c9_i190;
  real_T c9_u[138];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i189 = 0; c9_i189 < 138; c9_i189++) {
    c9_b_inData[c9_i189] = (*(real_T (*)[138])c9_inData)[c9_i189];
  }

  for (c9_i190 = 0; c9_i190 < 138; c9_i190++) {
    c9_u[c9_i190] = c9_b_inData[c9_i190];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i191;
  char_T c9_b_inData[136];
  int32_T c9_i192;
  char_T c9_u[136];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i191 = 0; c9_i191 < 136; c9_i191++) {
    c9_b_inData[c9_i191] = (*(char_T (*)[136])c9_inData)[c9_i191];
  }

  for (c9_i192 = 0; c9_i192 < 136; c9_i192++) {
    c9_u[c9_i192] = c9_b_inData[c9_i192];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i193;
  real_T c9_b_inData[136];
  int32_T c9_i194;
  real_T c9_u[136];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i193 = 0; c9_i193 < 136; c9_i193++) {
    c9_b_inData[c9_i193] = (*(real_T (*)[136])c9_inData)[c9_i193];
  }

  for (c9_i194 = 0; c9_i194 < 136; c9_i194++) {
    c9_u[c9_i194] = c9_b_inData[c9_i194];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i195;
  char_T c9_b_inData[135];
  int32_T c9_i196;
  char_T c9_u[135];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i195 = 0; c9_i195 < 135; c9_i195++) {
    c9_b_inData[c9_i195] = (*(char_T (*)[135])c9_inData)[c9_i195];
  }

  for (c9_i196 = 0; c9_i196 < 135; c9_i196++) {
    c9_u[c9_i196] = c9_b_inData[c9_i196];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i197;
  real_T c9_b_inData[135];
  int32_T c9_i198;
  real_T c9_u[135];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i197 = 0; c9_i197 < 135; c9_i197++) {
    c9_b_inData[c9_i197] = (*(real_T (*)[135])c9_inData)[c9_i197];
  }

  for (c9_i198 = 0; c9_i198 < 135; c9_i198++) {
    c9_u[c9_i198] = c9_b_inData[c9_i198];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i199;
  char_T c9_b_inData[131];
  int32_T c9_i200;
  char_T c9_u[131];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i199 = 0; c9_i199 < 131; c9_i199++) {
    c9_b_inData[c9_i199] = (*(char_T (*)[131])c9_inData)[c9_i199];
  }

  for (c9_i200 = 0; c9_i200 < 131; c9_i200++) {
    c9_u[c9_i200] = c9_b_inData[c9_i200];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i201;
  real_T c9_b_inData[131];
  int32_T c9_i202;
  real_T c9_u[131];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i201 = 0; c9_i201 < 131; c9_i201++) {
    c9_b_inData[c9_i201] = (*(real_T (*)[131])c9_inData)[c9_i201];
  }

  for (c9_i202 = 0; c9_i202 < 131; c9_i202++) {
    c9_u[c9_i202] = c9_b_inData[c9_i202];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i203;
  char_T c9_b_inData[134];
  int32_T c9_i204;
  char_T c9_u[134];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i203 = 0; c9_i203 < 134; c9_i203++) {
    c9_b_inData[c9_i203] = (*(char_T (*)[134])c9_inData)[c9_i203];
  }

  for (c9_i204 = 0; c9_i204 < 134; c9_i204++) {
    c9_u[c9_i204] = c9_b_inData[c9_i204];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i205;
  real_T c9_b_inData[134];
  int32_T c9_i206;
  real_T c9_u[134];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i205 = 0; c9_i205 < 134; c9_i205++) {
    c9_b_inData[c9_i205] = (*(real_T (*)[134])c9_inData)[c9_i205];
  }

  for (c9_i206 = 0; c9_i206 < 134; c9_i206++) {
    c9_u[c9_i206] = c9_b_inData[c9_i206];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i207;
  char_T c9_b_inData[87];
  int32_T c9_i208;
  char_T c9_u[87];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i207 = 0; c9_i207 < 87; c9_i207++) {
    c9_b_inData[c9_i207] = (*(char_T (*)[87])c9_inData)[c9_i207];
  }

  for (c9_i208 = 0; c9_i208 < 87; c9_i208++) {
    c9_u[c9_i208] = c9_b_inData[c9_i208];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i209;
  real_T c9_b_inData[87];
  int32_T c9_i210;
  real_T c9_u[87];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i209 = 0; c9_i209 < 87; c9_i209++) {
    c9_b_inData[c9_i209] = (*(real_T (*)[87])c9_inData)[c9_i209];
  }

  for (c9_i210 = 0; c9_i210 < 87; c9_i210++) {
    c9_u[c9_i210] = c9_b_inData[c9_i210];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i211;
  char_T c9_b_inData[115];
  int32_T c9_i212;
  char_T c9_u[115];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i211 = 0; c9_i211 < 115; c9_i211++) {
    c9_b_inData[c9_i211] = (*(char_T (*)[115])c9_inData)[c9_i211];
  }

  for (c9_i212 = 0; c9_i212 < 115; c9_i212++) {
    c9_u[c9_i212] = c9_b_inData[c9_i212];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i213;
  real_T c9_b_inData[115];
  int32_T c9_i214;
  real_T c9_u[115];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i213 = 0; c9_i213 < 115; c9_i213++) {
    c9_b_inData[c9_i213] = (*(real_T (*)[115])c9_inData)[c9_i213];
  }

  for (c9_i214 = 0; c9_i214 < 115; c9_i214++) {
    c9_u[c9_i214] = c9_b_inData[c9_i214];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i215;
  char_T c9_b_inData[117];
  int32_T c9_i216;
  char_T c9_u[117];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i215 = 0; c9_i215 < 117; c9_i215++) {
    c9_b_inData[c9_i215] = (*(char_T (*)[117])c9_inData)[c9_i215];
  }

  for (c9_i216 = 0; c9_i216 < 117; c9_i216++) {
    c9_u[c9_i216] = c9_b_inData[c9_i216];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 117),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i217;
  real_T c9_b_inData[117];
  int32_T c9_i218;
  real_T c9_u[117];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i217 = 0; c9_i217 < 117; c9_i217++) {
    c9_b_inData[c9_i217] = (*(real_T (*)[117])c9_inData)[c9_i217];
  }

  for (c9_i218 = 0; c9_i218 < 117; c9_i218++) {
    c9_u[c9_i218] = c9_b_inData[c9_i218];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 117), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_lib_affectiveChar_behavior_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  const mxArray *c9_rhs4 = NULL;
  const mxArray *c9_lhs4 = NULL;
  const mxArray *c9_rhs5 = NULL;
  const mxArray *c9_lhs5 = NULL;
  const mxArray *c9_rhs6 = NULL;
  const mxArray *c9_lhs6 = NULL;
  const mxArray *c9_rhs7 = NULL;
  const mxArray *c9_lhs7 = NULL;
  const mxArray *c9_rhs8 = NULL;
  const mxArray *c9_lhs8 = NULL;
  const mxArray *c9_rhs9 = NULL;
  const mxArray *c9_lhs9 = NULL;
  const mxArray *c9_rhs10 = NULL;
  const mxArray *c9_lhs10 = NULL;
  const mxArray *c9_rhs11 = NULL;
  const mxArray *c9_lhs11 = NULL;
  const mxArray *c9_rhs12 = NULL;
  const mxArray *c9_lhs12 = NULL;
  const mxArray *c9_rhs13 = NULL;
  const mxArray *c9_lhs13 = NULL;
  const mxArray *c9_rhs14 = NULL;
  const mxArray *c9_lhs14 = NULL;
  const mxArray *c9_rhs15 = NULL;
  const mxArray *c9_lhs15 = NULL;
  const mxArray *c9_rhs16 = NULL;
  const mxArray *c9_lhs16 = NULL;
  const mxArray *c9_rhs17 = NULL;
  const mxArray *c9_lhs17 = NULL;
  const mxArray *c9_rhs18 = NULL;
  const mxArray *c9_lhs18 = NULL;
  const mxArray *c9_rhs19 = NULL;
  const mxArray *c9_lhs19 = NULL;
  const mxArray *c9_rhs20 = NULL;
  const mxArray *c9_lhs20 = NULL;
  const mxArray *c9_rhs21 = NULL;
  const mxArray *c9_lhs21 = NULL;
  const mxArray *c9_rhs22 = NULL;
  const mxArray *c9_lhs22 = NULL;
  const mxArray *c9_rhs23 = NULL;
  const mxArray *c9_lhs23 = NULL;
  const mxArray *c9_rhs24 = NULL;
  const mxArray *c9_lhs24 = NULL;
  const mxArray *c9_rhs25 = NULL;
  const mxArray *c9_lhs25 = NULL;
  const mxArray *c9_rhs26 = NULL;
  const mxArray *c9_lhs26 = NULL;
  const mxArray *c9_rhs27 = NULL;
  const mxArray *c9_lhs27 = NULL;
  const mxArray *c9_rhs28 = NULL;
  const mxArray *c9_lhs28 = NULL;
  const mxArray *c9_rhs29 = NULL;
  const mxArray *c9_lhs29 = NULL;
  const mxArray *c9_rhs30 = NULL;
  const mxArray *c9_lhs30 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c9_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c9_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c9_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c9_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c9_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c9_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c9_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c9_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c9_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c9_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c9_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c9_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c9_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c9_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c9_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c9_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c9_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c9_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c9_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c9_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c9_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c9_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c9_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c9_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c9_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c9_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c9_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
  sf_mex_destroy(&c9_rhs4);
  sf_mex_destroy(&c9_lhs4);
  sf_mex_destroy(&c9_rhs5);
  sf_mex_destroy(&c9_lhs5);
  sf_mex_destroy(&c9_rhs6);
  sf_mex_destroy(&c9_lhs6);
  sf_mex_destroy(&c9_rhs7);
  sf_mex_destroy(&c9_lhs7);
  sf_mex_destroy(&c9_rhs8);
  sf_mex_destroy(&c9_lhs8);
  sf_mex_destroy(&c9_rhs9);
  sf_mex_destroy(&c9_lhs9);
  sf_mex_destroy(&c9_rhs10);
  sf_mex_destroy(&c9_lhs10);
  sf_mex_destroy(&c9_rhs11);
  sf_mex_destroy(&c9_lhs11);
  sf_mex_destroy(&c9_rhs12);
  sf_mex_destroy(&c9_lhs12);
  sf_mex_destroy(&c9_rhs13);
  sf_mex_destroy(&c9_lhs13);
  sf_mex_destroy(&c9_rhs14);
  sf_mex_destroy(&c9_lhs14);
  sf_mex_destroy(&c9_rhs15);
  sf_mex_destroy(&c9_lhs15);
  sf_mex_destroy(&c9_rhs16);
  sf_mex_destroy(&c9_lhs16);
  sf_mex_destroy(&c9_rhs17);
  sf_mex_destroy(&c9_lhs17);
  sf_mex_destroy(&c9_rhs18);
  sf_mex_destroy(&c9_lhs18);
  sf_mex_destroy(&c9_rhs19);
  sf_mex_destroy(&c9_lhs19);
  sf_mex_destroy(&c9_rhs20);
  sf_mex_destroy(&c9_lhs20);
  sf_mex_destroy(&c9_rhs21);
  sf_mex_destroy(&c9_lhs21);
  sf_mex_destroy(&c9_rhs22);
  sf_mex_destroy(&c9_lhs22);
  sf_mex_destroy(&c9_rhs23);
  sf_mex_destroy(&c9_lhs23);
  sf_mex_destroy(&c9_rhs24);
  sf_mex_destroy(&c9_lhs24);
  sf_mex_destroy(&c9_rhs25);
  sf_mex_destroy(&c9_lhs25);
  sf_mex_destroy(&c9_rhs26);
  sf_mex_destroy(&c9_lhs26);
  sf_mex_destroy(&c9_rhs27);
  sf_mex_destroy(&c9_lhs27);
  sf_mex_destroy(&c9_rhs28);
  sf_mex_destroy(&c9_lhs28);
  sf_mex_destroy(&c9_rhs29);
  sf_mex_destroy(&c9_lhs29);
  sf_mex_destroy(&c9_rhs30);
  sf_mex_destroy(&c9_lhs30);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static void c9_activate_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = c9_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_deactivate_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_increment_counters_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  if (chartInstance->c9_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c9_temporalCounter_i1++;
  }
}

static void c9_reset_counters_secsc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c9_lib_affectiveChar_behavior_secs(SimStruct
  *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_activate_secsc9_lib_affectiveChar_behavior(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_increment_counters_secsc9_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c9_lib_affectiveChar_behavior_secs
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_reset_counters_secsc9_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_deactivate_c9_lib_affectiveChar_behavior_secs(SimStruct
  *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_deactivate_secsc9_lib_affectiveChar_behavior(chartInstance);
}

boolean_T sf_exported_auto_isStablec9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c9_isStable;
}

void sf_exported_auto_duringc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_c9_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_enterc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_sendBML(chartInstance);
  c9_enter_atomic_c9_lib_affectiveChar_behavior(chartInstance);
  c9_enter_internal_c9_lib_affectiveChar_behavior(chartInstance);
}

void sf_exported_auto_exitc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_exit_internal_c9_lib_affectiveChar_behavior(chartInstance);
  c9_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_sendBML(chartInstance);
}

void sf_exported_auto_disablec9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  chartInstance->c9_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc9_lib_affectiveChar_behavior
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc9_lib_affectiveChar_behavior(SimStruct *
  c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc9_lib_affectiveChar_behavior(SimStruct
  *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc9_lib_affectiveChar_behavior(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_initc9_lib_affectiveChar_behavior(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec9_lib_affectiveChar_behavior
  (SimStruct *c9_S)
{
  const mxArray *c9_out = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_out = NULL;
  sf_mex_assign(&c9_out, sf_internal_get_sim_state_c9_lib_affectiveChar_behavior
                (c9_S), false);
  return c9_out;
}

void sf_exported_auto_setSimstatec9_lib_affectiveChar_behavior(SimStruct *c9_S,
  const mxArray *c9_in)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c9_lib_affectiveChar_behavior(c9_S, sf_mex_dup(c9_in));
  sf_mex_destroy(&c9_in);
}

void sf_exported_auto_check_state_inconsistency_c9_lib_affectiveChar_behavior
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_behaviorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_sendBMLc9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c9_arg
   [256])
{
  int32_T c9_i219;
  int32_T c9_i220;
  int32_T c9_i221;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c9_i219 = 0; c9_i219 < 256; c9_i219++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i219], 7U);
  }

  _SFD_SET_DATA_VALUE_PTR(7U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
  for (c9_i220 = 0; c9_i220 < 256; c9_i220++) {
    (*c9_b_arg)[c9_i220] = c9_arg[c9_i220];
  }

  for (c9_i221 = 0; c9_i221 < 256; c9_i221++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i221], 7U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(7U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
}

static void c9_idleGazeTablec9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[22];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  boolean_T c9_aVarTruthTableCondition_4;
  boolean_T c9_aVarTruthTableCondition_5;
  boolean_T c9_aVarTruthTableCondition_6;
  boolean_T c9_aVarTruthTableCondition_7;
  boolean_T c9_aVarTruthTableCondition_8;
  boolean_T c9_aVarTruthTableCondition_9;
  boolean_T c9_aVarTruthTableCondition_10;
  boolean_T c9_aVarTruthTableCondition_11;
  boolean_T c9_aVarTruthTableCondition_12;
  boolean_T c9_aVarTruthTableCondition_13;
  boolean_T c9_aVarTruthTableCondition_14;
  boolean_T c9_aVarTruthTableCondition_15;
  boolean_T c9_aVarTruthTableCondition_16;
  boolean_T c9_aVarTruthTableCondition_17;
  boolean_T c9_aVarTruthTableCondition_18;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv29[256];
  int32_T c9_i222;
  int32_T c9_i223;
  int32_T c9_i224;
  int32_T c9_i225;
  int32_T c9_i226;
  int32_T c9_i227;
  int32_T c9_i228;
  int32_T c9_i229;
  int32_T c9_i230;
  int32_T c9_i231;
  int32_T c9_i232;
  int32_T c9_i233;
  int32_T c9_i234;
  int32_T c9_i235;
  int32_T c9_i236;
  int32_T c9_i237;
  int32_T c9_i238;
  int32_T c9_i239;
  int32_T c9_i240;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_4, 3U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_5, 4U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_6, 5U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_7, 6U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_8, 7U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_9, 8U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_10, 9U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_11, 10U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_12, 11U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_13, 12U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_14, 13U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_15, 14U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_16, 15U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_17, 16U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_18, 17U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 18U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 19U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 20U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 21U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 11);
  c9_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 15);
  c9_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 16);
  c9_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 17);
  c9_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 19);
  c9_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 20);
  c9_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 24);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 27);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 30);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 33);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 36);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 39);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 42);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 45);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 48);
  c9_aVarTruthTableCondition_9 = (c9_bmlID == 9.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 51);
  c9_aVarTruthTableCondition_10 = (c9_bmlID == 10.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 54);
  c9_aVarTruthTableCondition_11 = (c9_bmlID == 11.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 57);
  c9_aVarTruthTableCondition_12 = (c9_bmlID == 12.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 60);
  c9_aVarTruthTableCondition_13 = (c9_bmlID == 13.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 63);
  c9_aVarTruthTableCondition_14 = (c9_bmlID == 14.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 66);
  c9_aVarTruthTableCondition_15 = (c9_bmlID == 15.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 69);
  c9_aVarTruthTableCondition_16 = (c9_bmlID == 16.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 73);
  c9_aVarTruthTableCondition_17 = (c9_bmlID == 17.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 77);
  c9_aVarTruthTableCondition_18 = (c9_bmlID == 18.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 79);
  if (CV_EML_IF(1, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 80);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 123);
    c9_encStr2Arr(chartInstance, c9_dv29);
    for (c9_i222 = 0; c9_i222 < 256; c9_i222++) {
      c9_gazeBML[c9_i222] = c9_dv29[c9_i222];
    }

    c9_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -123);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 81);
    if (CV_EML_IF(1, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 82);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 129U);
      c9_b_encStr2Arr(chartInstance, c9_dv29);
      for (c9_i223 = 0; c9_i223 < 256; c9_i223++) {
        c9_gazeBML[c9_i223] = c9_dv29[c9_i223];
      }

      c9_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -129);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 83);
      if (CV_EML_IF(1, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 84);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 135U);
        c9_c_encStr2Arr(chartInstance, c9_dv29);
        for (c9_i224 = 0; c9_i224 < 256; c9_i224++) {
          c9_gazeBML[c9_i224] = c9_dv29[c9_i224];
        }

        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -135);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 85);
        if (CV_EML_IF(1, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 86);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 141U);
          c9_d_encStr2Arr(chartInstance, c9_dv29);
          for (c9_i225 = 0; c9_i225 < 256; c9_i225++) {
            c9_gazeBML[c9_i225] = c9_dv29[c9_i225];
          }

          c9_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -141);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 87);
          if (CV_EML_IF(1, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 88);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 147U);
            c9_e_encStr2Arr(chartInstance, c9_dv29);
            for (c9_i226 = 0; c9_i226 < 256; c9_i226++) {
              c9_gazeBML[c9_i226] = c9_dv29[c9_i226];
            }

            c9_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -147);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 89);
            if (CV_EML_IF(1, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 90);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 153U);
              c9_f_encStr2Arr(chartInstance, c9_dv29);
              for (c9_i227 = 0; c9_i227 < 256; c9_i227++) {
                c9_gazeBML[c9_i227] = c9_dv29[c9_i227];
              }

              c9_updateDataWrittenToVector(chartInstance, 0U);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -153);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 91);
              if (CV_EML_IF(1, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 92);
                CV_EML_FCN(1, 7);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 159U);
                c9_g_encStr2Arr(chartInstance, c9_dv29);
                for (c9_i228 = 0; c9_i228 < 256; c9_i228++) {
                  c9_gazeBML[c9_i228] = c9_dv29[c9_i228];
                }

                c9_updateDataWrittenToVector(chartInstance, 0U);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -159);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 93);
                if (CV_EML_IF(1, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 94);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 165U);
                  c9_h_encStr2Arr(chartInstance, c9_dv29);
                  for (c9_i229 = 0; c9_i229 < 256; c9_i229++) {
                    c9_gazeBML[c9_i229] = c9_dv29[c9_i229];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 0U);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -165);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 95);
                  if (CV_EML_IF(1, 1, 8, c9_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 96);
                    CV_EML_FCN(1, 9);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 171U);
                    c9_i_encStr2Arr(chartInstance, c9_dv29);
                    for (c9_i230 = 0; c9_i230 < 256; c9_i230++) {
                      c9_gazeBML[c9_i230] = c9_dv29[c9_i230];
                    }

                    c9_updateDataWrittenToVector(chartInstance, 0U);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -171);
                  } else {
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 97);
                    if (CV_EML_IF(1, 1, 9, c9_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 98);
                      CV_EML_FCN(1, 10);
                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 177U);
                      c9_j_encStr2Arr(chartInstance, c9_dv29);
                      for (c9_i231 = 0; c9_i231 < 256; c9_i231++) {
                        c9_gazeBML[c9_i231] = c9_dv29[c9_i231];
                      }

                      c9_updateDataWrittenToVector(chartInstance, 0U);
                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -177);
                    } else {
                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 99);
                      if (CV_EML_IF(1, 1, 10, c9_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 100);
                        CV_EML_FCN(1, 11);
                        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 183U);
                        c9_k_encStr2Arr(chartInstance, c9_dv29);
                        for (c9_i232 = 0; c9_i232 < 256; c9_i232++) {
                          c9_gazeBML[c9_i232] = c9_dv29[c9_i232];
                        }

                        c9_updateDataWrittenToVector(chartInstance, 0U);
                        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -183);
                      } else {
                        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 101);
                        if (CV_EML_IF(1, 1, 11, c9_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 102);
                          CV_EML_FCN(1, 12);
                          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 189U);
                          c9_l_encStr2Arr(chartInstance, c9_dv29);
                          for (c9_i233 = 0; c9_i233 < 256; c9_i233++) {
                            c9_gazeBML[c9_i233] = c9_dv29[c9_i233];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 0U);
                          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -189);
                        } else {
                          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 103);
                          if (CV_EML_IF(1, 1, 12, c9_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 104);
                            CV_EML_FCN(1, 13);
                            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 195U);
                            c9_m_encStr2Arr(chartInstance, c9_dv29);
                            for (c9_i234 = 0; c9_i234 < 256; c9_i234++) {
                              c9_gazeBML[c9_i234] = c9_dv29[c9_i234];
                            }

                            c9_updateDataWrittenToVector(chartInstance, 0U);
                            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -195);
                          } else {
                            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 105);
                            if (CV_EML_IF(1, 1, 13,
                                          c9_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 106);
                              CV_EML_FCN(1, 14);
                              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 201U);
                              c9_n_encStr2Arr(chartInstance, c9_dv29);
                              for (c9_i235 = 0; c9_i235 < 256; c9_i235++) {
                                c9_gazeBML[c9_i235] = c9_dv29[c9_i235];
                              }

                              c9_updateDataWrittenToVector(chartInstance, 0U);
                              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -201);
                            } else {
                              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 107);
                              if (CV_EML_IF(1, 1, 14,
                                            c9_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 108);
                                CV_EML_FCN(1, 15);
                                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                              207U);
                                c9_o_encStr2Arr(chartInstance, c9_dv29);
                                for (c9_i236 = 0; c9_i236 < 256; c9_i236++) {
                                  c9_gazeBML[c9_i236] = c9_dv29[c9_i236];
                                }

                                c9_updateDataWrittenToVector(chartInstance, 0U);
                                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                              -207);
                              } else {
                                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 109);
                                if (CV_EML_IF(1, 1, 15,
                                              c9_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                110);
                                  CV_EML_FCN(1, 16);
                                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                213U);
                                  c9_p_encStr2Arr(chartInstance, c9_dv29);
                                  for (c9_i237 = 0; c9_i237 < 256; c9_i237++) {
                                    c9_gazeBML[c9_i237] = c9_dv29[c9_i237];
                                  }

                                  c9_updateDataWrittenToVector(chartInstance, 0U);
                                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                -213);
                                } else {
                                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                111);
                                  if (CV_EML_IF(1, 1, 16,
                                                c9_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                  112);
                                    CV_EML_FCN(1, 17);
                                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                  219U);
                                    c9_q_encStr2Arr(chartInstance, c9_dv29);
                                    for (c9_i238 = 0; c9_i238 < 256; c9_i238++)
                                    {
                                      c9_gazeBML[c9_i238] = c9_dv29[c9_i238];
                                    }

                                    c9_updateDataWrittenToVector(chartInstance,
                                      0U);
                                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                  -219);
                                  } else {
                                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent,
                                                  113);
                                    if (CV_EML_IF(1, 1, 17,
                                                  c9_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c9_sfEvent,
                                                    114);
                                      CV_EML_FCN(1, 18);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c9_sfEvent,
                                                    225U);
                                      c9_r_encStr2Arr(chartInstance, c9_dv29);
                                      for (c9_i239 = 0; c9_i239 < 256; c9_i239++)
                                      {
                                        c9_gazeBML[c9_i239] = c9_dv29[c9_i239];
                                      }

                                      c9_updateDataWrittenToVector(chartInstance,
                                        0U);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c9_sfEvent,
                                                    -225);
                                    } else {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c9_sfEvent,
                                                    116);
                                      CV_EML_FCN(1, 1);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c9_sfEvent,
                                                    123);
                                      c9_encStr2Arr(chartInstance, c9_dv29);
                                      for (c9_i240 = 0; c9_i240 < 256; c9_i240++)
                                      {
                                        c9_gazeBML[c9_i240] = c9_dv29[c9_i240];
                                      }

                                      c9_updateDataWrittenToVector(chartInstance,
                                        0U);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c9_sfEvent,
                                                    -123);
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

  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -116);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeInterestedTablec9_lib_affectiveChar_behavior
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[11];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  boolean_T c9_aVarTruthTableCondition_4;
  boolean_T c9_aVarTruthTableCondition_5;
  boolean_T c9_aVarTruthTableCondition_6;
  boolean_T c9_aVarTruthTableCondition_7;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv30[256];
  int32_T c9_i241;
  int32_T c9_i242;
  int32_T c9_i243;
  int32_T c9_i244;
  int32_T c9_i245;
  int32_T c9_i246;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[122];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[122];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i247;
  static char_T c9_cv26[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i248;
  static real_T c9_dv31[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i249;
  int32_T c9_i250;
  int32_T c9_i251;
  int32_T c9_i252;
  int32_T c9_i253;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c9_t_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_4, 3U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_5, 4U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_6, 5U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_7, 6U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 10U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 28);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 31);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 33);
  if (CV_EML_IF(0, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 55);
    c9_s_encStr2Arr(chartInstance, c9_dv30);
    for (c9_i241 = 0; c9_i241 < 256; c9_i241++) {
      c9_gazeBML[c9_i241] = c9_dv30[c9_i241];
    }

    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -55);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 35);
    if (CV_EML_IF(0, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 36);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 61);
      c9_t_encStr2Arr(chartInstance, c9_dv30);
      for (c9_i242 = 0; c9_i242 < 256; c9_i242++) {
        c9_gazeBML[c9_i242] = c9_dv30[c9_i242];
      }

      c9_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -61);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 37);
      if (CV_EML_IF(0, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 38);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 67);
        c9_u_encStr2Arr(chartInstance, c9_dv30);
        for (c9_i243 = 0; c9_i243 < 256; c9_i243++) {
          c9_gazeBML[c9_i243] = c9_dv30[c9_i243];
        }

        c9_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -67);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 39);
        if (CV_EML_IF(0, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 40);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 73);
          c9_v_encStr2Arr(chartInstance, c9_dv30);
          for (c9_i244 = 0; c9_i244 < 256; c9_i244++) {
            c9_gazeBML[c9_i244] = c9_dv30[c9_i244];
          }

          c9_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -73);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 41);
          if (CV_EML_IF(0, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 42);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 79);
            c9_w_encStr2Arr(chartInstance, c9_dv30);
            for (c9_i245 = 0; c9_i245 < 256; c9_i245++) {
              c9_gazeBML[c9_i245] = c9_dv30[c9_i245];
            }

            c9_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -79);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 43);
            if (CV_EML_IF(0, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 44);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 85);
              c9_x_encStr2Arr(chartInstance, c9_dv30);
              for (c9_i246 = 0; c9_i246 < 256; c9_i246++) {
                c9_gazeBML[c9_i246] = c9_dv30[c9_i246];
              }

              c9_updateDataWrittenToVector(chartInstance, 1U);
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -85);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 45);
              if (CV_EML_IF(0, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 91);
                _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_bb_debug_family_names,
                  c9_b_debug_family_var_map);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
                  c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_p_sf_marshallOut);
                _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
                  c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U,
                  c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_o_sf_marshallOut);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
                  c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
                  c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
                  c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                for (c9_i247 = 0; c9_i247 < 122; c9_i247++) {
                  c9_mystr[c9_i247] = c9_cv26[c9_i247];
                }

                CV_SCRIPT_FCN(0, 0);
                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
                c9_maxarrsize = 256.0;
                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
                for (c9_i248 = 0; c9_i248 < 122; c9_i248++) {
                  c9_arr[c9_i248] = c9_dv31[c9_i248];
                }

                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
                c9_ss = 122.0;
                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
                c9_padsize = c9_maxarrsize - c9_ss;
                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
                for (c9_i249 = 0; c9_i249 < 256; c9_i249++) {
                  c9_tt[c9_i249] = 0.0;
                }

                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
                for (c9_i250 = 0; c9_i250 < 122; c9_i250++) {
                  c9_tt[c9_i250] = c9_arr[c9_i250];
                }

                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
                for (c9_i251 = 0; c9_i251 < 256; c9_i251++) {
                  c9_myarr256[c9_i251] = c9_tt[c9_i251];
                }

                _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
                _SFD_SYMBOL_SCOPE_POP();
                for (c9_i252 = 0; c9_i252 < 256; c9_i252++) {
                  c9_gazeBML[c9_i252] = c9_myarr256[c9_i252];
                }

                c9_updateDataWrittenToVector(chartInstance, 1U);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -91);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 48);
                CV_EML_FCN(0, 1);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 55);
                c9_s_encStr2Arr(chartInstance, c9_dv30);
                for (c9_i253 = 0; c9_i253 < 256; c9_i253++) {
                  c9_gazeBML[c9_i253] = c9_dv30[c9_i253];
                }

                c9_updateDataWrittenToVector(chartInstance, 1U);
                _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -55);
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_sendBML(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c9_b_sendBML(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void sf_exported_user_c9_lib_affectiveChar_behavior_idleGazeInterestedTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_idleGazeInterestedTablec9_lib_affectiveChar_behavior(chartInstance,
    c9_bmlID, c9_gazeBML);
}

void sf_exported_user_c9_lib_affectiveChar_behavior_idleGazeTable(SimStruct
  *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_idleGazeTablec9_lib_affectiveChar_behavior(chartInstance, c9_bmlID,
    c9_gazeBML);
}

void sf_exported_user_c9_lib_affectiveChar_behavior_sendBML(SimStruct *c9_S,
  real_T c9_arg[256])
{
  int32_T c9_i254;
  real_T c9_b_arg[256];
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  for (c9_i254 = 0; c9_i254 < 256; c9_i254++) {
    c9_b_arg[c9_i254] = c9_arg[c9_i254];
  }

  c9_sendBMLc9_lib_affectiveChar_behavior(chartInstance, c9_b_arg);
}

static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int8_T c9_e_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int8_T c9_y;
  int8_T c9_i255;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i255, 1, 2, 0U, 0, 0U, 0);
  c9_y = c9_i255;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_secs;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int8_T c9_y;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_secs = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_secs), &c9_thisId);
  sf_mex_destroy(&c9_secs);
  *(int8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_f_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i256;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i256, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i256;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_g_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_tp_stateInitial, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateInitial),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateInitial);
  return c9_y;
}

static uint8_T c9_h_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u3;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u3, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u3;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_tp_stateInitial;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
    chartInstanceVoid;
  c9_b_tp_stateInitial = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateInitial),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateInitial);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint32_T c9_i_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_method, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_method),
    &c9_thisId);
  sf_mex_destroy(&c9_b_method);
  return c9_y;
}

static uint32_T c9_j_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u4;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_method_not_empty = false;
  } else {
    chartInstance->c9_method_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u4, 1, 7, 0U, 0, 0U, 0);
    c9_y = c9_u4;
  }

  sf_mex_destroy(&c9_u);
  return c9_y;
}

static uint32_T c9_k_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_d_state, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId);
  sf_mex_destroy(&c9_d_state);
  return c9_y;
}

static uint32_T c9_l_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u5;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_state_not_empty = false;
  } else {
    chartInstance->c9_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u5, 1, 7, 0U, 0, 0U, 0);
    c9_y = c9_u5;
  }

  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_m_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[625])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_n_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[625])
{
  uint32_T c9_uv3[625];
  int32_T c9_i257;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_c_state_not_empty = false;
  } else {
    chartInstance->c9_c_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c9_i257 = 0; c9_i257 < 625; c9_i257++) {
      c9_y[c9_i257] = c9_uv3[c9_i257];
    }
  }

  sf_mex_destroy(&c9_u);
}

static void c9_o_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_p_emlrt_marshallIn(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[2])
{
  uint32_T c9_uv4[2];
  int32_T c9_i258;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_b_state_not_empty = false;
  } else {
    chartInstance->c9_b_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c9_i258 = 0; c9_i258 < 2; c9_i258++) {
      c9_y[c9_i258] = c9_uv4[c9_i258];
    }
  }

  sf_mex_destroy(&c9_u);
}

static uint32_T c9_q_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_temporalCounter_i1, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_temporalCounter_i1),
    &c9_thisId);
  sf_mex_destroy(&c9_b_temporalCounter_i1);
  return c9_y;
}

static uint32_T c9_r_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u6;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u6, 1, 7, 0U, 0, 0U, 0);
  c9_y = c9_u6;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static const mxArray *c9_s_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_b_setSimStateSideEffectsInfo, const char_T *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_t_emlrt_marshallIn
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  (void)c9_parentId;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), false);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_updateDataWrittenToVector
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c9_vectorIndex)
{
  (void)chartInstance;
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 1, 1, 0)] = true;
}

static void c9_b_twister_state_vector
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed)
{
  real_T c9_d5;
  uint32_T c9_u7;
  uint32_T c9_r;
  int32_T c9_mti;
  real_T c9_b_mti;
  real_T c9_d6;
  uint32_T c9_u8;
  (void)chartInstance;
  c9_d5 = c9_seed;
  if (c9_d5 < 4.294967296E+9) {
    if (c9_d5 >= 0.0) {
      c9_u7 = (uint32_T)c9_d5;
    } else {
      c9_u7 = 0U;
    }
  } else if (c9_d5 >= 4.294967296E+9) {
    c9_u7 = MAX_uint32_T;
  } else {
    c9_u7 = 0U;
  }

  c9_r = c9_u7;
  c9_mt[0] = c9_r;
  for (c9_mti = 0; c9_mti < 623; c9_mti++) {
    c9_b_mti = 2.0 + (real_T)c9_mti;
    c9_d6 = muDoubleScalarRound(c9_b_mti - 1.0);
    if (c9_d6 < 4.294967296E+9) {
      if (c9_d6 >= 0.0) {
        c9_u8 = (uint32_T)c9_d6;
      } else {
        c9_u8 = 0U;
      }
    } else if (c9_d6 >= 4.294967296E+9) {
      c9_u8 = MAX_uint32_T;
    } else {
      c9_u8 = 0U;
    }

    c9_r = (c9_r ^ c9_r >> 30U) * 1812433253U + c9_u8;
    c9_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c9_b_mti), 1, 625, 1, 0) - 1] = c9_r;
  }

  c9_mt[624] = 624U;
}

static real_T c9_c_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T
   c9_d_state[625])
{
  int32_T c9_i259;
  uint32_T c9_u[2];
  int32_T c9_j;
  real_T c9_b_j;
  uint32_T c9_mti;
  int32_T c9_kk;
  real_T c9_b_kk;
  uint32_T c9_y;
  uint32_T c9_b_y;
  uint32_T c9_c_y;
  int32_T c9_c_kk;
  uint32_T c9_d_y;
  uint32_T c9_e_y;
  uint32_T c9_f_y;
  uint32_T c9_g_y;
  real_T c9_b_r;
  boolean_T c9_b1;
  boolean_T c9_isvalid;
  int32_T c9_k;
  int32_T c9_a;
  int32_T c9_b_a;
  real_T c9_d7;
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
    for (c9_i259 = 0; c9_i259 < 2; c9_i259++) {
      c9_u[c9_i259] = 0U;
    }

    for (c9_j = 0; c9_j < 2; c9_j++) {
      c9_b_j = 1.0 + (real_T)c9_j;
      c9_mti = c9_d_state[624] + 1U;
      if ((real_T)c9_mti >= 625.0) {
        for (c9_kk = 0; c9_kk < 227; c9_kk++) {
          c9_b_kk = 1.0 + (real_T)c9_kk;
          c9_y = (c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c9_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c9_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c9_b_y = c9_y;
          c9_c_y = c9_b_y;
          if ((real_T)(c9_c_y & 1U) == 0.0) {
            c9_c_y >>= 1U;
          } else {
            c9_c_y = c9_c_y >> 1U ^ 2567483615U;
          }

          c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c9_b_kk), 1, 625, 1, 0) - 1] =
            c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c9_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c9_c_y;
        }

        for (c9_c_kk = 0; c9_c_kk < 396; c9_c_kk++) {
          c9_b_kk = 228.0 + (real_T)c9_c_kk;
          c9_y = (c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c9_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c9_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c9_d_y = c9_y;
          c9_e_y = c9_d_y;
          if ((real_T)(c9_e_y & 1U) == 0.0) {
            c9_e_y >>= 1U;
          } else {
            c9_e_y = c9_e_y >> 1U ^ 2567483615U;
          }

          c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c9_b_kk), 1, 625, 1, 0) - 1] =
            c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c9_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c9_e_y;
        }

        c9_y = (c9_d_state[623] & 2147483648U) | (c9_d_state[0] & 2147483647U);
        c9_f_y = c9_y;
        c9_g_y = c9_f_y;
        if ((real_T)(c9_g_y & 1U) == 0.0) {
          c9_g_y >>= 1U;
        } else {
          c9_g_y = c9_g_y >> 1U ^ 2567483615U;
        }

        c9_d_state[623] = c9_d_state[396] ^ c9_g_y;
        c9_mti = 1U;
      }

      c9_y = c9_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c9_mti), 1, 625, 1, 0)
        - 1];
      c9_d_state[624] = c9_mti;
      c9_y ^= c9_y >> 11U;
      c9_y ^= c9_y << 7U & 2636928640U;
      c9_y ^= c9_y << 15U & 4022730752U;
      c9_y ^= c9_y >> 18U;
      c9_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c9_b_j), 1, 2, 1, 0) - 1] = c9_y;
    }

    c9_u[0] >>= 5U;
    c9_u[1] >>= 6U;
    c9_b_r = 1.1102230246251565E-16 * ((real_T)c9_u[0] * 6.7108864E+7 + (real_T)
      c9_u[1]);
    if (c9_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c9_d_state[624] >= 1.0) {
        if ((real_T)c9_d_state[624] < 625.0) {
          c9_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c9_b1 = false;
      }

      c9_isvalid = c9_b1;
      if (c9_isvalid) {
        c9_isvalid = false;
        c9_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c9_k < 625)) {
          if ((real_T)c9_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c9_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c9_a = c9_k;
            c9_b_a = c9_a + 1;
            c9_k = c9_b_a;
          } else {
            c9_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c9_isvalid) {
        c9_eml_error(chartInstance);
        c9_d7 = 5489.0;
        c9_b_twister_state_vector(chartInstance, c9_d_state, c9_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c9_b_r;
}

static real_T c9_get_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#345) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_BOREDOM_THRESHOLD_address;
}

static void c9_set_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#345) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_BOREDOM_THRESHOLD_address = c9_c;
}

static real_T *c9_access_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#345) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_BOREDOM_THRESHOLD_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c9_c;
}

static real_T c9_get_boredom(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#344) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_boredom_address;
}

static void c9_set_boredom(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#344) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_boredom_address = c9_c;
}

static real_T *c9_access_boredom(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#344) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_boredom_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c9_c;
}

static real_T c9_get_interest(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#349) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_interest_address;
}

static void c9_set_interest(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#349) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_interest_address = c9_c;
}

static real_T *c9_access_interest(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#349) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_interest_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c9_c;
}

static real_T c9_get_isPosing(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#348) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_isPosing_address;
}

static void c9_set_isPosing(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#348) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_isPosing_address = c9_c;
}

static real_T *c9_access_isPosing(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#348) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_isPosing_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c9_c;
}

static real_T c9_get_randAvertGazeChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#346) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randAvertGazeChance_address;
}

static void c9_set_randAvertGazeChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#346) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randAvertGazeChance_address = c9_c;
}

static real_T *c9_access_randAvertGazeChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#346) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randAvertGazeChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c9_c;
}

static real_T c9_get_randGazeDur(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#350) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randGazeDur_address;
}

static void c9_set_randGazeDur(SFc9_lib_affectiveChar_behaviorInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#350) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randGazeDur_address = c9_c;
}

static real_T *c9_access_randGazeDur
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#350) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randGazeDur_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c9_c;
}

static real_T c9_get_randPoseChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#347) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randPoseChance_address;
}

static void c9_set_randPoseChance(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#347) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randPoseChance_address = c9_c;
}

static real_T *c9_access_randPoseChance
  (SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#347) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randPoseChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c9_c;
}

static void init_dsm_address_info(SFc9_lib_affectiveChar_behaviorInstanceStruct *
  chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c9_BOREDOM_THRESHOLD_address,
    &chartInstance->c9_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c9_boredom_address, &chartInstance->c9_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c9_interest_address, &chartInstance->c9_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c9_isPosing_address, &chartInstance->c9_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c9_randAvertGazeChance_address,
    &chartInstance->c9_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randGazeDur", (void **)
    &chartInstance->c9_randGazeDur_address, &chartInstance->c9_randGazeDur_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c9_randPoseChance_address,
    &chartInstance->c9_randPoseChance_index);
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

void sf_c9_lib_affectiveChar_behavior_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1678105838U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1131856083U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(956600499U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(239231889U);
}

mxArray *sf_c9_lib_affectiveChar_behavior_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TiMFJpjNfXjVCr26RuBhtH");
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

mxArray *sf_c9_lib_affectiveChar_behavior_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_lib_affectiveChar_behavior_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_lib_affectiveChar_behavior(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c9_lib_affectiveChar_behavior\",},{M[9],M[0],T\"is_c9_lib_affectiveChar_behavior\",},{M[11],M[23],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x3[13 14 15],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_lib_affectiveChar_behavior_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_behaviorMachineNumber_,
           9,
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
          _SFD_SET_DATA_PROPS(2,11,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(3,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(4,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(5,11,0,0,"interest");
          _SFD_SET_DATA_PROPS(6,11,0,0,"randGazeDur");
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

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,19,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"idleGazeTablec9_lib_affectiveChar_behavior",0,
                             -1,2840);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",2840,-1,3027);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",3027,-1,3216);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",3216,-1,3399);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",3399,-1,3586);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",3586,-1,3777);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",3777,-1,3970);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",3970,-1,4165);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",4165,-1,4362);
        _SFD_CV_INIT_EML_FCN(1,9,"aFcnTruthTableAction_9",4362,-1,4563);
        _SFD_CV_INIT_EML_FCN(1,10,"aFcnTruthTableAction_10",4563,-1,4773);
        _SFD_CV_INIT_EML_FCN(1,11,"aFcnTruthTableAction_11",4773,-1,4985);
        _SFD_CV_INIT_EML_FCN(1,12,"aFcnTruthTableAction_12",4985,-1,5193);
        _SFD_CV_INIT_EML_FCN(1,13,"aFcnTruthTableAction_13",5193,-1,5399);
        _SFD_CV_INIT_EML_FCN(1,14,"aFcnTruthTableAction_14",5399,-1,5597);
        _SFD_CV_INIT_EML_FCN(1,15,"aFcnTruthTableAction_15",5597,-1,5801);
        _SFD_CV_INIT_EML_FCN(1,16,"aFcnTruthTableAction_16",5801,-1,6003);
        _SFD_CV_INIT_EML_FCN(1,17,"aFcnTruthTableAction_17",6003,-1,6170);
        _SFD_CV_INIT_EML_FCN(1,18,"aFcnTruthTableAction_18",6170,-1,6358);
        _SFD_CV_INIT_EML_IF(1,1,0,1606,1636,1667,2838);
        _SFD_CV_INIT_EML_IF(1,1,1,1667,1701,1732,2838);
        _SFD_CV_INIT_EML_IF(1,1,2,1732,1766,1797,2838);
        _SFD_CV_INIT_EML_IF(1,1,3,1797,1831,1862,2838);
        _SFD_CV_INIT_EML_IF(1,1,4,1862,1896,1927,2838);
        _SFD_CV_INIT_EML_IF(1,1,5,1927,1961,1992,2838);
        _SFD_CV_INIT_EML_IF(1,1,6,1992,2026,2057,2838);
        _SFD_CV_INIT_EML_IF(1,1,7,2057,2091,2122,2838);
        _SFD_CV_INIT_EML_IF(1,1,8,2122,2156,2187,2838);
        _SFD_CV_INIT_EML_IF(1,1,9,2187,2222,2254,2838);
        _SFD_CV_INIT_EML_IF(1,1,10,2254,2289,2321,2838);
        _SFD_CV_INIT_EML_IF(1,1,11,2321,2356,2388,2838);
        _SFD_CV_INIT_EML_IF(1,1,12,2388,2423,2455,2838);
        _SFD_CV_INIT_EML_IF(1,1,13,2455,2490,2522,2838);
        _SFD_CV_INIT_EML_IF(1,1,14,2522,2557,2589,2838);
        _SFD_CV_INIT_EML_IF(1,1,15,2589,2624,2656,2838);
        _SFD_CV_INIT_EML_IF(1,1,16,2656,2691,2723,2838);
        _SFD_CV_INIT_EML_IF(1,1,17,2723,2758,2790,2838);
        _SFD_CV_INIT_EML(0,1,8,7,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,
                             "idleGazeInterestedTablec9_lib_affectiveChar_behavior",
                             0,-1,1140);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1140,-1,1322);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1322,-1,1508);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1508,-1,1695);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1695,-1,1885);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1885,-1,2077);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",2077,-1,2271);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",2271,-1,2466);
        _SFD_CV_INIT_EML_IF(0,1,0,639,669,700,1138);
        _SFD_CV_INIT_EML_IF(0,1,1,700,734,765,1138);
        _SFD_CV_INIT_EML_IF(0,1,2,765,799,830,1138);
        _SFD_CV_INIT_EML_IF(0,1,3,830,864,895,1138);
        _SFD_CV_INIT_EML_IF(0,1,4,895,929,960,1138);
        _SFD_CV_INIT_EML_IF(0,1,5,960,994,1025,1138);
        _SFD_CV_INIT_EML_IF(0,1,6,1025,1059,1090,1138);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,52,1,48);

        {
          static int condStart[] = { 2, 28 };

          static int condEnd[] = { 25, 51 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,52,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,23,0,23);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,38,1,38);

        {
          static int condStart[] = { 2, 24 };

          static int condEnd[] = { 21, 37 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,38,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,42,1,42);

        {
          static int condStart[] = { 2, 28 };

          static int condEnd[] = { 25, 41 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_boredom_address);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_BOREDOM_THRESHOLD_address);
        _SFD_SET_DATA_VALUE_PTR(2U,
          chartInstance->c9_randAvertGazeChance_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_randPoseChance_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_isPosing_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_interest_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_randGazeDur_address);
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
  return "vYpGM9Ctc62mw24y8Axmi";
}

static void sf_opaque_initialize_c9_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_lib_affectiveChar_behaviorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
  initialize_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  enable_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  disable_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  sf_gateway_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_lib_affectiveChar_behavior
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_lib_affectiveChar_behavior();/* state var info */
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

extern void sf_internal_set_sim_state_c9_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_lib_affectiveChar_behavior();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_lib_affectiveChar_behavior
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c9_lib_affectiveChar_behavior(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c9_lib_affectiveChar_behavior(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_lib_affectiveChar_behaviorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_behavior_optimization_info();
    }

    finalize_c9_lib_affectiveChar_behavior
      ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_lib_affectiveChar_behavior
    ((SFc9_lib_affectiveChar_behaviorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_lib_affectiveChar_behavior(SimStruct *S)
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
    initialize_params_c9_lib_affectiveChar_behavior
      ((SFc9_lib_affectiveChar_behaviorInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_behavior_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,9,1);
    if (chartIsInlinable) {
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3467725017U));
  ssSetChecksum1(S,(388946292U));
  ssSetChecksum2(S,(310631453U));
  ssSetChecksum3(S,(1593918214U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_lib_affectiveChar_behavior(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_lib_affectiveChar_behavior(SimStruct *S)
{
  SFc9_lib_affectiveChar_behaviorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_lib_affectiveChar_behaviorInstanceStruct *)utMalloc
    (sizeof(SFc9_lib_affectiveChar_behaviorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_lib_affectiveChar_behaviorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_lib_affectiveChar_behavior;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_lib_affectiveChar_behavior;
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

void c9_lib_affectiveChar_behavior_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_lib_affectiveChar_behavior(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_lib_affectiveChar_behavior(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_lib_affectiveChar_behavior_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
